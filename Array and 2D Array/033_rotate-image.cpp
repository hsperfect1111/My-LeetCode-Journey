// 33.
// https://leetcode.com/problems/rotate-image/description/
// 48. Rotate Image
class Solution {
public:
	void reverseArray(vector<int> &row){
		int i = 0;
		int j = row.size()-1;

		while(i<j){
			int temp = row[i];
			row[i] = row[j];
			row[j] = temp;

			i++;
			j--;
		}
	}
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // It gives no. of rows and columns 
		
		// STEP 1 - Transpose
		for(int i=0; i<n; i++){ //row
			for(int j=0; j<n; j++){ //column
				if(i<j){
					// (i,j)-->(j,i)
					int temp = matrix[i][j];
					matrix[i][j] = matrix[j][i];
					matrix[j][i] = temp;
				}
			}
		}
		//Step 2 - Reverse the row
		for(int i=0; i<n; i++){
			//matrix[i] --> ith row
			//reverse(matrix[i].begin(), matrix[i].end());
			reverseArray(matrix[i]);
		}
    }
};
