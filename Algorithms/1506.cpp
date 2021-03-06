#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#define MAX 100
using namespace std;
int id;
int d[MAX];
bool visited[MAX];
int cost[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
int dfs(int val) {
	s.push(val);
	d[val] = ++id;
	int parent = d[val];

	for (int i = 0; i < v[val].size(); i++) {
		int next = v[val][i];
		if (d[next] == 0) {
			parent = min(parent, dfs(next));
		}
		else if (!visited[next]) {
			parent = min(parent, d[next]);
		}
	}

	if (parent == d[val]) {
		vector<int>scc;
		while (1) {
			int top = s.top();
			s.pop();
			scc.push_back(cost[top]);
			visited[top] = true;
			if (top == val) break;
		}
		SCC.push_back(scc);
	}




	return parent;
}


int main() {
	int N; cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> cost[n];
	}
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		
		for (int j = 0; j < N; j++) {
			if (s[j] - '0' == 1) v[i].push_back(j);
		}
	}
	for (int n = 0; n < N; n++) {
		if (visited[n] == false) dfs(n);
	}
	int SCCSize = SCC.size();
	for (int i = 0; i < SCCSize; i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	int ans = 0;
	for (int i = 0; i < SCCSize; i++) {
		ans += SCC[i][0];
	}

	cout << ans;
	return 0;
}