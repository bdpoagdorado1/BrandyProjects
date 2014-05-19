//-----------------------------------------------------------------------------
// Name: Brandy Poag
// File: a14q02.cpp
//
// Description
// Tests for LinearContainer.
//-----------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include "LinearContainer.h"

void pf(bool b)
{
	std::cout << (b ? "pass " : "fail ");
}

void test0()
{
	std::cout << "test0:\n";
	LinearContainer c;

	init(c);
	std::cout << "expected output: [ ] ... output: ";
	println(c);

	c.x[0] = 42;
	c.len = 1;
	std::cout << "expected output: [ 42 ] ... output: ";
	println(c);

	c.x[1] = 100;
	c.len = 2;
	std::cout << "expected output: [ 42 100 ] ... output: ";
	println(c);
}

void test1()
{
	std::cout << "test1 (test len(), isempty()): ";
	LinearContainer c;
	init(c);
	pf(isempty(c));
	pf(len(c) == 0);

	c.len = 3;
	pf(!isempty(c));
	pf(len(c) == 3);

	std::cout << std::endl;
}
void test2()
{
	std::cout << "test2 (test insert()): ";
	LinearContainer c;

	init(c);
	insert(c, 3, 42);
	pf(c.len == 1 && len(c) == 1);//0 changed all lengths

	insert(c, 0, 42);
	pf(c.len == 2 && len(c) == 2 && c.x[0] == 42);//1

	insert(c, 0, 100);
	pf(c.len == 3 && len(c) == 3 && c.x[0] == 100 && c.x[1] == 42);//2

	insert(c, 1, 10);
	pf(c.len == 4 && len(c) == 4 &&
	c.x[0] == 100 && c.x[1] == 10 && c.x[2] == 42);//3

	std::cout << std::endl;
}

void test3()
{
	std::cout << "test3 (test remove()): ";
	LinearContainer c;

	init(c);
	insert(c, 0, 42);
	insert(c, 1, 43);
	insert(c, 2, 44);

	remove(c, 4);
	pf(len(c) == 3 && c.x[0] == 42 && c.x[1] == 43 && c.x[2] == 44);

	remove(c, 0);
	pf(len(c) == 2 && c.x[0] == 43 && c.x[1] == 44);

	remove(c, 1);
	pf(len(c) == 1 && c.x[0] == 43);

	remove(c, 0);
	pf(len(c) == 0 && len(c) == 0 && isempty(c));

	std::cout << std::endl;
}

void test4()
{
	std::cout << "test4 (test push(), pop()): ";
	LinearContainer c;
	init(c);

	push(c, 40);
	pf(len(c) == 1 && c.x[0] == 40);

	push(c, 50);
	pf(len(c) == 2 && c.x[0] == 40 && c.x[1] == 50);
	///////////////////////////////////////////////////////////////////////should add 42 here
	push(c, 42);
	pf(len(c) == 3 && c.x[0] == 40 && c.x[1] == 50 && c.x[2] == 42);

	int popped;
	popped = pop(c);
	pf(len(c) == 2 && c.x[0] == 40 && c.x[1] == 50 && popped == 42);

	popped = pop(c);
	pf(len(c) == 1 && c.x[0] == 40 && popped == 50);

	popped = pop(c);
	pf(len(c) == 0 && popped == 40);

	std::cout << std::endl;
}
void test5()
{
	std::cout << "test5 (test enqueue(), dequeue()): ";
	LinearContainer c;
	init(c);

	enqueue(c, 40);
	pf(len(c) == 1 && c.x[0] == 40);

	enqueue(c, 50);
	pf(len(c) == 2 && c.x[0] == 40 && c.x[1] == 50);

	enqueue(c, 42);
	pf(len(c) == 3 && c.x[0] == 40 && c.x[1] == 50 && c.x[2] == 42);

	int dequeued;

	dequeued = dequeue(c);
	pf(len(c) == 2 && c.x[0] == 50 && c.x[1] == 42 && dequeued == 40);

	dequeued = dequeue(c);
	pf(len(c) == 1 && c.x[0] == 42 && dequeued == 50);

	dequeued = dequeue(c);
	pf(len(c) == 0 && dequeued == 42);

	std::cout << std::endl;
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}

