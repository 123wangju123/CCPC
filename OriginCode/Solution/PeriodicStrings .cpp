#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>

using namespace std;

char str[85];
int sp, mp, ep;
int sl;

int main(void)
{
	int counter;
	int period;
	bool ff;
	scanf("%d", &counter);
	for (int i = 0; i < counter; i++) {
		scanf("%s", str);
		sl = strlen(str);
		sp  = ep = 0;
		mp = 1;//reset three pointer 
		period = 0;
		ff = false;
		for (int i = 1; i < sl; i++) {
			if (ff) {
				if (str[mp] == str[ep]) {
					mp++;
					ep++;
				}
				else {
					ff = !ff;
					ep = sp;
				}
			}
			if (str[mp] == str[sp]) {
				ff = !ff;
			}
			if (!ff) {
				mp++;
			}
			if (ep - sp == mp-1 - ep) {
				break;
			}

		}
		period = ep - sp;
		cout << period << endl << endl;
	}
	system("pause");
	return 0;
}