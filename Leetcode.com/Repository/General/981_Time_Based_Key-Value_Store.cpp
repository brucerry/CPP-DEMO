// https://leetcode.com/problems/time-based-key-value-store/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// time: O(1) for set(), O(log(n)) for get()
// space: O(n)

class TimeMap {
private:
  unordered_map<string, vector<pair<string, int>>> m_Map; // key, (value, timestamp)
  
public:
  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    m_Map[key].emplace_back(value, timestamp);
  }
  
  string get(string key, int timestamp) {
    string ans;
    
    auto& values = m_Map[key];
    
    int l = 0, r = values.size() - 1;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (values[m].second <= timestamp) {
        ans = values[m].first;
        l = m + 1;
      }
      else
        r = m - 1;
    }
    
    return ans;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */