#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int map[101];
bool visited[101];
bool inStack[101];
stack<int> s;
vector<int>ans;
int N;
void inputAns(int parentNode) {
	while (s.top() != parentNode) {
		ans.push_back(s.top());
		s.pop();
	}
	ans.push_back(parentNode);
	while (!s.empty()) {
		s.pop();
	}
	for (int i = 1; i <= N; i++) {
		inStack[i] = false;
	}
}

void dfs(int node) {
	inStack[node] = true;
	s.push(node);
	visited[node] = true;
	if (inStack[map[node]]) {
		inputAns(map[node]);
		return;
	}
	if (!visited[map[node]]) {
		dfs(map[node]);
	}
	inStack[node] = false;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {

		cin >> map[i];
		if (i == map[i]) {
			ans.push_back(i);
			visited[i] = true;
		}

	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	int ansSize = ans.size();
	sort(ans.begin(), ans.end());
	cout << ansSize << '\n';
	for (int i = 0; i < ansSize; i++) {
		cout << ans[i] << '\n';
	}
	return 0;

}