#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<climits>
#include<list>
#include<algorithm>
#include<unordered_map>
using namespace std;

class LRUCache {
private:
	typedef list<int> LI;
	typedef pair<int, LI::iterator> PII;
	LI keys;
	unordered_map<int, PII> cache;
	void touch(int key, unordered_map<int, PII>::iterator &pi) {
		keys.erase(pi->second);
		keys.push_front(key);
		pi->second = keys.begin();
	}
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    int get(int key) {
    	unordered_map<int, PII>::iterator it = cache.find(key);
    	if(it == cache.end()) return -1;    	
    	touch(key, it);
    	cout<<key<<","<<it->first<<endl;
       	return it->first;
    }
    
    void put(int key, int value) {
    	unordered_map<int, PII>::iterator it = cache.find(key);

    	if(it != cache.end()) {
    		touch(key, it);
    		it->first = key;
    	} else {
    		keys.push_front(key);
    		PII pi(value, keys.begin());
    		map[key] = pi;
    		if(keys.size() > _capacity) {
    			map.remove(keys.back());
    			keys.pop_end();
    		}
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main() {
	LRUCache cache = new LRUCache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4
}

