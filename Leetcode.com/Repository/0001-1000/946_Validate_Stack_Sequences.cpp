// https://leetcode.com/problems/validate-stack-sequences/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stk;
        int i = 0;
        for (int num : pushed) {
            stk.push_back(num);
            while (stk.size() and stk.back() == popped[i]) {
                stk.pop_back();
                i++;
            }
        }
        return stk.size() == 0;
    }
};

// time: O(n)
// space: O(1)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for (int num : pushed) {
            pushed[i++] = num;
            while (i and pushed[i-1] == popped[j]) {
                i--, j++;
            }
        }
        return i == 0;
    }
};