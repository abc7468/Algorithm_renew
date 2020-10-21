#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<long long, long long>> map;
bool check[100001];

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else return false;
}

int main() {
	int N; cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		long long a, b;
		cin >> a >> b;
		map.push_back(make_pair(a, b));
	}
	
	sort(map.begin(), map.end(), cmp);
	long long min = 0;
	for (int i = 0; i < N; i++) {
		if (min <= map[i].first) {
			cnt++;
			min = map[i].second;
		}
	}
	

	cout << cnt;
	return 0;
}