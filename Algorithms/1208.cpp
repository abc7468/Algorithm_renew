#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, int> mminus;
map<int, int> mplus;
map<int, int>::iterator miter;
map<int, int>::iterator piter;
vector<int> vminus;
vector<int> vplus;
int n, c;
int mCount, pCount;

void mDfs(int i, int sum) {
	if (mCount == i) {
		mminus[sum]++;
		return;
	}
	mDfs(i + 1, sum);
	mDfs(i + 1, sum + vminus[i]);

}
void pDfs(int i, int sum) {
	if (pCount == i) {
		mplus[sum]++;

		return;
	}
	pDfs(i + 1, sum);
	pDfs(i + 1, sum + vplus[i]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> c;
	while (n--) {
		int a; cin >> a;
		if (a < 0) vminus.push_back(a);
		else vplus.push_back(a);
	}
	mCount = vminus.size();
	pCount = vplus.size();
	mDfs(0, 0);
	pDfs(0, 0);
	int ans = 0;
	for (miter = mminus.begin(); miter != mminus.end(); miter++) {
		for (piter = mplus.begin(); piter != mplus.end(); piter++) {
			if (miter->first + piter->first == c) {
				ans = ans+(miter->second)*(piter->second);
			}
			else if (miter->first == c) {
				ans += miter->second;
			}
			else if (piter->first == c) {
				ans += piter->second;
			}
		}
	}
	cout << ans;


	return 0;
}