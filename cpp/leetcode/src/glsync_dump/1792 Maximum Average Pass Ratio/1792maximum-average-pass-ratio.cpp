class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passes, int totalStudents) {
            return static_cast<double>(passes + 1) / (totalStudents + 1) -
                   static_cast<double>(passes) / totalStudents;
        };

        std::priority_queue<std::pair<double, std::pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += static_cast<double>(classInfo.first) / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};