// 37.
// https://leetcode.com/problems/maximal-rectangle/description/
// 85. Maximal Rectangle

class Solution {
public:

	// yaha humne do function bana lege ek left k liye aur ek right k liye  
	vector<int> nextSmallerLeft(vector<int> &heights)
	{
		stack<int> st;
        // Hume iterate krna h toh iska size nikal lo
		int N = heights.size();
		vector<int> answer(N, -1); // left element exist nhi kr raha hoga toh m isse -1 assume kr luga 
		// leftsmaller element on the left side nikalne k liye array m ulta iterate krna hoga 
		for(int i=N-1; i>=0; i--)
		{
			while(!st.empty() && heights[i] < heights[st.top()])
			{
				answer[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return answer;
	}

	vector<int> nextSmallerRight(vector<int> &heights)
	{
		stack<int> st;
		int N = heights.size();
		vector<int> answer(N, N); // yaha pr m assume kr raha hu ki akheri index answer h 
		// leftsmaller element on the left side nikalne k liye array m ulta iterate krna hoga 
		for(int i=0; i<N; i++)
		{
			while(!st.empty() && heights[i] < heights[st.top()])
			{
				answer[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return answer;
	}

	int largestRectangleArea(vector<int>& heights) {
        
        // ye bataye ki konse index pr smaller element h right aur left m 
		// yaha humne code divide kr diya left aur right part m 
        vector<int> leftPart = nextSmallerLeft(heights);
		vector<int> rightPart = nextSmallerRight(heights);

		// [3, 2, 1, 4]
		//  0  1  2  3
		// -1  4  => (4 - (-1) - 1) = 4

		int maxArea = 0;
		for(int i=0; i<heights.size(); i++)
		{
            // width nikalne ka formula 
			int width = rightPart[i] - leftPart[i] - 1;
			int currentAres = heights[i] * width;

			maxArea = max(maxArea, currentAres);
		}
		return maxArea;
	}	

    int maximalRectangle(vector<vector<char>>& matrix) {
        
		// row or column nikal diye
		int N = matrix.size();
		int M = matrix[0].size();
		// ek matrix banayege jo hume batayegi ki kya kya height h waha pr
		vector<vector<int>> arr(N, vector<int> (M, 0)); // ab m n element luga or  sb m 0 element rakh diya 
    
		// har row m iterate krna h niche ki taraf toh bhar wala loop column pr jaa raha hoga 
		for(int i=0; i<M; i++){

			int sum = 0;
			for(int j=0; j<N; j++) // ye represent kr raha h rows ko
			{
				if(matrix[j][i] == '1'){
					sum++;
				}
				else 
				{
					sum = 0;
				}

				arr[j][i] = sum;
			
			}
		}

		// ab largest rec area nikalne ki koshish krege har ek k liye 
		int answer = 0;
		for(int i=0; i<N; i++)
		{
			int area = largestRectangleArea(arr[i]);
			answer = max(answer, area);
		}	
		return answer;
	}
};
