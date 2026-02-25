#!/bin/zsh

# USAGE
# compl <compilePath> <executablePath>


ABSOLUTE_ROOT=$(dirname "$(realpath "$0")")
EXE_PATH="$ABSOLUTE_ROOT/.exe"

compl() {

    local compilePath="${ABSOLUTE_ROOT}/$1"
    local exec_path="${ABSOLUTE_ROOT}/$2"
    
    
    # cd "$compilePath"
    if [ -f $compilePath ]; then
        filesString="$compilePath"
    elif [ -d $compilePath ]; then
        filesString=($compilePath/*.c)
    fi
      
    gcc "${filesString[@]}" -lm -o "${exec_path}"    
    echo "Executable created"
    
    return
}

runni() {
    
    "$EXE_PATH/$1"
}
