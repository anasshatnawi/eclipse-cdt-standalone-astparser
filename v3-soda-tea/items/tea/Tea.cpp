#include "Tea.h"

#include <iostream>

using namespace std;

Tea::Tea(int teaType) : teaType(teaType)
{
}


bool Tea::prepareTea(int teaType)
{
	cout << "Preparing tea"<<endl;
    return true;
}

int Tea::getTea()
{
    return this->teaType;
}
