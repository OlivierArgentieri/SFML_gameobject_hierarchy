#include "SGH_Menu.h"
#include "SGH_GameManager.h"


SGH_Menu::SGH_Menu()
{
	title = new SGH_Text("PIXEAB__.ttf");
	title->SetString("Title");
	title->CenterPivot();
	title->SetPosition(1280/ 2, 20);
	title->SetSize(24);
	
	testButton = new SGH_Button("PIXEAB__.ttf", sf::Vector2f(10,10));

	buttonGame1 = new SGH_Button("PIXEAB__.ttf", sf::Vector2f(200, 30));
	buttonGame1->SetPosition(1280 / 2, 100);
	buttonGame1->SetString("Pong 1J");
	buttonGame1->SetColor(sf::Color::Blue);

	buttonGame2 = new SGH_Button("PIXEAB__.ttf", sf::Vector2f(200, 30));
	buttonGame2->SetPosition(1280 / 2, 150);
	buttonGame2->SetString("Pong 2J");
	buttonGame2->SetColor(sf::Color::Blue);

	buttonGame3 = new SGH_Button("PIXEAB__.ttf", sf::Vector2f(200, 30));
	buttonGame3->SetPosition(1280 / 2, 200);
	buttonGame3->SetString("Bric");
	buttonGame3->SetColor(sf::Color::Blue);
}

SGH_Menu::~SGH_Menu()
{
	delete title;
	
	delete buttonGame1;
	delete buttonGame2;
	delete buttonGame3;
}

void SGH_Menu::Update(sf::RenderWindow& _w)
{
	if (buttonGame1->Clicked(_w))
		SGH_GameManager::GetInstance()->PongOnePlayer(_w);

	if (buttonGame2->Clicked(_w))
		SGH_GameManager::GetInstance()->PongTwoPlayer(_w);

	if (buttonGame3->Clicked(_w))
		SGH_GameManager::GetInstance()->Bric(_w);

	Display(_w);
}

void SGH_Menu::Display(sf::RenderWindow& _w)
{
	title->Update(_w);
	
	buttonGame1->Update(_w);
	buttonGame2->Update(_w);
	buttonGame3->Update(_w);
}