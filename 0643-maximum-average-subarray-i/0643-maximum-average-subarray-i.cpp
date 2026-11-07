class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int winSum = 0;

        for(int i = 0; i<k; i++){
            winSum += nums[i];
        }
        int maxSum = winSum ;

        for(int i =k; i<n; i++){
            winSum += nums[i] - nums[i-k];
            maxSum = max(winSum , maxSum);
        }
        return (double)maxSum/k;
    }
};