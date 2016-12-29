# -*- coding: utf-8 -*-
"""
Created on Tue Oct 25 15:37:30 2016

@author: cosec-11
"""

import ctypes

so=ctypes.cdll.LoadLibrary
lib=so("./libpycallclass.so")

print 'display'
lib.display()
print 'display(100)'
lib.display(100)