#include<iostream>
using namespace std;

long long map[8][100001];
//0 : �������а�
//1 : �����
//2 : �̷���
//3 : �ž��
//4 : �Ѱ�������
//5 : ������
//6 : �л�ȸ��
//7 : �������а�
int main() {
	int N; cin >> N;
	map[1][1] = 1; map[2][1] = 1;
	for (int i = 2; i <= N; i++) {
		map[0][i] = (map[1][i - 1] + map[2][i - 1]) % 1000000007;
		map[1][i] = (map[0][i - 1] + map[2][i - 1] + map[3][i - 1]) % 1000000007;
		map[2][i] = (map[0][i - 1] + map[1][i - 1] + map[3][i - 1]+map[4][i-1]) % 1000000007;
		map[3][i] = (map[1][i - 1] + map[2][i - 1] + map[4][i - 1]+map[5][i-1]) % 1000000007;
		map[4][i] = (map[2][i - 1] + map[3][i - 1] + map[5][i - 1] + map[7][i - 1]) % 1000000007;
		map[5][i] = (map[3][i - 1] + map[4][i - 1] + map[6][i - 1]) % 1000000007;
		map[6][i] = (map[5][i - 1] + map[7][i - 1]) % 1000000007;
		map[7][i] = (map[6][i - 1] + map[4][i - 1]) % 1000000007;


	}
	cout << map[0][N];
	return 0;
}