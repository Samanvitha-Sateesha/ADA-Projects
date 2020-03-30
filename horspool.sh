#!/bin/bash

set xrange [0:500]
set yrange [0:300000]
set title "Horspool Algorithm"
set xlabel "Input Pattern Size"
set ylabel "Basic Operation Count"
set style data linesplot "horspool_bc.txt" title "Best Case" smooth unique, "horspool_wc.txt" title "Worst Case" smooth unique
