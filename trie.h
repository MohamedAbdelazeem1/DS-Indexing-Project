#ifndef TRIE_H
#define TRIE_H

#include "QCoreApplication"
#include "bits/stdc++.h"
#include "QString"
#include "QDebug"
#include "QChar"
#include <list>
using namespace std;
#define CHAR_SIZE 128

class Trie
{
public:
    Trie();
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    void insert(string,string);
    list <string> documents;
    list<string> * search(string);
    map <string,int> invertedIndex;
};

#endif // TRIE_H
