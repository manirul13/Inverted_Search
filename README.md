 ## Inverted Search

A C-based implementation of an Inverted Index data structure for searching words across multiple text files.
Instead of mapping documents → words (forward index), this project builds a reverse mapping of words → documents where they appear, making search operations efficient and structured.

## 📖 Features

Build a searchable database (inverted index) from multiple text files.
Search for words and list all files containing them.
Update the database when new files are added.
Save and reload the database from a text file.
Display the entire database in a human-readable format.

## 🏗️ Project Structure
Inverted_Search/
│── main.c                 # Entry point of the program
│── inverted_search.h      # Header file (structures & prototypes)
│── create_database.c      # Builds the inverted index from files
│── display_database.c     # Displays index contents
│── update_database.c      # Updates index with new files
│── search.c               # Performs word search
│── save_database.c        # Saves database to a file
│── database.txt           # Stores persistent index data
│── file1.txt, file2.txt   # Sample input files
│── Makefile               # Build automation
│── README.md              # Documentation

## ⚙️ Compilation & Execution
Using GCC:
gcc *.c -o inverted_search
./inverted_search

## Using Make:
make
./inverted_search

## 🖥️ Usage

Prepare text files (file1.txt, file2.txt, etc.).

Run the program and follow the menu:

====== Inverted Search Menu ======
1. Create Database
2. Display Database
3. Update Database
4. Search Word
5. Save Database
6. Exit

## Example

If file1.txt contains:

hello world
this is a test


And file2.txt contains:

world of C programming


Searching for world will output:

Word "world" found in:
- file1.txt
- file2.txt

## 📂 Sample Database Output

The database (database.txt) stores the inverted index in a structured way:

word : hello → file1.txt
word : world → file1.txt, file2.txt
word : test → file1.txt

## 📚 Concepts Behind

Forward Index: Document → Words
Inverted Index: Word → Documents
Used in Information Retrieval Systems like search engines (Google, Bing, etc.).
Efficient for large-scale text search.

## 🚀 Future Enhancements

Support for stop-word removal (ignore common words like is, the, of).
Case-insensitive search.
Ranking results by frequency.
Support for large datasets.

 