#include <iostream>
using namespace std;

int main(){
	 const int size = 8;
	int avgArr[size] = {69,69,35,85,45,69,75,69};
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += avgArr[i];
	}
	cout << "The average of the array is: " << sum / size << endl;
	cout << "The sum of the array is: " << sum << endl;
	cout << "The size of the array is: " << size << endl;
return 0;
}