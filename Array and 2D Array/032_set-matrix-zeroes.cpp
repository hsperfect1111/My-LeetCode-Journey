// 32.
// https://leetcode.com/problems/set-matrix-zeroes/
// 73. Set Matrix Zeroes
// YT : https://www.youtube.com/watch?v=N0MgLvceX7M

			// Better
// Using chatgpt by understanding but approach striver wali hi h 13:37: 
// YT : https://www.youtube.com/watch?v=N0MgLvceX7M

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         vector<int> row(m, 0);
//         vector<int> col(n, 0);

//         // Step 1: Mark rows and columns that need to be zeroed
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // When we find a 0 in the matrix at position (i, j), we:
//                 // Mark row[i] = 1 → this row needs to become all zero
//                 // Mark col[j] = 1 → this column also needs to become all zero
//                 if (matrix[i][j] == 0) {
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }

//         // Step 2: Set cells to 0 if their row or col is marked
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (row[i] == 1 || col[j] == 1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

// TC = O(2*n*m)
// Sc = O(n) + O(m)

		// optimal solution 
// YT :https://www.youtube.com/watch?v=N0MgLvceX7M

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Number of rows
        int m = matrix[0].size(); // Number of columns

        int col0 = 1;   // Flag to track whether the first column needs to be zeroed

        // Step 1: Use first row and first column as markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the first element of the current row as 0
                    // mark the ith row
                    matrix[i][0] = 0;
                    // If j != 0, mark the first row for this column
                    // Else, set col0 = 0 to mark that first column must be zeroed later
                    // mark the jth col
                    // Jab matrix[i][j] == 0 milta hai:
                    // Agar j != 0 hai (matlab column 0 ke alawa koi column hai), to us column ko mark kar dete hain:
                    if(j!=0)
                        matrix[0][j] = 0;
                    else // Agar j == 0 h toh col0 ko 0 mark kr dege
                        col0=0;
                }
            }
        }

        // Step 2: Use the markers to set matrix[i][j] to 0 if needed
        // Skip first row and first column for now
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {   
                // If either the row or column is marked, set current cell to 0
                if(matrix[i][j] != 0)   // Agar matrix[i][j] = 1 h to hume check karege row=0 , col=0 k liye
                {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: Handle the first row separately if needed
        if(matrix[0][0] == 0)
        {
            for(int j=0; j<m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column separately if needed
        if(col0 == 0)
        {
            for(int i=0; i<n; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
};
