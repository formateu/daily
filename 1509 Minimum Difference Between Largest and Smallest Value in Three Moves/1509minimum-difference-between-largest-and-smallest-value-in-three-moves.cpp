class Solution {
public:
int minDifference(std::vector<int> &nums) {
  if (nums.size() <= 4) {
    return 0;
  }

  // hint
  // 4 instead of 3 for corner case of arr size 5
  // where 3 smallest and 3 largest are not mutually exclusive sets
  std::multiset<int> min4, max4;

  for (const auto &num : nums) {
    if (min4.empty() || !min4.empty() && min4.size() < 4 ||  min4.size() == 4 && num <= *min4.rbegin()) {
      min4.emplace(num);

      if (min4.size() > 4) {
        min4.erase(--min4.end());
      }
    }

    if (max4.empty() || !max4.empty() && max4.size() < 4 || max4.size() == 4 && num >= *max4.begin()) {
      max4.emplace(num);

      if (max4.size() > 4) {
        max4.erase(max4.begin());
      }
    }
  }

  int result = *max4.rbegin() - *min4.begin();
  auto min = min4.begin();
  auto max = max4.begin();
  for (; min != min4.end(); ++min, ++max) {
    result = std::min(result, *max - *min);
  }

  return result;
}
};