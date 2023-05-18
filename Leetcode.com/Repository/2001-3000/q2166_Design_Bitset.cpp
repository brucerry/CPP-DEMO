// https://leetcode.com/problems/design-bitset/

#include <string>
using namespace std;

// time: O(size) for constructor, O(1) for all methods
// space: O(size)

class Bitset {
public:
    string bitset, ones_complement;
    int ones, size;

    Bitset(int size) {
        this->size = size;
        this->ones = 0;
        this->bitset = string(size, '0');
        this->ones_complement = string(size, '1');
    }
    
    void fix(int idx) {
        ones += bitset[idx] == '0';
        bitset[idx] = '1';
        ones_complement[idx] = '0';
    }
    
    void unfix(int idx) {
        ones -= bitset[idx] == '1';
        bitset[idx] = '0';
        ones_complement[idx] = '1';
    }
    
    void flip() {
        swap(bitset, ones_complement);
        ones = size - ones;
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return bitset;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */