#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include<string.h>
using namespace sf;
class Bullet{
public:
Texture fire_;
Texture aag_tex;
Sprite fire_sprite;
Sprite aag;
float speed = 1.4;
int x1,y1;
Bullet()
{
	aag_tex.loadFromFile("img/PNG/Lasers/laserRed06.png");
	fire_.loadFromFile("img/PNG/Lasers/laserBlue04.png");
	aag.setTexture(aag_tex);
	aag.setPosition(-1000,-1000);
	aag.setScale(9,18);
	fire_sprite.setTexture(fire_);
	x1=375;y1=580;
	fire_sprite.setPosition(x1,y1);
	fire_sprite.setScale(1,1);
}
void shooting ()
{
	float delta_y = 0;
	delta_y = -1;
	delta_y*=speed;
	fire_sprite.move(0,delta_y);
}
};
class Player{
public:
Texture tex;
Sprite sprite;
Sprite right_sprite;
Sprite left_sprite;
Sprite tail;
Texture left_tex;
Texture right_tex;
Texture tail_tex;
Bullet *b;

float speed=0.6;
int x,y;
int lives;
Player()
{
lives = 3;
tex.loadFromFile("img/player_ship.png");
right_tex.loadFromFile("img/right_player.png");
left_tex.loadFromFile("img/left_player.png");
right_sprite.setTexture(right_tex);
left_sprite.setTexture(left_tex);
sprite.setTexture(tex);
tail_tex.loadFromFile("img/PNG/Effects/fire04.png");
tail.setTexture(tail_tex);
tail.setScale(3,3);
b = new Bullet;
x=340;y=600;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
right_sprite.setScale(0.75,0.75);
left_sprite.setScale(0.75,0.75);
tail.setPosition(sprite.getPosition().x+20 , sprite.getPosition().y+70);
}
void fire()
{
	b->shooting();
	int temp_pos = sprite.getPosition().y-600;
	if (b->fire_sprite.getPosition().y < temp_pos)
	{
		b->fire_sprite.setPosition(sprite.getPosition().x+35,sprite.getPosition().y-20);		
	}
	
}
void move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l")
	delta_x = -1;//move the player left
else if(s=="r")
	delta_x = 1;//move the player right
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;

delta_x*=speed;
delta_y*=speed;
tail.setPosition(sprite.getPosition().x+20 , sprite.getPosition().y+70);
sprite.move(delta_x, delta_y);
if (sprite.getPosition().x >= 800)
sprite.setPosition(-50,sprite.getPosition().y);
if (sprite.getPosition().x <= -60)
sprite.setPosition(780,sprite.getPosition().y);
if (sprite.getPosition().y >= 600)
sprite.setPosition(sprite.getPosition().x,600);
if (sprite.getPosition().y <= 0)
sprite.setPosition(sprite.getPosition().x,0);

}

};
