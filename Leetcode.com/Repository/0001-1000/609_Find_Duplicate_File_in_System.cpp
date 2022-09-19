// https://leetcode.com/problems/find-duplicate-file-in-system/

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

// n = total chars in paths
// time: O(n)
// space: O(n)

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> contentGroups;
    vector<vector<string>> result;

    for (const string& path : paths) {
	    stringstream ss (path);
	    string root;
	    string s;
	    getline(ss, root, ' ');
	    while (getline(ss, s, ' ')) {
		    string fileName = root + '/' + s.substr(0, s.find('('));
		    string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
		    contentGroups[fileContent].emplace_back(fileName);
	    }
    }

    for (const auto& [ _, groups ] : contentGroups) {
      if (groups.size() > 1)
	      result.emplace_back(groups);
    }

    return result;
  }
};