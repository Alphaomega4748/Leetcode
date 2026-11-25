class Solution {
public:
    int solve(int i , int l , vector<int>&nums, vector<int> & dp){
        if(i<l) return 0;
        if(i == l) return nums[i];

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i-2, l, nums, dp);
        int skip = solve(i-1, l, nums, dp);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n,-1);

        int caseA = solve(n-2, 0, nums, dp1);
        int caseB = solve(n-1, 1, nums, dp2);

        return max(caseA, caseB);
    }
};