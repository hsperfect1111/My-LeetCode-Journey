// 44.
// https://www.geeksforgeeks.org/problems/queries-on-a-matrix0443/1
// Queries on a Matrix
// YT : https://www.youtube.com/watch?v=0Uu8WKJNfyA

// Note : Nahi chl raha code :
// YT : https://www.youtube.com/watch?v=7uxlCmQjwE0&t=229s
// class Solution {
// public:
//     vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
//         vector<vector<int>> matrix(n, vector<int>(n, 0));
//         int q = Queries.size();
        
//         // Process each query
//         for(int i=0; i<q; i++)
//         {
//             int a = Queries[i][0];  // Start row
//             int b = Queries[i][1];  // Start column
//             int c = Queries[i][2];  // End row
//             int d = Queries[i][3];  // End column
            
//             for(int row=a; row<=c; row++)
//             {
//                 matrix[row][b]++;   // Increment start column
//                 if(d+1<n) matrix[row][d+1]--;   // Decrement after end column (if within bounds)
//             }
//         }
        
//         // Perform the column-wise prefix sum
//         // At col = 0, there's no previous column (col - 1 would be -1, which is invalid), so we skip it.
//         // Starting from col = 1 ensures we always have a valid col - 1 to look back to.
//         for(int row=0; row<n; row++)
//         {
//             for(int col=1; col<n; col++)    // Start from column 1, not 0
//             {
//                 matrix[row][col] += matrix[row][col - 1];   // Column-wise prefix sum
//             }
//         }
//         return matrix;  // Return the final matrix
//     }
// };



// Note : Nahi chl raha code :
// class Solution {
//   public:
//     vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
//         // Code here
//         vector<vector<int>> ans(n,vector<int>(n,0));
        
//         for(int i=0; i<Queries.size(); i++)
//         {
//             int a = Queries[i][0];
//             int b = Queries[i][1];
//             int c = Queries[i][2];
//             int d = Queries[i][3];
            
//             // row a to c
//             for(int j=a; j<=c; j++)
//             {
//                 // col d to d
//                 for(int k=b; k<=d; k++)
//                 {
//                     ans[j][k] += 1;
//                 }
//             }
            
//         }
//         return ans;
//     }
// };

// TC = q * (c-a) * (d-b)
//      q * c * d
//      q * n * n => q*(n^2)

// Note : Nahi chl raha code :
// class Solution {
// public:
//     vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
//         vector<vector<int>> ans(n, vector<int>(n, 0));
//         int q = Queries.size();

//         // Apply difference updates row-wise
//         for (int i = 0; i < q; i++) {
//             int a = Queries[i][0];
//             int b = Queries[i][1];
//             int c = Queries[i][2];
//             int d = Queries[i][3];

//             for (int j = a; j <= c; j++) {
//                 ans[j][b] += 1;
//                 if (d + 1 < n) {
//                     ans[j][d + 1] -= 1;
//                 }
//             }
//         }

//         // Apply prefix sums row-wise to build the final matrix
//         for (int i = 0; i < n; i++) {
//             for (int j = 1; j < n; j++) {
//                 ans[i][j] += ans[i][j - 1];
//             }
//         }

//         return ans;
//     }
// };


// TC = (c-a) + O(n^2)
