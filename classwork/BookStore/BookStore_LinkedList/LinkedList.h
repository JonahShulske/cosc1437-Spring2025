#ifndef _LINKED_LIST_
#define _LINKED_LIST_
// #include "../BookStore_Vector/book.h"       // Would've included the vector's header file instead of just creating one like we did. If edited, then the vector one would be too
#include "book.h"

// typedef Book dataType; Same thing, but used on C and old versions of C++
using dataType = Book;  // Anywhere dataType is written, it'll let us use whatever variable type for the linked list

class LinkedList
{
    private:
        int size{};    // Start with 0 nodes
        class Node;    // Trust, there will be a node class
        Node* head{nullptr};   // Points to front of list
        Node* tail{nullptr};   // Points to end of list

        Node* GetNodeAtPosition(int pos) const;

    public:
        // Constructors
        LinkedList();   // Create an empty linked list
        LinkedList(dataType data);  // Create a one node list with data


        // Copy constructor, assignment override, destructor
        // The Big Three - If your class dynamically allocates memory, you always need to have these 3 methods
        LinkedList(const LinkedList& rhs);      // Copy Constructor
        LinkedList operator=(const LinkedList& rhs);    // Assignment
        virtual ~LinkedList();      // Destructor

        // Insertion methods
        void AddToFront(dataType data);
        void AddToRear(dataType data);
        void AddAt(dataType data, int pos);

        // Getters
        dataType GetFromFront() const;
        dataType GetAtRear() const;
        dataType GetAt(int pos) const;

        // Setters
        void SetFront(dataType data);
        void SetRear(dataType data);
        void SetAt(dataType data, int pos);

        // Deletion methods
        dataType RemoveFromFront();
        dataType RemoveFromRear();
        dataType RemoveAt(int pos);

        // Utility
        int GetSize() const;
        bool IsEmpty() const;

    private:
        class Node
        {
            private:
                dataType data;
                Node* next;
                
            public:
                Node(dataType data);
                Node(dataType data, Node* next);

                // Setters / Getters
                void SetNext(Node* next);   // Usually don't wanna return a pointer, but doing it here cause the only object that can access it is the LinkedList class
                Node* GetNext() const;
                void SetData(dataType data);
                dataType GetData() const;
        };


};





#endif _LINKED_LIST_