#pragma once
#include <iostream>

template <class ValType>
class Queue {
	Link<ValType> *h, *l;
public:
	Queue()
	{
		h = NULL;
		l = NULL;
	}

	~Queue()
	{
		while (!isEmpty()) { Pop(); }
	}

	/*Queue(const Queue& Q)
	{
		if (Q.h == NULL) { h = NULL; l = NULL; }
		else {
			Link<ValType> *T = Q.h;
			while (T != NULL) {
				Push(T->Value);
				T = T->next;
			}
		}
	}*/

	bool isEmpty()
	{
		return (h == NULL);
	}
	
	void Push(ValType a)
	{
		Link<ValType> *T;
		T = new Link<ValType>;
		T->Value = a;
		T->next = NULL;
		
		if (h != NULL) {
			l->next = T;
			l = T;
		}
		else { h = l = T; }
	}

	ValType Pop()
	{
		if (isEmpty()) throw - 100;

		ValType a = h->Value;

		Link<ValType> *T;
		T = h;
		h = h->next;
		delete T;

		if (h == NULL) { l = NULL; }

		return a;
	}

	void Show()
	{
		Link<ValType> *T = h;
		std::cout << endl;
		while (T != NULL) {
			std::cout << (T->Value) << '-';
			T = T->next;
		}
	}

	ValType Top()
	{
		if (isEmpty()) throw - 100;
		ValType a = h->Value;
		return a;
	}

	/*ValType AfterTop() {
		if (h->next == NULL) throw - 100;
		ValType a = h->next->Value;
		return a;
	}*/
};