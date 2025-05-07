#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, int w, int num)
{
	int answer = 0, idx = 0, pos = 0;
	vector<stack<int>> v(w);
	bool flag = true;

	for (int i = 1; i <= n; i++)
	{
		if (i == num)
			pos = idx;

		if (flag)
			v[idx++].push(i);

		else
			v[idx--].push(i);

		if (i % w == 0)
		{
			flag = !flag;

			if (!flag)
				idx--;

			else
				idx++;
		}
	}
	while (!v[pos].empty())
	{
		int n = v[pos].top(); v[pos].pop();
		answer++;

		if (n == num)
			break;
	}
	return answer;
}