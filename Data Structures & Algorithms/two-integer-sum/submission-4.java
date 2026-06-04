class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numIndexMap = new HashMap<>();

        // Iterate through every element to find target
        // Build numIndexMap along the way
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];

            if (numIndexMap.containsKey(diff)) {
                return new int[] {numIndexMap.get(diff), i};
            }

            numIndexMap.put(nums[i], i);
        }

        // return empty result to satisfy compiler
        // Since the problem says there is guaranteed to be exactly one solution,
        // so we will never return an empty array.
        return new int[] {};
    }
}
