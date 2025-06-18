#include "deception.h"
#include "SimulatedAnnealing.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	int bit = stoi(argv[1]);
	int run = stoi(argv[2]);
	int iter = stoi(argv[3]);
	string algo_type = argv[5]; /*¿ïºtºâªk*/

	if (algo_type == "SA")
	{
		algo_SA algo;
		algo.RunALG(bit, run, iter);
	}
	else
	{
		cout << "Choose Algorithm ( SA )" << endl;
	}

};