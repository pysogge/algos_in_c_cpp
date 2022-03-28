# Algorithm Implementations in C/C++

## Compile and Run with Input File
```bash
sh build.sh -c -x slow_sort
sh build.sh -c -x quick_sort
sh build.sh -c -x get_array
sh build.sh -c -x linked_list

# Build and Run CPP Files (With or Without Input Files)

##  sh build.sh -x <filename> (with or without extension)

## ! use -c to run all of the below with C instead of C++
## e.g. sh build.sh -c -x <filename>

## -x build and then run with an input file 
    ### (you can also default use -x and just ignore the input)
## -e build and then run without an input file
## -b build only
## -i run only with input file
## -r run only without input file
```

## Make new files and input files
```bash
sh makenew.sh -c -x new_sort

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

## Dump Assembly / Object Code
```bash
## Run this after building the program
otool -tv ./exec/slow_sort.out

## Run this to dump it into a file
mkdir -p asm && otool -tv ./exec/slow_sort.out > ./asm/slow_sort.txt
```

## Check File Size
```bash
## Run this after building the program
ls -sh ./exec/slow_sort.out

## Run this to get the size of a dir
du -sh ./exec/
```

TODO:
- Sorts
- Lists
- Search
- Multi-File
- Algorithms to Use Get Array input
