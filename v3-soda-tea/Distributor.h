#ifndef Distributor_H
#define Distributor_H


class Distributor {
public:
	/// Constructor
	Distributor(double sodaPrice, int sodaCode, double teaPrice, int teaCode);

	// methods
	bool acceptPayment(double money, int code);
	void cancel();
	bool select(int code);
	void serve(int code);
	void openCompartment();
	void closeCompartment();


	//Accessors and mutators
	void setSodaPrice(double sodaPrice);
	double getSodaPrice();

	void setSodaCode(int sodaCode);
	int getSodaCode();

	void setTeaPrice(double teaPrice);
	double getTeaPrice();

	void setTeaCode(int codeTea);
	int getTeaCode();


private:
	double sodaPrice = 0;
	int sodaCode = 0;

	double teaPrice = 0;
	int codeTea = 0;


};
#endif
