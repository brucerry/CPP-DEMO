// https://leetcode.com/problems/minimum-genetic-mutation/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// n = size of bank
// time: O(n)
// space: O(n)

class BidirectionalBFS {
public:
  int minMutation(string& start, string& end, vector<string>& bank) {
    unordered_set<string> bankSet (bank.begin(), bank.end()), head, tail, *phead, *ptail, tmp;
    if (bankSet.count(end) == 0)
      return -1;
    
    char choices[] = { 'A', 'C', 'G', 'T' };
    
    head.emplace(start);
    tail.emplace(end);
    
    int mutation = 1;
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
      for (string gene : *phead) {
        for (char& c : gene) {
          char backup_c = c;
          for (char& choice : choices) {
            c = choice;
            if (ptail->count(gene))
              return mutation;
            if (bankSet.count(gene)) {
              bankSet.erase(gene);
              tmp.emplace(gene);
            }
          }
          c = backup_c;
        }
      }
      
      mutation++;
      *phead = tmp;
    }
    
    return -1;
  }
};

class BFS {
public:
  int minMutation(string& start, string& end, vector<string>& bank) {
    unordered_set<string> bankSet (bank.begin(), bank.end());
    if (bankSet.count(end) == 0)
      return -1;
    
    char choices[] = { 'A', 'C', 'G', 'T' };
    
    queue<string> queue;
    queue.emplace(start);
    
    int mutation = 0;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        string gene = queue.front();
        queue.pop();
        
        if (gene == end)
          return mutation;
        
        for (char& c : gene) {
          char backup_c = c;
          for (char& choice : choices) {
            c = choice;
            if (bankSet.count(gene)) {
              bankSet.erase(gene);
              queue.emplace(gene);
            }
          }
          c = backup_c;
        }
      }
      mutation++;
    }
    
    return -1;
  }
};