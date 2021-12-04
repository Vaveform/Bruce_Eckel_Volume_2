#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "errorLog.h"

class BankAccount : public ErrorLog
{
	int balance;
	public:
	BankAccount(int value) : balance(value) {};
	void Spend(int value)
	{
		if(balance < value)
		{
			toErrorLog("Cannot to spend on account ")
				.toErrorLog((void*)this)
				.toErrorLog(" ")
				.toErrorLog(value)
				.toErrorLog("$ because balance ")
				.toErrorLog(balance)
				.toErrorLog("$")
				.toErrorLog("\n");
		}
		else
			balance -= value;
	}
	int getBalance() const
	{
		return balance;
	}
};


class Bank : public std::vector<BankAccount>, public ErrorLog
{
	private:
		using Clients = std::vector<BankAccount>;
		size_t max_num_clients;
	public:
		Bank(size_t num_clients = 15) : max_num_clients(num_clients){}
		void push_back(const BankAccount& acc)
		{
			//std::cout << "Calling lvalue push_back" << std::endl;
			if(Clients::size() < max_num_clients)
				Clients::push_back(acc);
			else{
				toErrorLog("Too much clients for bank: ")
					.toErrorLog((void*)this)
					.toErrorLog("\n");
			}
		}

		void push_back(BankAccount&& acc)
		{
			//std::cout << "Calling rvalue push_back" << std::endl;
			if(Clients::size() < max_num_clients)
				Clients::push_back(acc);
			else{
				toErrorLog("Too much clients for bank: ")
					.toErrorLog((void*)this)
					.toErrorLog("\n");
			}
		}
};



int main()
{
	using namespace std;
	srand(time(0));
	BankAccount a1(12345);
	BankAccount a2(12345);
	BankAccount a3(12345);
	BankAccount a4(12345);
	Bank maimi_bank(5);
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	maimi_bank.push_back(BankAccount(rand()));
	for(BankAccount& acc : maimi_bank)
		acc.Spend(rand());
	return 0;

};
