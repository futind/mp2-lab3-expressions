#pragma once
#include <iostream>

template <class ValType>
struct Link {
	ValType Value;
	Link<ValType> *next;
};

template <class ValType>
class Stack {
	Link<ValType> *h;
public:
	Stack() { h = NULL; }

	~Stack() { 
		while (h != NULL) { 
			this->Pop(); 
		} 
	}

	bool isEmpty() //Проверка на пустоту
	{
		return(h == NULL);
	}

	void Push(ValType a) //Добавление элемента
	{
		Link<ValType> *T;
		T = new Link<ValType>;
		T->Value = a;
		T->next = h;
		h = T;
	}

	ValType Pop() //Возвращение элемента с удалением
	{
		if (isEmpty()) throw - 100;
		ValType a = h->Value;
		Link<ValType> *T;
		T = h;
		h = h->next;
		delete T;
		return a;
	}

	ValType Top()
	{
		if (isEmpty()) throw - 100;
		return h->Value;
	}

	void Show()
	{
		Link<ValType> *T = h;
		std::cout << endl;
		while (T != NULL) {
			std::cout << (T->Value) << ' ';
			T = T->next;
		}
	}

	//friend istream& operator>>(istream& in, Stack<ValType>& S); TODO?
	//friend std::istream& operator<<(std::ostream& out, Stack<ValType>& S);
};