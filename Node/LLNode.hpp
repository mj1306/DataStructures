#ifndef LLNODE_HPP
#define LLNODE_HPP

template <typename T>
class LLNode
{
    public:
        T data;
        LLNode<T>* next;
        LLNode(): next(nullptr) {};
        LLNode(T init_data, LLNode<T>* init_next): data(init_data), next(init_next) {};
};

#endif