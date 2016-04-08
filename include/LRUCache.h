#ifndef LRUCACHE_H
#define LRUCACHE_H


#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <ctime>
#include <stdlib.h>

using std::string;
using std::unordered_map;
using std::list;
using std::pair;
using std::cout;
using std::endl;

class LRUCache{
    typedef list<pair<int,string> > lis;
    typedef unordered_map<int,lis::iterator> mip;

    lis* cache;
    mip* hash;
    int capacity;

    void putFirst(lis::iterator it);
public:
    LRUCache(unsigned cap);
    ~LRUCache();

    string get(int key);
    void del(int key);
    void set(int key, string value);

    void show();
};
#endif // LRUCACHE_H
