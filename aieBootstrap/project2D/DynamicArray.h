#pragma once
#include "memory.h"

template <typename T>

class dynamicArray
{
public:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	dynamicArray(int startSize = 0)
	{
		int cap = startSize;
		if (cap <= 0)
			cap = 1;

		data = new T[cap];
		arrayCap = cap;
		used = 0;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~dynamicArray()
	{
		delete data;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	dynamicArray(const dynamicArray& value)
	{
		arrayCap = value.arrayCap;
		used = value.used;

		data = new T[arrayCap];
		memcpy(data, value.data, sizeof(T) * arrayCap);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void pushBack(T value)
	{
		if (used >= arrayCap)
			resize();
		data[used] = value;
		++used;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void Insert(int index, T value)
	{
		if (index > used)
			return;
		if (used >= arrayCap)
			resize();

		for (int i = used - 1; i >= index; --i)
		{
			data[i + 1] = data[i];
		}
		data[index] = value;
		++used;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void pushFront(T value)
	{
		Insert(0, value);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T popBack()
	{
		--used;
		return data[used];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T remove(int index)
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Backup value we are removing from the list
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		T value = data[index];

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Shuffle all other values across to fill removed space
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		for (int i = index; i < used; ++i)
		{
			data[i] = data[i + 1];
		}
		--used;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Return removed value
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		return value;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T popFront()
	{
		return remove(0);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void clear()
	{
		used = 0;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void shrink()
	{
		int cap = used;
		if (cap <= 0)
			cap = 1;

		T* newData = new T[cap];
		memcpy(newData, data, sizeof(T) * cap);
		delete data;
		data = newData;
		arrayCap = cap;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T& operator[](const int index)
	{
		return data[index];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int size()
	{
		return used;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int capacity()
	{
		return arrayCap;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool empty()
	{
		if (used <= 0)
			return true;
		else
			return false;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T back()
	{
		return data[used - 1];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T secondBack()
	{
		return data[used - 2];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
private:
	dynamicArray& operator= (const dynamicArray& value) = default;
	dynamicArray(dynamicArray&& value) = default;
	dynamicArray& operator= (dynamicArray&& value) = default;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void resize()
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Create a new array that is twice as big as the original
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		T* newData = new T[arrayCap * 2];

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Copy old data across into new array
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		memcpy(newData, data, sizeof(T) * arrayCap);

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Delete old array
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		delete data;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Make sure our pointers still work
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		data = newData;
		arrayCap = arrayCap * 2;
	};
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	T* data;
	int arrayCap;
	int used;
};
