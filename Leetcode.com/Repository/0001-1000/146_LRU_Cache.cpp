// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

// double linked list
// time: O(1) for operations
// space: O(n)

struct Node {
    int key, value;
    Node* left, *right;

    Node() : key(0), value(0), left(nullptr), right(nullptr) {}
    Node(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}
    Node(int key, int value, Node* left, Node* right) : key(key), value(value), left(left), right(right) {}
};

class LRUCache {
public:
    int capacity_;
    unordered_map<int, Node*> cache_; // key, node
    Node* LRU_, *MRU_;

    void insert(Node* node) {
        node->left = MRU_->left;
        node->right = MRU_;
        node->left->right = MRU_->left = node;
    }

    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        node->left = node->right = nullptr;
    }

    LRUCache(int capacity) {
        capacity_ = capacity;
        LRU_ = new Node(0, 0, nullptr, MRU_);
        MRU_ = new Node(0, 0, LRU_, nullptr);
    }
    
    int get(int key) {
        if (cache_.count(key) == 0)
            return -1;
        Node* node = cache_[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache_.count(key)) {
            Node* node = cache_[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        cache_[key] = node;
        insert(node);
        if (cache_.size() > capacity_) {
            cache_.erase(LRU_->right->key);
            remove(LRU_->right);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */