#include "Game.h"

Game::Game() : deck_(Deck()), player_(HumanPlayer()), dealer_(Dealer()), show_(Show())
{	
	players_.push_back(&player_);
}

bool Game::Menu()
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
			return false;
		}
		else if (menu == '2')
		{
			std::wcout << "\nGoodbye!\n\n";
			Sleep(900);
			return true;
		}

		system("cls");
	}
}

bool Game::EndRound()
{
	char playerChoice = ' ';

	while (true)
	{
		system("cls");
		std::wcout << "Do you want play again?(y/n): ";
		std::cin >> playerChoice;

		if (playerChoice == 'y')
		{
			//TODO...

			dealer_.NewPlay();

			for (Player* player : players_)
			{
				player->NewPlay();
			}

			return true;
		}
		else if (playerChoice == 'n')
		{
			break;
		}
	}

	return false;
}

bool Game::CheckSituations(const std::vector<Player*>& players) const
{
	bool check = false;

	for (Player* player : players)
	{
		check |= player->IsBusts();
	}

	return !check;
}

void Game::ShowCardsOnDesk()
{
	show_.ShowCards(dealer_);

	for (Player* player : players_)
	{
		show_.ShowCards(*player);
	}
}

void Game::ShowSituations(std::wstring name, std::wstring situation)
{
	std::wcout << "------------------\n";
	std::wcout << name << ", "<< situation << "!";
	std::wcout << "\n------------------\n\n";
}

void Game::Start()
{
	if (Menu())
	{
		return;
	}

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
			if (CheckSituations(players_))
			{
				while (!dealer_.IsPass())
				{
					dealer_.TakeCard(deck_.GiveCard());
					dealer_.MakeAMove();
					system("cls");
					ShowCardsOnDesk();
				}

				if (!dealer_.IsBusts())
				{
					for (Player* player : players_)
					{
						if (player->IsBusts())
						{
							ShowSituations(player->GetName(), L"lose");
						}
						else
						{
							if (player->GetPoints() > dealer_.GetPoints())
							{
								ShowSituations(player->GetName(), L"win");
							}
							else if (player->GetPoints() < dealer_.GetPoints())
							{
								ShowSituations(player->GetName(), L"lose");
							}
							else if (player->GetPoints() == dealer_.GetPoints() && player->GetPoints() != 21)
							{
								ShowSituations(player->GetName(), L"Push");
							}
							else if (player->GetPoints() == dealer_.GetPoints() && player->GetPoints() == 21)
							{
								if (player->IsBlackJack() && !dealer_.IsBlackJack())
								{
									ShowSituations(player->GetName(), L"win");
								}
								else if (!player->IsBlackJack() && dealer_.IsBlackJack())
								{
									ShowSituations(player->GetName(), L"lose");
								}
								else if (!player->IsBlackJack() && !dealer_.IsBlackJack())
								{
									ShowSituations(player->GetName(), L"Push");
								}
							}
						}
					}
				}
				else 
				{
					for (Player* player : players_)
					{
						if (!player->IsBusts())
						{
							ShowSituations(player->GetName(), L"win");
						}
					}
				}

				Sleep(1000);				
			}
			else
			{
				system("cls");

				if (!dealer_.IsBusts())
				{
					ShowSituations(dealer_.GetName(), L"win");
				}
				else
				{
					ShowSituations(L"All", L"lose");
				}

				Sleep(1000);
			}

			if (EndRound())
			{
				dealer_.TakeCard(deck_.GiveCard());
				continue;
			}
			else
			{
				std::wcout << "\nGoodbye!\n\n";
				Sleep(900);
				return;
			}
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