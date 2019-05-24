#ifndef Tea_H
#define Tea_H


class Tea {
public:
	// Constructor
	Tea(int TeaType);

	// preparing tea
	bool prepareTea(int teaType);

	//return tea for the client
	int getTea();

private:
	// save the type of tea
	int teaType = 0;

};
#endif
