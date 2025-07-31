// 2.
// 231. Power of Two
// https://leetcode.com/problems/power-of-two/description/
// YouTube: https://www.youtube.com/watch?v=bVfA6_rDw4M

// --------------------------------------------------
// Approach 1: Recursion
// --------------------------------------------------
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0) return false;
//         if(n == 1) return true;
        
//         return n % 2 == 0 && isPowerOfTwo(n / 2);
//     }
// };

// --------------------------------------------------
// Iterative version
// --------------------------------------------------
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n == 0)  // Or just check if(n <= 0). If n == 0, it's obviously not a power of 2.
//             return false;  // Because 2^0 = 1, 2^1 = 2, powers of 2 are never negative or zero

//         while(n % 2 == 0)
//         {
//             n = n / 2;
//         }

//         if(n == 1)
//             return true;
        
//         return false;
//     }
// };

// Time Complexity: O(log₂(n))

// --------------------------------------------------
// Approach 2: Math (using logarithms)
// --------------------------------------------------
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n == 0)
//             return false;
        
//         int x = (log(n) / log(2));  // log₂(n)

//         if(pow(2, x) == n)
//             return true;

//         return false;
//     }
// };

// Time Complexity: O(log(n) + log(x))

// --------------------------------------------------
// Approach 3: Bit Manipulation
// --------------------------------------------------
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0)
//             return false;
        
//         return (n & (n - 1)) == 0; // A power of 2 has only one bit set.
//     }
// };

// OR more verbosely:
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0)
//             return false;

//         if((n & (n - 1)) == 0)  // Time Complexity = O(1)
//             return true;
        
//         return false;
//     }
// };

// Time Complexity: O(1)
// Space Complexity: O(1)

// --------------------------------------------------
// Approach 4: Using built-in function (GCC/C++)
// Note: Don't mention this in interviews unless asked
// --------------------------------------------------
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        // __builtin_popcount(n) returns the number of set bits in n.
        // Powers of 2 have exactly one set bit (e.g., 4 = 100, 8 = 1000)
        return __builtin_popcount(n) == 1;
    }
};

// Notes:
// - In C++: __builtin_popcount(n) works only with int. For long long, use __builtin_popcountll(n)
// - In Java: Use Integer.bitCount(n)
// - Any number n requires about log₂(n) bits to represent
// - Worst case TC = O(log(n)), but often optimized using hardware instructions ⇒ practically O(1)

// This method is useful for contests or quick checks, not recommended in interviews unless asked.
// Mention only if the interviewer asks for alternative/optimized/built-in solutions.
