#include "networkClass.h"

Node() {
	this->val = 0.0f;
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork& other) {
	// cout << "Routed via the copy constructor" << endl;
	this->init();
	(*this) = other;
}

NeuralNetwork::NeuralNetwork() {
	// cout << "Creating new default network." << endl;
	this->init();
}

void NeuralNetwork::init() {
	// cout << "Initializing network" << endl;
	this->nLayers = 0;
	this->nNodes = 0;
	this->net = NULL;
	this->created = false;
	this->generator.seed(time(NULL));
	// srand(time(NULL));
}

void NeuralNetwork::deleteLayers() {
	// cout << "Deleting " << this->nLayers << " layer(s) of " << this->nNodes << " nodes each." << endl;

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
	// cout << "Creating " << this->nLayers << " layer(s) of " << this->nNodes << " nodes each." << endl;

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

void NeuralNetwork::setEpochLimit(int n) {
	this->epochLimit = n;
}

void NeuralNetwork::mutate() {
	// cout << "Mutation on: " << endl;
	// cout << (*this) << endl;

	// default_random_engine generator;
	normal_distribution<double> distribution(0.0, 0.1);

	for (int i = 0; i < this->nLayers; i++) {
		for (int j = 0; j < this->nNodes; j++) {
			float mutateValue = distribution(this->generator);
			// cout << "Next: " << mutateValue << endl;
			this->net[i][j] += mutateValue;
		}
	}
	// cout << "Final:" << endl;
	// cout << (*this) << endl;
}

void NeuralNetwork::train(float input, float expectedOutput) {
	NeuralNetwork tempNN = (*this);
	// cout << "Before: " << endl;
	// cout << (*this) << endl;

	// cout << "Limit: " << this->epochLimit << endl;

	float oldResult, newResult;

	for (int i = 0; i < this->epochLimit; i++) {
		// cout << "Epoch number: " << i << endl;

		tempNN.mutate();

		oldResult = this->run(input);
		newResult = tempNN.run(input);
		// cout << "New result: " << newResult << " vs Old result: " << oldResult << endl;

		if (abs(oldResult - expectedOutput) > abs(newResult - expectedOutput)) {
			// cout << "Choosing mutation" << endl;
			(*this) = tempNN;
		}
		else {
			// cout << "Ditching mutation" << endl;
			tempNN = (*this);
		}
	}
}

void NeuralNetwork::train(float* inputArray, int inputLength, float* outputArray, int outputLength) {
	// float runResult;

	// for (int cEpoch = 0; cEpoch < this->epochLimit; cEpoch++) {
	// 	for (int i = 0; i < inputLength; i++) {
	// 		runResult = this->run(inputArray[i]);
	// 	}

	// 	if 
	// }
}

float NeuralNetwork::run(float input) {
	// cout << "Running " << input << " over: " << endl;
	// cout << (*this) << endl;

	float tempArray[this->nNodes];
	float copyArray[this->nNodes];
	// float* copyArray;
	// tempArray = new float[this->nNodes];
	// copyArray = new float[this->nNodes];

	for (int j = 0; j < this->nNodes; j++) { // Used j because j is current row, not column
		tempArray[j] = this->net[0][j] * input;
	}

	for (int i = 1; i < this->nLayers; i++) { // Iterate over layers - Starts at 1, because first layer calc'd manually
		for (int j = 0; j < this->nNodes; j++) { // Iterate over nodes in layer
			float sum = 0;
			for (int k = 0; k < this->nNodes; k++) { // Iterate over nodes in layer - sum to get new value
				sum += tempArray[k] * this->net[i][j];
			}
			copyArray[j] = sum;
		}
	}

	float finalSum = 0;
	for (int i = 0; i < this->nNodes; i++) {
		finalSum += tempArray[i];
	}

	// cout << "Got: " << finalSum << endl;

	return finalSum;
}

NeuralNetwork& NeuralNetwork::operator=(const NeuralNetwork& other) {
	// cout << "Starting copy!" << endl;
	// cout << "RH: " << other.net << endl;

	// cout << "Deleting layers of LH: " << this->net << endl;
	this->deleteLayers();
	// cout << "Done:" << this->net << endl;

	this->nLayers = other.nLayers;
	this->nNodes = other.nNodes;
	this->epochLimit = other.epochLimit;

	this->createLayers();

	for (int i = 0; i < this->nLayers; i++) {
		for (int j = 0; j < this->nNodes; j++) {
			this->net[i][j] = other.net[i][j];
		}
	}

	return (*this);
}


ostream& operator<<(ostream& co, const NeuralNetwork& nn) {
	if (nn.created) {
		co << "Network at address: " << nn.net << endl;
		co << setfill(' ') << setw(10) << ' '; 	// Pre-header row spacing
		for (int i = 0; i < nn.nLayers; i++) {
			co << "Layer " << i << "   "; 		// Labelling layers
		}
		co << endl; // End header row

		for (int j = 0; j < nn.nNodes; j++) {
			co << "Node " << j << ": "; 		// Label row
			for (int i = 0; i < nn.nLayers; i++) {
				co << setw(9) << nn.net[i][j] << " "; // Output data
			}
			co << endl;
		}
	}
	else {
		co << "Error: Network not yet created!";
	}

	return co;
}