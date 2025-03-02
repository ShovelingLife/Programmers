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

#define MAX 10001

ll dp[MAX];

int main()
{
	dp[1] = dp[2] = 1;


	int t, c = 1;
	cin >> t;

	while (t--)
	{
		int p, q;
		cin >> p >> q;

		for (int i = 3; i <= p; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % q;

		cout << "Case #" << c++ << ": " << dp[p] % q << '\n';
	}
}