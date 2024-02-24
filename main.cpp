#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        int answer = INT_MAX;
        queue<pair<int, int>> q;
        int stop = 0;
        q.push({src, 0});
        while (!q.empty() && stop++ <= k) {
            int size = q.size(); // We need to save this here; size will be changed
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                for (auto neighbor : graph[curr.first]) {
                    int cost = neighbor.second + curr.second;
                    if (answer < cost) continue;

                    q.push({neighbor.first, cost});

                    if (neighbor.first == dst) {
                        answer = min(answer, cost);
                    }
                }
            }
        }
        return answer == INT_MAX ? -1 : answer;
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
