# DC3 Suffix Array Implementation & Benchmarking

This repository contains implementations of the **DC3 (Skew) algorithm** for suffix array construction, along with comparison implementations (**Naive** and **Doubling**) and a full benchmarking + analysis pipeline.

## 📌 Project Goals

- Implement suffix array algorithms in **C++ and Python**
- Benchmark **runtime** and **memory usage**
- Analyze performance using **Jupyter notebooks**
- Compare theoretical vs practical performance

---

## 📁 Repository Structure
```
├── dc3-engine/ # Core algorithm implementations (C++ & Python)
│ ├── dc3.cpp
│ ├── dc3.py
│ ├── doubling.cpp
│ ├── doubling.py
│ ├── naive.cpp
│ └── naive.py
│
├── benchmark/ # Benchmark source code (C++)
│ ├── dc3.cpp # Runtime benchmark (DC3)
│ ├── dc3_mem.cpp # Memory benchmark (DC3)
│ ├── doubling.cpp # Runtime benchmark (Doubling)
│ ├── naive.cpp # Runtime benchmark (Naive)
│ └── naive_mem.cpp # Memory benchmark (Naive)
│
├── run/ # Compiled executables
│ ├── benchmark_dc3_latency.exe
│ ├── benchmark_dc3_mem.exe
│ ├── benchmark_doubling_latency.exe
│ ├── benchmark_naive_latency.exe
│ ├── benchmark_naive_mem.exe
│ └── test_comp_naive.exe
│
├── logs/ # Benchmark output logs
│ └── README.md # Describes expected log files
│
├── results/ # Analysis & visualization
│ ├── perf_latency.ipynb
│ └── perf_mem.ipynb
│
└── test/ # Correctness testing
```


---

## ⚙️ Algorithms Implemented

- **DC3 (Skew Algorithm)** — O(n)
- **Doubling Algorithm** — O(n log n)  
- **Naive Algorithm** — O(n² log n)

Each algorithm is implemented in both:
- C++
- Python

---

## 🚀 How to Compile & Run

### 1. Compile Benchmarks

#### Runtime Benchmark (DC3)
```bash
g++ .\benchmark\dc3.cpp -o .\run\benchmark_dc3_latency
```

#### Memory Benchmark (DC3)
```bash
g++ .\benchmark\dc3_mem.cpp -o .\run\benchmark_dc3_mem -lpsapi
```

#### Other Algorithms
```bash
g++ .\benchmark\doubling.cpp -o .\run\benchmark_doubling_latency
g++ .\benchmark\naive.cpp -o .\run\benchmark_naive_latency
g++ .\benchmark\naive_mem.cpp -o .\run\benchmark_naive_mem -lpsapi
```

### 2. Run Benchmarks
```bash
.\run\benchmark_dc3_latency.exe
.\run\benchmark_dc3_mem.exe
```
Logs will be generated inside the `logs/` directory.

### 3. Analyze Results
Use the Jupyter notebooks in `results/`:

-`perf_latency.ipynb` → Runtime analysis
-`perf_mem.ipynb` → Memory analysis

These notebooks:

-Parse log files
-Generate plots
-Provide insights into performance scaling

### 4. Run Correctness Tests
```bash
.\run\test_comp_naive.exe
```


## 📊 Logs
The `logs/` directory contains benchmark outputs such as:

- `latency_dc3.log`
- `mem_dc3.log`

See `logs/README.md` for details about file formats and naming.


## 🖥️ Benchmark Environment

Benchmarks were executed on:

- CPU: AMD Ryzen 5 7640HS (4.30 GHz)
- GPU: Radeon 760M Graphics
- RAM: 16 GB (15.2 GB usable)

## 📌 Notes

Memory benchmarks on Windows require:
```bash
-lpsapi
```

Executables are stored in `run/` for convenience
Python implementations are included for clarity and experimentation