class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int N = startTime.size();
        std::vector<int> prefixBestGap(N), suffixBestGap(N);

        prefixBestGap[0] = startTime[0];
        for (int i = 1; i < N; ++i) {
            prefixBestGap[i] = std::max(prefixBestGap[i-1], startTime[i] - endTime[i-1]);
        }

        suffixBestGap[N-1] = eventTime - endTime.back();
        for (int i = N-2; i >= 0; --i) {
            suffixBestGap[i] = std::max(suffixBestGap[i+1], startTime[i+1] - endTime[i]);
        }
        int result = 0;

        for (int i = 0; i < N; ++i) {
            const int l = endTime[i] - startTime[i];
            int left = i == 0 ? 0 : endTime[i-1];
            int right = (i == (N-1)) ? eventTime : startTime[i+1];
            if ((i > 0 && l <= prefixBestGap[i-1]) || i+1 < N && l <= suffixBestGap[i+1]) {
                result = std::max(result, right - left);
            } else {
                result = std::max(result, right - left - l);
            }
        }

        return result;
    }
};