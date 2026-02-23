#!/bin/zsh

ROOT="./"
ABSOLUTE_ROOT=$(dirname "$(realpath "$0")$ROOT")

compl() {

    local compilePath="${ABSOLUTE_ROOT}/$1"
    local exec_path="${ABSOLUTE_ROOT}/$2"
    
    
    # cd "$compilePath"
    if [ -f $compilePath ]; then
        files=$compilePath
    else
        filesString="$(find ${compilePath} -type f -printf "${compilePath}/%f ")"
        files=($filesString)
    fi
      
    echo "FILES LIST: $files"
        
    gcc "${files}" -lm -o "${exec_path}"    
    echo "Executable created"
    
    return
}


runni() {
    
    case "$1" in
        
        -h | --help)
            help()
            return
            ;;
        
        -c | --compile)
            shift
            compl()
            return
            ;;
    esac
}