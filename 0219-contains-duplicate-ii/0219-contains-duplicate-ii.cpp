class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> st;

        for (int right = 0; right < nums.size(); right++) {

            if (st.count(nums[right])) {
                return true;
            }
            st.insert(nums[right]);
            if (st.size() > k) {
                st.erase(nums[right - k]);
            }
        }
        return false;
    }
};