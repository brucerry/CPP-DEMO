// https://leetcode.com/problems/most-popular-video-creator/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

struct Info {
  long sumOfViews;
  int mostViews;
  string mostViewsSmallestID;

  // '~' > 'z'
  Info() : sumOfViews(0), mostViews(0), mostViewsSmallestID("~") {}
};

class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    int n = ids.size();
    
    unordered_map<string, Info> umap; // name, struct info
    long maxSum = 0;
    for (int i = 0; i < n; i++) {
      string& name = creators[i], &id = ids[i];
      int& view = views[i];
      if (umap.count(name) == 0)
        umap[name] = Info();

      Info* p = &umap[name];
      maxSum = max(maxSum, p->sumOfViews += view);
      if (view > p->mostViews or (view == p->mostViews and id < p->mostViewsSmallestID)) {
        p->mostViewsSmallestID = id;
        p->mostViews = view;
      }
    }
    
    vector<vector<string>> result;
    for (const auto& [ name, info ] : umap) {
      if (info.sumOfViews == maxSum)
        result.push_back({ name, info.mostViewsSmallestID });
    }

    return result;
  }
};