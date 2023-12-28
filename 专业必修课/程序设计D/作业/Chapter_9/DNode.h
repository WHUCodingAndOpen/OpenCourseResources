// 在双向链表中使用的结点类与单链表中使用的结点类相比,应有何不同?请声明并实现双向链表中使用的结点类DNode。
// 在双向链表中，每个结点通常需要保存指向前一个结点（前驱）和后一个结点（后继）的指针。相比于单链表中的结点，双向链表的结点类需要额外保存前驱指针。
// DNode.h
#ifndef DNODE_H
#define DNODE_H

template <typename T>
class DNode {
public:
    T data;          // 数据域
    
    // 构造函数
    DNode(void);
    DNode(const T& item);

    // 链表修改算法
    void insertRight(DNode<T> *p);
    void insertLeft(DNode<T> *p);
    DNode<T> *deleteNode(void);

    // 获取左侧和右侧相邻结点的地址
    DNode<T> *nextNodeRight(void) const;
    DNode<T> *nextNodeLeft(void) const;
private:
    DNode<T> *left; // 左指针
    DNode<T> *right; // 右指针
};

// 构造函数创建一个空结点，不初始化数据成员，用于链表头结点
template<typename T>
DNode<T>::DNode(void) {
    // 初始化结点，使之指向自身
    left = right = this;
}

// 构造函数，创建一个空结点并初始化数据成员
template<typename T>
DNode<T>::DNode(const T& item) {
    // 使结点指针指向自身并初始化数据成员
    left = right = this;
    data = item;
}

// 在当前结点的右侧插入一个结点p
template<typename T>
void DNode<T>::insertRight(DNode<T> *p) {
    // 将p与右结点链接
    p->right = right;
    right->left = p;

    // 将当前结点连接到p结点的左侧
    p->left = this;
    right = p;
}

// 在当前结点的左侧插入一个结点p
template<typename T>
void DNode<T>::insertLeft(DNode<T> *p) {
    // 将p与左结点连接
    p->left = left;
    left->right = p;

    // 将当前结点连接到p结点的右侧
    p->right = this;
    left = p;
}

// 断开当前结点与链表的连接，并返回当前结点的地址
template<typename T>
DNode<T> *DNode<T>::deleteNode(void) {
    // 使当前结点的左侧结点连接到当前结点的右侧结点
    left->right = right;

    // 使当前结点的右侧结点连接到当前结点的左侧结点
    right->left = left;

    // 返回当前结点的地址
    return this;
}

// 返回指向右结点的指针
template<typename T>
DNode<T> *DNode<T>::nextNodeRight(void) const {
    return right;
}

// 返回指向左结点的指针
template<typename T>
DNode<T> *DNode<T>::nextNodeLeft(void) const {
    return left;
}

#endif // DNODE_H