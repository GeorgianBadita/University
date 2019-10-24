#!/bin/bash

read expresion

echo $expresion|bc -l | xargs printf "%.3f"
