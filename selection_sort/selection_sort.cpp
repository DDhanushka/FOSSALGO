#include <iostream>
#include <utility>      // for std::swap()

using namespace std;

void selectionSort(int array[], int length)
{
    for(int startIndex = 0; startIndex < length - 1; startIndex++)
    {
        // Assume that the first element is the smallest element so far we have encountered
        int smallestIndex = startIndex;

        for(int currentIndex = startIndex+1; currentIndex < length; currentIndex++)
        {
            // Find the smallest element
            if(array[smallestIndex] > array[currentIndex])
                smallestIndex = currentIndex;
        }
        // swap the smallest element with the first element
        swap(array[smallestIndex], array[startIndex]);
    }
}

void printArray(int array[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int inputL;
    cout << " Enter the number of integers you want to sort: ";
    cin >> inputL;

    // Initialize constant variable for fixed array length
    const int length { inputL };

    int array[length];

    // Get each element from the user
    cout << " Enter " << length << " space seperated integers:  ";
    for(int i = 0; i < length; ++i)
    {
        cin >> array[i];
    }

    cout << "\n*** Sorted array ***\n";
    selectionSort(array, length);
    printArray(array, length);
    cout << "\n\n";
}
