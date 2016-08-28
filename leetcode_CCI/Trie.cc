class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;
    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode(false);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); i++) {
            int ch = word[i] - 'a';
            if(p->next[ch] == NULL) {
                p->next[ch] = new TrieNode(false);
            }
            if(i == word.length() - 1 && !p->next[ch]->is_word) {
                p->next[ch]->is_word = true;
            }
            p = p->next[ch];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        int ch;
        for(int i = 0; i < word.length(); i++) {
            ch = word[i] - 'a';
            if(p->next[ch] == NULL) {
                return false;
            }
            if(i == word.length() - 1) {
                return p->next[ch]->is_word;
            }
            p = p->next[ch]; 
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        int ch;
        for(int i = 0; i < prefix.length(); i++) {
            ch = prefix[i] - 'a';
            if(p->next[ch] == NULL) {
                return false;
            }
            p = p->next[ch]; 
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");