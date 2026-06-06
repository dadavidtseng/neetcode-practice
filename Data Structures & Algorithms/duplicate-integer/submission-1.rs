impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut s: HashSet<i32> = HashSet::new();

        for i in 0..nums.len()
        {
            // bool value set to true if and only if the insertion took place
            if !s.insert(nums[i])
            {
                return true;
            }
        }

        // return false if there's no duplicated nums
        false
    }
}
