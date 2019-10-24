#!/bin/bash

find a -type f -exec ls -l {} \; | awk '{print $5}' | sort -n
