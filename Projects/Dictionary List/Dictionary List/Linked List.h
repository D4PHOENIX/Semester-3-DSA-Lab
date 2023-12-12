#include "Node.h"
using namespace std;

// AlphabetLinkedList class which contains alphabets and words starting with that alphabet
class AlphabetLinkedList
{
private:
    AlphabetNode* head;
public:
    // constructor which initializes the linked list with alphabets
    AlphabetLinkedList() : head(nullptr)
	{
        // Initialize the linked list with alphabets
        head = new AlphabetNode('a');
        AlphabetNode* temp = head;
        for (char c = 'b'; c <= 'z'; c++) 
        {
            AlphabetNode* newNode = new AlphabetNode(c);
            newNode->prev = temp;
            temp->next = newNode;
            temp = newNode;
        }
    }
    // destructor
    ~AlphabetLinkedList()
	{
        while (head != nullptr) 
        {
            AlphabetNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // inserts a word with its respective alphabet the linked list
    void insertWord(string& word)
	{
		char firstLetter = tolower(word[0]);
		AlphabetNode* temp = head;
		while (temp != nullptr) 
        {
			if (temp->letter == firstLetter) 
            {
				temp->insertWord(word);
				return;
			}
			temp = temp->next;
		}
    }

    // deletes a word from the linked list
    void deleteWord(string& word)
    {
    	char firstLetter = tolower(word[0]);
		AlphabetNode* temp = head;
		while (temp != nullptr) 
        {
			if (temp->letter == firstLetter) 
            {
				temp->deleteWord(word);
				return;
			}
			temp = temp->next;
		}
    }

    // displays the words in the linked list
    void displayWords()
	{
        AlphabetNode* temp = head;
        while (temp != nullptr) 
        {
            cout << "Words starting with " << temp->letter << ": ";
            WordNode* wordNode = temp->wordsHead;
            while (wordNode != nullptr) 
            {
                cout << wordNode->word << " ";
                wordNode = wordNode->next;
            }
            cout << endl;
            temp = temp->next;
        }
    }

    // displays the number of words in the linked list
    void displayStats() {
        int totalWords = 0;
        AlphabetNode* temp = head;
        while (temp != nullptr) {
            int wordsCount = temp->countWords();
            totalWords += wordsCount;
            cout << "Total words starting with " << temp->letter << ": " << wordsCount << endl;
            temp = temp->next;
        }
        cout << "\n----------------------------------------"<<endl;
        cout << "\nTotal number of words: " << totalWords << endl;
    }
};