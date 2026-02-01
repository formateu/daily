class Solution {
public:
    int minimumCost(vector<int>& nums) {
        std::priority_queue<int> pq;
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pq.push(nums[i]);
            result += nums[i];
            if (pq.size() > 2) {
                result -= pq.top();
                pq.pop();
            } 
        }

        return result;
    }
};