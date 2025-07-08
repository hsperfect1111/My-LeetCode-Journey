https://leetcode.com/problems/pascals-triangle/submissions/1610807890/
118. Pascal's Triangle
YT : https://www.youtube.com/watch?v=bR7mQgwQ_o8

// Function to generate a specific row in Pascal's Triangle
vector<int> generateRow(int row)
{
    long long ans = 1; // First value in the row is always 1
    vector<int> ansRow;
    ansRow.push_back(1); // Push the first element

    // Compute the remaining elements using binomial coefficient formula
    for(int col = 1; col < row; col++)
    {
        ans = ans * (row - col); // Multiply with (row - col)
        ans = ans / col;         // Divide by col to complete C(row-1, col)
        ansRow.push_back(ans);   // Append the computed value to the row
    }

    return ansRow; // Return the completed row
}

// Class to generate the entire Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        // Generate each row from 1 to numRows and add to the result
        for(int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i)); // Generate the i-th row
        }

        return ans; // Return the full triangle
    }
};
