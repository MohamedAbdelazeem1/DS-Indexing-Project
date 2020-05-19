#include "trie.h"

Trie::Trie(){

    this->isLeaf = false;

    for (int i = 0; i < CHAR_SIZE; i++){

        this->character[i] = nullptr;
    }
}


#include <iostream>

// define character size
// A Class representing a Trie node
// Iterative function to insert a key in the Trie

void Trie::insert(std::string key, string fileName)
{
    // start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]] == nullptr)
            curr->character[key[i]] = new Trie();

        // go to next node
        curr = curr->character[key[i]];

    }
    // mark current node as leaf
    curr->isLeaf = true;
    curr->documents.push_back(fileName);
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
list<string> * Trie::search(std::string key)
{
    // return false if Trie is empty
    if (this == nullptr)
        return nullptr;

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // go to next node
        curr = curr->character[key[i]];

        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return nullptr;
    }
    // if current node is a leaf and we have reached the
    // end of the string, return true
    return &(curr->documents);
}

// C++ implementation of Trie Data Structure
