// 5.
// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
public:

    // This vector will store all the valid combinations found.
    vector<vector<int>> answer = {}; // This will store the final answer, a vector of vector of integers.

    // This vector will keep track of the current combination we are building.
    vector<int> currentSeq = {}; // This keeps the current combination (sequence of numbers we are choosing).

    // Recursion function to explore all combinations
    // target: The remaining sum we need to achieve.
    // candidates: The list of available numbers we can choose from.
    // start: The index in the candidates array from where we should start choosing next.
    void recursion(int target, vector<int>& candidates, int start) {
        
        // If the target is 0, it means we've found a valid combination.
        if (target == 0) {
            answer.push_back(currentSeq); // Add the current combination to the answer list.
            return;
        }

        // Loop through the candidates starting from the 'start' index.
        for (int i = start; i < candidates.size(); i++) {
            
            // We can only consider the current candidate if it doesn't exceed the target.
            if (target >= candidates[i]) {
                
                // Choose the current candidate.
                currentSeq.push_back(candidates[i]);

                // Recursively try to find the remaining combination for the reduced target.
                // Since we can reuse the same number, we pass 'i' again (not 'i+1').
                recursion(target - candidates[i], candidates, i);

                // After exploring, backtrack by removing the last element (undo the choice).
                currentSeq.pop_back();
            }
        }
    }

    // Main function that calls the recursion function
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        // Start the recursion with an initial target and starting index of 0.
        recursion(target, candidates, 0);

        // Return the final answer containing all valid combinations.
        return answer;
    }
};
