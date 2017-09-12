#include<iostream>
#include<cstdio>
#include <string>
#include <sstream>
#include<cstring>
#include<cstdlib>
using namespace std;

int counter[10];
int all,i,j,k;

int getInterger(char ch) 
{
	return int(ch - '0');
}
void print(int c[10]) 
{
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (i == 9)
			printf("%d",counter[i]);
		else
			printf("%d ", counter[i]);
	}
	cout << endl;
}
void reseta(int c[10]) 
{
	for (int i = 0; i < 10; i++) {
		c[i] = 0;
	}
}
int main(void) 
{
	memset(counter, 0, 10);
	stringstream ss;
	string s;
	string::iterator it;
	int tmp;
	scanf("%d", &all);
	for (i = 0; i < all; i++) {
		scanf("%d", &j);
		reseta(counter);
		//print(counter);
		for (k = 1; k <= j; k++) {
			ss << k;
			s.append(ss.str());
			ss.str("");
		}
		//cout << s.size() << endl;
		//cout << s << endl;
		for (it = s.begin(); it != s.end(); it++) {
			tmp = getInterger(*it);
			//cout << tmp << endl;
			counter[tmp] += 1;
		}
		print(counter);
		s.clear();
	}
	system("pause");
	return 0;
}