/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        const int len = s.length();
        std::string res;
        if (s.empty())
            return 0;
        int sublen = 1;
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));
        for (auto i = 0; i < len; i++)
        {
            for (auto j = 0; j <= i; j++)
            {
                if (j == i)
                {
                    dp[j][i] = true;
                }
                else if (i == j + 1)
                {
                    dp[j][i] = (s[i] == s[j]);
                }
                else
                {
                    dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1] == true);
                }


                if (dp[j][i])
                {
                    if (i - j + 1 >= sublen)
                    {
                        sublen = i - j + 1;
                        res = s.substr(j, i - j + 1);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
