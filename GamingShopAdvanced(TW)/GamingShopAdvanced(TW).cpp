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
	void CostWallet(double &Changes)
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
	bool IsSync = true;
	double totalprice;
	Wallet &wallet;
	GamingShop &shop;
	vector<Console> console;
	vector<Monitor> monitor;
	vector<Headset> headset;
	vector<Game> game;

public:
	ShoppingCart(GamingShop &Shop, Wallet &Cwallet) : shop(Shop), wallet(Cwallet) {}
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
		cout << "1) Consoles(" << calculatetotal(ItemType::console) <<")"<< endl;
		cout << "2) Monitors(" << calculatetotal(ItemType::monitor) <<")"<< endl;
		cout << "3) Headsets(" << calculatetotal(ItemType::headset) <<")"<< endl;
		cout << "4) Games(" << calculatetotal(ItemType::game) <<")"<< endl;
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
	int SearchByName(string &name)
	{
		struct item
		{
			string name;
			int id;
			item(string Name, int n) : id(n), name(Name) {}
		};
		vector<item> matchs;
		for (const Console &C : shop.consoles)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 1));
				break;
			}
		}
		for (const Monitor &C : shop.monitors)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 2));
				break;
			}
		}
		for (const Headset &C : shop.headsets)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 3));
				break;
			}
		}
		for (const Game &C : shop.games)
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
			cout << "We couldn't find any matchs,Enter the Category of the product your looing for:\n";
			cout << "1) Consoles\n2) Monitors\n3) Headsets\n4) Games\n";
			cin >> Cat;
			switch (Cat)
			{
			case 1:
				for (const Console &C : shop.consoles)
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
				for (const Monitor &C : shop.monitors)
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
				for (const Headset &C : shop.headsets)
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
				for (const Game &C : shop.games)
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
				cout << "Did you mean : ";
				for (const string &M : Match)
				{
					cout << M << "  ";
				}
				cout << "?(y/n)";
				char yn;
				cin >> yn;
				if(yn == 'y')
				{cout << endl
					<< "if Yes, write the name correctly one last time: ";
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
			cout << "there are 2 or more products found with this name\nChoose your Category:\n";
			cout << "1) Consoles\n2) Monitors\n3) Headsets\n4) Games\n";
			int n;
			cin >> n;
			return n;
		}

		return 0;
	}

	int SearchByNameinCart(string &name)
	{
		struct item
		{
			string name;
			int id;
			item(string Name, int n) : id(n), name(Name) {}
		};
		vector<item> matchs;
		for (const Console &C : console)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 1));
				break;
			}
		}
		for (const Monitor &C : monitor)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 2));
				break;
			}
		}
		for (const Headset &C : headset)
		{
			if (C.name == name)
			{
				matchs.push_back(item(name, 3));
				break;
			}
		}
		for (const Game &C : game)
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
			cout << "We couldn't find any matchs,Enter the Category of the product your looing for:\n";
			cout << "1) Consoles\n2) Monitors\n3) Headsets\n4) Games\n";
			cin >> Cat;
			switch (Cat)
			{
			case 1:
				for (const Console &C : console)
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
				for (const Monitor &C : monitor)
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
				for (const Headset &C : headset)
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
				for (const Game &C : game)
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
				cout << "Did you mean : ";
				for (const string &M : Match)
				{
					cout << M << "  ";
				}
				cout << "?(y/n)";
				char yn;
				cin >> yn;
				if(yn == 'y')
				{cout << endl
					<< "if Yes, write the name correctly one last time: ";
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
			cout << "there are 2 or more products found with this name\nChoose your Category:\n";
			cout << "1) Consoles\n2) Monitors\n3) Headsets\n4) Games\n";
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
								cout << "You have " << C.inventory << " of this product in your Cart\n";
								cout << "How many do you want to add? (You can buy " << limit << " more)\n";
								cin >> amount ;
								if(amount<= limit)
								{
									C.inventory += amount;
									cout << "done!\n";
									break;
								}
								else
								{
									char ch;
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
									cin >> ch;
									if (ch == 'y') continue;
									else break;		
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "How many do you want? (" << shop.consoles[i].inventory << " Available)\n";
							cin >> amount;
							if(amount != 0)
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
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
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
								cout << "You have " << C.inventory << " of this product in your Cart\n";
								cout << "How many do you want to add? (You can buy " << limit << " more)\n";
								cin >> amount ;
								if(amount<= limit)
								{
									C.inventory += amount;
									cout << "done!\n";
									break;
								}
								else
								{
									char ch;
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
									cin >> ch;
									if (ch == 'y') continue;
									else break;		
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "How many do you want? (" << shop.monitors[i].inventory << " Available)\n";
							cin >> amount;
							if(amount != 0)
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
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
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
								cout << "You have " << C.inventory << " of this product in your Cart\n";
								cout << "How many do you want to add? (You can buy " << limit << " more)\n";
								cin >> amount ;
								if(amount<= limit)
								{
									C.inventory += amount;
									cout << "done!\n";
									break;
								}
								else
								{
									char ch;
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
									cin >> ch;
									if (ch == 'y') continue;
									else break;		
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "How many do you want? (" << shop.headsets[i].inventory << " Available)\n";
							cin >> amount;
							if(amount != 0)
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
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
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
								cout << "You have " << C.inventory << " of this product in your Cart\n";
								cout << "How many do you want to add? (You can buy " << limit << " more)\n";
								cin >> amount ;
								if(amount<= limit)
								{
									C.inventory += amount;
									cout << "done!\n";
									break;
								}
								else
								{
									char ch;
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
									cin >> ch;
									if (ch == 'y') continue;
									else break;		
								}
							}
						}
					}
					if(thereis == false)
					{
						while (true)
						{
							cout << "How many do you want? (" << shop.games[i].inventory << " Available)\n";
							cin >> amount;
							if(amount != 0)
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
									cout << "Your desire exceeded our availability!!\nDo you want to try again?(y/n)";
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
							if (ch == 'y') continue;
							else break;
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
							if (ch == 'y') continue;
							else break;
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
							if (ch == 'y') continue;
							else break;
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
							if (ch == 'y') continue;
							else break;
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
		for (const Console &C : console)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Monitor &C : monitor)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Headset &C : headset)
		{
			TotalPrice += C.price * C.inventory;
		}
		for (const Game &C : game)
		{
			TotalPrice += C.price * C.inventory;
		}
		totalprice = TotalPrice;
	}
	void Finalize()
	{
		Totalprice();
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
			cout << "\n---Consoles---\n";
			for (Console &C : console)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,1,C.price);
				cout << endl;
				Sync(C.name,1,C.inventory);
				cout << "  --------------------------------------------  \n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;
		if(!monitor.empty())
		{
			cout << "\n---Monitors---\n";
			for (Monitor &C : monitor)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,2,C.price);
				cout << endl;
				Sync(C.name,2,C.inventory);
				cout << "  --------------------------------------------  \n";
				TotalPrice += C.price * C.inventory;	
			}
		}else unavailable++;
		if(!headset.empty())
		{
			cout << "\n---Headsets---\n";
			for (Headset &C : headset)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,3,C.price);
				cout << endl;
				Sync(C.name,3,C.inventory);
				cout << "  --------------------------------------------  \n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;
		if(!game.empty())
		{
			cout << "\n---Game---\n";
			for (Game &C : game)
			{
				cout << " " << C.name << " (x" << C.inventory << ") - $";
				SyncPrice(C.name,4,C.price);
				cout << endl;
				Sync(C.name,4,C.inventory);
				cout << "  --------------------------------------------  \n";
				TotalPrice += C.price * C.inventory;
			}
		}else unavailable++;

		if(unavailable == 4) cout << "there is no item in your cart\n";
		cout << "Fianl Price: $" << TotalPrice << endl;
	}

	bool isSync()
	{
		IsSync = true;
		for(const Console& C : console)
		{
			for(const Console& I : shop.consoles)
			{
				if(C.name == I.name)
				{
					if(I.inventory < C.inventory) IsSync = false;
				}
			}
		}
		for(const Monitor& C : monitor)
		{
			for(const Monitor& I : shop.monitors)
			{
				if(C.name == I.name)
				{
					if(I.inventory < C.inventory) IsSync = false;
				}
			}
		}
		for(const Headset& C : headset)
		{
			for(const Headset& I : shop.headsets)
			{
				if(C.name == I.name)
				{
					if(I.inventory < C.inventory) IsSync = false;
				}
			}
		}
		for(const Game& C : game)
		{
			for(const Game& I : shop.games)
			{
				if(C.name == I.name)
				{
					if(I.inventory < C.inventory) IsSync = false;
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
		else break;
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

void CustomerMenu(ShoppingCart &Cart, GamingShop &Shop)
{
	char cho;

	do
	{
		cout <<"\033c";
		cout << "---Customer Menu---\n";
		cout << "1) Add to cart" << endl;
		cout << "2) Categorized List of Products" << endl;
		cout << "3) List of all products" << endl;
		cout << "4) Customers_Money_Management" << endl;
		cout << "5) Shopping Cart" << endl;
		cout << "6) LogOut" << endl;
		cin >> cho;
		cout << endl;

		switch (cho)
		{
		case '1':
			while (true)
			{
				cout << "\033c";
				cout <<"---AddToCart---\n";
				cout << "1) Enter the product's name to Add\n2) Show a Categorized List(if you don't remember your desired item)\n3) Quit\n";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					string Name;
					cout << "Enter the name: ";
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
				cout <<"---CategorizedList---\n";
				Cart.GetData();
				cout << "1) Search for a specific Product\n2) Quit\n";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "Enter the number of product type you want to see: ";
					cin >> choice;
					Cart.ShowData(choice);
					cout << "Press Enter to go back ...";
					cin.ignore();
					cin.get();
				}
				else break;
			}
			break;
		case '3':
			cout << "\033c";
			cout <<"---ListofAllProducts---\n";
			Shop.ShowDisplay();
			cout << "Press Enter to go back";
			cin.ignore();
			cin.get();
			break;
		case '4':
			// Payment(name, ValueGamingShop, ValueCustomer);
			break;
		case '5':
		{
			bool loop = true;
			while (loop)
			{
				cout << "\033c";
				cout <<"---ShoppingCart---\n";
				char Choice;
				Cart.ShowCart();
				cout << "1) Finalize Purchase\n2) Remove some products\n3) Clear Shopping Cart\n4) Quit\n";
				cin >> Choice;
				switch (Choice)
				{
				case '1':
					if(Cart.isSync())
					{
						char ch;
						cout << "Are you sure ?(y/n)";
						cin >> ch;
						if (ch == 'y')
						{
							Cart.Finalize();
							loop = false;
						}
					}
					else 
					{
						cout << "This Action can't be done , some items are unavailable.\n";
						cout << "Remove them or Wait for the shop to restock\n";
					}
					break;
				case '2':
					while (true)
					{
						string name;
						cin.ignore();
						cout << "Enter the product's name: ";
						cin >> name;
						int n = Cart.SearchByNameinCart(name);
						if (n == 0)
						{
							cout << "We couldn't find any matchs";
							break;
						}
						else if(n == 5) break;
						Cart.RemoveFromCart(name, n);
						cout << "Do you want to Remove more?(y/n)";
						char ch;
						cin >> ch;
						if (ch == 'y') continue;
						else break;
					}
					break;
				case '3':
				{
					cout << "Are you sure?(y/n)";
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

void RoleSwitching(string &Password, GamingShop &Shop, ShoppingCart &Cart)
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
			CustomerMenu(Cart, Shop);
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
	RoleSwitching(Password, Shop, Cart);
	return 0;
}