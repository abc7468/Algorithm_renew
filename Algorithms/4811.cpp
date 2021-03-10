#include <iostream>
using namespace std;

int N;
long long dp[31][31] = { 0 };
long long dfs(int W, int H) {

	if (dp[W][H])
		return dp[W][H];

	if (W == 0)
		return 1;

	dp[W][H] = dfs(W - 1, H + 1);
	if (H > 0)
		dp[W][H] += dfs(W, H - 1);

	return dp[W][H];
}

int main() {

	std::ios_base::sync_with_stdio(false);
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		cout << dfs(N, 0) << endl;
	}

	return 0;
}
