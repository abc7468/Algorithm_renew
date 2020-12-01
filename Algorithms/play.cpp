#include<iostream>
using namespace std;

float list[1001];
float ans[1001];
int main() {
	int N; cin >> N;
	
	float big = 0;
	float tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		
		if (big < list[i]) big = list[i];
	}
	for (int i = 0; i < N; i++) {
		ans[i] = list[i] / big;
		tmp += ans[i];
	}
	cout << fixed;
	cout.precision(6);
	cout << (double)(tmp / N * 100);
}