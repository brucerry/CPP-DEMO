#include <queue>
#include <vector>

int knightAttack(int n, int kr, int kc, int pr, int pc) {
  std::queue<std::pair<int, int>> queue; // r, c
  queue.emplace(kr, kc);
  
  char moves[] { 0, 2, 0, -2, 0 }; // 4-dir
  std::vector<std::vector<char>> visited (n, std::vector<char>(n));
  
  int steps = 0;
  while (queue.size()) {
    for (int size = queue.size(); size; size--){
      auto [ r, c ] = queue.front();
      queue.pop();
      if (r == pr and c == pc)
        return steps;
      for (int i = 0; i < 4; i++) {
        for (int j = -1; j <= 1; j += 2) {
          int newr = r + moves[i] + (moves[i+1] ? j : 0);
          int newc = c + moves[i+1] + (moves[i] ? j : 0);
          if (std::min(newr, newc) >= 0 and std::max(newr, newc) < n and visited[newr][newc] == 0) {
            visited[newr][newc] = 1;
            queue.emplace(newr, newc);
          }
        }
      }
    }
    steps++;
  }
  
  return -1;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}