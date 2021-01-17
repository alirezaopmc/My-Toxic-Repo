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

template<typename T>
void displaceStackWithHelpOfStack(
        std::stack<T> &theStack,
        std::stack<T> &helperStack,
        std::stack<T> &targetStack    
    )
{
    int n = a.size();
    putAonB(n, theStack, helperStack);
    putAonB(n, helperStack, targetStack)
}

template<typename T>
void displaceStackWithHelpOfVariable(
        std::stack<T> &theStack,
        std::stack<T> &targetStack,
        int &tmp
    )
{
    int n = theStack.size();
    
    while (n--) {
        tmp = theStack().top();
        putAonB(n, theStack, targetStack)
        theStack.push(tmp);
        putAonB(n, targetStack, theStack);
    }

    putAonB(theStack.size(), theStack, targetStack);
}