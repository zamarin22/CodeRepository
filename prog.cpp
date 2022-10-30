#include <bits/stdc++.h>
using namespace std;

int maxPizza(int n, int arr[])
{
    int dp[n + 2];
    dp[0] = dp[1] = 0;
    int ans = 0;
    for (int i = 2; i < n + 2; i++)
    {
        int t = i - 2;
        int k = 0;
        while (t >= 0)
        {
            k = max(k, dp[t]);
            t--;
        }
        dp[i] = arr[i - 2] + k;
    }
    for (int i = 0; i < n + 2; i++)
        ans = max(ans, dp[i]);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxPizza(n, arr);
}