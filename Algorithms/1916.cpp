#include<iostream>
#include<queue>
#include<vector>
#define INF 1987654321
using namespace std;

struct compare {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};


vector<pair<int, int>> map[1001];
int d[1001];
int N,M;


int dij(int startNode, int desNode) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	d[startNode] = 0;
	pq.push(make_pair(startNode, 0));
	while (!pq.empty()) {
		int nowNode = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (d[nowNode] < distance) continue;
		for (int i = 0; i < map[nowNode].size(); i++) {
			int nextNode = map[nowNode][i].first;
			if (d[nextNode] > d[nowNode] + map[nowNode][i].second) {
				d[nextNode] = d[nowNode] + map[nowNode][i].second;
				pq.push(make_pair(nextNode, d[nextNode]));
			}

		}
	}
	return d[desNode];
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	int startNode, desNode; cin >> startNode >> desNode;
	cout << dij(startNode, desNode);
	cout << '\n' << '\n';
	for (int i = 1; i <= N; i++) {
		cout << d[i] << ' ';
	}
	return 0;
}