#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);

        for (auto flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int stops = 0;

        while (stops <= k && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                int apt = curr.first;
                int cost = curr.second;

                for (auto neighbor : adjList[apt]) {
                    int nextApt = neighbor.first;
                    int nextCost = neighbor.second;

                    if (cost + nextCost < dist[nextApt]) {
                        dist[nextApt] = cost + nextCost;
                        q.push({nextApt, cost+nextCost});
                    }
                }
            }
            stops++;
        }
        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }


    // int dfs(vector<vector<pair<int, int>>>& graph, int from, int dst, int price, int stops, int atMost) {
    //     if (from == dst) return price;
    //     else if (stops > atMost) return -1;

    //     vector<int> costs;
    //     for (auto pair : graph[from]) {
    //         int cost = dfs(graph, pair.first, dst, price+pair.second, stops+1, atMost);
    //         costs.push_back(cost);
    //     }

    //     int mini = INT_MAX;
    //     for (int cost : costs) {
    //         if (cost > 0 && cost < mini) {
    //             mini = cost;
    //         }
    //     }
    //     if (mini == INT_MAX) return -1;
    //     return mini;
    // }
};
