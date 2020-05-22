#ifndef TRIE_H
#define TRIE_H

#include "QCoreApplication"
#include "bits/stdc++.h"
#include "QString"
#include "QDebug"
#include "QChar"
#include "iostream"
#include <list>
using namespace std;
#define SIZE 128

class Trie
{
public:
    Trie();
    bool isLeaf;
    Trie* character[SIZE];
    void insert(string,string);
    list <string> documents;
    list<string> * search(string);
};

#endif // TRIE_H
