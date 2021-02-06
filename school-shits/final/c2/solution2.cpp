#include <iostream>
#include <stack>

template<typename T>
std::stack<T> removeRepeated(std::stack<T>& mainStack, std::stack<T>& helperStack, int cnt, int n); 

template<typename T>
void printStack(std::stack<T> theStack);

int main() {
    std::stack<int> s, t;
    s.push(5);
    s.push(5);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(2);
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(5);
    s.push(1);
    s.push(2);

    auto result = removeRepeated(s, t, 0, s.size());
    printStack(result);
}

template<typename T>
std::stack<T> removeRepeated(std::stack<T>& mainStack, std::stack<T>& helperStack, int cnt, int n) {
    int var = mainStack.top();
    mainStack.pop();
    helperStack.push(var);
    cnt++;

    while(! mainStack.empty()) {
        int top = mainStack.top();
        mainStack.pop();
        if (top != var) {
            helperStack.push(top);
        } else {
            n--;
        }
    }

    while(helperStack.size() != cnt) {
        int top = helperStack.top();
        helperStack.pop();
        if (top != var) {
            mainStack.push(top);
        }
    }

    if (cnt == n) return helperStack;
    else return removeRepeated(mainStack, helperStack, cnt, n); 

    // Explanation is attached as a voice file in link below
    // https://github.com/SleepingJempa/My-Toxic-Repo/tree/master/school-shits/final
}

template<typename T>
void printStack(std::stack<T> theStack) {
    while(!theStack.empty()) {
        std::cout << theStack.top() << std::endl;
        theStack.pop();
    }
}