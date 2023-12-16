/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <thread>
#include <map> // gives you access to the map data structure that is similar to dictionary
#include <shared_mutex>
using namespace std;
//shared memory between different threads.
map<string, int> INVENTORY;
bool bug = false;
typedef shared_mutex Lock;
Lock myLock;

void print_map(const map<string, int>& inventory)
{
	std::cout << endl << "...Inventory: ";
	for (const auto& elem : inventory)
		std::cout << '[' << elem.first<< "  " << elem.second << "]; ";
	std::cout << endl;
}

void BuyItem(string customerName, string itemName, int amount, bool wLock)
{
  if (wLock)

    myLock.lock();
  

	if (bug)
	{
		std::cout << endl << customerName << " Buy... "<<amount<<"	"<<itemName << "  read inventory" << endl;
		print_map(INVENTORY);
	}
	this_thread::sleep_for(chrono::milliseconds(10)); 

	int newAmount = INVENTORY[itemName] - amount;

	this_thread::sleep_for(chrono::milliseconds(10));
  
	if (newAmount >= 0){
		INVENTORY[itemName] = newAmount;
	}else{
		std::cout << customerName << "	SOLD OUT! Cannot buy." << endl;
	}
    if (wLock){
      myLock.unlock();
		return;
	}

	if (bug){
		std::cout << endl << customerName << " Finished buy... " << amount << "	" << itemName << endl;
		print_map(INVENTORY);
	}

  if (wLock){
    myLock.unlock();
  }
}

void ReturnItem(string customerName, string itemName, int amount, bool wLock)
{
  if (wLock)
    myLock.lock();
  
	if (bug)
	{
		std::cout << endl << customerName << " Return... " << amount << "	" << itemName << "  read inventory" << endl;
		print_map(INVENTORY);
	}
	this_thread::sleep_for(chrono::milliseconds(10));

	int newAmount = INVENTORY[itemName] + amount;

	this_thread::sleep_for(chrono::milliseconds(10));
	
	INVENTORY[itemName] = newAmount;

	if (bug)
	{
		std::cout << endl << customerName << " Finished return... " << amount << "	" << itemName << endl;
		print_map(INVENTORY);
	}
  if (wLock)
    myLock.unlock();
}

void Sim_Inventory(int round, bool enableWriteLock)
{
	std::cout << endl <<endl << "####################" << endl << "No lock. ROUND " << round << endl << "####################" << endl;
	//set same starting inventory for each round
	INVENTORY = { {"book", 5} ,{"PC",7},{"card", 11} };

	//create 4 threads calling either deposite or withdraw functions that modifies the ACCOUNT_BALANCE
	thread customer1(BuyItem,"customer1", "PC", 2, enableWriteLock);
	thread customer2(ReturnItem, "customer2", "bottle", 9, enableWriteLock);
	thread customer3(ReturnItem, "customer3", "PC", 1, enableWriteLock);
	thread customer4(BuyItem, "customer4", "bottle", 2, enableWriteLock);

	//start the threads
	customer1.join();
	customer2.join();
	customer3.join();
	customer4.join();

	//atm5 and 6 started a little later than previous threads
	thread customer5(BuyItem, "customer5", "card", 7, enableWriteLock);
	thread customer6(ReturnItem, "customer6", "card", 1, enableWriteLock);
	customer5.join();
	customer6.join();

	//Please calculate the correct inventory here
  
  
	//Please output the correct inventory and the output from the simulation with clear output format
	print_map(INVENTORY);
}

int main()
{
	//rounds of simulation
	int rounds = 10;
    bool wLock = true;
  
	//Run the simulation with multiple threads that do not have the read-write lock
	//You will see unstable output
	for (int r = 1; r <= rounds; r++)
		Sim_Inventory(r, wLock);
}