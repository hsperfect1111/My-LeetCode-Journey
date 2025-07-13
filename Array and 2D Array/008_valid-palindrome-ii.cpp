// 8.
// https://leetcode.com/problems/valid-palindrome-ii/description/
// 680. Valid Palindrome II
// YT : https://www.youtube.com/watch?v=wX3-411uJH0

class Solution {
public:
    // Helper function to check if a string is a palindrome
    // 'const string& s' means:
    //   - 'const': we won't modify the string inside this function
    //   - '&' (reference): we pass the string by reference to avoid copying
    //     (faster and memory-efficient, especially for large strings)
    // Helper function
    // We need a helper function to check if a part of the string is a palindrome:
    bool isPalindrome(const string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right]) 
                return false;   // Not a palindrome if mismatch found
            left++;
            right--;
        }
        return true;    // Palindrome confirmed
    }

    // Main function to check if the string can be a palindrome 
    // after deleting at most one character
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Two-pointer approach
        // Use two indexes:
        // left = 0, right = s.length() - 1
        // While left < right:
        // If s[left] == s[right]: move inward (left++, right--)
        // If mismatch found → try removing either s[left] or s[right] and check the remaining substring.
        while(left < right)
        {
            if(s[left] != s[right])
            {
                // Try skipping one character either from left or right
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;    // String is already a palindrome
    }
};
