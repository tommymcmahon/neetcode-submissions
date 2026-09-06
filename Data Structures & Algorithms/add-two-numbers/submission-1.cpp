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

        auto result = new ListNode();
        auto curr = result;

        int carry = 0;

        // Add values from l2 to l1
        while (l1 || l2)
        {
            // Get value in list or zero
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int val = v1 + v2 + carry;

            // new digit and carry
            carry = val / 10;
            int digit = val % 10;

            // update the list
            curr->next = new ListNode(digit);
            curr = curr->next;

            // move to next node
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        return result->next;
    }
};
