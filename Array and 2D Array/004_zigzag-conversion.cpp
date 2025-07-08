// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
        {
            return s;
        }
        vector<vector<char>> arr = {};
        for(int i=0; i<numRows; i++){
            vector<char> currentRow = {};
            arr.push_back(currentRow);
        }

        int rowIndex = 0;
        int turn = 0;

        for(int i=0; i<s.length(); i++){
            arr[rowIndex].push_back(s[i]);

            if(turn == 0){ 
                rowIndex++;

                if(rowIndex == numRows){
                    rowIndex = rowIndex - 2;
                    turn = 1;
                }
            }
            else { 
                rowIndex--;
                if(rowIndex == -1)
                {
                    rowIndex = rowIndex + 2;
                    turn = 0;
                }
            }
        }

        string answer = "";
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                answer += arr[i][j];
            }
        }

        return answer;
    }
};
