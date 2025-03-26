#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using IntPair = pair<int, int>;

#define y first
#define x second
#define MAX 1000

// 다음 위치 시계 방향
IntPair pos[]
{
    { 1, 0 }, // 북
    { 0, 1 }, // 서
    {-1, 0 }, // 남
    { 0,-1 }  // 동
};

int main()
{
    int n, res = 0;
    cin >> n;
    vector<int> cnt(MAX + 1);

    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        cnt[n]++;
    }
    for (int i = 0; i <= MAX; i++)
        res += min(cnt[i], 2);

    cout << res;
}