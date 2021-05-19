#include <queue>
#include <iostream>
#include <vector>
#define INF 1987654321
using namespace std;
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
int N, M;
vector<pair<int, int>> map[20];
vector<int> trace[20];
int d[20];

void dij(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(start, 0));
	d[0] = 0;
	trace[0].push_back(0);
	while (!pq.empty()) {
		int nowNode = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (distance > d[nowNode]) continue;
		int mSize = map[nowNode].size();
		for (int i = 0; i < mSize; i++) {
			int nextNode = map[nowNode][i].first;
			int nextDistance = map[nowNode][i].second;
			if (d[nextNode] > nextDistance + d[nowNode]) {
				pq.push(make_pair(nextNode, nextDistance + d[nowNode]));
				d[nextNode] = nextDistance + d[nowNode];
				trace[nextNode].clear();
				int tSize = trace[nowNode].size();
				for (int j = 0; j < tSize; j++) {
					trace[nextNode].push_back(trace[nowNode][j]);
				}
				trace[nextNode].push_back(nextNode);
			}
		}

	}

}

int main() {
	int T; cin >> T;
	for (int i = 0; i < 20; i++) {
		d[i] = INF;
	}
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, c));
			map[b].push_back(make_pair(a, c));
		}
		dij(0);
		cout << "Case #" << t << ":" << ' ';
		if (d[M - 1] == INF) {
			cout << -1 << '\n';
		}
		else {
			int tSize = trace[M - 1].size();
			for (int j = 0; j < tSize; j++) {
				cout << trace[M - 1][j] << ' ';
			}
			cout << '\n';
		}

		for (int i = 0; i < M; i++) {
			d[i] = INF;
			trace[i].clear();
			map[i].clear();
		}
	}

	return 0;
}