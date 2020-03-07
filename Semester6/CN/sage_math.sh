#!/bin/bash

eval PATH=$(echo $PATH | sed -r 's|([:/])[^:]*anaconda3?/bin:|\1|g') sage -n jupyter
