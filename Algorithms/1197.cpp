#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,pair<int, int>>> map;
int parent[10001];

int Find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b) {
	int small;
	int big;
	if (Find(a) < Find(b)) {
		small = Find(a);
		big = Find(b);
		if (small != big) {
			parent[big] = small;
		}
	}
	else {
		small = Find(b);
		big = Find(a);
		if (small != big) {
			parent[big] = small;
		}
	}
}



bool checkParent(int a, int b) {
	if (Find(a) == Find(b)) return false;
	else return true;
}

bool cmp(const pair<int,pair<int,int>> &a, const pair<int,pair<int, int>> &b) {
	return a.second.second < b.second.second;
}


int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map.push_back(make_pair(a, make_pair(b, c)));
	}
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	sort(map.begin(), map.end(),cmp);
	int brk = 0;
	long long ans=0;
	for (int i = 0; i < E ; i++) {
		if (checkParent(map[i].first, map[i].second.first)) {
			ans += map[i].second.second;
			Union(map[i].first, map[i].second.first);
			brk++;
		}
		if (brk == V - 1) {
			break;
		}
	}
	cout << ans;

	return 0;
}