#ifndef _NNCLASS
#define _NNCLASS

#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

class NeuralNetwork {
private:
	long nLayers, nNodes;
	float** net;
	bool created;
	int epochLimit;

	void init();
	void deleteLayers();
	void createLayers();
	void fillNet();
public:
	NeuralNetwork();
	NeuralNetwork(const NeuralNetwork&);

	void setNumNodes(int);
	void setNumLayers(int);
	void setEpochLimit(int);

	void mutate();
	void train(float, float);
	void train(float*, int, float*, int);

	float run(float);

	NeuralNetwork& operator=(const NeuralNetwork&);

	friend ostream& operator<<(ostream&, const NeuralNetwork&);
};

#endif