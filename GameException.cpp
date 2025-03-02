#include "GameException.h"
#include <iostream>
#include <string>
using namespace std;
GameException::GameException(string _class_type, string _method)
{
	class_type = _class_type;
	method = _method;
}
void GameException::Print()
{
	cerr << "Issue found for class: " << class_type << " in method: " << method << endl;
}