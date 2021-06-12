#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[201];
vector<int> v;

int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(x);
}

void Union(int x, int y) {
	int xp = GetParent(x);
	int yp = GetParent(y);
	if (min(xp, yp) == xp) parent[yp] = xp;
	else parent[xp] = yp;
}

bool check(int x, int y) {
	int xp = GetParent(x);
	int yp = GetParent(y);
	if (xp == yp)return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;  cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (a == 1) {
				if (!check(i, j)) {
					Union(i, j);
				}

			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int tmpParent = GetParent(v[0]);

	for (int i = 1; i < m; i++) {
		if (tmpParent != GetParent(v[i])) {
			cout<<"NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}