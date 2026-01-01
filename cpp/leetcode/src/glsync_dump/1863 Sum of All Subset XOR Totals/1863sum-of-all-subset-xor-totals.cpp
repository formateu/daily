class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return recursiveCountFromPosition(0, 0, nums);
    }

    int recursiveCountFromPosition(int pos, int currentXor, const vector<int> &nums) {
        if (pos == nums.size()) {
            return 0;
        }

        int currentNew = currentXor ^ nums[pos];
        
        int followingWithPos = recursiveCountFromPosition(pos+1, currentNew, nums);
        int followingWithoutPos = recursiveCountFromPosition(pos+1, currentXor, nums);

        return currentNew + followingWithPos + followingWithoutPos;
    }
};