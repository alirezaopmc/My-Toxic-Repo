#include <iostream>
#include <stack>

// This code is fixed after the standard exam time limit

template<typename T> std::stack<T>
removeRepeated
(std::stack<T>& mainStack, T& var, std::stack<T>& helperStack);

template<typename T> void
putAonB
(std::stack<T>& A, std::stack<T>& B)
{
    
}

int main() {

}

template<typename T> std::stack<T>
removeRepeated
(std::stack<T>& mainStack, T& var, std::stack<T>& helperStack)
{
    int n = mainStack.size();

    var = mainStack.top();
    mainStack.pop();

    while(! mainStack.empty()) {
        int top = mainStack.top();
        mainStack.pop();
        if (top != var) {
            helperStack.push(top);
        }
    }

    helperStack.push(var);

    if (n == helperStack.size()) return helperStack;
    else return removeRepeated(helperStack, var, mainStack); 

    // Explanation is attached as a voice file in link below
    // https://github.com/SleepingJempa/My-Toxic-Repo/tree/master/school-shits/final
}