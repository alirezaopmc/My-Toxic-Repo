template<typename T>
class DoubleStack
{
private:
    int MAX;
    int aSize;
    int bSize;

    T* arr;
public:
    DoubleStack(int MAX);
    void pushA(T e);
    T popA();
    T topA();
    void pushB(T e);
    T popB();
    T topB();
    ~DoubleStack();
};
