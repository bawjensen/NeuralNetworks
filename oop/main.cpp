#include <iostream>
#include <ctime>

#include "networkClass.h"

using namespace std;

int main() {
	NeuralNetwork nn;
	clock_t start, tTime;

	// cout << "Created first" << endl;

	nn.setNumNodes(100000);
	nn.setNumLayers(1);
	nn.setEpochLimit(1000);

	// cout << "Established first" << endl;
	// cout << "Creating second" << endl;

	NeuralNetwork nn2 = nn;

	// cout << "Created second" << endl;

	// cout << "First before: " << endl << nn << endl;

	int input = 1;
	int output = 1;

	start = clock();
	nn2.train(input, output);
	tTime = clock() - start;

	printf ("Training took %f seconds.\n", ((float)tTime)/CLOCKS_PER_SEC); // RESULT: 8.588 seconds
	cout << "Was it trained?: " << nn2.run(input) << endl;

	// cout << "First after: " << endl << nn << endl;
	// cout << "Second after: " << endl << nn2 << endl;

	// cout << nn << endl;

	// nn.train(2, 4);
	// nn.train(4, 6);
	// nn.train(6, 8);

	// cout << nn << endl;


	return 0;
}