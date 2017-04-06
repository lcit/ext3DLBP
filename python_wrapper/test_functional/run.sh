#!/bin/bash
for file in ./test*; do 
	python $file; 
	rc=$?; 
	if [[ $rc != 0 ]]; then 
		exit $rc; 
	fi
done
