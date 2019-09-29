// ITNOA
// O(n.k) DP by lnxdx, Mashhad
#include<iostream>
using namespace std;
const int N = 111;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int casi, n, k;
		cin >> casi >> n >> k;

		int dp[N][2][N] = { 0 };
		dp[1][0][0] = 1;
		dp[1][1][0] = 1;

		for (int b = 2;b <= n;b++)
			for (int ad = 0;ad <= k;ad++)
			{
				dp[b][0][ad] = dp[b - 1][0][ad] + dp[b - 1][1][ad];
				dp[b][1][ad] = (ad ? dp[b - 1][1][ad - 1] : 0) + dp[b - 1][0][ad];
			}
		cout << casi << ' ' << dp[n][0][k] + dp[n][1][k] << "\n";
	}
}
