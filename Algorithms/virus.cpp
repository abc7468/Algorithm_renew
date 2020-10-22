#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[11][10];
vector<int> answer;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int &count, int size, int **matrix) {
	visit[x][y] = true;
	count++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx>=0 && ny>=0 &&  nx < size && ny < size && matrix[nx][ny] == 1 && visit[nx][ny] == false) {
			dfs(nx, ny, count, size, matrix);
		}
	}
}

void solution(int sizeOfMatrix, int **matrix) {
	int N = sizeOfMatrix;
	int count = 0;
	int insert = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (visit[x][y] == false && matrix[x][y]==1) {
				dfs(x, y, count, N, matrix);
				answer.push_back(count);
				insert++;
				count = 0;
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << insert << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}


}

struct input_data {
	int sizeOfMatrix;
	int **matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int*[inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}