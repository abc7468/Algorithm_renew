#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector <pair<int, string>> v;

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		int b;
		cin >> a;
		b = a.size();
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end(), cmp);
	
	v.erase(unique(v.begin(), v.end()), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i].second << '\n';
	}
}