// 7.
// https://leetcode.com/problems/friends-of-appropriate-ages/description/
// 825. Friends Of Appropriate Ages
// NOTE : Solved by using ChatGPT but through understanding 

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // Har age ka count nikal lo
        // "Har age ka count nikal lo" ka logic:
        // Imagine karo input ye hai:
        // ages = [16, 16, 17, 18, 18, 18]
        // Ab hume baar baar ye check karna padta hai ki kisi age ke kitne log hain. Agar hum har baar ages array ko loop karte, toh time lagta zyada.
        // Toh hum ek frequency array bana lete hain jiska index = age, aur value = us age ke log kitne hain.
        vector<int> count(121, 0);
        for(int age : ages) {
            count[age]++;
        }

        // Yahaan total ek variable hai jo total friend requests ka count store karega.
        int total = 0;

        // Har age ke combination k liye check karo
        for(int ageA = 1; ageA <= 120; ageA++)
        {
            for(int ageB = 1; ageB <= 120; ageB++)
            {
                // Agar kisi age ka count 0 hai toh skip
                // Agar kisi age ka count 0 hai toh skip kyu kar rahe hain?
                // Agar kisi age ke log hi nahi hain, toh unse ya unke liye koi friend request possible hi nahi hai.
                if(count[ageA] == 0 || count[ageB] == 0) continue;
                
                // Rules check karo
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;

                // Agar dono ki age same h 
                if(ageA == ageB)
                {
                    total += count[ageA] * (count[ageA] - 1); // khud ko request nahi
                }
                else 
                {
                    total += count[ageA] * count[ageB];
                }
            }
        }
        return total;
    }
};
