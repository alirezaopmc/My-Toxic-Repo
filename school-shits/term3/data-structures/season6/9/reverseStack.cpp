#include <stack>
#include <queue>

template<typename T>
void reverseStackWithOnlyOneQueue(std::stack<T> &targetStack)
{
    std::queue<T> helperQueue;

    while(! targetStack.empty())
    {
        T e = targetStack.top();
        targetStack.pop();
        helperQueue.push(e);
    }

    while(! helperQueue.empty())
    {
        T e = helperQueue.front();
        helperQueue.pop();
        targetStack.push(e);
    }
}

template<typename T>
void putAonB(std::stack<T> &a, std::stack<T> &b)
{
    while(! a.empty())
    {
        T e = a.top();
        a.pop();
        b.push(e);
    }
}

template<typename T>
void reverseStackWithTwoStacks( std::stack<T> &targetStack,
                                std::stack<T> &helperStackA,
                                std::stack<T> &targetStackB)
{
    putAonB(targetStack, helperStackA);
    putAonB(helperStackA, helperStackB);
    putAonB(targetStackB, targetStack);
}
