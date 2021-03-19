#include <iostream>
#include<string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	map<string, int> x;
	map<string, int> y;
	map<string, int>::iterator iter;

	for (int i = 0; i < 3; i++) {
		string tmpX, tmpY;
		tmpX = to_string(v[i][0]);
		tmpY = to_string(v[i][1]);
		if (x.find(tmpX) == x.end()) {
			x[tmpX] = 1;
		}
		else {
			x[tmpX]++;
		}
		if (y.find(tmpY) == y.end()) {
			y[tmpY] = 1;
		}
		else {
			y[tmpY]++;
		}




	}
	for (iter = x.begin(); iter != x.end(); iter++) {
		if (iter->second == 1) {
			ans.push_back(stoi(iter->first));
		}
	}
	for (iter = y.begin(); iter != y.end(); iter++) {
		if (iter->second == 1) {
			ans.push_back(stoi(iter->first));
		}
	}

	return ans;
}
int main() {
	solution({ {1, 4},{3, 4},{3, 10} });
	return 0;
}