#include <iostream>
using namespace std;

class Node {
public:
    char data;
    string word;
    Node* next;
    Node() : next(nullptr) {}
};

class WordList {
public:
    Node* head;

    WordList() : head(nullptr) {
        // Initialize the linked list with alphabets
        for (char c = 'z'; c >= 'a'; c--) {
            Node* newNode = new Node();
            newNode->data = c;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertWord(const string& word) {
        char firstLetter = tolower(word[0]);
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == firstLetter) {
                Node* newWordNode = new Node();
                newWordNode->word = word;
                newWordNode->next = temp->next;
                temp->next = newWordNode;
                return;
            }
            temp = temp->next;
        }
    }

    void displayWords() {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->next != nullptr) {
                cout << "Words starting with the letter " << temp->data << ": ";
                Node* wordNode = temp->next;
                while (wordNode != nullptr) {
                    cout << wordNode->word << ", ";
                    wordNode = wordNode->next;
                }
                cout << endl;
            }
            temp = temp->next;
        }
    }

    void displayCount() {
        int total = 0;
        Node* temp = head;
        while (temp != nullptr) {
            int wordsCount = 0;
            Node* wordNode = temp->next;
            while (wordNode != nullptr) {
                wordsCount++;
                wordNode = wordNode->next;
            }
            if (wordsCount > 0) {
                total += wordsCount;
                cout << "Total words starting with the letter " << temp->data << ": " << wordsCount << endl;
            }
            temp = temp->next;
        }
        cout << "\nTotal number of words in the list: " << total << endl;
    }

    ~WordList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    WordList wordList;
    string word;
    cout << "Enter words (type 'exit' to exit):" << endl;
    while (true) {
        cout << "Enter a word: ";
        cin >> word;
        if (word == "exit") {
            break;
        }
        wordList.insertWord(word);
    }
    wordList.displayWords();
    wordList.displayCount();

    return 0;
}
