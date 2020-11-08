#!/bin/bash

for file in * ; do
	echo $(wc "$file" -lw) 
done

