#include <iostream>
#include <vector>


int main()
{
	std::vector< int > v;
	v.resize(4);
	v[0] = 2;
	v[1] = 5;
	v[2] = 3;
	v[3] = 1;
	std::cout << "size:" << v.size() << '\n';

	v.push_back(5);
	std::cout << "size:" << v.size() << " array:";
	for (int i = v.size() - 1; i >= 0; i--)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.push_back(-54);
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.push_back(13542);
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.resize(5);
	v[3] = 3;
	v[4] = 4;
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.resize(0);
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.resize(5);
	for (int i = 0; i < 5; i++) v[i] = i;
	std::vector< int > u = v;
	std::cout << "size:" << u.size() << " array:";
	for (int i = 0; i < u.size(); i++)
		std::cout << u[i] << ' ';
	std::cout << "\n";

	u[0] = -13579;
	u[1] = -24680;
	for (int i = 2; i < u.size(); i++) u[i] = 0;
	v = u;
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	v.resize(2);
	std::cout << "size:" << v.size() << " array:";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n";
return 0;
}
/*#include <iostream>

class vec2d
{
public:
	vec2d (doubel x0 =0, double y0 =0) : x(x0), y(y0) {}
	void print() { std::cout << '(' << x << ", " << y << ')'; }
	void move(double x0, double y0)
	{
		x += x0;
		y += y0;
	}
private:
	double x, y;
};

class Rect
{
public:
	Rect(double x0, double y0, double w0, double h0)
		: pos(x0, y0), w(w0), h(h0) {}
	void print()
	{
		pos.print();
		std::cout << ' ' << w << ", " << h;
	}
	void move()
	{
	}
private:
	vec2d pos;
	double w, h;
};

int main()
{
	vec2d v;
	v.print();
	std::cout << '\n';
	vec2d.move(2, 5);
	v.print();
	std::cout << '\n';

	return 0;
}*/
/*class C
{
public:
	C(int i = 0) : x(i), y(3.14) { std::cout << "Default x is 0!\n"; }

	//C(int x0 = 0, double d0 = 0) : x(x0), y(d0) {}
	void print()
	{
		std::cout << x << ',' << y << '\n';
	}
	void set_x(int newx)
	{
		x = newx;
	}
private:
	int x;
	double y;
};

int main()
{
	C arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i].set_x(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ' ';
		arr[i].print();
	}
	std::cout << '\n';
	/*int x[100];
	C y[200];

	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < 10; i++)
	{
		y[i].print();
	}
	return 0;
}*/

/*#include <iostream>

class C
{
public:
	C(int x0 = 0, double d0 = 0) : x(x0), y(d0) {}
	void print()
	{
		std::cout << x << ',' << y << '\n';
	}
private:
	int x;
	double y;
};
int main()
{
	int x[100];
	C y[200];

	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < 10; i++)
	{
		y[i].print();
	}
	return 0;
}
*/