#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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

    std::vector<int> vec = {1, 2, 3, 4, 5, 6,7};
    int i = 0;
    for (auto it = tr.begin_bfs_scan(); it != tr.end_bfs_scan(); ++it) {
        CHECK(*it == vec[i]);
        ++i;
    }
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
    std::vector<int> vec = {1, 2, 5, 6, 3, 7,8,4};
    int i = 0;
    for (auto it = tr.begin_pre_order(); it != tr.end_pre_order(); ++it) {
        CHECK(*it == vec[i]);
        ++i;
    }
}

TEST_CASE("INORDER for int") {
    tree<int> tr(2);
    tr.add_root(1);
    tr.add_sub_node(1, 2);
    tr.add_sub_node(1, 3);
    tr.add_sub_node(2, 4);
    tr.add_sub_node(2, 5);

    std::vector<int> vec = {4, 2, 5, 1, 3};
    int i = 0;
    for (auto it = tr.begin_in_order(); it != tr.end_in_order(); ++it) {
        CHECK(*it == vec[i]);
        ++i;
    }
}
