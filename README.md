# 🍽️ CokoMoko Food Delivery System

CokoMoko is a command-line based food ordering system that simulates a real-world food delivery service at tourist locations, specifically in Dehradun. Users can explore dishes, add them to a cart, and complete orders with simulated payments and feedback. The system also leverages advanced algorithms and data structures for a seamless and optimized experience.

---

## 🚀 Features

- ✅ User verification and input validation
- 🍴 Multiple ways to browse dishes:
  - By **restaurant/outlet**
  - By **cuisine** (North Indian, South Indian, Chinese, Italian)
  - By **dish name** (with **Trie-based fast search**)
- 🛒 Cart system to manage selected dishes
- 💳 Multiple payment options with status handling
- 📊 Feedback system post-order
- 🧠 Built-in logic for **shortest delivery path** using **Floyd-Warshall Algorithm**
- 🗃️ Persistent menu storage using file I/O
- 🔐 Robust exception handling for invalid inputs

---

## 🧠 Algorithms & Data Structures Used

### 📌 Algorithms
- **Floyd-Warshall Algorithm**  
  - Used for calculating the shortest paths between food outlets to optimize delivery routing.
  
- **Exception Handling**  
  - Gracefully manages invalid user inputs and prevents infinite loops through limit counters.

### 📌 Data Structures
- **Trie (Prefix Tree)**  
  - Enables efficient dish name searching by prefix or full match in the "search by dish name" option.
  
- **Unordered Map & Unordered Set**  
  - Used for storing and mapping unique dish keys and menu information.
  
- **Vectors**  
  - Used for dynamic storage of distances, menu items, and restaurant information.

---

## 🛠️ Tech Stack

- **Language**: C++
- **Libraries**: 
  - `<iostream>`, `<fstream>`, `<string.h>`, `<vector>`, `<unordered_map>`, `<unordered_set>`, `<exception>`, `<ctime>`, `<iomanip>`
- **Concepts**: File I/O, OOP, Algorithms, Data Structures

---

## 📂 Project Structure

```plaintext
CokoMoko/
│
├── main.cpp                   # Entry point and core logic
├── outlet.txt                 # Outlet details
├── north_indian.txt           # North Indian menu
├── south_indian.txt           # South Indian menu
├── chinease_corner.txt        # Chinese menu
├── italian.txt                # Italian menu
└── README.md                  # Project documentation
💻 How to Run
Ensure a C++ compiler is installed (e.g., g++, clang++)

Compile the program:
g++ -o CokoMoko main.cpp

Run the executable:
./CokoMoko


🔧 Possible Enhancements
  Add a GUI with Qt or SFML
  
  Implement live delivery tracking using maps and GPS APIs
  
  Store and manage user accounts and past orders with a local database
  
  Optimize search with more advanced string matching algorithms
