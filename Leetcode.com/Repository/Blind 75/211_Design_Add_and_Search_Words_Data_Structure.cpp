// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <string>
#include <array>
using namespace std;

struct Trie {
    Trie* children[26] = {};
    bool isEnd = false;

    Trie() {}

    void insert(string& word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string& word, Trie* cur, int start) {
        for (int i = start; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (cur->children[j] and search(word, cur->children[j], i + 1))
                        return true;
                }
                return false;
            }
            else {
                if (!cur->children[word[i] - 'a'])
                    return false;
                cur = cur->children[word[i] - 'a'];
            }
        }
        return cur->isEnd;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word, root, 0);
    }

private:
    Trie* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */