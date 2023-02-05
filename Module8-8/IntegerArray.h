//
//  IntegerArray.h
//  Module8-8
//
//  Created by Ольга Полевик on 13.07.2021.
//

#ifndef IntegerArray_h
#define IntegerArray_h

#include <iostream>
#include <cassert>
#include <exception>

using namespace std;

class BadLength : public exception
{
public:
    virtual  const char* what() const noexcept override
    {
        return "ERROR: wrong length.";
    }
};

class NotFound : public exception
{
public:
    virtual  const char* what() const noexcept override
    {
        return "ERROR: not found.";
    }
};

class BadRange : public exception
{
public:
    virtual  const char* what() const noexcept override
    {
        return "ERROR: out of range.";
    }
};

//class IntegerArray
template <typename X> class IntegerArray
{
private:
    int m_length = 0;
    X * m_data = nullptr;
    
public:
    IntegerArray() = default;
    IntegerArray(int length) : m_length (length)
    {
        if (length < 0)
        {
            throw BadLength();
        }
       // m_data = new int[length];
        m_data = new X [length];
    }
    
IntegerArray(const IntegerArray &that) : m_length (that.m_length)
    {
        //m_data = new int[m_length];
        m_data = new X[m_length];
        for (int index = 0 ; index < m_length ; ++index)
        {
            m_data[index] = that.m_data[index];
        }
    }
    
~IntegerArray()
    {
        delete[] m_data;
    }
    
    int find(X value)
    {
        for (int index = 0 ; index < m_length ; ++index)
        {
            if (m_data[index] == value)
            {
                return index;
            }
        }
        throw NotFound();
    }
    
    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    
   X& operator[](int index)
    {
        if (index < 0 || index >= m_length)
        {
            throw BadRange();
        }
        return m_data[index];
    }
     
    
    void reallocate (int newLength)
    {
        erase();
        if (newLength <= 0)
        {
            throw BadLength();
        }
        m_data = new X[newLength];
        m_length = newLength;
    }
    
//void insertBefore(int value, int index)
   void insertBefore (X value, int index)
    {
        if (index < 0 || index > m_length)
        {
            throw BadRange();
        }
        X *data = new X[m_length + 1];
        for (int before = 0; before < index; ++before)
        {
            data[before] = m_data[before];
        }
        data[index] = value;
        for (int after = index; after < m_length; ++after)
        {
            data[after + 1] = m_data[after];
        }
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    

int getLength() const
    {
        return m_length;
    }
  
//Добавлена функция изменения массива

    void resize (int newLength)
    {
        if (newLength == m_length)
        {
            return;
        }
           
        if (newLength <= 0)
        {
            throw BadLength();
        }
        
        X* data = new X [newLength];
        
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy ; ++index)
            {
                   data[index] = m_data[index];
            }
        }
    
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
};

#endif /* IntegerArray_h */
