class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = n/2;
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
             if(mp[x]>maj){
                return x;
             }
        }
        return 0;
       
    }
};