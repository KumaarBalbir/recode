#include <bits/stdc++.h> //finds no of connected component
using namespace std;
#define int long long
vector<bool> visited;
vector<vector<int>> graph;
void dfs(int vertex)
{
  // take action on vertex after entering the vertex
  visited[vertex] = true;
  for (int child : graph[vertex])
  {
    // take action on child before entering the child node
    if (visited[child])
      continue;
    dfs(child);
    // take action on child after existing the child node
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
  visited.resize(n + 1);
  for (int i = 0; i < e; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
      continue;
    dfs(i);
    cnt++;
  }
  cout << cnt << endl;
}