//314923822
//morberger444@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

TEST_CASE("error in tree") {
    tree<int> tr(2);
    //no root
    CHECK_THROWS_AS(tr.add_sub_node(1, 4), std::runtime_error);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(3, 3);
    tr.add_sub_node(2, 3);
    tr.add_sub_node(2, 4);
    tr.add_sub_node(4, 9.5);
    //error in number of children
    CHECK_THROWS_AS(tr.add_sub_node(1, 7), std::runtime_error);
    //not found the parent
    CHECK_THROWS_AS(tr.add_sub_node(5, 4), std::runtime_error);
}
TEST_CASE("Tree binary integer") {
    tree<int> tr(2);
    tr.add_root(1);
    CHECK(tr.get_root()->value == 1);
    tr.add_sub_node(1, 2);
    Node<int>* root = tr.get_root();
    CHECK(root->my_childs[0]->value == 2);
}


TEST_CASE("BFS with int") {
    tree<int> tr(3);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(1, 4);
    tr.add_sub_node(2, 5);
    tr.add_sub_node(2, 6);
    tr.add_sub_node(2, 7);

    std::vector<int> expected_order = {1, 2, 3, 4, 5, 6,7};
    // Create an iterator and verify the traversal
    auto it = tr.begin_bfs_scan();
    auto end = tr.end_bfs_scan();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}

TEST_CASE("DFS with int") {
    // Create the tree
    tree<int> tr(3);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(1, 4);
    tr.add_sub_node(2, 5);
    tr.add_sub_node(2, 6);
    tr.add_sub_node(2, 7);

    // Define the expected DFS order
    std::vector<int> expected_order = {1, 2, 5, 6, 7, 3, 4};

    // Create an iterator and verify the traversal
    auto it = tr.begin_dfs_scan();
    auto end = tr.end_dfs_scan();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}


TEST_CASE("PREORDER with int") {
    tree<int> tr(3);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(1, 4);
    tr.add_sub_node(2, 5);
    tr.add_sub_node(2, 6);
    tr.add_sub_node(3, 7);
    tr.add_sub_node(3, 8);
    std::vector<int> expected_order = {1, 2, 5, 6, 3, 7,8,4};
    // Create an iterator and verify the traversal
    auto it = tr.begin_pre_order();
    auto end = tr.end_pre_order();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}

TEST_CASE("INORDER for int") {
    tree<int> tr(2);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(2, 4);
    tr.add_sub_node(2, 5);

    std::vector<int> expected_order = {4, 2, 5, 1, 3};

    // Create an iterator and verify the traversal
    auto it = tr.begin_in_order();
    auto end = tr.end_in_order();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}

TEST_CASE("POST with int") {
    tree<int> tr(3);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(1, 4);
    tr.add_sub_node(2, 5);
    tr.add_sub_node(2, 6);
    tr.add_sub_node(3, 7);
    tr.add_sub_node(3, 8);
    std::vector<int> expected_order = {1, 2, 5, 6, 3, 7,8,4};

    // Create an iterator and verify the traversal
    auto it = tr.begin_post_order();
    auto end = tr.end_post_order();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}
TEST_CASE("Heap with int") {
    // Create the tree
    tree<int> tr(2);
    tr.add_root(1);
    tr.add_sub_node(1, 2); 
    tr.add_sub_node(1, 3); 
    tr.add_sub_node(2, 4); 
    tr.add_sub_node(2, 5); 
    tr.add_sub_node(3, 6); 
    tr.add_sub_node(3, 7); 

    // Define the expected heap order (usually level-order in a complete k-ary tree)
    std::vector<int> expected_order = {1, 2, 3, 4, 5, 6, 7};

    // Create an iterator and verify the traversal
    auto it = tr.begin_heap();
    auto end = tr.end_heap();
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}

TEST_CASE("Heap Iterator with an empty tree") {
    tree<int> tr(2);
    // No root or nodes added, so the heap size should be 0

    // Create the iterator
    auto it = tr.begin_heap();
    auto end = tr.end_heap();

    // Verify that the iterator is at the end and no elements are present
    CHECK(it == end); // Ensure that the iterator reaches the end immediately
}

TEST_CASE("Heap Iterator with tree having only root") {
    // Setup: Create a tree with only a root
    tree<int> tr(2);
    tr.add_root(1);

    // Create the iterator
    auto it = tr.begin_heap();
    auto end = tr.end_heap();

    // Verify that the iterator does not immediately reach the end
    // because the tree has one element
    CHECK(it != end);

    // Advance the iterator and check that it reaches the end
    ++it;
    CHECK(it == end); // After advancing, it should reach the end
}
TEST_CASE("Heap Iterator with k different then 2") {
    // Setup: Create a tree with only a root
    tree<int> tr(3);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(1, 4);
    tr.add_sub_node(4, 5);
    // Create the iterator
    auto it = tr.begin_heap();
    auto end = tr.end_heap();
    CHECK(it == end);
}
TEST_CASE("BFS and DFS produce the same order for a linear tree") {
    // Setup: Create a tree where each node has exactly one child
    tree<int> tr(2);  // Each node can have only one child to form a linear tree
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(2, 3);
    tr.add_sub_node(3, 4);
    tr.add_sub_node(4, 5);

    // Expected order: 1, 2, 3, 4, 5
    std::vector<int> expected_order = {1, 2, 3, 4, 5};

    // Check BFS order
    auto bfs_it = tr.begin_bfs_scan();
    auto bfs_end = tr.end_bfs_scan();
    std::vector<int> bfs_result;
    while (bfs_it != bfs_end) {
        bfs_result.push_back(*bfs_it);
        ++bfs_it;
    }

    // Check DFS order
    auto dfs_it = tr.begin_dfs_scan();
    auto dfs_end = tr.end_dfs_scan();
    std::vector<int> dfs_result;
    while (dfs_it != dfs_end) {
        dfs_result.push_back(*dfs_it);
        ++dfs_it;
    }

    // Verify both orders are the same
    CHECK(bfs_result == expected_order);
    CHECK(dfs_result == expected_order);
}

TEST_CASE("BFS with duble") {
    tree<double> tr(2);
    tr.add_root(1.3);
    tr.add_sub_node(1.3, 2.5);
    tr.add_sub_node(1.3, 3);
    tr.add_sub_node(3, 4);
    tr.add_sub_node(2.5, 5);
    tr.add_sub_node(2.5, 6);
    tr.add_sub_node(4, 7.8);

    std::vector<double> expected_order = {1.3, 2.5, 3, 5, 6, 4,7.8};
    // Create an iterator and verify the traversal
    auto it = tr.begin_bfs_scan();
    auto end = tr.end_bfs_scan();
    
    int index = 0;
    while (it != end) {
        CHECK(*it == expected_order[index]);
        ++it;
        ++index;
    }

    // Ensure we have traversed all nodes
    CHECK(index == expected_order.size());
}