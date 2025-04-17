#!/bin/bash

# Check if folder name is provided
if [ -z "$1" ]; then
    echo "Usage: createfolder <folder_name>"
    exit 1
fi

# Folder name
FOLDER_NAME="$1"

# Create the folder
mkdir -p "$FOLDER_NAME"

# Define snippets
SOL_SNIPPET='// Solution File
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}'

STUPID_SNIPPET='// Stupid Checker
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}'

TEST_SNIPPET='#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n = rand() % 100 + 1; // Generate a random number
    cout << n << endl;
    return 0;
}'

# Write snippets to files
echo "$SOL_SNIPPET" > "$FOLDER_NAME/sol.cpp"
echo "$STUPID_SNIPPET" > "$FOLDER_NAME/stupid.cpp"
echo "$TEST_SNIPPET" > "$FOLDER_NAME/test.cpp"

# Success message
echo "Folder '$FOLDER_NAME' created with sol.cpp, stupid.cpp, and test.cpp."

