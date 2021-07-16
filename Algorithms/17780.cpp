#include<iostream>
#include<deque>
#include<vector>
#define MAX 13
using namespace std;

class Piece {
public:
	int _id;
	int _x;
	int _y;
	int _dir;
	Piece(){}
	Piece(int id, int x, int y, int dir):_id(id), _x(x), _y(y), _dir(dir) {
	}
	void setEdgePiece( int x, int y) {
		_x = x;
		_y = y;
	}
};


int N, K;
int map[MAX][MAX];
vector<Piece*> chess;
deque<Piece*> hasPiece[MAX][MAX];


pair<int,int> findNext(int nowX, int nowY, int pieceDir) {
	int nextX;
	int nextY;
	switch (pieceDir)
	{
	case 1:
		nextX = ++nowX;
		nextY = nowY;
		break;

	case 2:
		nextX = --nowX;
		nextY = nowY;

		break;

	case 3:
		nextX = nowX;
		nextY = --nowY;
		break;

	case 4:
		nextX = nowX;
		nextY = ++nowY;
		break;
	default:
		break;
	}
	return{ nextX, nextY };
}

//white의 움직임
int go(int nowX, int nowY, int dir) {
	pair<int,int> nextEdge = findNext(nowX, nowY, dir);
	while (!hasPiece[nowY][nowX].empty()) {
		Piece* tmp = hasPiece[nowY][nowX].front();
		hasPiece[nowY][nowX].pop_front();
		tmp->setEdgePiece(nextEdge.first, nextEdge.second);
		hasPiece[nextEdge.second][nextEdge.first].push_back(tmp);
	}
	return hasPiece[nextEdge.second][nextEdge.first].size();
}

//red의 움직임
int reverse(int nowX, int nowY, int dir) {
	deque<Piece*>tmp;
	while (!hasPiece[nowY][nowX].empty()) {
		tmp.push_front(hasPiece[nowY][nowX].front());
		hasPiece[nowY][nowX].pop_front();
	}
	hasPiece[nowY][nowX] = tmp;
	return go(nowX, nowY, dir);

}
//blue의 움직임
int back(int nowX, int nowY, int dir) {

	switch (dir) {
	case 1:
		dir = 2;
		break;
	case 2:
		dir = 1;
		break;
	case 3:
		dir = 4;
		break;
	case 4:
		dir = 3;
		break;
	default:
		break;
	}
	hasPiece[nowY][nowX].front()->_dir = dir;
	pair<int, int> nextEdge = findNext(nowX, nowY, dir);
	if (map[nextEdge.second][nextEdge.first] == 2 || nextEdge.first <= 0 || nextEdge.first > N || nextEdge.second <= 0 || nextEdge.second > N) {
		return hasPiece[nowX][nowY].size();
	}
	else if (map[nextEdge.second][nextEdge.first] == 1) {
		int cnt = reverse(nowX, nowY, dir);
		return cnt;
	}
	return go(nowX, nowY, dir);
}

int main() {
	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y, dir; 
		cin >> y >> x >> dir;
		Piece* tmp = new Piece(i, x, y, dir);
		hasPiece[y][x].push_back(tmp);
		chess.push_back(tmp);
		
	}
	int turn = 0; //턴 수
	int pieceCount; // map이 가진 Piece개수
	bool isEnd = false;
	while (!isEnd) {
		turn++;
		for (int i = 0; i < K; i++) {
			//움직이고자 하는 말의 정보
			int pieceX = chess[i]->_x;
			int pieceY = chess[i]->_y;
			int pieceDir = chess[i]->_dir;
			if (hasPiece[pieceY][pieceX].front()->_id != i) {
				continue;
			}
			pair<int, int> nextEdge;
			nextEdge = findNext(pieceX, pieceY, pieceDir);

			//blue map && end of map
			if (map[nextEdge.second][nextEdge.first] == 2 || nextEdge.first <= 0 || nextEdge.first > N || nextEdge.second <= 0 || nextEdge.second > N) {
				pieceCount = back(pieceX, pieceY, pieceDir);
				if (pieceCount >= 4) {
					isEnd = true;
					break;
				}
				continue;
			}

			//white map
			else if (map[nextEdge.second][nextEdge.first] == 0) {
				pieceCount = go(pieceX, pieceY, pieceDir);
				if (pieceCount >= 4) {
					isEnd = true;
					break;
				}
				continue;
			}

			//red map
			else {
				pieceCount = reverse(pieceX, pieceY, pieceDir);
				if (pieceCount >= 4) {
					isEnd = true;
					break;
				}
				continue;
			}
		}
		if (turn >= 1000) {
			cout << "-1";
			return 0;
		}
	}
	cout << turn;
	return 0;

}