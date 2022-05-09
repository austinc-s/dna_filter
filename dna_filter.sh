#!/bin/bash

#Source Directories (CHANGE)
SOURCEDIRKS=/home/aus87/CyCIF/dna_filter/ks_files/*
SOURCEDIRUNM=/home/aus87/CyCIF/dna_filter/unmicst/

#Destination Directories (CHANGE)
DESTDIR=/home/aus87/CyCIF/dna_filter/trimmed/

shopt -s nullglob
for sourcefile in $SOURCEDIRKS; do
    BASE=${sourcefile##*/}
    /home/aus87/CyCIF/dna_filter/dna_filter $sourcefile "${SOURCEDIRUNM}${BASE}" #first item is program location (CHANGE)
done