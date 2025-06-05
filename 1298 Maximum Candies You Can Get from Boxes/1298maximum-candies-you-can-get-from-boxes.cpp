class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        std::vector<int> stack;
        std::vector<char> waiting(status.size(), false);

        for (const auto &box: initialBoxes) {
            if (status[box] == 1) {
                stack.emplace_back(box);
            } else {
                waiting[box] = true;
            }
        }

        int result = 0;
        
        while (!stack.empty()) {
            int current = stack.back();
            stack.pop_back();
            result += candies[current];
            for (const auto &box: keys[current]) {
                status[box] = 1;
                if (waiting[box]) {
                    waiting[box] = false;
                    stack.emplace_back(box);
                }
            }

            for (const auto &box: containedBoxes[current]) {
                if (status[box] == 1) {
                    stack.emplace_back(box);
                } else {
                    waiting[box] = true;
                }
            }
        }

        return result;   
    }
};