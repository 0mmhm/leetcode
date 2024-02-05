func twoSum(nums []int, target int) []int {
	var result []int

	var mp map[int]int
	mp = make(map[int]int)

	for i := 0; i < len(nums); i++ {
		mp[nums[i]] = i + 1
	}

	var x, y, xPos, yPos int
	for i := 0; i < len(nums); i++ {
		x = nums[i]
		y = target - x
		xPos = i
		yPos = mp[y] - 1

		if mp[y] > 0 && xPos != yPos {
			break
		}
	}

	result = append(result, xPos, yPos)

	return result
}