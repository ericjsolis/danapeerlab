﻿#!/usr/bin/env python
import settings
import os
import pickle
from odict import OrderedDict
from cache import CACHE
from cache import make_unique_str
from widget import Widget
from view import View
from view import render
from biology.dataindex import DataIndex
from django.utils.html import linebreaks

def options_from_table(table):
    other_markers = table.get_markers('other')
    signal_markers = table.get_markers('signal')
    surface_markers = table.get_markers('surface')
    none_markers = table.get_markers_not_in_groups('other', 'signal', 'surface', 'surface_ignore', 'signal_ignore')
    return [
        ('t-SNE', sorted(other_markers)),
        ('Surface Markers', sorted(surface_markers)),
        ('Signal Markers', sorted(signal_markers)),
        ('', sorted(none_markers))]
    
class Select(Widget):
  """ The select widget shows a combo box menu. 
  You can select one item or multiple items.
  When the user selects values, they are saved as a list in Select.values.choices.  
  Note: The selected values are saved as a list thanks to the set_value method in main.py
  which supports lists.
  The widget can also offer a default value for choices based on previous selection
  of the user. This is done by the guess_or_remember_choices method.
  """
  def __init__(self, id, parent):
    Widget.__init__(self, id, parent)
    self.values.choices = None

  def guess_or_remember_choices(self, text, options, guess_hint=''):
    """ Used to suggest a default value for the widget, or record the selected 
    value. 
    If there is no value in values.choices, the method will set its value
    to be a previously selected value. 
    Otherwise, the current value is recorded. 
    The key by which the value is recorded is a combination of 
    (text, options, guess_hint). 
    """
    select_dict = CACHE.get('select_dict', none_if_not_found=True)
    key = make_unique_str((text, options, guess_hint))
    if not select_dict:
      select_dict = {}
    if self.values.choices == None:
      self.values.choices = select_dict.get(key, None)
    else:
      select_dict[key] = self.values.choices
      CACHE.put('select_dict', select_dict, 'select')   
   
  def view(self, text, save_button, options, multiple=True, group_buttons=[], choices=None, comment=''):
    """ Returns a view of the select widget.
    text is a the title of the widget. 
    save_button is  an ApplyButton used to save the widget's state. 
    options describes the options in the select box. 
    options can be:
       1. a list of strings --> one selection group, titles and values are the same, none is selected
       2. a list of (value, title) tuples --> one selection group, titles and values are different, none is selected
       3. a list of (value, title, selected) tuples --> one selection group, titles and values are different, selection according to selected.
       3. a list of (group_name, 1/2/3 style list) --> multiple groups.
    groups is a list of tuples of (group_name, list of vals). If it is not None, then a button is added
    for every group. When the button is pressed, the relevant items are selected. 
    comment -- displays text next to the select box. 
    """
    def add_titles_if_needed(items):
      if items and type(items[0]) != tuple:
        items = zip(items, items)
      return items
    
    def add_selected_state(items):
      return [(o[0], o[1], o[0] in choices) for o in items]
      
    if choices == None:
      choices = self.values.choices
    if choices == None:
      choices = []
      
    options = add_titles_if_needed(options)
    #print options
    # Now options is either a list of title,val or a list of (group_name, group_values)
    if not type(options[0][1]) in (tuple, list):
      options = [('None', options)]
    #print options
    # Now options is either a list of (group_name, list(titles)) or a list of (group_name, list(titles, vals))
    options = [(o[0], add_titles_if_needed(o[1])) for o in options]
    #print options
    # Now add selected state the list so that we have (group_name list(titles, vals, select))
    options = [(o[0], add_selected_state(o[1])) for o in options]
    #print options
    
    html = render('select.html', {
        'height' : 300,
        'groups' : group_buttons,
        'text' : text,
        'saver_id' : save_button.id,
        'id' : self._get_unique_id(),
        'multiple' : multiple,
        'items' : options,
        'comment' : comment,
        'widget_id' : self.id})
    v = View(
        self, 
        html, 
        ['jquery.multiselect.css'],
        ['jquery.multiselect.js'])
    return v