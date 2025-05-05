#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define INF 2e9

int main()
{
	ll n, cur = 0, a = INF, b = INF;
	bool flag = false;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;

		if (x == -1)
		{
			flag = true;
			continue;
		}
		if (!flag)
			a = min(a, x);

		else
			b = min(b, x);
	}
	cout << a + b;
}