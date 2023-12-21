#include <bits/stdc++.h>
using namespace std;

stack<int> st;

inline int getCode(string s) {
	if (s == "h1") return 1;
	if (s == "/h1") return -1;
	if (s == "h2") return 2;
	if (s == "/h2") return -2;
	if (s == "i") return 3;
	if (s == "/i") return -3;
	if (s == "b") return 4;
	if (s == "/b") return -4;
	if (s == "url") return 5;
	if (s == "/url") return -5;
	if (s == "img") return 6;
	if (s == "/img") return -6;
	if (s == "quote") return 7;
	if (s == "/quote") return -7;
	throw(-1);
	return 0;
}

void push(string tag) {
	int x = getCode(tag);
	if (x > 0) {
		st.push(x);
		return ;
	}
	if (st.empty()) {
		cout << "Match Error";
		exit(0);
	}
	if (st.top()+x) {
		cout << "Match Error";
		exit(0);
	} else {
		st.pop();
	}
}

int main() {
	string s, res;
	string tag, url, describe, nowLine;
	int nowRead = 0;
	bool added;
	while (getline(cin, s)) {
		nowLine = "";
		added = 1;
		for (string::iterator it = s.begin(); it != s.end(); it++) {
			if (*it == '[') {  // 识别标签
				tag = "";
				it++;
				while (*it != ']' && *it != '=' && it != s.end()) tag += (*it), it++;
				if (nowRead == 7 && tag != "/quote") {
					nowLine += "["+tag+"]";
					continue;
				}
				push(tag);
				nowRead = getCode(tag);
				if (nowRead < 0) nowRead = 0;
				if (*it == '=') {  // 读取img和url的地址
					describe = "";
					url = "";
					it++;
					while (*it != ']' && it != s.end()) {
						url += *it;
						it++;
					}
				}
				if (tag == "/img") {
					nowLine += "!["+describe+"]("+url+")";
					nowRead = 0;
				} else if (tag == "/url") {
					nowLine += "["+describe+"]("+url+")";
					nowRead = 0;
				} else if (tag == "h1") {
					nowLine += "# ";
					nowRead = 1;
				} else if (tag == "/h1") {
					nowLine += " #";
					nowRead = 0;
				} else if (tag == "h2") {
					nowLine += "## ";
					nowRead = 2;
				} else if (tag == "/h2") {
					nowLine += " ##";
					nowRead = 0;
				} else if (tag == "i" || tag == "/i") {
					nowLine += "*";
					if (tag == "i") nowRead = 3;
					else nowRead = 0;
				} else if (tag == "b" || tag == "/b") {
					nowLine += "__";
					if (tag == "b") nowRead = 4;
					else nowRead = 0;
				} else if (tag == "url") {
					nowRead = 5;
				} else if (tag == "img") {
					nowRead = 6;
				} else if (tag == "quote") {
					nowRead = 7;
					if (it+1 == s.end()) {
						added = 0;
					}
					if (it-6 != s.begin() && it+1 != s.end()) {
						nowLine += "\n> ";
					}
				} else if (tag == "/quote") {
					if (it-6 != s.begin() && it+1 != s.end()) {
						nowLine += "\n";
					}
					nowRead = 0;
				}
				continue;
			}
			if (nowRead == 0 || nowRead == 1 || nowRead == 2 || nowRead == 3 || nowRead == 4) nowLine += *it;
			else if (nowRead == 5 || nowRead == 6) describe += *it;
			else if (nowRead == 7) nowLine += *it;
		}
		if (nowLine.empty()) continue;
		if (nowRead == 7 && added) res += "> "+nowLine+"\n";
		else res += nowLine+"\n";
	}
	if (!st.empty()) {
		cout << "Unclosed Mark";
		exit(0);
	}
	cout << res;
}

/*
[h1]Introducing Swift.[/h1][quote]
import SpriteKit
let object = SKSpriteNode(imageNamed: "[L2/Ascention]"
[/quote]
*/