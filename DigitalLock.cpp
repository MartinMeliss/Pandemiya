// Martin Meliss для игры Пандемия: дорога домой
//

#include "stdafx.h"
#include <iostream>
#include <wchar.h>

#include "Pin.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CPin pin;

	int iPinCount = pin.GetPinCount();

	int pValidResponse[] = { 0, 1, 2, 3, 4, 10, 11, 12, 13, 20, 21, 22, 30, 40 };

	while (iPinCount > 1)
	{
		sPin currPIN = pin.GetRandom();
		std::cout << "Now PIN count: " << iPinCount << std::endl;		
		std::cout << "Try enter PIN: " << currPIN.a1 << currPIN.a2 << currPIN.a3 << currPIN.a4 << std::endl;
		
		int iResponse = -1;
		while (iResponse == -1)
		{
			std::cout << "Enter response: ";
			std::cin >> iResponse;
			if (std::cin.fail())
			{
				std::cin.clear();
				char c;
				std::cin >> c;
			}
			std::cout << std::endl;
			bool bGoodResponse = false;
			for (int i = 0, iEnd = sizeof(pValidResponse) >> 2; i < iEnd; i++)
			{
				if (iResponse == pValidResponse[i])
				{
					bGoodResponse = true;
					break;
				}
			}
			if (!bGoodResponse)
			{
				iResponse = -1;
				std::cout << "Response is not valid!" << std::endl;
			}				
		}
		iPinCount = pin.SiftPins(iResponse, currPIN);
	}

	sPin currPIN = pin.GetRandom();
	std::cout << "Secret PIN is: " << currPIN.a1 << currPIN.a2 << currPIN.a3 << currPIN.a4 << std::endl;
	std::cout << "Done!" << std::endl << "enter any key" << std::endl;
	
	_getwch();

	return 0;
}

