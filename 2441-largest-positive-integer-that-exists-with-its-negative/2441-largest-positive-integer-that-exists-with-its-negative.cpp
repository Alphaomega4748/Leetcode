class Solution {
public:
    int findMaxK(vector<int>& nums) {
         int n = nums.size();
         unordered_set<int>st;

         for(auto it : nums){
            st.insert(it);
         }

         int ans = -1;
         
         for(auto x : nums){
            if(x > 0 && st.find(-x) != st.end()){
                ans = max(ans, x);
            }
         }
         return ans;
    }
};