// Uriel Klein 209739630
// Course - 150018.3.5781
//

#include "Vector.h"
#include <iostream>
using namespace std;
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast, at, insert
};
int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val, index;
	cout << "enter your choice 0-8:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3.assign(v1);
			break;
		case isEqual:	if (v1.isEqual(v2)) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:		cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
		case add:		v3.assign(v1.strnewcat(v2));
			break;
		case clear:		v1.clear();
			break;
		case delLast:	       v2.delLast();
			break;
		case at:		cout << "enter index:" << endl; cin >> index; cout << "enter value:" << endl; cin >> val; v3.at(index) = val;
			break;
		case insert:	cout << "enter value:" << endl; cin >> val; v3.insert(val);
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-8:\n";
		cin >> choice;
	}
	return 0;
}

Vector::Vector(int max)
{
	if (max < 0)
		cout << "ERROR" << endl;
	else{
		capacity = max;
		data = new int[max];
		size=0;
	}
}

Vector::~Vector()
{
	if (size)
		delete[] data;
	data = NULL;
}

Vector::Vector(const Vector& v)
{
	capacity = v.capacity;
	size = v.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

int Vector::getCapacity()
{
	return capacity;
}

int Vector::getSize()
{
	return size;
}

void Vector::print()
{
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

bool Vector::isEqual(Vector v)
{
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
			if (data[i] != v.data[i])
				return false;
		return true;
	}
	else
		return false;
}

int Vector::strcatcat(Vector v)
{
	if (size != v.size)
	{
		cout << "ERROR" << endl;
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += data[i] * v.data[i];
	return sum;
}

Vector Vector::strnewcat(Vector v)
{
	Vector temp(size+v.size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i];
	for (int i = size, j = 0; j < v.size; i++, j++)
		temp.data[i] = v.data[j];
	temp.size = v.size + size;
	return temp;
}

void Vector::clear()
{
	for (int i = 0; i < size; i++)
		data[i] = 0;
	size = 0;
}

void Vector::delLast()
{
	if (size == 0)
		cout << "ERROR" << endl;
	else
	{
		data[size - 1] = 0;
		size = size - 1;
	}
}

void Vector::insert(int value)
{
	if (size + 1 > capacity)
		capacity *= 2;
	int* p = new int[capacity];
	for (int i = 0; i < size; i++)
		p[i] = data[i];
	p[size] = value;
	delete[] data;
	data = p;
	size += 1;
}

void Vector::assign(Vector v)
{
	capacity = v.capacity;
	size = v.size;
	delete[] data;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

int& Vector::at(int index)
{
	if ((index >= size) || (index < 0))
	{
		cout << "ERROR" << endl;
		return *data;
	}
	//else if (index < 0)
	//	cout << "ERROR" << endl;
	else
		return *(data + index);
}
