class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }
        int maxCount = count;

        for(int i = k; i < n; i++){
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' ||
               s[i-k] == 'o' || s[i-k] == 'u') {
                count--;
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u'){
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};