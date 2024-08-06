#ifndef IN_ORDER_ITERATOR_HPP
#define IN_ORDER_ITERATOR_HPP
#include <stack>
#include <memory>
#include "node.hpp"

//this class represent INORDER_ITERATOR
template <typename T>
class in_order_iterator {
private:
    std::stack<Node<T>*> stack_inorder;//stack that store the nodes for inorder_iterator
    Node<T>* current_node;//the  current node
    int k;//the value k
    
//this function add the children that be in the left 
    void push_left(Node<T>* temp) {
        while (temp) {
            //we add the node to stack 
            stack_inorder.push(temp);
            //we add the left childrento the stack 
            if (!temp->my_childs.empty()) {
                temp = temp->my_childs[0].get();
            } 
            else {break;}
        }
    }

public:

   in_order_iterator(const std::unique_ptr<Node<T>>& t, int k) : current_node(nullptr), k(k) {
   //check if the tree is binary and call the function push left 
        if (k == 2) {
              push_left(t.get());
        } 
        //if the tree not binary 
        else if (t) {
                stack_inorder.push(t.get());
        }
        ++(*this); 
    }

// if the current node is different to the current node of the other we return true
//else return false
    bool operator!=(const in_order_iterator& other) const {
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


  in_order_iterator& operator++() {
    //check if the tree is binary 
        if (k == 2) {
           
           if (current_node && current_node->my_childs.size() > 1) {push_left(current_node->my_childs[1].get());}
           //check if the stack not is empty 
            if (!stack_inorder.empty()) {
            //store the top of stack  in the current node
                current_node = stack_inorder.top();
              //remove the top of the stack
                stack_inorder.pop();
            } 
            
            //if the stack is empty update the currend node to be null 
            else {current_node = nullptr;}
        }
  //if the tree is not binary 
        else{
        //check if the stack is not binary 
            if (!stack_inorder.empty()) {
            //store the top of the stack 
                Node<T>* top_node = stack_inorder.top();
                //remove the top of the stack 
                stack_inorder.pop();
                //update the current node to be the top of the stack 
                current_node = top_node;
                //pass on the childs off the top node and add them to the stack
                for (auto it = top_node->my_childs.rbegin(); it != top_node->my_childs.rend(); ++it) {
                    if (*it) {
                        stack_inorder.push(it->get());
                    }
                }
            } 
            //if stack empty update the current node to be null 
            else {current_node = nullptr;}
        }
        return *this;
    }
};

#endif 
