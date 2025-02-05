/* Jonah Shulske
 * Chapter 11 Notes - Pointers
 * 2/3/25 + 2/5/25
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/* Memory Review
* 
 * Primary memory in a computer is RAM
 * RAM is composedf of 8-bit cells. A nibble is 4 bits.
 * A bit (binary digit) is a 0 or 1.
 * Each cell in RAM has a unique ID called an address.
 * Except for char and bool types, data values are stored across multiple cells.
 * 
 * Negative integers are stored using Two's Complement Binary
 * To convert between negative-positive and positive-negative, invert all bits and add 1
 * An integer that begins with 0 is positive, and an int that begins with 1 is negative (when working with signed numbers)
 * Even though each int has 4 addresses, we only use either the first or last to id the location
 * Which one depends on the system architecture
 * A memory address is a numeric value composed of a string of bits like any other value.
 * Endianness - The order in which bytes within a word of digital data are transmitted over a data communication medium
 * All addresses in a system have the sane number of bits. This is the width or size of the address
 * 
 * 32 bit memory space -> 32 byte address
 * 2^32 possible addresses ~ (4,000,000,000) ~ 4.0x10^9
 * Requires 4 bytes of RAM to store an address.
 * 
 * 64 bit memory space -> 64 bit address
 * 2^64 possible addresses. ~1.84x10^19 ~ 18 Exabytes.
 * Requires 8 bytes of RAM to store an address. Can never store all the addresses at once in all gigs of RAM.
 * 
 * Stack Memory - Memory in RAM that is allocated to a program.
 * The stack memory (space) stores all the variables, instructions, and activation records all for a program.
 * 
 * Heap Memory - Any memory in RAM that is not currently allocated to a program is part of the heap.
 * A program can "borrow" memory from the heap.
 * 
 * Pointer - A data type for an address
 * A pointer variable is a variable that stores an address to some data type
 * int* pFoo = nullptr;     int is data type pointed to, * is pointer, pFoo is variable name
 * double* pTrouble = nullptr;
 * Both are the same width, as a pointer is the same number of bytes no matter what it points to
 * 
 * Address of operator &
 * int foo = 42;
 * int* pFoo = &foo
 * Store the address of foo in the pointer pFoo
 * Notice the foo is type int and pFoo is declared to store an address of type int.
 * 
 * Dereferencing (End Direction) - Obtaining the value stored in the variable being pointed to.
 * int foo = 42;
 * int& pFoo = &foo;
 * cout << *pFoo << endl;   Output: 42
 * *pFoo = 21;              Changes foo to: 21
 * cout << foo << endl;     Output: 21
 * --DO NOT WRITE CODE LIKE THIS--
 * 
 * Byte Sizes
 * Different data types are represented with a different number of bytes
 * 
 * Type         Size           # of Addresses
 * char          1 byte         1 address
 * bool
 * short         2 bytes        2 addresses
 * int           4 bytes        4 addresses
 * long
 * long long     8 bytes        8 addresses
 * float         4 bytes        4 addresses
 * double        8 bytes        8 addresses
 * long double   16 bytes       16 bytes
 * 
 * All pointers are the same width and can only store one address.
 * 
 * short bar = 42;
 * short* pBar = &bar;
 * int foo = 21;
 * int* pFoo = &foo;
 * 
 * All we store in the pointer is the address of the first byte.
 * That's why that data type pointer to is needed.
 * After we get to the first byte from the pointer, we need to know how many more bytes to use.
 * 
 * Void pointer (raw pointer/generic pointer) - Pointer that can point to any data type.
 * A void pointer simply stores the address of a single byte without an associated data type.
 * Useful when you need a pointer that can hold the address of any data type. 
 * Because they don't have a specific type, you can't directly dereference a void pointer or perform pointer arithmetic on it.
 * Must first cast it to another pointer type. Mostly used in C
 * 
 * void* pAny = nullptr;
 * int foo = 42;
 * pAny = &foo;    // Assigning one address to a one address location
 * cout << pAny;   // Ok, outputs the content of pAny
 * cout << *pAny   // Very bad. There's an address but no data type to get all the bytes.
 * cout << *(static_cast<int*>(pAny));  // Cast pAny to pointer to an int, then dereference
 * 
 * New Operator
 * The new operator makes a request to the OS to get memory from the heap
 * If memory access is successful, the new operator returns the address of the first byte of the allocated memory
 * If memory allocation is not successful, an exception is thrown.
 * int* ptr = nullptr;
 * ptr = new int;
 * *ptr = 42;
 * cout << *ptr << endl;
 * 
 * Delete Operator
 * The delete operator does NOT delete a pointer or an address.
 * It notifies the OS that the address contained in the pointer that the delete operator is referencing is no longer being used by the program and may be reclaimed
 * After a pointer is "deleted", the address stored in the pointer is still there, but no longer belongs to the program.
 * void makePtr (int val)
 * {
 *     int* p;
 *     p = new int;
 *     *p = value;
 * }  // memory
 * 
 * int main()
 * {
 *    int foo = 42;
 *    makePtr(foo);
 *    return 0;     // memory leak
 * }
 * 
 * Recode makePtr to remove memory leak
 * void makePtr(int val)
 * {
 *    int* p;
 *    p = new int;
 *    *p = val;
 *    delete p;     // No more memory leak
 * }
 * 
 * Another, and better way to do it
 * int* makePtr(int val)
 * {
 *    int* p = new int;
 *    *p = val;
 *    return p;
 * }
 * 
 * int main()
 * {
 *    int foo = 42;
 *    int* bar = makePtr(foo);
 *    delete bar;
 *    return 0;
 * }
 * 
 * Dynamic Array - Array whose size can be set at runtime. The size declarator is allowed to be a variable.
 * A pointer is required to build a dyanmic array
 * Dynamic array is almost as fast and spacially efficient as a static array
 * The size of a dynamic array cannot change after it's declared.
 * 
 * int numTeams;
 * string* teamNames;   // Scalar or array - Don't know yet at this part.
 * cout << "How many teams?"
 * cin >. numTeams; cin.ignore();
 * teamNames = new string[numTeams];
 * for (int index {0}; index < numTeams; ++index)
 * {
 *    getline(cin, teamNames[index]);
 * }
 * delete[] teamNames;
 * Notice [] for deleting dynamic array
 * 
 * Power Arithmetic - An integer can ge added or subtracted to or from a pointer. This results in a new memory location.
 * A pointer can be subtracted from another pointer of the same data type.
 * This results in the number of data type units between the two pointers.
 * 
 * int arr[5] {2, 4, 6, 8, 10};     // 20 bytes
 * int* p = nullptr;
 * p = arr;              // p stores address of first byte of arr
 * cout << arr << endl;  // Outputs address of first byte of arr
 * cout << p << endl;    // same as above
 * cout << arr[0] <<     // Outputs first element of arr
 * cout << *p << endl;   // Same as above
 * for (int index = 0; index < 5; ++index)
 * {
 *    cout << arr[index] << endl;
 *    cout << *(p + index) << endl;
 * }
 * Parentheses around (p + index) are needed because * binds more tightly than plus.
 * *p + 4 => 2 + 4 => 6
 * *(p + 4) => *(p pointed to element 4) => 10
 * 
 * Each element is 4 bytes
 * 
 * Pointers can be  and decremented.
 * ptr++ => ptr = ptr + 1
 * for (int* ptr = arr; ptr < arr + 5; ptr++)
 * {
 *    cout << *ptr << endl;
 * }
 * 
 * Linked List - Ordered, liner data structure
 * Linked lists are used to built other, more complex data structures (stacks, queues, deques, hash tables, etc.)
 * The building block of a linked list is the node
 * A node has at least 2 components. Data and a pointer to the next node (often called 'Next')
 * Head and tail are pointers to node. They are not nodes themselves.
 * A linked list node is self-referential
 *
 */



