/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int length = s.length();
        if (length == 1)
            return 1;
        std::size_t maxLen = 0;
        std::unordered_map<char, std::size_t> charMap;
        std::size_t count = 0;
        for (auto i = 0; i < length; ++i)
        {
            ++count;
            const std::size_t key = s[i];
            if (charMap.count(key) != 0)
            {
                count = std::min(i - charMap.at(key), count);
            }
            maxLen = std::max(count, maxLen);
            charMap[key] = i;
        }
        return maxLen;
    }
};
// @lc code=end
