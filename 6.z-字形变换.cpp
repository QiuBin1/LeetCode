/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        std::string res;
        auto length = s.length();
        for (auto i = 0; i < numRows; ++i)
        {
            if (i >= length)
            {
                break;
            }
            res.push_back(s[i]);
            int index = i;
            for (auto j = 0;; ++j)
            {
                auto seg = j % 2 == 0 ? 2 * (numRows - i - 1) : 2 * (i);
                if (numRows == 1)
                {
                    seg = 1;
                }
                else if (i == 0)
                {
                    seg = 2 * (numRows - i - 1);
                }
                else if (i == numRows - 1)
                {
                    seg = 2 * i;
                }
                index = index + seg;
                if (index >= length || seg == 0)
                {
                    break;
                }
                res.push_back(s[index]);
            }
        }
        return res;
    }
};
// @lc code=end
