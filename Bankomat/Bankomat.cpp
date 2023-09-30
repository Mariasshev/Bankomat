#include "Bankomat.h"
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

int Bankomat::IdentNum;

string Bankomat::toString(int sum)
{
    string rez = to_string(sum);
    return rez;
}

bool Bankomat::CheckCash(int cash)
{
    for (int i = 0; i < sizeof(nominal) / sizeof(int); i++) {
        if (cash == nominal[i]) {
            return true;
            break;
        }
    }
    return false;
}

void Bankomat::PrintInf()
{
    cout << endl;
    cout << "ID: " << IdentNum << endl;
    cout << "Max sum: " << maxSum << endl;
    cout << "Min sum: " << minSum << endl;
    cout << "Current amount of money: " << toString(CurrentAmount) << endl;     //convert amount of money in ATM to string
}

Bankomat::Bankomat()
{
    IdentNum++;
    maxSum = 10000;
    minSum = 100;
    CurrentAmount = 0;
}


Bankomat::Bankomat(int max, int min, int curr)
{
    IdentNum++;
    maxSum = max;
    minSum = min;
    CurrentAmount = curr;
}


void Bankomat::AddCash()
{
    int cash;
    int amount;
    cout << "Enter amount of your bills: ";
    cin >> amount;
    int* AmountOfcash = new int[amount];

   for(int i = 0; i < amount; i++) {
        cout << "Insert the bill: ";
        cin >> cash;
        if (CheckCash(cash)) {
            AmountOfcash[i] = cash;
            CurrentAmount += AmountOfcash[i];
        }
        else {
            cout << "Wrong nominal!" << endl;
            i--;
        }

        if (i == amount - 1) {
            cout << "count your bills..." << endl;
            Sleep(200);
            cout << "ready!" << endl;
        }
   }
}

void Bankomat::toWithdrawCash()
{
    int Cash;
    int temp;
    cout << "How much money to withdraw? ";
    cin >> Cash;
    if (Cash > maxSum || Cash < minSum) {
        cout << "Min sum is " << minSum << endl;
        cout << "Max sum is " << maxSum << endl;
    }
    else {
        if (CurrentAmount < Cash)
        {
            temp = Cash - CurrentAmount;
            cout << "Now Bankomat has only " << temp << "$" << endl;
            cout << "Do you want to withdraw this amount of money? y/n";
            char userAnsw;
            cin >> userAnsw;
            if (userAnsw == 'y') {
                cout << "Here is your " << temp << "$" << endl;
                CurrentAmount -= temp;
            }
            else if (userAnsw == 'n') {
                cout << "Cancel the operation.." << endl;
            }
            else {
                cout << "Wrong answer" << endl;
            }
        }
        else {
            cout << "Here is your " << Cash << "$" << endl;
            CurrentAmount -= Cash;
        }
    }
    
}
