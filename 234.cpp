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
    ListNode *reverse(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *pre = NULL, *curr = head, *next = head;
        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);

        ListNode *i = head, *j = slow->next;
        while (j)
        {
            if (i->val != j->val)
                return false;
            i = i->next;
            j = j->next;
        }
        return true;
    }
};