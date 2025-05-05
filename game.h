
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
#include "Addon.h"
#include <fstream>

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
	Sprite background; //Game background sprite
	Texture bg_texture;
	Player* p;
	Enemy ** e;
	Addon ** ad;
	int phase;
	int level;
	int score;



	Game()
	{
		score = 0;
		e=new Enemy*[5];
		ad = new Addon*[4];
		ad[0] = new Power;
		ad[1] = new Life;
		ad[2] = new Danger;
		ad[3] = new Fire;
		e[0]=new Alpha[14];
		e[1]=new Beta [13];
		e[2]=new Gamma[13];
		e[3]=new Monster;
		e[4]=new Dragon;
		p=new Player;
		phase = 1;
		level = 1;
		bg_texture.loadFromFile("img/background.png");
		background.setTexture(bg_texture);
		background.setScale(2.5, 1.5);

	}
	void shape_alpha_rectangle()
	{
		for (int i = 0 ; i < 6; i ++)
		{

			e[0][i].sprite.setPosition(100+(i*100) , 100);
		}
		int count = 0;
		for (int i = 6 ; i < 8 ; i++)
		{
			e[0][i].sprite.setPosition(100+(count*100) , 200);
			count+=5;
		}
		count = 0;
		for (int i = 8 ; i < 14 ; i++)
		{
			e[0][i].sprite.setPosition(100+(count*100) , 300);
			count++;
		}
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
	}
	void shape_beta_triangle()
	{
		e[1][0].sprite.setPosition(350,30);
		e[1][1].sprite.setPosition(280, 100);
		e[1][2].sprite.setPosition(420, 100);
		e[1][3].sprite.setPosition(210, 170);
		e[1][4].sprite.setPosition(490, 170);
		e[1][5].sprite.setPosition(160, 240);
		e[1][6].sprite.setPosition(560, 240);
		e[1][7].sprite.setPosition(90, 310);
		e[1][8].sprite.setPosition(630, 310);
		e[1][9].sprite.setPosition(200, 310);
		e[1][10].sprite.setPosition(520, 310);
		e[1][11].sprite.setPosition(410, 310);
		e[1][12].sprite.setPosition(310, 310);
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void shape_gamma_cross()
	{
		e[2][0].sprite.setPosition(100,50);
		e[2][1].sprite.setPosition(180,100);
		e[2][2].sprite.setPosition(260,150);
		e[2][3].sprite.setPosition(340,200);
		e[2][4].sprite.setPosition(420,250);
		e[2][5].sprite.setPosition(500,300);
		e[2][6].sprite.setPosition(580,350);
		e[2][7].sprite.setPosition(100,350);
		e[2][8].sprite.setPosition(180,300);
		e[2][9].sprite.setPosition(260,250);
		e[2][10].sprite.setPosition(420,150);
		e[2][11].sprite.setPosition(500,100);
		e[2][12].sprite.setPosition(580,50);
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}

	}
	void shape_circle()
	{
		e[0][0].sprite.setPosition(150,200-100);
		e[1][0].sprite.setPosition(150,300-100);
		e[2][0].sprite.setPosition(150,400-100);
		e[0][1].sprite.setPosition(250,100-100);
		e[1][1].sprite.setPosition(350,100-100);
		e[2][1].sprite.setPosition(450,100-100);
		e[0][2].sprite.setPosition(550,200-100);
		e[1][2].sprite.setPosition(550,300-100);
		e[2][2].sprite.setPosition(550,400-100);
		e[0][3].sprite.setPosition(450,500-100);
		e[1][3].sprite.setPosition(350,500-100);
		e[2][3].sprite.setPosition(250,500-100);
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void shape_diamond()
	{
		e[0][0].sprite.setPosition(250,100-100);
		e[1][0].sprite.setPosition(350,100-100);
		e[2][0].sprite.setPosition(450,100-100);
		e[0][1].sprite.setPosition(100,100);
		e[1][1].sprite.setPosition(600,100);
		e[2][1].sprite.setPosition(100,200);
		e[0][2].sprite.setPosition(600,200);
		e[1][2].sprite.setPosition(600,100);
		e[2][2].sprite.setPosition(200,250);
		e[0][3].sprite.setPosition(500,250);
		e[1][3].sprite.setPosition(300,300);
		e[2][3].sprite.setPosition(400,300);
		e[0][4].sprite.setPosition(350,350);
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void shape_heart()
	{
		e[0][0].sprite.setPosition(250,100-100);
		e[1][0].sprite.setPosition(350,50);
		e[2][0].sprite.setPosition(450,100-100);
		e[0][1].sprite.setPosition(100,100);
		e[1][1].sprite.setPosition(600,100);
		e[2][1].sprite.setPosition(100,200);
		e[0][2].sprite.setPosition(600,200);
		e[1][2].sprite.setPosition(600,100);
		e[2][2].sprite.setPosition(200,250);
		e[0][3].sprite.setPosition(500,250);
		e[1][3].sprite.setPosition(300,300);
		e[2][3].sprite.setPosition(400,300);
		e[0][4].sprite.setPosition(350,350);
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void shape_filled_rectangle()
	{
		for (int i = 0 ; i < 6; i ++)
		{

			e[0][i].sprite.setPosition(100+(i*100) , 100);
		}
		int count = 0;
		for (int i = 6 ; i < 8 ; i++)
		{
			e[0][i].sprite.setPosition(100+(count*100) , 200);
			count+=5;
		}
		count = 0;
		for (int i = 1 ; i <= 6 ; i++)
		{
			e[2][i].sprite.setPosition(100+(count*100) , 300);
			count++;
		}
		for (int i = 1 ; i <= 4 ; i++)
		{
			e[1][i].sprite.setPosition(100+(i * 100) , 180);
		}
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void shape_filled_triangle()
	{
		e[1][0].sprite.setPosition(350,30);
		e[1][1].sprite.setPosition(280, 100);
		e[0][1].sprite.setPosition(350 , 125);
		e[0][2].sprite.setPosition(420 , 200);
		e[0][3].sprite.setPosition(280 , 200);
		e[0][4].sprite.setPosition(350 , 200);
		e[0][5].sprite.setPosition(490 , 275);
		e[0][6].sprite.setPosition(215 , 275);
		e[0][7].sprite.setPosition(420 , 275);
		e[0][8].sprite.setPosition(280 , 275);
		e[0][9].sprite.setPosition(350 , 200);
		e[1][2].sprite.setPosition(420, 100);
		e[1][3].sprite.setPosition(210, 170);
		e[1][4].sprite.setPosition(490, 170);
		e[1][5].sprite.setPosition(160, 240);
		e[1][6].sprite.setPosition(560, 240);
		e[2][7].sprite.setPosition(90, 320);
		e[2][8].sprite.setPosition(630, 320);
		e[2][9].sprite.setPosition(200, 320);
		e[2][10].sprite.setPosition(520, 320);
		e[2][11].sprite.setPosition(410, 320);
		e[2][12].sprite.setPosition(310, 320);
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}
	}
	void shape_filled_circle()
	{

		e[0][0].sprite.setPosition(150,200-100);
		e[1][0].sprite.setPosition(150,300-100);
		e[2][0].sprite.setPosition(150,400-100);
		e[0][4].sprite.setPosition(250,200-100);
		e[1][4].sprite.setPosition(250,300-100);
		e[2][4].sprite.setPosition(250,400-100);
		e[0][5].sprite.setPosition(350,200-100);
		e[1][5].sprite.setPosition(350,300-100);
		e[2][5].sprite.setPosition(350,400-100);
		e[0][6].sprite.setPosition(450,200-100);
		e[1][6].sprite.setPosition(450,300-100);
		e[2][6].sprite.setPosition(450,400-100);
		e[0][1].sprite.setPosition(250,100-100);
		e[1][1].sprite.setPosition(350,100-100);
		e[2][1].sprite.setPosition(450,100-100);
		e[0][2].sprite.setPosition(550,200-100);
		e[1][2].sprite.setPosition(550,300-100);
		e[2][2].sprite.setPosition(550,400-100);
		e[0][3].sprite.setPosition(450,500-100);
		e[1][3].sprite.setPosition(350,500-100);
		e[2][3].sprite.setPosition(250,500-100);
		for (int i = 0 ; i < 14 ; i++)
		{
			e[0][i].bom->laser.setPosition(e[0][i].sprite.getPosition().x+20,e[0][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[2][i].bom->laser.setPosition(e[2][i].sprite.getPosition().x+20,e[2][i].sprite.getPosition().y+20);
		}
		for (int i = 0 ; i < 13 ; i++)
		{
			e[1][i].bom->laser.setPosition(e[1][i].sprite.getPosition().x+20,e[1][i].sprite.getPosition().y+20);
		}

	}
	void set_monster_position()
	{
		e[3]->sprite.setPosition(-1000,0);
	}
	void set_dragon_position()
	{
		e[4]->sprite.setPosition(150,-500);
	}
	void start_game()
	{
		Font score_font;
		score_font.loadFromFile("MachineGunk-nyqg.ttf");
		Text text_score("0" , score_font);
		text_score.setCharacterSize(25);
		text_score.setPosition(0,0);//this is position of the text on the window
		text_score.setString("Score = ");//this is whats gonna be displayed on the screen
		text_score.setFont(score_font);
		Text text_lives("0" , score_font);
		text_lives.setCharacterSize(25);
		text_lives.setPosition(0,50);//this is position of the text on the window
		text_lives.setString("LIVES = ");//this is whats gonna be displayed on the screen
		text_lives.setFont(score_font);
		Text text_level("0" , score_font);
		text_level.setCharacterSize(25);
		text_level.setPosition(690,0);//this is position of the text on the window
		text_level.setString("LEVEL = ");//this is whats gonna be displayed on the screen
		text_level.setFont(score_font);
		Text text_phase("0" , score_font);
		text_phase.setCharacterSize(25);
		text_phase.setPosition(690,50);//this is position of the text on the window
		text_phase.setString("PHASE = ");//this is whats gonna be displayed on the screen
		text_phase.setFont(score_font);
		Text text_game_over("0" , score_font);
		text_game_over.setCharacterSize(100);
		text_game_over.setPosition(0,200);//this is position of the text on the window
		text_game_over.setString("  GAME OVERRRRRRR  ");//this is whats gonna be displayed on the screen
		text_game_over.setFont(score_font);
		Text text_pause("0" , score_font);
		text_pause.setCharacterSize(100);
		text_pause.setPosition(0,200);//this is position of the text on the window
		text_pause.setString("  PAUSED  ");//this is whats gonna be displayed on the screen
		text_pause.setFont(score_font);
		Text text_restart("0" , score_font);
		text_restart.setCharacterSize(40);
		text_restart.setPosition(160,400);//this is position of the text on the window
		text_restart.setString("  PRESS R TO RESTART  ");//this is whats gonna be displayed on the screen
		text_restart.setFont(score_font);
		Text text_exit("0" , score_font);
		text_exit.setCharacterSize(40);
		text_exit.setPosition(160,500);//this is position of the text on the window
		text_exit.setString("  PRESS Escaape TO Exit  ");//this is whats gonna be displayed on the screen
		text_exit.setFont(score_font);
		srand(time(0));
		RenderWindow window(VideoMode(780, 780), title);
		Clock clock;
		int temp3 = 0;
		int temp4 = 0;
		int temp5 = 0;
		int temp6 = 0;
		int temp7 = 0;
		int temp8  =0;
		int temp9 = 0;
		int temp10 = 0;
		int temp11 = 0;
		int temp12 = 0;
		int temp13 = 0;
		int temp14 = 0;
		int temp15 = 0;
		int temp16 = 0;
		float timer = 0;
		float timer2 = 0;
		float timer3 = 0;
		float timer4 = 0;
		float timer5 = 0;
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;
		bool flag4 = false;
		bool flag5 = false;
		bool flag6 = false;
		bool flag7 = false;
		bool flag8 = false;
		bool flag9 = false;
		bool flag10 = false;
		bool flag11 = false;
		bool flag12 = false;
		bool flag13 = false;
		bool flag14 = false;
		bool flag15 = false;
		bool flag16 = false;
		bool flag17 = false;
		bool flag18 = false;
		bool flag19 = false;
		bool flag20 = false;
		bool flag21 = false;
		bool flag22 = false;
		bool flag23 = false;
		bool flag24 = false;
		bool flag25 = false;
		bool wait = true;
		bool wait1 = true;
		int count = 0;
		int count2 = 0;
		int count3 = 0;
		int count4 = 0;
		int count5 = 0;
		int count6 = 0;
		while (window.isOpen())
		{
			if (wait == true && wait1 == true)
			{
				text_score.setString("Score = "+std::to_string(score));
				text_lives.setString("LIVES = "+std::to_string(p->lives));
				text_phase.setString("Phase = "+std::to_string(phase));
				text_level.setString("LEVEL = "+std::to_string(level));
				if (phase == 1 && flag3 == false && level == 1)
				{
					shape_alpha_rectangle();
					flag3 = true;
				}
				if (phase == 2 && flag4 == false && level == 1)
				{
					shape_beta_triangle();
					flag4 = true;
				}
				if (phase == 3 && flag8 == false && level == 1)
				{
					shape_gamma_cross();
					flag8 = true;
				}
				if (phase == 1 && level == 2 && flag20 == false)
				{
					shape_circle();
					flag20 = true;
				}
				if (phase == 2 && level == 2 && flag21 == false)
				{
					shape_diamond();
					flag21 = true;
				}
				if (phase == 3 && level == 2 && flag22 == false)
				{
					shape_heart();
					flag22 = true;
				}
				if (phase == 1 && level == 3 && flag23 == false)
				{
					shape_filled_rectangle();
					flag23 = true;
				}
				if (phase == 2 && level == 3 && flag24 == false)
				{
					shape_filled_triangle();
					flag24 = true;
				}
				if (phase == 3 && level == 3 && flag25 == false)
				{
					shape_filled_circle();
					flag25 = true;
				}
				if (flag13 == false)
				{
					temp10 = rand()%4;
					temp9 = rand()%780;
					ad[temp10]->sprite.setPosition(temp9 , -200);
					flag13 = true;
				}
				if ( flag10 == false)
				{
					set_monster_position();
					flag10 = true;
				}
				if (flag1 == false )
				{
					count = 1+rand()%2;
					count2 = rand()%14;
					flag1 = true;
				}
				if (flag5 == false)
				{
					count3 = rand()%13;
					count4 = 1+rand()%2;
					flag5 = true;
				}
				if (flag7 == false)
				{
					count5 = rand()%13;
					count6 = 1+rand()%2;
					flag7 = true;
				}
				float time = clock.getElapsedTime().asSeconds();
				clock.restart();
				timer+=time;
				timer4+=time;
				if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
					p->move("l");    // Player will move to left
				if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
					p->move("r");  //player will move to right
				if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
					p->move("u");    //playet will move upwards
				if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
					p->move("d");
				if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
				{
					flag18 = true;
					p->left_sprite.setPosition(p->sprite.getPosition().x , p->sprite.getPosition().y);
				}
				else
					flag18 = false;
				if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
				{
					flag19 = true;
					p->right_sprite.setPosition(p->sprite.getPosition().x , p->sprite.getPosition().y);
				}
				else
					flag19 = false;
				if (flag17 != true)
					p->fire();
				else
				{
					timer5+=time;
					if (timer5 >= 5)
					{
						flag17 = false;
						timer5 = 0;
					}
					p->b->fire_sprite.setPosition(-4000,0);
					p->b->aag.setPosition(p->sprite.getPosition() .x- 15,p->sprite.getPosition().y - 620);
				}
				if (flag17 == false)
					p->b->aag.setPosition(1000 ,-1000);
				temp8 = rand()%99999;
				if(temp8 == 501 || flag16 == true)
				{
					ad[temp10]->move();
					flag16 = true;
					if (ad[temp10]->sprite.getPosition().y > 780)
					{
						flag13 = false;
						flag16 = false;
					}
				}
				if (ad[1]->sprite.getPosition().x + 10 >= p->sprite.getPosition().x && ad[1]->sprite.getPosition().x <= p->sprite.getPosition().x + 50 && ad[1]->sprite.getPosition().y + 30 >= p->sprite.getPosition().y && ad[1]->sprite.getPosition().y  <= p->sprite.getPosition().y + 50)
				{
					ad[1]->sprite.setPosition(-100 , 0);
					p->lives++;
				}
				if (p->sprite.getPosition().x + 30 >= ad[2]->sprite.getPosition().x && p->sprite.getPosition().x <= ad[2]->sprite.getPosition().x+270 &&p->sprite.getPosition().y + 30 >= ad[2]->sprite.getPosition().y && p->sprite.getPosition().y <= ad[2]->sprite.getPosition().y+120)
				{
					ad[2]->sprite.setPosition(-500 , 0);
					p->lives--;
					p->sprite.setPosition(p->x , p->y);
				}

				if (ad[3]->sprite.getPosition().x + 10 >= p->sprite.getPosition().x && ad[3]->sprite.getPosition().x <= p->sprite.getPosition().x + 50 && ad[3]->sprite.getPosition().y + 30 >= p->sprite.getPosition().y && ad[3]->sprite.getPosition().y  <= p->sprite.getPosition().y + 50)
				{
					ad[3]->sprite.setPosition(-100 , 0);
					flag17 = true;
				}
				if (ad[0]->sprite.getPosition().x + 10 >= p->sprite.getPosition().x && ad[0]->sprite.getPosition().x <= p->sprite.getPosition().x + 50 && ad[0]->sprite.getPosition().y + 30 >= p->sprite.getPosition().y && ad[0]->sprite.getPosition().y  <= p->sprite.getPosition().y + 50)
				{
					ad[0]->sprite.setPosition(-100 , 0);
				}
				//random coming for monster and its movement etc
				temp6 = rand()%99999;
				if ((temp6 == 501 || flag12 == true) & flag14 == false)
				{
					timer2 += time;
					//timer2 =0;
					for (int i = 0 ; i < 14 ; i++)
					{
						if (e[0][i].sprite.getPosition().x > 0)
						{
							e[0][i].sprite.setPosition(-1000,0);
							e[0][i].bom->laser.setPosition(-1000,0);
						}
					}
					for (int i = 0 ; i < 13 ; i++)
					{
						if (e[1][i].sprite.getPosition().x > 0)
						{
							e[1][i].sprite.setPosition(-1000,0);
							e[1][i].bom->laser.setPosition(-1000,0);
						}
					}
					for (int i = 0 ; i < 13 ; i++)
					{
						if (e[2][i].sprite.getPosition().x > 0)
						{
							e[2][i].sprite.setPosition(-1000,0);
							e[2][i].bom->laser.setPosition(-1000,0);
						}
					}
					e[3]->move();
					if (timer2 >= 10 )
					{
						e[3]->sprite.setPosition(-1000,0);
						flag12 = false;
						timer2= 0;
						phase++;
						score+=40;
					}
					else
					{
						flag12 = true;
					}
				}

				if (flag12 == true && flag11 == false)
				{
					timer = 0;
					timer2  = 0;
					flag11 = true;
				}
				if (timer >= 1)
				{
					e[3]->laser.setPosition(e[3]->sprite.getPosition().x + 145 , e[3]->sprite.getPosition().y+80);
					if (timer >=2)
					{
						timer = 0;
						e[3]->laser.setPosition(-1000 , 0);
					}
				}
				// random coming of dragon and its movement etc
				temp7 = rand()%99999;
				if ((temp7 == 501 || flag14 == true) & flag12 == false)
				{
					timer3 += time;
					for (int i = 0 ; i < 14 ; i++)
					{
						if (e[0][i].sprite.getPosition().x > 0)
						{
							e[0][i].sprite.setPosition(-1000,0);
							e[0][i].bom->laser.setPosition(-1000,0);
						}
					}
					for (int i = 0 ; i < 13 ; i++)
					{
						if (e[1][i].sprite.getPosition().x > 0)
						{
							e[1][i].sprite.setPosition(-1000,0);
							e[1][i].bom->laser.setPosition(-1000,0);
						}
					}
					for (int i = 0 ; i < 13 ; i++)
					{
						if (e[2][i].sprite.getPosition().x > 0)
						{
							e[2][i].sprite.setPosition(-1000,0);
							e[2][i].bom->laser.setPosition(-1000,0);
						}
					}
					e[4]->move();
					if (timer3 >= 10 )
					{
						e[4]->sprite.setPosition(150,-500);
						e[4]->laser.setPosition(-1000,0);
						flag14 = false;
						timer3= 0;
						phase++;
						score+=50;
					}
					else
					{
						flag14 = true;
					}
				}
				if (flag14 == true && flag15 == false)
				{
					timer = 0;
					timer3  = 0;
					flag15 = true;
				}
				if (timer4 >= 1)
				{
					if (e[4]->sprite.getPosition().y <= -100 && e[4]->sprite.getPosition().y >=-150)
					{
						if (p->sprite.getPosition().x > 500)
						{
							e[4]->laser.setTexture(e[4]->laser_tex_2);
							e[4]->laser.setPosition(e[4]->sprite.getPosition().x+200, e[4]->sprite.getPosition().y+380);
						}
						else if (p->sprite.getPosition().x < 200)
						{
							e[4]->laser.setTexture(e[4]->laser_tex_1);
							e[4]->laser.setPosition(e[4]->sprite.getPosition().x -300, e[4]->sprite.getPosition().y+380);
						}
						else if(p->sprite.getPosition().x > 200&&p->sprite.getPosition().x < 500)
						{
							e[4]->laser.setTexture(e[4]->laser_tex_1);
							e[4]->laser.setTexture(e[4]->laser_tex);
							e[4]->laser.setPosition(e[4]->sprite.getPosition().x + 165 , e[4]->sprite.getPosition().y+380);
						}
					}
					if(p->sprite.getPosition().x>= 320 && p->sprite.getPosition().x<= 450 && e[4]->laser.getPosition().x>= 0)
					{
						p->sprite.setPosition(p->x-100 , p->y);
						p->lives--;
					}
					else if (p->sprite.getPosition().x >= 600 &&  p->sprite.getPosition().x <= 780&& e[4]->laser.getPosition().x>= 0)
					{
						p->sprite.setPosition(p->x-100 , p->y);
						p->lives--;
					}
					if (timer4 >=4)
					{
						timer4 = 0;
						e[4]->laser.setPosition(-1000 , -1000);
					}
				}

				// random fire for alpha
				if(e[0][count2].sprite.getPosition().x>0)
					e[0][count2].shoot(count);
				else
					e[0][count2].bom->flag = false;
				if (e[0][count2].bom->flag == false)
					flag1 = false;
				// random fire for beta
				if(e[1][count3].sprite.getPosition().x>0)
					e[1][count3].shoot(count4);
				else
					e[1][count3].bom->flag = false;
				if (e[1][count3].bom->flag == false)
					flag5 = false;
				// random fire for gamma
				if(e[2][count5].sprite.getPosition().x>0)
					e[2][count5].shoot(count6);
				else
					e[2][count5].bom->flag = false;
				if (e[2][count5].bom->flag == false)
					flag7 = false;

				//this checks collision between players laser and enemy ship
				for (int i = 0 ; i < 14 ; i++)
				{
					if ((p->b->fire_sprite.getPosition().x>=e[0][i].sprite.getPosition().x &&p->b->fire_sprite.getPosition().x<=e[0][i].sprite.getPosition().x+50 && p->b->fire_sprite.getPosition().y>=e[0][i].sprite.getPosition().y &&p->b->fire_sprite.getPosition().y<=e[0][i].sprite.getPosition().y+50) ||(p->b->aag.getPosition().x + 80 >= e[0][i].sprite.getPosition().x && p->b->aag.getPosition().x  <= e[0][i].sprite.getPosition().x + 50) )
					{
						p->b->fire_sprite.setPosition(-200 , p->b->fire_sprite.getPosition().y);
						e[0][i].sprite.setPosition(-500 , -200);
						e[0][i].bom->laser.setPosition(-100 , e[0][i].bom->laser.getPosition().y);
						score+=10 * level;
						temp3++;
						if (level == 2 && phase == 1)
							temp11++;
						if (level == 2 && phase ==2)
							temp12++;
						if (level == 2 && phase == 3)
							temp13++;
						if (level == 3 && phase == 1)
							temp14++;
						if (level == 3 && phase ==2)
							temp15++;
						if (level == 3 && phase == 3)
							temp16++;
					}
				}
				for (int i = 0 ; i < 13 ; i++)
				{
					if ((p->b->fire_sprite.getPosition().x>=e[1][i].sprite.getPosition().x &&p->b->fire_sprite.getPosition().x<=e[1][i].sprite.getPosition().x+50 && p->b->fire_sprite.getPosition().y>=e[1][i].sprite.getPosition().y &&p->b->fire_sprite.getPosition().y<=e[1][i].sprite.getPosition().y+50)||(p->b->aag.getPosition().x + 80 >= e[1][i].sprite.getPosition().x && p->b->aag.getPosition().x  <= e[1][i].sprite.getPosition().x + 50) )
					{
						p->b->fire_sprite.setPosition(-200 , p->b->fire_sprite.getPosition().y);
						e[1][i].bom->laser.setPosition(-100 , e[1][i].bom->laser.getPosition().y);
						e[1][i].sprite.setPosition(-500 , -200);
						score+=10*level;
						temp4++;
						if (level == 2 && phase == 1)
							temp11++;
						if (level == 2 && phase ==2)
							temp12++;
						if (level == 2 && phase == 3)
							temp13++;
						if (level == 3 && phase == 1)
							temp14++;
						if (level == 3 && phase ==2)
							temp15++;
						if (level == 3 && phase == 3)
							temp16++;
					}
				}
				for (int i = 0 ; i < 13 ; i++)
				{
					if ((p->b->fire_sprite.getPosition().x>=e[2][i].sprite.getPosition().x &&p->b->fire_sprite.getPosition().x<=e[2][i].sprite.getPosition().x+70 && p->b->fire_sprite.getPosition().y>=e[2][i].sprite.getPosition().y &&p->b->fire_sprite.getPosition().y<=e[2][i].sprite.getPosition().y+50)||(p->b->aag.getPosition().x + 80 >= e[2][i].sprite.getPosition().x && p->b->aag.getPosition().x  <= e[2][i].sprite.getPosition().x + 50) )
					{
						p->b->fire_sprite.setPosition(-200 , p->b->fire_sprite.getPosition().y);
						e[2][i].bom->laser.setPosition(-100 , e[2][i].bom->laser.getPosition().y);
						e[2][i].sprite.setPosition(-500 , -200);
						score+=10*level;
						temp5++;
						if (level == 2 && phase ==1)
							temp11++;
						if (level == 2 && phase ==2)
							temp12++;
						if (level == 2 && phase == 3)
							temp13++;
						if (level == 3 && phase == 1)
							temp14++;
						if (level == 3 && phase ==2)
							temp15++;
						if (level == 3 && phase == 3)
							temp16++;
					}
				}
				// this loop checks collision between enemy bomb and player ship
				for (int i = 0 ; i < 14 ; i ++)
				{
					if(e[0][i].bom->laser.getPosition().x >= p->sprite.getPosition().x &&e[0][i].bom->laser.getPosition().x <= p->sprite.getPosition().x+70 &&e[0][i].bom->laser.getPosition().y >= p->sprite.getPosition().y &&e[0][i].bom->laser.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						e[0][i].bom->laser.setPosition(-100 , e[0][i].bom->laser.getPosition().y);
						p->lives--;
					}
				}
				for (int i = 0 ; i < 13 ; i ++)
				{
					if(e[1][i].bom->laser.getPosition().x >= p->sprite.getPosition().x && e[1][i].bom->laser.getPosition().x <= p->sprite.getPosition().x+70 && e[1][i].bom->laser.getPosition().y >= p->sprite.getPosition().y && e[1][i].bom->laser.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						e[1][i].bom->laser.setPosition(-100 , e[1][i].bom->laser.getPosition().y);
						p->lives--;
					}
				}
				for (int i = 0 ; i < 13 ; i ++)
				{
					if(e[2][i].bom->laser.getPosition().x >= p->sprite.getPosition().x && e[2][i].bom->laser.getPosition().x <= p->sprite.getPosition().x+70 && e[2][i].bom->laser.getPosition().y >= p->sprite.getPosition().y && e[2][i].bom->laser.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						e[2][i].bom->laser.setPosition(-100 , e[2][i].bom->laser.getPosition().y);
						p->lives--;
					}
				}
				// this checks collision of player ship and enemy ship
				for (int i = 0 ; i < 14 ; i ++)
				{
					if(e[0][i].sprite.getPosition().x >= p->sprite.getPosition().x &&e[0][i].sprite.getPosition().x <= p->sprite.getPosition().x+70 &&e[0][i].sprite.getPosition().y >= p->sprite.getPosition().y &&e[0][i].sprite.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						p->lives--;

					}
				}
				for (int i = 0 ; i < 13 ; i ++)
				{
					if(e[1][i].sprite.getPosition().x >= p->sprite.getPosition().x && e[1][i].sprite.getPosition().x <= p->sprite.getPosition().x+70 &&e[1][i].sprite.getPosition().y >= p->sprite.getPosition().y &&e[1][i].sprite.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						p->lives--;
					}
				}
				for (int i = 0 ; i < 13 ; i ++)
				{
					if(e[2][i].sprite.getPosition().x >= p->sprite.getPosition().x && e[2][i].sprite.getPosition().x <= p->sprite.getPosition().x+70 &&e[2][i].sprite.getPosition().y >= p->sprite.getPosition().y &&e[2][i].sprite.getPosition().y <= p->sprite.getPosition().y+70)
					{
						p->sprite.setPosition(p->x,p->y);
						p->lives--;
					}
				}
				//this checks the collisions of the monster
				if(e[3]->laser.getPosition().x >= p->sprite.getPosition().x && e[3]->laser.getPosition().x  <= p->sprite.getPosition().x+70)
				{
					p->sprite.setPosition(p->x+350 , p->y);
					p->lives--;
				}
				if (p->sprite.getPosition().x + 50 >= e[3]->sprite.getPosition().x && p->sprite.getPosition().x <= e[3]->sprite.getPosition().x+380 && p->sprite.getPosition().y + 50 >= e[3]->sprite.getPosition().y && p->sprite.getPosition().y <= e[3]->sprite.getPosition().y+200)
				{
					p->sprite.setPosition(p->x , p->y);
					p->lives--;
				}
				//this checks the collision of the dragon
				if (p->sprite.getPosition().x + 50  >= e[4]->sprite.getPosition().x && p->sprite.getPosition().x <= e[4]->sprite.getPosition().x+300 && p->sprite.getPosition().y + 50 >= e[4]->sprite.getPosition().y && p->sprite.getPosition().y <= e[4]->sprite.getPosition().y+300)
				{
					p->sprite.setPosition(p->x , p->y);
					p->lives--;
				}

				if (temp3 == 14 && flag2 == false && level == 1)
				{
					phase++;
					flag2 = true;
				}
				if (temp4 == 13 && flag6 == false&&level == 1)
				{
					phase++;
					flag6 = true;
				}
				if (temp5 == 13 && flag9 == false && level == 1)
				{
					phase=1;
					level++;
					flag9 = true;
				}
				if (temp11 == 12 && level == 2 && phase == 1)
				{
					phase++;
					temp11 = 0;
				}
				if (temp12 == 13 && level == 2 && phase == 2)
				{
					phase++;
					temp12 = 0;
				}
				if (temp13 == 13 && level == 2 && phase == 3)
				{
					phase++;
					temp13 = 0;
				}
				if (temp14 == 18 && level == 3 && phase == 1)
				{
					phase++;
					temp14 = 0;
				}
				//	cout<<temp15<<endl;
				if (temp15 == 22 && level == 3 && phase == 2)
				{
					phase++;
					temp15 = 0;
				}
				if (temp16 == 21 && level == 3 && phase == 3)
				{
					phase++;
					temp16 = 0;
				}
				if (phase == 4)
				{
					phase =1;
					level++;
					temp11 = 0;
				}
				if (level == 4 && phase == 1)
				{
					wait1 = !wait1;
				}
				if (p->lives == 0)
				{
					wait1 = !wait1 ;
				}


				window.clear(Color::Black);//clears the screen
				window.draw(background);
				if (flag18 == false && flag19 == false)// setting background
					window.draw(p->sprite);
				if (flag18 == false && flag19 == true)
					window.draw(p->right_sprite);
				if (flag18 == true && flag19 == false)
					window.draw(p->left_sprite);// setting player on screen
				window.draw(p->tail);
				window.draw(p->b->fire_sprite);
				window.draw(p->b->aag);
				for (int i = 0 ; i < 13 ; i++)
					window.draw(e[2][i].bom->laser);
				for (int i = 0 ; i < 13 ; i++)
					window.draw(e[2][i].sprite);
				for (int i = 0 ; i < 13 ; i++)
					window.draw(e[1][i].bom->laser);
				for (int i = 0 ; i < 13 ; i++)
					window.draw(e[1][i].sprite);
				for (int i = 0 ; i < 14 ; i++)
					window.draw(e[0][i].bom->laser);
				for (int i = 0 ; i < 14 ; i++)
					window.draw(e[0][i].sprite);
				window.draw(e[3]->laser);
				window.draw(e[3]->sprite);
				window.draw(e[4]->sprite);
				window.draw(e[4]->laser);
				window.draw(ad[0]->sprite);
				window.draw(ad[1]->sprite);
				window.draw(ad[2]->sprite);
				window.draw(ad[3]->sprite);
				window.draw(text_score);
				window.draw(text_lives);
				window.draw(text_phase);
				window.draw(text_level);
				if (wait1 == false)
				{
					window.draw(text_game_over);
					window.draw(text_restart);
					window.draw(text_exit);

				}
				window.display();  //Displying all the sprites
			}
			Event ev;
			ofstream obj("Score.txt", fstream::app);
			while (window.pollEvent(ev))
			{
				if (ev.type == Event::Closed) // If cross/close is clicked/pressed
					window.close();
				if (ev.type == Event::KeyPressed)
				{
					if (ev.key.code == Keyboard::P)
					{
						wait = !wait;
					}
					if (ev.key.code == Keyboard::R)
					{
						window.close();
						Game gam;
						gam.start_game();
					}
					if (ev.key.code == Keyboard::Escape)
					{
						window.close();
					}
				}
			}
		}
		ofstream obj("Score.txt", fstream::app);
		obj<<score;
		obj<<" ";
		obj.close();

	}


};

