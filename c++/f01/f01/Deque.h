// Name: Brandy Poag
// File: Deque.h

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream> 
#include <exception>

template< class T >

class Node
{
public:
	Node(T data0 = 0, Node * next0 = NULL)
		: data(data0), next(next0) { }
	T get_data()
	{
		return data;
	}
	Node * get_next() const
	{
		return  next;
	}
	void set_next(Node * node)
	{
		next = node;
	}
private:
	T data;
	Node * next;
};

template< class T >

class Deque
{
public:
	Deque< T > () : head(new Node< T >) { }
	Deque< T > (const Deque< T > & a)
		: head(new Node< T >)
	{
		*this = a;
	}
	void insert_head(T i)
	{
		try
		{
			if (head->get_next() == NULL)
			{
				Node< T > * node = new Node< T > (i, NULL);
				head->set_next(node);
			}
			else
			{
				Node< T > * node = new Node< T > (i,
					head->get_next());
				head->set_next(node);
			}
		}
		catch (std::bad_alloc & e)
		{
			throw std::exception("overflow error!");
		}
	}

	void insert_tail(T i)
	{
		try
		{
			if (head->get_next() == NULL)
			{
				Node< T > * node = new Node< T > (i, NULL);
				head->set_next(node);
			}
			else
			{
				Node< T > * n = head->get_next();
				while (n != NULL)
				{
					if (n->get_next() == NULL) break;
					n = n->get_next();
				}
				Node< T > * node = new Node< T > (i, NULL);
				n->set_next(node);
			}
		}
		catch (std::bad_alloc & e)
		{
			throw std::exception("overflow error!");
		}
	}

	T remove_head()
	{
		if (head->get_next() != NULL)
		{
			int return_value = head->get_next()->get_data();
			Node< T > * n = head->get_next()->get_next();
			delete head->get_next();
			head->set_next(n);
			return return_value;
		}
		else throw std::exception("underflow error!");
	}

	T remove_tail()
	{
		Node< T > * n = head->get_next();
		if (head->get_next() == NULL)
		{
			throw std::exception("underflow error!");
		}
		else if(n->get_next() == NULL)
		{
			int hold = n->get_data();
			head->set_next(NULL);
			delete n;
			return hold;
		}
		else
		{
			while (n != NULL)
			{
				if (n->get_next()->get_next() == NULL) break;
				n = n->get_next();
			}
			int hold = n->get_next()->get_data();
			delete n->get_next();
			n->set_next(NULL);
			return hold;
		}
	}
	bool is_empty()
	{
		return (head->get_next() == NULL);
	}
	int size()
	{
		T i = 0;
		Node< T > * n = head->get_next();
		while (n != NULL)
		{
			i++;
			if (n->get_next() == NULL) break;
			n = n->get_next();
		}
		return i;
	}
	Deque< T > & operator=(const Deque< T > & a)
	{
		if (a.get_head()->get_next() != NULL)
		{
			Node< T > * n = a.get_head()->get_next();
			while (n != NULL)
			{
				insert_tail(n->get_data());
				if (n->get_next() == NULL) break;
				n = n->get_next();
			}
		}
		return *this;
	}
	Deque & clear()
	{
		while (head->get_next() != NULL)
		{
			remove_tail();
		}
		return *this;
	}
	bool remove(T i)
	{
		if (is_empty()) throw std::exception("underflow error!");
		Node< T > * n = head->get_next();
		Node< T > * previous = head;
		while (n != NULL)
		{
			if (n->get_data() == i)
			{
				if (head->get_next()->get_next() == NULL)
				{
					delete n;
					head->set_next(NULL);
					return true;
				}
				else
				{
					previous->set_next(n->get_next());
					delete n;
					return true;
				}
			}
			else if (n->get_next() == NULL) break;
			previous = n;
			n = n->get_next();
		}
		return false;
	}
	Node< T > * get_head() const
	{
		return head;
	}
	~Deque()
	{
		delete head;
	}

private:
	Node< T > * head;
};

template< class T >
class Iterator
{
public:
	Iterator(Deque< T > & d) : head(d.get_head()) { }
	bool has_value()
	{
		return (head->get_next() != NULL);
	}
	void operator++()
	{
		head = head->get_next();
	}
	T operator*()
	{
		return head->get_next()->get_data();
	}
	Node< T > * get_head() const
	{
		return head;
	}
private:
	Node< T > * head;
};

template< class T >

std::ostream & operator<<(std::ostream & out, Deque< T > & a)
{
	out << '[';
	if (a.get_head() != NULL)
	{
		Node< T > * n = a.get_head()->get_next();
		while (n != NULL)
		{
			out << n->get_data();
			if (n->get_next() != NULL) out << ", ";
			else break;
			n = n->get_next();
		}
	}
	out << "]\n";
	return out;
}

#endif
