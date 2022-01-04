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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *itr = head;
        int val = itr->val;

        int cnt = 0;
        while (itr && itr->val == val)
        {
            itr = itr->next;
            cnt++;
        }

        ListNode *del_itr = head;

        if (cnt != 1)
        {
            head = deleteDuplicates(itr);

            while (del_itr != itr)
            {
                ListNode *tmp = del_itr;
                del_itr = del_itr->next;
                delete tmp;
            }
        }
        else
            head->next = deleteDuplicates(head->next);

        return head;
    }
};