#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string text_before_space(string text) {
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			result += text[i];
		}
		else {
			i = text.length();
		}
	}
	return result;
}

string change_letters_before_first_space(string filename) {
	ifstream file(filename);
	string temp, text_in_file = "";
	int iter = 0;
	while (getline(file, temp)) {
		text_in_file += temp;
		iter++;
	}
	string text_before_first_space = text_before_space(text_in_file);

	for (int i = 0; i < text_before_first_space.length(); i++) {
		if (isalpha(text_before_first_space[i])) {
			text_in_file[i] = toupper(text_before_first_space[i]);
		}
	}
	return text_in_file;
}

void print_to_file(string filename, string text) {
	ofstream fout(filename);
	for (int i = 0; i < text.length(); i++) {
		fout << text[i];
	}
}

int main() {
	string file = "data1.txt";
	string file2 = "data2.1.txt";
	print_to_file(file2, change_letters_before_first_space(file));
}