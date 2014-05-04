#include <iostream>
#include <sstream>
#include <random>
#include <map>

using namespace std;

char toChar(int n) {
	return n + '0';
}

int toInt(char c) {
	return c - '0';
}

string toString(int x) {
	ostringstream convert;

	convert << x;

	return convert.str();
}

float parseMath(string statement) {
	cout << "Statement: " << statement << endl;

	string newStatement = "";
	for (int i = 0; i < statement.length(); i++) {
		if (statement[i] == '*' or statement[i] == '/') {
			int value;
			if (statement[i] == '*')
				value = toInt(statement[i-1]) * toInt(statement[i+1]);
			else if (statement[i] == '/')
				value = toInt(statement[i-1]) / toInt(statement[i+1]);

			cout << "Value: " << value << endl;

			for (int j = 0; j < i-1; j++) {
				newStatement += statement[j];
			}

			cout << "toChar: " << toChar(value) << endl;

			newStatement += toChar(value);

			for (int j = i+2; j < statement.length(); j++) {
				newStatement += statement[j];
			}

			cout << "After, new: " << newStatement << endl;

			statement = newStatement;
		}
	}

	statement = newStatement;

	cout << "New: " << newStatement << endl;

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

string generateChromosome(int chromLength, int geneLength) {
	srand(time(NULL));
	string chromosome = "";

	for (int i = 0; i < chromLength*geneLength; i++) {
		chromosome += toString(rand() % 2);
	}

	return chromosome;
}

string binaryDecode(string codedChromosome) {
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

	string gene;
	string decodedChromosome = "";
	char decodedGene;

	for (int i = 0; i < codedChromosome.length(); i += 4) {
		gene = "";

		for (int j = i; j < (i+4); j++)
			gene += codedChromosome[j];

		decodedGene = decode[gene];

		decodedChromosome += decodedGene;
	}

	return decodedChromosome;
}

void doGenetics() {

	string chromosome = generateChromosome(6, 4);

	string statement = binaryDecode(chromosome);

	cout << chromosome << endl;

	float result = parseMath(statement);
}

int main() {
	// doGenetics();
	//			   1   +   2   *   9   /   3
	string test = "0001101000101100100111010011";

	cout << parseMath(binaryDecode(test)) << endl;
}