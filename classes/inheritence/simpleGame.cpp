/**Challenge time! The following quiz question is more difficult and lengthy. 
*We're going to write a simple game where you fight monsters. The goal of the 
*game is to collect as much gold as you can before you die or get to level 20.
*
*Our program is going to consist of 3 classes: A Creature class, a Player class,
* and a Monster class. Player and Monster both inherit from Creature.
*
*3a) First create the Creature class. Creatures have 5 attributes: A name 
*(std::string), a symbol (a char), an amount of health (int), the amount of 
*damage they do per attack (int), and the amount of gold they are carrying 
*(int). Implement these as class members. Write a full set of getters (a get 
*function for each member). Add three other functions: void reduceHealth(int) 
*reduces the Creature's health by an integer amount. bool isDead() returns true
* when the Creature's health is 0 or less. void addGold(int) adds gold to the 
*Creature
*3b) Now we're going to create the Player class. The Player class inherits from
* Creature. Player has one additional member, the player's level, which starts 
* at 1. The player has a custom name (entered by the user), uses symbol '@', has
* 10 health, does 1 damage to start, and has no gold. Write a function called 
*levelUp() that increases the player's level and damage by 1. Also write a 
*getter for the level member. Finally, write a function called hasWon() that 
*returns true if the player has reached level 20.
*3c) Next up is the Monster class. Monster also inherits from Creature. Monsters
* have no non-inherited member variables.
*
*First, write an empty Monster class inheriting from Creature, and then add an 
*enum inside the Monster class named Type that contains enumerators for the 3 
*monsters that we'll have in this game: DRAGON, ORC, and SLIME (you'll also 
*want a MAX_TYPES enumerator, as that will come in handy in a bit).
*
*/

#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature{
	private:
		std::string m_name;
		char m_symbol;
		int m_amtOfHealth;
		int m_amtOfDamage;
		int m_amtOfGold;
	
	public:
		Creature(std::string n, char s, int ah, int ad, int ag)
			:m_name(n), m_symbol(s), m_amtOfHealth(ah), m_amtOfDamage(ad),
				m_amtOfGold(ag) { }

		std::string getName()
		{
			return m_name;
		}

		char getSymbol()
		{
			return m_symbol;
		}
		
		int getHealth()
		{
			return m_amtOfHealth;
		}

		int getDamage()
		{
			return m_amtOfDamage;
		}

		int getGold()
		{
			return m_amtOfGold;
		}

		void reduceHealth(int n)
		{
			m_amtOfHealth -= n;
		}

		bool isDead()
		{
			return (m_amtOfHealth <= 0)? true : false;
		}

		void addGold(int g)
		{
			m_amtOfGold += g;
		}

		void increaseDamage()
		{
			m_amtOfDamage++;
		}
};
 
class Player:public Creature
{
	private:
		int m_playerLevel;

	public:
		Player(std::string name):Creature(name,'@',10,1,0),m_playerLevel(1){ }

		void levelUp()
		{
			m_playerLevel++;
			increaseDamage();
		}

		int getLevel()
		{
			return m_playerLevel;
		}

		bool hasWon()
		{
			return (m_playerLevel >= 20)?true : false;
		}	
};

class Monster: public Creature
{
	public:
		enum Type
		{
			DRAGON,
			ORC,
			SLIME,
			MAX_TYPES};

		struct MonsterData
		{
			std::string name;
			char symbol;
			int health;
			int damage;
			int gold;
		};

		static MonsterData monsterData[MAX_TYPES];	

		Monster(Type type)
			: Creature(monsterData[type].name,monsterData[type].symbol, 
			monsterData[type].health, monsterData[type].damage, 
			monsterData[type].gold){ }	

		static Monster getRandomMonster()
		{
			int type = getRandomNumber(0, MAX_TYPES-1);
			Monster monster(static_cast<Type>(type));
			return monster;
		}
			
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

void attackMonster(Monster& m, Player& p)
{
	m.reduceHealth(p.getDamage());
	std::cout<<"You hit the "<<m.getName()<<" for "<<p.getDamage()<<" damage.\n";

	if(m.isDead())
	{
		std::cout<<"You killed the "<<m.getName()<<".\n";
		p.levelUp();
		std::cout<<"You are now level "<<p.getLevel()<<".\n";
		p.addGold(m.getGold());
		std::cout<<"You found "<<m.getGold()<<" gold.\n";
	}
	
}

void attackPlayer(Monster& m, Player& p)
{
	p.reduceHealth(m.getDamage());
	std::cout<<"The "<<m.getName()<<" hit you for "<<m.getDamage()<<" damage.\n";

}

void fightMonster(Monster& m, Player& p)
{
	char choice;
	std::cout<<"(R)un or (F)ight: ";
	std::cin>>choice;
	choice = tolower(choice);
	if(choice == 'r')
	{	
		int chance = getRandomNumber(0,1);//deciding escaped or not
		if(chance == 0)//escapes
		{
			std::cout<<"You successfully fled.\n";
			return;
		}
		else//does not escape
		{	
			std::cout<<"You failed to flee.\n";
			attackPlayer(m,p);
			return;
		}
	}
	else
	{
		attackMonster(m,p);
		if(!m.isDead())
			attackPlayer(m,p);
	}
}

int main()
{
	std::string name;

	std::cout<<"Enter your name: ";
	std::cin>>name;

	Player p(name);

	std::cout<<"Welcome, "<<p.getName()<<".\n";
	while(!p.isDead() && p.getLevel() < 20)
	{
	 	Monster	m = Monster::getRandomMonster();
		std::cout<<"You have encountered a "<<m.getName()<<" ("
			<<m.getSymbol()<<").\n";
		fightMonster(m,p);

	}

	if(p.isDead())
	{
		std::cout<<"You died at level "<<p.getLevel()<<" and with "
			<<p.getGold()<<" gold\n";
		std::cout<<"Too bad you can't take it with you!\n";
	}
	
	if(p.getLevel() == 20)
	{
		std::cout<<"You won with "<<p.getGold()<<"gold\n";
	}
	return 0;
}
/*int main()
{
	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}*/
/*int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result
 
	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}
}*/
