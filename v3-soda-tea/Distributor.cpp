#include "Distributor.h"

#include <iostream>

#include "soda/Soda.h"
#include "items/tea/Tea.h"
using namespace std;

Distributor::Distributor(double sodaPrice, int sodaCode, double teaPrice,
		int teaCode) :
		sodaPrice(sodaPrice), sodaCode(sodaCode), teaPrice(teaPrice), codeTea(
				teaCode) {
}

bool Distributor::acceptPayment(double money, int code) {
	if (code == this->sodaCode) {
		if (money >= this->sodaPrice) {
			cout << "Payment accepted" << endl;
			return true;
		} else {
			cout << "Insufficient payment to take soda" << endl;
			return false;
		}
	} else {
		if ((money >= this->teaPrice)) {
			cout << "Payment accepted" << endl;
			return true;
		} else {
			cout << "Insufficient payment to take tea" << endl;
			return false;
		}
	}
}

void Distributor::cancel() {
	cout << "Cancel order" << endl;
}

bool Distributor::select(int code) {
	int x;
	int y=10;
	int z=x;

	double t;
	if (code == this->sodaCode) {
		cout << "Soda" << endl;
		Soda soda = new Soda(1);
		soda.prepareSoda(1);
		soda.getSoda();
		return true;
	} else  if (code == this->codeTea) {
		cout << "Tea" << endl;
		Tea tea = new Tea(1);
		tea.prepareTea(1);
		tea.getTea();
		return true;
	} else {
		cout << "Nothing is selected" << endl;
		return false;
	}
}

void Distributor::serve(int code) {
	if (code == this->sodaCode) {
		cout << "Serving soda..." << endl;
	} else {
		cout << "Serving tea..." << endl;
	}
}

void Distributor::openCompartment() {
	cout << "open compartment" << endl;
}

void Distributor::closeCompartment() {
	cout << "close compartment" << endl;
}

void Distributor::setSodaPrice(double price) {
	this->sodaPrice = price;
}

double Distributor::getSodaPrice() {
	return this->sodaPrice;
}

void Distributor::setSodaCode(int code) {
	this->sodaCode = code;
}

int Distributor::getSodaCode() {
	return this->sodaCode;
}

void Distributor::setTeaPrice(double price) {
	this->teaPrice = price;
}

double Distributor::getTeaPrice() {
	return this->teaPrice;
}

void Distributor::setTeaCode(int code) {
	this->codeTea = code;
}

int Distributor::getTeaCode() {
	return this->codeTea;
}
