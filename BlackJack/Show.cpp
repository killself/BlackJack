#include "Show.h"

Show::Show() : hConsole_(GetStdHandle(STD_OUTPUT_HANDLE))
{
	if (_setmode(_fileno(stdout), _O_U16TEXT) == -1)
	{
		throw;
	}	 
}

void Show::ShowCards(const Player& player)
{

	int changInX = 4;
	int changInY = -4;

	std::wcout << player.GetName();

	if (player.GetName() != L"Dealer")
	{
		std::wcout << "(wins: " << player.GetWinsCount() << ")";
	}

	std::wcout << "\nPoints: " << player.GetPoints() << "\n";

	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(hConsole_, &csbiInfo);
	_COORD cursorPosition = csbiInfo.dwCursorPosition;


	for (const Card* card : player.GetCardsOnHand())
	{
		SetConsoleCursorPosition(hConsole_, cursorPosition);
		std::wcout << " -----";

		++cursorPosition.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition);
		std::wcout << "|" << card->GetRank() << "   |";

		++cursorPosition.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition);
		std::wcout << "|  " << card->GetSuitUnicode() << "  |";

		++cursorPosition.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition);
		std::wcout << "|     |";

		++cursorPosition.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition);
		std::wcout << " ----- ";

		cursorPosition.X += changInX;
		cursorPosition.Y += changInY;

		Sleep(200);
	}

	std::wcout << "\n\n\n\n";
}