class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int N = startTime.size();
        std::vector<int> prefixEventSize(N);
        prefixEventSize[0] = endTime[0] - startTime[0];
        for (int i = 1; i < N; ++i) {
            prefixEventSize[i] = prefixEventSize[i-1] + endTime[i] - startTime[i];            
        }

        int result = 0;
        for (int i = 0; i+k <= N; ++i) {
            int prev = (i == 0) ? 0 : endTime[i-1];
            int end = 0;
            if (i+k >= N) {
                end = std::max(endTime.back(), eventTime);
            } else {
                end = startTime[i+k];
            }
            int windowEventSize = prefixEventSize[i+k-1];
            if (i > 0) {
                windowEventSize -= prefixEventSize[i-1];
            }
            result = std::max(result, end - prev - windowEventSize);
        }

        return result;
    }
};