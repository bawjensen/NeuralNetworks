#include <random>

#include "networkClass.h"

void NeuralNetwork::createLayers() {
	cout << "Creating " << this->nLayers << " layer(s) of " << this->nNodes << " nodes each." << endl;

	// Removing the old net
	if (this->net) { // If it's not NULL - aka it's been previously initialized
		for (int i = 0; i < this->nLayers; i++) {
			if (this->net[i]) delete[] this->net[i]; // Remove any previously allocated layers
		}

		delete[] this->net; // Remove the overall array
	}


	// Creating the new net
	this->net = new float*[this->nLayers];

	for (int i = 0; i < this->nLayers; i++) {
		this->net[i] = new float[this->nNodes];
	}
}

NeuralNetwork::NeuralNetwork() {
	cout << "Creating new default network." << endl;
	this->net = NULL;
}

void NeuralNetwork::setNumLayers(int n) {
	// NOTE: Setting new values for either nodes or layers will delete all existing data
	this->nLayers = n;

	if (this->nNodes)
		this->createLayers();
}

void NeuralNetwork::setNumNodes(int n) {
	// NOTE: Setting new values for either nodes or layers will delete all existing data
	this->nNodes = n;

	if (this->nLayers)
		this->createLayers();
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