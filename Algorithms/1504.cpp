#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAXNODE 801
#define INF 987654321
using namespace std;

int d[MAXNODE];
vector<pair<int, int>>map[MAXNODE];
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};


int dij(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(start, 0));
	d[start] = 0;
	while (!pq.empty()) {
		int nowNode = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (distance > d[nowNode]) continue;
		int vSize = map[nowNode].size();
		for (int i = 0; i < vSize; i++) {
			int nextNode = map[nowNode][i].first;
			int nextDistance = map[nowNode][i].second;
			if (d[nextNode] > d[nowNode] + nextDistance) {
				d[nextNode] = d[nowNode] + nextDistance;
				pq.push(make_pair(nextNode, d[nowNode] + nextDistance));
			}
		}
	}

	return d[end];
}
void init(int n) {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

}
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	int forceA, forceB; cin >> forceA >> forceB;
	int forceSize = map[forceA].size();
	bool isHave = false;
	long long minForce = INF;
	init(N);
	minForce = dij(forceA, forceB);
	if (minForce == INF) {
		cout << "-1" << '\n';
		return 0;
	}
	init(N);
	long long route1 = dij(1, forceA);
	init(N);
	long long route2 = dij(forceB, N);
	init(N);
	long long route3 = dij(1, forceB);
	init(N);
	long long route4 = dij(forceA, N);
	if (min(route1 + route2, route3 + route4) == route1 + route2) {
		if (route1 == INF || route2 == INF) {
			cout << "-1" << '\n';
			return 0;
		}
	}
	else if (min(route1 + route2, route3 + route4) == route3 + route4) {
		if (route3 == INF || route4 == INF) {
			cout << "-1" << '\n';
			return 0;
		}
	}



	cout << min(route1 + route2, route3 + route4) + minForce << '\n';

	return 0;
}