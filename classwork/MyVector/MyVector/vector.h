#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdexcept>
#include <iostream>
#include <string>

namespace cosc1437
{
    template<class T>
    class Vector
    {
        public:
            using size_type = unsigned long;
            using iterator = T*;
            using const_iterator = const T*;

        private:
            size_type size;
            size_type capacity;
            T& pElems;
            void CheckSize();

        public:
            // Constructor
            Vector<T>();
            Vector<T>(size_type capacity);
            Vector<T>(size_type capacity, T val);

            // Copy Constructor
            Vector<T>(const Vector<T>& rhs);

            // Destructor
            virtual ~Vector<T>();

            // Overloaded Operators
            Vector<T>& operator=(const Vector<T>& rhs);
            Vector<T>& operator[](const int index);
            Vector<T>& operator+(const Vector<T>& rhs);
            Vector<T>& operator+(const T& rhs);
            bool operator==(const Vector<T>& rhs);
            bool operator!=(const Vector<T>& rhs);
            //friend std::ostream& operator<<(std::ostream& outprint, const Vector<T> rhs);       // I use "outprint" instead of "out". Make sure to change this if you follow the instructor's code

            // Getters
            int GetSize() const;
            int GetCapacity() const;

            // Other Methods
            T Add(const T elem);            // Add element to end of vector
            T Remove();                     // Remove the last element in vector
            T& At(const int index);         // Return or set the element at position in vector
            bool Contains(const T elem);    // Is elem already in vector
            bool IsEmpty();
            void Clear();

            // Iterator Methods
            iterator Begin() { return pElems; }
            const_iterator Begin() const { return pElems; }
            iterator End() { return &pElems[size]; }
            const_iterator End() const { return &pElems[size]; }
    };

    // This is a private method
    template<class T>
    inline void Vector<T>::CheckSize()
    {
        // Check if array is large enough to add another element
        if (size < capacity)    // Good
            return;
        
        if (size >= capacity)   // Resize capacity
            capacity *= 2;

        // Create new array of type T with capacity
        T* temp = new T[capacity];

        // Copy elements in pElem to temp
        for (size_type index {0}; index < size; ++index)        // Make sure to change "index" to "i" if you are following the instructor's code
            temp[index] = pElems[index];

        // Delete pElems so there's no memory leaks
        if (pElems)
            delete[] pElems;

        // Assign value of temp to pElems
        pElems = temp;
    }

    // Constructor
    template<class T>
    inline Vector<T>::Vector() : Vector<T>(10) {}

    template<class T>
    inline Vector<T>::Vector(size_type capacity) : size(0)
    {
        if (capacity < 1)
            throw std::runtime_error("Error: Cannot create a vector of less than 1 capacity");

        if (capacity < 10)  // Just make the capacity 10 anyway
            capacity = 10;

        this->capacity = capacity;
        pElems = new T[capacity];
    }

    template<class T>
    inline Vector<T>::Vector(size_type capacity, T val) : Vector<T>(capacity * 2), size(capacity) 
    {
        for (size_type index {0}; index < size; ++index)        // Make sure to change "index" to "i" if you are following the instructor's code
            pElems[index] = val;
    }

    // Copy Constructor
    template<class T>
    inline Vector<T>::Vector(const Vector<T>& rhs) : Vector<T>(rhs.capacity)
    {
        this->size = rhs.size;
        for (size_type index {0}; index < size; ++index)         // Make sure to change "index" to "i" if you are following the instructor's code
            pElems[index] = rhs.pElem[index];
    }

    // Destructor
    template<class T>
    inline Vector<T>::~Vector()
    {
        if (pElems)
            delete[] pElems;
    }

    // Overloaded Operators
    template<class T>
    inline Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
    {
        if (pElems)     // Deleting and replacing what's in the vector
            delete[] pElems;

        size = rhs.size;
        capacity = rhs.capacity;
        pElems = new T[capacity];

        for (size_type index {0}; index < size; ++index)        // Make sure to change "index" to "i" if you are following the instructor's code
            pElems[index] = rhs.pElems[index];

        return *this;
    }

    template<class T>
    inline Vector<T>& Vector<T>::operator[](const int index) 
    { 
        return pElems[index]; 
    }

    template<class T> // v1 + v2 => v3
    inline Vector<T>& Vector<T>::operator+(const Vector<T>& rhs)
    {
        Vector<T> tempVec = *this;
        for (size_type index {0}; index < rhs.size; ++index)    // Make sure to change "index" to "i" if you are following the instructor's code
            tempVec.Add(rhs.pElems[index]);

        return tempVec;
    }

    template<class T>   // v3 = v1 + T, which is the same as v3 = v1 or v3.Add(T)
    inline Vector<T>& Vector<T>::operator+(const T & rhs)   
    {
        Vector<T> tempVec = *this;
        tempVec.Add(rhs);

        return tempVec;
    }

    template<class T>
    inline bool Vector<T>::operator==(const Vector<T>& rhs)
    {
        if (size != rhs.size)
            return false;

        for (size_type index {0}; index < size; ++index)         // Make sure to change "index" to "i" if you are following the instructor's code
            if (pElems[index] != rhs.pElems[index])
                return false;

        return true;
    }

    template<class T>
    inline bool Vector<T>::operator!=(const Vector<T>& rhs)     // The exact opposite of the other operator
    {
        return (!operator==(rhs));
    }

    // Getters
    template<class T>
    inline int Vector<T>::GetSize() const
    {
        return size;
    }

    template<class T>
    inline int Vector<T>::GetCapacity() const
    {
        return capacity;
    }

    // Other Methods
    template<class T>
    inline T Vector<T>::Add(const T elem)       // Essentially the same thing as push_back on a regular vector
    {
        CheckSize();
        pElems[size] = elem;
        size++;

        return elem;
    }

    template<class T>
    inline T Vector<T>::Remove()        // Same as pop_back on a regular vector
    {
        if (size == 0)
            throw std::runtime_error("Error: Cannot remove an element from an empty vector");
        T temp = pElems[size - 1];
        size--;     /* Technically doesn't delete the element, but it removes the index from the array, "deleting" the element
                       [0 1 2 3 4] size = 5, last_index = 4             [0 1 2 3 4] size = 4, last_index = 3
                    */

        return temp;
    }

    template<class T>
    inline T & Vector<T>::At(const int index)
    {
        if (index < 0 || index >= size)
            throw std::runtime_error("Error: Index out of bounds, size is " + std::to_string(size));

        return operator[](index);
    }

    template<class T>
    inline bool Vector<T>::Contains(const T elem)
    {
        for (auto e : pElems)
            if (elem == e)
                return true;

        return false;
    }

    template<class T>
    inline bool Vector<T>::IsEmpty()
    {
        return size == 0;
    }

    template<class T>
    inline void Vector<T>::Clear()
    {
        size = 0;
    }

    /*template<class T>
    std::ostream& operator<<(std::ostream & outprint, const Vector<T> rhs)    // I use "outprint" instead of "out". Make sure to change this if you follow the instructor's code
    {
        outprint << "[ ";
        for (Vector<T>::size_type index {0}; index < GetSize(); ++index)       // Make sure to change "index" to "i" if you are following the instructor's code
            outprint << pElems[index] << " ";
        outprint << "]";
        return outprint;
    } */

}


#endif // !_VECTOR_H_
