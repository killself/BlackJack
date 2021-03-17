#include "Game.h"

Game::Game() : deck_(Deck()), player_(HumanPlayer()), dealer_(Dealer()), show_(Show())
{	
	players_.push_back(&player_);
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

bool Game::Check(const std::vector<Player*>& players) const
{
	// TODO...
	return true;
}

void Game::ShowCardsOnDesk()
{
	show_.ShowCards(dealer_);

	for (Player* player : players_)
	{
		show_.ShowCards(*player);
	}
}

void Game::Start()
{
	Menu();

	dealer_.TakeCard(deck_.GiveCard());

	while (true)
	{	
		bool check = false;		

		for (Player* player : players_)
		{
			player->MakeAMove();

			if (!player->IsPass())
			{
				player->TakeCard(deck_.GiveCard());
			}
			else
			{
				check |= true;
			}
		}

		if (check)
		{
			if (Check(players_))
			{
				while (!dealer_.IsPass())
				{
					dealer_.TakeCard(deck_.GiveCard());
					dealer_.MakeAMove();
					system("cls");
					ShowCardsOnDesk();
				}

				std::wcout << "HuH'";
				Sleep(1000);
				return;
			}
			else
			{
				// TODO...
			}

			// TODO it, bleat'..
		}

		system("cls");
		ShowCardsOnDesk();
		Sleep(400);
	}
}


//	for (Player* player : players) // Что-то сделать с это фигнёй
//	{
//		if (player->GetName() != L"Dealer")
//		{
//			Situations situation = player->GetSituation();
//
//			switch (situation)
//			{
//			case Situations::Pass:
//
//				break;
//
//			case Situations::TwentyOne:
//
//				break;
//
//			case Situations::BlackJack:
//
//				break;
//
//			case Situations::Busts:
//
//				break;
//			}						 
//		}
//	}
