class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::unordered_map<int, int> freq;
        for (int i : arr) {
            ++freq[i];
        }

        int max = -1;
        
        for (const auto &[k, v] : freq) {
            if (k == v && k > max) {
                max = k;
            }
        }

        return max;
    }
};