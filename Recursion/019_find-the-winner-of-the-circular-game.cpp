// 19.
// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
// YT : https://www.youtube.com/watch?v=lq3RMxKST-Y&t=848s

// using Array
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> arr;
//         // Yahaan pe loop 1 se shuru ho raha hai kyunki aap arr vector me 1 se n tak ke players ko dal rahe ho. Lekin problem statement me log usually numbering 1-based dete hain (player 1, 2, ..., n), isliye yeh loop 1 se start kiya gaya.
//         for(int i=1; i<=n; i++)
//         {
//             arr.push_back(i);
//         }

//         // Yahaan i ka use current index track karne ke liye ho raha hai, array ke index ke hisaab se.
//         int i=0;

//         while(arr.size() > 1)   // n
//         {
//             int idx = (i+k-1) % arr.size();

//             arr.erase(arr.begin() + idx);   // n

//             i = idx;
//         }

//         return arr[0];
//     }
// };

// Tc = O(n^2)

// Using Queue 
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> que;
//         for(int i=1; i<=n; i++)
//         {
//             que.push(i);
//         }

//         while(que.size() > 1)
//         {
//             // Har round me aap k-th person ko eliminate karte ho.
//             // Lekin usse pehle, aap k-1 logon ko pass karte ho (yaani queue ke aage se hata kar peeche bhej dete ho).
//             for(int count = 1; count <= k-1; count++)
//             {
//                 que.push(que.front());
//                 que.pop();
//             }
//             que.pop();
//         }
//         return que.front();
//     }
// };

// using Recursion : If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
// Note : ye solution love babbar ki video se h kyuki ye wala samjh m aa raha h easily codewithmic ka samjh m nhi aaya tha : https://www.youtube.com/watch?v=gAZwWpv_GUM
class Solution {
public:
    int solve(int n , int k)
    {
        if(n==1)
        {
            return 0;
        }

        // agar ek player bhad raha h to k iteration or lagege
        return (solve(n-1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        // Final +1 karte hain kyunki question me players 1-based hain (1, 2, 3...), par index 0-based tha.
        // later add +1 inside the function because mode gives the answer zero, I need to get its answer returned through 1-based indexing/
        int ans = solve(n, k) + 1;
        return ans;
    }
};

// codewithmike ka solution samajh nhi aaya tha
// class Solution {
// public:
//     int findWinnerIdx(int n, int k)
//     {
//         if(n == 1)
//         {
//             return 0;
//         }

//         // n-1 pass karte hain kyunki har step me ek banda eliminate ho chuka hota hai.
//         int idx = findWinnerIdx(n-1, k);
//         idx = (idx+k) % n;  // to find the original index in the original array

//         return idx;
//     }

//     int findTheWinner(int n, int k) {
        
//         int result_idx = findWinnerIdx(n, k);

//         // Final +1 karte hain kyunki question me players 1-based hain (1, 2, 3...), par index 0-based tha.
//         return result_idx + 1;

//     }
// };
