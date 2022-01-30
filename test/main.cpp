#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
using namespace std;


unordered_map<string, vector<string>> buildGraph(std::vector<std::tuple<std::string, std::string>> edges) {
  unordered_map<string, vector<string>> graph;
  for (auto [ a, b ] : edges) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

bool undirectedPath(unordered_map<string, vector<string>> graph, string src, string dst) {
  if (src == dst) return true;
  
  for (auto neighbor : graph[src]) {
    if (undirectedPath(graph, neighbor, dst)) return true;
  }
  
  return false;
}


bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst) {
  unordered_map<string, vector<string>> graph = buildGraph(edges);
  return undirectedPath(graph, src, dst);
}



int main() {
  std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "j", "m"); // -> 1 (true)
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}