class Solution {
public:
    int takeCharacters(string s, int k) {
        int totalA = 0, totalB = 0, totalC = 0;
        int result = s.size();
        for (const auto &c : s) {
            if (c == 'a') ++totalA;
            if (c == 'b') ++totalB;
            if (c == 'c') ++totalC;
        }

        if (totalA < k || totalB < k || totalC < k) {
            return -1;
        }

        int a = 0, b = 0, c = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] == 'a') ++a;
            if (s[r] == 'b') ++b;
            if (s[r] == 'c') ++c;
            ++r;

            while (a > totalA - k || b > totalB - k || c > totalC - k) {
                if (s[l] == 'a') --a;
                if (s[l] == 'b') --b;
                if (s[l] == 'c') --c;
                ++l;

            }

            result = std::min(result, static_cast<int>(s.size()) - (r - l));
        }

        return result;
    }
};