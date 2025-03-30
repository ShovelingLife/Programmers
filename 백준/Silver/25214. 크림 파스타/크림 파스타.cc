#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#pragma region 최적화

using IntPair = pair<int, int>;

#define y first
#define x second

// 다음 위치 시계 방향
IntPair pos[]
{
    { 1, 0 }, // 북
    { 0, 1 }, // 서
    {-1, 0 }, // 남
    { 0,-1 }  // 동
};

#pragma endregion

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n), dp(n + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 0;
    m = a[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(a[i] - m, dp[i - 1]);
        m = min(m, a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << dp[i] << ' ';
}