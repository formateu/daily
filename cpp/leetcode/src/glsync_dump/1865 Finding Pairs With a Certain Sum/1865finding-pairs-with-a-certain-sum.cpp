class FindSumPairs {
    std::vector<int> nums1_;
    std::vector<int> nums2i_;
    std::unordered_map<int, int> nums2_;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1_(nums1), nums2i_(nums2), nums2_(nums2.size()) {
        for (int i = 0; i < nums2i_.size(); ++i) {
            auto it1 = nums2_.find(nums2i_[i]);
            if (it1 != nums2_.end()) {
                ++nums2_[nums2i_[i]];
            } else {
                nums2_.emplace(nums2[i], 1);
            }
        }
    }
    
    void add(int index, int val) {
        int oldVal = nums2i_[index];
        int newVal = oldVal + val;
        if (nums2_[oldVal] == 1) {
            nums2_.erase(oldVal);
        } else {
            --nums2_[oldVal];
        }

        nums2i_[index] = newVal;
        auto newIt = nums2_.find(newVal);
        if (newIt != nums2_.end()) {
            ++newIt->second;
        } else {
            nums2_.emplace(newVal, 1);
        }
    }
    
    int count(int tot) {
        int result = 0;
        for (auto num: nums1_) {
            int tmp = tot - num;
            if (nums2_.contains(tmp)) {
                result += nums2_[tmp];
            }
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */