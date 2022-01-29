/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int len1 = nums1.size();
        const int len2 = nums2.size();
        const auto mid = (len1 + len2) / 2;
        const auto bit = (len1 + len2) % 2;
        int index1 = 0;
        int index2 = 0;
        int lastValue = 0;
        int lastValue2 = 0;
        for (auto i = 0; i <= mid; ++i)
        {
            lastValue2 = lastValue;
            if (index1 >= len1)
            {
                lastValue = nums2[index2];
                ++index2;
            }
            else if (index2 >= len2)
            {
                lastValue = nums1[index1];
                ++index1;
            }
            else if (nums1[index1] > nums2[index2])
            {
                lastValue = nums2[index2];
                ++index2;
            }
            else
            {
                lastValue = nums1[index1];
                ++index1;
            }
        }
        if (bit == 1)
        {
            return lastValue;
        }
        return (lastValue + lastValue2) / 2.0;
    }
};
// @lc code=end
