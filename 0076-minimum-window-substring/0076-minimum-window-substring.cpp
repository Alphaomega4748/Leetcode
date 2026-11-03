class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }
        int i = 0, j = 0;
        int count = t.size();
        int start = 0;
        int mini = INT_MAX;

        while(j < s.size()) {
            if(mp[s[j]] > 0) {
                count--;
            }

            mp[s[j]]--;
            j++;

            while(count == 0) {
                if(j - i < mini) {
                    mini = j - i;
                    start = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0) {
                    count++;
                }

                i++;
            }
        }
        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};