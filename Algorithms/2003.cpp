#include<iostream>
using namespace std;
int list[10000];
long long ans;
int main() {
	int start = 0;
	int end = 0;
	int N;
	
	long long O = 0;
	long long tmp = 0;
	cin >> N >> O;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		start = i;
		end = i;
		for (int j = end; j < N; j++) {
			tmp += list[j];
			if (tmp == O) {
				ans++;
				break;
			}
		}
		tmp = 0;
	}
	cout << ans;
	return 0;
}