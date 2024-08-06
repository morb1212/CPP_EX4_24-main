#ifndef HEAP_ITERATOR_HPP
#define HEAP_ITERATOR_HPP
#include "node.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

//this class represent the HEAP_ITERATOR
template <typename T>
class heap_iterator {
private:
    std::vector<Node<T>*> my_heap; //vector that store the nodes for heap_iterator
    //struc compare node
    struct CompareNodes {
        bool operator()(const Node<T>* a, const Node<T>* b) const {
            return a->value > b->value;
        }
    };

    void collect_nodes(Node<T>* node) {
      if (node) {//check if exists node
          my_heap.push_back(node);//if node exists we push to the vector of the heap 
          //we pass on his childs and push them to the vector of the heap 
          for (auto& child : node->my_childs) {
                if (child) {collect_nodes(child.get());}
            }
        }
    }

public:
    heap_iterator(Node<T>* root, int k) {
    //check if the K is 2 
        if (k == 2) {
    //check if exist root
            if (root) {
               //collect node of the root
                collect_nodes(root);
                //make heap with struct of compare node
                std::make_heap(my_heap.begin(), my_heap.end(), CompareNodes());
            }
        }  
        //if the K is not 2 we throw error bcause heap iterator works just with binary tree
        else if (k > 2 && root!=nullptr) {
            std::cout << "HEAP ITERATOR: Error in the value of K - different of 2." << std::endl;
        }
    }

    T& operator*() const {
        return my_heap.front()->value;//return the value of the front of the heap 
    }
    heap_iterator& operator++() {
        std::pop_heap(my_heap.begin(), my_heap.end(), CompareNodes());//pop of the heap 
        my_heap.pop_back();
        return *this;
    }

    heap_iterator& operator=(const heap_iterator& other) {
    //update the heap to be the heap of the other
        if (this != &other) {my_heap = other.my_heap;}
        return *this;
    }
     T* operator->() const {
//return the value of the front of the heap 
        return &(my_heap.front()->value);
    }
    bool operator==(const heap_iterator& other) const{
    //check if their heap equals
        if(my_heap == other.my_heap){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator!=(const heap_iterator& other) const {
    //check if their heap different
        return !(*this == other);

    }

   

};

#endif 
