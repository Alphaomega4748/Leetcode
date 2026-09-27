class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        set<int> st;
        for(auto it : nums){
            st.insert(it);
        }
        unordered_map<int,int>freq;

        for(auto x : nums){
            freq[x]++;
        }

        int remaining = nums.size();
        vector<int> ans;

        while(remaining > 0){
            for(auto it : st){
                if(freq[it] > 0){
                    ans.push_back(it);
                    freq[it]--;
                    remaining--;
                }
            }
        }
        return ans;
        
        }
};