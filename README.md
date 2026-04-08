

# 🔍 Inverted Search Engine

## 📌 Project Overview

The Inverted Search Engine is a data structure–based project that enables efficient searching of words across multiple text files. Instead of scanning every file repeatedly, it builds an inverted index that maps each word to the list of files in which it appears. This approach significantly improves search speed and performance.

## 🎯 Objectives

The main objective of this project is to understand and implement the concept of inverted indexing, perform fast text searching, and gain practical experience with file handling, pointers, and data structures in C.

## ⚙️ Features

This project reads multiple text files, extracts unique words, and creates an inverted index. It allows users to search for words across all files and displays how many times each word appears in each file. It may also support saving and loading the database.

## 🛠️ Technologies Used

The project is implemented using the C programming language and uses concepts such as linked lists, file handling, structures, and pointers.

## 🧠 Working Principle

The program reads all input files, breaks the content into individual words, and stores them in a data structure. It creates a mapping where each word points to the files it appears in along with occurrence counts. When a user searches for a word, the program directly retrieves results from the index, making the search efficient.

## 🧾 Data Structure Used

The project uses a linked list–based structure where each node represents a word, and each word node contains a sub-list of file names along with the count of occurrences.

Example:
Word: data
→ file1.txt (3 times)
→ file2.txt (1 time)

## 🚀 How to Run

First, compile the program using: gcc *.c
Then run the executable using: ./a.out file1.txt file2.txt
After running, follow the menu options such as creating the database, displaying it, searching for a word, saving, or updating the database.

## 📸 Sample Output

Enter the word to search: data
Word found!
File: file1.txt -> Count: 3
File: file2.txt -> Count: 1

## ⚠️ Challenges Faced

* Managing dynamic memory allocation efficiently
* Handling linked list creation and traversal
* Avoiding duplicate word entries in the database
* Maintaining correct file-to-word mapping
* Implementing efficient search operations
* Handling file input/output errors
* Ensuring proper pointer usage without memory leaks

## 📚 Key Learnings

* Understanding the concept of **inverted indexing**
* Strong practice of **pointers and dynamic memory allocation**
* Hands-on experience with **linked list data structures**
* Improved knowledge of **file handling in C**
* Learned how to design **efficient search algorithms**
* Better understanding of **data organization and mapping techniques**
* Debugging and handling **runtime errors and edge cases**


## 👩‍💻 Author

Samiksha Mane
BTech Electronics & Telecommunication Engineering

