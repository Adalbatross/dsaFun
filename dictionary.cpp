#include <bits/stdc++.h>

using namespace std;

struct Node {
    string word;
    Node* next;
    
    Node(string word) : word(word), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(string word) {
        Node* newNode = new Node(word);
        newNode->next = head;
        head = newNode;
    }

    bool search(string word) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->word == word) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "NULL";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->word;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
    }
};

class HashTable {
private:
    static const int table_size = 10;
    LinkedList table[table_size];

    int hashFunction(string word) {
        int hash = 0;
        for (char ch : word) {
            hash += static_cast<int>(ch);
        }
        return hash % table_size;
    }

public:
    void insert(string word) {
        int index = hashFunction(word);
        table[index].insert(word);
    }

    bool search(string word) {
        int index = hashFunction(word);
        return table[index].search(word);
    }

    void display() {
        for (int i = 0; i < table_size; ++i) {
            cout << "Bucket " << i << ": ";
            table[i].display();
            cout << endl;
        }
    }

    void loadDictionary(const string &filename) {
        ifstream file(filename);
        string word;
        while (file >> word) {
            insert(word);
        }
    }
};

void createDictionaryFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        ofstream outFile(filename);
        if (outFile) {
            outFile << "this is an empty dictionary crated for testing if the word is present or not\n";
            cout << "Dictionary file created and populated with sample words." << endl;
        } else {
            cout << "Error creating the dictionary file." << endl;
        }
    } else {
        cout << "Dictionary file already exists." << endl;
    }
}

void displayMenu() {
    cout << "\n----- Menu -----\n";
    cout << "1. Insert the words into dictionary\n";
    cout << "2. Search for a word\n";
    cout << "3. Display all words\n";
    cout << "4. Exit\n";
    cout << "----------------\n";
}

int main() {
    string dictionaryFilename = "dictionary.txt";
    
    createDictionaryFile(dictionaryFilename);

    HashTable hashTable;

    hashTable.loadDictionary(dictionaryFilename);

    int choice;
    string input_word;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the word to insert: ";
                cin >> input_word;
                for (char &ch : input_word) {
                    ch = tolower(ch);
                }
                hashTable.insert(input_word);
                cout << "'" << input_word << "' has been inserted into the hash table.\n";
                break;

            case 2:
                cout << "Enter the word to search: ";
                cin >> input_word;
                for (char &ch : input_word) {
                    ch = tolower(ch);
                }
                if (hashTable.search(input_word)) {
                    cout << "'" << input_word << "' is spelled correctly!" << endl;
                } else {
                    cout << "'" << input_word << "' is not spelled correctly." << endl;
                }
                break;

            case 3:
                cout << "Displaying all words in the hash table:\n";
                hashTable.display();
                break;

            case 4:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}