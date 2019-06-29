//https://leetcode.com/problems/house-robber/
//Dynamic programming, Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return 0;
        
        if(len==1)
            return nums[0];
        
        vector<long> dp(n+1,0);
        dp[1]=nums[0];dp[2]=nums[1];
        long ans=max(nums[0],nums[1]);
        for(int i=3;i<=n;i++){
            dp[i]=nums[i-1];
            dp[i]=max(dp[i]+dp[i-2],dp[i]+dp[i-3]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
