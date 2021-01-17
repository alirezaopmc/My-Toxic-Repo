template<typename T>
class QueueStack
{
private:
    int MAX;

    int queueSize;
    int queueFirstIndex;
    int queueLastIndex;
    
    int stackSize;

    T* arr;
public:
    QueueStack(int MAX);
    void enqueue(T e);
    T dequeue();
    T first();
    T last();
    void push(T e);
    T pop();
    T top();
    ~QueueStack();
};
