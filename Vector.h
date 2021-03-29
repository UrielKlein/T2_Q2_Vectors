#pragma once
class Vector
{
	int* data;
	int capacity;
	int size;
public:
	Vector(int max = 2);
	~Vector();
	Vector(const Vector&);
	int getCapacity();
	int getSize();
	void print();
	bool isEqual(Vector);
	int strcatcat(Vector);
	Vector strnewcat(Vector);
	void clear();
	void delLast();
	void insert(int);
	void assign(Vector);
	int& at(int);
};

