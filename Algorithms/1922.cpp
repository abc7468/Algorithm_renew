#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int parent[1001];
vector<pair<int, pair<int,int>>> v;
int find(int node) {
	if (node == parent[node]) {
		return node;
	}
	else {
		int y = find(parent[node]);
		parent[node] = y;
		return y;
	}
}

bool check(int x, int y) {
	if (find(x) == find(y)) return false;
	return true;
}


void uni(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a < b) swap(a, b);
	parent[a] = b;
}

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	sort(v.begin(), v.end());
	int vSize = v.size();
	int count = 0;
	int ans = 0;
	for (int i = 0; i < vSize; i++) {
		if (count == N - 1) break;
		int x = v[i].second.first;
		int y = v[i].second.second;
		int dis = v[i].first;
		if (check(x, y)) {
			uni(x, y);
			count++;
			ans += dis;
		}



	}
	cout << ans;

}