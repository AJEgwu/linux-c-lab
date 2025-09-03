#!/usr/bin/env bash
# Usage: ./file-check.sh path/to/file
FILE="$1"
if [ -z "$FILE" ]; then
  echo "Usage: $0 <file-path>"
  exit 1
fi

if [ -f "$FILE" ]; then
  echo "File exists:"
  ls -lh "$FILE"
else
  echo "File not found: $FILE"
  exit 2
fi
