//314923822
//morberger444@gmail.com
#ifndef PRE_ORDER_ITERATOR_HPP
#define PRE_ORDER_ITERATOR_HPP
#include <stack>
#include "node.hpp"

//this class represent the PREORDER_ITERATOR
template <typename T>
class pre_order_iterator {
private:
    std::stack<Node<T>*> stack_preorder;//stack that store the nodes for preorder_iterator
    Node<T>* current_node;//the current node

public:
    pre_order_iterator(Node<T>* root);
    //operator for the preorder iterator
    bool operator!=(const pre_order_iterator& other) const;
    T& operator*();
    pre_order_iterator& operator++();
};

template <typename T>
pre_order_iterator<T>::pre_order_iterator(Node<T>* root) : current_node(root){
    if (root) {stack_preorder.push(root);}
}

//return the value of the current node
template <typename T>
T& pre_order_iterator<T>::operator*(){
    return current_node->value;
}

template <typename T>
pre_order_iterator<T>& pre_order_iterator<T>::operator++() {
//check if the stack is not empty 
    if (!stack_preorder.empty()) {
    //store the top of the stack
        Node<T>* top_node = stack_preorder.top();
        //remove the top of the stack
        stack_preorder.pop();
        //pass on the childs off the top node and add them to the stack
        for (auto it = top_node->my_childs.rbegin(); it != top_node->my_childs.rend(); ++it) {
            if (*it) {
                stack_preorder.push(it->get());
            }
        }
        //if stack not empty update the current node to be the top of the stack 
        if (!stack_preorder.empty()) { current_node = stack_preorder.top();} 
        //if stack is empty update the current node to be null
        else {current_node = nullptr;}
    }
    return *this;
}
// if the current node is different to the current node of the other we return true
//else return false
template <typename T>
bool pre_order_iterator<T>::operator!=(const pre_order_iterator& other) const {
    if(current_node != other.current_node){
        return true;
    }
    else{
        return false;
    }
}


#endif 
