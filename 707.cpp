class MyLinkedList
{
    class Node
    {
    public:
        int val;
        Node *next = NULL;

        Node(int val) : val(val), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;

        Node *itr = head;
        for (int i = 0; i < index; i++)
            itr = itr->next;
        return itr->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
            return;

        Node *itr = head;
        Node *new_node = new Node(val);

        if (index == 0)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
                itr = itr->next;

            new_node->next = itr->next;
            itr->next = new_node;
        }
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
            return;

        if (index == 0)
        {
            Node *new_head = head->next;
            delete head;
            head = new_head;
        }
        else
        {
            Node *itr = head;
            for (int i = 0; i < index - 1; i++)
                itr = itr->next;

            Node *next_node = itr->next->next;
            delete itr->next;
            itr->next = next_node;
        }
        size--;
    }
    ~MyLinkedList()
    {
        Node *itr = head;
        while (head)
        {
            head = head->next;
            delete itr;
            itr = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */