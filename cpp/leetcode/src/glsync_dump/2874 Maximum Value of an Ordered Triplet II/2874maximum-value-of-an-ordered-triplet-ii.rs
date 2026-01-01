impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut res: i64 = 0;
        let mut leftMax: Vec<i64> = vec![0; nums.len()];
        let mut rightMax: Vec<i64> = vec![0; nums.len()];
        leftMax[0] = nums[0] as i64;
        rightMax[nums.len() - 1] = nums[nums.len() - 1] as i64;
                for i in 1..nums.len() {
        leftMax[i] = std::cmp::max(leftMax[i-1], nums[i] as i64);
        }
        for i in (0..=nums.len()-2).rev() {
            rightMax[i] = std::cmp::max(rightMax[i+1], nums[i] as i64)
        }

        for j in (1..=nums.len()-2) {
            res = std::cmp::max(res, (leftMax[j-1] - nums[j] as i64) * rightMax[j+1]);
        }
            res
    }
}