class Solution {
public:
string reverseParentheses(string s) {
    std::vector<char> stack;
    stack.reserve(s.length());

    for (const auto &c: s) {
        if (c != ')') {
            stack.emplace_back(c);
        } else {
            const auto openP = std::find(stack.rbegin(), stack.rend(), '(');
            std::string revSub(stack.rbegin(), openP);
            stack.erase(--openP.base(), stack.end());
            stack.insert(stack.end(), revSub.begin(), revSub.end());
        }
    }
    return std::string(stack.begin(), stack.end());
}
};