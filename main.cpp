#include <iostream>

#include "networkClass.h"

using namespace std;

int main() {
	NeuralNetwork nn;

	// cout << "Created first" << endl;

	nn.setNumNodes(5);
	nn.setNumLayers(1);
	nn.setEpochLimit(10);

	// cout << "Established first" << endl;
	// cout << "Creating second" << endl;

	NeuralNetwork nn2 = nn;

	// cout << "Created second" << endl;

	// cout << "First before: " << endl << nn << endl;

	nn2.train(2, 4);

	// cout << "First after: " << endl << nn << endl;
	// cout << "Second after: " << endl << nn2 << endl;

	// cout << nn << endl;

	// nn.train(2, 4);
	// nn.train(4, 6);
	// nn.train(6, 8);

	// cout << nn << endl;


	return 0;
}