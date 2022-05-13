// https://leetcode.com/problems/time-based-key-value-store/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// time: O(1) for set(), O(log(n)) for get()
// space: O(n)

class TimeMap {
public:
  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    m_Map[key].emplace_back(timestamp, value);
  }
  
  string get(string key, int timestamp) {
    if (m_Map.count(key) == 0)
      return "";
    
    string value;
    int l = 0, r = m_Map[key].size() - 1;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      const auto& [ time, val ] = m_Map[key][m];
      
      if (time <= timestamp) {
        value = val;
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    
    return value;
  }
  
private:
  unordered_map<string, vector<pair<int, string>>> m_Map; // key, (timestamp, value)
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */