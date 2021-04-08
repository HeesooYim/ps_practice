#include <string>

using namespace std;

void level1(string &new_id) {
	for (char &c : new_id) {
		if ('A' <= c && c <= 'Z') {
			c = c - 'A' + 'a';
		}
	}
}

void level2(string &new_id) {
	for (int i = 0; i < new_id.length(); i++) {
		if ('0' <= new_id[i] && new_id[i] <= '9') continue;
		if ('A' <= new_id[i] && new_id[i] <= 'Z') continue;
		if ('a' <= new_id[i] && new_id[i] <= 'z') continue;
		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
		new_id.erase(new_id.begin() + i);
		i--;
	}
}

void level3(string &new_id) {
	for (int i = 0; i < new_id.length() - 1; i++) {
		if (new_id[i] == '.' && new_id[i + 1] == '.') {
			new_id.erase(new_id.begin() + i + 1);
			i--;
		}
	}
}

void level4(string &new_id) {
	if (!new_id.empty() && new_id.front() == '.') {
		new_id.erase(new_id.begin());
	}
	if (!new_id.empty() && new_id.back() == '.') {
		new_id.erase(new_id.end() - 1);
	}
}

void level5(string &new_id) {
	if (new_id.empty()) {
		new_id.append("a");
	}
}

void level6(string &new_id) {
	if (new_id.length() >= 16) {
		new_id.erase(new_id.begin() + 15, new_id.end());
	}
	if (!new_id.empty() && new_id.back() == '.') {
		new_id.erase(new_id.end() - 1);
	}
}

void level7(string &new_id) {
	while (new_id.length() <= 2) {
		new_id.push_back(new_id.back());
	}
}

string solution(string new_id) {
	level1(new_id);
	level2(new_id);
	level3(new_id);
	level4(new_id);
	level5(new_id);
	level6(new_id);
	level7(new_id);
	
	return new_id;
}
