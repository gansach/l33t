class MyQueue
{
    stack<int> read, write;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        write.push(x);
    }

    int pop()
    {
        int front = peek();
        read.pop();
        return front;
    }

    int peek()
    {
        if (read.empty())
        {
            while (!write.empty())
            {
                read.push(write.top());
                write.pop();
            }
        }
        return read.top();
    }

    bool empty()
    {
        return read.empty() && write.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */