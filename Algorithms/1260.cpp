#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> map[1001];
queue<int> q;

bool v[1001];

void clear(int n) {
	for (int i = 1; i <= n; i++) {
		v[i] = false;
	}
}

void dfs(int node) {
	v[node] = true;
	cout << node <<' ';
	for (int i = 0; i < map[node].size(); i++) {
		int next = map[node][i];
		if (v[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int node) {
	q.push(node);
	v[node] = true;
	while (!q.empty()) {
		int next = q.front(); q.pop();
		cout << next << ' ';
		for (int i = 0; i < map[next].size(); i++) {
			if (v[map[next][i]] == false) {
				q.push(map[next][i]);
				v[map[next][i]] = true;
			}

		}
			
		
	}

}

int main() {
	int N, M, V; cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(map[i].begin(), map[i].end());
	}
	dfs(V);
	cout << '\n';
	clear(N);
	bfs(V);
	return 0;
}