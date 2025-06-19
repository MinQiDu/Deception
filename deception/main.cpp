#include "deception.h"
#include "SimulatedAnnealing.h"
#include "Tabu.h"
#include <string>
#include <algorithm> // for all_of(input.begin(), input.end(), ::isdigit) & transform(輸入起點, 輸入終點, 輸出起點, 處理函式);
#include <cctype> // for toupper() tolower()
using namespace std;

bool is_num(const string& input)
{
	return !input.empty() && all_of(input.begin(), input.end(), ::isdigit);
}

int getline_and_check(const string &prompt)
{
	string input;

	while (true)
	{
		cout << prompt;
		getline(cin, input);
		if (is_num(input))
		{
			return stoi(input);
		}
		else
		{
			cout << "Please retype and make sure the form is number.\n";
		}
	}
}

int main(int argc, char *argv[])
{
	int bit = stoi(argv[1]);
	int run = stoi(argv[2]);
	int iter = stoi(argv[3]);
	string algo_type = argv[5];  /*選演算法*/
	transform(algo_type.begin(), /*防呆! 轉換algo_type成全大寫*/
		algo_type.end(),
		algo_type.begin(),
		toupper);

	if (algo_type == "SA")
	{
		algo_SA algo;
		algo.RunALG(bit, run, iter);
	}

	else if (algo_type == "TB")
	{
		int tabu_size = getline_and_check("Please type tabu_size = ");
		int tweak_num = getline_and_check("Please type tweak_num = ");

		algo_TB algo;
		algo.RunALG(bit, run, iter, tabu_size, tweak_num);
	}

	else
	{
		cout << "Choose Algorithm ( SA / TB)" << endl;
	}

};