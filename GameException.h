#pragma once
#include <iostream>
#include <string>
using namespace std;
class GameException
{
private:
	string class_type;
	string method;
public:
	GameException(string _class_type="nd", string _method="nd");
	void Print();
};

