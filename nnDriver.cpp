#include <iostream>

#include "networkClass.h"

using namespace std;

int main() {
	NeuralNetwork nn;

	nn.setNumNodes(5);
	nn.setNumLayers(1);

	cout << nn << endl;

	nn.train(2, 4);
	nn.train(4, 6);
	nn.train(6, 8);

	cout << nn << endl;


	return 0;
}