class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        std::vector<int> fruitSearchWindow(2*k+1, 0);
        int closestFruitPos = binsearchClosest(fruits, startPos, 0, fruits.size() - 1);
        if (std::abs(fruits[closestFruitPos][0] - startPos) > k) {
            return 0;
        }

        int startFruit = 0;
        if (fruits[closestFruitPos][0] == startPos) startFruit = fruits[closestFruitPos][1];

        // left pass
        int leftIdx = -1;
        if (fruits[closestFruitPos][0] == startPos) {
            leftIdx = closestFruitPos;
        } else if (fruits[closestFruitPos][0] < startPos) {
            leftIdx = closestFruitPos;
        } else if (closestFruitPos > 0) {
            leftIdx = closestFruitPos - 1;
        }

        if (leftIdx != -1) {
            int last = 0;
            int leftSteps = startPos - fruits[leftIdx][0];
            for (; leftSteps <= k && leftIdx >= 0; ) {
                fruitSearchWindow[k - leftSteps] = last + fruits[leftIdx][1];
                last = fruitSearchWindow[k - leftSteps];

                int prevPos = fruits[leftIdx][0];
                --leftIdx;
                if (leftIdx < 0) break;
                leftSteps += prevPos - fruits[leftIdx][0];
            }
        }

        for (int i = k - 1; i >= 0; --i) {
            fruitSearchWindow[i] = std::max(fruitSearchWindow[i], fruitSearchWindow[i + 1]);
        }

        // right pass
        int rightIdx = -1;
        if (fruits[closestFruitPos][0] == startPos) {
            rightIdx = closestFruitPos;
        } else if (fruits[closestFruitPos][0] > startPos) {
            rightIdx = closestFruitPos;
        } else if (closestFruitPos + 1 < fruits.size()) {
            rightIdx = closestFruitPos + 1;
        }

        if (rightIdx != -1) {
            int last = 0;
            int rightSteps = fruits[rightIdx][0] - startPos;
            for (; rightSteps <= k && rightIdx < fruits.size(); ) {
                fruitSearchWindow[k + rightSteps] = last + fruits[rightIdx][1];
                last = fruitSearchWindow[k + rightSteps];

                int prevPos = fruits[rightIdx][0];
                ++rightIdx;
                if (rightIdx >= fruits.size()) break;
                rightSteps += fruits[rightIdx][0] - prevPos;
            }
        }

        for (int i = k + 1; i <= 2 * k; ++i) {
            fruitSearchWindow[i] = std::max(fruitSearchWindow[i], fruitSearchWindow[i - 1]);
        }

        int result = 0;
        for (int d = 0; d <= k; ++d) {
            int t = k - 2*d;
            if (t < 0) continue;

            int leftThenRight = fruitSearchWindow[k - d] + fruitSearchWindow[k + t] - startFruit;
            int rightThenLeft = fruitSearchWindow[k + d] + fruitSearchWindow[k - t] - startFruit;

            result = std::max(result, std::max(leftThenRight, rightThenLeft));
        }

        return result;   
    }

    int binsearchClosest(const auto &fruits, int startPos, int l, int r) {
        while (l + 1 < r) {
            int p = l + (r - l) / 2;
            if (fruits[p][0] == startPos) {
                return p;
            } else if (fruits[p][0] < startPos) {
                l = p;
            } else {
                r = p;
            }
        }

        if (std::abs(fruits[l][0] - startPos) <= std::abs(fruits[r][0] - startPos)) {
            return l;
        } else {
            return r;
        }
    }
};