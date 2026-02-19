class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const auto &log : logs) {
            if (log[0] == '.' && log[1] == '.') {
                if (depth ==  0) {
                    continue;
                } else {
                    --depth;
                }
            } else if (log[0] == '.') {
                continue;
            } else {
                ++depth;
            }
        }

        return depth;
    }
};