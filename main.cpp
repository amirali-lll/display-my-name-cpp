#include "SFML/Graphics.hpp"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>

using namespace sf;

//functios:

void printString(RenderWindow window, std::string text, int fontSize);
void setAlphabet(int*** alphabet, const int alphabetSize, const int height, const int weight);
void print_array_std(int**, const int height, const int weight);
void toUp(std::string&);
void initShape(RectangleShape& shape, Vector2f const& pos, bool isFill);



double cell_size = 10;

int main()
{
	std::string text;
	std::getline(std::cin, text);
	RenderWindow window(VideoMode(1100,400), "the title");
	//set target Rrames pes second:
	window.setFramerateLimit(60);
	//Render objects :
	RectangleShape cell(Vector2f(10, 10));
	
	Event ev;
	double x_start_pos = 10, y_start_pos = 10;
	const int height = 5;
	const int weight = 6;
	const int alphabetSize = 39;//26 char Upercase + '?''!'+ space +0-9
	int*** alphabet = new int** [alphabetSize];
	setAlphabet(alphabet,alphabetSize, height, weight);
	toUp(text);
	
	while (window.isOpen()) 
	{


		while (window.pollEvent(ev))
		{
				if (ev.type == Event::EventType::Closed)
					window.close();
				if (Keyboard::isKeyPressed(Keyboard::Key::Equal) || Keyboard::isKeyPressed(Keyboard::Key::PageUp))
					cell_size += 0.5;
				if (Keyboard::isKeyPressed(Keyboard::Key::Hyphen)|| Keyboard::isKeyPressed(Keyboard::Key::PageDown))
					cell_size -= 0.5;
				if (Keyboard::isKeyPressed(Keyboard::Key::Up))
					y_start_pos-=3;
				if (Keyboard::isKeyPressed(Keyboard::Key::Down))
					y_start_pos+=3;
				if (Keyboard::isKeyPressed(Keyboard::Key::Left))
					x_start_pos-=3;
				if (Keyboard::isKeyPressed(Keyboard::Key::Right))
					x_start_pos+=3;

		}
		//Update Frame :
		
		




		//Render Frame :
		window.clear(Color::White);
		int b;
		for (int i = 0; text[i] != '\0'; i++)
		{
			if (int(text[i]) > 64 && int(text[i]) < 91)
				b = int(text[i]) - 64;
			switch (int(text[i]))
			{
			case 32:
				b = 0;
				break;
			case 63:
				b = 28;
				break;
			case 33:
				b = 27;
				break;
			}
			if (int(text[i]) > 47 && int(text[i]) < 58)
				b = int(text[i]) - 19;
			for(int j=0;j<height;j++)
				for (int k = 0; k < weight; k++)
				{
					initShape(cell, Vector2f(cell_size * k + x_start_pos + (i * cell_size*weight), cell_size * j + y_start_pos), alphabet[b][j][k]);
					window.draw(cell);
				}
		}

		window.display();
		
	}
	return 0;
}

void printString(RenderWindow window, std::string text, int fontSize)
{
	for (int i = 0;text[i]!='\0' ; i++)
	{

	}
}

void setAlphabet(int*** alphabet, const int alphabetSize, const int height, const int weight)
{
	
	for (size_t i = 0; i < alphabetSize; i++)
	{
		alphabet[i] = new int* [height];
		for (int j = 0; j < height; j++)
			alphabet[i][j] = new int[weight] ;
		for (int j = 0; j < height; j++)
			for (int k = 0; k < weight; k++)
				alphabet[i][j][k] = 0;
	}
	//0=space
	
	//1=A 
	for (int j = 0; j < height; j++)
	{
		alphabet[1][j][1] = 1;
		alphabet[1][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[1][0][i] = 1;
		alphabet[1][2][i] = 1;
	}
	//2=B 
	for (int j = 0; j < height; j++)
	{
		alphabet[2][j][1] = 1;
		alphabet[2][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[2][0][i] = 1;
		alphabet[2][2][i] = 1;
		alphabet[2][4][i] = 1;
	}
	alphabet[2][0][4] = 0;
	alphabet[2][2][4] = 0;
	alphabet[2][4][4] = 0;
	//3=C
	for (int j = 0; j < height; j++)
	{
		alphabet[3][j][1] = 1;
		
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[3][0][i] = 1;
		alphabet[3][4][i] = 1;
	}
	alphabet[3][0][1] = 0;
	alphabet[3][4][1] = 0;
	//4=D
	for (int j = 0; j < height; j++)
	{
		alphabet[4][j][1] = 1;
		alphabet[4][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[4][0][i] = 1;
		alphabet[4][4][i] = 1;
	}
	alphabet[4][0][4] = 0;
	alphabet[4][4][4] = 0;
	//5=E
	for (int j = 0; j < height; j++)
	{
		alphabet[5][j][1] = 1;
		alphabet[5][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[5][0][i] = 1;
		alphabet[5][2][i] = 1;
		alphabet[5][4][i] = 1;
	}
	alphabet[5][1][4] = 0;
	alphabet[5][2][4] = 0;
	alphabet[5][3][4] = 0;
	//6=F
	for (int j = 0; j < height; j++)
	{
		alphabet[6][j][1] = 1;
		
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[6][0][i] = 1;
		alphabet[6][2][i] = 1;	
	}
	alphabet[6][2][4] = 0;
	//7=G
	for (int j = 0; j < height; j++)
	{
		alphabet[7][j][1] = 1;
		alphabet[7][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[7][0][i] = 1;
		alphabet[7][2][i] = 1;
		alphabet[7][4][i] = 1;
	}
	alphabet[7][0][1] = 0;
	alphabet[7][4][1] = 0;
	alphabet[7][1][4] = 0;
	alphabet[7][2][2] = 0;
	//8=H
	for (int j = 0; j < height; j++)
	{
		alphabet[8][j][1] = 1;
		alphabet[8][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		
		alphabet[8][2][i] = 1;
		
	}
	//9=I
	for (int i = 1; i <= 3; i++)
	{

		alphabet[9][0][i] = 1;
		alphabet[9][4][i] = 1;
	}
	for (int j = 0; j < height; j++)
		alphabet[9][j][2] = 1;
	//10=J
	for (int j = 0; j < height; j++)
		alphabet[10][j][4] = 1;
	for (int i = 1; i <= 4; i++)
		alphabet[10][4][i] = 1;
	alphabet[10][4][1] = 0;
	alphabet[10][4][4] = 0;
	alphabet[10][3][1] = 1;
	//11=K
	for (int j = 0; j < height; j++)
		alphabet[11][j][1] = 1;
	alphabet[11][2][2] = 1;
	alphabet[11][1][3] = 1;
	alphabet[11][0][4] = 1;
	alphabet[11][3][3] = 1;
	alphabet[11][4][4] = 1;
	//12=L
	for (int j = 0; j < height; j++)
		alphabet[12][j][1] = 1;
	alphabet[12][4][2] = 1;
	alphabet[12][4][3] = 1;
	//13=M
	for (int j = 0; j < height; j++) {
		alphabet[13][j][0] = 1;
		alphabet[13][j][4] = 1;
	}
	alphabet[13][2][2] = 1;
	alphabet[13][1][1] = 1;
	alphabet[13][1][3] = 1;
	//14=N
	for (int j = 0; j < height; j++)
	{
		alphabet[14][j][1] = 1;
		alphabet[14][j][4] = 1;
	}
	alphabet[14][1][2] = 1;
	alphabet[14][2][3] = 1;
	//15=O
	for (int j = 0; j < height; j++)
	{
		alphabet[15][j][1] = 1;
		alphabet[15][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{

		alphabet[15][0][i] = 1;
		alphabet[15][4][i] = 1;
	}
	alphabet[15][4][1] = 0;
	alphabet[15][0][1] = 0;
	alphabet[15][4][4] = 0;
	alphabet[15][0][4] = 0;
	//16=P
	for (int j = 0; j < height; j++)
	{
		alphabet[16][j][1] = 1;
		
	}
	for (int i = 1; i <= 3; i++)
	{

		alphabet[16][0][i] = 1;
		alphabet[16][2][i] = 1;
	}
	alphabet[16][1][4] = 1;
	//17=Q
	for (int j = 0; j < height; j++)
	{
		alphabet[17][j][1] = 1;
		alphabet[17][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{

		alphabet[17][0][i] = 1;
		alphabet[17][4][i] = 1;
	}
	alphabet[17][4][1] = 0;
	alphabet[17][0][1] = 0;
	alphabet[17][3][3] = 1;
	alphabet[17][0][4] = 0;
	alphabet[17][3][4] = 0;
	//18=R
	for (int j = 0; j < height; j++)
	{
		alphabet[18][j][1] = 1;

	}
	for (int i = 1; i <= 3; i++)
	{

		alphabet[18][0][i] = 1;
		alphabet[18][2][i] = 1;
	}
	alphabet[18][1][4] = 1;
	alphabet[18][4][4] = 1;
	alphabet[18][3][3] = 1;
	//19=S
	
	for (int i = 1; i <= 4; i++)
	{
		alphabet[19][0][i] = 1;
		alphabet[19][4][i] = 1;
	}
	alphabet[19][0][1] = 0;
	alphabet[19][4][4] = 0;
	alphabet[19][1][1] = 1;
	alphabet[19][2][2] = 1;
	alphabet[19][3][4] = 1;
	alphabet[19][2][3] = 1;
	//20=T
	for (int j = 0; j < height; j++)
		alphabet[20][j][2] = 1;
	alphabet[20][0][1] = 1;
	alphabet[20][0][3] = 1;
	//21=U
	for (int j = 0; j < height; j++)
	{
		alphabet[21][j][1] = 1;
		alphabet[21][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
		alphabet[21][4][i] = 1;
	//22=V 
	for (int j = 0; j < height; j++)
	{
		alphabet[22][j][2] = 1;
		alphabet[22][j][4] = 1;
	}
	alphabet[22][4][2] = 0;
	alphabet[22][4][4] = 0;
	alphabet[22][4][3] = 1;
	//23=W
	for (int j = 0; j < height; j++)
	{
		alphabet[23][j][0] = 1;
		alphabet[23][j][4] = 1;
	}
	alphabet[23][4][0] = 0;
	alphabet[23][4][4] = 0;
	alphabet[23][4][3] = 1;
	alphabet[23][4][1] = 1;
	alphabet[23][3][2] = 1;
	//24=X
	for (int j = 0; j < height; j++)
	{
		alphabet[24][j][1] = 1;
		alphabet[24][j][3] = 1;
	}
	alphabet[24][2][1] = 0;
	alphabet[24][2][3] = 0;
	alphabet[24][2][2] = 1;
	//25=Y
	for (int j = 0; j < height-2; j++)
	{
		alphabet[25][j][1] = 1;
		alphabet[25][j][3] = 1;
	}
	alphabet[25][4][2] = 1;
	alphabet[25][3][2] = 1;
	alphabet[25][2][2] = 1;
	//26=Z
	for (int i = 1; i <= 4; i++)
	{
		alphabet[26][0][i] = 1;
		alphabet[26][4][i] = 1;
	}
	alphabet[26][1][4] = 1;
	alphabet[26][2][3] = 1;
	alphabet[26][3][2] = 1;
	//27='!'
	for (int j = 0; j < height; j++)
		alphabet[27][j][2] = 1;
	alphabet[27][3][2] = 0;
	//28='?'
	alphabet[28][0][2] = 1;
	alphabet[28][2][2] = 1;
	alphabet[28][4][2] = 1;
	alphabet[28][0][3] = 1;
	alphabet[28][2][3] = 1;
	alphabet[28][1][4] = 1;
	//29='0'
	for (int j = 0; j < height; j++)
	{
		alphabet[29][j][1] = 1;
		alphabet[29][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
	
		alphabet[29][0][i] = 1;
		alphabet[29][4][i] = 1;
	}
	//30='1'
	for (int j = 0; j < height; j++)
		alphabet[30][j][3] = 1;
	alphabet[30][1][2] = 1;
	alphabet[30][4][2] = 1;
	alphabet[30][4][4] = 1;
	//31='2'
	for (int j = 0; j < height; j++)
	{
		alphabet[31][j][1] = 1;
		alphabet[31][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[31][2][i] = 1;
		alphabet[31][0][i] = 1;
		alphabet[31][4][i] = 1;
	}
	alphabet[31][1][1] = 0;
	alphabet[31][3][4] = 0;
	//32='3'
	for (int j = 0; j < height; j++)
	{
		alphabet[32][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[32][2][i] = 1;
		alphabet[32][0][i] = 1;
		alphabet[32][4][i] = 1;
	}
	//33='4'
	for (int j = 0; j < height; j++)
	{
		alphabet[33][j][1] = 1;
		alphabet[33][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{

		alphabet[33][2][i] = 1;

	}
	alphabet[33][3][1] = 0;
	alphabet[33][4][1] = 0;
	//34='5'
	for (int j = 0; j < height; j++)
	{
		alphabet[34][j][1] = 1;
		alphabet[34][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[34][2][i] = 1;
		alphabet[34][0][i] = 1;
		alphabet[34][4][i] = 1;
	}
	alphabet[34][3][1] = 0;
	alphabet[34][1][4] = 0;
	//35='6'
	for (int j = 0; j < height; j++)
	{
		alphabet[35][j][1] = 1;
		alphabet[35][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[35][2][i] = 1;
		alphabet[35][0][i] = 1;
		alphabet[35][4][i] = 1;
	}
	alphabet[35][1][4] = 0;
	//36='7'
	for (int i = 1; i <= 4; i++)
		alphabet[36][0][i] = 1;
	alphabet[36][1][4] = 1;
	alphabet[36][2][3] = 1;
	alphabet[36][3][2] = 1;
	alphabet[36][4][1] = 1;
	//37='8'
	for (int j = 0; j < height; j++)
	{
		alphabet[37][j][1] = 1;
		alphabet[37][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[37][2][i] = 1;
		alphabet[37][0][i] = 1;
		alphabet[37][4][i] = 1;
	}
	//38='9'
	for (int j = 0; j < height; j++)
	{
		alphabet[38][j][1] = 1;
		alphabet[38][j][4] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		alphabet[38][2][i] = 1;
		alphabet[38][0][i] = 1;
		alphabet[38][4][i] = 1;
	}
	alphabet[38][3][1] = 0;








}

void print_array_std(int** arr, const int height, const int weight)
{
	for (int i = 0; i < height; i++){
		for (int j = 0; j < weight; j++)
			if (arr[i][j] == 1)
				std::cout << "*";
			else
				std::cout << ' ';
		std::cout <<'\n';
	}
}

void toUp(std::string& text )
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (int(text[i]) > 96 && int(text[i]) < 123)
			text[i] -= 32;
		
	
	}
}

void initShape(RectangleShape& shape, Vector2f const& pos, bool isFill)
{
	shape.setSize(Vector2f(cell_size,cell_size));
	if (isFill)
		shape.setFillColor(Color::Cyan);
	else
		shape.setFillColor(Color::White);
	shape.setOutlineColor(Color::Black);
	shape.setOutlineThickness(1);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}
