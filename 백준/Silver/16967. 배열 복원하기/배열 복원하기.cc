#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//using IntPair = pair<int, int>;

int main() 
{
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	vector<vector<int>> v(h + x, vector<int>(w + y));

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cin >> v[i][j];		
	}
	for (int i = x; i < h; i++)
	{
		for (int j = y; j < w; j++)
			v[i][j] -= v[i - x][j - y];
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << v[i][j] << ' ';
		cout << '\n';
	}
}