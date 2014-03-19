#include <random>

#include "networkClass.h"

NeuralNetwork::NeuralNetwork() {
	cout << "Creating new default network." << endl;
	this->net = NULL;

}

void NeuralNetwork::setNumLayers(int n) {
	if (this->nNodes) {
		for (int i = 0; i > n; i++) {
			if (this->net[i]) delete[] this->net[i];
		}
	}
	if (this->net) delete[] this->net;



	this->net = new float*[n];



	if (this->nNodes) { // Already provided the number of nodes
		for (int i = 0; i < n; i++) {
			this->net[i] = new float[this->nNodes];
		}
	}
	else { // Haven't provided - Default to null
		for (int i = 0; i < n; i++) {
			this->net[i] = NULL;
		}
	}
}

void NeuralNetwork::setNumNodes(int n) {
	if ( !(this->net) ) return;

	this->nNodes = n;

	for (int i = 0; i < this->nLayers; i++) {
		if (this->net[i]) delete[] this->net[i];
		this->net[i] = new float[this->nNodes];
	}
}

// NeuralNetwork::NeuralNetwork(int numLayers, int numNodes) {
// 	cout << "Creating new parameterized network." << endl;

// 	this->hNetwork = new float*[numLayers];

// 	for (int cLayer = 0; cLayer < numLayers; cLayer++) {
// 		this->hNetwork[cLayer] = new float[numNodes];

// 		for (int cNode = 0; cNode < numNodes; cNode++) {
// 			this->hNetwork[cLayer][cNode] = 1;
// 		}
// 	}
// }

void NeuralNetwork::train(float* inputArray, int inputLength, float* outputArray, int outputLength) {
	// default_random_engine generator;
	// normal_distribution<double> distribution(5.0, 2.0);
	// float runResult;

	// for (int cEpoch = 0; cEpoch < this->epochLimit; cEpoch++) {
	// 	for (int i = 0; i < inputLength; i++) {
	// 		runResult = this->run(inputArray[i]);
	// 	}

	// 	if 
	// }
}

float NeuralNetwork::run(float input) {

	return 0.0f;
}