#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int board[9][9];
vector<pair<int,int>> emptyBoard;

bool check(int x, int y, int val) {
	// 3*3 체크
	if( x>=0 && x<3 && y>=0 && y<3 ) {
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}
	}else if(x >= 0 && x<3 && y>=3 && y<6) {
		for(int i=0; i<3; i++){
			for(int j=3; j<6; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 0 && x<3 && y>=6 && y<9) {
		for(int i=0; i<3; i++){
			for(int j=6; j<9; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}
	}else if(x >= 3 && x<6 && y>=0 && y<3) {
		for(int i=3; i<6; i++){
			for(int j=0; j<3; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 3 && x<6 && y>=3 && y<6) {
		for(int i=3; i<6; i++){
			for(int j=3; j<6; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 3 && x<6 && y>=6 && y<9) {
		for(int i=3; i<6; i++){
			for(int j=6; j<9; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 6 && x<9 && y>=0 && y<3) {
		for(int i=6; i<9; i++){
			for(int j=0; j<3; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 6 && x<9 && y>=3 && y<6) {
		for(int i=6; i<9; i++){
			for(int j=3; j<6; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}else if(x >= 6 && x<9 && y>=6 && y<9) {
		for(int i=6; i<9; i++){
			for(int j=6; j<9; j++){
				if(i == x && j == y) continue;
				if(board[i][j] == val) return false;
			}
		}	
	}
	// 가로 체크
	for(int i=0; i<9; i++){
		if(i == y) continue;
		if(board[x][i] == val){
			return false;
		}
	}
	// 세로 체크
	for(int i=0; i<9; i++){
		if(i == x) continue;
		if(board[i][y] == val){
			return false; 
		}
	}
	return true;
}

void backTracking(int idx) {
	pair<int,int> tmp = emptyBoard[idx];
	if(idx == emptyBoard.size()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout<<board[i][j]<<" ";
			}
			cout<<"\n";
		}
		exit(0);
	}
	for(int j=1; j<=9; j++){
		if(check(tmp.first, tmp.second, j)){
			board[tmp.first][tmp.second] = j;
			backTracking(idx+1);
			board[tmp.first][tmp.second] = 0;
		}
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cin >>  board[i][j];
			if(board[i][j] == 0){
				emptyBoard.push_back({i,j});
			}
		}
	}
	
	backTracking(0);
	
	return 0;
}