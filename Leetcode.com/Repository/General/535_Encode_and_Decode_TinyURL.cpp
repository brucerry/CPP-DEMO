// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(1)
// space: O(n)

class Solution {
public:

  // Encodes a URL to a shortened URL.
  string encode(const string& longUrl) {
    if (encodeMap.count(longUrl) == 0) {
      string shortUrl = base + to_string(encodeMap.size());
      encodeMap[longUrl] = shortUrl;
      decodeMap[shortUrl] = longUrl;
    }
    return encodeMap[longUrl];
  }

  // Decodes a shortened URL to its original URL.
  string decode(const string& shortUrl) {
    return decodeMap[shortUrl];
  }
  
private:
  unordered_map<string, string> encodeMap;
  unordered_map<string, string> decodeMap;
  string base = "http://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));