#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int>v;
int x[20];
int y[20];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--) {
		long double min = 998877665544332211;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < n / 2; i++) {
			v.push_back(0);
		}
		for (int i = 0; i < n / 2; i++) {
			v.push_back(1);
		}
		do {
			int tx = 0;
			int ty = 0;
			for (int i = 0; i < n; i++) {
				if (v[i] == 0) {
					tx += x[i];
					ty += y[i];
				}
				else {
					tx -= x[i];
					ty -= y[i];
				}
			}
			long long tmp = pow(tx,2) + pow(ty,2);
			if (min > tmp) min = tmp;


		} while (next_permutation(v.begin(), v.end()));
		cout << fixed;
		cout.precision(10);
		cout << sqrt(min) << '\n';
		v.clear();






	}


	return 0;
}