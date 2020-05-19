#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct node
{
  string document;
  node *left;
  node *right;
};


class BST
{
public:
    BST();
    void insert(string key);
    void destroy_tree();
    vector <string> traverse_tree();
private:
    void destroy_tree(node *leaf);
    node *root;
};

#endif // BST_H
