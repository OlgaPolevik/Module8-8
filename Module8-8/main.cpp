//
//  main.cpp
//  Module8-8
//
//  Created by Ольга Полевик on 13.07.2021.
//

#include <iostream>
#include "IntegerArray.h"

using namespace std;
 
int main()
{
    setlocale (LC_ALL,"");
    
    try
    {
        bool test_failed;
        
        //1.Проверка создания контейнера отрицательной длины
        
        try
        {
            test_failed = true;
            
            IntegerArray <int> arr_negative(-10);
        }
        catch (BadLength& e)
        {
            cout << e.what() << endl;
            test_failed = false;
        }
        if (!test_failed)
        {
            cout << "Тест на отрицательную длину контейнера пройден" << endl;
        }
       
        //2.Проверка правильного заполнения массива arr
        
        try
        {
            test_failed = false;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
                cout << arr[i];
            }
           
            for (int i = 0; i < arr.getLength(); ++i)
            {
                if( arr[i] != i + 1)
                {
                    throw exception();
                }
            }
        }
        catch (exception& e)
        {
            cout << "Тест на заполнение массива не пройден по причине: " << e.what() << endl;
            test_failed = true;
        }
        if (!test_failed)
        {
            cout << "Тест на заполнение массива пройден" << endl;
        }
        
        //3.Проверка копирования массива arr в массив arr_copy
        
        try
        {
            test_failed = false;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
            
            IntegerArray <int> arr_copy(arr);
            for (int i = 0; i < arr.getLength(); ++i)
            {
                if( arr[i] != arr_copy[i])
                {
                    throw exception();
                }
            }
        }
        catch (exception& e)
        {
            cout << "Тест на копирование массива не пройден по причине: " << e.what() << endl;
            test_failed = true;
        }
        if (!test_failed)
        {
            cout << "Тест на копирование массива пройден" << endl;
        }
        
       //4.Проверка поиска элемента в мвссиве
        
        try
        {
            test_failed = true;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
            
            cout << arr.find(11) << endl;
        }
        catch (NotFound& e)
        {
            cout << e.what() << endl;
            test_failed = false;
        }
        if (!test_failed)
        {
            cout << "Тест на поиск элемента в массиве пройден" << endl;
        }
        
        //5.Проверка вставки элемента в массив
        
        try
        {
            test_failed = true;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
            
            arr.insertBefore(20, -5);
        }
        
        catch (BadRange& e)
        {
            cout << e.what() << endl;
            test_failed = false;
        }
        if (!test_failed)
        {
            cout << "Тест на вставку элемента в массив пройден" << endl;
        }
        
        //6.Проверка изменения размеров массива
        
        try
        {
            test_failed = true;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
            
            arr.resize(-8);
        }
        
        catch (BadLength& e)
        {
            cout << e.what() << endl;
            test_failed = false;
        }
        if (!test_failed)
        {
            cout << "Тест на изменение размеров массива пройден" << endl;
        }
        
        //7.Проверка замена массива
        
        try
        {
            test_failed = true;
            
            IntegerArray <int> arr(10);
            
            for (int i = 0; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
            arr.reallocate(-9);
            for (int i = 1; i < arr.getLength(); ++i)
            {
                arr[i] = i + 1;
            }
        }
        
        catch (BadLength& e)
        {
            cout << e.what() << endl;
            test_failed = false;
        }
        if (!test_failed)
        {
            cout << "Тест на замену массива пройден" << endl;
        }
    }
    catch (exception& e)
        {
            cout << e.what() << endl;
        }
    return 0;
}

