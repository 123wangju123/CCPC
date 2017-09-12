#include <iostream>
#include <cstring>
#include<cstdlib>
#include <cstdio>
using namespace std;

const double cm = 12.01;
const double hm = 1.008;
const double om = 16.00;
const double nm = 14.01;

char * molars = new char[100];
char cha;
int test, i, j, sl;
int cn = 0, on = 0, hn = 0, nn = 0;
bool isnumber(char a) {
	return (a >= '0' && a <= '9');
}
void assignn(char ch, int num) {
	if (tolower(ch) == 'c')cn += num;
	else if (tolower(ch) == 'n')nn += num;
	else if (tolower(ch) == 'o')on += num;
	else if (tolower(ch) == 'h')hn += num;
}

int main(void) 
{
	memset(molars, '\0', 100);
	scanf("%d", &test);
	for (i = 0; i < test; i++) {
		scanf("%s", molars);
		sl = strlen(molars);

		//cout << molars << endl;

		for (j = 0; j < sl; j++) {
			if (isalpha(molars[j])) {
				cha = molars[j];
				if (isalpha(molars[j + 1]) || molars[j +1] == '\0') {
					//cout << cha << endl;
					assignn(cha, 1);
				}
			}
			else if (isnumber(molars[j])) {
				if (isnumber(molars[j + 1])) {
					assignn(cha, ((molars[j] - '0') * 10) + (molars[j + 1] - '0') * 1);
					j++;
				}
				else {
					assignn(cha, ((molars[j] - '0')));
				}
			}
		}
		/*cout << " C num " << cn << " N num " << nn << " O num " << on << " H num " << hn <<endl;
		cout << " C M " << cm << " N M " << nm << " O M " << om << " H M " << hm << endl;*/
		printf("%.3f\n", (cn * cm) + (nn * nm) + (on * om) + (hm *hn));
		cn = 0; on = 0; nn = 0; hn = 0;
	}
	system("pause");
	return 0;
}