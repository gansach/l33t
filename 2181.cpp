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
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == NULL)
            return head;

        if (head->next == NULL)
            return NULL;

        ListNode *itr = head->next;
        while (itr->val != 0)
        {
            head->val += itr->val;

            ListNode *tmp = itr;
            itr = itr->next;

            head->next = itr;
            delete tmp;
        }
        head->next = mergeNodes(itr);
        return head;
    }
};