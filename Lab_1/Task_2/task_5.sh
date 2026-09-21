OUTPUT_FILE="result.txt"
LINES=${1:-5}
top -b -n 1 | head -n "$LINES" > "$OUTPUT_FILE"
cat "$OUTPUT_FILE"
echo "successfully"
#4313 % 6 = 5