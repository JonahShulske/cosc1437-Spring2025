#include <iostream>
#include <string>
#include "vector.h"
using namespace std;
//using namespace cosc1437;

void OutputVector(cosc1437::Vector<string>& vec);

int main()
{
    cosc1437::Vector<string> vec;
    string stuff[15] {"Red", "Green", "Blue", "Yellow", "Magenta", "Cyan", "Pink", "Black", "White", "Navy", "Orange", "Purple", "Brown", "Grey", "Tan"};

    int capacity = 0;
    for (int index {0}; index < 15; ++index)
    {
        if (capacity != vec.GetCapacity())
        {
            capacity = vec.GetCapacity();
            std::cout << index << " size: " << vec.GetSize() << ", capacity: " << vec.GetCapacity() << endl;
        }
        vec.Add(stuff[index]);
    }

    OutputVector(vec);
    cout << endl;

    string color;
    std::cout << "Enter a color: ";
    getline(cin, color);
    vec.Add(color);
    cout << "\n" << endl;

    OutputVector(vec);
    cout << endl;

    vec.Remove();
    vec.Remove();
    OutputVector(vec);
    cout << endl;

    std::cout << "The size of our vector is: " << vec.GetSize() << endl;
    std::cout << "The capacity of our vector is: " << vec.GetCapacity() << endl;

}

void OutputVector(cosc1437::Vector<string>& vec)
{
    int count = 0;
    for (cosc1437::Vector<string>::size_type index {0}; index < vec.GetSize(); ++index)
    {
        std::cout << vec.At(index) << " ";
        count++;
        if (count % 10 == 0)
            cout << endl;
    }
}
