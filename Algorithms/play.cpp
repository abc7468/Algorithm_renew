#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int a[5];
	int tmp = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		tmp += pow(a[i],2);
	}
	cout << tmp % 10;


	return 0;
}