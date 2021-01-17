#include <stack>

template<typename T>
void putAonB(int cnt, std::stack<T> &a, std::stack<T> &b)
{
    while(cnt-- && a.size())
    {
        T e = a.top();
        a.pop();
        b.push(e);
    }
}

// Theta(n^2+n)
template<typename T>
void reverseStack2( std::stack<T> &targetStack,
                    std::stack<T> &helperStack)
{
    int n = targetStack.size();
    while(n--)
    {
        T tmp = targetStack.top();
        targetStack.pop();
        putAonB(n, targetStack, helperStack);
        targetStack.push(tmp);
        putAonB(n, helperStack, targetStack);
    }
}
