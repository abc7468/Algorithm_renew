#include<iostream>
#include<string>
using namespace std;

int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int col, row, num; cin >> col >> row >> num;
		int floor, ho;
		string ho_ = "";
		if (num%col == 0) {
			floor = col;
		}
		else {
			floor = num % col;
		}
		if (num%col == 0) {
			ho = num / col;
		}
		else {
			ho = (num / col) + 1;
		}
		if (ho / 10 == 0) {
			ho_ = "0" + to_string(ho);
		}
		else {
			ho_ = to_string(ho);
		}
		cout << floor << ho_ <<'\n';
	}
	return 0;
}