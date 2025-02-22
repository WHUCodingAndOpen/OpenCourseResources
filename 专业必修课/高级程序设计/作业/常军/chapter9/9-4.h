template <typename T>
class DNode {
public:
    T data; // 存储数据
    DNode<T>* prev; // 指向前一个结点的指针
    DNode<T>* next; // 指向后一个结点的指针

    // 构造函数
    DNode(T d, DNode<T>* p = nullptr, DNode<T>* n = nullptr) : data(d), prev(p), next(n) {}

    // 析构函数
    ~DNode() {
    // 如果有前一个结点，需要更新前一个结点的next指针
    if (prev != nullptr) {
        prev->next = next;
    }
    // 如果有后一个结点，需要更新后一个结点的prev指针
    if (next != nullptr) {
        next->prev = prev;
    }
}
};