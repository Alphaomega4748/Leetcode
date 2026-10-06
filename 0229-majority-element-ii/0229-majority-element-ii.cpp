class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
              int cnt1 = 0;
              int cnt2 = 0;
              int el1 = INT_MIN;
              int el2 = INT_MIN;

              for(auto x : nums) {
                if(cnt1 == 0 && x != el2){
                    cnt1 = 1;
                    el1 = x;
                }
                else if (cnt2 == 0 && x != el1) {
                   cnt2 = 1;
                   el2 = x;
                }else if(x == el1) cnt1++;
                else if(x == el2)  cnt2++;
                else{
                    cnt1--;
                    cnt2--;
                }

              } 

                cnt1 = 0; cnt2 = 0;
        for (int x : nums) {
            if (x == el1) cnt1++;
            else if (x == el2) cnt2++;
        }

        vector<int> ans;
        int need = nums.size() / 3;
        if (cnt1 > need) ans.push_back(el1);
        if (cnt2 > need) ans.push_back(el2);
        return ans;
    
    }
};