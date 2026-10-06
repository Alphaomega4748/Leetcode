class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int>mpp;
        int maj = n/3;

        for(auto it : nums){
             mpp[it]++;
        }

       for (const auto &x : mpp) {
             if (x.second > maj) ans.push_back(x.first);
          }
        return ans;
    }
};