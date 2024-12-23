#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(const vector<vector<char>>& board) {
    // Set to track seen digits for rows, columns, and sub-boxes
    unordered_set<char> rows[9], cols[9], boxes[9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];

            if (num == '.') {
                continue;  // Skip empty cells
            }

            // Check row for duplicates
            if (rows[i].find(num) != rows[i].end()) {
                return false;
            }
            rows[i].insert(num);

            // Check column for duplicates
            if (cols[j].find(num) != cols[j].end()) {
                return false;
            }
            cols[j].insert(num);

            // Check sub-box for duplicates
            int boxIndex = (i / 3) * 3 + (j / 3);  // Calculate the index of the sub-box
            if (boxes[boxIndex].find(num) != boxes[boxIndex].end()) {
                return false;
            }
            boxes[boxIndex].insert(num);
        }
    }

    return true;  // If no duplicates were found, the Sudoku is valid
}

int main() {
    // Example input: a partially filled Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '8', '.', '6', '.', '.', '3'},
        {'4', '.', '9', '.', '.', '8', '3', '.', '1'},
        {'7', '.', '.', '4', '1', '9', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '6', '8', '.', '.', '7', '9'},
        {'9', '.', '.', '.', '2', '.', '4', '.', '.'}
    };

    // Check if the board is valid
    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}
