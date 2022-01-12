/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *itrA = headA, *itrB = headB;
        while (itrA != itrB)
        {
            itrA = itrA == NULL ? headB : itrA->next;
            itrB = itrB == NULL ? headA : itrB->next;
        }
        return itrA;
    }
};