#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/* Jonah Shulske
 * Lecture 2 Notes
 * 2/19/25
 */

// FILES

/* Section 1 - What are Files in General?
 * 
 * A file is a named byte stream, stored on disk, with a starting location and a length.
 * It serves as a means to store data persistently, allowing programs to read from or write to them even after the program has stopped running.
 * Files can be classified into 2 types. 
 * Text Files - Human readable files, usually containing characters encoded in a specific format (ASCII, UTF-8, etc.)
 * Binary Files - Files containing data in a format specific to the program, but not directly human readable.
 */

/* Section 2 - Text Files in C++
 * 
 * Text files are files that contain data encoded as a sequence of characters.
 * Examples include .txt, .csv, and .html files. 
 * They're structured using line breaks and spaces to separate different elements, making them easy to read with standard text editors.
 * Opening a text file: Use the ifstream (input file stream) class to read from a text file ofstream (output file stream) class to write to a text file.
 * Always close the file using .close() after operations to avoid data loss and to free up resources.
 */

// WRITING TO A TEXT FILE
// 
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//    // Create an output file stream
//    /*(std::)*/ ofstream outFile("Example.txt");
//
//    if (outFile.is_open())
//    {
//        outFile << "Hello, World!" << endl;
//        outFile << "This is a text file" << endl;
//        outFile.close();
//        std::cout << "Data is written to the file successfully" << endl;
//    } else
//        /*std::*/ cerr << "Unable to open file for writing" << endl;
//
//    return 0;
//}

// READING FROM A TEXT FILE
// 
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    // Create an input file stream
//    /*std::*/ ifstream inFile("Example.txt");
//    string Line;
//
//    if (inFile.is_open())
//    {
//        while (getline(inFile, Line))
//            std::cout << Line << endl;
//
//        inFile.close();
//    } 
//    else
//        cerr << "Unable to open file for reading" << endl;
//
//    return 0;
//}

/* Section 3 - Binary Files in C++
 *
 * Binary files contain data in a format that is directly understandable by a computer's hardware.
 * They store data in its native binary form, allowing for efficient storage and faster access compared to text files.
 * Common examples include images, executables, and serialized objects.
 * 1. Opening a binary file: Use ios::binary mode in combination with ifstream and ofstream to work with binary files.
 */

// WRITING TO A BINARY FILE
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//struct Data
//{
//    int ID;
//    double Value;
//};
//
//int main()
//{
//    // Open file in binary mode
//    ofstream outFile("data.bin", std::ios::binary);
//
//    if (outFile.is_open())
//    {
//        Data D = {1, 123.45};
//        // Write binary data
//        outFile.write(reinterpret_cast<char*>(&D), sizeof(D));
//        outFile.close();
//        std::cout << "Data written to binary file successfully" << endl;
//    } else
//        cerr << "Unable to open file for writing" << endl;
//
//    return 0;
//}

// READING FROM A BINARY FILE
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//struct Data
//{
//    int ID;
//    double Value;
//};
//
//int main()
//{
//    // Open file in binary mode
//    ifstream inFile("data.bin", ios::binary);
//
//    if (inFile.is_open())
//    {
//        Data D;
//        // Read binary data
//        inFile.read(reinterpret_cast<char*>(&D), sizeof(D));
//        inFile.close();
//
//        std::cout << "ID: " << D.ID << "Value: " << D.Value << endl;
//    } 
//    else
//        cerr << "Unable to open file for reading";
//
//    return 0;
//}

/* Section 4 - Differences Between Text Files and Binary Files
 *
 * Aspect                  Text Files                                      Binary Files
 * Human Readable           Yes                                             No
 * Size                     Generally larger due to character encoding      Generally smaller (compact binary format)
 * Speed                    Slower to read/write (parsing required)         Faster (direct memory read/write)
 * Data Integrity           May lose precision (floating-point, etc.)       Preserves exact binary representation
 * Access Methods           Line-by-line, character-by-character            Block or structure based
 * 
 * Practical Use Cases:
 * Text Files: Good for configuration files, logs, or simple data storage where readability is needed.
 * Binary Files: Suitable for complex data storage, images, or when file size and speed are crucial.
 */