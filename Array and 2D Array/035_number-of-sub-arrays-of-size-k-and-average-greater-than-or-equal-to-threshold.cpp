// 35.
// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
// YT : https://www.youtube.com/watch?v=N6RnntEC7M0

// sliding window approach with fixed size of k
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0;              // Left pointer of the sliding window
        int j = 0;              // Right pointer of the sliding window
        int sum = 0;            // Sum of the current window of size k
        int ans = 0;            // Counter for valid subarrays

        // Traverse the array with right pointer j
        while (j < n) {
            sum += arr[j];  // Add current element to the window sum

            // Check if the current window size is exactly k
            if (j - i + 1 == k) {
                // Check if average of the current window is >= threshold
                if ((sum / k) >= threshold) {
                    ans++;  // Valid subarray found
                }

                // Slide the window: remove the leftmost element
                sum -= arr[i];
                i++;  // Move the left pointer
            }

            j++;  // Move the right pointer
        }

        return ans;  // Return total count of valid subarrays
    }
};

//                  Using chatGpt
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int count = 0;

        // Pehle k elements ka sum lo
        for (int i = 0; i < k; ++i) {
            sum += arr[i];
        }

        // Check karo pehla window valid hai ya nahi
        if (sum / k >= threshold) {
            count++;
        }

        // Ab window slide karo ek-ek element se
        for (int i = k; i < n; ++i) {
            sum = sum - arr[i - k] + arr[i];  // window update karo
            if (sum / k >= threshold) {
                count++;
            }
        }

        return count;
    }
};

// TC = O(n)
// SC = O(1)
