#!/bin/bash

./bin/dynamo >> result
python plot.py
rm result
