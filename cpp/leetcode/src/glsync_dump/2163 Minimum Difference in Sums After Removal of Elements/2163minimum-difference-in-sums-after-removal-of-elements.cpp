class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        constexpr long long MAX = 9007199254740991LL;
        const int n = nums.size() / 3;

        std::priority_queue<int> max_heap(nums.begin(), nums.begin() + n);
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin() + 2*n, nums.end()); 

        long long sum_f = 0, sum_s = 0;

        for (int i = 0; i < n; ++i) {
            sum_f += nums[i];
        }

        for (int i = 3*n - 1; i >= 2*n; --i) {
            sum_s += nums[i];
        }

        std::vector<long long> sums_first(nums.size(), MAX);
        std::vector<long long> sums_second(nums.size(), MAX);

        sums_first[n - 1]  = sum_f;
        sums_second[2 * n] = sum_s;

        for (int i = n; i < 3*n; ++i) {
            if (int biggest = max_heap.top(); nums[i] < biggest) {
                max_heap.pop();
                max_heap.push(nums[i]);
                sum_f += nums[i] - biggest;
            }
            sums_first[i] = sum_f;

        }

        for (int i = 2*n-1; i >= 0; --i) {
            if (int smallest = min_heap.top(); nums[i] > smallest) {
                min_heap.pop();
                min_heap.push(nums[i]);
                sum_s += nums[i] - smallest;
            }
            sums_second[i] = sum_s;

        }

        long long result = MAX;
        for (int i = n-1; i < 2*n; ++i) {
            if (sums_first[i] != MAX && sums_second[i+1] != MAX) {
                result = std::min(result, sums_first[i] - sums_second[i+1]);
            }
        }

        return result;
    }
};