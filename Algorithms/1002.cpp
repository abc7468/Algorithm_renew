#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x1, x2, y1, y2, r1, r2;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1\n";
			continue;
		}
		double sX, sY, sR, bX, bY, bR;
		if (r2 >= r1) {
			sX = x1, sY = y1, sR = r1;
			bX = x2, bY = y2, bR = r2;
		}
		else {
			sX = x2, sY = y2, sR = r2;
			bX = x1, bY = y1, bR = r1;
		}
		double dis = sqrt(pow(bX - sX, 2) + pow(bY - sY, 2));
		
		if (dis <= bR) {
			if (dis + sR == bR) {
				cout << "1\n";
				continue;
			}
			else if (dis + sR < bR) {
				cout << "0\n";
				continue;
			}
			else {
				cout << "2\n";
				continue;
			}
		}
		else {
			if (bR + sR < dis) {
				cout << "0\n";
				continue;
			}
			else if (bR+sR==dis) {
				cout << "1\n";
				continue;
			}
			else {
				cout << "2\n";
				continue;
			}
		}

	}


	return 0;
}