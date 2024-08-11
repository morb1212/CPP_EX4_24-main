//314923822
//morberger444@gmail.com
#ifndef BFS_ITERATOR_HPP
#define BFS_ITERATOR_HPP
#include <queue>
#include "node.hpp"
template <typename T>

//this class represent the BFS_ITERATOR
class bfs_iterator {
private:
    std::queue<Node<T>*> queu_bfs;//queu that store the nodes for bfs_iterator
    Node<T>* current_node;//the current node 

public:
    //bfs iterator constrractor
    bfs_iterator(Node<T>* root);
    
    //operator for the bfs iterator
    T& operator*();
    bfs_iterator& operator++();
    bool operator!=(const bfs_iterator& other) const;
};

template <typename T>
bfs_iterator<T>::bfs_iterator(Node<T>* root) : current_node(root) {
    if (root) {//check if the root exists
        queu_bfs.push(root);//if the root exists we add to the queu 
    }
}


template <typename T>
T& bfs_iterator<T>::operator*() {
    return current_node->value;//return the value of the current node
}

template <typename T>
bfs_iterator<T>& bfs_iterator<T>::operator++() { 
    if (!queu_bfs.empty()) {//check if the queu is empty 
        Node<T>* node_front = queu_bfs.front();//take the front of the queu 
        queu_bfs.pop();//remove the front of the queu
//pass on the childs off the front node and add them to the queu 
        for (auto& child : node_front->my_childs) {
            if (child) {queu_bfs.push(child.get());}
        }
//if the queu is not empty we update the current node to be the front of the queu
        if (!queu_bfs.empty()) {
            current_node = queu_bfs.front();
        } 
//if the queu is empty we update the current node to be null
        else {
            current_node = nullptr;
        }
    }
    return *this;
}

template <typename T>
bool bfs_iterator<T>::operator!=(const bfs_iterator& other) const {
// if the current node is different to the current node of the other we return true
//else return false
    if(current_node != other.current_node){
        return true;
    }
    else{
        return false;
    }
}

#endif
