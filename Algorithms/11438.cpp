#include<iostream>
#include<vector>
#define MAX 100001
#define LOG 18
using namespace std;
bool visited[MAX];
vector<int>v[MAX];
int depth[MAX];
int parent[MAX][LOG];
int N;


void initDepth(int node) {
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int nextNode = v[node][i];
		if (visited[nextNode] == false) {
			visited[nextNode] = true;
			depth[nextNode] = depth[node] + 1;
			parent[nextNode][0] = node;
			initDepth(nextNode);
		}
	}
}

void initParent() {
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	initDepth(1);
	initParent();

	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		int a, b; cin >> a >> b;
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = LOG - 1; i > -1; i-- ) {
			if (depth[a] - depth[b] >= (1 << i)) {
				a = parent[a][i];
			}
		}
		if (a == b) {
			cout << a << '\n';
			continue;
		}
		for (int i = LOG-1; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		cout << parent[a][0] << '\n';

	}
	return 0;



}