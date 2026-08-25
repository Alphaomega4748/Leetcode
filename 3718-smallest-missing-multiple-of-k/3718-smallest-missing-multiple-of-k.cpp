class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for(auto x : nums) {
            mpp[x]++;
        }

        int num = 1;

        while(true) {
            int ans = k * num;

            if(mpp.find(ans) == mpp.end()) {
                return ans;
            }

            num++;
        }
    }
};