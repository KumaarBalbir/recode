#include <bits/stdc++.h>
#define int long long
using namespace std;
const int m = 1e9 + 7;
int n, q;
vector<int> tree;
// recursive version of code can handle everything
int solve(int node_ind, int node_low, int node_hig, int query_low, int query_hig)
{
  if (node_low >= query_low && node_hig <= query_hig)
    return tree[node_ind];
  if (query_hig < node_low || query_low > node_hig)
    return 0;

  int m = (node_low + node_hig) >> 1;
  return solve(2 * node_ind, node_low, m, query_low, query_hig) + solve(2 * node_ind + 1, m + 1, node_hig, query_low, query_hig);
}
// avoid iterative version of code
//  void update(int i, int v)
//  {
//     tree[i + n] = v;
//     for (int j = (n + i) / 2; j >= 1; j /= 2)
//     {
//        tree[j] = tree[2 * j] + tree[2 * j + 1];
//     }
//  }

// recursive version of code can handle everything
void update(int node_ind, int node_low, int node_hig, int query_low, int query_hig, int val)
{
  if (node_low >= query_low && node_hig <= query_hig)
  {
    tree[node_ind] = val;
    return;
  }
  if (query_hig < node_low || query_low > node_hig)
    return;

  int m = (node_low + node_hig) >> 1;
  update(2 * node_ind, node_low, m, query_low, query_hig, val);
  update(2 * node_ind + 1, m + 1, node_hig, query_low, query_hig, val);
  tree[node_ind] = tree[node_ind * 2] + tree[node_ind * 2 + 1];
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  while (__builtin_popcount(n) != 1)
  {
    v.push_back(0);
    n++;
  }

  tree.resize(2 * n);
  for (int i = 0; i < n; i++)
  {
    tree[n + i] = v[i];
  }
  for (int i = n - 1; i >= 1; i--)
  {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if (x == 1)
    {
      int idx, val;
      cin >> idx >> val;
      --idx;
      update(1, 0, n - 1, idx, idx, val);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << solve(1, 0, n - 1, l, r) << endl;
    }
  }
}