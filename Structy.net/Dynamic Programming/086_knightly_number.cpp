#include <vector>

int solve(int n, int m, int r, int c, int pr, int pc, std::vector<std::vector<std::vector<int>>>& memo, char* moves) {
  if (std::min(r, c) < 0 or std::max(r, c) >= n)
    return 0;
    
  if (m == 0)
    return r == pr and c == pc;
    
  int& res = memo[r][c][m];  
  
  if (res != -1)
    return res;
    
  res = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = -1; j <= 1; j += 2) {
      int newr = r + moves[i] + (moves[i+1] ? j : 0);
      int newc = c + moves[i+1] + (moves[i] ? j : 0);
      res += solve(n, m - 1, newr, newc, pr, pc, memo, moves);
    }
  }
  
  return res;
}

int knightlyNumber(int n, int m, int kr, int kc, int pr, int pc) {
  std::vector<std::vector<std::vector<int>>> memo (n, std::vector<std::vector<int>>(n, std::vector<int>(m + 1, -1)));
  char moves[] { 0, 2, 0, -2, 0 }; // 4-dir
  return solve(n, m, kr, kc, pr, pc, memo, moves);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}