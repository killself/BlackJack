#include "Game.h"

Game::Game()
{
	deck_ = Deck();	
	//players.push_back(Dealer());
	//players.push_back(HumanPlayer());
}

void Game::Start()
{
	char menu = '0';

	while (true)
	{
		std::wcout << "*********************************************************************************\n";
		std::wcout << "\t\t\tThe Black Jack Game v0.01\n";
		std::wcout << "*********************************************************************************\n\n";
		std::wcout << "\nMENU:\n\n";
		std::wcout << "1. Play the game\n";
		std::wcout << "2. Exit\n";
		std::cin >> menu;

		if (menu == '1')
		{
			break;
		}
		else if (menu == '2')
		{
			std::wcout << "\nGoodbye!\n\n";
			Sleep(900);
			return;
		}

		system("cls");
	}

	while (true)
	{	
	
		HumanPlayer player = HumanPlayer();
		Dealer dealer = Dealer();
		players.push_back(dealer);
		players.push_back(player);
		//player.MakeAMove(deck_);
		players[1].MakeAMove(deck_);
		//for (unsigned int i = 0; i < players.size(); ++i)
		//{
		//	players[i].MakeAMove(deck_);
		//}

		//system("cls");

		//for (Player player : players)
		//{
		//	player.ShowCards();
		//}

		system("pause");		

	//	if ()
	//	{
	//		system("cls");
	//		std::cout << "\nYou win!\n\n";
	//		Sleep(1000);
	//		return 0;
	//	}
	//	Sleep(300);

	}
}