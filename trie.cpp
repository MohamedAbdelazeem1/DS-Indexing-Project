#include "trie.h"

Trie::Trie(){

    this->isLeaf = false;

    for (int i = 0; i < SIZE; i++){

        this->character[i] = nullptr;
    }
}




// a Function used to insert a word with its FileName

void Trie::insert(std::string key, string fileName)
{
    // starting from the Head node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // Create new node if the the Path isn't found
        if (curr->character[key[i]] == nullptr)
            curr->character[key[i]] = new Trie();

        // move to the next node
        curr = curr->character[key[i]];

    }
    // mark last node as leaf
    curr->isLeaf = true;
    curr->documents.push_back(fileName); //push the File Name to the Node List of documents
}

// Iterative search function to search a word in Trie. and returns the List of file Names
// if the word is found in Trie, otherwise it returns null pointer
list<string> * Trie::search(std::string word)
{
    // return null pointer if The Trie is empty
    if (this == nullptr)
        return nullptr;

    Trie* curr = this;
    for (int i = 0; i < word.length(); i++)
    {
        // go to next node each iteration
        curr = curr->character[word[i]];

        // if string is invalid (reached end of path in Trie) return null pointer
        if (curr == nullptr)
            return nullptr;
    }
    // if last node is a leaf and we have finished the loop
    // and went to the end of the word, return the Node List of Documents
    return &(curr->documents);
}

