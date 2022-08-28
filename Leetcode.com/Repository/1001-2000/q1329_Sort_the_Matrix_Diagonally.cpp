// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// d = max len of diagonal = min(r, c)
// time: O(r * c * log(d))
// space: O(r * c)

class HashMap {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> mapNums;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mapNums[r - c].emplace(mat[r][c]);
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat[r][c] = mapNums[r - c].top();
        mapNums[r - c].pop();
      }
    }
    
    return mat;
  }
};

class BruteForce {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    vector<vector<int>> buffer;
    vector<int> eachRow;
    
    for (int i = cols - 1; i >= 0; i--) {
      eachRow = {};
      for (int c = i, r = 0; c < cols and r < rows; c++, r++) {
        eachRow.emplace_back(mat[r][c]);
      }
      sort(eachRow.begin(), eachRow.end());
      buffer.emplace_back(eachRow);
    }
    
    for (int i = 1; i < rows; i++) {
      eachRow = {};
      for (int r = i, c = 0; c < cols and r < rows; c++, r++) {
        eachRow.emplace_back(mat[r][c]);
      }
      sort(eachRow.begin(), eachRow.end());
      buffer.emplace_back(eachRow);
    }
    
    vector<vector<int>> result (rows, vector<int>(cols));
    
    int curRow = 0, curCol = 0;
    for (int i = cols - 1; i >= 0; i--) {
      for (int c = i, r = 0; c < cols and r < rows; c++, r++) {
        result[r][c] = buffer[curRow][curCol++];
        int size = buffer[curRow].size();
        curRow += curCol == size;
        curCol %= size;
      }
    }
    
    for (int i = 1; i < rows; i++) {
      for (int r = i, c = 0; c < cols and r < rows; c++, r++) {
        result[r][c] = buffer[curRow][curCol++];
        int size = buffer[curRow].size();
        curRow += curCol == size;
        curCol %= size;
      }
    }
    
    return result;
  }
};