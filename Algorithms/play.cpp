#include<iostream>
using namespace std;

int map[1001];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int start = 0;
	int end = 0;
	int max = 0;
	while (1) {
		if (end == N-1) {
			if (map[end] - map[start] > max)max = map[end] - map[start];
			break;
		}
		if (map[end] < map[end + 1]) {
			end++;
		}
		else {
			if (start == end) {
				start++;
				end++;
				continue;
			}
			else {
				if (map[end] - map[start] > max)max = map[end] - map[start];
				start = end + 1;
				end = start;
			}
			
		}
	}
	cout << max;
	return 0;
}