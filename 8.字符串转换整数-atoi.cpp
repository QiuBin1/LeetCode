/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        auto length = s.length();
        auto isPositive = true;
        auto hasPositiveTag = false;
        auto result = 0;
        auto const maxInt = static_cast<int>(std::pow(2, 31) - 1);
        auto const minInt = static_cast<int>(-std::pow(2, 31));
        for (auto i = 0; i < length; ++i)
        {
            auto const letter = s[i];
            if (letter >= '0' && letter <= '9')
            {
                auto const number = letter - '0';
                if (isPositive && (result > maxInt / 10) || (result == maxInt / 10 && number > maxInt % 10))
                {
                    return maxInt;
                }
                if (!isPositive && (0 - result < minInt / 10) || (0 - result == minInt / 10 && number > minInt % 10))
                {
                    return minInt;
                }
                result = result * 10 + number;
            }
            else if (letter == '-')
            {
                if(hasPositiveTag)
                {
                    return 0;
                }
                isPositive = false;
                hasPositiveTag = true;
            }
            else if (letter == '+')
            {
                if(hasPositiveTag)
                {
                    return 0;
                }
                isPositive = true;
                hasPositiveTag = true;
            }
            else if (letter == ' ')
            {
                continue;
            }
            else
            {
                break;
            }
        }

        if (isPositive == true)
        {
            return result;
        }
        return 0 - result;
    }
};
// @lc code=end
