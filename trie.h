#ifndef TRIE_H
#define TRIE_H

#include "QCoreApplication"
#include "bits/stdc++.h"
#include "QString"
#include "QDebug"
#include "QChar"
#include "bst.h"
using namespace std;
#define CHAR_SIZE 128

class Trie
{
public:
    Trie();
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    void insert(string,string);
    map<string,int> search(string);
    map <string,int> invertedIndex;
    BST documents;
};

#endif // TRIE_H
