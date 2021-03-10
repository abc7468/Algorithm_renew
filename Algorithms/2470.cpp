#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int ans= 9876543210;
vector<int> vPlus;
vector<int> vMinus;
bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a <= 0) {
			vMinus.push_back(a);
		}
		else {
			vPlus.push_back(a);
		}
	}
	sort(vPlus.begin(), vPlus.end());
	sort(vMinus.begin(), vMinus.end(), cmp);
	int mSize = vMinus.size();
	int pSize = vPlus.size();
	for (int i = 0; i < mSize; i++) {
		int start = 0;
		int end = pSize - 1;
		while (start > end) {
			int mid = (start + end)/2;
			int comp = vMinus[i]+vPlus[mid];
			if
		}



	}



	return 0;
}