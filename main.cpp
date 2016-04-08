#include <LRUCache.h>
#include <iostream>
#include <vector>
using std::cin;
using std::vector;
string getRandStr(){
    string res;
    int i = rand();
    while(i / 26){
        res += (i % 26) + 'a';
        i /= 26;
    }
    return res;
}
void setTest(LRUCache& lru,int CAPA,vector<pair<int,string>>& kvVec){
    cout << "**********setTest:************" << endl;
    for(int i = 0;i < CAPA;++ i){
        int key;
        string val;
        //cin >> key >> val;
        key = rand();
        val = getRandStr();
        lru.set(key,val);
        kvVec.push_back(make_pair(key,val));
    }

    lru.show();
}


void delTest(LRUCache& lru,vector<pair<int,string>>& kvVec){
    cout <<"********delTest*******" << endl;
    int len = kvVec.size();
    int delNum = len / 3;
    cout << "delNum : " << delNum <<endl;
    for(int i = 0;i < delNum;++ i){
        unsigned delIndex = rand() % kvVec.size();
        cout << "del: key : " << kvVec[delIndex].first << " val: " << kvVec[delIndex].second << endl;
        lru.del(kvVec[delIndex].first);
        kvVec.erase(delIndex + kvVec.begin());
    }
    lru.show();
}

void getTest(LRUCache& lru,vector<pair<int,string>>& kvVec){

    cout << "**********getTest********" << endl;
    int len = kvVec.size();
    int getNum = rand() % len;
    for(int i = 0;i < getNum;++ i){
        int getIndex = rand()% len;
        cout << "kvVec: key : " << kvVec[getIndex].first << " Val: " << kvVec[getIndex].second << endl;
        cout << "lru.get():" << lru.get(kvVec[getIndex].first) << endl;
    }
    lru.show();
}
int main(){

    srand(static_cast<unsigned int>(time(nullptr)));
    unsigned CAPA = rand() % 20;
    while(CAPA == 0){
        CAPA = rand() % 20;
    }
    LRUCache lru(CAPA);

    vector<pair<int,string>> kvVec;
    cout << "plz input "<< CAPA << " key and val" << endl;
    setTest(lru,CAPA,kvVec);
    cout << endl;
    delTest(lru,kvVec);
    cout << endl;
    setTest(lru,CAPA,kvVec);
    cout << endl;
    getTest(lru,kvVec);
    return 0;
}


