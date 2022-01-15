/* Josephus Problem */
class Solution
{
public:
    int helper(int n, int k)
    {
        if (n == 1)
            return 0;
        return (helper(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k)
    {
        return helper(n, k) + 1;

        // dp
        int winner = 0;
        for (int i = 1; i <= n; i++)
            winner = (winner + k) % i;
        return winner + 1;
    }
};

/* Queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < k - 1; j++) {
                int x = q.front();
                q.pop();
                q.push(x);
            }
            q.pop();
        }
        return q.front();
    }
};
*/

/* Circular Linked List
class Solution
{
public:
    class Node
    {
    public:
        int val;
        Node *next;
        Node(int val) : val(val), next(NULL) {}
    };

    int findTheWinner(int n, int k)
    {
        if (k == 1)
            return n;

        Node *head = new Node(1);
        Node *tail = head;

        for (int i = 2; i <= n; i++)
        {
            tail->next = new Node(i);
            tail = tail->next;
        }
        tail->next = head;

        Node *itr = head;

        int winner = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int i = 0; i < k - 2; i++)
            {
                itr = itr->next;
            }
            itr->next = itr->next->next;
            itr = itr->next;
            winner = itr->val;
        }
        return winner;
    }
};
*/