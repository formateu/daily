class Solution {
public:
    int punishmentNumber(int n) {
        int result = 1;

        for (int i = 2; i <= n; ++i) {
            if (checkNumber(i*i, 0, i, 1)) {
                result += i*i;
            }
        }

        return result;
    }

    bool checkNumber(int value, int suffix, int n, int padding) {
        if (value == 0) {
            return suffix == n;
        }

        if (suffix > n) {
            return false;
        }

        if (checkNumber(value / 10, suffix + value % 10, n, 10)) {
            return true;
        }

        if (checkNumber(value / 10, suffix + (value % 10)* padding, n, padding* 10)) {
            return true;
        }

        return false;
    }
};