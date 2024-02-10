func lengthOfLongestSubstring(s string) int {
	var mp map[rune]int
	mp = make(map[rune]int)

	var maxLen, tempLen, ind int
	var char, tempChar rune
	slen := len(s)

	for i := 0; i < slen; i++ {
		char = rune(s[i])
		mp[char]++
		tempLen++

		if mp[char] > 1 {
			for mp[char] > 1 {
				tempChar = rune(s[ind])
				ind++
				mp[tempChar]--
				tempLen--
			}
		}

		if tempLen > maxLen {
			maxLen = tempLen
		}
	}

	return maxLen
}