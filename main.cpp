#include <iostream>
#include <string>
#include <stack>

using namespace std;

//checking brackets
bool check(string s) {
	int x = 0, y = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '(' and s[i] != ')') {
			s.erase(i, 1);
			i--;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			x++;
		else
			y++;
	}

	if (x != y)
		return false;
	else
		return true;
}

//adds to end of the line for prefix form 
string add_to_end(string res, char x) {
	reverse(res.begin(), res.end());;
	res += x;
	reverse(res.begin(), res.end());;
	return res;
}

//defines priority of symbol
int priority(char x) {
	int pr;
	if (x == '+' or x == '-')
		pr = 1;
	else
		if (x == '*' or x == '/')
			pr = 2;
		else
			pr = 0;
	return pr;
}

//from infix to prefix form
string Pref(string s, stack<char> st) {
	reverse(s.begin(), s.end());
	string res;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*') {
			if (st.empty()) {
				st.emplace(s[i]);
			}
			else {
				if (priority(s[i]) < priority(st.top())) {
					for (int o = 0; o <= st.size(); o++) {
						if (st.top() == ')') {
							st.pop();
							break;
						}
						res = add_to_end(res, st.top());
						st.pop();
					}
					st.emplace(s[i]);
				}
				else {
					if (priority(s[i]) == priority(st.top())) {
						if (st.top() == ')') {
							st.pop();
						}
						else {
							res = add_to_end(res, st.top());
							st.pop();
						}
						st.emplace(s[i]);
					}
					else {
						st.emplace(s[i]);
					}
				}
			}
		}
		else {
			if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z' or s[i] >= '0' and s[i] <= '9') {
				res = add_to_end(res, s[i]);
			}
			else {
				if (s[i] == '(' or s[i] == ')') {
					if (s[i] == ')') {
						st.emplace(s[i]);
					}
					else {
						if (s[i] == '(' and !st.empty()) {
							for (int y = 0; y <= st.size(); y++) {
								if (st.top() == ')') {
									st.pop();
									break;
								}
								res = add_to_end(res, st.top());
								st.pop();
							}
						}
					}
				}
			}
		}
	}

	if (!st.empty()) {
		for (int i = 0; i <= st.size(); i++) {
			res = add_to_end(res, st.top());
			st.pop();
		}
	}

	return res;
}

//from infix to postfix form
string Post(string s, stack<char> st) {
	string res;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*') {
			if (st.empty()) {
				st.emplace(s[i]);
			}
			else {
				if (priority(s[i]) < priority(st.top())) {
					for (int o = 0; o <= st.size(); o++) {
						if (st.top() == '(') {
							st.pop();
							break;
						}
						res += st.top();
						st.pop();
					}
					st.emplace(s[i]);
				}
				else {
					if (priority(s[i]) == priority(st.top())) {
						if (st.top() == '(') {
							st.pop();
						}
						else {
							res += st.top();
							st.pop();
						}
						st.emplace(s[i]);
					}
					else {
						st.emplace(s[i]);
					}
				}
			}
		}
		else {
			if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z' or s[i] >= '0' and s[i] <= '9') {
				res += s[i];
			}
			else {
				if (s[i] == '(' or s[i] == ')') {
					if (s[i] == '(') {
						st.emplace(s[i]);
					}
					else {
						if (s[i] == ')' and !st.empty()) {
							for (int y = 0; y <= st.size(); y++) {
								if (st.top() == '(') {
									st.pop();
									break;
								}
								res += st.top();
								st.pop();
							}
						}
					}
				}
			}
		}
	}

	if (!st.empty()) {
		for (int i = 0; i <= st.size(); i++) {
			res += st.top();
			st.pop();
		}
	}

	return res;
}

int main() {
	setlocale(LC_ALL, "ru");
	string s;
	stack<char> st;
	int c;

	cout << endl << "Menu:\n 1 - To prefix\n 2 - To postfix\nEnter number - ";
	cin >> c;
	cout << endl << "Enter infix line - ";
	cin >> s;
	if (check(s)) {
		switch (c)
		{
		case 1:
			cout << endl << "Resalt - " << Pref(s, st);
			break;
		case 2:
			cout << endl << "Resalt - " << Post(s, st);
			break;
		default:
			break;
		}
	}
	else {
		cout << "Please chek brackets" << endl;
	}
}#include <iostream>
#include <string>
#include <stack>

using namespace std;

//checking brackets
bool check(string s) {
	int x = 0, y = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '(' and s[i] != ')') {
			s.erase(i, 1);
			i--;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			x++;
		else
			y++;
	}

	if (x != y)
		return false;
	else
		return true;
}

//adds to end of the line for prefix form 
string add_to_end(string res, char x) {
	reverse(res.begin(), res.end());;
	res += x;
	reverse(res.begin(), res.end());;
	return res;
}

//defines priority of symbol
int priority(char x) {
	int pr;
	if (x == '+' or x == '-')
		pr = 1;
	else
		if (x == '*' or x == '/')
			pr = 2;
		else
			pr = 0;
	return pr;
}

//from infix to prefix form
string Pref(string s, stack<char> st) {
	reverse(s.begin(), s.end());
	string res;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*') {
			if (st.empty()) {
				st.emplace(s[i]);
			}
			else {
				if (priority(s[i]) < priority(st.top())) {
					for (int o = 0; o <= st.size(); o++) {
						if (st.top() == ')') {
							st.pop();
							break;
						}
						res = add_to_end(res, st.top());
						st.pop();
					}
					st.emplace(s[i]);
				}
				else {
					if (priority(s[i]) == priority(st.top())) {
						for (int o = 0; o <= st.size(); o++) {
							if (st.top() == ')') {
								st.pop();

							}
							else {
								res = add_to_end(res, st.top());
								st.pop();
							}
						}
						st.emplace(s[i]);
					}
					else {
						st.emplace(s[i]);
					}
				}
			}
		}
		else {
			if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z' or s[i] >= '0' and s[i] <= '9') {
				res = add_to_end(res, s[i]);
			}
			else {
				if (s[i] == '(' or s[i] == ')') {
					if (s[i] == ')') {
						st.emplace(s[i]);
					}
					else {
						if (s[i] == '(' and !st.empty()) {
							for (int y = 0; y <= st.size(); y++) {
								if (st.top() == ')') {
									st.pop();
									break;
								}
								res = add_to_end(res, st.top());
								st.pop();
							}
						}
					}
				}
			}
		}
	}

	if (!st.empty()) {
		for (int i = 0; i <= st.size(); i++) {
			res = add_to_end(res, st.top());
			st.pop();
		}
	}

	return res;
}

//from infix to postfix form
string Post(string s, stack<char> st) {
	string res;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*') {
			if (st.empty()) {
				st.emplace(s[i]);
			}
			else {
				if (priority(s[i]) < priority(st.top())) {
					for (int o = 0; o <= st.size(); o++) {
						if (st.top() == '(') {
							st.pop();
							break;
						}
						res += st.top();
						st.pop();
					}
					st.emplace(s[i]);
				}
				else {
					if (priority(s[i]) == priority(st.top())) {
						if (st.top() == '(') {
							st.pop();
						}
						else {
							res += st.top();
							st.pop();
						}
						st.emplace(s[i]);
					}
					else {
						st.emplace(s[i]);
					}
				}
			}
		}
		else {
			if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z' or s[i] >= '0' and s[i] <= '9') {
				res += s[i];
			}
			else {
				if (s[i] == '(' or s[i] == ')') {
					if (s[i] == '(') {
						st.emplace(s[i]);
					}
					else {
						if (s[i] == ')' and !st.empty()) {
							for (int y = 0; y <= st.size(); y++) {
								if (st.top() == '(') {
									st.pop();
									break;
								}
								res += st.top();
								st.pop();
							}
						}
					}
				}
			}
		}
	}

	if (!st.empty()) {
		for (int i = 0; i <= st.size(); i++) {
			res += st.top();
			st.pop();
		}
	}

	return res;
}

int main() {
	setlocale(LC_ALL, "ru");
	string s;
	stack<char> st;
	int c;

	cout << endl << "Menu:\n 1 - To prefix\n 2 - To postfix\nEnter number - ";
	cin >> c;
	cout << endl << "Enter infix line - ";
	cin >> s;
	if (check(s)) {
		switch (c)
		{
		case 1:
			cout << endl << "Resalt - " << Pref(s, st);
			break;
		case 2:
			cout << endl << "Resalt - " << Post(s, st);
			break;
		default:
			break;
		}
	}
	else {
		cout << "Please chek brackets" << endl;
	}
}
