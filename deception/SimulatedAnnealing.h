#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include "Deception.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class algo_SA : Deception
{
public:
    void RunALG(int bit, int run, int iter);

private:
    //*input from command_line argument*//
    int bit;
    int run;
    int iter;    /*max times of iteration = mnfes*/
    double temp;
    double cool_rate;
    double reheat_rate;
    double min_temp;

    //*use times of evaluation to replace times of iteration*//
    int mnfes;   /*max times of evaluation*/
    int nfes;    /*times of evaluation*/

    void Init(vector<int>& sol, int& value);                                    /*�H�����ͪ�l��*/
    vector<int> Neighbor(const vector<int>& sol);                               /*�h�I�ܲ����;F�~*/
    void Evaluation(const vector<int>& sol, int& value);                        /*�p��s�Ѫ�value*/
    void T_cooldown(double& temp);                                              /*���C�ū�*/
    void T_reheat(double& temp);                                                /*�ɰ��ū�*/
    void Create_Vrecord(const string& filename, const vector<double>& content); /*create.txt to record values*/
};

#endif
