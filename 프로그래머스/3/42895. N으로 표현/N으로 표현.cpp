#include <string>
#include <vector>

using namespace std;

int answer = 9;
int goal = 0;
 
void cal(int n, int cnt, int sum)
{
    if (cnt > 8) 
    return;
 
    if (sum == goal &&
        answer > cnt)
        answer = cnt;
 
    int tmp = 0;
 
    for (int i = 1; i <= 8; i++)
    {
        tmp = (tmp * 10) + n;
 
        cal(n, cnt + i, sum + tmp);
        cal(n, cnt + i, sum - tmp);
        cal(n, cnt + i, sum / tmp);
        cal(n, cnt + i, sum * tmp);
    }
}
 
int solution(int N, int number)
{
    goal = number;
    cal(N, 0, 0);
    return (answer > 8) ? -1 : answer;
}