# Build and Run CPP Files (With or Without Input Files)

##  sh build.sh -x <filename> (with or without extension)

## ! use -c to run all of the below with C instead of C++
## e.g. sh build.sh -c -x <filename>

## -x build and then run with an input file
## -e build and then run without an input file
## -b build only
## -i run only with input file
## -r run only without input file



## DEFINE
sourcedir="."
inputdir="./inputs"
runfiledir="./exec"

## Globals

sourcename="default"
sourcefile="default.cpp"
inputfile="default.txt"
runfile="default.out"

isrun=false
isbuild=false
isuseinputfile=false;

isc=false;


# isinputfile=false
# output=false
# issourcefile=false
# iscompileandrun=false
# sourcefile="default.cpp"
# inputfile="default.txt"
# runfile="default.out"
# runonly=false;

while getopts x:e:b:r:i:c opt
do
    sourcename=${OPTARG}
    case "${opt}" in
        x)
            isbuild=true
            isrun=true
            isuseinputfile=true;;
        e)
            isbuild=true
            isrun=true;;
        b)
            isbuild=true;;
        r) 
            isrun=true;;
        i) 
            isrun=true
            isuseinputfile=true;;
        c)
            isc=true;;
    esac
done

fileextension="cpp"
compilecommand="g++"

if [ "$isc" = true ] ; then
    fileextension="c"
    compilecommand="gcc"
fi

sourcename=$(echo "$sourcename" | cut -f 1 -d '.') || $sourcename
sourcefile="$sourcedir/$sourcename.$fileextension"
inputfile="$inputdir/$sourcename-input.txt"
runfile="$runfiledir/$sourcename.out"

if [ "$isbuild" = true ] ; then
    echo "Building source: $sourcefile";
    echo "$compilecommand $sourcefile -o $runfile"
    $compilecommand $sourcefile -o $runfile
fi

if [ "$isrun" = true ] ; then
    echo "Running program: $sourcefile";
    if [ "$isuseinputfile" = true ]
    then
        echo "Using input: $inputfile"
        echo "cat $inputfile | $runfile"
        echo "===Program output:==="
        cat $inputfile | $runfile
    else
        echo "With no input file"
        echo "$runfile";
        echo "===Program output:==="
        $runfile
    fi
    echo "\n===/Build and Program output==="
fi