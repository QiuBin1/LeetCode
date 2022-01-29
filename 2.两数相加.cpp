/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto result = new ListNode(0);
        auto curNode = result;
        std::size_t carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            const std::size_t val1 = l1 == nullptr ? 0 :l1->val;
            const std::size_t val2 = l2 == nullptr ? 0 :l2->val;
            std::size_t sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            auto node = new ListNode(sum);
            curNode-> next = node;
            curNode = curNode-> next;
            l1 = l1!= nullptr ? l1 -> next : nullptr;
            l2 = l2!= nullptr ? l2 -> next : nullptr;
        }
        return result->next;
        
    }
};
// @lc code=end

