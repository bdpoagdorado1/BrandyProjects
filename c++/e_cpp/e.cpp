#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Thing
{
public:
  Thing() : id(num_id) { num_id++; }
  int get_id() const { return id; }
private:
  static int num_id;
  int id;
};

int Thing::num_id(0);

std::ostream & operator<<(std::ostream & cout, const Thing & t)
{
  cout << "<Thing, id:" << t.get_id() << '>';
  return cout;
}


class Weapon
{
};

class knife : public Weapon
{
};


class Position
{
public:
  Position(int row0 = 0, int col0 = 0) : row(row0), col(col0) {}
  int get_row() const { return row; }
  int get_col() const { return col; }
private:
  int row, col;
};

std::ostream & operator<<(std::ostream & cout, const Position & pos)
{
  cout << "(" << pos.get_row() << ", " << pos.get_col() << ")";
  return cout;
}




class Person: public Thing
{
public:
  Person(std::string fname0, std::string lname0, int row0=0, int col0=0)
    : fname(fname0), lname(lname0), energy(1000), pos(row0, col0) {}
  Person(std::string fname0, std::string lname0, const Position & pos0)
    : fname(fname0), lname(lname0), energy(1000), pos(pos0) {}
  std::string get_fname() const { return fname; }
  std::string get_lname() const { return lname; }
  int get_row() const { return pos.get_row(); }
  int get_col() const { return pos.get_col(); }
  Position get_pos() const { return pos; }
  int get_energy() const { return energy; }

  void fight(Person & p)
  {
    std::cout << "POW!!!" << std::endl;
    energy -= rand() % 100;
    p.energy -= rand() % 100;
  }

  void fightwith(Person & p, Weapon w)
  {
    std::cout << "POW!!!" << std::endl;
    energy -= rand() % 100;
    p.energy -= rand() % 100;
  }

  bool is_alive() const
  {
    return energy > 0;
  }

  void pickup(Weapon w)
  {
    weapon.push_back(w);
  }
private:
  std::string fname;
  std::string lname;
  Position pos;
  int energy;
  std::vector< Weapon > weapon;
};

std::ostream & operator<<(std::ostream & cout, const Person & p)
{
  cout << "<Person, " 
       << Thing(p)
       << ", fname:" << p.get_fname() << ", "
       << "lname:" << p.get_lname() << ", "
       << "pos:" << p.get_pos() << ", "
       << "energy:" << p.get_energy()
       << ">";
  return cout;
}


int main()
{
  srand(time(NULL));

  Thing s, t, u;
  std::cout << s << std::endl;
  std::cout << t << std::endl;
  std::cout << u << std::endl;

  Person johnDoe("John", "Doe", Position(10, 20));
  std::cout << johnDoe << std::endl;

  Person joshFriend("Josh", "Friend");
  std::cout << joshFriend << std::endl;

  while (joshFriend.is_alive() && johnDoe.is_alive())
    {
      joshFriend.fight(johnDoe); 
      std::cout << johnDoe << std::endl;
      std::cout << joshFriend << std::endl;
      std::cout << std::endl;
    }

  if (!joshFriend.is_alive()) 
    std::cout << "josh is dead" << std::endl;

  if (!johnDoe.is_alive()) 
    std::cout << "john is dead" << std::endl;

  return 0;
}
