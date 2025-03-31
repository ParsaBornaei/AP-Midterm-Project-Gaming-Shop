#include <vector>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

enum ItemType
{
	console,
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
			consoles.push_back(Console(name, inventory, price)); // Fix this
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
		default:
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

string MakePassword(bool IsMade)
{	
	string pass;
	if(IsMade == false)
	{		
		bool check=false;
		while(check == false)
		{
			cout << "Enter the password you want: (It should ONLY contain one of the . @ ! & * ^ Symbols)\n";
			cout << "Password: ";
			pass = "";
			bool ok = false;
			cin >> pass;
			for(char ch : pass)
			{
				if(ch == '.' || ch == '&' || ch == '*' || ch == '!' || ch == '@' || ch == '^' || ((ch >= 97 || ch <= 122) && (ch >= 65 || ch <= 90))) ok == true;
			}
			if(ok) cout << "Password is set\n";
			else
			{
				cout << "Password was not correct,Try again!\n";
			}
		}
	}
	else
	{
		bool check=false;
		while(check == false)
		{
			char choice;
			cout << "Do you want to change your password?(y/n) ";
			cin >> choice;
			if(choice == 'y')
			{
				cout << "Enter the password you want: (It should ONLY contain one of the . @ ! & * ^ Symbols)\n";
				cout << "Password: ";
				pass = "";
				bool ok = false;
				cin >> pass;
				for(char ch : pass)
				{
					if(ch == '.' || ch == '&' || ch == '*' || ch == '!' || ch == '@' || ch == '^' || ((ch >= 97 || ch <= 122) && (ch >= 65 || ch <= 90))) ok == true;
				}
				if(ok) cout << "Password is set\n";
				else
				{
					cout << "Password was not correct,Try again!\n";
				}
			}
			else break;
		}
	}

	return pass;
}

int main()
{
	GamingShop Shop;
	string Password;
	int number, Item_Type;
	double Price;
	string Name;
	int choice, Inventory;
	bool IsPassMade = false;
	do
	{
	Roleـswitching:
		cout << "Please choose your identity with number ( 1: Administration /  2: Customers  /  3: Exit ) : ";
		cin >> number;
		if (number == 1)
		{
		TryAgain:
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
			if (Password == "admin1admin")
			{
			menu:
				cout << "1) AddProduct" << endl;
				cout << "2) RemoveGame_And_Product" << endl;
				cout << "3) ShowInformations" << endl;
				cout << "4) CalculateTotalValue" << endl;
				cout << "5) GamingShop_Money_Management" << endl;
				cout << "6) LogOut" << endl;
				cin >> choice;
				cout << endl;
				// نمایش منو و گرفتن انتخاب مدیر
				// ...
				switch (choice)
				{
				case 1:
					cout << "Please choose type of product (choice number) :" << endl;
					cout << "1: Console" << endl;
					cout << "2: Monitor" << endl;
					cout << "3: Headset" << endl;
					cout << "4: Game" << endl;
					cin >> Item_Type;
					ItemType num = static_cast<ItemType>(Item_Type);
					cout << "Please write the name: ";
					cin >> Name;
					cout << "Please write the inventory: ";
					cin >> Inventory;
					cout << "Please write the price: ";
					cin >> Price;
					Shop.Add(Name, Inventory, Price, num);
					goto menu;
					// افزودن بازی
					break;
				case 2:
					cout << "Please choose type of product or game (choice number) :" << endl;
					cout << "1: Console" << endl;
					cout << "2: Monitor" << endl;
					cout << "3: Headset" << endl;
					cout << "4: Game" << endl;
					cin >> Item_Type;
					ItemType num = static_cast<ItemType>(Item_Type);
					cout << "Please write the name: ";
					cin >> Name;
					Shop.Remove(Name, num);
					goto menu;
					// حذف بازی
					break;
				case 3:
					// نمایش کالاهای موجود در فروشگاه
					Shop.ShowDisplay();
					goto menu;
					break;
				case 4:
					//CalculateTotalValue();
					goto menu;
					break;
				case 5:
					// کیف پول مدیر و حساب و دارایی های فروشگاه
					//GamingShop_Money_Management(&ValueGamingShop);
					goto menu;
					break;
				case 6:
					goto Roleـswitching;
					break;
				}
			}
			else
			{
				cout << "your password is incorrect ! " << endl;
				cout << "(choose with number) \n 1: Back \n 2: Try Again ";
				int Back_continue;
				cin >> Back_continue;
				if (Back_continue == 2)
				{
					goto TryAgain;
				}
				else if (Back_continue == 1)
				{
					goto Roleـswitching;
				}
			}
		}
		else if (number == 2)
		{
		Customer:
			cout << "1) SearchGame ( buy game )" << endl;
			cout << "2) ShowInformations" << endl;
			cout << "3) Customers_Money_Management" << endl;
			cout << "4) Payment" << endl;
			cout << "5) LogOut" << endl;
			cin >> choice;
			cout << endl;
			// نمایش منو و گرفتن انتخاب کاربر
			// ...
			switch (choice)
			{
			case 1:
				//SearchGame(name);
				goto Customer;
				break;
			case 2:
				// نمایش کالاهای موجود در فروشگاه
				Shop.ShowDisplay();
				goto Customer;
				break;
			case 3:
				// کیف پول کاربر
				//Customers_Money_Management(&ValueCustomer);
				goto Customer;
				break;
			case 4:
				//Payment(name, ValueGamingShop, ValueCustomer);
				goto Customer;
				break;
			case 5:
				goto Roleـswitching;
				break;
			}
		}
		else if (number == 3)
		{
			return 0;
		}
	} while (choice != 0);
}