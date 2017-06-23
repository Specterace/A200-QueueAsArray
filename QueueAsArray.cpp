/*
 Choy, Oscar
 CS A200
 February 9, 2016

 This is an impelementation of a Queue, done on an array.
*/
#include "QueueAsArray.h"

// default constructor
template<class T>
QueueAsArray<T>::QueueAsArray() {

	maxQueueSize = 50;

	queueFront = 0;
	queueRear = 0;

	queueArray = new T[maxQueueSize];
}

// overloaded constructor
template<class T>
QueueAsArray<T>::QueueAsArray(int newSize) {
	maxQueueSize = 50;

	queueFront = 0;
	queueRear = 0;

	queueArray = new T[maxQueueSize];
}
// another overloaded constructor
template<class T>
QueueAsArray<T>::QueueAsArray(const QueueAsArray<T>& oQueue) {
	maxQueueSize = oQueue.maxQueueSize;
	queueFront = oQueue.queueFront;
	queueRear = oQueue.queueRear;

	queueArray = new T[maxQueueSize];

	for (int i = queueFront; i <= queueRear; ++i) {
		queueArray[i] = oQueue.queueArray[i];
	}
	count = oQueue.count;
}

//overloaded assignment operator
template<class T>
QueueAsArray<T>& QueueAsArray<T>::operator=(const QueueAsArray<T>& oQueue) {
	if (this == &oQueue) {
		cerr << "Cannot assign to itself" << endl;
	} else {
		maxQueueSize = oQueue.maxQueueSize;
		queueFront = oQueue.queueFront;
		queueRear = oQueue.queueRear;
		T *newArray = new T[maxQueueSize];

		for (int i = queueFront; i <= queueRear; ++i) {
			newArray[i] = oQueue.queueArray[i];
		}
		delete queueArray;
		queueArray = newArray;
		newArray = NULL;
		count = oQueue.count;
	}
	return *this;
}

// isEmptyQueue
template<class T>
bool QueueAsArray<T>::isEmptyQueue() const {

	return (queueFront == queueRear);

}

// isFullQueue
template<class T>
bool QueueAsArray<T>::isFullQueue() const {
	return ((queueFront - 1) == queueRear)
}

// front
template<class T>
T QueueAsArray<T>::front() const {
	
	if (queueFront == queueRear) {
		cerr << "Queue is empty." << endl;
		system("Pause");
		exit(0);
	} else {
		return queueArray[queueFront];
	}
}

// addToQueue
template<class T>
void QueueAsArray<T>::addToQueue(const T& queueElement) {
	if ((queueFront - 1) == queueRear) {
		cerr << "This queue is full." << endl;
	} else {
		queueArray[queueRear] = queueElement;
		queueRear = (queueRear + 1) % maxQueueSize;
	}
}

// popFromQueue

template<class T>
void QueueAsArray<T>::popFromQueue() {
	if (queueFront == queueRear) {
		cerr << "This queue is empty." << endl;
	} else {
		queueFront = (queueFront + 1) % maxQueueSize;
	}
}

// emptyTheQueue
template<class T>
void QueueAsArray<T>::emptyTheQueue() {
	queueFront = 0;
	queueRear = 0;
}

// destroyQueue	
template<class T>
void QueueAsArray<T>::destroyQueue() {
	delete[] queueArray;
	queueArray = NULL;
	queueFront = 0;
	queueRear = 0;
}

// destructor
template<class T>
QueueAsArray<T>::~QueueAsArray() {
	destroyQueue();
}
