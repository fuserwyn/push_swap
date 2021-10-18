#!/bin/bash
ARG=`./gen.py 500`; ./push_swap $ARG > resps;  < resps additional/checker_Mac $ARG;
< resps wc -l
