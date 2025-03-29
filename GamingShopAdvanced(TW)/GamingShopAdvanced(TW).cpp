#include <vector>
#include <iostream>
#include <conio.h>
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
	Item(){}
	Item(string name , int inventory , double price) : name(name), inventory(inventory) , price(price){}
	//virtual void ShowDisplay();
};
class Console : public Item
{
public:
	Console()
	{
		itemType = ItemType::console;
	}
	Console(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::console; }
};
class Monitor : public Item
{
public:
	Monitor()
	{
		itemType = ItemType::monitor;
	}
	Monitor(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::monitor; }
};
class Headset : public Item
{
public:
	Headset()
	{
		itemType = ItemType::headset;
	}
	Headset(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::headset; }
};
class Game : public Item
{
public:
	Game()
	{
		itemType = ItemType::game;
	}
	Game(string name, int inventory, double price) : Item(name, inventory, price) { itemType = ItemType::game; }
};
class GamingShop
{
public:
	vector<Console*>consoles;
	vector<Monitor*>monitors;
	vector<Headset*>headses;
	vector<Game*>games;
	void Add(string name, int inventory, double price , ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::console : 
			Console* console = new Console(name, inventory, price);
			consoles.push_back(console);
			break;
		case ItemType::monitor :
			Monitor* monitor = new Monitor(name, inventory, price);
			monitors.push_back(monitor);
			break;
		case ItemType::headset :
			Headset* headset = new Headset(name, inventory, price);
			headses.push_back(headset);
			break;
		case ItemType::game :
			Game* game = new Game(name, inventory, price);
			games.push_back(game);
			break;
		default:
			break;
		}
	}
	void ShowDisplay()
	{
		for (Console* ConS : consoles)
		{
			cout << "Console\nName: " << ConS->name << endl <<"Inventory: " << ConS->inventory << endl << "Price: " << ConS->price << "\n\n";
		}
		for (Monitor* MonT : monitors)
		{
			cout << "Monitor\nName: " << MonT->name << endl << "Inventory: " << MonT->inventory << endl << "Price: " << MonT->price << "\n\n";
		}
		for (Headset* HeaD : headses)
		{
			cout << "Headset\nName: " << HeaD->name << endl << "Inventory: " << HeaD->inventory << endl << "Price: " << HeaD->price << "\n\n";
		}
		for (Game* GamE : games)
		{
			cout << "Game\nName: " << GamE->name << endl << "Inventory: " << GamE->inventory << endl << "Price: " << GamE->price << "\n\n";
		}
	}
};


int main()
{
    GamingShop Shop;
	string Password;
	int number ,Item_Type;
	double Price;
	string Name;
	int choice , Inventory;
	do {
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
					cin >> Name;
					cin >> Inventory;
					cin >> Price;
					Shop.Add(Name,Inventory,Price,num);
					goto menu;
					// افزودن بازی
					break;
				case 2:
					int x;
					cout << "Please choose type of product or game (choice number) :" << endl;
					cout << "1: Console" << endl;
					cout << "2: Monitor" << endl;
					cout << "3: Headset" << endl;
					cout << "4: Game" << endl;
					cin >> x;
					cout << "Please write the name : ";
					cin >> Name;
					RemoveGame_And_Product(Name, x);
					goto menu;
					// حذف بازی
					break;
				case 3:
					Shop.ShowDisplay();
					goto menu;
					break;
				case 4:
					CalculateTotalValue();
					goto menu;
					break;
				case 5:
					GamingShop_Money_Management(&ValueGamingShop);
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
				SearchGame(name);
				goto Customer;
				break;
			case 2:
				Shop.ShowDisplay();
				goto Customer;
				break;
			case 3:
				Customers_Money_Management(&ValueCustomer);
				goto Customer;
				break;
			case 4:
				Payment(name, ValueGamingShop, ValueCustomer);
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