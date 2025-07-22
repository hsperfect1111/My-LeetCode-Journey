// 27.
// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Union of 2 Sorted with Duplicates
// YT : https://www.youtube.com/watch?v=wvcQg43_V8U

// we hear something like unique : map or set comes to our head
// Do not use unordered set bco2 the odering will get distorted, it will not able to maintain the sorted order that's why use set data structure.
                    // Brute force
// class Solution {
//   public:
//     // a,b : the arrays
//     // Function to return a list containing the union of the two arrays.
//     vector<int> findUnion(vector<int> &a, vector<int> &b) {
//         // Your code here
        
//         set<int> st;
//         int n1 = a.size();
//         int n2 = b.size();
        
//         for(int i=0; i<n1; i++)
//         {
//             st.insert(a[i]);
//         }
//         for(int i=0; i<n2; i++)
//         {
//             st.insert(b[i]);
//         }
        
//         vector<int> result;
//         for(auto it : st)
//         {
//             result.push_back(it);   // if using list aur vector you can write : // union.add(it) or push_back(it);
//         }
        
//         return result; 
        
//         // return vector with correct order of elements
//     }
// };

// Time Complexity:
// Inserting n1 elements of array 'a' into a set takes O(n1 * log n1)
// Inserting n2 elements of array 'b' into the set takes O(n2 * log(n1 + n2)) in the worst case
// Then iterating over the set to copy into a result vector takes O(n1 + n2) in the worst case
// So total time complexity: O(n1 * log n1 + n2 * log(n1 + n2)) + O(n1 + n2)


// Space Complexity:
// O(n1 + n2) for the set (in worst case, all elements are unique)
// O(n1 + n2) for the result vector (since we return the union of both arrays)
// Total space: O(n1 + n2) + O(n1 + n2)

            // Optimal Solution : advantage of array are sorted we will be using two-pointer approach.f
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        
        int n1 = a.size();
        int n2 = b.size();
        int i=0;
        int j=0;
        vector<int> unionArr;
        while(i<n1 && j<n2)
        {
            if(a[i] <= b[j])
            {
                if(unionArr.size()==0 || unionArr.back() != a[i])
                {
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if(unionArr.size()==0 || unionArr.back() != b[j])
                {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        
        // if first array is exhausted mtlb khatam ho gaya to 
        while(j<n2)
        {
            if(unionArr.size()==0 || unionArr.back() != b[j])
                {
                    unionArr.push_back(b[j]);
                }
                j++;
        }
        
        while(i<n1)
        {
            if(unionArr.size()==0 || unionArr.back() != a[i])
                {
                    unionArr.push_back(a[i]);
                }
                i++;
        }
        
        return unionArr;
        
        // return vector with correct order of elements
    }
};

// Time: O(n1 + n2) assuming a and b are already sorted
// Space: O(n1 + n2) in the worst case (for the result vector)
