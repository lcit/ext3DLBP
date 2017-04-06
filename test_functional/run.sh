#!/bin/bash
for file in ./build/test*; do 
	$file; 
	rc=$?; 
	if [[ $rc != 0 ]]; then 
		exit $rc; 
	fi
done
