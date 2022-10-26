// https://leetcode.com/problems/matrix-block-sum/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)
class InplacePrefixSum {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int rows = mat.size(), cols = mat[0].size();
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int left = 0 <= c - 1 ? mat[r][c-1] : 0;
        int top = 0 <= r - 1 ? mat[r-1][c] : 0;
        int diag = 0 <= c - 1 and 0 <= r - 1 ? mat[r-1][c-1] : 0;
        mat[r][c] += left + top - diag;
      }
    }

    vector<vector<int>> result (rows, vector<int>(cols));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int minr = max(0, r - k);
        int maxr = min(rows - 1, r + k);
        int minc = max(0, c - k);
        int maxc = min(cols - 1, c + k);
        int left = 0 <= minc - 1 ? mat[maxr][minc-1] : 0;
        int top = 0 <= minr - 1 ? mat[minr-1][maxc] : 0;
        int diag = 0 <= minc - 1 and 0 <= minr - 1 ? mat[minr-1][minc-1] : 0;
        result[r][c] = mat[maxr][maxc] - left - top + diag;
      }
    }
    return result;
  }
};

// time: O(r * c)
// space: O(r * c)
class PrefixSum {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> prefix (rows + 1, vector<int>(cols + 1));
    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        prefix[r][c] = mat[r-1][c-1] + prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1];
      }
    }

    vector<vector<int>> result (rows, vector<int>(cols));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int minr = max(0, r - k);
        int maxr = min(rows - 1, r + k);
        int minc = max(0, c - k);
        int maxc = min(cols - 1, c + k);
        result[r][c] = prefix[maxr+1][maxc+1] - prefix[maxr+1][minc] - prefix[minr][maxc+1] + prefix[minr][minc];
      }
    }
    return result;
  }
};

// time: O(r * c * k^2)
// space: O(1)
class BruteForce {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> result (rows, vector<int>(cols));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int sum = 0;
        for (int i = max(0, r - k); i <= min(rows - 1, r + k); i++) {
          for (int j = max(0, c - k); j <= min(cols - 1, c + k); j++) {
            sum += mat[i][j];
          }
        }
        result[r][c] = sum;
      }
    }
    return result;
  }
};