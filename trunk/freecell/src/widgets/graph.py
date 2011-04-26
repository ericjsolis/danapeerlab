﻿#!/usr/bin/env python
import scipy
import numpy as np
import itertools
import logging
import gc
from widget import Widget
from multitimer import MultiTimer
from view import View
from view import render
from biology.dataindex import DataIndex
from table import Table
from figure import Figure
import axes
from axes import kde2d
from axes import new_axes
from axes import new_figure
from biology.datatable import fake_table
from biology.datatable import combine_tables
from biology.datatable import DimRange
from view import stack_lines
import matplotlib.cm as cm

    

class Graph(Widget):
  def __init__(self):
    Widget.__init__(self)

  def view(self, nodes, edges):
    html = render('graph.html', {
        'id' : self._get_unique_id()})
    v = View(self, html, ['graph.css'], ['json2.js', 'AC_OETags.js', 'cytoscapeweb.js'])
    return v