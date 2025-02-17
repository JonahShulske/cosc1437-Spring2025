/* Jonah Shulske
 * 2/11/25 + 2/15/25 + 2/16/25
 * PointerProgram, movielist.cpp
 * COSC-1437 Spring 2025
 */


// Included all required libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;  // I use std::cout whenever it's something the user will actually see/interact with.

// Global variable that reads the name of the used file
const string FILE_NAME = "moviecount.txt";

// Function prototypes

int ReadMovieData(int*& Movies, string fileName);
double CalculateAverage(int* Movies, int Size);
double CalculateMedian(int* Movies, int Size);
int* CalculateMode(int* Movies, int Size, int& numModes);
void Sort(int*& Movies, int Size);
void Swap(int* A, int* B);

//@brief Main function of program, allows program to run
int main()
{
    int numStudents;
    int* movieCounts = nullptr;


    // Making sure that the file is actually opened by the program
    try
    {
        numStudents = ReadMovieData(*&movieCounts, FILE_NAME);
    }
    catch (const char* Message)
    {
        cout << Message << endl;
        system("ERROR");
        exit(EXIT_FAILURE);
    }

    // Setting the precision of the output
    cout << setprecision(2) << fixed << showpoint;

    // Outputting results of all calculations
    std::cout << "The total number of students who watched movies is: " << numStudents << endl;
    std::cout << "The average number of movies watched by all students is: " << CalculateAverage(movieCounts, numStudents) << endl;
    std::cout << "The median number of movies watched by all students is: " << CalculateMedian(movieCounts, numStudents) << endl;

    // Sorting array for mode
    Sort(movieCounts, numStudents);

    int numModes = 0;
    int* Modes = CalculateMode(movieCounts, numStudents, numModes);

    // Printing out modes
    std::cout << "The mode number of movies watched by all students is: ";
    if (numModes >= 1 && Modes != nullptr)
    {
        std::cout << Modes[0];
        for (int index = 1; index < numModes; ++index)
            std::cout << ", " << Modes[index];
    }
    cout << "\n" << endl;


    // Deleting arrays so memory is freed
    delete[] movieCounts;
    delete[] Modes;

    return 0;
}


//@brief ReadMovieData - Reads the data from the file
//@param Movies - Pointer to the array of movie counts
//@return numStudents - Number of students in the array
int ReadMovieData(int*& Movies, string fileName)
{
    // Opening the file
    ifstream inputFile(fileName);

    // In the chance the file doesn't exist/open, an error is thrown
    if (!inputFile)
        throw "Error opening file: " + fileName;

    // Reading the number of students
    int numStudents;
    inputFile >> numStudents;

    // Allocating memory for the array of movie counts
    Movies = new int[numStudents];
    for (int index = 0; index < numStudents; ++index)
        inputFile >> Movies[index];

    inputFile.close();

    return numStudents;
}

//@brief CalculateAverage - Calculates the average of the movie counts
//@return - Returns calculation of average between Sum and Size variables
double CalculateAverage(int* Movies, int Size)
{
    if (Size == 0)
        return 0.0;

    double Sum = 0.0;
    for (int index = 0; index < Size; ++index)
        Sum += Movies[index];

    return (Sum / Size);
}

//@brief CalculateMedian - Calculates the median of the movie counts
//@return - Returns calculation of median between Movies and Size variables
double CalculateMedian(int* Movies, int Size)
{
    if (Size == 0)
        return 0.0;

    Sort(Movies, Size);

    if (Size % 2 == 1)
        return Movies[Size / 2];
    else
    {
        int mid1 = (Size / 2);
        int mid2 = mid1 - 1;
        return (Movies[mid1] + Movies[mid2]) / 2.0;
    }

}

//@brief CalculateMode - Calculates the mode of the movie counts
//@return - Returns calculation of mode between Movies and Size variables
int* CalculateMode(int* Movies, int Size, int& numModes)
{
    if (Size == 0)
    {
        numModes = 0;
        return nullptr;
    }

    int maxValue = *max_element(Movies, Movies + Size);

    int* Frequency = new int[maxValue + 1]();
    for (int index = 0; index < Size; ++index)
        Frequency[Movies[index]]++;

    int maxFrequency = 0;
    for (int index = 0; index <= maxValue; ++index)
        if (Frequency[index] > maxFrequency)
            maxFrequency = Frequency[index];

    numModes = 0;
    for (int index = 0; index <= maxValue; ++index)
        if (Frequency[index] == maxFrequency)
            numModes++;

    int* modeArray = new int[numModes];
    int modeIndex = 0;
    for (int index = 0; index <= maxValue; ++index)
        if (Frequency[index] == maxFrequency && modeIndex < numModes)
            modeArray[modeIndex++] = index;

  
    delete[] Frequency;
    return modeArray;
}

//@brief Sort - Sorts the array of movie counts
void Sort(int*& Movies, int Size)
{
    for (int index = 0; index < (Size - 1); ++index)
        for (int index2 = 0; index2 < (Size - index - 1); ++index2)
            if (Movies[index2] > Movies[index2 + 1])
                Swap(&Movies[index2], &Movies[index2 + 1]);
}

//@brief Swap - Swaps two integers
void Swap(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

