#ifndef _NNCLASS
#define _NNCLASS

#include <iostream>

using namespace std;

class NeuralNetwork {
private:
	long nLayers, nNodes;
	float** net;
	bool created;
	int epochLimit;

	void deleteLayers();
	void createLayers();
	void fillNet();
public:
	NeuralNetwork();

	void setNumNodes(int);
	void setNumLayers(int);

	void train(float, float);
	void train(float*, int, float*, int);

	float run(float);
};

#endif