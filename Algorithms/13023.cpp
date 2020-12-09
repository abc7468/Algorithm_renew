#include<iostream>
#include<algorithm>
using namespace std;

int map[2000];
bool visit[2000];
int tmp = 0;
bool _end;
void check(int parent) {
	if (visit[parent] == true) return;
	if (tmp >= 4) {
		cout << "1";
		_end = true;
		return;
	}
	if (visit[map[map[parent]]] == false) {
		tmp++;
		visit[map[map[parent]]] = true;
		check(map[map[parent]]);
	}

}
int main() {
	//N : 사람 수
	//M : 관계 수
	int ans = 0;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		map[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		map[a] = b;
	}
	if (M < 4) {
		cout << "0" << '\n';
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (map[i] != i) {
			if (_end) {
				return 0;
			}
			check(map[i]);
			for (int i = 0; i < N; i++) {
				visit[i] = false;
			}
			tmp = 0;
		}
	}
	cout << "0" << '\n';
}