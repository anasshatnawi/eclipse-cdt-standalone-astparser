#include "Distributor.h"

#include <iostream>

#include "soda/Soda.h"
using namespace std;

Distributor::Distributor(double sodaPrice, int sodaCode) :
		sodaPrice(sodaPrice), sodaCode(sodaCode) {
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
	}
}

// Cancellation feature
void Distributor::cancel() {
	cout << "Cancel order" << endl;
}

bool Distributor::select(int code) {
	if (code == this->sodaCode) {
		cout << "Soda" << endl;
		Soda soda = new Soda(1);
		soda.prepareSoda(1);
		soda.getSoda();
		return true;
	} else {
		cout << "Soda not selected" << endl;
		return false;
	}
}

void Distributor::serve(int code) {
	if (code == this->sodaCode) {
		cout << "Serving soda..." << endl;
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
