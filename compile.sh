#!/bin/bash

# Find all C files recursively in subdirectories
find . -name '*.c' | while read file; do
    if [ -f "$file" ]; then
        filename=$(basename "$file" .c)
        output_path=$(dirname "$file")
        clang -o "${output_path}/${filename}" "$file"
        if [ $? -eq 0 ]; then
            echo "Compilation successful for $file"
        else
            echo "Error compiling $file"
        fi
    fi
done
