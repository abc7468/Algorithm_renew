#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
pair<int, int> dp[16];
pair<int, int> map[16];


int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int t, c; cin >> t >> c;
		map[i] = make_pair(t, c);
	}
	int pointer = 1;
	int mmax = 0;
	dp[1] = make_pair(map[1].second, map[1].first - 1);//dp.first = cost, dp.second = time
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[j].second == 0) {
				if (mmax < dp[j].first)mmax = dp[j].first;
			}
			else dp[j].second--;
		}
		//if (dp[pointer].second == 0) {
		//	while (pointer < i) {
		//		if (dp[pointer].second != 0) {
		//			break;
		//		}
		//		pointer++;
		//	}
		//}
		dp[i] = make_pair(mmax+map[i].second, map[i].first - 1);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i].second == 0 && dp[i].first > ans)ans = dp[i].first;
	}
	
	//for (int i = 1; i <= N; i++) {
	//	cout << dp[i].first << ' ';
	//}

	cout << ans;

	return 0;
}