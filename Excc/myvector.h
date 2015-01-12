//
//  myvector.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__myvector__
#define __Excc__myvector__

#include <stdio.h>
using namespace std;
#include <algorithm> //для функции min

//!класс итератор
template <class MyType>
class myiterator
{
private:
    MyType* cur;//!указатель на элемент
public:
    myiterator() :cur(0){}; //!пустой конструктор
    myiterator(MyType *a) :cur(a){}; //!конструктор
    int operator !=(const myiterator<MyType> &a) const{ return cur != a.cur; }//!перегр оператор !=
    int operator ==(const myiterator<MyType> &a) const{ return cur == a.cur; }//!перегр оператор ==
    MyType& operator *(){ return *cur; }//!перегр оператор *()
    myiterator<MyType>& operator ++()
    {
        ++cur;
        return *this;
    }
    myiterator<MyType> operator ++(int)
    {
        ++cur;
        return cur;
    }
    myiterator<MyType> operator +(int i)
    {
        myiterator<MyType> p(*this);
        p.cur += i;
        return p;
    }
    myiterator<MyType>* operator ->()//!перегруженный оператор ->
    {
        return cur;
    }
    
};
//!Класс конст.итератор
template <class T>
class myiterator_const
{
private:
    T* elem;//!Указатель
public:
    myiterator_const() :elem(0){};//!пустой конструктор
    myiterator_const(T *a) :elem(a){};//! конструктор
    int operator !=(const myiterator_const<T> &a) const{ return elem != a.elem; }
    int operator ==(const myiterator_const<T> &a) const{ return elem == a.cur; }
    T& operator *(){ return *elem; }//!перегр оператор !=
    myiterator_const<T>& operator ++()//!перегр оператор ==
    {
        ++elem;
        return *this;
    }
    myiterator_const<T> operator ++(int)
    {
        ++elem;
        return elem;
    }
    myiterator_const<T> operator +(int i)
    {
        myiterator_const<T> p(*this);
        p.elem += i;
        return p;
    }
    
};
//!Класс вектор
template <class T>
class myvector
{
    friend class myiterator<T>;
private:
    int size; //!текужий размер
    int maxsize; //!максимальный размер
    T* mas; //!массив элементов
public:
    myvector(): maxsize(15), size(0), mas(new T[15]){} //!пустой конструктор
    
    myvector(const myvector<T> &a) :size(a.size), maxsize(a.maxsize), mas(new T[maxsize])//!конструктор
    { for (int i = 0; i != size; ++i) mas[i] = a.mas[i]; };
    
    int getsize() const; //!получить текущий размер
    int getmaxsize() const; //!получить максимальный размер
    bool empty() const; //!есть элементы или нет
    void clear(); //!очистка
    void push_back(const T&); //!вставка
    myiterator<T> erase(myiterator<T>);//!удаление
    myiterator<T> begin(); //!указатель на начало
    myiterator<T> end(); //!указатель на конец
    myiterator_const<T> begin() const;//!указатель на начало
    myiterator_const<T> end() const;//!указатель на конец
    T& at(int); //! доступ к элементу по индексу
    typedef myiterator<T> iterator; //!переопределение типа
    typedef myiterator_const<T> const_iterator;//!переопределение типа
    void resize(int); //!переpаспределение размера
    ~myvector()
    {
        delete[] mas;
    };
};

template <class T>
void myvector<T>::resize(int new_size)
{
    maxsize = 2 * new_size;
    T *newmas = new T[maxsize];
    for (int i = 0; i != std::min(size, new_size); ++i)
        newmas[i] = mas[i];
    delete[] mas;
    size = new_size;
    mas = newmas;
}

template <class T>
int myvector<T>::getsize() const
{
    if (size <= 0) return -1;
    else return size;
}

template <class T>
int myvector<T>::getmaxsize() const
{
    return maxsize;
}

template <class T>
myiterator<T> myvector<T>::begin()
{
    return myiterator<T>(this->mas);
}

template <class T>
myiterator<T> myvector<T>::end()
{
    return myiterator<T>(this->mas + size);
}

template <class T>
void myvector<T>::push_back(const T& x)
{
    int i = getsize();
    if (i < 0)
    {
        if (size >= maxsize)
        {
            resize(size + 1);
            size = 0;
        }
    }
    mas[size] = x;
    size +=1;
}

template <class T>
myiterator<T> myvector<T>::erase(myiterator<T> x)
{
    //delete *x; в случае если вектор содержит указатели
    for (myiterator<T> p = x; p != end(); ++p)
    {
        myiterator<T> t = p + 1;
        *p = *(t);
    }
    size-=1;
    return x;
}

template <class T>
void myvector<T>::clear()
{
    size = 0;
    maxsize = 0;
    delete[] mas;
    mas = nullptr;
}

template <class T>
T& myvector<T>::at(int i)
{//OUT_OF_RANGE
    if (i
        >= size)
        throw "Error!";
    return mas[i];
}

template <class T>
bool myvector<T>::empty() const
{
    return size == 0;
}

template <class T>
myiterator_const<T> myvector<T>::begin() const
{
    return myiterator_const<T>(this->mas);
}

template <class T>
myiterator_const<T> myvector<T>::end() const
{
    return myiterator_const<T>(this->mas + size);
}

#endif /* defined(__Excc__myvector__) */
