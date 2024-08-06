#ifndef POST_ORDER_ITERATOR_HPP
#define POST_ORDER_ITERATOR_HPP
#include <stack>
#include "node.hpp"

//this class represent the POST_ITERATOR
template <typename T>
class post_order_iterator {
private:
    std::stack<Node<T>*> stack_postorder;//stack that store the nodes for postorer_iterator
    Node<T>* current_node;//the current node
    int k;//the value k 
//this function add the childrens of the left of the tree
    void pushLeft(Node<T>* top_node) {
        while (top_node) {
            stack_postorder.push(top_node);
            if (!top_node->my_childs.empty()) {
                top_node = top_node->my_childs[0].get();
            } 
            else {break;}
        }
    }

public:
    post_order_iterator(Node<T>* root, int k) : current_node(nullptr), k(k) {
        if (root) {
        //check if binary tree
            if (k == 2) { pushLeft(root);} 
        //if not binary tree
            else {stack_postorder.push(root);}
        }
        ++(*this);
    }
// if the current node is different to the current node of the other we return true
//else return false
    bool operator!=(const post_order_iterator& other) const {
        if(current_node != other.current_node){
            return true;
        }
        else{
            return false;
        }

    }
    //return the value of the current node
    T& operator*() {
        return current_node->value;
    }

    post_order_iterator& operator++() {
  //check if the tree is binary 
  //if binary we use the fonction pushLeft
        if (k == 2) {
        //check if the stack is not empty 
            if (!stack_postorder.empty()) {
            //store the top of the stack 
                Node<T>* top_node = stack_postorder.top();
                //remove the top of the stack 
                stack_postorder.pop();
                //check if the stack is not empty second time 
                if (!stack_postorder.empty()) {
                //store the top of the stack
                    Node<T>* top_node_2 = stack_postorder.top();
                    if (top_node_2->my_childs.size() > 1 && top_node == top_node_2->my_childs[0].get()) {
                        pushLeft(top_node_2->my_childs[1].get());
                    }
                }
                //update the current node to be the top node of the stack 
                current_node = top_node;
            } 
            //if the stack is empty update the current node to be null
            else {
                  current_node = nullptr;
            }
        }  
        else {
            // if not tree binary we use dfs
            //chec if the tree stack is not empty 
            if (!stack_postorder.empty()) {
            //we take the top of the stack
                Node<T>* top_node = stack_postorder.top();
                //we remove the top of the stack
                stack_postorder.pop();
                //pass on the childs off the top node and add them to the stack
                for (auto it = top_node->my_childs.rbegin(); it != top_node->my_childs.rend(); ++it) {
                    if (*it) {
                        stack_postorder.push(it->get());
                    }
                }
                //update the current  node to be the top node
                current_node = top_node;
            } 
            //if stack is empty update the current node to be null 
            else {
                  current_node = nullptr;
            }

        }
        return *this;
    }


};

#endif 
