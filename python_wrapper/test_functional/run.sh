#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
echo $DIR
for file in $DIR/test*; do 
	python $file; 
	rc=$?; 
	if [[ $rc != 0 ]]; then 
		exit $rc; 
	fi
done
