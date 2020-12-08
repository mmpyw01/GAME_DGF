#include "Menu.h"

Menu::Menu(float width, float height)
{
	this->KeyTimer = 0.f;
	this->KeyLapse = 1.f;

	this->font.loadFromFile("Fonts/maaja.ttf");
	text[0].setFont(font);
	text[0].setFillColor(Color::Yellow);
	text[0].setString("New Game");
	text[0].setCharacterSize(100);
	text[0].setPosition(Vector2f(960,350));

	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("How to play");
	text[1].setCharacterSize(125);
	text[1].setPosition(Vector2f(1150,570));

	text[2].setFont(font);
	text[2].setFillColor(Color::White);
	text[2].setString("Quit");
	text[2].setCharacterSize(120);
	text[2].setPosition(Vector2f(1575,800));

	currentLineIndex = 0;
}

Menu::~Menu()
{
}

void Menu::Draw(RenderWindow* window)
{
	for (int i = 0; i < NUM_OF_LINE; i++)
	{
		window->draw(text[i]);
	}
}

void Menu::MoveUp()
{
	if (currentLineIndex > 0)
	{
		text[currentLineIndex].setFillColor(Color::White);
		currentLineIndex--;
		text[currentLineIndex].setFillColor(Color::Yellow);
	}
}

void Menu::MovedDown()
{
	if (currentLineIndex < NUM_OF_LINE - 1)
	{
		text[currentLineIndex].setFillColor(Color::White);
		currentLineIndex++;
		text[currentLineIndex].setFillColor(Color::Yellow);
	}
}

void Menu::MenuUpdate(float dt)
{
	KeyTimer += dt;
	if (Keyboard::isKeyPressed(Keyboard::Down) && KeyTimer > KeyLapse)
	{
		KeyTimer -= KeyLapse;
		MovedDown();
	}
}

int Menu::GetLine()
{
	return this->currentLineIndex;
}