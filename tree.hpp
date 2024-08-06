#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "bfs_iterator.hpp"
#include "dfs_iterator.hpp"
#include "pre_order_iterator.hpp"
#include "post_order_iterator.hpp"
#include "in_order_iterator.hpp"
#include "heap_iterator.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class tree {
private:
    //root of the tree
    std::unique_ptr<Node<T>> root;
    //number max of chidrens
    int k;

public:
//default of the k is 2
    tree(int k = 2) : root(nullptr), k(k) {}
//update the root
    void add_root(const T& value) {
        root = std::make_unique<Node<T>>(value, k);
    }
    //get the root of the tree
    Node<T>* get_root() const { 
           return root.get(); 
    }
    //add node to the tree
    void add_sub_node(const T& parent_value, const T& child_value) {
    //check if exist root
        if (!root) {
            throw std::runtime_error("Tree is empty ");
        }
        std::queue<Node<T>*> q;
        q.push(root.get());
//find the parent of the node that we want add
        while (!q.empty()) {
            Node<T>* fr = q.front();
            q.pop();
//if we found the parent of the node
            if (fr->value == parent_value) {
                for (int i = 0; i < k; ++i) {
                    if (!fr->my_childs[i]) {
                        fr->my_childs[i] = std::make_unique<Node<T>>(child_value, k);
                        return;
                    }
                }
                //if the number of childrens of the parent is >k throw error
                throw std::runtime_error("Error in number of chilrens");
            }

            for (auto& child : fr->my_childs) {
                if (child) {q.push(child.get());}
            }
}
      //if not found the parent of the node throw error  
        throw std::runtime_error("Not found the parent");
    }
   //begin ,end iterator 
     heap_iterator<T> begin_heap(){
        return heap_iterator<T>(root.get(), k);
    }
    heap_iterator<T> end_heap() {
        return heap_iterator<T>(nullptr, k);
    }
    bfs_iterator<T> begin_bfs_scan() {
        return bfs_iterator<T>(root.get());
    }
    bfs_iterator<T> end_bfs_scan() {
        return bfs_iterator<T>(nullptr);
    }
    dfs_iterator<T> begin_dfs_scan() {
        return dfs_iterator<T>(root.get());
    }
    dfs_iterator<T> end_dfs_scan() {
        return dfs_iterator<T>(nullptr);
    }
    pre_order_iterator<T> begin_pre_order() {
        return pre_order_iterator<T>(root.get());
    }
    pre_order_iterator<T> end_pre_order() {
        return pre_order_iterator<T>(nullptr);
    }

    post_order_iterator<T> begin_post_order() {
        return post_order_iterator<T>(root.get(), k);
    }
    post_order_iterator<T> end_post_order() {
        return post_order_iterator<T>(nullptr, k);
    }
       in_order_iterator<T> begin_in_order() {
        return in_order_iterator<T>(root, k);
    }
    in_order_iterator<T> end_in_order() {
        return in_order_iterator<T>(nullptr, k);
    }

    ~tree() = default;
};



#endif 
