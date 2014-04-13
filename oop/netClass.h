#ifndef _NNCLASS
#define _NNCLASS

#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

class Node {
private:
	int nPointers;
	Node** pointers;
	float val;

public:
	Node();

	void operator=(float);
	void operator+=(float);
	float operator*(float);

	friend float operator*(const float&, const Node&);
	friend ostream& operator<<(ostream&, const Node&);
};

class NeuralNetwork {
private:
	long nLayers, nNodes;
	Node** net;
	// float** net;
	bool created;
	int epochLimit;

	default_random_engine generator;

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