// https://leetcode.com/problems/flood-fill/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class DFS {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] != color)
      solve(image, sr, sc, color, image[sr][sc]);
    return image;
  }

private:
  void solve(vector<vector<int>>& image, int r, int c, int newColor, int originalColor) {
    if (r < 0 or r >= image.size() or c < 0 or c >= image[0].size() or image[r][c] != originalColor)
      return;
    
    image[r][c] = newColor;

    solve(image, r+1, c, newColor, originalColor);
    solve(image, r-1, c, newColor, originalColor);
    solve(image, r, c+1, newColor, originalColor);
    solve(image, r, c-1, newColor, originalColor);
  }
};

class BFS {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] == color)
      return image;

    int rows = image.size();
    int cols = image[0].size();

    queue<pair<int, int>> queue;
    queue.emplace(sr, sc);
    int originalColor = image[sr][sc];
    image[sr][sc] = color;

    vector<pair<int, int>> moves { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

    while (queue.size()) {
      auto [ r, c ] = queue.front();
      queue.pop();

      for (const auto& [ dr, dc ] : moves) {
        int newr = r + dr;
        int newc = c + dc;
        if (0 <= newr and newr < rows and 0 <= newc and newc < cols and image[newr][newc] == originalColor) {
          image[newr][newc] = color;
          queue.emplace(newr, newc);
        }
      }
    }

    return image;
  }
};