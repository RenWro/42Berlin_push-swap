#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
GREY="\033[0;90m"
RESET="\033[0m"

# Paths
PS=./push_swap
CK=./checker
LOG=log_ko.txt

# Clear previous log file
> $LOG

# Function to run a test
run_test() {
	input="$1"
	echo -e "${GREY}Test: ./push_swap $input${RESET}"
	moves=$($PS $input | wc -l)
	result=$($PS $input | $CK $input 2>/dev/null)

	if [ "$result" == "OK" ]; then
		echo -e "✅ ${GREEN}OK${RESET} - Moves: $moves"
	else
		echo -e "❌ ${RED}KO${RESET} - Output: $result"
		echo "Input: $input" >> $LOG
		echo "Moves: $moves" >> $LOG
		echo "Result: $result" >> $LOG
		echo "---" >> $LOG
	fi
	echo
}

# Custom input via CLI
if [ "$#" -gt 0 ]; then
	run_test "$*"
	exit 0
fi

# Standard cases
run_test "3 2 1"
run_test "1 5 2 4 3"
run_test "5 4 3 2 1"
run_test "1 2 3 4 5"
run_test "2 1 3"

# Edge cases
run_test "1"
run_test ""
run_test "1 1"
run_test "0 0 0"
run_test "2147483647 -2147483648"
run_test "42 -42 0"
run_test "1 -1 2 -2 3"

# Random test
RAND=$(seq 1 100 | shuf | tr '\n' ' ')
echo -e "${GREY}Random 100 test...${RESET}"
$PS $RAND | $CK $RAND 2>/dev/null
