class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      std::unordered_map<int,int> nums_s;
      int maxLen = 0;
      for(int num: nums) {
        if (!nums_s[num]) {
            int left  = nums_s[num-1];   
            int right = nums_s[num+1];   
            int currLen = left + right + 1;

            nums_s[num] = currLen;
            nums_s[num - left]  = currLen;
            nums_s[num + right] = currLen;

            maxLen = std::max(maxLen, currLen);
        }
      }
      return maxLen;
    }

};