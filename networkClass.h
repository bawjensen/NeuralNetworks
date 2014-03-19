#ifndef _NNCLASS
#define _NNCLASS

#include <iostream>

using namespace std;

class NeuralNetwork {
private:
	long nLayers;
	long nNodes;

	float** net;

	int epochLimit;

	void createLayers();
	void fillNet();
public:
	NeuralNetwork();
	// NeuralNetwork(int, int);

	void setNumNodes(int);
	void setNumLayers(int);

	void train(float*, int, float*, int);

	float run(float);
};

#endif