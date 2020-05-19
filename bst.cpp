#include "bst.h"

BST::BST()
{
    root=nullptr;
}

void BST::destroy_tree(node *leaf)
{
  if(leaf!=nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BST::insert(string key)
{

    node * current = this->root;

    if(current==nullptr){
        this->root = new node;
        this->root->document=key;
        this->root->left = nullptr;
        this->root->right = nullptr;

        return;
    }

    node * last =current;
    while(current!=nullptr){
        last=current;
        if(current->document == key)return;
        else if(key>current->document){
            current = current->right;
        }
        else{
            current = current->left;
        }
    }

    if(key>last->document){
        last->right = new node;
        last->right->document = key;
        last->right->left = nullptr;
        last->right->right = nullptr;
    }
    else{
        last->left = new node;
        last->left->document = key;
        last->left->left = nullptr;
        last->left->right = nullptr;
    }
    return;
}


vector <string> BST::traverse_tree(){
    vector<string> result;
    node * root = this->root;
    stack<node *> s;
        node *curr = root;

        while (curr != nullptr || s.empty() == false)
        {
            /* Reach the left most Node of the
               curr Node */
            while (curr !=  nullptr)
            {
                /* place pointer to a tree node on
                   the stack before traversing
                  the node's left subtree */
                s.push(curr);
                curr = curr->left;
            }
            /* Current must be NULL at this point */
            curr = s.top();
            s.pop();
            result.push_back(curr->document);
            /* we have visited the node and its
               left subtree.  Now, it's right
               subtree's turn */
            curr = curr->right;
        } /* end of while */
        return result;
}


void BST::destroy_tree()
{
  destroy_tree(root);
}



