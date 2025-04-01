#include <vector>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

enum ItemType
{
	console = 1,
	monitor,
	headset,
	game
};
class Item
{
public:
	ItemType itemType;
	string name;
	int inventory;
	double price;
	Item(string name, int inventory, double price) : name(name), inventory(inventory), price(price) {}
	// virtual void ShowDisplay();
};
class Console : public Item
{
public:
	Console(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::console; }
};
class Monitor : public Item
{
public:
	Monitor(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::monitor; }
};
class Headset : public Item
{
public:
	Headset(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::headset; }
};
class Game : public Item
{
public:
	Game(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::game; }
};
class GamingShop
{
private:
	double Value = 0;

public:
	vector<Console> consoles;
	vector<Monitor> monitors;
	vector<Headset> headsets;
	vector<Game> games;
	void Add(string name, int inventory, double price, ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::console:
			consoles.push_back(Console(name, inventory, price));
			break;
		case ItemType::monitor:
			monitors.push_back(Monitor(name, inventory, price));
			break;
		case ItemType::headset:
			headsets.push_back(Headset(name, inventory, price));
			break;
		case ItemType::game:
			games.push_back(Game(name, inventory, price));
			break;
		}
	}

	void Remove(string name, ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::console:
			for (int i = 0; i < consoles.size(); i++)
			{
				if (consoles[i].name == name)
				{
					consoles.erase(consoles.begin() + (i));
					break;
				}
			}
			break;
		case ItemType::monitor:
			for (int i = 0; i < monitors.size(); i++)
			{
				if (monitors[i].name == name)
				{
					monitors.erase(monitors.begin() + (i));
					break;
				}
			}
			break;
		case ItemType::headset:
			for (int i = 0; i < headsets.size(); i++)
			{
				if (headsets[i].name == name)
				{
					headsets.erase(headsets.begin() + (i));
					break;
				}
			}
			break;
		case ItemType::game:
			for (int i = 0; i < games.size(); i++)
			{
				if (games[i].name == name)
				{
					games.erase(games.begin() + (i));
					break;
				}
			}
			break;
		default:
			break;
		}
	}
	void Financial_Value_Of_The_Store()                                          //Required Fix: you have to multiple the price with quantity
	{
		for (Console ConS : consoles)
		{
			Value += (ConS.price)*(ConS.inventory);
		}
		for (Monitor MonT : monitors)
		{
			Value += (MonT.price)*(MonT.inventory);
		}
		for (Headset HeaD : headsets)
		{
			Value += (HeaD.price)*(HeaD.inventory);
		}
		for (Game GamE : games)
		{
			Value += (GamE.price)*(GamE.inventory);
		}
		cout << "Total value gaming shop: " << Value << "\n\n";
	}
	void ShowDisplay()
	{
		for (Console ConS : consoles)
		{
			cout << "Console\nName: " << ConS.name << endl
				 << "Inventory: " << ConS.inventory << endl
				 << "Price: " << ConS.price << "\n\n";
		}
		for (Monitor MonT : monitors)
		{
			cout << "Monitor\nName: " << MonT.name << endl
				 << "Inventory: " << MonT.inventory << endl
				 << "Price: " << MonT.price << "\n\n";
		}
		for (Headset HeaD : headsets)
		{
			cout << "Headset\nName: " << HeaD.name << endl
				 << "Inventory: " << HeaD.inventory << endl
				 << "Price: " << HeaD.price << "\n\n";
		}
		for (Game GamE : games)
		{
			cout << "Game\nName: " << GamE.name << endl
				 << "Inventory: " << GamE.inventory << endl
				 << "Price: " << GamE.price << "\n\n";
		}
	}
};

string ChangePassword()
{
	string pass;
	bool check = false;
	while (check == false)
	{
		char choice;
		cout << "Do you want to change your password?(y/n) ";
		cin >> choice;
		if (choice == 'y')
		{
			cout << "Enter the password you want: (It should ONLY contain one of the . @ ! & * ^ Symbols)\n";
			cout << "Password: ";
			pass = "";
			bool ok = false;
			cin >> pass;
			for (char ch : pass)
			{
				if (ch == '.' || ch == '&' || ch == '*' || ch == '!' || ch == '@' || ch == '^' || (ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
				{
					ok = true;
				}
			}
			if (ok)
			{
				cout << "Password is set\n";
				check = true;
			}
			else
			{
				cout << "Password was not correct,Try again!\n";
			}
		}
		else
			break;
	}

	return pass;
}
void EnterPassword(string &Password)
{
	Password = "";
	char ch;
	const char ENTER = 13;
	cout << "Please enter the password: ";

	while ((ch = _getch()) != ENTER)
	{
		if (ch != 8)
		{
			Password += ch;
			cout << '*';
		}
		else if (ch == 8 && Password.length() > 0)
		{
			Password.pop_back();
			cout << "\b \b";
		}
	}
	cout << "\n";
}

void AdminMenu(string &Password, GamingShop &Shop)
{
	int choice, Item_Type;
	string Name;
	int Inventory;
	double Price;
	ItemType num;

	do
	{
		cout << "1) AddProduct" << endl;
		cout << "2) RemoveGame_And_Product" << endl;
		cout << "3) ShowInformations" << endl;
		cout << "4) CalculateTotalValue" << endl;
		cout << "5) GamingShop_Money_Management" << endl;
		cout << "6) Change the password" << endl;
		cout << "7) LogOut" << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Please choose type of product (choice number):\n1: Console\n2: Monitor\n3: Headset\n4: Game\n";
			cin >> Item_Type;
			num = static_cast<ItemType>(Item_Type);
			cout << "Please write the name: ";
			cin >> Name;
			cout << "Please write the inventory: ";
			cin >> Inventory;
			cout << "Please write the price: ";
			cin >> Price;
			Shop.Add(Name, Inventory, Price, num);
			break;
		case 2:
			cout << "Please choose type of product or game (choice number):\n1: Console\n2: Monitor\n3: Headset\n4: Game\n";
			cin >> Item_Type;
			num = static_cast<ItemType>(Item_Type);
			cout << "Please write the name: ";
			cin >> Name;
			Shop.Remove(Name, num);
			break;
		case 3:
			Shop.ShowDisplay();
			break;
		case 4:
			Shop.Financial_Value_Of_The_Store();
			break;
		case 5:
			// GamingShop_Money_Management(&ValueGamingShop);
			break;
		case 6:
			Password = ChangePassword();
			break;
		case 7:
			return;
		}
	} while (true);
}

void CustomerMenu(GamingShop &Shop)
{
	int choice;
	string name;

	do
	{
		cout << "1) SearchGame (buy game)" << endl;
		cout << "2) ShowInformations" << endl;
		cout << "3) Customers_Money_Management" << endl;
		cout << "4) Payment" << endl;
		cout << "5) LogOut" << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			// SearchGame(name);
			break;
		case 2:
			// Shop.ShowDisplay();
			break;
		case 3:
			// Customers_Money_Management(&ValueCustomer);
			break;
		case 4:
			// Payment(name, ValueGamingShop, ValueCustomer);
			break;
		case 5:
			return;
		}
	} while (true);
}
void SearchGame(GamingShop &Shop)
{
	int Item_Type;
	string Name;
	int Inventory;
	int Price;
	ItemType num;
	Shop.ShowDisplay(); // We should make a function which finds most similar entry if the input one couldn't match
	cout << "--------------------------------------------------------------";
	cout << "Please choose type of product (choice number):\n1: Console\n2: Monitor\n3: Headset\n4: Game\n";
	cin >> Item_Type;
	num = static_cast<ItemType>(Item_Type);
	cout << "Please write the name: ";
	cin >> Name;
	cout << "Please write the inventory: ";
	cin >> Inventory;
	cout << "Please write the price: ";
	cin >> Price;
	Shop.Add(Name, Inventory, Price, num);
}
void RoleSwitching(string& Password, GamingShop& Shop)
{
	int number, choice;
	do
	{
		cout << "Please choose your identity with number ( 1: Administration /  2: Customers  /  3: Exit ) : ";
		cin >> number;

		if (number == 1)
		{
			// Admin Role
			EnterPassword(Password);
			bool ok = false;
			while (ok == false)
			{
				if (Password == "admin1admin")
				{
					AdminMenu(Password, Shop);
					ok = true;
				}
				else
				{
					cout << "Your password is incorrect!" << endl;
					cout << "(choose with number) \n 1: Back \n 2: Try Again ";
					cin >> choice;
					if (choice == 1)
					{
						break;
					}
					else if (choice == 2)
					{
						EnterPassword(Password);
					}
				}
			}
		}
		else if (number == 2)
		{
			// Customer Role
			CustomerMenu(Shop);
		}
		else if (number == 3)
		{
			return;
		}
	} while (true);
}
int main()
{
	GamingShop Shop;
	string Password;

	RoleSwitching(Password, Shop);
	return 0;
}