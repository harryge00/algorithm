#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

class Trie {
private:
    Trie *next[26];
    bool isWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *p = this;
        int curIndex;
        int i = 0;
        for(; i < word.size() - 1; i++) {
            curIndex = word[i] - 'a';
            if(p->next[curIndex] == NULL) {
                p->next[curIndex] = new Trie();
            }
            p = p->next[curIndex];
        }
        curIndex = word[i] - 'a';
        p->next[curIndex] = new Trie();
        p->next[curIndex]->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *p = this;
        int i = 0;
        for(; p && i < word.size(); i++) {
            p = p->next[word[i] - 'a'];
        }
        return p && p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *p = this;
        int i = 0;
        for(; p && i < prefix.size(); i++) {
            p = p->next[prefix[i] - 'a'];
        }
        return i == prefix.size() && p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 001010
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout<<obj->search("app");
    cout<<obj->search("appe");
    cout<<obj->startsWith("app");
    cout<<obj->startsWith("appe");
    cout<<obj->startsWith("appl");
    cout<<obj->search("apple");
    cout<<obj->search("append");
    obj->insert("append");
    cout << endl;
    cout<< obj->startsWith("appe") << endl;
    cout<< obj->startsWith("apple") << endl;
    cout<< obj->startsWith("append") << endl;
}