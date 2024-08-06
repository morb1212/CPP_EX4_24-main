#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <memory>
//this class represent a node

template <typename T>
class Node {
public:
//value of the node
    T value;
  //vector that store the childs of the nnode
    std::vector<std::unique_ptr<Node<T>>> my_childs;
    Node(T val, int k);
};

template <typename T>
Node<T>::Node(T val, int k) : value(val), my_childs(k) {}

#endif 
