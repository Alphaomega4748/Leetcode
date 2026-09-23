class Solution {
public:
    int missingNumber(vector<int>& nums) {
      
          int n = nums.size();
          int nsum = n*(n+1)/2;
          int totSum = 0;

        for(int i = 0; i<n; i++){
            totSum += nums[i];
        }

    return nsum - totSum;

    }
};