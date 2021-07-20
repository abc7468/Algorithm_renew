#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> start;
vector<int> person[51];
vector<int> party[51];
vector<int> conn[51];
bool visited[51];


void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < conn[node].size(); i++) {
		int next = conn[node][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		start.push_back(tmp);
	}
	for (int i = 1; i <= M; i++) {
		int personCount;
		cin >> personCount;
		for (int j = 0; j < personCount; j++) {
			int joinner; cin >> joinner;
			party[i].push_back(joinner);
		}
	}
	
	for (int j = 1; j <= M; j++) {
		for (int k = 0; k < party[j].size(); j++) {
				person[party[j][k]].push_back(j);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < person[i].size(); j++) {
			for (int k = 0; k < party[person[i][j]].size(); k++) {
				if (party[person[i][j]][k] == i) continue;
				conn[i].push_back(party[person[i][j]][k]);
				conn[party[person[i][j]][k]].push_back(i);
			}
		}
	}

	for (int i = 0; i < start.size(); i++) {
		if (!visited[start[i]]) {
			dfs(start[i]);
		}
	}
	int count = 0;
	for (int i = 1; i <= M; i++) {
		bool isEnd = false;
		for (int j = 0; j < party[i].size(); j++) {
			if (visited[party[i][j]]) {
				isEnd = true;
				break;
			}
		}
		if (!isEnd) {
			count++;
		}
	}
	cout << count << '\n';


	return 0;
}