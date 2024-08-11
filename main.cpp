//314923822
//morberger444@gmail.com
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath> 
#include <sstream> 
using namespace std;
//this class represent a demo ti vusualize tree

//this function calculate the depth of the tree
template <typename T>
int Depth(Node<T>* node) {
    if (!node) return 0;
    int d = 0;
    for (auto& ch : node->my_childs) {
        d = max(d, Depth(ch.get()));
    }
    return d + 1;
}
//this function draw the tree on the screen
template <typename T>
void draw_tree(sf::RenderWindow &window, Node<T>* node, sf::Vector2f position, float offset, float offset2) 
{
    //check if the root exists
    if (!node) return;
    
    //draw the circle to represent the node
    sf::CircleShape c(20);
    c.setPosition(position.x - c.getRadius(), position.y - c.getRadius()); 
    c.setFillColor(sf::Color::Red); 
    window.draw(c);
    
    //load the font
    sf::Font f;
    if (!f.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        cerr << "Error in the load of font" << endl;
        return;
    }
    //write the text (value of the node)in the circle(node)
    sf::Text value_of_node;
    value_of_node.setFont(f);
    std::ostringstream s;
    s << node->value;
    value_of_node.setString(s.str());
    value_of_node.setCharacterSize(16); 
    value_of_node.setFillColor(sf::Color::Black); 
    value_of_node.setPosition(position);
    window.draw(value_of_node);

    int number_childs = node->my_childs.size();
    for (int i = 0; i < number_childs ; ++i) {
        auto& ch = node->my_childs[i];
        if (ch) { 
            float s= ((-70.0f - (number_childs - 1) * 25.0f) + i * 32.0f )* M_PI / 175.0f;
            sf::Vector2f p = position + sf::Vector2f(cos(s) * offset, offset2);
            sf::Vertex line[] = {
                sf::Vertex(position + sf::Vector2f(0, 40)),
                sf::Vertex(p + sf::Vector2f(0, -40))
            };
            line->color = sf::Color::Black; 
            window.draw(line, 2, sf::Lines);
            draw_tree(window, ch.get(), p, offset / 2.2f, offset2 * 1.2f); 
        }
    }
}


template <typename T>
void screen_tree(sf::RenderWindow& window, tree<T>& tree) {
    Node<T>* root = tree.get_root();
    int depth = Depth(root);
    sf::Vector2f p(window.getSize().x / 2, 40);
    draw_tree(window, root, p,  window.getSize().x / (pow(2, depth - 1) + 1) * 2.5, window.getSize().y / (depth + 1) * 1.5);
}

int main() {
    tree<int> first_tree(2);
    first_tree.add_root(1);
    first_tree.add_sub_node(1, 2); 
    first_tree.add_sub_node(1, 3); 
    first_tree.add_sub_node(2, 4); 
    first_tree.add_sub_node(2, 5); 
    first_tree.add_sub_node(3, 6); 
    first_tree.add_sub_node(3, 7); 

    cout << "Pre-order  binary tree : ";
    for (auto it = first_tree.begin_pre_order(); it != first_tree.end_pre_order(); ++it) {cout << *it << " ";}
    cout << endl;

    cout << "Post-order  binary tree : ";
    for (auto it = first_tree.begin_post_order(); it != first_tree.end_post_order(); ++it){cout << *it << " ";}
    cout << endl;

    cout << "In-order  binary tree : ";
    for (auto it = first_tree.begin_in_order(); it != first_tree.end_in_order(); ++it){cout << *it << " ";}
    cout << endl;

    cout << "Bfs  binary tree : ";
    for (auto it = first_tree.begin_bfs_scan(); it != first_tree.end_bfs_scan(); ++it) {cout << *it << " ";}
    cout << endl;

    cout << "Dfs  binary tree : ";
    for (auto it = first_tree.begin_dfs_scan(); it != first_tree.end_dfs_scan(); ++it) {cout << *it << " ";}
    cout << endl;

    cout << "Heap  binary tree: ";
    for (auto it = first_tree.begin_heap(); it != first_tree.end_heap(); ++it) {cout << *it << " ";}
    cout << endl;

    tree<int> second_tree(3);
    second_tree.add_root(1);
    second_tree.add_sub_node(1, 2);
    second_tree.add_sub_node(1, 3);
    second_tree.add_sub_node(1, 4);
    second_tree.add_sub_node(2, 5);
    second_tree.add_sub_node(2, 6);
    second_tree.add_sub_node(3, 7);
    second_tree.add_sub_node(3, 8);
    second_tree.add_sub_node(3, 9);


    cout << "Pre-order  k-3 tree : ";
    for (auto it = second_tree.begin_pre_order(); it != second_tree.end_pre_order(); ++it){cout << *it << " ";}
    cout << endl;

    cout << "Post-order  k-3 tree: ";
    for (auto it = second_tree.begin_post_order(); it != second_tree.end_post_order(); ++it){cout << *it << " "; }
    cout << endl;

    cout << "In-order  k-3 tree : ";
    for (auto it = second_tree.begin_in_order(); it != second_tree.end_in_order(); ++it) {cout << *it << " ";}
    cout << endl;

    cout << "Bfs  k-3 tree : ";
    for (auto it = second_tree.begin_bfs_scan(); it != second_tree.end_bfs_scan(); ++it){cout << *it << " ";}
    cout << endl;

    cout << "Dfs  k-3 tree: ";
    for (auto it = second_tree.begin_dfs_scan(); it != second_tree.end_dfs_scan(); ++it){cout << *it << " ";}
    cout << endl;

    cout << "Heap  k-3 tree: ";
    for (auto it = second_tree.begin_heap(); it != second_tree.end_heap(); ++it){ cout << *it << " ";}
    cout << endl;



    
//binary tree
    sf::RenderWindow first_window(sf::VideoMode(800, 600), "Visualization Binary Tree "); 

    while (first_window.isOpen()){
        sf::Event e;
        while (first_window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                first_window.close();
        }
        first_window.clear(sf::Color::White);
        screen_tree(first_window, first_tree);
        first_window.display();
    }


//draw tree for k-3 tree 
    sf::RenderWindow second_window(sf::VideoMode(800, 600), "Visualization  k-3 Tree"); 

    while (second_window.isOpen()) {
        sf::Event e;
        while (second_window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                second_window.close();
        }

        second_window.clear(sf::Color::White);
        screen_tree(second_window, second_tree);
        second_window.display();
    }

}
