class Solution
{
public:
    long long getNext(int n)
    {
        long long digit_square_sum = 0;
        while (n)
        {
            digit_square_sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return digit_square_sum;
    }

    bool isHappy(int n)
    {
        int fast = n, slow = n;

        slow = getNext(n);
        fast = getNext(getNext(n));

        while (slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));

            if (fast == 1)
                return true;
        }
        return fast == 1;
    }
};