class Solution {
public:
int findTheWinner(int n, int k) {
    std::vector<int> v(n);
    std::iota (std::begin(v), std::end(v), 1);
    std::set<int> s(v.begin(), v.end());
    auto it = s.begin(), next = std::next(it);
    int index = 1;
    while (s.size() > 1) {
        for (int i = 0; i < k-1; ++i) {
            ++it;
            if (it == s.end()) {
                it = s.begin();
            }
        }
        next = std::next(it);
        if (it != s.end()) {
            s.erase(it);
        }
        it = next == s.end() ? s.begin() : next;
    }

    return *s.begin();
}
};