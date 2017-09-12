#include<iostream>
#include<string>
#include <cstring>
#include<cstdio>


using namespace std;
#define MAX_LEN 99999
/*
You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in
detail how the strings are generated and inserted into the original message. To validate your method,
however, it is necessary to write a program that checks if the message is really encoded in the final
string.
Given two strings s and t, you have to decide whether s is a subsequence of t, i.e. if you can remove
characters from t such that the concatenation of the remaining characters is s.

Input
The input contains several testcases. Each is specified by two strings s, t of alphanumeric ASCII
characters separated by whitespace. Input is terminated by EOF.

Output
For each test case output, if s is a subsequence of t.

Sample Input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
Sample Output
Yes
No
Yes
No
*/
int main(void)
{
	string s, t;
	s.resize(MAX_LEN);
	t.resize(MAX_LEN);
	int current = 0;
	bool isTrue = true;
	int i;
	while (cin >> s >> t)
	{
		for (i = 0; i < strlen(s.c_str()); i++) {
			if (!isalpha(s.at(i))) {
				isTrue = false;
				break;
			}
			if (t.find(s.at(i), current) != -1) {
				current = t.find(s.at(i), current) + 1;
			}
			else {
				isTrue = false;
				break;
			}
		}

		if (isTrue) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		current = 0;
		isTrue = true;
		/*while (cin >> s >> t) {
			int l1 = strlen(val);
			int l2 = strlen(str);

			if (l1 > l2) {
				cout << "No" << endl;
				continue;
			}

			int s = 0;
			for (int i = 0; i < l2; ++i)
				if (val[s] == str[i] && s++ == l1 - 1)
					break;

			if (s == l1)
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}*/
	}
	return 0;
}