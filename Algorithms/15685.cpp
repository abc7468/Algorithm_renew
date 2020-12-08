#include<iostream>
#include<vector>

using namespace std;


//커브 만들기, 그리는거, 체크하는거
bool map[101][101];
vector<pair<int, int>> curve;
vector<pair<int, int>> vTmp;
int ans = 0;

void change(int x, int y, int dotX, int dotY) { // dot이 기준
	int nowX = x - dotX;
	int nowY = y - dotY; //원점 이동
	int tmp;
	if (nowX == 0) {
		nowX = -nowY;
		nowY = 0;
	}
	else if (nowY == 0) {
		nowY = nowX;
		nowX = 0;
	}
	else {
		tmp = nowX;
		nowX = -nowY;
		nowY = tmp;
		
	}
	nowX += dotX;
	nowY += dotY;
	vTmp.push_back(make_pair(nowX, nowY));
}

void makeCurve(int gen) {

	
	for (int g = 0; g < gen; g++) {
		int size = curve.size();
		for (int i = size - 2; i >= 0; i--) {
			change(curve[i].first, curve[i].second, curve[size - 1].first, curve[size - 1].second);
			int tmpSize = vTmp.size();
			for (int i = 0; i < tmpSize; i++) {
				curve.push_back(make_pair(vTmp[i].first, vTmp[i].second));
			}
			while (!vTmp.empty()) {
				vTmp.pop_back();
			}
		}
	}

}

void check() {
	int size = curve.size();
	for (int i = 0; i < size; i++) {
		map[curve[i].first][curve[i].second] = true;
	}

}




int main() {
	int N; cin >> N;
	for (int n = 0; n < N; n++) {
		int x, y, d, g; cin >> x >> y >> d >> g;
		if (d == 0) {
			curve.push_back(make_pair(x, y));
			curve.push_back(make_pair(x + 1, y));
		}
		else if (d == 1) {
			curve.push_back(make_pair(x, y));
			curve.push_back(make_pair(x, y - 1));
		}
		else if (d == 2) {
			curve.push_back(make_pair(x, y));
			curve.push_back(make_pair(x-1, y));
		}
		else if (d == 3) {
			curve.push_back(make_pair(x, y));
			curve.push_back(make_pair(x, y+1));
		}
		makeCurve(g);
		check();

		while (!curve.empty()) {
			curve.pop_back();
		}
	}
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[x][y]) {
				if (map[x + 1][y]) {
					if (map[x][y + 1]) {
						if (map[x + 1][y + 1]) {
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans;
}