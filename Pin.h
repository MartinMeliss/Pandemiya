#pragma once

#include <vector>

struct sPin
{
	int a1;
	int a2;
	int a3;
	int a4;
	sPin()
	{
		a1 = 0;
		a2 = 0;
		a3 = 0;
		a4 = 0;
	}
	sPin(int _a1, int _a2, int _a3, int _a4)
	{
		a1 = _a1;
		a2 = _a2;
		a3 = _a3;
		a4 = _a4;
	}
	bool operator==(const sPin& a)
	{
		return (a1 == a.a1) && (a2 == a.a2) && (a3 == a.a3) && (a4 == a.a4);
	}
};

class CPin
{
public:
	CPin();
	~CPin();

	sPin GetRandom();

	int SiftPins(int iResponse, sPin pin);

	int GetPinCount();

private:

	bool FindUsesPin(sPin& pin);

	int GetResponse(sPin& pinSecret, sPin& pinInput);

	std::vector<sPin> m_PinData;
	std::vector<sPin> m_PinDataUses;

};

