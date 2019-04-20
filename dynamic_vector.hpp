#ifndef DYNAMIC_VECTOR_HPP
#define DYNAMIC_VECTOR_HPP

#include <string>

using namespace std;

template <typename T>
class DynamicVector
{
private:
	T * elems;
	int size;
	int capacity;
public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element on position pos.
	*/
	T& operator[](int pos);

	// Adds an element to the current DynamicVector.
	void add(const T& e);

	bool deleteEvent(const string & givenTitle);

	int getSize() const;
	T* getElems() const;
	void setSize(int s) { size = s; }

private:
	void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.capacity; i++)
	{
		this->elems[i] = v.elems[i];
	}

}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.capacity; i++)
	{
		this->elems[i] = v.elems[i];
	}

	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(const T& e)
{
	if (this->size == this->capacity)
		resize();

	this->elems[this->size++] = e;
}

template <typename T>
bool DynamicVector<T>::deleteEvent(const string & givenTitle)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getTitle() == givenTitle)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				this->elems[j] = this->elems[j + 1];
			}
			this->size--;
			return true;
		}
	}
	return false;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
T* DynamicVector<T>::getElems() const
{
	return this->elems;
}

#endif