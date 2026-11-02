# 🎀 Duplicate Detection
### ⚡ Brute Force vs. Sort-and-Scan

**One Problem. Two Algorithms. Different Performances.** 🧠💻

Welcome to my little corner of algorithm analysis! 🌷

This C++ project explores two different approaches to detecting duplicate elements in an integer array.

The goal? To discover how algorithm design affects execution time and why choosing the right algorithm matters as the input size grows.

---

## 🧠 Meet the Algorithms

### 🐢 1. Brute Force

The straightforward approach!

Brute Force compares each element with the remaining elements until it finds a duplicate or finishes checking the array.

- ⏱️ **Time Complexity:** O(n²)
- 💾 **Space Complexity:** O(1)

### 🚀 2. Sort-and-Scan

A smarter approach for larger datasets!

First, the array is sorted. Then, neighboring elements are compared to detect duplicates.

- ⏱️ **Time Complexity:** O(n log n)
- 💾 **Auxiliary Space:** Depends on the sorting implementation.

---

## ✨ What's Inside?

- 🔍 Two duplicate detection algorithms implemented in C++.
- 🧪 Four correctness tests.
- ⏱️ Execution time measurement using `std::chrono`.
- 🎲 Randomized arrays using `std::shuffle`.
- 📊 Performance comparison across five input sizes.
- 🔁 Five trials per input size.
- ⚡ Speedup calculations.
- 📈 Growth ratio analysis.

---

## 🔬 The Experiment

**Can we actually observe the difference between O(n²) and O(n log n)?**

To find out, I tested both algorithms using five input sizes:

`4,000 • 8,000 • 16,000 • 32,000 • 64,000`

Each input size was tested five times with different random seeds.

The benchmark arrays contained unique integers shuffled into random order.

Execution times were measured in nanoseconds and averaged in milliseconds.

---

## 📊 Experimental Results

Here is what happened when the input size increased!

| 📦 Input Size | 🐢 Brute Force (ms) | 🚀 Sort-and-Scan (ms) | ⚡ Speedup |
|---|---:|---:|---:|
| 4,000 | 18.4031 | 0.575238 | 31.99x |
| 8,000 | 74.3702 | 1.28553 | 57.85x |
| 16,000 | 288.268 | 2.56849 | 112.23x |
| 32,000 | 1151.52 | 5.49 | 209.75x |
| 64,000 | 4652.56 | 11.71 | 397.32x |

💡 **Fun observation:** At 64,000 elements, Sort-and-Scan was approximately **397 times faster** than Brute Force!

*Results were measured on an Intel Core i7-10850H processor. Actual execution times may vary across systems.*

---

## 📈 What Did I Discover?

🐢 **Brute Force:** When the input size doubles, execution time increases by approximately 4x.

🚀 **Sort-and-Scan:** When the input size doubles, execution time increases by approximately 2x or slightly more.

✨ **The takeaway:** Algorithm efficiency becomes increasingly important as the amount of data grows.

A small difference in algorithm design can create a huge difference in performance!

---

## 💻 How to Run

You'll need a C++ compiler with C++11 support or later.

**1. Clone the repository**

```bash
git clone https://github.com/tala-daraghmeh/Duplicate-Detection.git
```

**2. Open the project directory**

```bash
cd Duplicate-Detection
```

**3. Compile the program**

Using g++:

```bash
g++ -std=c++11 main.cpp -o duplicate_detection
```

**4. Run it**

On Windows:

```bash
.\duplicate_detection.exe
```

On macOS/Linux:

```bash
./duplicate_detection
```

The program will display the test results, execution times, averages, speedups, and growth ratios.

---

## 🛠️ Tech Stack

- 💻 **Language:** C++
- 📚 **Libraries:** STL (`algorithm`, `chrono`, `random`)
- 🧪 **Testing:** Custom correctness tests
- ⏱️ **Benchmarking:** `std::chrono`
- 🗂️ **Version Control:** Git & GitHub

---

## 🎓 About This Project

This project was developed as part of my **Analysis and Design of Algorithms** university course.

It helped me explore the relationship between theoretical time complexity and real execution performance through hands-on experimentation.

**Learning algorithms is one thing. Watching them compete is another!** 🧠⚡

---

### 🌷 Made with curiosity, C++, and a little bit of pink energy. 🎀💻
