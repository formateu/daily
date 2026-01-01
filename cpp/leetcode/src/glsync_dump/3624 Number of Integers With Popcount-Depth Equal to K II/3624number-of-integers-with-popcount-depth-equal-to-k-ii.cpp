class Solution {
    struct SegmentTree {
        const int N;
        std::vector<int> t;
        SegmentTree(const int n): N(n), t(2*n, 0) {}
        
        void build(const std::vector<int> & vals) {
            std::copy(vals.begin(), vals.begin() + N, t.begin() + N);
            for (int i = N-1; i >= 0; --i) {
                t[i] = t[2*i] + t[2*i + 1];
            }
        }

        int get(int l, int r) {
            int res = 0;
            for (l += N, r+= N; l < r;) {
                if (l % 2 == 1) {
                  res += t[l];
                  ++l;
                }
                if (r % 2 == 1) {
                  --r;
                  res += t[r];
                }
                l = l / 2;
                r = r / 2;
            }

            return res;
        }

        void modify(int p, int value) {
            p += N;
            t[p] = value;
            while (p > 1) {
                p = p / 2;  
                t[p] = t[2*p] + t[2*p + 1];
              }
        }
    };

    int popCountDepth(long long n) {
        if (n <= 1) {
            return 0;
        }

        long long i = n;
        int result = 0;
        while (i) {
            result += (i % 2);
            i /= 2;
        }

        return 1+ popCountDepth(result);
    }
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        const int N = nums.size();
        for (auto &n : nums) {
            n = popCountDepth(n);
        }

        const int K = 7;
        std::vector<SegmentTree> trees(K, N);
        std::vector<int> temp(N);


        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < N; ++j) {
                temp[j] = (nums[j] == i);
            }

            trees[i].build(temp);
        }

        const int Q = queries.size();
        std::vector<int> result;
        for (int i = 0; i < Q; ++i) {
            if (queries[i][0] == 1) {
                const int l = queries[i][1];
                const int r = queries[i][2];
                const int k = queries[i][3];
                result.emplace_back(trees[k].get(l, r+1));
            } else {
                const int idx = queries[i][1];
                const long long val = queries[i][2];
                const long long old = nums[idx];
                trees[old].modify(idx, 0);
                const int new_val = popCountDepth(val);
                trees[new_val].modify(idx, 1);
                nums[idx] = new_val;
            }
        }

        return result;
    }
};