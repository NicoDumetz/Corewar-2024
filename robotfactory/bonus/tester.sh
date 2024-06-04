#!/bin/bash

for file in *.s; do
    ../asm "$file"
    corrected_file="${file%.s}.cor"
    if [ -f "$corrected_file" ]; then
        cp "$corrected_file" "${corrected_file}_orig"
    else
        echo "$file non trouvé."
        exit 1
    fi
    ../asmdir/asm "$file"
    if cmp -s "$corrected_file" "${corrected_file}_orig"; then
        echo "$file [OK]"
    else
        echo "$file. Erreur output"
    fi
    rm "$corrected_file" "${corrected_file}_orig"
done

