#include <iostream>
using namespace std;
const int maxitem = 20;
class ListofNum
{
private:
    int size;
    int item[maxitem];
public:
    ListofNum()
    {
        size = 0;
    }
    void count()
    {
        cout << "Values in List are " << size<<endl;
        
    }
    void add(int value)
    {
        if (size < 20)
        {
            item[size] = value;
            size++;
        }
    }
    void insert(int value, int pos)
    {
        if (size < 20 && pos >= 0 && pos <= size)
        {
            for(int i = size-1; i >= pos ; i--)
                item[i + 1] = item[i];
            item[pos] = value;
            size++;
        }
    }
    void retrieve(int pos)
    {
        if (pos >= 0 && pos < size)
        {
            cout << "Value on position " << pos << "is " << item[pos]<<endl;
        }
        else
            cout << "Position not found"<<endl;
    }
    void display()
    {
        cout << "Values in List are following ";
        for (int i = 0; i < size; i++)
            cout << item[i] << " ";
    }

};
int main()
{
    ListofNum is;
    is.add(10);
    is.add(20);
    is.add(30);
    is.add(40);
    is.count();
    is.display();
    is.retrieve(3);
    is.insert(60, 2);
    is.display();
    is.add(50);
    is.display();
    // is.itemdelete(2);
    cout << "After del the value" << endl;
    is.display();
    is.count();

}
