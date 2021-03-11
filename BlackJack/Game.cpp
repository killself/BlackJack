#include "Game.h"

Game::Game() : deck_(Deck()), player_(HumanPlayer()), dealer_(Dealer())
{
	players.push_back(&dealer_);
	players.push_back(&player_);
}

void Game::Menu()
{
	char menu = '0';

	while (true)
	{
		std::wcout << "*********************************************************************************\n";
		Sleep(150);
		std::wcout << "\t\t\tThe Black Jack Game v0.01\n";
		Sleep(150);
		std::wcout << "*********************************************************************************\n\n";
		Sleep(150);
		std::wcout << "\nMENU:\n\n";
		Sleep(150);
		std::wcout << "1. Play the game\n";
		Sleep(150);
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
}

void Game::Start()
{
	Menu();

	while (true)
	{	
		bool check = true;

		for (Player* player : players)
		{
			player->MakeAMove(deck_);
			check &= player->IsPass();
		}

		system("cls");

		Show show = Show();		

		for (Player* player : players)
		{
			show.ShowCards(*player);
		}

		//if (check)
		//{
		//	for (Player* player : players) // Что-то сделать с это фигнёй
		//	{
		//		if (player->GetName() != L"Dealer")
		//		{
		//			Situations situation = player->GetSituation();

		//			switch (situation)
		//			{
		//			case Situations::Pass:

		//				break;

		//			case Situations::TwentyOne:

		//				break;

		//			case Situations::BlackJack:

		//				break;

		//			case Situations::Busts:

		//				break;
		//			}						 
		//		}
		//	}
		//}

		Sleep(400);
	}
}