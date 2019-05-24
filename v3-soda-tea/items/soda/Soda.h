#ifndef Soda_H
#define Soda_H


class Soda {
public:
	// Constructor
	Soda(int sodaType);

	// prepare soda for the client
	bool prepareSoda(int sodaType);
	// send the soda to the client
	int getSoda();

private:
	// to save the type of soda
	int sodaType = 0;

};
#endif
