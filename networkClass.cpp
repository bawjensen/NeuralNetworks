#include "networkClass.h"

void NeuralNetwork::deleteLayers() {
	cout << "Deleting " << this->nLayers << " layer(s) of " << this->nNodes << " nodes each." << endl;

	// Removing the old net
	if (this->net) { // If it's not NULL - aka it's been previously initialized
		for (int i = 0; i < this->nLayers; i++) {
			if (this->net[i]) delete[] this->net[i]; // Remove any previously allocated layers
		}

		delete[] this->net; // Remove the overall array
	}

	this->created = false;
}

void NeuralNetwork::createLayers() {
	cout << "Creating " << this->nLayers << " layer(s) of " << this->nNodes << " nodes each." << endl;

	// Creating the new net
	this->net = new float*[this->nLayers];

	for (int i = 0; i < this->nLayers; i++) {
		this->net[i] = new float[this->nNodes];
	}

	this->created = true;

	this->fillNet();
}

void NeuralNetwork::fillNet() {
	// Fills the net with 0's
	for (int i = 0; i < this->nLayers; i++) {
		for (int j = 0; j < this->nNodes; j++) {
			this->net[i][j] = 0;
		}
	}
}

NeuralNetwork::NeuralNetwork() {
	cout << "Creating new default network." << endl;
	this->nLayers = 0;
	this->nNodes = 0;
	this->net = NULL;
	this->created = false;
}

void NeuralNetwork::setNumLayers(int n) {
	// NOTE: Setting new values for either nodes or layers will delete all existing data
	if (this->created)
		this->deleteLayers(); // Delete before setting, or the dimensions will be wrong

	this->nLayers = n;

	if (this->nNodes)
		this->createLayers();
}

void NeuralNetwork::setNumNodes(int n) {
	// NOTE: Setting new values for either nodes or layers will delete all existing data
	if (this->created)
		this->deleteLayers(); // Delete before setting, or the dimensions will be wrong

	this->nNodes = n;

	if (this->nLayers)
		this->createLayers();
}

void NeuralNetwork::train(float input, float expectedOutput) {

	float* tempArray = new float[this->nLayers];

	for (int i = 0; i < this->nLayers; i++) {

	}


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

ostream& operator<<(ostream& co, const NeuralNetwork& nn) {
	if (nn.created) {
		co << setfill('-') << setw(5) << '-';
		for (int i = 0; i < nn.nLayers; i++) {
			co << "Layer " << i << " ";
		}
		co << endl;

		for (int j = 0; j < nn.nNodes; j++) {
			co << "Node " << j << ": ";
			for (int i = 0; i < nn.nLayers; i++) {
				co << nn.net[i][j] << " ";
			}
			co << endl;
		}
	}
	else {
		co << "Error: Network not yet created!";
	}

	return co;
}