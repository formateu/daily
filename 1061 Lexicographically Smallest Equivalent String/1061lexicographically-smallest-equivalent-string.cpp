class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        std::array<std::array<bool, 26>, 26> adj{};
        std::array<char, 26> smallest;
        smallest.fill('z' + 1);
        std::array<bool, 26> visited;
        for (int i = 0; i < s1.size(); ++i) {
            adj[s1[i] - 'a'][s2[i] - 'a'] = true;
            adj[s2[i] - 'a'][s1[i] - 'a'] = true;
        }
        
        std::vector<char> stack;
        stack.reserve(26);

        for (int i = 0; i < s1.size(); ++i) {
            if (smallest[s1[i] - 'a'] != 'z' + 1) {
                continue;
            }

            visited.fill(false);
            char min = s1[i];
            stack.emplace_back(s1[i]);

            while (!stack.empty()) {
                char current = stack.back();
                stack.pop_back();
                visited[current - 'a'] = true;
                if (current < min) {
                    min = current;
                }

                for (int j = 0; j < 26; ++j) {
                    if (!visited[j] && adj[current - 'a'][j]) {
                        stack.emplace_back('a' + j);
                    }
                }
            }

            for (int j = 0; j < 26; ++j) {
                if (visited[j] && smallest[j] > min) {
                    smallest[j] = min;
                } 
            }
        }

        for (int i = 0; i < baseStr.size(); ++i) {
            if (smallest[baseStr[i] - 'a'] != 'z' + 1) {
                baseStr[i] = smallest[baseStr[i] - 'a'];
            }
        }

        return baseStr;
    }   
};