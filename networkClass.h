#ifndef _NNCLASS
#define _NNCLASS

#include <iostream>

using namespace std;

class NeuralNetwork {
private:
	long numHLayers;
	long nodePerLayer;

	float** hNetwork;

	int epochLimit;
public:
	NeuralNetwork();
	NeuralNetwork(int, int);

	void train(float*, int, float*, int);

	float run(float);
};

#endif