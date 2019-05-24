#include "Soda.h"

#include <iostream>

using namespace std;

Soda::Soda(int sodaType) : sodaType(sodaType)
{
}


bool Soda::prepareSoda(int sodaType)
{
	// process of preparing soda
	cout << "Preparing soda"<<endl;
    return true;
}

int Soda::getSoda()
{
	// return the soda to the client
    return this->sodaType;
}
