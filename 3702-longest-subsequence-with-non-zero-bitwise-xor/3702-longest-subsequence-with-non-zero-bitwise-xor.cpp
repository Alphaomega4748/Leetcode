class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int xorValue = 0;
        int zeroCount = 0;

        for (int num : nums) {

            xorValue ^= num;

            if (num == 0) {
                zeroCount++;
            }
        }

        if (xorValue != 0) {
            return n;
        }

        if (zeroCount == n) {
            return 0;
        }

        return n - 1;
    }
};