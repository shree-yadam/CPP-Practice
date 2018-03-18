/* 3) Let’s create a random monster generator. This one should be fun.

3a) First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional MAX_MONSTER_TYPES enum so we can count how many enumerators there are.

3b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType), a name (std::string), a roar (std::string), and the number of hit points (int). Create a Monster class that has these 4 member variables.

3c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration.

3d) Create a constructor that allows you to initialize all of the member variables.
3e) Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going to need to write a function that converts a MonsterType into a std::string. Write that function (called getTypeString()), as well as a print() member function.

3f) Now we can create a random monster generator. Let’s consider how our MonsterGenerator class will work. Ideally, we’ll ask it to give us a Monster, and it will create a random one for us. We don’t need more than one MonsterGenerator. This is a good candidate for a static class (one in which all functions are static). Create a static MonsterGenerator class. Create a static function named generateMonster(). This should return a Monster. For now, make it return anonymous Monster(Monster::Skeleton, “Bones”, “*rattle*”, 4);

3g) Now, MonsterGenerator needs to generate some random attributes. 

3h) Now edit function generateMonster() to generate a random MonsterType (between 0 and Monster::MAX_MONSTER_TYPES-1) and a random hit points (between 1 and 100). This should be fairly straightforward. Once you’ve done that, define two static fixed arrays of size 6 inside the function (named s_names and s_roars) and initialize them with 6 names and 6 sounds of your choice. Pick a random name from these arrays.

*/

#include <iostream>
#include <string>
#include <ctime> //for time()
#include <cstdlib> //for rand() and srand()

#define __3A__
#define __3B__
#define __3D__
#define __3E__
#define __3F__
#define __3G__
#define __3H__

#ifdef __3B__
class Monster
{
	public:
#ifdef __3A__
		enum MonsterType
		{
			Dragon,
			Goblin,
			Ogre,
			Orc,
			Skeleton,
			Troll,
			Vampire,
			Zombie,
			MAX_MONSTER_TYPES
		};
#endif
	private:
		MonsterType m_type;
		std::string m_name;
		std::string m_roar;
		int m_hit_points;
#endif
	public:

#ifdef __3D__
		Monster(MonsterType type, std::string name, std::string roar, \
			int hit_points):m_type(type),m_name(name), m_roar(roar), \
			m_hit_points(hit_points) { }
#endif

#ifdef __3E__
		std::string getTypeString() const
		{
			switch (m_type)
			{
				case Dragon:
					return "Dragon";
					break;
				
				case Goblin:
					return "Goblin";
					break;

				case Ogre:
					return "Ogre";
					break;

				case Orc:
					return "Orc";
					break;

				case Skeleton:
					return "Skeleton";
					break;
			
				case Troll:
					return "Troll";
					break;

				case Vampire:
					return "Vampire";
					break;

				case Zombie:
					return "Zombie";
					break;
			}
			return "Error";
		}

		void print()
		{
			std::cout<<m_name<<" the "<<std::string(getTypeString())<< \
				" has "<<m_hit_points<<" hit points and says "<<m_roar<< \
				std::endl;
		}
#endif

#ifdef __3G__
		// Generate a random number between min and max (inclusive)
		// Assumes srand() has already been called
		static int getRandomNumber(int min, int max)
		{
			static const double fraction = 1.0 / \
				(static_cast<double>(RAND_MAX) + 1.0);  
			// static used for efficiency, so we only calculate this 
			// value once evenly distribute the random number across 
			//our range
			return static_cast<int>(rand() * fraction * (max - min + 1) + \
			min);
		}
#endif

#ifdef __3B__
};
#endif

#ifdef __3F__
class MonsterGenerator
{
	public:
		static Monster generateMonster();
};

Monster MonsterGenerator::generateMonster()
{
#ifdef __3H__
	static std::string s_names[6] = {"Bones", "Horror", "Mesa", "Gyro", "Zumbo",\
									"Squiggly"};
	static std::string s_roars[6] = {"roar", "burp", "crunch", "rip", "moan", \
									"screech"};
	return Monster(static_cast<Monster::MonsterType>(Monster::getRandomNumber(0,Monster::MAX_MONSTER_TYPES-1)), \
				s_names[Monster::getRandomNumber(0,5)], \
				s_roars[Monster::getRandomNumber(0,5)], \
				Monster::getRandomNumber(0,100));
#elif defined __3F__
	return Monster(Monster::Skeleton, "Bones", "*rattle*", 4);
#endif
}

#endif

#ifdef __3H__
int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();
 
    return 0;
}
#elif defined __3F__
int main()
{
	Monster m = MonsterGenerator::generateMonster();
	m.print();
 
    return 0;
}

#elif defined __3E__
int main()
{
	Monster skele(Monster::Skeleton, "Bones", "*rattle*", 4);
#ifndef __3D__
	skele.print();
#endif
 
    return 0;
}
#endif
