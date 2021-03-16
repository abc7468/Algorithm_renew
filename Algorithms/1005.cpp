#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int cost[1001];
int dp[1001];
int parent[1001];
int root;
queue<int> q;
vector<int>v[1001];
void bfs() {
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int nextNode = v[node][i];
			if (dp[node] + cost[nextNode] > dp[nextNode]) {
				dp[nextNode] = dp[node] + cost[nextNode];
				q.push(nextNode);
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K; cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			v[i].clear();
		}


		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 1; i <= K; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			parent[b] = a;
		}
		for (int i = 1; i <= N; i++) {
			if (parent[i] == 0) { 
				dp[i] = cost[i];
				q.push(i);
			}
		}
		bfs();
		int dest; cin >> dest;

		cout << dp[dest] <<'\n';
		for (int i = 1; i <= N; i++) {
			dp[i] = 0;
			parent[i] = 0;
			cost[i] = 0;
		}
	}

	return 0;
}