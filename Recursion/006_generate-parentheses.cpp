// 6.
// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
// Yt : https://www.youtube.com/watch?v=7xkPbffc6w8

// NOTE : Backtracking is nothing but recursion only.
// Backtracking :
// 	--> Do
// 	--> Explore
// 	--> Undo
// If Question is related to Generate possibility or configuration use backtracking

// Generate possibility -> combinations  use backtracking
// 	 	     -> Permutations  use backtracking

// Valid h k nhi woh check kaise karege , stack lelo uspr iterate karo , Ye stack O(N) space lega

// #isko count se karege open dikhega toh +1 kr dege close dikhega to -1 kr dege , count ka sum = 0 aayega to valid

// 			IMP 
// n pairs = length of parenthesis string
// 	= 2*n
// har ek position k liye 2-options h
// Total possibilities = 2^2n possibilities 

// TC = O(2^2n * 2n) , 2n for isValid k liye h
// Depth of recursion tree = O(2*n) empty string jo h usme 2n spaces h to usko bharne k liye 2*n niche jaana padega 

//                 		Approach-1
class Solution {
public:
    vector<string> result;

    bool isValid(string str)
    {
        int count = 0;
        for(char ch : str)
        {
            if(ch == '(')
                count++;
            else
                count--;

            // "())(" 
            // 1 -1 -1 +1 = 0 is inValid
            if(count < 0)
                return false;
        }
        return count == 0;
    }

    void solve(string& curr, int n)
    {
        if(curr.length() == 2*n)
        {
            if(isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return result;
    }
};

//                 Approach-2 Same as Approach-1 with safety check, No need of isValid() function
class Solution {
public:
    vector<string> result;

    void solve(string& curr, int n, int open, int close)
    {
        // This block of code is the base case for your recursive function solve(...), and it's essential for correctly generating all valid parentheses combinations.
        if(curr.length() == 2*n)
        {
            result.push_back(curr);
            return;
        }

        if(open < n)
        {
            curr.push_back('(');
            solve(curr, n, open + 1, close);
            curr.pop_back();
        }

        if(close < open)
        {
            curr.push_back(')');
            solve(curr, n, open, close + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        int open = 0;
        int close = 0;

        solve(curr, n, open, close);

        return result;
    }
};

// Tc = O(2^2n)
// Sc = O(2*n)
