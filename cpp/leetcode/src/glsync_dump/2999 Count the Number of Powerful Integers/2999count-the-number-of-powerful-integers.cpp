class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
        return numberOfPowerfulUpTo(finish, limit, s)
             - numberOfPowerfulUpTo(start - 1, limit, s);
    }

private:
    long long numberOfPowerfulUpTo(long long finish, int limit, const string &s) {
        // numeric value of suffix
        long long suffixVal = stoll(s);
        if (finish < suffixVal) return 0;

        string finishS = to_string(finish);
        int n = finishS.size(), m = s.size();

        // if same length, only one candidate
        if (n == m) {
            return (finishS >= s && allDigitsOk(s, limit)) ? 1l : 0l;
        }

        long long count = 0;
        // include the bare suffix itself
        if (allDigitsOk(s, limit)) count++;

        // count lengths between suffix-only and full length
        for (int L = m + 1; L < n; ++L) {
            int spots = L - m - 1;
            long long ways = 1;
            for (int i = 0; i < spots; ++i) ways *= (limit + 1);
            // first digit: 1..limit
            count += limit * ways;
        }

        // now handle full-length (L == n) with upper-bound finish
        int p = n - m;
        // split finish into prefix and suffix parts
        string pref = finishS.substr(0, p);
        string tail = finishS.substr(p);

        // count how many prefixes of length p (no leading zero) <= pref
        long long combos = 0;
        for (int i = 0; i < p; ++i) {
            int digit = finishS[i] - '0';
            int minD = (i == 0 ? 1 : 0);
            int maxD = limit;
            // choices less than finish's digit here
            int lessMax = min(digit - 1, maxD);
            if (lessMax >= minD) {
                long long choices = lessMax - minD + 1;
                // remaining free positions
                long long rem = 1;
                for (int j = i + 1; j < p; ++j) rem *= (limit + 1);
                combos += choices * rem;
            }
            // if this digit exceeds limit, no further exact match
            if (digit > limit) {
                // can't match further prefixes, done
                return count + combos;
            }
            // if we're at last prefix position, consider exact match
            if (i == p - 1) {
                // prefix == finish's prefix, now check suffix
                if (allDigitsOk(s, limit) && s <= tail) {
                    combos += 1;
                }
            }
        }
        return count + combos;
    }

    bool allDigitsOk(const string &x, int limit) {
        for (char c : x) if (c - '0' > limit) return false;
        return true;
    }
};