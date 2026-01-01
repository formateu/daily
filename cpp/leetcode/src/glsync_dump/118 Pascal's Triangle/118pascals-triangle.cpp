class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;

        result.push_back({1});
        
        for (int i = 1; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1);
            const vector<int>& prev = result.back();
            
            for (int j = 1; j < i; ++j) {
                row[j] = prev[j - 1] + prev[j];
            }
            
            result.push_back(row);
        }
        
        return result;
    }
};