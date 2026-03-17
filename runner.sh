# Bash script for compile C files from a directory,
# saves it at "execs" folder with the name of the directory
# and executes it

    absoluteDir="$1"
    relativeDir="$2"
    exec_path="../execs/$relativeDir"
    echo $exec_path
    
    filesString=($realtiveDir/*.c)
      
    gcc "${filesString[@]}" -lm -o "${exec_path}"
    echo "Executable created"
    
    return
    
    "$EXE_PATH/$1"
