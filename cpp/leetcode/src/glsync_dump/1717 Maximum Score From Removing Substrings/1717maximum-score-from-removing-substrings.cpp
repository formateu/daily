class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (s.size() < 2) {
            return 0;
        }
        std::vector<char> st;
        st.reserve(s.size());
        int score = 0;
        int i = 2;
        st.push_back(s[0]);
        st.push_back(s[1]);

        std::string op1, op2;
        int p1, p2;
        if (x > y) {
            op1 = "ab";  p1 = x;
            op2 = "ba";  p2 = y;
        } else {
            op1 = "ba";  p1 = y;
            op2 = "ab";  p2 = x;
        }

        while (i < s.size()) {
            if (st.size() >= 2 && st[st.size()-2] == op1[0] && st[st.size()-1] == op1[1]) {
                score += p1;
                st.pop_back();
                st.pop_back();
            } else {
                st.push_back(s[i++]);
            }
        }
        while (st.size() >= 2 && st[st.size()-2] == op1[0] && st[st.size()-1] == op1[1]) {
            score += p1;
            st.pop_back();
            st.pop_back();
        }

        std::vector<char> st2;
        st2.reserve(st.size());
        for (char c : st) {
            if (!st2.empty() && st2.back() == op2[0] && c == op2[1]) {
                score += p2;
                st2.pop_back();
            } else {
                st2.push_back(c);
            }
        }

        return score;
    }
};