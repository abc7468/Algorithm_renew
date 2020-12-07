#include<iostream>

using namespace std;

int dp[10001];
int price[10001];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
		dp[i] = price[i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[i] < dp[i - j] + dp[j]) {
				dp[i] = dp[i - j] + dp[j];
			}
		}
	}
	cout << dp[n];
	return 0;
}