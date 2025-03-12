#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//#include <map>

using namespace std;

using IntPair = pair<int, int>;
using ll = long long;

IntPair nDir[]
{
	{1, 0},	  // 상
	{-1, 0},  // 하
	{0, -1},  // 좌
	{ 0, 1 },  // 우
};

int n, m, v;
vector<vector<int>> g;
vector<bool> vis;

void DFS(int n = v)
{
	vis[n] = true;
	cout << n << ' ';

	for (int i = 0; i < g[n].size(); i++)
	{
		int nxt = g[n][i];

		if (!vis[nxt])
			DFS(nxt);
	}	
}

void BFS()
{
	cout << endl;
	vis.clear();
	vis.resize(n + 1);
	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		int f = q.front(); q.pop();
		cout << f << ' ';
		
		for (int i = 0; i < g[f].size(); i++)
		{
			int nxt = g[f][i];

			if (!vis[nxt])
			{
				vis[nxt] = true;
				q.push(nxt);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	g.resize(n + 1);
	vis.resize(n + 1);

	// 정점 입력
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());
	
	DFS();
	BFS();
	return 0;
}