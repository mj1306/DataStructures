#ifndef STACKNODE_H
#define STACKNODE_H

template <typename T>
/*
Stacks are data structures that follow LiFo principle.
Last element to go in is the first to go out.
Below is an
*/
class StackNode
{
    private:
        

    public:
        T data;
        StackNode<T>* next;

        StackNode(): data(), next(nullptr) {};
        StackNode(const T& t): data(t) {}
        ~StackNode() {next = nullptr;}

        StackNode<T>* get_next()
        {
            return next;
        }
};
#endif