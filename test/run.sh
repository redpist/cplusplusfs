#!/bin/sh

for i in `find test -name '*.cc'` ; do g++-4.8 -std=c++11 -I include `find src -name '*.cc'` $i && ./a.out ; done