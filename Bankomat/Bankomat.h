#pragma once
#include <string>
#include <iostream>
using namespace std;

class Bankomat
{
private:
	static int IdentNum;
	int CurrentAmount;
	int nominal[7] = { 10, 20, 50, 100, 200, 500, 1000 };
	int maxSum;
	int minSum;
public:
	Bankomat();								//constructor by default
	Bankomat(int max, int min, int curr);	//constructor with params
	
	void AddCash();							//Add cash in ATM
	void toWithdrawCash();					//withdraw cash
	string toString(int sum);				//convert to string
	bool CheckCash(int cash);				//check bill by nominal
	void PrintInf();						//Print info about ATM
};

