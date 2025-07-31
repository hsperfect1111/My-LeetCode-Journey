// 1.
// 342. Power of Four
// https://leetcode.com/problems/power-of-four/description/
// YouTube: https://www.youtube.com/watch?v=-2Z4ngPy4H0

// Approach 1: Using Recursion
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        
        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};

// Time Limit Exceeded (iterative version)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)
            return false;

        while(n % 4 == 0)
        {
            n = n / 4;
        }

        if(n == 1)
            return true;
        
        return false;
    }
};

// Time Complexity: log(n) base 4

// Approach 2: Math
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)    // Because the input may include negative numbers as per constraints
            return false;
        
        int x = (log(n) / log(4));   // Time Complexity = log(n)

        if(pow(4, x) == n)           // Time Complexity = log(x)
            return true;

        return false;
    }
};

// Time Complexity = log(n) + log(x)

// Approach 3: Math + Bit Manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;

        // To check if a number is a power of 2, do n & (n - 1). If the result is 0, it's a power of 2.
        // Additionally, for power of 4: (n - 1) must be divisible by 3.
        if((n & (n - 1)) == 0 && (n - 1) % 3 == 0)
            return true;

        return false;
    }
};
