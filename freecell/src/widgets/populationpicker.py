﻿#!/usr/bin/env python
from odict import OrderedDict
from widget import Widget
from view import View
from view import render
from view import stack_left
from view import stack_lines
from biology.dataindex import DataIndex
from biology.datatable import combine_tables
from widgets.expander import Expander
from widgets.select import Select
from widgets.applybutton import ApplyButton
from widgets.input import Input
import settings
   
  
class PopulationPicker(Widget):
  def __init__(self, id, parent):
    Widget.__init__(self, id, parent)
    self._add_widget('experiment_select', Select)
    self._add_widget('combine_select', Select)
    self._add_widget('arcsin_factor', Input)
    self._add_widget('apply', ApplyButton)

    self.experiment_to_widgets = {}
    self.experiment = None
    self.data = None
    self.summary = ''

  def _get_index(self):
    if not self.experiment:
      raise Exception('No experiment defined')
    if type(settings.EXPERIMENTS[self.experiment]) == tuple:
      return DataIndex.load(settings.EXPERIMENTS[self.experiment][0])
    else:
      return DataIndex.load(settings.EXPERIMENTS[self.experiment])
      

  def title(self, short):
    if short:           
      return self.experiment
    else:
      return 'Population Picker: %s' % self.summary

  def get_inputs(self):
    return []
  
  def get_outputs(self):
    return ['tables']

  def run(self):
    ret = {}
    if not self.experiment:
      raise Exception('No data was loaded, pick an experiment first.')
    tables = self.get_data(count=False, arcsin_factor=1./self.widgets.arcsin_factor.value_as_float())
    if 'combine' in self.widgets.combine_select.values.choices:
      ret['tables'] = [combine_tables(tables.values())]
      ret['tables'][0].name = self.summary
      #ret['view'] = 'loaded %d cells' % ret['tables'][0].num_cells
    else:
      ret['tables'] = tables.values()
      logs = []
      #for key in tables:
      #  logs.append('%s: loaded %d cells' % (str(key), tables[key].num_cells))
      #ret['view'] = '\n'.join(logs)        
    return ret

  def get_data(self, count, arcsin_factor):
    index = self._get_index()
    tag_to_vals = {}
    for w in self.experiment_to_widgets[self.experiment]:
      tag_to_vals[w.tag] = w.values.choices
    if count:      
      return index.count_cells(tag_to_vals, arcsin_factor=arcsin_factor)
    else:
      return index.load_table(tag_to_vals, arcsin_factor=arcsin_factor)

  def is_ready(self):
    return self.experiment and self.experiment in self.experiment_to_widgets
  
  def on_load(self):
    if not self.widgets.experiment_select.values.choices:
      return
    
    self.experiment = self.widgets.experiment_select.values.choices[0]
    
    if not self.experiment in self.experiment_to_widgets:
      self.summary = 'Please select population for experiment %s' % self.experiment
      return
      
    index = self._get_index()
    
    def summary_from_widget(w, index):
      choices = []
      if w.values.choices:
        choices = w.values.choices
      if set(index.all_values_for_tag(w.tag)) == set(choices):
        return ''
      return '[%s]' % ', '.join(choices)
        
      #if set(index.all_values_for_tag(w.tag)) == set(w.values.choices):
      #  return '%s: any' % w.tag
      #return '%s: %s' % (w.tag, ', '.join(w.values.choices))
    self.summary = '%s %s' % (
        self.experiment,
        ' '.join(
            [summary_from_widget(w, index) for w in self.experiment_to_widgets.get(self.experiment, [])]))    

  def view(self, enable_expander=False):
    experiments = settings.EXPERIMENTS.keys()
    if not self.experiment:
      return stack_lines(
          self.widgets.experiment_select.view('Please Select an experiment', self.widgets.apply, experiments, False),
          self.widgets.apply.view())
    
    if not self.experiment in self.experiment_to_widgets:
      index = self._get_index()
      widgets = []
      if type(settings.EXPERIMENTS[self.experiment]) == tuple:
        editable_tags = settings.EXPERIMENTS[self.experiment][1]
      else:
        editable_tags = index.all_tags()
      for tag in editable_tags:
        new_widget = self._add_widget('%s_%s' % (self.experiment, tag), Select)
        new_widget.tag = tag
        new_widget.vals = index.all_values_for_tag(tag)        
        widgets.append(new_widget)
      self.experiment_to_widgets[self.experiment] = widgets
    
    for w in self.experiment_to_widgets[self.experiment]:
      w.guess_or_remember((w.tag, w.vals, self.__class__.__name__), [])
    
    self.widgets.combine_select.guess_or_remember(('populationpicker combine_select', self.experiment), ['combine'])
    self.widgets.arcsin_factor.guess_or_remember(('populationpicker arcsin_factor', self.experiment), 5)
    
    #if not self.widgets.arcsin_factor.values.value:
    #  self.widgets.arcsin_factor.values.value = '1'

    views = [w.view(w.tag, self.widgets.apply, w.vals) for w in self.experiment_to_widgets[self.experiment]]
    stacked_views = stack_lines(*views)
 
    expanded = stack_lines(
        self.widgets.experiment_select.view(
            'Experiment', self.widgets.apply, experiments, False),
        stacked_views,
        self.widgets.combine_select.view('Combine files', self.widgets.apply, [('combine', 'Combine items into one table'), ('seperate', 'Seperate to one table per parameter combination')], multiple=False),
        self.widgets.arcsin_factor.view('Arcsinh Factor', self.widgets.apply, numeric_validation=True, comment='Transformation: arcsinh(value / factor)'),
        View(None, '<p style="clear: both"></p>'),
        self.widgets.apply.view())
    if not enable_expander:
      return expanded
    return self.widgets.expander.view('',[self.summary], [expanded])