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

	vector<int> Init();                        /*���ͪ�l�Ѩÿ�X�A�]�wbest_sol, best_fit��l��*/
	vector<int> Tweak(const vector<int> &sol); /*�L��origin_sol tweak_num���ÿ�X*/
	int Evaluation(const vector<int>& sol);    /*�p��sol��onemax fitness�A��Xfitness*/
	
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
	} /*���ͬ������e����r�ɡA�]����@�b�h�ث��O�W�ҥH�ϥ�template*/
};

#endif
