#include <bits/stdc++.h> //height and distance of each node
using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<vector<int>> graph;
int depth[N];
int height[N];
void dfs(int vertex, int par = 0)
{
  // take action on vertex after entering the vertex

  for (int child : graph[vertex])
  {
    // take action on child before entering the child node
    if (child == par)
      continue;
    depth[child] = depth[vertex] + 1;
    dfs(child, vertex);
    // take action on child after existing the child node
    height[vertex] = max(height[vertex], height[child] + 1);
  }
  // take action on vertex before existing the vertex
}
int32_t main()
{

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, e;
  cin >> n >> e;
  graph.resize(n + 1);

  for (int i = 0; i < e; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  dfs(1, 0);
  // print height and distance
}