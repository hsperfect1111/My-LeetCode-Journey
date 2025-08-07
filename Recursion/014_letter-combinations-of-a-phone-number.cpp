// 14.
// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// YT : https://www.youtube.com/watch?v=vgnhZzw-kfU

class Solution {
public:
    vector<string> result;
    void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp)
    {
        if(idx>= digits.length())
        {
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0; i<str.length(); i++)
        {
            // Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        
        solve(0, digits, temp, mp);
        return result;
    }
};

// map in C++ is used when you want to store key-value pairs
//  Use map when:
// You want to look up values by keys quickly
// Example: Storing names and phone numbers, or counting word frequency.

// You want to avoid duplicate keys
// A map automatically ensures all keys are unique.

// You need keys in sorted order (for std::map)
// If you don’t care about order and want faster access, use unordered_map.
