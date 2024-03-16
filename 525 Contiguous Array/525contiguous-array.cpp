#include <unordered_map>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size(), res=0, diff = 0;

        unordered_map<int, int>m;
        m[0] = -1;

        for(int i=0; i<n; ++i)
        {
            if(nums[i] == 1)
                ++diff;

            else
                --diff;
            
            if(m.find(diff) == m.end())
                m[diff] = i;
            else
                res = max(res, i - m[diff]);
        }

        return res;
    }
};