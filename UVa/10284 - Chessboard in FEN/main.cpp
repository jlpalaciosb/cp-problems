#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

char board[8][8];
bool attacked[8][8];

void init(string fen);

template <typename T>
void print_matrix(T matrix[8][8]);
void expand_pawn(int r, int c, char color);
void expand_knight(int r, int c);
void expand_bishop(int r, int c);
void expand_rook(int r, int c);
void expand_king(int r, int c);
bool occupied(int r, int c);
int count_unnattacked();
void attack_if_possible(int r, int c);

int main() {
	string fen;

	while(getline(cin, fen)) {
		init(fen);
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				switch(board[i][j]) {
					case 'P':
						expand_pawn(i, j, 'w');
						break;
					case 'p':
						expand_pawn(i, j, 'b');
						break;
					case 'N':
						expand_knight(i, j);
						break;
					case 'B':
						expand_bishop(i, j);
						break;
					case 'R':
						expand_rook(i, j);
						break;
					case 'Q':
						expand_bishop(i, j);
						expand_rook(i, j);
						break;
					case 'K':
						expand_king(i, j);
						break;
					default:
						break;
				}
			}
		}
		//print_matrix(board);
		//print_matrix(attacked);
		cout << count_unnattacked() << endl;
	}

	return 0;
}

void init(string fen) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = '_';
			attacked[i][j] = false;
		}
	}

	replace(fen.begin(), fen.end(), '/', ' ');
	stringstream s(fen);

	for(int i = 0; i < 8; ++i) {
		string row;
		s >> row;
		int sq = 0;
		for(int j = 0; j < row.length(); j++) {
			if(isdigit(row[j])) {
				int skip = row[j] - '0';
				sq += skip;
			} else {
				board[i][sq] = (row[j] == 'p' || row[j] == 'P') ? row[j] : toupper(row[j]);
				attacked[i][sq] = true;
				sq += 1;
			}
		}
	}
}

template <typename T>
void print_matrix(T matrix[8][8]) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void expand_pawn(int r, int c, char color) {
	int s = 1;
	if(color == 'w') {
		s = -1;
	}
	attack_if_possible(r + s, c - 1);
	attack_if_possible(r + s, c + 1);
}

void expand_knight(int r, int c) {
	attack_if_possible(r - 2, c - 1);
	attack_if_possible(r - 2, c + 1);
	attack_if_possible(r - 1, c - 2);
	attack_if_possible(r - 1, c + 2);
	attack_if_possible(r + 1, c - 2);
	attack_if_possible(r + 1, c + 2);
	attack_if_possible(r + 2, c - 1);
	attack_if_possible(r + 2, c + 1);
}

void expand_bishop(int r, int c) {
	for (int i = 1; i <= min(r, c) && !occupied(r - i, c - i); ++i)
		attacked[r - i][c - i] = true;
	for (int i = 1; i <= min(r, 7 - c) && !occupied(r - i, c + i); ++i)
		attacked[r - i][c + i] = true;
	for (int i = 1; i <= min(7 - r, c) && !occupied(r + i, c - i); ++i)
		attacked[r + i][c - i] = true;
	for (int i = 1; i <= min(7 - r, 7 - c) && !occupied(r + i, c + i); ++i)
		attacked[r + i][c + i] = true;
}

void expand_rook(int r, int c) {
	for (int i = r + 1; i < 8 && !occupied(i, c); ++i)
		attacked[i][c] = true;
	for (int i = r - 1; i > -1 && !occupied(i, c); --i)
		attacked[i][c] = true;
	for (int i = c + 1; i < 8 && !occupied(r, i); ++i)
		attacked[r][i] = true;
	for (int i = c - 1; i > -1 && !occupied(r, i); --i)
		attacked[r][i] = true;
}

void expand_king(int r, int c) {
	attack_if_possible(r - 1, c - 1);
	attack_if_possible(r - 1, c);
	attack_if_possible(r - 1, c + 1);
	attack_if_possible(r, c - 1);
	attack_if_possible(r, c + 1);
	attack_if_possible(r + 1, c - 1);
	attack_if_possible(r + 1, c);
	attack_if_possible(r + 1, c + 1);
}

int count_unnattacked() {
	int c = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if(!attacked[i][j]) {
				c++;
			}
		}
	}
	return c;
}

bool occupied(int r, int c) {
	return board[r][c] != '_';
}

void attack_if_possible(int r, int c) {
	if(r < 8 && r >= 0 && c < 8 && c >= 0) {
		attacked[r][c] = true;
	}
}
