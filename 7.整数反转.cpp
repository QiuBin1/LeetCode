/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == -pow(2,31))
        {
            return 0;   
        }
        bool isNegative = false;
        if( x < 0 )
        {
            isNegative = true;
        }
        x = abs(x);
        int res = 0;
        while(x/10>0 || x%10>0)
        {
            const int num = x%10;
            if(res > pow(2,31)/10||
            ((res == int(pow(2,31)-1)/10) && (num>int(pow(2,31)-1)%10)))
            {
                return 0;
            }
            res = res * 10  +  num;
            x = x/10;
        }
        if(isNegative)
        {
            return 0 - res;
        }
        return res;
    }
};
// @lc code=end

