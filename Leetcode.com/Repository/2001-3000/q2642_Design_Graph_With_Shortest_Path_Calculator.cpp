// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

#include <vector>
#include <queue>
using namespace std;

// time: O(e * log(n))
// space: O(n + e)

class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> graph; // to, cost
    
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        for (auto& e : edges) {
            addEdge(e);
        }
    }
    
    void addEdge(vector<int> e) {
        int from = e[0], to = e[1], cost = e[2];
        graph[from].emplace_back(to, cost);
    }
    
    int shortestPath(int from, int to) {
        vector<long> costs (n, INT_MAX);
        costs[from] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap; // cost, node
        minheap.emplace(0, from);
        
        while (minheap.size()) {
            auto [ cost, node ] = minheap.top();
            minheap.pop();
            
            if (node == to)
                return cost;

            for (auto& [ nei, neicost] : graph[node]) {
                int newcost = neicost + cost;
                if (newcost < costs[nei]) {
                    costs[nei] = newcost;
                    minheap.emplace(newcost, nei);
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */