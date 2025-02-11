/* Jonah Shulske
 * 2/11/25
 * PointerProgram, movielist.cpp
 * COSC-1437 Spring 2025
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;  // I use std:: for cout whenever it's something the user will actually see/interact with.

const string FILE_NAME = "moviecount.txt";

int ReadMovieData(int*& Movies, string fileName);
int ReadMovieData(int** Movies, string fileName);
double CalculateAverage(int* Movies, int Size);
double CalculateMedian(int* Movies, int Size);
int* CalculateMode(int* Movies, int Size, int& numModes);
void Sort(int*& Movies, int Size);
void Swap(int* A, int* B);

int main()
{
    int numStudents;
    int* movieCounts = nullptr;

    try
    {
        numStudents = ReadMovieData(&movieCounts, FILE_NAME);
    } catch (const char* Message)
    {
        cout << Message << endl;
        system("ERROR");
        exit(EXIT_FAILURE);
    }

    cout << setprecision(2) << fixed << showpoint;

    std::cout << "The total number of students who watched movies is: " << numStudents << endl;
    std::cout << "The average number of movies watched by all students is: " << CalculateAverage(movieCounts, numStudents) << endl;
    std::cout << "The median number of movies watched by all students is: " << CalculateMedian(movieCounts, numStudents) << endl;

    int numModes = 0;
    int* Modes = CalculateMode(movieCounts, numStudents, numModes);
    std::cout << "The mode number of movies watched by all students is: ";
    if (numModes >= 1)
        std::cout << Modes[0];
    for (int index = 0; index < numModes; index++)
        std::cout << ", " << Modes[index];
    cout << "\n" << endl;

    return 0;
}

int ReadMovieData(int *& Movies, string fileName)
{

    return 0;
}

int ReadMovieData(int ** Movies, string fileName)
{
    return 0;
}

double CalculateAverage(int * Movies, int Size)
{
    return 0.0;
}

double CalculateMedian(int * Movies, int Size)
{
    return 0.0;
}

int * CalculateMode(int * Movies, int Size, int & numModes)
{
    return nullptr;
}

void Sort(int *& Movies, int Size)
{}

void Swap(int * A, int * B)
{}
