class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int absMinDiff = std::numeric_limits<int>::max();
        int cnt = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (int d = arr[i+1] - arr[i]; d < absMinDiff) {
                absMinDiff = d;
                cnt = 0;
            } else if (d == absMinDiff) { 
                ++cnt;
            }
        }

        std::vector<std::vector<int>> result;
        result.reserve(cnt);

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (int d = arr[i+1] - arr[i]; d == absMinDiff) {
                result.emplace_back(std::vector<int>({arr[i], arr[i+1]}));
            }
        }

        return result;
    }
};