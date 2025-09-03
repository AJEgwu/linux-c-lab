#!/usr/bin/env bash
# Usage: ./file-count.sh path/to/dir
DIR="${1:-.}"
if [ ! -d "$DIR" ]; then
  echo "Not a directory: $DIR" >&2
  exit 1
fi

echo "Directory: $DIR"
# Count by extension (case-insensitive)
find "$DIR" -type f -print0 \
| awk -v RS='\0' '
  {
    n=split($0, a, /\./);
    ext=(n>1)?a[n]: "noext";
    ext=tolower(ext);
    cnt[ext]++;
  }
  END {
    for (e in cnt) printf "%s: %d\n", e, cnt[e];
  }' | sort
