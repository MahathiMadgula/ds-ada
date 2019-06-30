//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//#121. Best Time to Buy and Sell Stock
//O(N) time and O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=INT_MAX,sell=INT_MIN,diff=0,temp=0;
        for(int i=0;i<n;i++){
            if(prices[i]<buy){
                //Sice we can't sell before we buy
                buy=prices[i];
                sell=INT_MIN;
                temp=0;
            }
            if(prices[i]>sell){
                sell=prices[i];
            }
            if(buy!=INT_MAX && sell!=INT_MIN){
                temp=sell-buy;
                diff=max(diff,temp);
            }
        }
        return diff;
    }
};
