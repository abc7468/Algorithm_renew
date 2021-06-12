#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<pair<int,int>, pair<int, int>>> map;

bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
	if (a.first.first == b.first.first) {
		return a.first.second > b.first.second;
	}
	return a.first.first > b.first.first;
}

bool getFirstLine(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
	return a.second.first < b.second.first;
}
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int weight, height; cin >> weight >> height;
		map.push_back({ {weight, height},{i, 0} });
	}
	sort(map.begin(), map.end(), cmp);

	map[0].second.second = 1;
	int ki = map[0].first.second;
	for (int i = 1; i < N; i++) {
		if (map[i].first.second < ki) {
			map[i].second.second = i+1;
			ki = map[i].first.second;
		}
		else {
			map[i].second.second = map[i - 1].second.second;

		}
	}

	sort(map.begin(), map.end(), getFirstLine);
	for (int i = 0; i < N; i++) {
		cout << map[i].second.second<<' ';
	}


	return 0;
}