#include "LinkedList.h"
#include <fstream>

string filename = "new";

void inputc(string s, LinkedList& L, int& i);
void takeInput(LinkedList& L, int& currLine);

void insert(string s, LinkedList& L, int& currLine) {

	if (s.size() <= 2) {
		cout << currLine << ">\t"; getline(cin, s);
		inputc(s, L, currLine);
		return;
	}

	else {
		int toInsertBefore; string toConvert = "";
		for (int j = 2; s[j] != '\0' || s[j] == ' '; j++)
			toConvert += s[j];
		toInsertBefore = stoi(toConvert);

		currLine = toInsertBefore;
		cout << currLine << ">\t"; getline(cin, s);
		inputc(s, L, currLine);
	}
}


void del(string s, LinkedList& L, int& currLine) {

	if (s == "D" || s=="d") {
		L.del(currLine);
		takeInput(L, currLine);
	}

	int startRange = -1, endRange = -1;

	string toConvert = ""; int j;

	for (j = 2; s[j]; j++) {
		if (s[j] == ' ')
			break;
		toConvert += s[j];
	}

	startRange = stoi(toConvert);

	if (s[j] == ' ') {
		toConvert = "";
		for (j + 1; s[j] != '\0'; j++)
			toConvert += s[j];
		endRange = stoi(toConvert);
	}

	L.del(currLine, startRange, endRange);
	takeInput(L, currLine);
}

void display(string s, LinkedList& L, int& currLine) {
	if (s == "L" || s == "l");
	{
		L.print();
		takeInput(L, currLine);
	}

	int startRange = -1, endRange = -1;

	string toConvert = ""; int j;

	for (j = 2; s[j]; j++) {
		if (s[j] == ' ')
			break;
		toConvert += s[j];
	}

	startRange = stoi(toConvert);

	if (s[j] == ' ') {
		toConvert = "";
		for (j + 1; s[j] != '\0'; j++)
			toConvert += s[j];
		endRange = stoi(toConvert);
	}
	L.display(currLine, startRange, endRange);
	takeInput(L, currLine);
}

void append(string s, LinkedList& L, int& currLine) {
	string st;
	cout << currLine << ">\t"; getline(cin, st);
	L.appendInNode(st, currLine);
	currLine++;
}

void inputc(string s, LinkedList& L, int& i) {

	if (s.substr(0, 2) == "I " || s == "I" || s.substr(0, 2) == "i " || s == "i")
		insert(s, L, i);

	else if (s.substr(0, 2) == "D " || s == "D" || s.substr(0, 2) == "d " || s == "d")
		del(s, L, i);

	else if (s.substr(0, 2) == "L " || s == "L" || s.substr(0, 2) == "l " || s == "l")
		display(s, L, i);

	else if (s == "A" || s == "a")
		append(s, L, i);

	else if (s == "E"|| s == "e") {
		ofstream out(filename + ".txt");
		out << L.toString();
		out.close();
		exit(0);
	}

	else
	{
		L.insert(s, i);
		i++;
	}
	takeInput(L, i);
}

void takeInput(LinkedList& L, int& currLine) {
	string s;
	cout << currLine << ">\t"; getline(cin, s);
	inputc(s, L, currLine);
}



int main() {

	string s;
	getline(cin, s);

	if (s.substr(0, 4) == "EDIT" || s.substr(0, 4) == "edit") {

		if (s.size() > 5)
			filename = s.substr(5, s.size() - 5);

		LinkedList L;

		int currLine = 1;

		while (true)
		{
			takeInput(L, currLine);
		}
	}
	return 0;
}