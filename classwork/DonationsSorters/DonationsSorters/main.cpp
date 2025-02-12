/* Jonah Shulske
 * COSC-1437 Spring 2025 DonationSorters  
 * 2/10/25
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function declarations
void SelectionSort(int** ptrToElememts, int Size);
void DisplayDonations(int* Donations, int Size);
void DisplaySortedDonations(int** ptrToElements, int Size);
int* GetDonations(string fileName, int& numDonations);
int** CreatePtrArray(int* Donations, int Size);
const string FILE_NAME = "donations.txt";

int main()
{
    int numDonations = 0;   // Number of donations
    int* Donations = nullptr;  // Dynamic array

    // Create an array to hold the donations, then get donations

    try
    {
        Donations = GetDonations(FILE_NAME, numDonations);
    }
    catch (const char* msg)
    {
        std::cout << msg << endl;
        exit(EXIT_FAILURE);
    }
    catch (...)     // Catch all. Always do this at the end so that it doesn't catch what is declared as ok
    {
        std::cout << "How did you get here?" << endl;
        exit(EXIT_FAILURE);
    }

    // Create an array of pointers to ints
    int** ptrDonations = CreatePtrArray(Donations, numDonations);

    // Sort the donations
    SelectionSort(ptrDonations, numDonations);

    // Display the donations in original order
    cout << endl;
    std::cout << "Donations before being sorted:" << endl;
    DisplayDonations(Donations, numDonations);

    // Display the sorted donations
    cout << endl;
    std::cout << "Donations after being sorted:" << endl;
    DisplaySortedDonations(ptrDonations, numDonations);

    delete[] Donations;
    delete[] ptrDonations;

    return 0;
}

void SelectionSort(int** ptrToElements, int Size)
{
    int startIndex; // Where do we start searching from?
    int minIndex; // Which index contains the smallest number so far?
    int* ptrMinElements;    // Point to the address with the smallest value

    for (startIndex = 0; startIndex < (Size - 1); ++startIndex)
    {
        minIndex = startIndex;
        ptrMinElements = ptrToElements[minIndex];    /* ptrMinElements = *(ptrToElements + ptrMinElements);*/

        for (int index = (startIndex + 1); index < Size; ++index)
        {
            if (*ptrToElements[index] < *ptrMinElements) /* (**(ptrToElements + index) < *ptrMinElements);*/
            {
                ptrMinElements = ptrToElements[index];      /* ptrMinElements = *(ptrToElements + index);*/
                minIndex = index;
            }

        }   // Inner for loop

        // Swap the new min value with startIndex value
        ptrToElements[minIndex] = ptrToElements[startIndex];    /* *(ptrToElements + minIndex) = *(ptrToElements + startIndex);*/
        ptrToElements[startIndex] = ptrMinElements;     /* *(ptrToElements + startIndex) = ptrMinElements;*/

    }   // Outer for loop
}

void DisplayDonations(int* Donations, int Size)
{
    for (int index = 0; index < Size; ++index)
    {
        std::cout << Donations[index] << endl;  // *(Donations + index)
    }
}

void DisplaySortedDonations(int** ptrToElements, int Size)
{
    for (int index = 0; index < Size; ++index)
    {
        std::cout << *ptrToElements[index] << endl; // std::cout << *(*(ptrToElements + index)) << endl;
    }
}

int* GetDonations(string fileName, int& numDonations)
{
    // Open the file
    ifstream ogFile(fileName);
    if (!ogFile)
        throw "Cannot open file " + fileName;

    // Get the first integer which is the number of remaining integers (if not lied to by user)
    ogFile >> numDonations;

    // Create a dynamic array the size of numDonations
    int* arr = new int[numDonations];

    // Read the file into the array
    for (int index = 0; index < numDonations; ++index)
    {
        ogFile >> arr[index];    // ogFile >> *(arr + index); works as well
    }

    /* // Test the input
    for (int index = 0; index < numDonations; ++index)
    {
        std::cout << arr[index] << " ";
    }

    cout << endl;
    */

    return arr;
}

int** CreatePtrArray(int* Donations, int Size)
{
    int** ptrArray = new int* [Size];

    for (int index = 0; index < Size; ++index)
    {
        // Value of ptrArray at index and the Address of Donations at index
        ptrArray[index] = Donations + index;    // *(ptrArray + index) = Donations + index;
    }


    return ptrArray;
}
