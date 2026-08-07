class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for(int num : nums){

            prefix += num;

            int rem = ((prefix % k) + k) % k;

            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};