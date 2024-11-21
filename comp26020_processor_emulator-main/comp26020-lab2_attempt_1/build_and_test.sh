#!/bin/sh

cmake -B build -DCMAKE_CXX_COMPILER=g++-12

cmake --build build/ --target tests

