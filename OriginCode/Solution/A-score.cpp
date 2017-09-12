#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int sum = 0, i, j, c, ch, sl;
int ct = 0;
char str[100];


int main(void) 
{
	scanf("%d", &c);
	for (i = 0; i < c; i++) {
		scanf("%s", str);
		sl = strlen(str);
		for (j = 0; j < sl; j++) {
			if (tolower(str[j]) == 'o') {
				ct++;
			}
			else {
				ct = 0;
			}
			sum += ct;
		}
		cout << sum << endl;
		ct = 0;
		sum = 0;
	}
	system("pause");
	return 0;
}