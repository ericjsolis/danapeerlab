﻿#!/usr/bin/env python
import logging
import os
import sys
# uncomment when using the main:
sys.path.insert(0, '.')
from depends import fix_path
fix_path(True)

from scriptservices import services
from scriptservices import cache
from biology.datatable import DataTable
from biology.datatable import combine_tables
from biology.loaddatatable import load_data_table
from biology.loaddatatable import get_num_events
from odict import OrderedDict

class DataIndexEntry:
  def __init__(self, filename, tags):
    self.filename = filename
    self.tags = tags
    
  def get_tag_value(self, tag_name):
    if not tag_name in self.tags:
      return None
    return self.tags[tag_name]
  
  def __str__(self):
    tags = ['\t%s: %s\n' % (k, self.tags[k]) for k in self.tags]
    return '%s\n%s' % (self.filename, ''.join(tags))

    
  @staticmethod
  def load(idx, lines):
    assert len(lines) > 0
    assert not lines[idx].startswith('\t')
    assert not lines[idx].startswith('  ')
    filename = lines[idx].strip()
    idx += 1
    tags = OrderedDict()
    while idx < len(lines) and (lines[idx].startswith('\t') or lines[idx].startswith('  ')):
      if ':' in lines[idx]:
        splitted = lines[idx].split(':')
        tag_key = splitted[0].strip()
        tag_val = splitted[1].strip()
        assert tag_key
        assert tag_val
        tags[tag_key] = tag_val
      idx += 1
    return idx, DataIndexEntry(filename, tags)

NO_VALUE_TAG = 'No Value'

def is_number(s):
  try:
    float(s)
    return True
  except ValueError:
    return False    

class DataIndex(object):
  def __init__(self, entries, path): 
    self.entries = entries
    self.path = path
    self.tags = list(set(sum([e.tags.keys() for e in entries], [])))
    self.legends = [self.create_legend_for_tag(t) for t in self.tags]

  def save(self, path):
    save_str = ''.join([str(e) for e in self.entries])
    with open(path, 'w') as dest:
      dest.write(save_str)

  def create_legend_for_tag(self, tag_name):
    # get all values for tag:
    legend = {}
    vals = list(self.all_values_for_tag(tag_name))
    if all([is_number(v) for v in vals]):
      for v in vals:
        legend[float(v)] = v
    else:
      for i in xrange(len(vals)):
        legend[float(i + 1)] = vals[i]
    if not float(0) in legend:
      legend[float(0)] = NO_VALUE_TAG
    else:
      no_value_num = min(legend.keys()) - 1
      legend[no_value_num] = NO_VALUE_TAG
    # make the legend bidrectional:
    revd=dict([reversed(i) for i in legend.items()])
    legend.update(revd)
    return legend

  def all_tags(self):
    tags = reduce(list.__add__, [e.tags.keys() for e in self.entries], [])
    tags = list(set(tags))
    tags.sort()
    return tags

  def all_values_for_tag(self, tag_name):
    ret = list(set([e.tags[tag_name] for e in self.entries if tag_name in e.tags]))
    ret.sort()
    return ret

  def count_cells_predicate(self, predicate):
    entries_to_load = [e for e in self.entries if predicate(e.tags)]
    counts = [self.num_cells_from_entry(e) for e in entries_to_load]
    return reduce(int.__add__, counts, 0)

  def load_table_predicate(self, predicate, arcsin_factor=1):   
    entries_to_load = [e for e in self.entries if predicate(e.tags)]
    if not entries_to_load:
      raise Exception('Could not find data matching the query')
    tables_to_load = [self.table_from_entry(e, arcsin_factor) for e in entries_to_load]
    tables_to_load = [t for t in tables_to_load if t]
    return combine_tables(tables_to_load)
  
  #@cache('data tables')
  def load_table(self, *args, **kargs):
    return self._count_load_table(False, *args, **kargs)

  def count_cells(self, *args, **kargs):
    return self._count_load_table(True, *args, **kargs)

  def _count_load_table(self, count, *args, **kargs):
    def predicate(tags):
      if not kargs:
        return False
      for key,val in kargs.iteritems():
        if not key in tags:
          return False
        if type(val) in (str, unicode):
          if tags[key] != val:
            return False
        else:
          if not tags[key] in val:
            return False
      return True
    if count:
      return self.count_cells_predicate(predicate)
    else:
      return self.load_table_predicate(predicate)

  

  def num_cells_from_entry(self, entry):
    return get_num_events(os.path.join(self.path, entry.filename))

  def table_from_entry(self, entry, arcsin_factor=1):
    value_str = [entry.tags.get(t, NO_VALUE_TAG) for t in self.tags]
    value_num = [self.legends[i][val] for i,val in enumerate(value_str)]    
    table =  load_data_table(
        os.path.join(self.path, entry.filename), 
        self.tags,
        value_num,
        self.legends,
        arcsin_factor)
    if table:
      services.print_text('<b>Loaded %d cells from entry ...%s</b>' % (table.data.shape[0], entry.filename[-100:]))
    return table

  @staticmethod
  def load_cytof54_elad_dir(fcs_dir):
    fcs_files = [f for f in os.listdir(fcs_dir) if f.endswith('.fcs')]
    logging.info('Fcs files found:\n%s' % '\n'.join(fcs_files))
    if not fcs_files:    
      raise Exception('No FCS files in the given dir')
    entries = []
    for f in fcs_files:
      tags = {}
      parts = f.split('_')
      tags['stim'] = parts[3].strip()
      assert tags['stim']
      tags['cluster_num'] = parts[-4].strip()
      assert tags['cluster_num']
      print f
      print parts
      print tags['cluster_num']
      assert is_number(tags['cluster_num'])
      if parts[-3].strip():
        tags['cluster_name'] = parts[-3].strip()
      entries.append(DataIndexEntry(f, tags))
    return DataIndex(entries, fcs_dir)

  @staticmethod
  def load_cytof54_erin_dir(fcs_dir):
    fcs_files = [f for f in os.listdir(fcs_dir) if f.endswith('.fcs')]
    logging.info('Fcs files found:\n%s' % '\n'.join(fcs_files))
    if not fcs_files:    
      raise Exception('No FCS files in the given dir')
    entries = []
    for f in fcs_files:
      tags = {}
      parts = f.split('_')
      tags['marrow'] = parts[0]
      tags['tube'] = parts[1]
      tags['stim'] = parts[2]
      tags['cell_type'] = parts[-1].split('.')[0]
      assert is_number(tags['tube'])
      entries.append(DataIndexEntry(f, tags))
    return DataIndex(entries, fcs_dir)
    
  @staticmethod
  def load(path):
    with open (path, 'rU') as src:
      lines = src.readlines()
    idx = 0
    entries = []
    while idx < len(lines):
      idx, entry = DataIndexEntry.load(idx, lines)
      entries.append(entry)
    return DataIndex(entries, os.path.dirname(path))

if __name__ == '__main__':
  logging.getLogger('').setLevel(logging.DEBUG)
  stream_handler = logging.StreamHandler()
  formatter = logging.Formatter(
      "%(asctime)s - %(levelname)s - %(message)s")
  stream_handler.setFormatter(formatter)
  logging.getLogger('').addHandler(stream_handler)
  if len(sys.argv) < 2:
    print 'Usage: dataindex.py fcs_dir'
    print 'Note: Right now this works only for cytof54 data'
    exit()
  index = DataIndex.load_cytof54_erin_dir(sys.argv[1])
  index.save(os.path.join(sys.argv[1], 'cytof54.index'))
  print 'Saved file cytof54.index'