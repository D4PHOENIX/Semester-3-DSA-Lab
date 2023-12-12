#include <iostream>
using namespace std;

class WordNode {
public:
    string word;
    WordNode* next;
    WordNode(string w) {
        word = w;
        next = nullptr;
    }
};

class AlphabetNode {
public:
    char letter;
    WordNode* wordsHead;
    AlphabetNode* next;
    AlphabetNode* prev;
    AlphabetNode(char c) {
        letter = c;
        wordsHead = nullptr;
        next = nullptr;
        prev = nullptr;
    }  

    void insertWord(const string& w) {
        WordNode* newWord = new WordNode(w);
        newWord->next = wordsHead;
        wordsHead = newWord;
    }

    void deleteWord(const string& w)
{
    WordNode* temp = wordsHead;
    WordNode* prev = nullptr;

    while (temp != nullptr) 
    {
        if (temp->word == w) {
            if (prev != nullptr) {
                prev->next = temp->next;
            }
            else {
                wordsHead = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
};

class AlphabetLinkedList {
private:
    AlphabetNode* head;
public:
    AlphabetLinkedList() : head(nullptr) {
        // Initialize the linked list with alphabets
        head = new AlphabetNode('a');
        AlphabetNode* temp = head;
        for (char c = 'b'; c <= 'z'; c++) {
            AlphabetNode* newNode = new AlphabetNode(c);
            newNode->prev = temp;
            temp->next = newNode;
            temp = newNode;
        }
    }


    ~AlphabetLinkedList() {
        while (head != nullptr) {
            AlphabetNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertWord(const string& word) {
		char firstLetter = tolower(word[0]);
		AlphabetNode* temp = head;
		while (temp != nullptr) {
			if (temp->letter == firstLetter) {
				temp->insertWord(word);
				return;
			}
			temp = temp->next;
		}
    }

    void deleteWord(const string& word)
    {
    	char firstLetter = tolower(word[0]);
		AlphabetNode* temp = head;
		while (temp != nullptr) {
			if (temp->letter == firstLetter) {
				temp->deleteWord(word);
				return;
			}
			temp = temp->next;
		}
    }

    void displayWords() {
        AlphabetNode* temp = head;
        while (temp != nullptr) {
            cout << "Words starting with " << temp->letter << ": ";
            WordNode* wordNode = temp->wordsHead;

            while (wordNode != nullptr) {
                cout << wordNode->word << " ";
                wordNode = wordNode->next;
            }
            cout << endl;

            temp = temp->next;  // Move to the next alphabet node
        }
    }

};

void clearScreen()
{
	cout << "\n Press any key to go back...";
	getchar();
	system("cls");
}

int main() {

    AlphabetLinkedList alphabetList;
	int choice;
	bool exit = false;
	string word;
	while (!exit)
	{
		cout << "1. Insert a word" << endl;
		cout << "2. Delete a word" << endl;
		cout << "3. Display all words" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		clearScreen();
		switch (choice)
		{
		case 1:
			cout << "Enter words (type 'exit' to stop):" << endl;
			while (true) {
				cout << "Enter a word to insert: ";
				cin >> word;
				if (word == "exit") {
					break;
				}
				alphabetList.insertWord(word);
			}
			clearScreen();
			break;
		case 2:
			cout << "Enter words (type 'exit' to stop):" << endl;
			while (true) {
				cout << "Enter a word to delete: ";
				cin >> word;
				if (word == "exit") {
					break;
				}
				alphabetList.deleteWord(word);
			}
			clearScreen();
			break;
		case 3:	
			alphabetList.displayWords();
			clearScreen();
			break;
		case 4:
			exit = true;
			clearScreen();
			break;
		default:
			cout << "Invalid choice" << endl;
			clearScreen();
		}
	}
	

return 0;
}