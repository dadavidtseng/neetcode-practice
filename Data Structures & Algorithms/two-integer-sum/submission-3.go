func twoSum(nums []int, target int) []int {
    numIndexMap := make(map[int]int)

	for i, num := range nums {
		diff := target - num

		if index, found := numIndexMap[diff]; found {
			return []int{index, i}
		}

		numIndexMap[num] = i
	}

	return nil
}
