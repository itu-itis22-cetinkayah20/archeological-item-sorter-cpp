

# Archeological Item Sorter

## Overview

This project is designed to sort archeological items based on various attributes. The project reads item data from CSV files, processes it using different sorting algorithms, and writes the sorted results back to CSV files. The goal is to provide a structured and efficient way to handle and sort archeological item data.

### Sorting Algorithms Used

- **Counting Sort**: This algorithm is used to sort items based on discrete attributes such as age, type, and origin. It can sort in both ascending and descending order.
  - **Ascending Counting Sort**: Sorts items in ascending order by counting the occurrences of each attribute value and then placing items in the correct position.
  - **Descending Counting Sort**: Sorts items in descending order by counting the occurrences of each attribute value and then placing items in the correct position.

- **Heap Sort**: This algorithm is used to sort items based on the rarity score. It can also sort in both ascending and descending order.
  - **Max-Heapify**: Ensures that the largest element is at the root of the heap.
  - **Min-Heapify**: Ensures that the smallest element is at the root of the heap.
  - **Heap Sort by Rarity**: Builds a heap from the items and then extracts elements one by one to sort the items.
## Features

- **Read Items**: Read archeological item data from CSV files.
- **Create Items**: Create item objects from the data.
- **Write Items**: Write sorted item data back to CSV files.
- **Error Handling**: Handle file reading errors gracefully.

---

## **Project Structure**

```
/archeological-item-sorter-cpp/
│── .devcontainer/            # Development container configuration
│── .vscode/                  # VS Code configuration
│── bin/                      # Compiled binaries
│── data/                     # CSV files with item data
│   │── permutations/         # Permutation data
│   │── sizes/                # Different sizes of item data
│── include/                  # Header files
│── lib/                      # Libraries
│── src/                      # Source code
│   │── main.cpp              # Main entry point for the application
│   │── metrics.cpp           # Metrics calculation
│   │── sort.cpp              # Sorting algorithms
│   │── utilities.cpp         # Utility functions
│── tests/                    # Unit tests
│── LICENSE                   # License information
│── Makefile                  # Build configuration
│── README.md                 # Documentation
```

---

## **Getting Started**

### **Prerequisites**

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., g++, clang).
- **Make**: Make sure you have `make` installed for building the project.
- **Docker**: Make sure that Docker is installed in your system. Reopen the project in docker container when vscode offers to ensure that tests work. 

### **Installation**

1. **Clone the repository**
    - You can clone the repository using git or download it from Code, Download ZIP
    ```sh
    git clone https://github.com/itu-itis22-cetinkayah20/archeological-item-sorter-cpp.git
    cd archeological-item-sorter-cpp
    ```

2. **Build the project**
    ```sh
    g++ -g -o bin/item_sorter src/*.cpp -Iinclude
    make build
    ```

### **Running the Application**
- The application will process the item data and output the sorted results to the specified CSV files.
- You can activate the commented code blocks in `main.cpp` to observe the execution times of different algorithms.
```sh
./bin/item_sorter
```
### **Making Tests**
Make sure that you execute the following command. 
```sh
make build
```
Then you can run the tests. 
```sh
make tests
```

## **Technologies Used**

- **C++**: Core programming language for processing item data.
- **CSV**: Format for input and output data files.
- **Makefile**: For building the project.
- **Unit Testing**: To ensure code reliability and correctness.

## **Usage**

- **Sort Items**: Run the application to sort item data from the CSV files.
- **Modify Data**: Update the CSV files with new item data and re-run the application to see updated results.

---

## **Contributing**
Contributions are welcome! Please fork the repository and submit a pull request.

---

## **License**

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this software dedicate any and all copyright interest in the software to the public domain. We make this dedication for the benefit of the public at large and to the detriment of our heirs and successors. We intend this dedication to be an overt act of relinquishment in perpetuity of all present and future rights to this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>






