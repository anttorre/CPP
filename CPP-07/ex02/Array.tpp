/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:08:49 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/22 13:15:49 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void){
    _arr = NULL;
    _size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n){
    _arr = new T[n];
    _size = n;
}

template<typename T>
Array<T>::Array(const Array &other){
    _arr = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
    {
        _arr[i] = other._arr[i];
    }
    _size = other._size;
    
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
    if(this != &other){
        if(_arr)
            delete[] _arr;
        _arr = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
        {
            _arr[i] = other._arr[i];
        }
        _size = other._size;
    }
    return (*this);
}

template<typename T>
Array<T>::~Array(){
    if(_arr)
        delete[] _arr;
}

template<typename T>
unsigned int Array<T>::size() const{
    return _size;
}

template<typename T>
T &Array<T>::operator[](unsigned int i){
    if (i <= _size)
	{
		if (i == _size)
			throw(Array<T>::OutOfBoundsException());
		return _arr[i];
	}
    throw(Array<T>::OutOfBoundsException());
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}