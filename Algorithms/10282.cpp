#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 10001
#define INF 987654321
using namespace std;

int n, d, c;
int dis[MAX];

vector<pair<int, int>> map[MAX];
vector<int> trace;
struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

void dij(int startNode) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	dis[startNode] = 0;
	pq.push({ startNode, 0 });
	while (!pq.empty()) {

		int nowNode = pq.top().first;
		int distance = pq.top().second;
		trace.push_back(nowNode);

		pq.pop();
		if (dis[nowNode] < distance)continue;
		int mSize = map[nowNode].size();
		for (int i = 0; i < mSize; i++) {
			int nextNode = map[nowNode][i].first;
			int nextDist = map[nowNode][i].second;
			if (dis[nextNode] > nextDist + dis[nowNode]) {
				dis[nextNode] = nextDist + dis[nowNode];
				pq.push({ nextNode, nextDist + dis[nowNode] });
			}
		}
	}

}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= MAX; i++) {
		dis[i] = INF;
	}
	for (int t = 0; t < T; t++) {
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int a, b, s; cin >> a >> b >> s;
			map[b].push_back({ a,s });
		}
		dij(c);
		trace.erase(unique(trace.begin(), trace.end()), trace.end());
		int max = 0;
		int tSize = trace.size();
		for (int i = 0; i < tSize; i++) {
			if (dis[trace[i]] > max) max = dis[trace[i]];
		}
		cout << tSize << ' ' << max << '\n';
		for (int i = 1; i <= n; i++) {
			dis[i] = INF;
			map[i].clear();
		}
		trace.clear();
	}
}