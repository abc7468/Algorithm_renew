#include<iostream>
#include<vector>
using namespace std;
int d[50001];
int p[50001];
bool visited[50001];
vector<int>v[50001];
int N;
void dfs(int node) {
	visited[node] = true;
	int nowDepth = d[node];
	for (int i = 0; i < v[node].size(); i++) {
		int nextNode = v[node][i];
		if (visited[nextNode] == false) {
			d[nextNode] = nowDepth + 1;
			p[nextNode] = node;
			dfs(nextNode);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	p[1] = 1;
	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		int a, b; cin >> a >> b;
		if (d[a] < d[b]) {
			swap(a, b);
		}
		while (d[a] != d[b]) {
			a = p[a];
		}
		while (a!=b) {
			a = p[a];
			b = p[b];
		}
		cout << a<<'\n';
	}
	return 0;
}