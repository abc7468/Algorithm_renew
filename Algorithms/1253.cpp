#include <iostream>
#include <algorithm>
using namespace std;

int map[2000];
int N;
int _count = 0;
void binarySearch() {
	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N-1;
		while (left <= right) {
			if (left == right) break;
			if (map[left] + map[right] == map[i]) {
				if (left != i && right != i) {
					_count++;
					break;
				}
				else if (left == i) left++;
				else if (right == i) right--;
			}
			if (map[left] + map[right] > map[i]) {
				right--;
			}
			else if (map[left] + map[right] < map[i]) {
				left++;
			}
		}		
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	sort(map, map + N);
	binarySearch();
	cout << _count;
	return 0;
}