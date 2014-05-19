#include <iostream>
#include <exception>


#ifndef LIST_H
#define LIST_H

template <typename Object>
class List
{
private:
	struct Node
	{
		Object data;
		Node *prev;
		Node *next;

		Node( const Object & d = Object(), Node *p = NULL, Node *n = NULL )
			: data( d ), prev( p ), next( n ) { };
	};

public:
	class const_iterator
	{
	public:
		const_iterator(): current( NULL ) { }
		const Object & operator*( ) const
		{
			return retrieve();
		}
		const_iterator & operator--()
		{
			current = current->prev;
			assertIsValid( );
			return *this;
		}
		const_iterator operator--( int )
		{
			const_iterator old = *this;
			--( *this );
			return old;
		}
		const_iterator & operator++( )
		{
			current = current->next;
			assertIsValid( );
			return *this;
		}
		const_iterator & operator++( int )
		{
			const_iterator old = *this;
			++( *this );
			return old;
		}
		bool operator==( const const_iterator & rhs ) const
		{
			return current == rhs.current; 
		}
		bool operator!=( const const_iterator & rhs ) const
		{
			return !( *this == rhs );
		}

	protected:
		Node *current;
		const List<Object> *theList;
		Object & retrieve() const
		{
			return current->data;
		}
		const_iterator( const List<Object> & lst, Node *p ) : theList( &lst ), current( p ) { }
		void assertIsValid( ) const
		{
			if ( theList == NULL ) std::cout << "thelist\n";
			if ( current == NULL ) std::cout << "current\n";
			if ( current == theList->head ) std::cout << "head\n";
			if ( theList == NULL || current == NULL || current == theList->head )
				throw std::exception("Error oops iterator is on a NULL");
		}
		friend class List<Object>;
	};

	class iterator : public const_iterator
	{
	public:
		iterator() {}
		Object & operator*()
		{ 
			return retrieve();
		}
		const Object & operator*() const
		{
			return const_iterator::operator*();
		}
		iterator & operator++()
		{
			current = current->next;
			assertIsValid( );
			return *this;
		}
		iterator operator++( int )
		{
			iterator old = *this;
			++( *this );
			return old;
		}
		iterator & operator--()
		{
			current = current->prev;
			assertIsValid( );
			return *this;
		}
		iterator operator--( int )
		{
			iterator old = *this;
			--( *this );
			return old;
		}
		
	protected:
		iterator( const List<Object> & lst, Node *p ) : const_iterator( lst, p ) { }
		void assertIsValid_itr( ) const
		{
			assertIsValid( );
		}
		friend class List<Object>;
	};

public:
	List()
	{
		init();
	}
	List( const List & rhs )
	{
		init();
		*this = rhs;
	}
	~List()
	{
		clear();
		delete head;
		delete tail;
	}
	const List & operator= ( const List & rhs )
	{
		if( this == &rhs )
			return *this;
		clear();
		for( const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
			push_back( *itr );
		return *this;
	}
	iterator begin()
	{
		iterator itr(*this, head );
		return ++itr;
	}
	const_iterator begin() const
	{
		const_iterator itr(*this, head );
		return ++itr;
	}
	iterator end()
	{
		return iterator( *this, tail );
	}
	const_iterator end() const
	{
		return const_iterator ( *this, tail );
	}

	int size() const
	{
		return theSize;
	}
	bool empty() const
	{
		return (size() == 0);
	}

	void clear()
	{
		while( !empty() )
			pop_front();
	}

	Object & front()
	{
		return *begin();
	}
	const Object & front() const
	{
		return *begin();
	}
	Object & back()
	{
		return *--end();
	}
	const Object & back() const
	{
		return *--end();
	}
	void push_front( const Object & x )
	{
		insert( begin(), x );
	}
	void push_back( const Object & x )
	{
		insert( end(), x );
	}
	void pop_front()
	{
		if( !empty() ) erase( begin() );
 	}
	void pop_back()
	{
		if( !empty() ) erase( --end() );
	}

	iterator insert( iterator itr, const Object & x )
	{
		if( itr.theList != this )
		throw std::exception("Error this iterator is not for this object");
		if( size() == 0 )
		{
			theSize++; 
			return iterator( *this, head->next = tail->prev = new Node( x, head, tail ) );
		}
		itr.assertIsValid_itr();
		Node *p = itr.current;
		theSize++; 
		return iterator( *this, p->prev = p->prev->next = new Node( x, p->prev, p ) );
	}
	iterator erase( iterator itr )
	{
		if( itr.theList != this )
		throw std::exception("Error this iterator is not for this object");
		itr.assertIsValid_itr();
		if( itr.current == head )
		{
			theSize--;
			return itr;
		}
		Node *p = itr.current;
		iterator retVal( *this, p->next );
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;
		return retVal;
	}
	iterator erase( iterator start, iterator end )
	{
		if( start.theList != this || end.theList != this )
		throw std::exception("Error this iterator is not for this object");
		start.assertIsValid_itr();
		end.assertIsValid_itr();
		for( iterator itr = start; itr != end; )
			itr = erase( itr );
		return end;
	}
	void insert_inorder( const Object & x )
	{
		iterator itr = begin();
		while( itr++ != --end() )
		{
			if (itr.retrieve() >= x)
			{
				insert( itr, x );
				return;
			}
		}
		--itr;
		push_back(x);
	}
	void removeAll( const Object & x )
	{
		iterator itr = begin();
		while( itr != end() )
		{
			if (itr.retrieve() == x)
			{
				itr = erase( itr );
			}
			else ++itr;
		}
		return;
	}
	int countOcc( const Object & x )
	{
		iterator itr = begin();
		int count = 0;
		while( itr != end() )
		{
			if (itr.retrieve() == x)
			{
				++count;
			}
			++itr;
		}
		return count;
	}
	void sort( )
	{
		if( size() == 1 || empty() ) return;
		iterator x( *this, head->next->next );
		while( x != end() )
		{
			if( x != begin() && x.retrieve() < (--x).retrieve() )
			{
				int n = (++x).retrieve();
				erase( x );
				iterator y( *this, head->next );
				while( y != end() )
				{
					if( n < y.retrieve() )
					{
						insert( y, n );
						y = iterator( *this, tail->prev );
					}
					++y;
				}
			}
			++( ++x );
		}
		return;
	}
	void merge( List & rhs )
	{
		iterator lh( *this, head->next );
		iterator rh( rhs, rhs.head->next );
		if( theSize == 0 )
		{
			--rhs.theSize;
			++theSize;
			lh = iterator( *this, head->next = tail->prev = new Node( rh.retrieve(), head, tail ) );
			rh.current = rh.current->next;
			Node *p = rh.current->prev;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			while( rh.current != rhs.tail )
			{
				--rhs.theSize;
				++theSize;
				lh = iterator( *this, lh.current->next = tail->prev = new Node( rh.retrieve(), lh.current, tail ) );
				rh.current = rh.current->next;
				Node *p = rh.current->prev;
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
			}

		}
		else
		{

			while( rh.current != rhs.tail && lh.current != tail )
			{
				
				if( lh.retrieve() < rh.retrieve() )
				{
					lh.current = lh.current->next;
				}
				else 
				{
					--rhs.theSize;
					++theSize;
					lh = iterator( *this, lh.current->prev = lh.current->prev->next = new Node( rh.retrieve(), lh.current->prev, lh.current ) );
					rh.current = rh.current->next;
					Node *p = rh.current->prev;
					p->prev->next = p->next;
					p->next->prev = p->prev;
					delete p;
				}
			}
		}
	}
	void reverse( )
	{
		std::cout << "Error can't reverse\n";
		/*iterator start(*this, head->next);
		iterator curr(*this, head->next);
		iterator last(*this, head->next);
		head->next = tail->prev;
		curr.current->next = tail->prev;
		curr.current->prev = head;
		curr.current = curr.current->next;
		while( curr.current != start.current )
		{
			curr.current->next = curr.current->prev;
			curr.current->prev = last.current;
			last.current = curr.current;
			curr.current = curr.current->next;
		}
		tail->prev = curr.current;
		curr.current->next = tail;
		curr.current->prev = last.current;*/
	}
	void print( std::ostream & out = std::cout ) const
	{
		if ( empty() )
			out << "(NULL)\n";
		else
		{
			const_iterator itr = begin();
			out << "[ " << *itr;

			while( ++itr != end() )
				if( itr.current != NULL ) out << ", " << *itr;
			out << " ]" << "  size: " << size() << '\n';
		}
	}
private:
	int theSize;
	Node *head;
	Node *tail;

	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};

#endif

