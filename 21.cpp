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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *smaller = list1->val < list2->val ? list1 : list2;
        ListNode *bigger = list1->val >= list2->val ? list1 : list2;

        ListNode *itr = smaller;
        while (itr->next != NULL && itr->next->val < bigger->val)
            itr = itr->next;

        ListNode *next_smaller = itr->next;

        itr->next = mergeTwoLists(next_smaller, bigger);

        return smaller;
    }
};