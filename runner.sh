#!/bin/zsh

# USAGE
# compl <compilePath> <executablePath>


ABSOLUTE_ROOT=$(dirname "$(realpath "$0")")

compl() {

    local path_args="${@:1:$#-1}"
    local compile_paths=()
    local exec_path="${ABSOLUTE_ROOT}/${!#}"
    
    
    # cd "$compilePath"
    if [ -f $compilePath ]; then
        compile_paths="${ABSOLUTE_ROOT}/${path_args}"

    elif [ -d $compilePath ]; then
        for arg in $path_args; do
            compile_paths+=("${ABSOLUTE_ROOT}/${arg}")
        done
    fi

    gcc "${compile_paths[@]}" -lm -o "${exec_path}"    
    echo "Executable created"
    
    return
}