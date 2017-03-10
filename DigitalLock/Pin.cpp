#include "Pin.h"
#include <algorithm>
#include <time.h>



CPin::CPin()
{
	for (int a1 = 1; a1 <= 8; a1++)
	{
		for (int a2 = 1; a2 <= 8; a2++)
		{
			for (int a3 = 1; a3 <= 8; a3++)
			{
				for (int a4 = 1; a4 <= 8; a4++)
				{
					if ((a1 == a2) || (a1 == a3) || (a1 == a4) || (a2 == a3) || (a2 == a4) || (a3 == a4))
						continue;
					m_PinData.push_back(sPin(a1, a2, a3, a4));
				}
			}
		}
	}
	srand(unsigned(time(NULL)));
	std::random_shuffle(m_PinData.begin(), m_PinData.end());
}


CPin::~CPin()
{
}

sPin CPin::GetRandom()
{
	std::random_shuffle(m_PinData.begin(), m_PinData.end());

	int iPos = -1;

	if ((int)m_PinData.size() > 1)
	{
		while (iPos < 0)
		{
			iPos = rand() % (int)m_PinData.size();
			if (FindUsesPin(m_PinData[iPos]))
				iPos = -1;
		}
	}
	else
		iPos = 0;	

	m_PinDataUses.push_back(m_PinData[iPos]);	
	return m_PinData[iPos];
}

bool CPin::FindUsesPin(sPin& pin)
{
	for (int i = 0, iEnd = (int)m_PinDataUses.size(); i < iEnd; i++)
	{
		if (m_PinDataUses[i] == pin)
			return true;
	}
	return false;
}

int CPin::SiftPins(int iResponse, sPin pin)
{
	std::vector<sPin> tempPins;
	for (int i = 0, iEnd = (int)m_PinData.size(); i < iEnd; i++)
	{
		if (GetResponse(m_PinData[i], pin) == iResponse)
			tempPins.push_back(m_PinData[i]);
	}
	m_PinData = tempPins;
	return (int)m_PinData.size();
}

int CPin::GetResponse(sPin& pinSecret, sPin& pinInput)
{
	int iResponse = 10 * ((int)(pinSecret.a1 == pinInput.a1) + (int)(pinSecret.a2 == pinInput.a2) + (int)(pinSecret.a3 == pinInput.a3) + (int)(pinSecret.a4 == pinInput.a4));
	iResponse += (int)(pinSecret.a1 == pinInput.a2) + (int)(pinSecret.a1 == pinInput.a3) + (int)(pinSecret.a1 == pinInput.a4);
	iResponse += (int)(pinSecret.a2 == pinInput.a1) + (int)(pinSecret.a2 == pinInput.a3) + (int)(pinSecret.a2 == pinInput.a4);
	iResponse += (int)(pinSecret.a3 == pinInput.a1) + (int)(pinSecret.a3 == pinInput.a2) + (int)(pinSecret.a3 == pinInput.a4);
	iResponse += (int)(pinSecret.a4 == pinInput.a1) + (int)(pinSecret.a4 == pinInput.a2) + (int)(pinSecret.a4 == pinInput.a3);

	return iResponse;
}

int CPin::GetPinCount()
{
	return (int)m_PinData.size();
}