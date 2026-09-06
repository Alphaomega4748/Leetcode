class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;
        // Har possible rotation
        for (int start = 0; start < n; start++) {
            int score = 0;
            // Current rotation ke adjacent pairs check karo
            for (int i = 0; i < n - 1; i++) {

                char a = s[(start + i) % n];
                char b = s[(start + i + 1) % n];

                if (a == b) {
                    score++;
                }
            }
            if (score == k) {
                ans++;
            }
        }
        return ans;
    }
};