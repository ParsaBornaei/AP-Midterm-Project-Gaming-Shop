#include <vector>
#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>
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
		cout << "\x1b[36mPlease enter the desired recharge amount: \x1b[0m";
		cin >> Charge;
		Value += Charge;
		cout << "\x1b[1;32mYour wallet has been recharged with \x1b[0m" << Charge << "\x1b[33m$\x1b[0m" << ".\n\n";
	}
	void CostWallet(double& Changes)
	{
		Value -= Changes;
		cout << "\x1b[35mThe amount of \x1b[0m" << Changes << "\x1b[35m was deducted from your wallet.\x1b[0m" << "\x1b[35mYour account balance: \x1b[0m" << Value << "\x1b[33m$\x1b[0m" << "\n\n";
	}
	void RemainingWallet()
	{
		cout << "\x1b[34mYour wallet balance: \x1b[0m" << Value << "$\n\n";
	}
	void AddMoney(double Money)
	{
		Value += Money;
	}
	double Balance()
	{
		return Value;
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
		int choice, increase;
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

	void Change(string name, ItemType itemType, Wallet& AWallet)
	{
		int choice, increase;
		double NewPrice, Result;
		bool Validation ;
		switch (itemType)
		{
		case ItemType::console:
		{
			for (int i = 0; i < consoles.size(); i++)
			{
				if (consoles[i].name == name)
				{
					cout << "\x1b[33mThe desired product is available in the store. \nWould you like to make a change to the product?\x1b[0m\x1b[34m(\x1b[0m 1:\x1b[33m increase inventory\x1b[0m\x1b[34m/\x1b[0m 2:\x1b[33m Change price\x1b[0m\x1b[34m/\x1b[0m 3:\x1b[33m No Change(Back)\x1b[0m\x1b[34m)\x1b[0m: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "\x1b[31mWrite the desired number: \x1b[0m";
						cin >> increase;
						if (increase <= 0)
						{
							Validation = true;
							while (Validation)
							{


								cout << "\x1b[32mPlease enter a positive number: \x1b[0m";
								cin >> increase;
								if (increase > 0)
								{
									Validation = false;
								}
								else
								{
									continue;
								}
							}
						}
						Result = double(increase)*0.7*double(consoles[i].price);
						AWallet.CostWallet(Result);
						consoles[i].inventory += increase;
						cout << "\x1b[36mThe number of the desired product was successfully increased.\x1b[0m" << "\n\n";
						cout << "\x1b[36mPress enter to go back \x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 2:
						cout << "\x1b[36mEnter the new price: \x1b[0m";
						cin >> NewPrice;
						consoles[i].price = NewPrice;
						cout << "\x1b[35mNew product price: \x1b[0m" << consoles[i].price << "\n\n";
						cout << "\x1b[32mPress enter to go back\x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 3:
						return;
						break;
					default:
					{
						cout << "\x1b[35mYour choice incorrect!\x1b[0m" << "\n\n";
						return;
						break;
					}
					}
				}
			}
		}
		case ItemType::monitor:
		{
			for (int i = 0; i < monitors.size(); i++)
			{
				if (monitors[i].name == name)
				{
					cout << "\x1b[33mThe desired product is available in the store. \nWould you like to make a change to the product?\x1b[0m\x1b[34m(\x1b[0m 1:\x1b[33m increase inventory\x1b[0m\x1b[34m/\x1b[0m 2:\x1b[33m Change price\x1b[0m\x1b[34m/\x1b[0m 3:\x1b[33m No Change(Back)\x1b[0m\x1b[34m)\x1b[0m: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "\x1b[31mWrite the desired number: \x1b[0m";
						cin >> increase;
						if (increase <= 0)
						{
							Validation = true;
							while (Validation)
							{


								cout << "\x1b[32mPlease enter a positive number: \x1b[0m";
								cin >> increase;
								if (increase > 0)
								{
									Validation = false;
								}
								else
								{
									continue;
								}
							}
						}
						Result = double(increase) * 0.7 * double(monitors[i].price);
						AWallet.CostWallet(Result);
						monitors[i].inventory += increase;
						cout << "\x1b[36mThe number of the desired product was successfully increased.\x1b[0m" << "\n\n";
						cout << "\x1b[36mPress enter to go back \x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 2:
						cout << "\x1b[36mEnter the new price: \x1b[0m";
						cin >> NewPrice;
						monitors[i].price = NewPrice;
						cout << "\x1b[35mNew product price: \x1b[0m" << monitors[i].price << "\n\n";
						cout << "\x1b[32mPress enter to go back\x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 3:
						return;
						break;
					default:
					{
						cout << "\x1b[35mYour choice incorrect!\x1b[0m" << "\n\n";
						return;
						break;
					}
					}
				}
			}
		}
		case ItemType::headset:
		{
			for (int i = 0; i < headsets.size(); i++)
			{
				if (headsets[i].name == name)
				{
					cout << "\x1b[33mThe desired product is available in the store. \nWould you like to make a change to the product?\x1b[0m\x1b[34m(\x1b[0m 1:\x1b[33m increase inventory\x1b[0m\x1b[34m/\x1b[0m 2:\x1b[33m Change price\x1b[0m\x1b[34m/\x1b[0m 3:\x1b[33m No Change(Back)\x1b[0m\x1b[34m)\x1b[0m: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "\x1b[31mWrite the desired number: \x1b[0m";
						cin >> increase;
						if (increase <= 0)
						{
							Validation = true;
							while (Validation)
							{


								cout << "\x1b[32mPlease enter a positive number: \x1b[0m";
								cin >> increase;
								if (increase > 0)
								{
									Validation = false;
								}
								else
								{
									continue;
								}
							}
						}
						Result = double(increase) * 0.7 * double(headsets[i].price);
						AWallet.CostWallet(Result);
						headsets[i].inventory += increase;
						cout << "\x1b[36mThe number of the desired product was successfully increased.\x1b[0m" << "\n\n";
						cout << "\x1b[36mPress enter to go back \x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 2:
						cout << "\x1b[36mEnter the new price: \x1b[0m";
						cin >> NewPrice;
						headsets[i].price = NewPrice;
						cout << "\x1b[35mNew product price: \x1b[0m" << headsets[i].price << "\n\n";
						cout << "\x1b[32mPress enter to go back\x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 3:
						return;
						break;
					default:
					{
						cout << "\x1b[35mYour choice incorrect!\x1b[0m" << "\n\n";
						return;
						break;
					}
					}
				}
			}}
		case ItemType::game:
		{
			for (int i = 0; i < games.size(); i++)
			{
				if (games[i].name == name)
				{
					cout << "\x1b[33mThe desired product is available in the store. \nWould you like to make a change to the product?\x1b[0m\x1b[34m(\x1b[0m 1:\x1b[33m increase inventory\x1b[0m\x1b[34m/\x1b[0m 2:\x1b[33m Change price\x1b[0m\x1b[34m/\x1b[0m 3:\x1b[33m No Change(Back)\x1b[0m\x1b[34m)\x1b[0m: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "\x1b[31mWrite the desired number: \x1b[0m";
						cin >> increase;
						if (increase <= 0)
						{
							Validation = true;
							while (Validation)
							{


								cout << "\x1b[32mPlease enter a positive number: \x1b[0m";
								cin >> increase;
								if (increase > 0)
								{
									Validation = false;
								}
								else
								{
									continue;
								}
							}
						}
						Result = double(increase) * 0.7 * double(games[i].price);
						AWallet.CostWallet(Result);
						games[i].inventory += increase;
						cout << "\x1b[36mThe number of the desired product was successfully increased.\x1b[0m" << "\n\n";
						cout << "\x1b[36mPress enter to go back \x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 2:
						cout << "\x1b[36mEnter the new price: \x1b[0m";
						cin >> NewPrice;
						games[i].price = NewPrice;
						cout << "\x1b[35mNew product price: \x1b[0m" << games[i].price << "\n\n";
						cout << "\x1b[32mPress enter to go back\x1b[0m \n";
						cin.ignore();
						cin.get();
						return;
						break;
					case 3:
						return;
						break;
					default:
						cout << "\x1b[35mYour choice incorrect!\x1b[0m" << "\n\n";
						return;
						break;
					}
				}
			}
		}
		}
	}

	bool CheckName(string name, ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::console:
			for (int i = 0; i < consoles.size(); i++)
			{
				if (consoles[i].name == name)
				{
					return true;
				}
			}
			break;
		case ItemType::monitor:
			for (int i = 0; i < monitors.size(); i++)
			{
				if (monitors[i].name == name)
				{
					return true;
				}
			}
			break;
		case ItemType::headset:
			for (int i = 0; i < headsets.size(); i++)
			{
				if (headsets[i].name == name)
				{
					return true;
				}
			}
			break;
		case ItemType::game:
		{
			for (int i = 0; i < games.size(); i++)
			{
				if (games[i].name == name)
				{
					return true;
				}
			}
			break;
		}
		default:
		{
			return false;
		}
		}
		return false;
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
		cout << "\x1b[32mTotal value of the gaming shop: \x1b[0m" << Value << "\x1b[33m$\x1b[0m" << "\n\n";
	}
	void ShowDisplay()
	{
		for (Console ConS : consoles)
		{
			cout << "\x1b[35mConsole\x1b[0m\n\x1b[36mName: \x1b[0m" << ConS.name << endl
				<< "\x1b[36mAvailable Stock: \x1b[0m" << ConS.inventory << endl
				<< "\x1b[36mPrice: \x1b[0m" << ConS.price <<"\x1b[33m$\x1b[0m"<< "\n\n";
		}
		for (Monitor MonT : monitors)
		{
			cout << "\x1b[35mMonitor\x1b[0m\n\x1b[36mName: \x1b[0m" << MonT.name << endl
				<< "\x1b[36mAvailable Stock: \x1b[0m" << MonT.inventory << endl
				<< "\x1b[36mPrice: \x1b[0m" << MonT.price << "\x1b[33m$\x1b[0m" << "\n\n";
		}
		for (Headset HeaD : headsets)
		{
			cout << "\x1b[35mHeadset\x1b[0m\n\x1b[36mName: \x1b[0m" << HeaD.name << endl
				<< "\x1b[36mAvailable Stock: \x1b[0m" << HeaD.inventory << endl
				<< "\x1b[36mPrice: \x1b[0m" << HeaD.price << "\x1b[33m$\x1b[0m" << "\n\n";
		}
		for (Game GamE : games)
		{
			cout << "\x1b[35mGame\x1b[0m\n\x1b[36mName: \x1b[0m" << GamE.name << endl
				<< "\x1b[36mAvailable Stock: \x1b[0m" << GamE.inventory << endl
				<< "\x1b[36mPrice: \x1b[0m" << GamE.price << "\x1b[33m$\x1b[0m" << "\n\n";
		}
	}
};

class ShoppingCart
{
private:
	bool IsSync = true;
	double totalprice;
	Wallet& wallet;
	GamingShop& shop;
	vector<Console> console;
	vector<Monitor> monitor;
	vector<Headset> headset;
	vector<Game> game;

public:
	ShoppingCart(GamingShop& Shop, Wallet& Cwallet) : shop(Shop), wallet(Cwallet) {}
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
		cout << "\x1b[34mProducts in stock\x1b[0m\n\x1b[33m-----------------------------------------------------\x1b[0m\n";
		cout << "\x1b[35m1)\x1b[0m \x1b[36mConsoles(\x1b[0m" << calculatetotal(ItemType::console) <<"\x1b[36m)\x1b[0m"<< endl;
		cout << "\x1b[35m2)\x1b[0m \x1b[36mMonitors(\x1b[0m" << calculatetotal(ItemType::monitor) <<"\x1b[36m)\x1b[0m"<< endl;
		cout << "\x1b[35m3)\x1b[0m \x1b[36mHeadsets(\x1b[0m" << calculatetotal(ItemType::headset) <<"\x1b[36m)\x1b[0m"<< endl;
		cout << "\x1b[35m4)\x1b[0m \x1b[36mGames(\x1b[0m" << calculatetotal(ItemType::game) <<"\x1b[36m)\x1b[0m"<< endl;
		cout << "\x1b[33m-----------------------------------------------------\x1b[0m\n";
	}
	void ShowData(int n)
	{
		switch (n)
		{
		case 1:
			cout << "\x1b[34mConsoles-------\x1b[0m\n";
			for (Console ConS : shop.consoles)
			{
				cout << "\x1b[36mName: \x1b[0m" << ConS.name << endl
					<< "\x1b[36mInventory: \x1b[0m" << ConS.inventory << endl
					<< "\x1b[36mPrice: \x1b[0m" << ConS.price << "\n\n";
			}
			cout << "\x1b[33m-------------------------------------------------------\x1b[0m\n";
			break;
		case 2:
			cout << "\x1b[34mMonitors-------\x1b[0m\n";
			for (Monitor MonT : shop.monitors)
			{
				cout << "\x1b[36mName: \x1b[0m" << MonT.name << endl
					<< "\x1b[36mInventory: \x1b[0m" << MonT.inventory << endl
					<< "\x1b[36mPrice: \x1b[0m" << MonT.price << "\n\n";
			}
			cout << "\x1b[33m-------------------------------------------------------\x1b[0m\n";
			break;
		case 3:
			cout << "\x1b[34mHeadsets-------\x1b[0m\n";
			for (Headset HeaD : shop.headsets)
			{
				cout << "\x1b[36mName: \x1b[0m" << HeaD.name << endl
					<< "\x1b[36mInventory: \x1b[0m" << HeaD.inventory << endl
					<< "\x1b[36mPrice: \x1b[0m" << HeaD.price << "\n\n";
			}
			cout << "\x1b[33m-------------------------------------------------------\x1b[0m\n\n";
			break;
		case 4:
			cout << "\x1b[34mGames----------\x1b[0m\n";
			for (Game GamE : shop.games)
			{
				cout << "\x1b[36mName: \x1b[0m" << GamE.name << endl
					<< "\x1b[36mInventory: \x1b[0m" << GamE.inventory << endl
					<< "\x1b[36mPrice: \x1b[0m" << GamE.price << "\n\n";
			}
			cout << "\x1b[33m-------------------------------------------------------\x1b[0m\n\n";
			break;
		}
	}
	int SearchByName(string& name)
	{
		struct item
		{
			string name;
			int id;
			item(string Name, int n) : id(n), name(Name) {}
		};
		vector<item> matchs;
		for (const Console& C : shop.consoles)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 1));
				break;
			}
		}
		for (const Monitor& C : shop.monitors)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 2));
				break;
			}
		}
		for (const Headset& C : shop.headsets)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 3));
				break;
			}
		}
		for (const Game& C : shop.games)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 4));
				break;
			}
		}

		if (matchs.size() == 0)
		{
			int Cat;
			int best = 0;
			vector<string> Match;
			cout << "\x1b[31mWe couldn't find any matchs,Enter the Category of the product your looking for:\x1b[0m\n";
			cout << "\x1b[33m1) Consoles\n2) Monitors\n3) Headsets\n4) Games\x1b[0m\n";
			cin >> Cat;
			switch (Cat)
			{
			case 1:
				for (const Console& C : shop.consoles)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 2:
				for (const Monitor& C : shop.monitors)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 3:
				for (const Headset& C : shop.headsets)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best  && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 4:
				for (const Game& C : shop.games)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			}
			if(best != 0)
			{
				cout << "\x1b[36mDid you mean : \x1b[0m";
				for (const string &M : Match)
				{
					cout << M << "  ";
				}
				cout << "\x1b[36m?(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
				char yn;
				cin >> yn;
				if(yn == 'y')
				{cout << endl
					<< "\x1b[36mif Yes, write the name correctly one last time: \x1b[0m";
				string finally;
				cin >> finally;
				name = finally;
				return Cat;}
				else return 5;
			}
			else if(best == 0)
			{
				return 0;
			}
		}
		if (matchs.size() == 1)
		{
			return matchs[0].id;
		}

		if (matchs.size() > 1)
		{
			cout << "\x1b[32mthere are\x1b[0m 2 \x1b[32mor more products found with this name\nChoose your Category:\x1b[0m\n";
			for (item I : matchs)
			{
				switch (I.id)
				{
				case 1:
					cout << "1) \x1b[36mConsole\x1b[0m\n";
					break;
				case 2:
					cout << "2) \x1b[36mMonitor\x1b[0m\n";
					break;
				case 3:
					cout << "3) \x1b[36mHeadset\x1b[0m\n";
					break;
				case 4:
					cout << "4) \x1b[36mGame\x1b[0m\n";
					break;
				default:
					cout << ":/";
					break;
				}
			}
			int n;
			cin >> n;
			return n;
		}

		return 0;
	}

	int SearchByNameinCart(string& name)
	{
		struct item
		{
			string name;
			int id;
			item(string Name, int n) : id(n), name(Name) {}
		};
		vector<item> matchs;
		for (const Console& C : console)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 1));
				break;
			}
		}
		for (const Monitor& C : monitor)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 2));
				break;
			}
		}
		for (const Headset& C : headset)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 3));
				break;
			}
		}
		for (const Game& C : game)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 4));
				break;
			}
		}

		if (matchs.size() == 0)
		{
			int Cat;
			int best = 0;
			vector<string> Match;
			cout << "\x1b[31mWe couldn't find any matchs,Enter the Category of the product your looking for:\x1b[0m\n";
			cout << "\x1b[33m1) Consoles\n2) Monitors\n3) Headsets\n4) Games\x1b[0m\n";
			cin >> Cat;
			switch (Cat)
			{
			case 1:
				for (const Console& C : console)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 2:
				for (const Monitor& C : monitor)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 3:
				for (const Headset& C : headset)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			case 4:
				for (const Game& C : game)
				{
					int min;
					int max = 0;
					if (C.name.size() < name.size())
						min = C.name.size();
					else
						min = name.size();
					for (int i = 0; i < min; i++)
					{
						if (C.name[i] == name[i])
							max++;
					}
					if (max > best)
					{
						Match.clear();
						Match.shrink_to_fit();
						Match.push_back(C.name);
						best = max;
					}
					else if (max == best && max != 0)
					{
						Match.push_back(C.name);
					}
				}
				break;
			}
			if(best != 0)
			{
				cout << "\x1b[36mDid you mean : \x1b[0m";
				for (const string &M : Match)
				{
					cout << M << "  ";
				}
				cout << "\x1b[36m?(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
				char yn;
				cin >> yn;
				if(yn == 'y')
				{cout << endl
					<< "\x1b[36mif Yes, write the name correctly one last time: \x1b[0m";
				string finally;
				cin >> finally;
				name = finally;
				return Cat;}
				else return 5;
			}
			else if(best == 0)
			{
				cout << "\x1b[31mNo similar item found...\x1b[0m\n";
				cin.ignore();
				cin.get();
				return 0;
			}
		}
		if (matchs.size() == 1)
		{
			return matchs[0].id;
		}

		if (matchs.size() > 1)
		{
			cout << "\x1b[32mthere are\x1b[0m 2 \x1b[32mor more products found with this name\nChoose your Category:\x1b[0m\n";
			for (item I : matchs)
			{
				switch (I.id)
				{
				case 1:
					cout << "1) \x1b[36mConsole\x1b[0m\n";
					break;
				case 2:
					cout << "2) \x1b[36mMonitor\x1b[0m\n";
					break;
				case 3:
					cout << "3) \x1b[36mHeadset\x1b[0m\n";
					break;
				case 4:
					cout << "4) \x1b[36mGame\x1b[0m\n";
					break;
				default:
					cout << ":/";
					break;
				}
			}
			int n;
			cin >> n;
			return n;
		}

		return 0;
	}

	void AddToCart(string name, int n)
	{
		string incartname;
		bool thereis = false;
		int amount = 0;
		int limit = 0;

		switch (n)
		{
		case 1:
			for (int i = 0; i < shop.consoles.size(); i++)
			{
				if (name == shop.consoles[i].name)
				{
					for(Console& C : console)
					{
						limit = shop.consoles[i].inventory - C.inventory;
						if(C.name == name)
						{
							thereis = true;
							while(true)
							{
								cout << "\x1b[34mYou have \x1b[0m" << C.inventory << "\x1b[34m of this product in your Cart\x1b[0m\n";
								cout << "\x1b[34mHow many do you want to add? \x1b[0m(You can buy \x1b[34m" << limit << "\x1b[0m more)\n";
								cin >> amount ;
								if (amount > 0)
								{
									if (amount <= limit)
									{
										C.inventory += amount;
										cout << "\x1b[32mdone!\x1b[0m\n";
										break;
									}
									else
									{
										char ch;
										cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
										cin >> ch;
										if (ch == 'y') continue;
										else break;
									}
								}
								else
								{
									break;
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "\x1b[33mHow many do you want? (\x1b[0m" << shop.consoles[i].inventory << "\x1b[33m Available): \x1b[0m\n";
							cin >> amount;
							if(amount > 0)
							{
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
									cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
									cin >> ch;
									if (ch == 'y') continue;
									else break;
								}
							}
							else break;
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
					for(Monitor& C : monitor)
					{
						limit = shop.monitors[i].inventory - C.inventory;
						if(C.name == name)
						{
							thereis = true;
							while(true)
							{
								cout << "\x1b[34mYou have \x1b[0m" << C.inventory << "\x1b[34m of this product in your Cart\x1b[0m\n";
								cout << "\x1b[34mHow many do you want to add? \x1b[0m(You can buy \x1b[34m" << limit << "\x1b[0m more)\n";
								cin >> amount ;
								if (amount > 0)
								{
									if (amount <= limit)
									{
										C.inventory += amount;
										cout << "\x1b[32mdone!\x1b[0m\n";
										break;
									}
									else
									{
										char ch;
										cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
										cin >> ch;
										if (ch == 'y') continue;
										else break;
									}
								}
								else
								{
									break;
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "\x1b[33mHow many do you want? (\x1b[0m" << shop.monitors[i].inventory << "\x1b[33m Available)\x1b[0m\n";
							cin >> amount;
							if(amount > 0)
							{
								if (amount < shop.monitors[i].inventory)
								{
									monitor.push_back(Monitor(name, amount, shop.monitors[i].price));
									// shop.monitors[i].inventory -= amount;
									break;
								}
								else if (amount == shop.monitors[i].inventory)
								{
									monitor.push_back(Monitor(name, amount, shop.monitors[i].price));
									// shop.monitors.erase(shop.monitors.begin() + i);
									break;
								}
								else
								{
									char ch;
									cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
									cin >> ch;
									if (ch == 'y') continue;
									else break;
								}
							}else break;
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
					for(Headset& C : headset)
					{
						limit = shop.headsets[i].inventory - C.inventory;
						if(C.name == name)
						{
							thereis = true;
							while(true)
							{
								cout << "\x1b[34mYou have \x1b[0m" << C.inventory << "\x1b[34m of this product in your Cart\x1b[0m\n";
								cout << "\x1b[34mHow many do you want to add? \x1b[0m(You can buy \x1b[34m" << limit << "\x1b[0m more)\n";
								cin >> amount ;
								if (amount > 0)
								{
									if (amount <= limit)
									{
										C.inventory += amount;
										cout << "\x1b[32mdone!\x1b[0m\n";
										break;
									}
									else
									{
										char ch;
										cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
										cin >> ch;
										if (ch == 'y') continue;
										else break;
									}
								}
								else
								{
									break;
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "\x1b[33mHow many do you want? (\x1b[0m" << shop.headsets[i].inventory << "\x1b[33m Available)\x1b[0m\n";
							cin >> amount;
							if(amount > 0)
							{
								if (amount < shop.headsets[i].inventory)
								{
									headset.push_back(Headset(name, amount, shop.headsets[i].price));
									// shop.headsets[i].inventory -= amount;
									break;
								}
								else if (amount == shop.headsets[i].inventory)
								{
									headset.push_back(Headset(name, amount, shop.headsets[i].price));
									// shop.headsets.erase(shop.headsets.begin() + i);
									break;
								}
								else
								{
									char ch;
									cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
									cin >> ch;
									if (ch == 'y') continue;
									else break;
								}
							}else break;
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
					for(Game& C : game)
					{
						limit = shop.games[i].inventory - C.inventory;
						if(C.name == name)
						{
							thereis = true;
							while(true)
							{
								cout << "\x1b[34mYou have \x1b[0m" << C.inventory << "\x1b[34m of this product in your Cart\x1b[0m\n";
								cout << "\x1b[34mHow many do you want to add? \x1b[0m(You can buy \x1b[34m" << limit << "\x1b[0m more)\n";
								cin >> amount ;
								if (amount > 0)
								{
									if (amount <= limit)
									{
										C.inventory += amount;
										cout << "\x1b[32mdone!\x1b[0m\n";
										break;
									}
									else
									{
										char ch;
										cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
										cin >> ch;
										if (ch == 'y') continue;
										else break;
									}
								}
								else
								{
									break;
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "\x1b[33mHow many do you want? (\x1b[0m" << shop.games[i].inventory << "\x1b[33m Available)\x1b[0m\n";
							cin >> amount;
							if(amount > 0)
							{
								if (amount < shop.games[i].inventory)
								{
									game.push_back(Game(name, amount, shop.games[i].price));
									// shop.games[i].inventory -= amount;
									break;
								}
								else if (amount == shop.games[i].inventory)
								{
									game.push_back(Game(name, amount, shop.games[i].price));
									// shop.games.erase(shop.games.begin() + i);
									break;
								}
								else
								{
									char ch;
									cout << "\x1b[31mYour desire exceeded our availability!!\nDo you want to try again?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m";
									cin >> ch;
									if (ch == 'y') continue;
									else break;
								}
							}else break;
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
						cout << "\x1b[33mHow many do you want to remove? (\x1b[0m" << console[i].inventory << "\x1b[33m In your Cart)\x1b[0m\n";
						cin >> amount;
						if (amount > 0)
						{
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
								cout << "\x1b[35myou don't have this much in your cart!, Do you want to try agin?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
								cin >> ch;
								if (ch == 'y') continue;
								else break;
							}
						}
						else
						{
							cout << "\x1b[31mthis action can't be done!\x1b[0m\n";
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
						cout << "\x1b[33mHow many do you want to remove? (\x1b[0m" << monitor[i].inventory << "\x1b[33m In your Cart)\x1b[0m\n";
						cin >> amount;
						if (amount > 0)
						{
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
								cout << "\x1b[35myou don't have this much in your cart!, Do you want to try agin?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
								cin >> ch;
								if (ch == 'y') continue;
								else break;
							}
						}
						else
						{
							cout << "\x1b[31mthis action can't be done!\x1b[0m\n";
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
						cout << "\x1b[33mHow many do you want to remove? (\x1b[0m" << headset[i].inventory << "\x1b[33m In your Cart)\x1b[0m\n";
						cin >> amount;
						if (amount > 0)
						{
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
								cout << "\x1b[35myou don't have this much in your cart!, Do you want to try agin?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
								cin >> ch;
								if (ch == 'y') continue;
								else break;
							}
						}
						else
						{
							cout << "\x1b[31mthis action can't be done!\x1b[0m\n";
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
						cout << "\x1b[33mHow many do you want to remove? (\x1b[0m" << game[i].inventory << "\x1b[33m In your Cart)\x1b[0m\n";
						cin >> amount;
						if (amount > 0)
						{
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
								cout << "\x1b[35myou don't have this much in your cart!, Do you want to try agin?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
								cin >> ch;
								if (ch == 'y') continue;
								else break;
							}
						}
						else
						{
							cout << "\x1b[31mthis action can't be done!\x1b[0m\n";
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
	void Totalprice()
	{
		int TotalPrice = 0;
		for (const Console& C : console)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Monitor& C : monitor)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Headset& C : headset)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Game& C : game)
		{
			TotalPrice += C.price * C.inventory;
		}
		totalprice = TotalPrice;
	}
	void Finalize(Wallet& AWallet)
	{
		Totalprice();
		if(totalprice <= wallet.Balance())
		{
			for (Console C : console)
			{
				for (int i = 0; i < shop.consoles.size(); i++)
				{
					if (C.name == shop.consoles[i].name)
					{
						if (C.inventory < shop.consoles[i].inventory)
						{
							shop.consoles[i].inventory -= C.inventory;
						}
						else if (C.inventory == shop.consoles[i].inventory)
						{
							shop.consoles.erase(shop.consoles.begin() + i);
							shop.consoles.shrink_to_fit();
						}
					}
				}
			}
			for (Monitor C : monitor)
			{
				for (int i = 0; i < shop.monitors.size(); i++)
				{
					if (C.name == shop.monitors[i].name)
					{
						if (C.inventory < shop.monitors[i].inventory)
						{
							shop.monitors[i].inventory -= C.inventory;
						}
						else if (C.inventory == shop.monitors[i].inventory)
						{
							shop.monitors.erase(shop.monitors.begin() + i);
							shop.monitors.shrink_to_fit();
						}
					}
				}
			}
			for (Headset C : headset)
			{
				for (int i = 0; i < shop.headsets.size(); i++)
				{
					if (C.name == shop.headsets[i].name)
					{
						if (C.inventory < shop.headsets[i].inventory)
						{
							shop.headsets[i].inventory -= C.inventory;
						}
						else if (C.inventory == shop.headsets[i].inventory)
						{
							shop.headsets.erase(shop.headsets.begin() + i);
							shop.headsets.shrink_to_fit();
						}
					}
				}
			}
			for (Game C : game)
			{
				for (int i = 0; i < shop.games.size(); i++)
				{
					if (C.name == shop.games[i].name)
					{
						if (C.inventory < shop.games[i].inventory)
						{
							shop.games[i].inventory -= C.inventory;
						}
						else if (C.inventory == shop.games[i].inventory)
						{
							shop.games.erase(shop.games.begin() + i);
							shop.games.shrink_to_fit();
						}
					}
				}
			}
			ClearCart();
			wallet.CostWallet(totalprice);
			AWallet.AddMoney(totalprice);
		}
		else
		{
			cout << "\x1b[1;31myou don't have enough money\x1b[0m\n";
		}
	}

	void Sync(string name,int n,int inventory)
	{
		bool ThereIs = false;
		switch(n)
		{
			case 1:
				for (const Console &C : shop.consoles)
				{
					if(C.name == name)
					{
						ThereIs = true;
						if(C.inventory < inventory)
						{
							cout << "\033[31mThere is not enough product in the stock ( " << C.inventory << " ) Available.\033[0m\n";
						}
					}
				}
				if(!ThereIs)
				{
					cout << "\033[31mThis product is out of stock\033[0m\n";
				}
				break;
			case 2:
					for (const Monitor &C : shop.monitors)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.inventory < inventory)
							{
								cout << "\033[31mThere is not enough product in the stock ( " << C.inventory << " ) Available.\033[0m\n";
							}
						}
					}
					if(!ThereIs)
					{
						cout << "\033[31mThis product is out of stock\033[0m\n";
					}
				break;
			case 3:
					for (const Headset &C : shop.headsets)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.inventory < inventory)
							{
								cout << "\033[31mThere is not enough product in the stock ( " << C.inventory << " ) Available.\033[0m\n";
							}
						}
					}
					if(!ThereIs)
					{
						cout << "\033[31mThis product is out of stock\033[0m\n";
					}
				break;
			case 4:
					for (const Game &C : shop.games)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.inventory < inventory)
							{
								cout << "\033[31mThere is not enough product in the stock ( " << C.inventory << " ) Available.\033[0m\n";
							}
						}
					}
					if(!ThereIs)
					{
						cout << "\033[31mThis product is out of stock\033[0m\n";
					}
				break;
		}
	}

	void SyncPrice(string name,int n,double &price)
	{
		bool ThereIs = false;
		switch(n)
		{
			case 1:
				for (const Console &C : shop.consoles)
				{
					if(C.name == name)
					{
						ThereIs = true;
						if(C.price != price)
						{
							cout << "\033[31m" << C.price << "\033[0m";
							price = C.price;
						}
						else cout << price ;
					}
				}
				if(!ThereIs)
				{
					cout << price ;
				}
				break;
			case 2:
				for (const Monitor &C : shop.monitors)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.price != price)
							{
								cout << "\033[31m" << C.price << "\033[0m";
								price = C.price;
							}
							else cout << price ;	
						}
					}
					if(!ThereIs)
					{
						cout << price ;
					}
				break;
			case 3:
				for (const Headset &C : shop.headsets)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.price != price)
							{
								cout << "\033[31m" << C.price << "\033[0m";
								price = C.price;
							}
							else cout << price ;	
						}
					}
					if(!ThereIs)
					{
						cout << price ;
					}
				break;
			case 4:
				for (const Game &C : shop.games)
					{
						if(C.name == name)
						{
							ThereIs = true;
							if(C.price != price)
							{
								cout << "\033[31m" << C.price << "\033[0m";
								price = C.price;
							}
							else cout << price ;
						}
					}
					if(!ThereIs)
					{
						cout << price ;
					}
				break;
		}
	}

	void ShowCart()
	{
		int unavailable = 0;
		int TotalPrice = 0;

		if(!console.empty())
		{
			cout << "\n\x1b[35m---Consoles---\x1b[0m\n";
			for (Console &C : console)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,1,C.price);
				cout << endl;
				Sync(C.name,1,C.inventory);
				cout << "\x1b[36m  --------------------------------------------  \x1b[0m\n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;
		if(!monitor.empty())
		{
			cout << "\n\x1b[35m---Monitors---\x1b[0m\n";
			for (Monitor &C : monitor)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,2,C.price);
				cout << endl;
				Sync(C.name,2,C.inventory);
				cout << "\x1b[36m  --------------------------------------------  \x1b[0m\n";
				TotalPrice += C.price * C.inventory;	
			}
		}else unavailable++;
		if(!headset.empty())
		{
			cout << "\n\x1b[35m---Headsets---\x1b[0m\n";
			for (Headset &C : headset)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,3,C.price);
				cout << endl;
				Sync(C.name,3,C.inventory);
				cout << "\x1b[36m  --------------------------------------------  \x1b[0m\n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;
		if(!game.empty())
		{
			cout << "\n\x1b[35m---Game---\x1b[0m\n";
			for (Game &C : game)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,4,C.price);
				cout << endl;
				Sync(C.name,4,C.inventory);
				cout << "\x1b[36m  --------------------------------------------  \x1b[0m\n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;

		if(unavailable == 4) cout << "\x1b[33mthere is no item in your cart\x1b[0m\n";
		cout << "\x1b[35mFianl Price: \x1b[0m\x1b[33m$\x1b[0m" << TotalPrice << endl;
	}

	bool isSync()
	{
		IsSync = false;
		for(const Console& C : console)
		{
			for(const Console& I : shop.consoles)
			{
				if(C.name == I.name)
				{
					if(I.inventory >= C.inventory) IsSync = true;
				}
			}
		}
		for(const Monitor& C : monitor)
		{
			for(const Monitor& I : shop.monitors)
			{
				if(C.name == I.name)
				{
					if(I.inventory >= C.inventory) IsSync = true;
				}
			}
		}
		for(const Headset& C : headset)
		{
			for(const Headset& I : shop.headsets)
			{
				if(C.name == I.name)
				{
					if(I.inventory >= C.inventory) IsSync = true;
				}
			}
		}
		for(const Game& C : game)
		{
			for(const Game& I : shop.games)
			{
				if(C.name == I.name)
				{
					if(I.inventory >= C.inventory) IsSync = true;
				}
			}
		}

		return IsSync;
	}
};

string ChangePassword()
{
	string pass;
	bool check = false;
	while (check == false)
	{
		char choice;
		cout << "Do you want to change your password?(y/n): ";
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
		else break;
	}

	return pass;
}
void EnterPassword(string& Password)
{
	Password = "";
	char ch;
	const char ENTER = 13;
	cout << "\033c";
	cout << "\x1b[32mPlease enter the password: \x1b[0m";

	while ((ch = _getch()) != ENTER)
	{
		if (ch != 8)
		{
			Password += ch;
			cout << "\x1b[2;34;43m*\x1b[0m";
		}
		else if (ch == 8 && Password.length() > 0)
		{
			Password.pop_back();
			cout << "\b \b";
		}
	}
	cout << "\n";
}

void AdminMenu(string& Password,string& Pass, GamingShop& Shop, Wallet& AdminWallet)
{
	int choice, Item_Type;
	string Name , select;
	int Inventory;
	double Price;
	ItemType num;

	do
	{
		cout << "\033c";
		cout << "\x1b[2;32m---\x1b[0m\x1b[3;4;33mAdmin Menu\x1b[0m\x1b[2;32m---\x1b[0m\n";
		cout << "\x1b[32m1)\x1b[0m \x1b[3;36mAdd Product\x1b[0m" << endl;
		cout << "\x1b[32m2)\x1b[0m \x1b[3;36mRemove Product\x1b[0m" << endl;
		cout << "\x1b[32m3)\x1b[0m \x1b[3;36mShow Informations\x1b[0m" << endl;
		cout << "\x1b[32m4)\x1b[0m \x1b[3;36mCalculate Total Value\x1b[0m" << endl;
		cout << "\x1b[32m5)\x1b[0m \x1b[3;36mGamingShop Money Management\x1b[0m" << endl;
		cout << "\x1b[32m6)\x1b[0m \x1b[3;36mChange the password\x1b[0m" << endl;
		cout << "\x1b[32m7)\x1b[0m \x1b[3;36mLogOut\x1b[0m" << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "\x1b[33mPlease choose type of product (\x1b[0m\x1b[4mchoice number\x1b[0m\x1b[33m):\x1b[0m\n\x1b[32m1:\x1b[0m Console\n\x1b[32m2:\x1b[0m Monitor\n\x1b[32m3:\x1b[0m Headset\n\x1b[32m4:\x1b[0m Game\n";
			cin >> Item_Type;
			num = static_cast<ItemType>(Item_Type);
			cout << "\x1b[1;34mPlease write the name: \x1b[0m";
			cin >> Name;
			if (Shop.CheckName(Name, num)==true)
			{
				Shop.Change(Name, num, AdminWallet);
			}
			else
			{
				cout << "\x1b[1;34mHow many do you want to Add: \x1b[0m";
				cin >> Inventory;
				cout << "\x1b[1;34mPlease write the price: \x1b[0m";
				cin >> Price;
				double cost = Inventory * (0.7) * Price;
				AdminWallet.CostWallet(cost);
				Shop.Add(Name, Inventory, Price, num);
				cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
				cin.ignore();
				cin.get();
			}
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
			cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
			cin.ignore();
			cin.get();
			break;
		case 4:
			Shop.Financial_Value_Of_The_Store();
			cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
			cin.ignore();
			cin.get();
			break;
		case 5:
			cout << "\x1b[3;33mWelcome to your shop wallet account.\x1b[0m\n";
			while (true)
			{
				cout << "\x1b[1;31m--------------------------------------------\x1b[0m" << endl;
				AdminWallet.RemainingWallet();
				cout << "\x1b[33mDo you want to top up your wallet?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
				cin >> select;
				if (select == "y")
				{
					select = "";
					AdminWallet.ChargeWallet();
				}
				else if (select == "n")
				{
					break;
				}
				else
				{
					cout << "\x1b[5;31mYour selection is not defined. Please try again! \x1b[0m" << endl;
				}
			}
			cout << "\x1b[1;31m--------------------------------------------\x1b[0m" << endl;
			cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
			cin.ignore();
			cin.get();
			break;
		case 6:
			Pass = ChangePassword();
			cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
			cin.ignore();
			cin.get();
			break;
		case 7:
			return;
		}
	} while (true);
}

void CustomerMenu(ShoppingCart& Cart, GamingShop& Shop , Wallet& CustomerWallet,Wallet& AdminWallet)
{
	char cho;
	string select;

	do
	{
		cout <<"\033c";
		cout << "\x1b[2;32m---\x1b[0m\x1b[3;4;33mCustomer Menu\x1b[0m\x1b[2;32m---\x1b[0m\n";
		cout << "\x1b[32m1)\x1b[0m \x1b[3;36mAdd to cart\x1b[0m" << endl;
		cout << "\x1b[32m2)\x1b[0m \x1b[3;36mCategorized List of Products\x1b[0m" << endl;
		cout << "\x1b[32m3)\x1b[0m \x1b[3;36mList of all products\x1b[0m" << endl;
		cout << "\x1b[32m4)\x1b[0m \x1b[3;36mCustomers_Money_Management\x1b[0m" << endl;
		cout << "\x1b[32m5)\x1b[0m \x1b[3;36mShopping Cart\x1b[0m" << endl;
		cout << "\x1b[32m6)\x1b[0m \x1b[3;36mLogOut\x1b[0m" << endl;
		cin >> cho;
		cout << endl;

		switch (cho)
		{
		case '1':
			while (true)
			{
				cout << "\033c";
				cout << "\x1b[2;33m---\x1b[0m\x1b[3;4;5;32mAddToCart\x1b[0m\x1b[2;33m---\x1b[0m\n";
				cout << "\x1b[1;35m1)\x1b[0m \x1b[1;33mEnter the product's name to Add\x1b[0m\n\x1b[1;35m2)\x1b[0m \x1b[1;35mShow a Categorized List(if you don't remember your desired item)\n3) Quit\n";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					string Name;
					cout << "\x1b[1;34mEnter the name: \x1b[0m";
					cin >> Name;
					choice = Cart.SearchByName(Name);
					if (choice == 0)
					{
						cout << "We couldn't find any";
						break;
					}
					else if(choice == 5) break;
					Cart.AddToCart(Name, choice);
					cout << "Do you want to add more?(y/n):";
					char Ch;
					cin >> Ch;
					if(Ch == 'y') continue;
					else break;
				}
				else if (choice == 2)
				{
					while (true)
					{
						Cart.GetData();
						cout << "1) Search for a specific Product\n2) Quit\n";
						int Choice;
						int Cat;
						cin >> Choice;
						if (Choice == 1)
						{
							cout << "Enter the number of product type you want to see: ";
							cin.ignore();
							cin >> Cat;
							Cart.ShowData(Cat);
							cout << "1) Enter the product name to add it to Cart\n2) Back\n";
							cin >> Choice;
							if (Choice == 1)
							{
								string name;
								cin.ignore();
								cout << "Enter the name: ";
								cin >> name;
								Cart.AddToCart(name, Cat);
								cout << "Do you want to add more?(y/n):";
								char Ch;
								cin >> Ch;
								if (Ch == 'y') continue;
								else break;
							}
							else if (choice == 2)
							{
								cout << "\033c";
								continue;
							}
						}
						else break;
					}
				}
				else if (choice == 3) break;
			}
			break;
		case '2':
			while (true)
			{
				cout << "\033c";
				cout << "\x1b[2;33m---\x1b[0m\x1b[3;4;5;32mCategorizedList\x1b[0m\x1b[2;33m---\x1b[0m\n";
				Cart.GetData();
				cout << "1) Search for a specific Product\n2) Quit\n";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "Enter the number of product type you want to see: ";
					cin >> choice;
					Cart.ShowData(choice);
					cout << "\x1b[5;31mPress enter to go back . . .\x1b[0m\n";
					cin.ignore();
					cin.get();
				}
				else break;
			}
			break;
		case '3':
			cout << "\033c";
			cout << "\x1b[2;33m---\x1b[0m\x1b[3;4;5;32mListofAllProducts\x1b[0m\x1b[2;33m---\x1b[0m\n";
			Shop.ShowDisplay();
			cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
			cin.ignore();
			cin.get();
			break;
		case '4':
			cout << "\x1b[3;33mWelcome to your wallet account.\x1b[0m\n";
			while (true)
			{
				cout << "\x1b[1;31m--------------------------------------------\x1b[0m" << endl;
				CustomerWallet.RemainingWallet();
				cout << "\x1b[33mDo you want to top up your wallet?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
				cin >> select;
				if (select == "y")
				{
					select = "";
					CustomerWallet.ChargeWallet();
				}
				else if (select == "n")
				{
					break;
				}
				else
				{
					cout << "\x1b[5;31mYour selection is not defined. Please try again! \x1b[0m" << endl;
				}
			}
			cout << "\x1b[1;31m--------------------------------------------\x1b[0m" << endl;
			break;
		case '5':
		{
			bool loop = true;
			while (loop)
			{
				cout << "\033c";
				cout << "\x1b[2;33m---\x1b[0m\x1b[3;4;5;32mShoppingCart\x1b[0m\x1b[2;33m---\x1b[0m\n";
				CustomerWallet.RemainingWallet();
				char Choice;
				Cart.ShowCart();
				cout << "\x1b[1;31m1)\x1b[0m Finalize Purchase\n\x1b[1;31m2)\x1b[0m Remove some products\n\x1b[1;31m3)\x1b[0m Clear Shopping Cart\n\x1b[1;31m4)\x1b[0m Quit\n";
				cin >> Choice;
				switch (Choice)
				{
				case '1':
					if(Cart.isSync())
					{
						char ch;
						cout << "\x1b[36mAre you sure ?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
						cin >> ch;
						if (ch == 'y')
						{
							Cart.Finalize(AdminWallet);
							loop = false;
							cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
							cin.ignore();
							cin.get();
						}
					}
					else 
					{
						cout << "\x1b[1;35mThis Action can't be done , some items are unavailable.\n";
						cout << "Remove them or Wait for the shop to restock\x1b[0m\n";
						cout << "\x1b[5;31mPress enter to go back \x1b[0m\n";
						cin.ignore();
						cin.get();
					}
					break;
				case '2':
					while (true)
					{
						string name;
						cin.ignore();
						cout << "\x1b[1;34mEnter the product's name: \x1b[0m";
						cin >> name;
						int n = Cart.SearchByNameinCart(name);
						if (n == 0)
						{
							cout << "\x1b[31mWe couldn't find any matchs\x1b[0m";
							break;
						}
						else if(n == 5) break;
						Cart.RemoveFromCart(name, n);
						cout << "\x1b[36mDo you want to Remove more?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
						char ch;
						cin >> ch;
						if (ch == 'y') continue;
						else break;
					}
					break;
				case '3':
				{
					cout << "\x1b[36mAre you sure?\x1b[0m\x1b[36m(\x1b[0m\x1b[32my\x1b[0m\x1b[36m/\x1b[0m\x1b[31mn\x1b[0m\x1b[36m):\x1b[0m ";
					char ch;
					cin >> ch;
					if (ch == 'y') Cart.ClearCart();
					break;
				}
				case '4':
					loop = false;
					break;
				}
			}
			break;
		}
		case '6':
			return;
			break;
		}
	} while (true);
}

void RoleSwitching(string& Password,string& Pass, GamingShop& Shop, ShoppingCart& Cart, Wallet& AdminWallet, Wallet& CustomerWallet)
{
	int number, choice;
	do
	{
		cout << "\033c";
		cout << "\x1b[1;35mPlease choose your identity with number (\x1b[0m 1: \x1b[5;33mAdministration \x1b[0m/  2: \x1b[5;33mCustomers \x1b[0m /  3: \x1b[5;33mExit \x1b[0m\x1b[1;35m):\x1b[0m ";
		cin >> number;

		if (number == 1)
		{
			// Admin Role
			EnterPassword(Password);
			bool ok = false;
			while (ok == false)
			{
				if (Password == Pass)
				{
					AdminMenu(Password,Pass, Shop, AdminWallet);
					ok = true;
				}
				else
				{
					cout << "\x1b[1;5;31mYour password is incorrect!\x1b[0m" << endl;
					cout << "\x1b[33m(\x1b[0mchoose with number\x1b[33m)\x1b[0m \n 1: \x1b[5;33mBack\x1b[0m \n 2: \x1b[5;33mTry Again \x1b[0m";
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
			CustomerMenu(Cart, Shop, CustomerWallet,AdminWallet);
		}
		else if (number == 3)
		{
			return;
		}
	} while (true);
}

int main()
{
	Wallet AdminWallet, CustomerWallet;
	GamingShop Shop;
	ShoppingCart Cart(Shop, CustomerWallet);
	string Password;
	string Pass = "admin1admin";
	RoleSwitching(Password,Pass, Shop, Cart, AdminWallet, CustomerWallet);
	return 0;
}