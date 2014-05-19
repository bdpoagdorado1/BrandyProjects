#include <iostream>
#include <string>


/*class D
{
public: D() : x(0) {}
		int get_x( ) { return x; }
		void set_x( int a) { x = a; }

private: int x;
};

class C : public D
{
public: C() : y(1) {}
		int get_y( ) { return y; }
		void set_y( int a) { y = a; }

private: int y;
		
};
int main()
{
	C c;
	std::cout << "c.x=" << c.get_x() << ", c.y=" << c.get_y() << '\n';
	return 0;
}*/
/*class D
{
public: void set_x(int x0) { x = x0; }
private: int x;
};

class C : public D
{
public: void f() { set_x(0); }
private: int y;
		
};
int main()
{
	C c;
	c.f();
	return 0;
}*/
/*Class D
{
public: void f() { std::cout << "d::f()\n"; }
private: int x;
};

class C : public D
{
public: void f() { std::cout << "c::f()\n"; D::f(); }
private: int y;
		
};
int main()
{
	D d;
	C c;
	d.f();
	c.f();
	c.D::f();
	d = c;
	return 0;
}*/

/*class Thing
{
public: 
	Thing() : id(num_id) { num_id++; }
	int get_id() const { return id; }
private:
	static int num_id;
	int id;
};
int Thing::num_id(0);

std::ostream & operator<<(std::ostream & out, const Thing & t)
{
	out << "Thing, id:" << t.get_id() << '>';
	return out;
}

std::ostream & operator<<(std::ostream & out, const Position & pos)
{
	out << "(" << pos.get_row() << ", " << pos.get_col() << ')';
	return out;
}
class Person : public Thing
{
public: 
	Person(std::string fname0, std::string lname0, int pos0 = 0) : fname(fname0), lname(lname0) { }
	std::string get_fname() const { return fname; }
	std::string get_lname() const { return lname; }
	Position get_pos() const { return pos; }
private:
	std::string fname;
	std::string lname;
	Position pos;
	int energy;
};

class Position
{
public:
	Position(int row0 = 0, int col0 = 0) : row(row0), col(col0) {}
	int get_row() const { return row; }
	int get_col() const { return col; }
private:
	int row;
	int col;
};
std::ostream & operator<<(std::ostream & out, const Person & p)
{
	out << "Person, id:" << p.get_id() << ", fname " << p.get_fname() << ", lname " << p.get_lname() << ", pos: " << p.get_pos()<< '>';
	return out;
}

int main()
{
	Thing s, t, u;
	std::cout << s << '\n';
	std::cout << t << '\n';
	std::cout << u << '\n';

	Person johnDoe("John", "Doe");
	std::cout << johnDoe << '\n';

	Person joshFriend("Josh", "Friend");
	std::cout << joshFriend << '\n';
	return 0;
}*/
/*class D
{
public:
	void f() { std::cout << "D::f\n"; }
};
class C : public D
{
public:
	void f() { std::cout << "C::f\n"; }
};
int main()
{
	C c;
	D * p = & c;
	p->f();
	return 0;
}*/
/*class D
{
public:
	virtual void f() { std::cout << "D::f\n"; }
};
class C : public D
{
public:
	void f() { std::cout << "C::f\n"; }
};
int main()
{
	C c;
	D * p = & c;
	p->f();
	return 0;
}*/
class D
{
public:
	virtual void f() { std::cout << "D::f\n"; }
};
class C : public D
{
public:
	void f() { std::cout << "C::f\n"; }
};
class B : public D
{
public:
	void f() { std::cout << "B::f\n"; }
};
int main()
{
	D * p;
	C c;
	B b;
	char ch;
	std::cout << "Do you want B or C?";
	std::cin >> ch;
	if (ch == 'C')
		p = &c;
	else
		p = &b;
	p->f();
	return 0;
}