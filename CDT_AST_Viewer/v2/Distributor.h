#ifndef Distributor_H
#define Distributor_H

class Distributor {
public:
	// Constructor
	Distributor(double sodaPrice, int sodaCode);

	// methods
	bool acceptPayment(double money, int code);

	bool select(int code);
	void serve(int code);
	void openCompartment();
	void closeCompartment();

	void cancel(); // Cancellation feature

	//Accessors and mutators
	void setSodaPrice(double sodaPrice);
	double getSodaPrice();

	void setSodaCode(int sodaCode);
	int getSodaCode();

private:
	double sodaPrice = 0;
	int sodaCode = 0;

};
#endif
