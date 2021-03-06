#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001
using namespace std;

bool visited[MAX];
vector<int>v[MAX];
vector<vector<int>>SCC;
int d[MAX];
int id;
stack<int> s;

int dfs(int x) {
	s.push(x);
	d[x] = ++id;
	int parent = d[x];
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (d[next] == 0) parent = min(parent, dfs(next));
		else if (!visited[next]) parent = min(parent, d[next]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int top = s.top();
			s.pop();
			scc.push_back(top);
			visited[top] = true;
			if (top == x) break;
		}
		SCC.push_back(scc);
	}


	return parent;
}

bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[0] < b[0];
}

int main() {
	int V, E; cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == false) dfs(i);
	}

	int SCCSize = SCC.size();
	for (int i = 0; i < SCCSize; i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end(), cmp);
	cout << SCCSize << '\n';
	for (int i = 0; i < SCCSize; i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << "-1" << '\n';
	}

	return 0;
}