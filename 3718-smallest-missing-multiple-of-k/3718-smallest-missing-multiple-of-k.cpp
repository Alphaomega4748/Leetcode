class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(auto it : nums){
               st.insert(it);
        }

        int x = k;

        while(st.find(x) != st.end()){ // jbb tak set mai found h element tbb tk ye loop chalega 
              x += k;
        }

        return x;
    }
};