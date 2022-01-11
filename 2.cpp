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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *itr1 = l1, *itr2 = l2;

        int carry = 0;
        ListNode *last = NULL;

        while (itr1 && itr2)
        {
            int d = itr1->val + itr2->val + carry;
            carry = d / 10;
            itr1->val = d % 10;

            last = itr1;

            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        if (itr2)
        {
            last->next = itr2;

            while (itr2)
            {
                int d = itr2->val + carry;
                carry = d / 10;
                itr2->val = d % 10;

                last = itr2;
                itr2 = itr2->next;
            }
        }

        while (itr1)
        {
            int d = itr1->val + carry;
            carry = d / 10;
            itr1->val = d % 10;

            last = itr1;
            itr1 = itr1->next;
        }

        if (carry)
            last->next = new ListNode(carry);

        return l1;
    }
};