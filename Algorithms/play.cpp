#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
//m : column
//n : row
int dx[4];
int dy[4];
bool visited[101][101];
int count_;
void dfs(vector<vector<int>> &map, int col, int row, int value, int m, int n) {
	visited[col][row] = true;
	count_++;

	int nowCol = col; int nowRow = row;
	for (int k = 0; k < 4; k++) {
		int nextCol = nowCol + dy[k];
		int nextRow = nowRow + dx[k];
		if (visited[nextCol][nextRow] == false) {
			if (nextCol >= 0 && nextCol < m && nextRow >= 0 && nextRow < n) {
				if (map[nextCol][nextRow] == value) {
					dfs(map, nextCol, nextRow, value,m,n);
				}
			}
		}
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited[i], false, n * sizeof(bool));
		}
	}
	dx[0] = -1;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = -1;
	dy[2] = 0;
	dy[3] = 1;
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && picture[i][j] != 0) {
				count_ = 0;
				number_of_area++;
				dfs(picture, i, j, picture[i][j],m,n);
				if (max_size_of_one_area < count_)max_size_of_one_area = count_;
			}
		}
	}





	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
int main() {
	vector<int>a = solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });
	cout << a[0] << ' ' << a[1];
}