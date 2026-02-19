class KMinCostWindow {
public:
    explicit KMinCostWindow(int k): target(k - 1), sum(0) {}

    bool hot() { return low.size() == target; }

    void add(int val) {
        if (low.size() == target && val >= *std::prev(low.end())) {
            high.insert(val);
        } else {
            low.insert(val);
            sum += val;

            if (low.size() > target) {
                auto it = std::prev(low.end());
                sum -= *it;
                high.insert(*it);
                low.erase(it);
            }
        }
    }

    void remove_one(int val) {
        auto itH = high.find(val);
        if (itH != high.end()) {
            high.erase(itH);
            return;
        } else {
            auto itL = low.find(val);
            if (itL == low.end()) {
                return;
            }

            sum -= *itL;
            low.erase(itL);

            if (low.size() < target && !high.empty()) {
                auto it = high.begin();
                sum += *it;
                low.insert(*it);
                high.erase(it);
            }
        }
    }

    long long current_sum() const { return sum; }

private:
    int target;
    long long sum;
    std::multiset<int> low, high;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();
        KMinCostWindow window(k);

        for (int i = 1; i <= dist + 1 && i < N; ++i) {
            window.add(nums[i]);
        }

        long long result = std::numeric_limits<int>::max();

        if (dist + 1 < N) {
            result = window.current_sum();
        }

        for (int i = 2; i + dist < N; ++i) {
            window.remove_one(nums[i - 1]);
            window.add(nums[i + dist]);
            result = std::min(result, window.current_sum());
        }

        return result + nums[0];
    }
};