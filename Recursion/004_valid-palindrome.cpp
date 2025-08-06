// 4. 
// NOTE : WE HAVE TO DO THIS QUESTION USING RECURSION IN BELOW 2nd_method
// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/

// A two-pointer iterative approach:
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.length() - 1;

//         while (left < right) {
//             // Skip non-alphanumeric characters
//             while (left < right && !isalnum(s[left])) left++;
//             while (left < right && !isalnum(s[right])) right--;

//             // Compare characters (case insensitive)
//             if (tolower(s[left]) != tolower(s[right])) {
//                 return false;
//             }

//             left++;
//             right--;
//         }

//         return true;
//     }
// };


// Using chatGPT and above two pointer approach
// Recursive version (with backtracking-style structure)

class Solution {
public:
    bool isPalindromeRecursive(string& s, int left, int right)
    {
        // Alphabets + Numbers — yani:
        // Alphabets: A–Z, a–z
        // Digits: 0–9
        // Agar alphanum nhi h yani , ya space h toh left++ krdo or right++
        while(left<right && !isalnum(s[left])) left++;
        while(left<right && !isalnum(s[right])) right--;

        if(left>=right)
            return true;
        // tolower(char c) in C++: It converts an uppercase letter to its lowercase form.
        if(tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        return isPalindromeRecursive(s, left+1, right-1);
    }
    bool isPalindrome(string s) {
        return isPalindromeRecursive(s, 0, s.length() - 1);
        
    }
};
