#!/bin/bash
ARG=`./gen.py 100`; ./push_swap $ARG > resps;  < resps additional/checker_Mac $ARG;
< resps wc -l
