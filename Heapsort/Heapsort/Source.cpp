
#include <iostream> 
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	string text;
	int * arr;
	const int n = 90025;
	arr = new int[n];
	int i = 0;

	ifstream MyReadFile("10000000.txt"); //read input file
	for (int i = 0; i < n; i++) {
		MyReadFile >> arr[i];   //fill array with numbers from file
	}
	MyReadFile.close();

	//reading file and print
	//while (getline(MyReadFile, text)) {
	//	cout << text;
	//}
	
	auto start = chrono::high_resolution_clock::now();//start counting time
	heapSort(arr, n);//sorting
	//delete[] arr;
	auto finish = chrono::high_resolution_clock::now();//end counting time

	chrono::duration<double> elapsed = finish - start;//whole time that tooks from start to finish

	/*for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/
	cout << "\nfor 100000 elements it needs: " << elapsed.count() << " seconds";
	
	
	ofstream myFile("Sorted90025.txt");//create file where will write sorted nums
	for (int i = 0; i < n; i++) {
		myFile << arr[i]<<" ";  //writing
	}
	delete[] arr;
	myFile.close();
}
