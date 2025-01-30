#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the size of the hash table
const int TABLE_SIZE = 101;

// Hash table class with separate chaining
class HashTable {
private:
    list<string> table[TABLE_SIZE];

    // Hash function to map a word to a table index
    int hashFunction(const string& word) {
        int hashValue = 0;
        for (char ch : word) {
            hashValue = (hashValue * 31 + ch) % TABLE_SIZE;
        }
        return hashValue;
    }

public:
    // Insert a word into the hash table
    void insert(const string& word) {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    // Check if a word exists in the hash table
    bool search(const string& word) {
        int index = hashFunction(word);
        for (const string& storedWord : table[index]) {
            if (storedWord == word) {
                return true;
            }
        }
        return false;
    }

    // Remove a word from the hash table
    void remove(const string& word) {
        int index = hashFunction(word);
        table[index].remove(word);
    }

    // Display all words in the hash table
    void displayAll() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (const string& word : table[i]) {
                cout << word << " ";
            }
        }
        cout << endl;
    }
};

// Function to load words from the dictionary file into the hash table
void loadDictionary(const string& filename, HashTable& hashTable, vector<string>& dictionaryWords) {
    ifstream file(filename);
    string word;
    
    if (!file) {
        cerr << "Error opening dictionary file!" << endl;
        exit(1);
    }

    dictionaryWords.clear();  // Clear previous words
    while (file >> word) {
        hashTable.insert(word);
        dictionaryWords.push_back(word);
    }
    file.close();
}

// Function to save the words back to the dictionary file
void saveDictionary(const string& filename, const vector<string>& dictionaryWords) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening dictionary file for writing!" << endl;
        exit(1);
    }
    
    for (const string& word : dictionaryWords) {
        file << word << " ";
    }
    file.close();
}

// Function to remove a word from the dictionary vector
void removeFromVector(vector<string>& dictionaryWords, const string& word) {
    auto it = find(dictionaryWords.begin(), dictionaryWords.end(), word);
    if (it != dictionaryWords.end()) {
        dictionaryWords.erase(it);
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add a word\n";
    cout << "2. Delete a word\n";
    cout << "3. Search a word\n";
    cout << "4. Show all words\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    // Create a hash table object
    HashTable hashTable;

    // Load the dictionary file into the hash table and vector
    string dictionaryFile = "dictionary.txt"; // Change the file name as per your system
    vector<string> dictionaryWords;
    loadDictionary(dictionaryFile, hashTable, dictionaryWords);

    // Variable to store user's choice
    int choice;
    string userInput;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Add a word
                cout << "Enter word to add: ";
                cin >> userInput;
                if (!hashTable.search(userInput)) {
                    hashTable.insert(userInput);
                    dictionaryWords.push_back(userInput);
                    saveDictionary(dictionaryFile, dictionaryWords);
                    cout << userInput << " added successfully!" << endl;
                } else {
                    cout << userInput << " is already in the dictionary!" << endl;
                }
                break;

            case 2: // Delete a word
                cout << "Enter word to delete: ";
                cin >> userInput;
                if (hashTable.search(userInput)) {
                    hashTable.remove(userInput);
                    removeFromVector(dictionaryWords, userInput);
                    saveDictionary(dictionaryFile, dictionaryWords);
                    cout << userInput << " deleted successfully!" << endl;
                } else {
                    cout << userInput << " not found in the dictionary!" << endl;
                }
                break;

            case 3: // Search a word
                cout << "Enter word to search: ";
                cin >> userInput;
                if (hashTable.search(userInput)) {
                    cout << userInput << " is spelled correctly!" << endl;
                } else {
                    cout << userInput << " is not spelled correctly!" << endl;
                }
                break;

            case 4: // Show all words
                cout << "All words in the dictionary:\n";
                hashTable.displayAll();
                break;

            case 5: // Exit
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
