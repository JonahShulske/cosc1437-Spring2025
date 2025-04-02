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
            throw std::runtime_error("Error: Was zum Teufel ist los mit dir?");

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
    return dataType();
}

dataType LinkedList::RemoveFromRear()
{
    return dataType();
}

dataType LinkedList::RemoveAt(int pos)
{
    return dataType();
}

int LinkedList::GetSize() const
{
    return 0;
}

bool LinkedList::IsEmpty() const
{
    return false;
}

// Private Method
LinkedList::Node* LinkedList::GetNodeAtPosition(int pos) const
{
    return nullptr;
}

// Methods for class Node
LinkedList::Node::Node(dataType data)
{
}

LinkedList::Node::Node(dataType data, Node* next)
{
}

void LinkedList::Node::SetNext(Node* next)
{
}

LinkedList::Node* LinkedList::Node::GetNext() const
{
    return nullptr;
}

void LinkedList::Node::SetData(dataType data)
{
}

dataType LinkedList::Node::GetData() const
{
    return dataType();
}
