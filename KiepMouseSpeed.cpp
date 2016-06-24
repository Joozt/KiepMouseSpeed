#include "stdafx.h"


DWORD getMouseSpeed()
{
	DWORD value;

	BOOL result = SystemParametersInfo(SPI_GETMOUSESPEED, 0, &value, 0);

	if (result)
	{
		printf("Current mouse speed: %d\n", value);
		return value;
	}
	else
	{
		printf("Error retrieving mouse speed (error: 0x%X)\n", GetLastError());
		return 0;
	}
}

BOOL setMouseSpeed(DWORD speed)
{
	BOOL result = SystemParametersInfo(SPI_SETMOUSESPEED, 0, (void*)speed, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

	if (result)
	{
		printf("New mouse speed: %d\n", speed);
	}
	else
	{
		printf("Error setting mouse speed (error: 0x%X)\n", GetLastError());
	}

	return result;
}

int main(int argc, char* argv[])
{
	DWORD speed;
	DWORD value;

	if (argc == 1)
	{
		printf("Usage:\n");
		printf(" AdjustMouseSpeed [-s speed] [-i speed_difference] [-d speed_difference]\n");
		printf("\n");
		printf(" -s : Sets mouse speed to provided speed [1..20].\n");
		printf(" -i : Increases mouse speed by speed_difference [0..19].\n");
		printf(" -d : Decreases mouse speed by speed_difference [0..19].\n");

		return -1;
	}

	for (int i = 1; i < argc; ++i)
	{
		if ((argv[i][0] == '-') || (argv[i][0] == '\\'))
		{
			switch (argv[i][1])
			{
			case 's':
			case 'S':
				speed = atoi(argv[i + 1]);

				setMouseSpeed(speed);
				break;

			case 'i':
			case 'I':
				value = atoi(argv[i + 1]);

				if (value == 0)
					return -1;

				speed = getMouseSpeed();
				speed += value;

				if (!setMouseSpeed(speed))
					return -1;
				break;

			case 'd':
			case 'D':
				value = atoi(argv[i + 1]);

				if (value == 0)
					return -1;

				speed = getMouseSpeed();
				speed -= value;

				if (!setMouseSpeed(speed))
					return -1;
				break;
			}
		}
	}

	return 0;
}

