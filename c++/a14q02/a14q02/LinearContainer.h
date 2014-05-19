// File: Container.h
// Name: Brandy Poag

#ifndef LINEARCONTAINER_H
#define LINEARCONTAINER_H

const int LINEAR_CONTAINER_SIZE = 5;
const int NO_DATA = -9999;

struct LinearContainer
{
	int x[LINEAR_CONTAINER_SIZE];
	int len;
	int size;
};

void init(LinearContainer & x);

void println(const LinearContainer & x);

int len( const LinearContainer & x);
bool isempty(const LinearContainer & x);

void insert(LinearContainer & x, int index, int newvalue);
void remove(LinearContainer & x, int index);

void push(LinearContainer & x, int newvalue);

int pop(LinearContainer & x);

void enqueue(LinearContainer & x, int newvalue);

int dequeue(LinearContainer & x);

#endif

