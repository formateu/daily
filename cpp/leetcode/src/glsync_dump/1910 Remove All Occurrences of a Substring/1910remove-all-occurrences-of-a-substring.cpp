class Solution {
public:
    string removeOccurrences(string s, string part) {
        std::vector<char> stack;
        stack.reserve(s.size()); 
        for (const auto &c : s) {
            stack.emplace_back(c);
            
            if (stack.size() >= part.size()) {
                std::string_view last_n_view(stack.data() + stack.size() - part.size(), part.size());
                if (last_n_view == part) {
                    // Remove the matched substring
                    stack.resize(stack.size() - part.size());
                }
            }
        }

        // Final cleanup in case there are consecutive occurrences at the end.
        // (This loop may not be necessary depending on your algorithm logic.)
        while (stack.size() >= part.size()) {
            std::string_view last_n_view(stack.data() + stack.size() - part.size(), part.size());
            if (last_n_view == part) {
                stack.resize(stack.size() - part.size());
            } else {
                break;
            }
        }

        return std::string(stack.data(), stack.size());
    }
};