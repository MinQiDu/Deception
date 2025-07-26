# Implement SimulatedAnnealing / TabuSearch for Solving Deception Problem

## ( I ) Introduction

- Language: C++
- Metaheuristic algorithms: Simulated Annealing (SA), Tabu Search (TB)
- Benchmark function: Deception Problem
- Objective: Maximize \( f(x) = |\text{b2b}(x) - 2^{bit - 2}| \)

## ( II ) Main Functionality

### `SimulatedAnnealing`

- `void RunALG(int bit, int run, int iter)`  
  *Runs SA algorithm*
- `void Init(vector<int>& sol, int& value)`  
  *Generates a random initial solution*
- `vector<int> Neighbor(const vector<int>& sol)`  
  *Generates a neighbor by multi-bit mutation*
- `void Evaluation(const vector<int>& sol, int& value)`  
  *Evaluates the solution’s fitness value*
- `void T_cooldown(double& temp)` / `void T_reheat(double& temp)`  
  *Controls the temperature schedule*
- `void Create_Vrecord(const string& filename, const vector<double>& content)`  
  *Outputs fitness values to a `.txt` file*

### `TabuSearch`

- `void RunALG(int bit, int run, int iter, int tabu_size, int tweak_num)`  
  *Runs Tabu Search*
- `vector<int> Init()`  
  *Initializes a solution and sets initial best*
- `vector<int> Tweak(const vector<int>& origin_sol)`  
  *Generates `tweak_num` tweaked neighbors*
- `int Evaluation(const vector<int>& sol)`  
  *Calculates the fitness of a solution for Deception*
- `void Create_Record(const string& filename, const vector<T>& content)`  
  *Outputs records to `.txt`, supports multiple data types via templates*

## ( III ) Input

### Command-line arguments:

- **Bit Length:** `bit = (4 or 10)`
- **Number of Independent Runs:** `run = (e.g., 30)`
- **Number of Iterations per Run:** `iter = (1000 for SA / 5000 for TB)`
- `pop_size = unused (placeholder)`
- **Type of Algorithm:** `algo_type = SA / TB`
- For Tabu Search:
  - **Size of Tabu List:** `tabu_size = 5`
  - **Times of Tweak:** `tweak_num = 20`

## ( IV ) Output

### `SimulatedAnnealing`

- `values_of_run~30_SA_{bit}.txt`
- `values_average_SA_{bit}.txt`
- `plot_SA.plt`
- `result_Deception_SimulatedAnnealing_{bit}.png`

### `TabuSearch`

- `fitness_of_run_1~30_TB_bit_size_tweak.txt`
- `fitness_average_TB_bit_size_tweak.txt`
- `plot_TB.plt`
- `result_Deception_TB_bit_size_tweak.png`

## ( V ) How to Compile, Run and Result Visualization

### Compile

#### Visual Studio

1. Open the solution `deception.sln`
2. Press `Ctrl + F5` to build

#### VSCode

1. Open CMD or PowerShell
2. Navigate to the project folder
3. Run:
```bash
g++ main.cpp deception.cpp SimulatedAnnealing.cpp Tabu.cpp -o deception.exe
```

### Run

```bash
.\deception.exe bit run iter pop_size algo_type
```
Examples:
```bash
.\deception.exe 10 30 1000 1 SA
.\deception.exe 10 30 5000 0 TB
```
Then:
```
Please type tabu_size = (your input)
Please type tweak_num = (your input)
```

### Result Visualization

1. Install gnuplot
2. Run:
```bash
gnuplot plot_SA.plt
gnuplot plot_TB.plt
```
Generated PNGs will be found in the working directory

## ( VI ) File Structure

```
deception/
|
├── main.cpp
├── deception.cpp / deception.h
├── SimulatedAnnealing.cpp / SimulatedAnnealing.h
├── Tabu.cpp / Tabu.h
│
├── results/  ← output files (.txt, .png)
└── README.md ← this file
```

## ( VII ) Observations
- Simulated Annealing performs well in avoiding local optima by probabilistic acceptance of worse solutions.
- Tabu Search maintains a memory structure to avoid revisiting explored areas, which helps in escaping plateaus.
- Tabu Search is more sensitive to `tweak_num` and `tabu_size` parameters.
- Both algorithms are suitable for deception landscapes due to their non-greedy mechanisms.

## ( VIII ) Key Features
- Objective function tailored for deceptive landscape
- C++ implementation with modular design
- Exportable logs and gnuplot-ready visualization scripts
- Interactive runtime configuration via command-line and user input

## ( IX ) Skills Demonstrated
- Advanced metaheuristic algorithm implementation
- Custom fitness landscape evaluation (deception)
- Iterative local search (SA) and memory-based search (TB)
- Parameter-driven control of neighborhood exploration
- Integration with gnuplot for visual output
- Runtime I/O and template-based logging

