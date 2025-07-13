12.
https://leetcode.com/problems/3sum/description/
15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
		
        set<vector<int>> s; // ek data structure hota h set naam ka //iske andar jo bhi jata h woh unique hi hota h
        // set<int> // set int, char, bool ka bhi bana skte h 
		// set<char>
		// set<bool>int n=nums.size();
        int n = nums.size();
		for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};//ek vector bana liya temp jo hoga equal to (nums[i],nums[j],nums[k])
                        sort(temp.begin(), temp.end());				//aur fir usko krege sort //ye usse start se and tk sort kr dega //sort isliye kiya kyuki woh use tabhi pakad payega jb array same same hoge sort nhi kroge toh same nhi hoge 
                        // 1,3,4 ye dono same h toh set ek baar hi lega
                        // 1,3,4

						//1,3,4 hume pata h ki ye same h pr set k liye ye alag alag h
						//1,4,3 isliye hum isse sort krege jisse ye bhi 1,3,4 ho jaye aur rk hi set m jaye inme se 
						s.insert(temp);// fir insert kr dege set k andar
                    }
                }
            }
        }
		// fir ans m push krna h hume
        for(auto a : s){ //ye travers krega set k sare element pr jayega 
            ans.push_back(a); //aur ans k andar ek ek krke push krta jayega
        }
        return ans;
    }
};
