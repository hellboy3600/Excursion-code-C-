//
//  table.h
//  Excc
//
//  Created by Сергей on 11.01.15.
//  Copyright (c) 2015 SM. All rights reserved.
//

#ifndef __Excc__table__
#define __Excc__table__

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class myvectorit;

template <class T>
class mvector
{
    friend class myvectorit<T>;
private:
    static const int PP=10;
    int size,capacity;
    T* arr;
public:
    mvector():capacity(PP), size(0), arr(new T[PP]){}
    mvector(const mvector<T> &);
    ~mvector(){delete [] arr;};
    int size1() const;
    int capacity1() const;
    T& at( int );
    //mvector<T>& operator = (const mvector<T> &);
    myvectorit<T> erase( myvectorit<T> );
    void clear();
    int getPos();
    //const T& at( int ) const;
    bool empty() const;
    void push_back( const T& );
    typedef myvectorit<T> iterator;
    myvectorit<T> begin();
    void resize(int);
    myvectorit<T> end();
};

template <class T>
mvector<T>::mvector( const mvector<T>& c ):
size( c.size ), capacity( c.capacity ), arr( new T[capacity] )
{
    for ( int i = 0; i != size; ++i )
        arr[i] = c.arr[i];
}

template <class T>
void mvector<T>::resize( int new_size )
{
    capacity = 2 * new_size;
    T *new_arr = new T[capacity];
    for ( int i = 0; i != std::min(size, new_size ); ++i )
        new_arr[i] = arr[i];
    delete [] arr;
    size = new_size;
    arr = new_arr;
}


/*
 template <class T>
 mvector<T>& mvector<T>::operator= ( const mvector<T>& c )
 {
 if ( this != &c )
 {
 size = c.size;
 capacity = c.capacity;
 delete [] arr;
 arr = new T[capacity];
 for ( int i = 0; i != c.size; ++i )
 arr[i] = c.arr[i];
 }
 
 return *this;
 }
 */
template <class T>
int mvector<T>::size1() const
{
    return size;
}

template <class T>
int mvector<T>::capacity1() const
{
    return capacity;
}

template <class T>
myvectorit<T> mvector<T>::begin()
{
    return myvectorit<T>(this->arr);
}

template <class T>
myvectorit<T> mvector<T>::end()
{
    return myvectorit<T>(this->arr+size);
}/*
  template <class T>
  void mvector<T>::push_back( const T& val )
  {
  if ( size == capacity )
  {
  resize( size + 1 );
  --size;
  }
  
  arr[size++] = val;
  }
  */
template <class T>
int mvector<T>::getPos()
{
    if (size<=0)
        return -1;
    else
        return size;
}



template <class T>
void mvector<T>::push_back (const T& val)
{
    int i = getPos();
    if (i < 0){
        if (size >= capacity)
        {
            resize(size+1);
            size=0;
        }
    }
    arr[size]= val;
    size=size+1;
}

template <class T>
myvectorit<T> mvector<T>::erase( myvectorit<T> position )
{
    myvectorit<T> i=begin();
    T* new_arr=new T[size-1];
    for (int z=0,z1=0; z!=size; ++z )
    {
        if (i!=position)
        {
            new_arr[z1++]=arr[z];
        }
        ++i;
    }
    delete [] arr;
    --size;
    arr = new_arr;
    return position;
}
template <class T>
void mvector<T>::clear()
{
    for (myvectorit<T> it = begin();it != end(); ++it)
        delete *it;
    arr = nullptr;
    size = 0;
    capacity = 0;
}


template <class T>
T& mvector<T>::at( int index )
{
    if ( index >= size )
        throw "‚˚¯ÎË Á‡ ÔÂ‰ÎÂÎ˚";
    return arr[index];
}

template <class T>
bool mvector<T>::empty() const
{
    return size == 0;
}






template <class T>
class myvectorit
{
private:
    T* cur;
public:
    myvectorit():cur(0){};
    myvectorit(T *a):cur(a){};
    int operator !=(const myvectorit<T> &) const ;
    int operator ==(const myvectorit<T> &) const ;
    T& operator *();
    myvectorit<T>& operator ++();
    myvectorit<T> operator ++(int);
    myvectorit<T> operator +(int);
    
};

template <class T>
int myvectorit<T>::operator !=(const  myvectorit<T> &it) const
{
    return cur!=it.cur;
}

template <class T>
int myvectorit<T>::operator ==(const myvectorit<T> &it) const
{
    return cur ==it.cur;
}

template <class T>
T& myvectorit<T>::operator *()
{
    return *cur;
}

template < class T>
myvectorit<T>& myvectorit<T>::operator ++()
{
    ++cur;
    return *this;
}

template <class T>
myvectorit<T> myvectorit<T>::operator ++(int)
{
    ++cur;
    return cur;
}
#endif /* defined(__Excc__table__) */
