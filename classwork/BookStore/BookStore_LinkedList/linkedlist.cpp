#include "linkedlist.h"
#include <stdexcept>


LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::LinkedList(dataType data) : LinkedList()
{
    AddToFront(data);
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList & rhs)
{
    Node* curr = rhs.head;
    while (curr != nullptr)
    {
        this->AddToRear(curr->GetData());
        curr = curr->GetNext();
    }
}

LinkedList LinkedList::operator=(const LinkedList & rhs)
{
    // Clear this list
    while (!IsEmpty())
    {
        RemoveFromFront();
    }

    // Copy the data from the rhs to this linked list (lhs)
    Node* curr = rhs.head;
    while (curr != nullptr)
    {
        this->AddToRear(curr->GetData());
        curr = curr->GetNext();
    }
    return *this;
}

LinkedList::~LinkedList()
{
    // Clear this list
    while (!IsEmpty())
        RemoveFromFront();
}

// Add a node to the front of the list
void LinkedList::AddToFront(dataType data)
{
    // Build a node with the data. Dynamically allocate memory for the node
    Node* node = new Node(data);

    // Check if list is empty
    if (head == nullptr)
    {
        // List is empty
        head = node;
        tail = node;
    }
    else
    {
        // List isn't empty. Place node in front of head
        node->SetNext(head);
        head = node;
    }
    size++;
}

void LinkedList::AddToRear(dataType data)
{
    // Buils a node to store data
    Node* node = new Node(data);

    // Check if list is empty
    if (head == nullptr)
    {
        // List is empty
        head = node;
        tail = node;
    }
    else
    {
        // Place node after node
        tail->SetNext(node);
        tail = node;
    }
    size++;
}

void LinkedList::AddAt(dataType data, int pos)
{
    // Add the node in front of pos. If pos == size, add at the end. Validate pos
    if (pos < 0 || pos > size)
        throw std::invalid_argument("Error: Position Out of Range");
    
    if (pos == 0)
        AddToFront(data);
    else if (pos == size)
        AddToRear(data);
    else
    {
        // Add somewhere in middle. Get a pointer to node before
        Node* prev = GetNodeAtPosition(pos - 1);
        if (prev == nullptr || prev->GetNext() == nullptr)
            throw std::runtime_error("Fehler: Was zum Teufel ist los mit dir?");

        // Get a pointer to the node inserting at
        Node* curr = prev->GetNext();
        Node* node = new Node(data);
        node->SetNext(curr);
        prev->SetNext(node);
        size++;
    }
}

dataType LinkedList::GetFromFront() const
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Get Data From Empty List");

    return head->GetData();
}

dataType LinkedList::GetAtRear() const
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Get Data From Empty List");

    return tail->GetData();
}

dataType LinkedList::GetAt(int pos) const
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Get Data From Empty List");
    
    if (pos < 0 || pos > size)
        throw std::invalid_argument("Error: Position Out of Range");

    Node* curr = GetNodeAtPosition(pos);
    return curr->GetData();
}

void LinkedList::SetFront(dataType data)
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Set Data In Empty List");
    head->SetData(data);
}

void LinkedList::SetRear(dataType data)
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Set Data In Empty List");
    tail->SetData(data);
}

void LinkedList::SetAt(dataType data, int pos)
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Get Data From Empty List");

    if (pos < 0 || pos > size)
        throw std::invalid_argument("Error: Position Out of Range");

    Node* curr = GetNodeAtPosition(pos);
    curr->SetData(data);
}

dataType LinkedList::RemoveFromFront()
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Remove Data From Empty List");

    dataType data = head->GetData();    // Get the Data From the Node

    Node* temp = head;      // Declare Pointer to Node and Point Node to Head

    head = head->GetNext();     // Move Head to Next Node

    // Break Link from First Node and Return Allocated Memory to OS
    temp->SetNext(nullptr);
    delete temp;

    if (head == nullptr)    // Will only happen with a one node list
        tail = head;
    size--;

    return data;
}

dataType LinkedList::RemoveFromRear()
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Remove Data From Empty List");

    dataType data = tail->GetData();
    if (head == tail)  // Only have one node
    {
        delete head;    // Releases alllocated memory
        head = tail = nullptr;
    }
    else    // Find the node before the tail in order to remove tail
    {
        Node* prev = GetNodeAtPosition(size - 2);
        if (prev == nullptr)
            throw std::runtime_error("Error: Previous Node Cannot be Null");

        prev->SetNext(nullptr);
        delete tail;
        tail = prev;
    }
    size--;

    return data;
}

dataType LinkedList::RemoveAt(int pos)
{
    if (IsEmpty())
        throw std::runtime_error("Error: Cannot Remove Data From Empty List");

    if (pos < 0 || pos > size)
        throw std::invalid_argument("Error: Position Out of Range");

    if (pos == 0)       // User somehow made it to the wrong function
        return RemoveFromFront();
    else if (pos == size - 1)
        return RemoveFromRear();


    Node* prev = GetNodeAtPosition(pos - 1);
    if (prev == nullptr)
        throw std::runtime_error("Error: Previous Node Cannot be Null");

    Node* curr = prev->GetNext();
    dataType data = curr->GetData();

    prev->SetNext(curr->GetNext());
    curr->SetNext(nullptr);

    delete curr;
    return data;
}

int LinkedList::GetSize() const
{
    return size;
}

bool LinkedList::IsEmpty() const
{
    return head == nullptr;
}

// Private Method
LinkedList::Node* LinkedList::GetNodeAtPosition(int pos) const
{
    // pos: 0 is head, size - 1 is tail
    Node* curr = head;

    for (int index = 0; curr != nullptr && index < pos; ++index)
        curr = curr->GetNext();

    return curr;
}

// Methods for class Node
LinkedList::Node::Node(dataType data) : Node(data, nullptr) {}

LinkedList::Node::Node(dataType data, Node* next) : data(data), next(next) {}

void LinkedList::Node::SetNext(Node* next)
{
    this->next = next;
}

LinkedList::Node* LinkedList::Node::GetNext() const
{
    return next;
}

void LinkedList::Node::SetData(dataType data)
{
    this->data = data;
}

dataType LinkedList::Node::GetData() const
{
    return data;
}
