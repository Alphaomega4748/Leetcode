class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = INT_MAX;

        if(k == 1){
            return 0;
        }
        for(int i = 0; i <= n-k; i++){
            mini = min(mini, nums[i+k-1] - nums[i]);
        }
        return mini;
    }
};