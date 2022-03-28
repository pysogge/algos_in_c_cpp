# Algorithm Implementations in C/C++

## Compile and Run with Input File
```bash
sh build.sh -c -x slow_sort
sh build.sh -c -x get_array
sh build.sh -c -x linked_list

# Build and Run CPP Files (With or Without Input Files)

##  sh build.sh -x <filename> (with or without extension)

## ! use -c to run all of the below with C instead of C++
## e.g. sh build.sh -c -x <filename>

## -x build and then run with an input file
## -e build and then run without an input file
## -b build only
## -i run only with input file
## -r run only without input file
```

## Make new files and input files
```bash
sh makenew.sh -c -x slow_sort

# Create New Source Files

##  sh makenew.sh -x <filename> (with or without extension)
## Removes all files with file basename (.cpp, .out, .txt)
## Makes a new cpp source file <filename>.cpp and input file <filename>-input.txt

## ! use -c to run all of the below with C instead of C++
## e.g. sh makenew.sh -c -x <filename>

## -n make  (touch) new source and input files only (.cpp, .txt)
## -r remove old files (.cpp, .out, .txt) only
## -x remove and make new files (.cpp, .out, .txt)
```

TODO:
- Sorts
- Lists
- Search
- Multi-File
- Algorithms to Use Get Array input
