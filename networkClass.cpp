#include <random>

#include "networkClass.h"

NeuralNetwork::NeuralNetwork() {
	cout << "Creating new default network." << endl;

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
	default_random_engine generator;
	normal_distribution<double> distribution(5.0, 2.0);
	float* runResultArray;

	for (int cEpoch = 0; cEpoch < this->epochLimit; cEpoch++) {
		for (int i = 0; i < inputLength; i++) {
			runResultArray = this->run(inputArray[i]);
		}

		if 
	}
}

float NeuralNetwork::run(float input) {
	
}