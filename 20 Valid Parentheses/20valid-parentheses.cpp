class Solution {
public:
    bool isValid(string s) {
        std::vector<char> st;
        st.reserve(s.size());
        // st.push_back(s[0]);
        for (char c: s) {
            if (!st.empty()) {
                if (st.back() == '(' && c == ')') {
                    st.pop_back();
                } else if (st.back() == '[' && c == ']') {
                    st.pop_back();
                } else if (st.back() == '{' && c == '}') {
                    st.pop_back();
                } else {
                    st.push_back(c);
                }
            } else {
                st.push_back(c);
            }
        }

        return st.empty();
    }
};