class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;

        set<double> st;

        while (left < right) {
            double el = (nums[left] + nums[right]) / 2.0;

            st.insert(el);

            left++;
            right--;
        }

        return st.size();
    }
};