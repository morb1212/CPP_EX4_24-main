//314923822
//morberger444@gmail.com
#ifndef DFS_ITERATOR_HPP
#define DFS_ITERATOR_HPP
#include <stack>
#include "node.hpp"

//this class represent the DFS_ITERATOR
template <typename T>
class dfs_iterator {
private:
    std::stack<Node<T>*> stack_dfs;//stack that store the nodes for dfs_iterator
    Node<T>* current_node;//the current node

public:
// //dfs iterator constrractor
    dfs_iterator(Node<T>* root);
//operator for the bfs iterator
    T& operator*();
    dfs_iterator& operator++(); 
    bool operator!=(const dfs_iterator& other) const;   
};

template <typename T>
dfs_iterator<T>::dfs_iterator(Node<T>* root) : current_node(root) {
    if (root) {
        stack_dfs.push(root);//if the root exists we add to the stack 
    }
}

template <typename T>
T& dfs_iterator<T>::operator*() {
    return current_node->value;//return the value of the current node
}

template <typename T>
dfs_iterator<T>& dfs_iterator<T>::operator++() {
    if (!stack_dfs.empty()) {//check if the stack is empty 
        Node<T>* node_top = stack_dfs.top();//take the top of the stack 
        stack_dfs.pop();//remove the top of the stack 
        //pass on the childs off the top node and add them to the stack
        for (auto it = node_top->my_childs.rbegin(); it != node_top->my_childs.rend(); ++it) {
            if (*it) {stack_dfs.push(it->get());}
        }
//if the stack is not empty we update the current node to be the top of the queu
        if (!stack_dfs.empty()) {current_node = stack_dfs.top();} 
        //if the stack is empty we update the current node to be null
        else {current_node = nullptr;}
    }
    return *this;
}
template <typename T>
bool dfs_iterator<T>::operator!=(const dfs_iterator& other) const {
// if the current node is different to the current node of the other we return true
//else return false
    if (current_node != other.current_node){
        return true;
    }
    else{
        return false;
    }
}



#endif 
