18.
37. Sudoku Solver
https://leetcode.com/problems/sudoku-solver/description/
YT : https://www.youtube.com/watch?v=70cP3qtJp-s

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig)
    {
        // horizontal 
        for(int j=0; j<=9; j++)
        {
            if(board[row][j] == dig)
            {
                return false;
            }
        }

        // Vertical 
        for(int i=0; i<9; i++)
        {
            if(board[i][col] == dig)
            {
                return false;
            }
        }

        // IMP grid srow = (r/3)*3 , scol = (c/3)*3
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i=srow; i<=srow+2; i++)
        {
            for(int j=scol; j<=scol+2; j++)
            {
                if(board[i][j] == dig)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col)
    {
        if(row == 9)
        {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if(nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        // place the digit
        for(char dig='1'; dig<='9'; dig++)
        {
            if(isSafe(board, row, col, dig))
            {
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol))
                {
                    return true;
                }
                board[row][col] = '.';
            }
            board[row][col] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

// Time Complexity (TC): O(9^m)
// → m = number of empty cells; each can try 9 digits → total 9^m possibilities.

// Space Complexity (SC): O(m)
// → Recursion stack depth up to m (number of empty cells).
