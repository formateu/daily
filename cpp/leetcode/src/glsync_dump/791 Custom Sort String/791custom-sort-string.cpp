#include <unordered_map>
#include <algorithm>

class Solution {
public:
    string customSortString(string order, string s) {
        std::unordered_map<char, short> orderMap(order.length());
        for (short i = 0; i< order.length(); ++i) {
            orderMap.emplace(order[i], i);
        }

        std::sort(s.begin(), s.end(), [&orderMap](char a, char b)
                            {
                                return orderMap[a] < orderMap[b];
                            });

        return s;
    }
};