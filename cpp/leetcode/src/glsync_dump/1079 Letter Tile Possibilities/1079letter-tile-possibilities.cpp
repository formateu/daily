class Solution {
public:
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 1) {
            return 1;
        }

        std::array<int, 26> initOcc{};
        for (auto c: tiles) {
            ++initOcc[c - 'A'];
        }

        return recursivePossibilities(initOcc);
    }
private:
    int recursivePossibilities(std::array<int, 26> &occ) {
        int result = 0;
        for (auto &i : occ) {
            if (i > 0) {
                --i;
                result += 1 + recursivePossibilities(occ);
                ++i;
            }
        }

        return result;
    }
};