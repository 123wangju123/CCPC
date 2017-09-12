#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
#define __DEBUG__
#define ALL 25

bool _A(char  squre[5][5], int& x, int& y)
{
	if (x - 1 == -1)
		return false;
	char tmp = squre[x - 1][y];
	squre[x - 1][y] = squre[x][y];
	squre[x --][y] = tmp;
}
bool _B(char  squre[5][5], int& x, int& y)
{
	if (x + 1 == 5)
		return false;
	char tmp = squre[x + 1][y];
	squre[x + 1][y] = squre[x][y];
	squre[x ++][y] = tmp;
}
bool _R(char  squre[5][5], int& x, int& y)
{
	if (y + 1 == 5)
		return false;
	char tmp = squre[x][y + 1];
	squre[x][y + 1] = squre[x][y];
	squre[x][y ++] = tmp;
}
bool _L(char  squre[5][5], int& x, int& y)
{
	if (y - 1 == -1)
		return false;
	char tmp = squre[x][y - 1];
	squre[x][y - 1] = squre[x][y];
	squre[x][y -- ] = tmp;
}
void print(const char squre[5][5]) 
{
	int i,j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (j == 4) {
				cout << squre[i][j] << endl;
			}
			else {
				cout << squre[i][j] << ' ';
			}
		}
	}
}

int main(void) 
{
	int ch,count = 1,x = 0,y = 0,c = 0,i,j;
	bool isTrue = true;
	char squre[5][5];
	char cmd[1005];

	for (;;) {
		
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5; ++j) {
				ch = getchar();
				if ((char)ch == 'Z')
					return 0;
				if ((char)ch == '\n') {
					j--;
				}
				else {
					if ((char)ch == ' ') {
						x = i;
						y = j;
					}
					squre[i][j] = (char)ch;
				}
			}
		}
		for (;;) {
			ch = getchar();
			if ((char)ch == '0') {
				cmd[c] = '\0';
				break;
			}	
			if (!((char)ch == '\n'))
				cmd[c++] = (char)ch;
			
		}
		cout << "Puzzle #" << count << ":" << endl;
		for (j = 0; j < strlen(cmd); j++) {
			switch (cmd[j]) {
			case 'A':
				if (!_A(squre, x, y))
					isTrue = false;
			/*	print(squre);
				cout << endl;*/
				break;
			case 'B':
				if (!_B(squre, x, y))
					isTrue = false;
				break;
			case 'L':
				if (!_L(squre, x, y))
					isTrue = false;
				break;
			case 'R':
				if (!_R(squre, x, y))
					isTrue = false;
				break;
			default:
				isTrue = false;
				break;

			}
			if (!isTrue)
				break;
		}
		if (isTrue) {
			print(squre);
			cout << endl;
		}else
			cout << "This puzzle has no final configuration." << endl << endl;
		/*for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5;++j) {
				cout << squre[i][j];
			}
			cout << endl;
		}*/
		c = 0;
		count++;
		//printf("%s - %d\n", cmd,strlen(cmd));
	}
	//system("pause");
#ifdef __DEBUG__
	
#endif
	return 0;
}