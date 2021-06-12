#include <iostream>
#include <string>
using namespace std;

int map[9][9];
bool rowCheck[9][10];
bool colCheck[9][10];
bool isEnd;
bool square(int x, int y) {
	bool check[10];
	for (int i = 0; i < 10; i++) {
		check[i] = false;
	}


	int nx = x / 3;
	int ny = y / 3;
	for (int yy = ny; yy < yy + 3; yy++) {
		for (int xx = nx; xx < xx + 3; xx++) {
			if (map[xx][yy] != 0) {
				if (check[map[xx][yy]] == false) {
					check[map[xx][yy]] = true;
				}
				else {
					return false;
				}
			}
		}
	}
	return true;
}

void back(int num) {
	if (isEnd) {
		return;
	}
	if (num == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[j][i];
			}
			cout << '\n';
		}
		isEnd = true;
	}

	int nx = num % 9;
	int ny = num / 9;
	if (map[nx][ny] != 0) {
		back(num + 1);
	}
	else {
		for (int val = 1; val < 10; val++) {
			if (colCheck[ny][val] == false && rowCheck[nx][val] == false && square(nx, ny)) {
				map[nx][ny] = val;
				colCheck[ny][val] == true;
				rowCheck[nx][val] == true;
				back(num + 1);
				colCheck[ny][val] == false;
				rowCheck[nx][val] == false;
				map[nx][ny] = 0;

			}
		}
	}
}



int main() {
	for (int y = 0; y < 9; y++) {
		string str;
		cin >> str;
		for (int x = 0; x < 9; x++) {
			map[x][y] = str[x] - '0';
			colCheck[y][str[x] - '0'] = true;
			rowCheck[x][str[x] - '0'] = true;
		}
	}
	back(0);

}