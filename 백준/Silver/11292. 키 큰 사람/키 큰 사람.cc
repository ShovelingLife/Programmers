#include <iostream>
#include <vector>
#include <map>

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

int main()
{
	int t;

	while (1)
	{
		cin >> t;

		if (t == 0)
			break;

		multimap<float, string> m;
		float mx = 0.f;

		while (t--)
		{
			string str;
			float val;
			cin >> str >> val;
			m.insert({ val,str });
			mx = max(mx, val);
		}
		auto range = m.equal_range(mx);

		for (auto it = range.first; it != range.second; it++)
			cout << it->second << ' ';

		cout << '\n';
	}
}