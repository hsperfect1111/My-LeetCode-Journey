// 20.
// 51. N-Queens
// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
	vector<vector<string>> answer = {};
	vector<string> chessboard = {}; //ek chessboard bana liya vector of string
    
    bool isSafe(int r, int c, int n) //yaha hum dekh rhe h ki queen safe h yaa nhi 
    {
		//two pointer wala logic laga diya ye loop check krega ki uss row maine kahi Queen h yaa nhi h 
        for(int i=0; i<n; i++)
        {
			//ek m row fix krdi aur dusre m column fix kr diya aur check kiya ki waha pr Queen rakhi h yaa nhi rakhi
            if(chessboard[r][i] == 'Q' || chessboard[i][c] == 'Q') // row k liye check aur dusra column k liye check 
            {
                return false;
            }
        }

		//diagonals
		int R = r, C = c;
		// upward left
		//Yaha two pointer logic laga diya ki woh upward left gaya toh row-colmn kaise change hoga aur agar ek baar upward right gaya toh kaise change hoga 
		while(R>=0 && C>=0)
		{
			if(chessboard[R][C] == 'Q')
			{
				return false;
			}
			R--;
			C--;
		}

		R = r, C = c;
		// upward right
		while(R>=0 && C<n)
		{
			if(chessboard[R][C] == 'Q')
			{
				return false;
			}
			R--;
			C++;
		}

		R = r, C = c;
		// downward left
		while(R<n && C>=0)
		{
			if(chessboard[R][C] == 'Q')
			{
				return false;
			}
			R++;
			C--;
		}

		R = r, C = c;
		// downward right
		while(R<n && C<n)
		{
			if(chessboard[R][C] == 'Q')
			{
				return false;
			}
			R++;
			C++;
		}

		return true;
    }

	void recursion(int row, int n)
	{
		// base case
		if(row == n)
		{
			// you have placed n queens
			answer.push_back(chessboard);
			return;
		}

		// recursive case ~ OPTIONS (COLUMN is option to place queen)
		for(int j=0; j<n; j++)
		{
			if(isSafe(row, j, n))
			{
				chessboard[row][j] = 'Q';
				recursion(row+1, n);
				chessboard[row][j] = '.'; //UNDO
			}
		}
	}
	
	vector<vector<string>> solveNQueens(int n) {
        
		//creating chessboard
		// n*n --> dots
		for(int i=0; i<n; i++)
		{
			string row = "";
			for(int j=0; j<n; j++) 
			{
				row += ".";
			}
			chessboard.push_back(row);
		}
		recursion(0, n);

		return answer;
    }
};

// Return krege A list of vector of vector
// vector < vector < vector <int>> : 
// 1. first vector represent = list of chessboad
// 2. second vector < vector <int>> represent : chessboad
// Data type : vector<string>
// multiple return krni h toh vector < vector <string>>

// 0 -> Q
// 1 -> Q
// 2 -> Q
// 3 -> Q
// 4 -> Q (Done)
// n options (columns) to place queen
// R(row,n) where , n = batayega ki kitni row h

// for(0.........n-1)
// 	{
// 		chessboad[row][j] = 'Q';
// 		R(row+1, n);
// 		chessboad[row][j] = '.';
// 	}
