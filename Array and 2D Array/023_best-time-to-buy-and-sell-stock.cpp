// 23.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Sabse pehle, hum mini variable ko set karte hain jo ki minimum stock price ko track karega.
        int mini = prices[0];
        // Yahan par maxProfit ko 0 set kar rahe hain, kyunki ab tak koi profit nahi hua hai. Hum is variable mein apna maximum profit track karenge.   
        int maxProfit = 0;  
        int n = prices.size();
        for(int i=0; i<n; i++)
        {
            // Har iteration mein, hum cost calculate karte hain jo current stock price (prices[i]) aur ab tak ka minimum price (mini) ka difference hota hai. Har iteration mein, hum cost calculate karte hain jo current stock price (prices[i]) aur ab tak ka minimum price (mini) ka difference hota hai. Har iteration mein, hum cost calculate karte hain jo current stock price (prices[i]) aur ab tak ka minimum price (mini) ka difference hota hai. Yeh difference potential profit hai agar hum abhi sell karte hain.
            int cost = prices[i] - mini;    
            // Ab hum maxProfit ko update karte hain. Agar abhi tak ka profit (cost) zyada hai, toh maxProfit ko update karte hain.
            maxProfit = max(maxProfit, cost); 
            // hum mini ko update karte hain, taki woh ab tak ke lowest stock price ko track kar sake. Agar current price (prices[i]) chhota hai, toh mini ko update karenge.  
            mini = min(mini, prices[i]); 
        }
        return maxProfit;
        
    }
};
