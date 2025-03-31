/* Jonah Shulske
 */

#include <iostream>
#include "computer.h"
using namespace std;

int main()
{
    try
    {
        CPU cpu1(8, 3.6);
        Monitor monitor1("1440p", 27.0);
        Computer pc1("PC1001", "ASUS", "ROG Strix", cpu1, monitor1);

        CPU cpu2(6, 4.0);
        Monitor monitor2("2160p", 32.0);
        Computer pc2("PC1002", "MSI", "MEG Trident", cpu2, monitor2);

        pc1.Print();
        pc2.Print();
    }
    catch (const exception& e)
    {
        std::cout << "Error: " << e.what() << endl;
    }
}