#pragma once

struct Queue
{
	int info;
	Queue* next, * prev;
};

class QueueLibrary
{
public:
	static void Create_First_Element(Queue** begin, Queue** end, int info);

	static void Push_to_begin(Queue** begin, Queue** end, int info);

	static void Push_to_end(Queue** begin, Queue** end, int info);

	static void View_from_begin(Queue* begin);

	static void View_from_end(Queue* end, Queue* begin);

	static void Pop_from_begin(Queue** begin);

	static void Pop_from_end(Queue** end);

	static void Сlear_queue(Queue** begin);

	static int Remove_element(int key, Queue** begin, Queue** end);

	static double Average(Queue* begin);

	static void Individual_Task(Queue* begin);
};s
