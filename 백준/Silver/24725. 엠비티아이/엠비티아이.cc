#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using IntPair = pair<int, int>;
using ll = long long;

IntPair dir[]
{
	{1, 0},	  // 상
	{-1, 0},  // 하
	{0, -1},  // 좌
	{ 0, 1 },  // 우

	{1, -1},	
	{1, 1}, 
	{-1, -1},
	{-1, 1 },
};

#define MAX 2

string alpha[]{"E","I", "N", "S", "F", "T", "P", "J"};
vector<string> mbti, board;
int n, m, res;

void Init()
{
	// E N F P > [0][0] + [1][0] + [2][0] + [3][0]

	for (int _1 = 0; _1 < MAX; _1++) // 0 1
	{
		for (int _2 = MAX; _2 < pow(MAX, 2); _2++) // 2 3
		{
			for (int _3 = pow(MAX, 2); _3 < pow(MAX, 2) + 2; _3++) // 4 5
			{
				for (int _4 = pow(MAX, 2) + 2; _4 < pow(MAX, 3); _4++) // 6 7
					mbti.push_back({ alpha[_1] + alpha[_2] + alpha[_3] + alpha[_4]});
			}
		}
	}
}

bool CheckValue(string str)
{
	return find(mbti.begin(), mbti.end(), str) != mbti.end();
}

int main()
{
	Init();

	cin >> n >> m;
	board.resize(n);

	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			char c = board[y][x];

			if (c == 'E' ||
				c == 'I')
			{
#pragma region 검사

				// 각 방향으로 쭉 뻗어나감
				for (int _ = 0; _ < 8; _++)
				{
					string str{c};
					IntPair nxt{ y + dir[_].first, x + dir[_].second };

					for (int i = 1; i < 4; i++)
					{
						if (nxt.first >= n ||
							nxt.first < 0 ||
							nxt.second >= m ||
							nxt.second < 0)
							continue;

						str += board[nxt.first][nxt.second];
						nxt.first += dir[_].first;
						nxt.second += dir[_].second;
					}
					res += CheckValue(str);
					//cout << str << endl;
				}

#pragma endregion
			}
		}
	}
	cout << res;
	return 0;
}