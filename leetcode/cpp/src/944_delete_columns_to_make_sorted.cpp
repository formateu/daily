#include <vector>
#include <string>

namespace lc::p0944 {
int minDeletionSize(const std::vector<std::string>& strs) {
    int result = 0;
    for (std::size_t i = 0; i < strs[0].size(); ++i) {
        for (std::size_t prev = 0, curr = 1; curr < strs.size(); ++curr, ++prev) {
            if (strs[prev][i] > strs[curr][i]) {
                ++result;
                break;
            }
        }
    }

    return result;
}
} //namespace lc::p0944

#if defined(LC_ENABLE_TESTS) && LC_ENABLE_TESTS
#include <gtest/gtest.h>

TEST(P0944_DeleteColumnsToMakeSorted, Example1) {
    const std::vector<std::string> strs{"cba", "daf", "ghi"};
    EXPECT_EQ(lc::p0944::minDeletionSize(strs), 1);
}

TEST(P0944_DeleteColumnsToMakeSorted, Example2) {
    const std::vector<std::string> strs{"a", "b"};
    EXPECT_EQ(lc::p0944::minDeletionSize(strs), 0);
}

TEST(P0944_DeleteColumnsToMakeSorted, Example3) {
    const std::vector<std::string> strs{"zyx", "wvu", "tsr"};
    EXPECT_EQ(lc::p0944::minDeletionSize(strs), 3);
}

#endif