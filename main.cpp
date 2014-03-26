#include <iostream>

#include "networkClass.h"

using namespace std;

int main() {
	NeuralNetwork nn;

	cout << "Created first" << endl;

	nn.setNumNodes(5);
	nn.setNumLayers(1);

	cout << "Established first" << endl;
	cout << "Creating second" << endl;

	NeuralNetwork nn2 = nn;

	cout << "Created second" << endl;

	cout << nn << endl;

	nn2.train(2, 4);

	cout << nn << endl;
	cout << nn2 << endl;

	// cout << nn << endl;

	// nn.train(2, 4);
	// nn.train(4, 6);
	// nn.train(6, 8);

	// cout << nn << endl;


	return 0;
}