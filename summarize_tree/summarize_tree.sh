#!/bin/bash


fileCount=$(find $1 -type f | wc -l)
dirCount=$(find $1 -type d | wc -l)


printf "Processed all the files from <%s>.\n" "$1"
printf "There were %d directories.\n" "$dirCount"
printf "There were %d regular files.\n" "$fileCount"
