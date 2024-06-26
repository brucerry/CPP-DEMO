// https://leetcode.com/problems/open-the-lock/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string& target) {
        unordered_set<string> visited (deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;

        queue<string> queue;
        queue.push("0000");

        int turn = 0;
        while (queue.size()) {
            int size = queue.size();
            
            while (size--) {
                string code = queue.front();
                queue.pop();
                
                if (code == target)
                    return turn;
                
                for (int i = 0; i < 4; i++) {
                    rotate(code, i, 1);
                    if (visited.count(code) == 0) {
                        visited.insert(code);
                        queue.push(code);
                    }
                    rotate(code, i, -1);
                    rotate(code, i, -1);
                    if (visited.count(code) == 0) {
                        visited.insert(code);
                        queue.push(code);
                    }
                    rotate(code, i, 1);
                }
            }
            turn++;
        }

        return -1;
    }
  
    void rotate(string& code, int i, int change) {
        code[i] = (code[i] - '0' + change + 10) % 10 + '0';
    }
};

// Bi-directional BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string& target) {
        unordered_set<string> visited (deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;

        unordered_set<string> head { "0000" }, tail { target }, tmp, *phead, *ptail;

        int turns = 0;
        while (head.size() and tail.size()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            tmp = {};
            
            for (string code : *phead) {
                if (ptail->count(code))
                    return turns;

                if (visited.count(code))
                    continue;
                visited.insert(code);
                
                for (int i = 0; i < 4; i++) {
                    rotate(code, i, 1);
                    tmp.insert(code);
                    rotate(code, i, -1);
                    rotate(code, i, -1);
                    tmp.insert(code);
                    rotate(code, i, 1);
                }
            }
            turns++;
            *phead = tmp;
        }

        return -1;
    }

    void rotate(string& code, int i, int change) {
        code[i] = (code[i] - '0' + change + 10) % 10 + '0';
    }
};