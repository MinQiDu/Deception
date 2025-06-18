#include "SimulatedAnnealing.h"
#include <cstdlib>       /*for srand()*/
#include <ctime>         /*for time()*/
#include <cmath>
#include <fstream>
#include <unordered_set> /*for unordered_set*/

void algo_SA::RunALG(int _bit, int _run, int _iter)
{
    bit = _bit;
    run = _run;
    iter = _iter;
    mnfes = iter;

    srand(time(NULL));

    vector<double> vrecord_sum(mnfes, 0); /*for output of values & plot*/

    for (int r = 0; r < run; ++r)
    {
        temp = 10000.0;
        cool_rate = 0.9799;
        reheat_rate = 1.1;
        min_temp = 1e-15;
        nfes = 0;

        vector<int> sol(bit);
        int value;
        Init(sol, value);
        vector<int> best_sol = sol;
        int best_value = value;
        vector<double> vrecord(mnfes, 0); /*for output of values & plot*/
        
        int stuck_count = 0; /*adaptive cooling reheat machanism*/

        while (nfes < mnfes and temp > min_temp)
        {
            vector<int> new_sol = Neighbor(sol); /*sol���ӥͦ��s��*/
            int new_value;
            Evaluation(new_sol, new_value);
            double differ = new_value - value; /*�s�ͦ����F�~�M��Ȫ��t*/

            if (differ > 0 or (exp(differ / temp) > (double)rand() / RAND_MAX))
            {                  /*��s���u���� or �Y�L�h�@�w���v�U*/
                sol = new_sol; /*��s���ӥͦ��s�Ѫ���*/
                value = new_value;

                if (value > best_value) /*����s�Ѫ����A�U*/
                {                       /*�i�@�B�ˬd�s�ѬO�_�u��best_value*/
                    best_sol = sol;     /*�Y���h��s���u��*/
                    best_value = value;
                }
            }

            if (differ <= 0)
            {
                stuck_count++;
            }

            if (stuck_count >= 50) /*�Y_��iter���S�i�B*/
            {
                T_reheat(temp);  /*�N����reheat*/
                stuck_count = 0; /*�O�o�M��stuck_count���s�p��*/
            }
            else
            {
                T_cooldown(temp); /*adjust temp after evaluation*/
            }

            vrecord[nfes] = best_value;
            nfes++;
        };
        for (int n = 0; n < mnfes; ++n)
        {
            vrecord_sum[n] += (vrecord[n] / run);
        }

        Create_Vrecord("values_of_run_" + to_string(r + 1) + "_SA_" + to_string(bit) + "bit.txt", vrecord);

        cout << "[Best Value of Run " << r << "] = " << best_value << " [Best Solution] = "; /*��Xbest_sol of each run*/
        for (int i = 0; i < bit; ++i) 
        {
            cout << best_sol[i];
        };
        cout << endl;

    };
    Create_Vrecord("values_average_SA_" + to_string(bit) + "bit.txt", vrecord_sum); /*�إߨCrun���Citeration��average value����*/

    ofstream plot("plot_SA.plt"); /*�إ�plot_SA.plt*/
    plot << "set terminal png size 800, 600\n";
    plot << "set output 'result_Deception_SimulatedAnnealing_" << bit << "bit.png'\n";
    plot << "set title 'Average Convergence with SimulatedAnnealing on OneMax'\n";
    plot << "set xlabel 'Iteration'\n";
    plot << "set ylabel 'Average Value'\n";
    plot << "set xrange [0:" << mnfes << "]\n";
    plot << "set yrange [0:" << pow(2, bit) - 1 << "]\n";
    plot << "plot 'values_average_SA_" << bit << "bit.txt'" << "using 1:2 with lines title 'Average with SimulatedAnnealing'\n";
    plot.close();
};

void algo_SA::Init(vector<int>& sol, int& value)
{
    for (int b = 0; b < bit; ++b)
    {
        sol[b] = rand() % 2;
    };
    value = DeceptionProblem(sol, bit);
};

vector<int> algo_SA::Neighbor(const vector<int>& sol)
{
    vector<int> new_sol = sol;
    int flips = 1 + rand() % 2; /* ��ĳ flip 1~3 bits ����*/

    unordered_set<int> flipped; // �T�O������ flip �P�@��

    while (flipped.size() < flips)
    {
        int idx = rand() % bit;
        if (flipped.insert(idx).second)
            new_sol[idx] = 1 - new_sol[idx];
    }
    return new_sol;
};

void algo_SA::Evaluation(const vector<int>& sol, int& value)
{
    value = DeceptionProblem(sol, bit);
};

void algo_SA::T_cooldown(double& temp) /*�������temperature����*/
{
    temp = temp * cool_rate;
};

void algo_SA::T_reheat(double& temp)
{
    temp = temp * reheat_rate;
};

void algo_SA::Create_Vrecord(const string& filename, const vector<double>& content)
{
    ofstream file(filename); /*�إߨCrun���Citeration��average value����*/
    for (int i = 0; i < iter; ++i)
    {
        file << i + 1 << " " << content[i] << "\n";
    }
    file.close();
};