#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int ans;
	
	ans = min(a, min(b, c));
	ans += min(d, e);
	cout << ans - 50;
}