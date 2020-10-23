#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

vector <pair<int,int>> map[10001];
bool v[10001];
int dis[100001];
int bigger = 0;
int startNode;
queue <int> q;

void bfs(int node) {
	v[node] = true;
	q.push(node);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i].first;
			if (v[next] == false) {
				q.push(next);
				v[next] = true;
				dis[next] = dis[now] + map[now][i].second;
				if (dis[next] > bigger) {
					bigger = dis[next];
					startNode = node;
				}
			}
			
		}

	}
}

int main() {
	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++) {
		memset(dis, 0, sizeof(dis));
		memset(v, false, sizeof(v));
		bfs(i);
	}
	cout << bigger;
}