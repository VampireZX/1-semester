#include "Header.h"
#include <iostream>
#include <iomanip>

void QueueLibrary::Create_First_Element(Queue** begin, Queue** end, int info)
{
	Queue* TempElement = new Queue;
	TempElement->info = info;
	TempElement->next = TempElement->prev = NULL;
	*begin = *end = TempElement;
}

void QueueLibrary::Push_to_begin(Queue** begin, Queue** end, int info)
{
	Queue* TempElement = new Queue;
	TempElement->info = info;
	TempElement->prev = NULL;
	TempElement->next = *begin;
	(*begin)->prev = TempElement;
	*begin = TempElement;
}

void QueueLibrary::Push_to_end(Queue** begin, Queue** end, int info)
{
	Queue* TempElement = new Queue;
	TempElement->info = info;
	TempElement->next = NULL;
	TempElement->prev = *end;
	(*end)->next = TempElement;
	*end = TempElement;
}

void QueueLibrary::View_from_begin(Queue* begin)
{
	Queue* TempElement = begin;
	if (begin != nullptr)
	{
		while (TempElement != NULL)
		{
			std::cout << std::setw(6) << TempElement->info << std::endl;
			TempElement = TempElement->next;
		}
	}
	else
	{
		std::cout << "Очередь пуста.\n";
	}
}

void QueueLibrary::View_from_end(Queue* end, Queue* begin)
{
	Queue* TempElement = end;
	if (end != nullptr)
	{
		while (TempElement != NULL)
		{
			std::cout << std::setw(6) << TempElement->info << std::endl;
			TempElement = TempElement->prev;
		}
	}
	else
	{
		std::cout << "Очередь пуста.\n";
	}

}

void QueueLibrary::Pop_from_begin(Queue** begin)
{
	(*begin)->next->prev = nullptr;
	*begin = (*begin)->next;
}

void QueueLibrary::Pop_from_end(Queue** end)
{
	(*end)->prev->next = nullptr;
	*end = (*end)->prev;
}

void QueueLibrary::Сlear_queue(Queue** begin) {
	Queue* t;
	while (*begin != nullptr) {
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}

int QueueLibrary::Remove_element(int key, Queue** begin, Queue** end) {
	Queue* t = *begin; int c = 0;
	while (t != nullptr) {
		if (t->info == key) {
			c++;
			if (t != *begin)
				t->prev->next = t->next;
			else
				*begin = (*begin)->next;
			if (t != *end)
				t->next->prev = t->prev;
			else
				*end = (*end)->prev;
		}
		t = t->next;
	}
	return c;
}

double QueueLibrary::Average(Queue* begin)
{
	int sum = 0, amount = 0;
	Queue* TempElement = begin;
	while (TempElement != nullptr)
	{
		sum += TempElement->info;
		amount++;
		TempElement = TempElement->next;
	}
	return sum / amount;
}

void QueueLibrary::Individual_Task(Queue* begin)
{
	double average = QueueLibrary::Average(begin);
	std::cout << "Среднее арифметическое: " << (int)average << std::endl;
	for (Queue* TempQueue = begin; TempQueue; TempQueue = TempQueue->next)
		if (TempQueue->info % 2 == 0)
			TempQueue->info = (int)average;
}
