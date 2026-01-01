class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const long sum = std::accumulate(chalk.begin(), chalk.end(), 0L);
        k = k % sum;
        int studentNum = 0;

        while (k > 0) {
            k -= chalk[studentNum];
            if (k < 0) {
                return studentNum;
            }
            studentNum = (studentNum + 1) % chalk.size();
        }

        return studentNum;
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();