class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mpp;
        int left = 0;
        int ans = 0;
           
           for(int right =0; right<s.length(); right++){
            mpp[s[right]]++;

            while(mpp[s[right]] > 2){
                mpp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left +1);
           }
           return ans;
    }
};