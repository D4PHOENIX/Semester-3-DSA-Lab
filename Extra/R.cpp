#include <iostream>
using namespace std;

class Node_Word {
public:
    string word;
    Node_Word* next;
    Node_Word(){
        next = NULL;
    }    
};

class Node_Letter {
public:
    char alphabet;
    Node_Word* wordsLink;
    Node_Letter* next;
    Node_Letter* prev;
    Node_Letter(){
        wordsLink = NULL; 
        next = NULL; 
        prev = NULL;
    }
};

class Word_List {
public:
    Node_Letter* head;
    Word_List() : head(NULL) {
        for (char c = 'a'; c <= 'z'; c++) {
            Node_Letter* newNode = new Node_Letter();
            newNode->alphabet = c;
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
        }
    }
    ~ Word_List() {
        while (head != NULL) {
            Node_Letter* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void wordInsert(string word) {
        char first_letter = word[0];
        Node_Letter* temp = head;
        while (temp != NULL) {
            if (temp->alphabet == first_letter) {
                Node_Word* newWord = new Node_Word();
                newWord->word = word;
                newWord->next = temp->wordsLink;
                temp->wordsLink = newWord;
                return;
            }
            temp = temp->next;
        }
    }
    void listDisplay() {
        Node_Letter* temp = head;
        while (temp != NULL) {
            if (temp->wordsLink != NULL) {
                cout << "Words with letter " << temp->alphabet << ": ";
                Node_Word* wordNode = temp->wordsLink;
                while (wordNode != NULL) {
                    cout << wordNode->word << " ";
                    wordNode = wordNode->next;
                }
                cout << endl;
            }
            temp = temp->next;
        }
    }
    void countDisplay() {
    int total = 0;
    Node_Letter* temp = head;
    while (temp != nullptr) {
        Node_Word* wordNode = temp->wordsLink;
        int wordsCount = 0;
        while (wordNode != nullptr) {
            wordsCount++;
            wordNode = wordNode->next;
        }
        if (wordsCount > 0) {
            total += wordsCount;
            cout << "Total words with letter " << temp->alphabet << ": " << wordsCount << endl;
        }
        temp = temp->next;
    }

    cout << "\nTotal number of words: " << total << endl;
}

};

int main() {
    Word_List list;
    string word;
    cout << "Enter words (type 'exit' to exit):" << endl;
    while (true) {
        cout << "Enter a word: ";
        cin >> word;
        list.wordInsert(word);
        if (word == "exit") {
            break;
        }
    }
    list.listDisplay();
    list.countDisplay();

    return 0;
}
