// Name: Brandy Poag
// File: LinearContainer.h

#ifndef LINEARCONTAINER_H
#define LINEARCONTAINER_H

const int LINEAR_CONTAINER_SIZE = 5; // The capacity of the container.
const int NO_DATA = -9999; // See pop() and dequeue() below.

struct LinearContainer
{
	int * x; // x will point to an array of ints
	int len;
	int size;
};

void init(LinearContainer & c, int size = LINEAR_CONTAINER_SIZE);
// LINEAR_CONTAINER_SIZE

void println(const LinearContainer & c);

int len(const LinearContainer &); // returns the value of len
bool isempty(const LinearContainer &); // returns true exactly when len
// is 0

void insert(LinearContainer &, int index, int newvalue);
void remove(LinearContainer &, int index);

void push(LinearContainer &, int newvalue); // insert at index position
// len
int pop(LinearContainer &); // same as remove at index
// position len, except that
// value removed is returned.
// If the container is empty,
// NO_DATA is returned.

void enqueue(LinearContainer &, int newvalue); // This is the same as push
int dequeue(LinearContainer &); // Same as remove at index
// position 0, except that
// the value removed is
// returned. If the
// container is empty,
// NO_DATA is returned.

void resize(LinearContainer & c, int newsize);

#endif
