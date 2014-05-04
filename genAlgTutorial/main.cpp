#include <iostream>
#include <sstream>
#include <random>
#include <map>

using namespace std;

int toInt(char c) {
	return c - '0';
}

float parseMath(string statement) {
	for (int i = 0; i < statement.length(); i++) {
		string newStatement = "";

		if (statement[i] == '*') {
			float value = toInt(statement[i-1]) * toInt(statement[i+1]);

			for (int j = 0; j < i-1; j++) {
				newStatement += statement[j];
			}
		}
	}

	return 0.0f;
}

bool isOperator(char test) {
	if (test == '+'
		or test == '-'
		or test == '*'
		or test == '/') return true;
	else return false;
}

bool isNumber(char test) {
	if (test == '0'
		or test == '1'
		or test == '2'
		or test == '3'
		or test == '4'
		or test == '5'
		or test == '6'
		or test == '7'
		or test == '8'
		or test == '9') return true;
	else return false;
}

string toString(int x) {
	ostringstream convert;

	convert << x;

	return convert.str();
}

int main() {
	int chromLength = 6;
	int geneLength = 4;
	string chromosome = "";

	map<string, char> decode;

	decode["0000"] = '0';
	decode["0001"] = '1';
	decode["0010"] = '2';
	decode["0011"] = '3';
	decode["0100"] = '4';
	decode["0101"] = '5';
	decode["0110"] = '6';
	decode["0111"] = '7';
	decode["1000"] = '8';
	decode["1001"] = '9';
	decode["1010"] = '+';
	decode["1011"] = '-';
	decode["1100"] = '*';
	decode["1101"] = '/';

	srand(time(NULL));

	for (int i = 0; i < chromLength*geneLength; i++) {
		chromosome += toString(rand() % 2);
	}

	string gene, mathStatement;
	char decodedGene;
	char lastOperation = '\0';
	int value, tempValue;

	bool wantNumber = true; // Start out by looking for a number
	bool wantOperator = false; // Start out by NOT looking for an operator

	for (int i = 0; i < chromLength*geneLength; i += geneLength) {
		gene = "";

		for (int j = i; j < (i+4); j++)
			gene += chromosome[j];

		decodedGene = decode[gene];

		mathStatement += decodedGene;
	}
	cout << chromosome << endl;
	cout << mathStatement << endl;

	float result = parseMath(mathStatement);
}