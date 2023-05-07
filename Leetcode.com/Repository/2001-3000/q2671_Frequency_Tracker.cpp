// https://leetcode.com/problems/frequency-tracker/

#include <unordered_map>
using namespace std;

// time: O(1) for each method
// space: O(n)

class FrequencyTracker {
public:
    unordered_map<int, int> num_freq;
    unordered_map<int, int> freq_count;
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int& f = num_freq[number];
        freq_count[f]--;
        freq_count[++f]++;
    }
    
    void deleteOne(int number) {
        if (num_freq[number] == 0)
            return;
        
        int& f = num_freq[number];
        freq_count[f]--;
        freq_count[--f]++;
    }
    
    bool hasFrequency(int frequency) {
        return freq_count[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */