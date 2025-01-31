#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, a, b;
		cin >> n >> m;

		for (int i = 0; i < m; i++)
			cin >> a >> b;

		cout << n - 1 << '\n';
	}
	return 0;
}