class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(auto it : nums){
               st.insert(it);
        }

        int x = k;

        while(st.find(x) != st.end()){
              x += k;
        }

        return x;
    }
};