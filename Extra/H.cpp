#include <iostream>
using namespace std;

class Singly_Node {
public:
    string word;
    Singly_Node* next;
    Singly_Node() : next(NULL) {}
};

class Doubly_Node {
public:
    char alphabet;
    Singly_Node* link;
    Doubly_Node* next;
    Doubly_Node* prev;
    Doubly_Node() : link(NULL), next(NULL), prev(NULL) {}
};

class Linked_List {
public:
    Doubly_Node* head;
    Linked_List() : head(NULL) {
        for (char c = 'a'; c <= 'z'; c++) {
            Doubly_Node* newNode = new Doubly_Node();
            newNode->alphabet = c;
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
        }
    }

    void insert_word(string word) {
        char first_letter = word[0];
        Doubly_Node* temp = head;
        while (temp != NULL) {
            if (temp->alphabet == first_letter) {
                Singly_Node* newWord = new Singly_Node();
                newWord->word = word;
                newWord->next = temp->link;
                temp->link = newWord;
                return;
            }
            temp = temp->next;
        }
    }
    void display_words() {
        Doubly_Node* temp = head;
        while (temp != NULL) {
            if (temp->link != NULL) {
                cout << "Words starting with the letter " << temp->alphabet << ": ";
                Singly_Node* wordNode = temp->link;
                while (wordNode != NULL) {
                    cout << wordNode->word << ", ";
                    wordNode = wordNode->next;
                }
                cout << endl;
            }
            temp = temp->next;
        }
    }
    void display_count() {
        int total = 0;
        Doubly_Node* temp = head;
        while (temp != NULL) {
            int words_count = 0;
            Singly_Node* wordNode = temp->link;
            while (wordNode != NULL) {
                words_count++;
                wordNode = wordNode->next;
            }
            if (words_count > 0) {
                total += words_count;
                cout << "Total words starting with the letter " << temp->alphabet << ": " << words_count << endl;
            }
            temp = temp->next;
        }
        cout << "\nTotal number of words in the list: " << total << endl;
    }
};

int main() {
    Linked_List list;
    string word;
    cout << "Enter words (type 'exit' to exit):" << endl;
    while (true) {
        cout << "Enter a word: ";
        cin >> word;
        if (word == "exit") {
            break;
        }
        list.insert_word(word);
    }
    list.display_words();
    list.display_count();

    return 0;
}
