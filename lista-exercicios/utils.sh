#!/bin/bash

# --- CREATED WITH CLAUDE.AI ---


# C Exercises Management Script
# Usage: 
#   gogo <list> <filename> - Compile and run an exercise
#   more <path> - Create a new C file with boilerplate

EXEC_DIR="algoritmos-resolucoes/execs"

# Function to compile and run C exercise
gogo() {
    if [ $# -ne 2 ]; then
        echo "Usage: gogo <list> <filename>"
        echo "Example: gogo lista1 exercise1"
        return 1
    fi
    
    local list="$1"
    local filename="$2"
    
    # Remove .c extension if provided
    filename="${filename%.c}"
    
    local source_file="algoritmos-resolucoes/${list}/${filename}.c"
    local exec_file="${EXEC_DIR}/${filename}"
    
    # Check if source file exists
    if [ ! -f "$source_file" ]; then
        echo "Error: Source file '$source_file' not found!"
        return 1
    fi
    
    # Create exec directory if it doesn't exist
    mkdir -p "$EXEC_DIR"
    
    # Compile the C file
    echo "Compiling $source_file..."
    if gcc -o "$exec_file" "$source_file"; then
        echo "Compilation successful!"
    else
        echo "Compilation failed!"
        return 1
    fi
}

# Function to create new C file with boilerplate
more() {
    if [ $# -ne 1 ]; then
        echo "Usage: more <path>"
        echo "Example: more lista1/exercise1.c"
        return 1
    fi
    
    local file_path="$1"
    
    # Add .c extension if not provided
    if [[ "$file_path" != *.c ]]; then
        file_path="${file_path}.c"
    fi
    
    # Check if file already exists
    if [ -f "$file_path" ]; then
        echo "Error: File '$file_path' already exists!"
        return 1
    fi
    
    # Create the C file with boilerplate
    cat > "./algoritmos-resolucoes/$file_path" << 'EOF'
int main() {
    // Your code here
    
    return 0;
}
EOF
    
    echo "Created C file: $file_path"
}

# Main script logic
# case "$1" in
#     "gogo")
#         shift
#         gogo "$@"
#         ;;
#     "more")
#         shift
#         more "$@"
#         ;;
#     *)
#         echo "C Exercises Management Script"
#         echo ""
#         echo "Available commands:"
#         echo "  gogo <list> <filename>  - Compile and run an exercise"
#         echo "                           Example: gogo lista1 exercise1"
#         echo ""
#         echo "  more <path>            - Create a new C file with boilerplate"
#         echo "                           Example: more lista1/exercise1.c"
#         echo ""
#         echo "Notes:"
#         echo "  - Executables are stored in: $EXEC_DIR"
#         echo "  - .c extension is optional for both commands"
#         echo "  - Directories are created automatically if needed"
#         ;;
# esac