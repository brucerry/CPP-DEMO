// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/

// time: O(1)
// space: O(1)

class DataStream {
public:
    DataStream(int value, int k) : k(k), value(value), count(0) {

    }
    
    bool consec(int num) {
        count = num == value ? count + 1 : 0;
        return count >= k;
    }

private:
    int k, value, count;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */