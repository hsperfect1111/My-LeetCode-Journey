3.
50. Pow(x, n)
https://leetcode.com/problems/powx-n/description/
YT : https://www.youtube.com/watch?v=7wcJXZoGKMI

class Solution {
public:
    // why double and long : Because the problem (like LeetCode 50. Pow(x, n)) asks for computing powers of floating-point numbers — like 2.1^3
    double solve(double x, long n)
    {
        if(n == 0) 
            return 1;

        if(n < 0)
        {
            return solve(1/x, -n);
        }

        if(n%2 == 0) 
            return solve(x*x, n/2);
        
        return x*solve(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
        // why long
        // long n: You wrote long n to handle the case when n is negative, especially when n == INT_MIN (which is -2,147,483,648). In C++, the range of int is typically from -2^31 to 2^31 - 1
        return solve(x, (long)n);
    }
};
	
// Time Complexity (TC): O(log n)
// → Because each recursive call divides n by 2 (binary exponentiation)

// Space Complexity (SC): O(log n)
// → Due to recursion stack depth up to log n

