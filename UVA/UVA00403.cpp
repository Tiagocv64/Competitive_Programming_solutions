#include <iostream>
#include <string>

using namespace std;

char page[60][60];
char C5[][5][7] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},//A
    {"****..", "*...*.", "****..", "*...*.", "****.."},//B
    {".****.", "*...*.", "*.....", "*.....", ".****."},//C
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},//D
    {"*****.", "*.....", "***...", "*.....", "*****."},//E
    {"*****.", "*.....", "***...", "*.....", "*....."},//F
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},//G
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},//H
    {"*****.", "..*...", "..*...", "..*...", "*****."},//I
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},//J
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},//K
    {"*.....", "*.....", "*.....", "*.....", "*****."},//L
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},//M
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},//N
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},//O
    {"****..", "*...*.", "****..", "*.....", "*....."},//P
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},//Q
    {"****..", "*...*.", "****..", "*..*..", "*...*."},//R
    {".****.", "*.....", ".***..", "....*.", "****.."},//S
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},//T
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},//U
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},//V
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},//W
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},//X
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},//Y
    {"*****.", "...*..", "..*...", ".*....", "*****."},//Z
    {"......", "......", "......", "......", "......"},//BLANK
};

void writeC1(int r, int c, string word){
	for (int i = 0; i < word.size(); i++){
		if (word.at(i) == ' ')
			continue;
		if (c+i < 0)
			continue;
		if (c+i < 60)
			page[r][c+i] = word.at(i);
	}
}

void writeC5(int r, int c, string word){
	for (int i = 0; i < word.size(); i++){
		if (word.at(i) == ' ')
			continue;
		int letra = word.at(i) - 'A';
		for (int y = 0; y < 5 && y + r < 60; y++){
			for (int x = c + i*6, pos = 0; x < 60 && pos < 6; x++, pos++){
				if (x < 0)
					continue;
				if (C5[letra][y][pos] == '.')
					continue;
				page[y+r][x] = C5[letra][y][pos];
			}
		}
	}
}

int main(){

	for (int i = 0; i < 60; i++){
		for (int j = 0; j < 60; j++){
			page[i][j] = '.';
		}
	}
	string op, font, word;
	int row, column;
	while (cin >> op){
		if (op == ".P"){
			cin >> font >> row >> column;
			getline(cin, word);
			word = word.substr(word.find_first_of('|')+1, word.find_last_of('|') - word.find_first_of('|')-1);
			if (font == "C1"){
				writeC1(row-1, column-1, word);
			} else {
				writeC5(row-1, column-1, word);
			}
		} else if (op == ".EOP"){
			for (int y = 0; y < 60; y++){
				for (int x = 0; x < 60; x++){
					cout << page[y][x];
					page[y][x] = '.';
				}
				cout << "\n";
			}
			cout << "\n------------------------------------------------------------\n\n";
		} else {
			cin >> font >> row;
			getline(cin, word);
			word = word.substr(word.find_first_of('|')+1, word.find_last_of('|') - word.find_first_of('|')-1);
			if (op == ".L"){
				if (font == "C1"){
					writeC1(row-1, 0, word);
				} else {
					writeC5(row-1,0,word);
				}
			} else if (op == ".R"){
				if (font == "C1"){
					writeC1(row-1, 60-word.size(), word);
				} else {
					writeC5(row-1, 60-(word.size()*6),word);
				}
			} else {
				if (font == "C1"){
					writeC1(row-1, 30-(word.size()/2), word);
				} else {
					writeC5(row-1, 30-(word.size()*3), word);
				}
			}
		}



	}

}