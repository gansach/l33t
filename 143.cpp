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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *reversed = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversed;
    }
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *l1 = head;
        ListNode *l2 = reverseList(slow->next);

        slow->next = NULL;

        ListNode *tail = head;

        while (l1 != NULL && l2 != NULL)
        {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;
            l2->next = l1_next;

            tail = l2;

            l1 = l1_next;
            l2 = l2_next;
        }
        if (l1)
            tail->next = l1;
    }
};
/*
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *head_next = head->next;

        ListNode *second_last = head;
        while (second_last->next->next)
            second_last = second_last->next;

        ListNode *last = second_last->next;
        second_last->next = NULL;

        head->next = last;
        last->next = head_next;

        reorderList(head_next);
    }
};
*/