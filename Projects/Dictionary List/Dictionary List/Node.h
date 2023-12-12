using namespace std;

// WordNode is a class of node in a linked list of words
class WordNode
{
public:
    string word;
    WordNode* next;
    WordNode(string w)
	{
        word = w;
        next = nullptr;
    }
};

// AlphabetNode is a class of node in a linked list of letters
class AlphabetNode
{
public:
    char letter;
    WordNode* wordsHead;
    AlphabetNode* next;
    AlphabetNode* prev;
    // constructor
    AlphabetNode(char c)
	{
        letter = c;
        wordsHead = nullptr;
        next = nullptr;
        prev = nullptr;
    }  

    // insertWord inserts the word into the linked list of words
    void insertWord(string& w)
	{
        WordNode* newWord = new WordNode(w);
        newWord->next = wordsHead;
        wordsHead = newWord;
    }

    // deleteWord deletes the word from the linked list of words
    void deleteWord(string& w)
	{
        WordNode* temp = wordsHead;
        WordNode* prev = nullptr;

        while (temp != nullptr) 
        {
            if (temp->word == w)
            {
                if (prev != nullptr) 
                {
                    prev->next = temp->next;
                }
                else 
                {
                    wordsHead = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // countWords returns the number of words in the linked list of words
    int countWords()
	{
        int count = 0;
        WordNode* temp = wordsHead;
        while (temp != nullptr) 
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};