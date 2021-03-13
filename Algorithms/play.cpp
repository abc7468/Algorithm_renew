#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main()
{
	int n;
	int a;
	int dp[2][41] = { 0, };
	cin >> n;
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[0][1] = 0;
	dp[1][1] = 1;
	for (int i = 2; i < 41; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << dp[0][a] << ' ' << dp[1][a] << '\n';
	}
}