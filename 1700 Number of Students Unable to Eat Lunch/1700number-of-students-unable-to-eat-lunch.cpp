class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int counter = 0;

        while (counter < students.size() && !students.empty() && !sandwiches.empty()) {
            if (students.front() == sandwiches.front()) {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                counter = 0;
            } else {
                ++counter;
                const int lastStudent = students.front();
                students.erase(students.begin());
                students.push_back(lastStudent);
            }
        }

        return students.size();
    }
};