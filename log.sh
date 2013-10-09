#!/usr/bin/bash

total=0
linecount=0
while read line
do
    linecount=$linecount+1
    total=$($ave+$(cut $line -d ' ' -f 8))
done < access.log
let ave=total/linecount
echo $ave
