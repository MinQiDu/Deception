# 使用 SimulatedAnnealing 解 Deception problem

## 1. 基本說明

- Using C++
- Implement SimulatedAnnealing to solve Deception problem : maximize f(x) = abs(b2b(x) - pow(2, bit - 2))



## 2. 主要功能 

### `SimulatedAnnealing`

- void RunALG(int bit, int run, int iter) : 執行SA
- void Init(vector<int> &sol, int &value) : 隨機產生初始解
- vector<int> Neighbor(const vector<int> &sol) : 多點變異產生鄰居
- void Evaluation(const vector<int> &sol, int &value) : 計算新解的value
- void T_cooldown(double &temp) : 降低溫度
- void T_reheat(double &temp) : 升高溫度
- void Create_Vrecord(const string& filename, const vector<double>& content) : create.txt to record values



## 3. Input 

### command_line argument :

- 二進位位元數 | bit = 4 or 10
- 回合數 | run = 30
- 單回合迭代次數 | iter = 1000
- 一世代人口數 | pop_size = no use
- 演算法種類 | algo_type = SA



## 4. Output 

### `SimulatedAnnealing`

- values_of_run~30_SA_幾bit.txt
- values_average_SA_幾bit.txt
- plot_SA.plt
- result_OneMax_SimulatedAnnealing_幾bit.png



## 5. 執行方式 

### `------------編譯------------`

#### `VisualStudio`
1. 開啟 Visual Studio 專案 `deception.sln`
2. 按下 `Ctrl + F5` 開始編譯

#### `VSCode`
1. 在 Windows cmd 或 PowerShell 中
2. 先到正確資料夾路徑
3. 輸入 :

g++ main.cpp deception.cpp SimulatedAnnealing.cpp -o deception.exe


### `------------執行------------`

1. 在 Windows cmd 或 PowerShell 中
2. 先到正確資料夾路徑
3. 輸入 :   
.\deception.exe bit run iter pop_size algo_type   
eg. 
.\deception.exe 10 30 1000 1 SA



### `------------出圖------------`

1. 安裝gnuplot
2. 在 Windows cmd 或 PowerShell 中
3. 先到正確資料夾路徑
4. 輸入 : 

gnuplot plot_SA.plt   
即可在資料夾中找到 result_Deception_SimulatedAnnealing_幾bit.png

## 6. 檔案結構
- deception/
`SimulatedAnnealing.cpp` / `SimulatedAnnealing.h`   
`deception.cpp` / `deception.h`