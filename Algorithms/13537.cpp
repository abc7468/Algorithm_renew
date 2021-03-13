#include<iostream>
using namespace std;

long long map[1000001];
long long tree[1000001];
int N;

long long sum(int node) {
	long long tmp = 0;
	while (node > 0) {
		tmp += tree[node];
		node -= (node&-node);
	}
	return tmp;
}

void update(int index, long long val) {
	while (index <= N) {
		tree[index] += val;
		index += (index&-index);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 0) {
			int start, end;
			cin >> start >> end;
			if (start > end) swap(start, end);
			cout << sum(end) - sum(start - 1) << '\n';
		}
		else if (a == 1) {
			int index, val;
			cin >> index >> val;
			update(index, val-map[index]);
			map[index] = val;
		}
	}
	return 0;
}