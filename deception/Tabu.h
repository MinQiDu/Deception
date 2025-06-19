#ifndef TABU_H
#define TABU_H

#include "deception.h"
#include <string>
#include <fstream>

class algo_TB
{
public :
	void RunALG(const int &bit,
		        const int &run,
		        const int &iter,
		        const int &tabu_size,
		        const int &tweak_num);
private :
	int bit;
	int run;
	int iter;

	int mnfes;
	int nfes;

	vector<int> best_sol;
	int best_fit;
	vector<int> best_record;
	vector<double> avg_record;

	vector<int> Init();                        /*產生初始解並輸出，設定best_sol, best_fit初始值*/
	vector<int> Tweak(const vector<int> &sol); /*微調origin_sol tweak_num次並輸出*/
	int Evaluation(const vector<int>& sol);    /*計算sol的onemax fitness，輸出fitness*/
	
	template<typename T>
	void Create_Record(const string& filename,
		const vector<T>& content)
	{
		ofstream file(filename);
		for (int i = 0; i < mnfes; ++i)
		{
			file << i + 1 << " " << content[i] << "\n";
		}
		file.close();
	} /*產生紀錄內容的文字檔，因為實作在多種型別上所以使用template*/
};

#endif
