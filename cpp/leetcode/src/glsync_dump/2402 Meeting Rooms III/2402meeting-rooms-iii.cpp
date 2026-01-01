class Solution {
    template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<>>;
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        MinHeap<int> freeRooms;
        MinHeap<std::pair<std::int64_t, int>> busy;
        std::vector<int> meetingCount(n, 0);

        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

        for (const auto &m: meetings) {
            std::int64_t start = m.front();
            std::int64_t end = m.back();

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (freeRooms.empty()) {
                auto [earliestEnd, room] = busy.top();
                busy.pop();
                std::int64_t delay = earliestEnd - start;
                start += delay;
                end += delay;
                freeRooms.push(room);
            }

            int room = freeRooms.top();
            freeRooms.pop();
            ++meetingCount[room];
            busy.emplace(end, room);
        }

        int result = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > max) {
                max = meetingCount[i];
                result = i;
            }
        }

        return result;

    }
};