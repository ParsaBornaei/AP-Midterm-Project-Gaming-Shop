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
class Wallet
{
private:
	double Value = 0;
	double Charge;
public:
	void ChargeWallet()
	{
		cout << "Please enter the desired recharge amount: ";
		cin >> Charge;
		Value += Charge;
		cout << "Your wallet has been recharged with " << Charge << ".\n\n";
	}
	void CostWallet(double& Changes)
	{
		Value -= Changes;
		cout << "The amount of " << Changes << "was deducted from your wallet." << "Your account balance: " << Value << "\n\n";
	}
	void RemainingWallet()
	{
		cout << "Your wallet balance: " << Value << "\n\n";
	}
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
	void Financial_Value_Of_The_Store()
	{
		for (Console ConS : consoles)
		{
			Value += (ConS.price) * (ConS.inventory);
		}
		for (Monitor MonT : monitors)
		{
			Value += (MonT.price) * (MonT.inventory);
		}
		for (Headset HeaD : headsets)
		{
			Value += (HeaD.price) * (HeaD.inventory);
		}
		for (Game GamE : games)
		{
			Value += (GamE.price) * (GamE.inventory);
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

class ShoppingCart
{
private:
	int totalprice;
	GamingShop &shop;                   //Wallet should be added later
	vector<Console> console;
	vector<Monitor> monitor;
	vector<Headset> headset;
	vector<Game> game;

public:
	ShoppingCart(GamingShop &Shop) : shop(Shop) {}
	int calculatetotal(ItemType item)
	{
		int total = 0;
		switch (item)
		{
		case ItemType::console:
			for (Console C : shop.consoles)
			{
				total += C.inventory;
			}
			break;
		case ItemType::monitor:
			for (Monitor M : shop.monitors)
			{
				total += M.inventory;
			}
			break;
		case ItemType::headset:
			for (Headset H : shop.headsets)
			{
				total += H.inventory;
			}
			break;
		case ItemType::game:
			for (Game G : shop.games)
			{
				total += G.inventory;
			}
			break;
		}

		return total;
	}
	void GetData()
	{
		cout << "Products in stock\n-----------------------------------------------------\n";
		cout << "1) Consoles(" << calculatetotal(ItemType::console) << endl;
		cout << "2) Monitors(" << calculatetotal(ItemType::monitor) << endl;
		cout << "3) Headsets(" << calculatetotal(ItemType::headset) << endl;
		cout << "4) Games(" << calculatetotal(ItemType::game) << endl;
		cout << "-----------------------------------------------------\n";
	}
	void ShowData(int n)
	{
		switch (n)
		{
		case 1:
			cout << "Consoles-------\n";
			for (Console ConS : shop.consoles)
			{
				cout << "Console\nName: " << ConS.name << endl
					 << "Inventory: " << ConS.inventory << endl
					 << "Price: " << ConS.price << "\n\n";
			}
			cout << "-------------------------------------------------------\n";
			break;
		case 2:
			cout << "Monitors-------\n";
			for (Monitor MonT : shop.monitors)
			{
				cout << "Monitor\nName: " << MonT.name << endl
					 << "Inventory: " << MonT.inventory << endl
					 << "Price: " << MonT.price << "\n\n";
			}
			cout << "-------------------------------------------------------\n";
			break;
		case 3:
			cout << "Headsets-------\n";
			for (Headset HeaD : shop.headsets)
			{
				cout << "Headset\nName: " << HeaD.name << endl
					 << "Inventory: " << HeaD.inventory << endl
					 << "Price: " << HeaD.price << "\n\n";
			}
			cout << "-------------------------------------------------------\n";
			break;
		case 4:
			cout << "Games----------\n";
			for (Game GamE : shop.games)
			{
				cout << "Game\nName: " << GamE.name << endl
					 << "Inventory: " << GamE.inventory << endl
					 << "Price: " << GamE.price << "\n\n";
			}
			cout << "-------------------------------------------------------\n";
			break;
		}
	}
	int SearchByName(string name)
	{

	}
	void AddToCart(string name, int n)
	{
		int amount = 0;

		switch (n)
		{
		case 1:
			for (int i = 0; i < shop.consoles.size(); i++)
			{
				if (name == shop.consoles[i].name)
				{
					while (true)
					{
						cout << "How many do you want? (" << shop.consoles[i].inventory << " Available)\n";
						cin >> amount;
						if (amount < shop.consoles[i].inventory)
						{
							console.push_back(Console(name, amount, shop.consoles[i].price));
							// shop.consoles[i].inventory -= amount;
							break;
						}
						else if (amount == shop.consoles[i].inventory)
						{
							console.push_back(Console(name, amount, shop.consoles[i].price));
							// shop.consoles.erase(shop.consoles.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < shop.monitors.size(); i++)
			{
				if (name == shop.monitors[i].name)
				{
					while (true)
					{
						cout << "How many do you want? (" << shop.monitors[i].inventory << " Available)";
						cin >> amount;
						if (amount < shop.monitors[i].inventory)
						{
							console.push_back(Console(name, amount, shop.monitors[i].price));
							shop.monitors[i].inventory -= amount;
							break;
						}
						else if (amount == shop.monitors[i].inventory)
						{
							console.push_back(Console(name, amount, shop.monitors[i].price));
							shop.monitors.erase(shop.monitors.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < shop.headsets.size(); i++)
			{
				if (name == shop.headsets[i].name)
				{
					while (true)
					{
						cout << "How many do you want? (" << shop.headsets[i].inventory << " Available)";
						cin >> amount;
						if (amount < shop.headsets[i].inventory)
						{
							console.push_back(Console(name, amount, shop.headsets[i].price));
							shop.headsets[i].inventory -= amount;
							break;
						}
						else if (amount == shop.headsets[i].inventory)
						{
							console.push_back(Console(name, amount, shop.headsets[i].price));
							shop.headsets.erase(shop.headsets.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < shop.games.size(); i++)
			{
				if (name == shop.games[i].name)
				{
					while (true)
					{
						cout << "How many do you want? (" << shop.games[i].inventory << " Available)";
						cin >> amount;
						if (amount < shop.games[i].inventory)
						{
							console.push_back(Console(name, amount, shop.games[i].price));
							shop.games[i].inventory -= amount;
							break;
						}
						else if (amount == shop.games[i].inventory)
						{
							console.push_back(Console(name, amount, shop.games[i].price));
							shop.games.erase(shop.games.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		}
	}
	void RemoveFromCart(string name, int n)
	{
		int amount = 0;
		switch (n)
		{
		case 1:
			for (int i = 0; i < console.size(); i++)
			{
				if (name == console[i].name)
				{
					while (true)
					{
						cout << "How many do you want to remove? (" << console[i].inventory << " In your Cart)\n";
						cin >> amount;
						if (amount < console[i].inventory)
						{
							console[i].inventory -= amount;
							break;
						}
						else if (amount == console[i].inventory)
						{
							console.erase(console.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "you don't have this much in your cart!, Do you want to try agin?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < monitor.size(); i++)
			{
				if (name == monitor[i].name)
				{
					while (true)
					{
						cout << "How many do you want to remove? (" << monitor[i].inventory << " In your Cart)\n";
						cin >> amount;
						if (amount < monitor[i].inventory)
						{
							monitor[i].inventory -= amount;
							break;
						}
						else if (amount == monitor[i].inventory)
						{
							monitor.erase(monitor.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "you don't have this much in your cart!, Do you want to try agin?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < headset.size(); i++)
			{
				if (name == headset[i].name)
				{
					while (true)
					{
						cout << "How many do you want to remove? (" << headset[i].inventory << " In your Cart)\n";
						cin >> amount;
						if (amount < headset[i].inventory)
						{
							headset[i].inventory -= amount;
							break;
						}
						else if (amount == headset[i].inventory)
						{
							headset.erase(headset.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "you don't have this much in your cart!, Do you want to try agin?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < game.size(); i++)
			{
				if (name == game[i].name)
				{
					while (true)
					{
						cout << "How many do you want to remove? (" << game[i].inventory << " In your Cart)\n";
						cin >> amount;
						if (amount < game[i].inventory)
						{
							game[i].inventory -= amount;
							break;
						}
						else if (amount == game[i].inventory)
						{
							game.erase(game.begin() + i);
							break;
						}
						else
						{
							char ch;
							cout << "you don't have this much in your cart!, Do you want to try agin?(y/n)";
							cin >> ch;
							if (ch == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			break;
		}
	}

	void ClearCart()
	{
		console.clear();
		console.shrink_to_fit();
		monitor.clear();
		monitor.shrink_to_fit();
		headset.clear();
		headset.shrink_to_fit();
		game.clear();
		game.shrink_to_fit();
	}

	void Finalize()
	{
		for(Console C : console)
		{
			for(int i=0;i<shop.consoles.size();i++)
			{
				if(C.name == shop.consoles[i].name)
				{
					if(C.inventory < shop.consoles[i].inventory)
					{
						shop.consoles[i].inventory -= C.inventory;
					}
					else if(C.inventory == shop.consoles[i].inventory)
					{
						shop.consoles.erase(shop.consoles.begin() + i);
						shop.consoles.shrink_to_fit();
					}
				}
			}
		}
		for(Monitor C : monitor)
		{
			for(int i=0;i<shop.monitors.size();i++)
			{
				if(C.name == shop.monitors[i].name)
				{
					if(C.inventory < shop.monitors[i].inventory)
					{
						shop.monitors[i].inventory -= C.inventory;
					}
					else if(C.inventory == shop.monitors[i].inventory)
					{
						shop.monitors.erase(shop.monitors.begin() + i);
						shop.monitors.shrink_to_fit();
					}
				}
			}
		}
		for(Headset C : headset)
		{
			for(int i=0;i<shop.headsets.size();i++)
			{
				if(C.name == shop.headsets[i].name)
				{
					if(C.inventory < shop.headsets[i].inventory)
					{
						shop.headsets[i].inventory -= C.inventory;
					}
					else if(C.inventory == shop.headsets[i].inventory)
					{
						shop.headsets.erase(shop.headsets.begin() + i);
						shop.headsets.shrink_to_fit();
					}
				}
			}
		}
		for(Game C : game)
		{
			for(int i=0;i<shop.games.size();i++)
			{
				if(C.name == shop.games[i].name)
				{
					if(C.inventory < shop.games[i].inventory)
					{
						shop.games[i].inventory -= C.inventory;
					}
					else if(C.inventory == shop.games[i].inventory)
					{
						shop.games.erase(shop.games.begin() + i);
						shop.games.shrink_to_fit();
					}
				}
			}
		}
		ClearCart();
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
				else
				{
					ok = false;
					break;
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

void CustomerMenu(ShoppingCart &Cart, GamingShop& Shop)
{
	int choice;
	string name;

	do
	{
		cout << "1) Add to cart" << endl;
		cout << "2) Categorized List of Products" << endl;
		cout << "3) List of all products" << endl;
		cout << "4) Customers_Money_Management" << endl;
		cout << "5) Shopping Cart" << endl;
		cout << "6) LogOut" << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			while(true)
			{
				cout<<"1) Enter the product's name to buy\n2) Show a Categorized List\n";
				int choice;
				cin >> choice;
				if(choice == 1)
				{

				}
				else if(choice == 2)
				{

				}
			}
			break;
		case 2:
			while(true)
			{
				Cart.GetData();
				cout << "1) Search for a specific Product\n2)Quit\n";
				int choice;
				cin >> choice;
				if(choice == 1)
				{
					cout << "Enter the number of product type you want to see: ";
					cin >> choice;
					Cart.ShowData(choice);
					cout << "Press Enter to go back ...";
					cin.ignore();
					cin.get();
					cout <<"\033c";
				}
				else break;
			}
			break;
		case 3:
			Shop.ShowDisplay();
			break;
		case 4:
			// Payment(name, ValueGamingShop, ValueCustomer);
			break;
		case 5:
			return;
		}
	} while (true);
}

void RoleSwitching(string &Password, GamingShop &Shop,ShoppingCart &Cart)
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
			CustomerMenu(Cart,Shop);
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
	ShoppingCart Cart(Shop);
	Wallet AdminWallet, CustomerWallet;
	string Password;
	RoleSwitching(Password, Shop,Cart);
	return 0;
}