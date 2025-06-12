class Solution {
public:
string robotWithString(string s) {
        array<int,26> freq{};
        for (char c : s) 
            ++freq[c - 'a'];

        string p;
        vector<char> t;
        int smallestChar = 0;
        while (smallestChar < 26 && freq[smallestChar] == 0)
            ++smallestChar;

        for (char c : s) {
            --freq[c - 'a'];
            while (smallestChar < 26 && freq[smallestChar] == 0)
                ++smallestChar;

            t.push_back(c);

            while (!t.empty() && (t.back() - 'a') <= smallestChar) {
                p.push_back(t.back());
                t.pop_back();
            }
        }

        p.append(t.rbegin(), t.rend());
        return p;
    }
};