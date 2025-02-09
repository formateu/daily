class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::unordered_set<int> uniqueA(A.size()), uniqueB(B.size());
        int counter = 0;
        std::vector<int> result(A.size());
        uniqueA.emplace(A[0]);
        uniqueB.emplace(B[0]);

        if (A[0] == B[0]) {
            ++counter;
            result[0] = counter;
        } else {
            result[0] = 0;
        }

        for (int i = 1; i < A.size(); ++i) {
            bool a = false, b = false;
            if (!uniqueA.contains(A[i])) {
                uniqueA.emplace(A[i]);
            }

            if (!uniqueB.contains(B[i])) {
                uniqueB.emplace(B[i]);
            }

            if (A[i] == B[i]) {
                ++counter;
            } else {
                if (uniqueA.contains(B[i])) ++counter;
                if (uniqueB.contains(A[i])) ++counter;
            }

            result[i] = counter;
        }

        return result;
    }
};