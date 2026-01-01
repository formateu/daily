class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        long long sum1 = 0, sum2 = 0, result = 0;
        int z1 = 0, z2 = 0;

        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == 0) {
                ++z1;
            } else {
                sum1 += nums1[i];
            }
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (nums2[i] == 0) {
                ++z2;
            } else {
                sum2 += nums2[i];
            }
        }

        sum1 += z1;
        sum2 += z2;

        if (z1 == 0 && sum2 > sum1 || z2 == 0 && sum1 > sum2) {
            return -1;
        }

        return std::max(sum1, sum2);

    }
};