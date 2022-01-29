/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        const uint len = nums.size();
        for(uint i=0;i<len;++i)
        {
            for(uint j=i+1;j<len;++j)
            {
                if(nums[i]+nums[j] == target)
                {
                    result.emplace_back(i);
                    result.emplace_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

