#include "LRUCache.h"

LRUCache::LRUCache(unsigned cap = 1) : capacity(cap) {
    cache = new lis();
    hash = new mip();
}

LRUCache::~LRUCache(){
    delete cache;
    delete hash;
}

string LRUCache::get(int key) {
    auto it = hash->find(key);
    if(it == hash->end()) return "can't find";
    putFirst(it->second);
    (*hash)[key] = cache->begin();
    return it->second->second;

}

void LRUCache::del(int key){
    auto it = hash->find(key);
    if(it != hash->end()){
        cache->erase(it->second);
        hash->erase(it);
    }
    else cout << "del error : key isn't exsit" << endl;
}

void LRUCache::set(int key, string value) {
    auto it = hash->find(key);
    if(it != hash->end()){
        putFirst(it->second);
        cache->begin()->second = value;
    }
    else{
        if(capacity == cache->size()){
            hash->erase(cache->back().first);
            cache->pop_back();
        }
        cache->push_front({key,value});
    }
    (*hash)[key] = cache->begin();
}


void LRUCache::putFirst(lis::iterator it){
    auto c = *it;
    cache->erase(it);
    cache->push_front(c);
}

void LRUCache::show(){
    cout << "***********LRUCache::show**********" << endl;
    for(auto i = cache->begin();i != cache->end();++ i){
        cout << "key: " << i->first << " value: " << i->second << endl;
    }
}
