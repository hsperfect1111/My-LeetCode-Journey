// 14.
// https://www.lintcode.com/problem/3691/
// 3691 · Dot Product of Two Sparse Vectors

#include <iostream>
#include <vector>
#include <unordered_map>

class SparseVector {
public:
    // Constructor to initialize the SparseVector with non-zero elements
    SparseVector(std::vector<int>& nums) {
        // Store non-zero elements in a hashmap (index -> value)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                non_zero_elements[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;

        // Iterate through the non-zero elements of the current vector
        for (const auto& [index, value] : non_zero_elements) {
            // Check if the current index exists in the other vector
            if (vec.non_zero_elements.find(index) != vec.non_zero_elements.end()) {
                // If the index exists in both vectors, compute the product
                result += value * vec.non_zero_elements.at(index);
            }
        }
        return result;
    }

private:
    // Map to store non-zero elements and their indices
    std::unordered_map<int, int> non_zero_elements;
};

int main() {
    // Test Case 1
    std::vector<int> nums1 = {0, 0, 1, 2, 0, 3};
    std::vector<int> nums2 = {4, 0, 1, 0, 0, 3};
    
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    
    // Output the dot product
    std::cout << "Dot Product (Test Case 1): " << v1.dotProduct(v2) << std::endl;  // Output: 10

    // Test Case 2
    std::vector<int> nums3 = {1, 0, 0, 0};
    std::vector<int> nums4 = {0, 0, 2, 0};
    
    SparseVector v3(nums3);
    SparseVector v4(nums4);
    
    // Output the dot product
    std::cout << "Dot Product (Test Case 2): " << v3.dotProduct(v4) << std::endl;  // Output: 0

    return 0;
}
