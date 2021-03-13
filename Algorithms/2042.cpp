#include<iostream>
using namespace std;

long long map[1000001];
long long tree[1000001];
int N;
long long pre_fix(int end) {
	long long val = 0;
	int i = end;
	while (i > 0) {
		val += tree[i];
		i -= (i&-i);
	}
	return val;
}

void update(int index, long long val) {
	int i = index;
	while (i <= N) {
		tree[i] = tree[i]+val;
		i += (i&-i);
	}
}



int main() {
	cin >> N;
	int M, K; cin >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
		update(i, map[i]);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b; cin >> a >> b;
		long long c; cin >> c;
		if (a == 1) {
			
			update(b, c - map[b]);
			map[b] = c;
		}
		else if (a == 2) {
			cout << pre_fix(c) - pre_fix(b-1) << '\n';
		}
	}

	return 0;
}