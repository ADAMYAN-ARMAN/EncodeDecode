#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EncodeDecode {
	string text, key;
	char letters[5][5];

public:
	bool checkstring(string text);
	bool checktext(string text);
	bool checkkey(string key);
	void deleteletters();
	bool checklettersinarray(char c);
	bool checkkeyletters(char letters[5][5], char c);
	void addletters();
	void findindex_encode();
	void findindex_decode();
	void encode();
	void decode();
};

bool EncodeDecode::checkstring(string text) {

	for (int i = 0, k=0; i < text.size(); ++i) {
		if (text[i] != ' ')
			++k;

		if (i == text.size() - 1 && k == 0)
			return false;
	}

	for (int i = 0; i < text.size(); ++i) {
		for (char c = '0'; c <= '9'; ++c) {
			if (text[i] == c) {
				return false;
			}
		}
	}

	//In ASCII Chart 33-47 contain ! " # $ % & ' ( ) * + , - . / symbols
	for (int i = 0; i < text.size(); ++i) {
		for (char c = 33; c < 48; ++c) {
			if (text[i] == c) {
				return false;
			}
		}
	}

	//In ASCII Chart 58-64 contain : ; < = > ? @ symbols
	for (int i = 0; i < text.size(); ++i) {
		for (char c = 58; c < 65; ++c) {
			if (text[i] == c) {
				return false;
			}
		}
	}

	//In ASCII Chart 91-96 contain [ \ ] ^ _ ` symbols
	for (int i = 0; i < text.size(); ++i) {
		for (char c = 91; c < 97; ++c) {
			if (text[i] == c) {
				return false;
			}
		}
	}

	//In ASCII Chart 123-126 contain { | } ~ symbols
	for (int i = 0; i < text.size(); ++i) {
		for (char c = 123; c < 127; ++c) {
			if (text[i] == c) {
				return false;
			}
		}
	}

	return true;
}

bool EncodeDecode::checktext(string text) {
	if (!checkstring(text)) {
		system("cls");
		cout << "Your text must contain only letters" << endl;
		return false;
	}

	return true;
}

bool EncodeDecode::checkkey(string key) {
	if (!checkstring(key)) {
		system("cls");
		cout << "Your key must contain only letters" << endl;
		return false;
	}

	return true;
}

void EncodeDecode::deleteletters() {

	for (int count = 0; count < key.size(); ++count) {
		for (int i = 0; i < key.size() - 1; ++i) {
			if (key[i] == ' ') {
				key.erase(i, 1);
			}
			for (int j = i + 1; j < key.size(); ++j) {
				if (key[i] == key[j] || key[i] == key[j] - 32 || key[i] == key[j] + 32) {
					key.erase(j, 1);
				}
			}
		}
	}

	if (key[key.size() - 1] == ' ') {
		key.erase(key.size() - 1, 1);
	}

	if (key[0] == key[1]) {
		key.erase(1, 1);
	}
}

bool EncodeDecode::checklettersinarray(char c) {
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (c == ch) {
			return false;
		}
	}
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		if (c == ch) {
			return false;
		}
	}

	return true;
}

bool EncodeDecode::checkkeyletters(char letters[5][5], char c) {
	if (c == 'j') {
		return false;
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (c == letters[i][j] || c - 32 == letters[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void EncodeDecode::addletters() {
	char c = 'a';

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (checklettersinarray(letters[i][j])) {
			check:
				if (checkkeyletters(letters, c)) {
					letters[i][j] = c;
					if (c == 'z') {
						i = 5;
						j = 5;
					}
					++c;
				}
				else {
					++c;
					goto check;
				}
			}
		}
	}

}

void EncodeDecode::findindex_encode() {
	vector <int> textindex;
	vector <int> forup;
	vector <int> fordown;

	for (int count = 0; count < text.size(); ++count) {
		for (int i = 0; i < text.size(); ++i) {
			if (text[i] == ' ')
				text.erase(i, 1);
			if (text[i] == 'j')
				text[i] = 'i';
		}
	}
	cout << "text: " << text << endl;

	for (int count = 0, index=0; count < text.size(); ++count) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (text[index] == letters[i][j] || text[index] == letters[i][j] - 32 || text[index] == letters[i][j] + 32) {
					textindex.push_back(i);
					textindex.push_back(j);
					++index;
				}
			}
		}
	}

	cout << endl;

	for (int i = 0; i < textindex.size(); ++i) { 
		if (i % 2 == 0) {
			forup.push_back(textindex[i]);
		}
	}
	cout << endl;

	for (int i = 0; i < textindex.size(); ++i) {
		if (i % 2 != 0) {
			fordown.push_back(textindex[i]);
		}
	}



	if (forup.size() % 2 ==0 ) {
		for (int i = 0, k = 0; i < textindex.size(); ++i) {
			if (i == 0 || i % 2 == 0) {
				if (k % 2 == 0) {
					cout << "(" << textindex[i] << "  ";
				}
				if (k % 2 != 0) {
					cout << textindex[i] << ")  ";
				}
				++k;
			}
		}
		cout << endl;

		for (int i = 0, k = 0; i < textindex.size(); ++i) {
			if (i % 2 != 0) {
				if (k % 2 == 0) {
					cout << "(" << textindex[i] << "  ";
				}
				if (k % 2 != 0) {
					cout << textindex[i] << ")  ";
				}
				++k;
			}
		}

		cout << endl << endl;
		for (int i = 0; i < forup.size() - 1; i += 2) {
			cout << letters[forup[i]][forup[i + 1]];
		}
		for (int i = 0; i < fordown.size() - 1; i += 2) {
			cout << letters[fordown[i]][fordown[i + 1]];
		}
	}


	else {
		for (int i = 0, k = 0; i < textindex.size(); ++i) {
			if (i % 2 == 0) {
				if (k % 2 == 0) {
					cout << "(" << textindex[i] << "  ";
				}
				if (k % 2 != 0) {
					cout << textindex[i] << ")  ";
				}
				++k;
			}
		}
		cout << endl;
		cout << textindex[1] << ") ";
		for (int i = 3, k = 0; i < textindex.size(); ++i) {
			if (i % 2 != 0) {
				if (k % 2 == 0) {
					cout << "(" << textindex[i] << "  ";
				}
				if (k % 2 != 0) {
					cout << textindex[i] << ")  ";
				}
				++k;
			}
		}

		cout << endl << endl;
		for (int i = 0; i < forup.size() - 2; i += 2) {
			cout << letters[forup[i]][forup[i + 1]];
		}
		cout << letters[forup[forup.size() - 1]][fordown[0]];
		for (int i = 1; i < fordown.size() - 1; i += 2) {
			cout << letters[fordown[i]][fordown[i + 1]];
		}
	}
	
}

void EncodeDecode::findindex_decode() {
	vector <int> textindex;
	vector <int> forup;
	vector <int> fordown;

	for (int count = 0; count < text.size(); ++count) {
		for (int i = 0; i < text.size(); ++i) {
			if (text[i] == ' ')
				text.erase(i, 1);
			if (text[i] == 'j')
				text[i] = 'i';
		}
	}

	cout << "letters: " << text << endl;

	for (int count = 0, index=0; count < text.size(); ++count) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (text[index] == letters[i][j] || text[index] == letters[i][j] - 32 || text[index] == letters[i][j] + 32) {
					textindex.push_back(i);
					textindex.push_back(j);
					++index;
				}
			}
		}
	}

	cout << endl;

	for (int i = 0; i < textindex.size()/2; ++i) {
		forup.push_back(textindex[i]);
	}
	cout << endl;

	for (int i = textindex.size()/2; i < textindex.size(); ++i) {
		fordown.push_back(textindex[i]);
	}



	for (int i = 0; i < textindex.size()/2; ++i) {
		cout << "|" << textindex[i] << "|  ";
	}
	cout << endl;

	for (int i = textindex.size()/2; i < textindex.size(); ++i) {
		cout << "|" << textindex[i] << "|  ";
	}

	cout << endl << endl;
	for (int i = 0; i < forup.size(); ++i) {
		cout << letters[forup[i]][fordown[i]];
	}
}

void EncodeDecode::encode() {
	int count = 0;

	cin.ignore();

thetextagain:
	cout << endl << "Write the text: ";

	getline(cin, text);

	if (!checktext(text))
		goto thetextagain;

thekeyagain:
	cout << "Write the key: ";
	getline(cin, key);

	if (!checkkey(key))
		goto thekeyagain;


	deleteletters();

	cout << "\n\nkey: " << key;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (key[count] == 'j') {
				letters[i][j] = 'i';
				++count;
				continue;
			}
			if (count == key.size()) {
				break;
			}
			letters[i][j] = key[count];
			++count;
		}
		if (count == key.size()) {
			break;
		}
	}

	addletters();

	cout << endl << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << letters[i][j] << " ";
		}
		cout << endl;
	}

	findindex_encode();
	cout << "\n\n\n";
}

void EncodeDecode::decode() {
	int count = 0;

	cin.ignore();

thetextagain:
	cout << endl << "Write the letters: ";

	getline(cin, text);

	if (!checktext(text))
		goto thetextagain;

thekeyagain:
	cout << "Write the key: ";
	getline(cin, key);

	if (!checkkey(key))
		goto thekeyagain;


	deleteletters();

	cout << "\n\nkey: " << key;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (key[count] == 'j') {
				letters[i][j] = 'i';
				++count;
				continue;
			}
			if (count == key.size()) {
				break;
			}
			letters[i][j] = key[count];
			++count;
		}
		if (count == key.size()) {
			break;
		}
	}

	addletters();

	cout << endl << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << letters[i][j] << " ";
		}
		cout << endl;
	}

	findindex_decode();
	cout << "\n\n\n";
}

int main() {
	EncodeDecode ob;
	string a;

again:
	cout << "1.Encode" << endl;
	cout << "2.Decode" << endl;
	cout << "3.Clean" << endl;

	cin >> a;
	if (a == "1") {
		ob.encode();
	}
	else if (a == "2") {
		ob.decode();
	}
	else if (a == "3") {
		system("cls");
		goto again;
	}
	else {
		system("cls");
		cout << "There are no option for your choice" << endl;
		goto again;
	}

	goto again;
	return 0;
}
