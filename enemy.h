#include <SFML/Graphics.hpp>
#pragma once
#include <time.h>
#include <iostream>
using namespace std;
#include<string.h>
using namespace sf;
class Bomb
{
public:
Sprite laser;
Texture laser_tex;
bool flag;
Bomb()
{
	flag = true;
	laser_tex.loadFromFile("img/enemy_laser.png");
	laser.setTexture(laser_tex);
	laser.setScale(0.75,0.75);
}
void move ()
{
	float delta_y = 0.5;
	laser.move (0 , delta_y);
}
};
class Enemy
{
public:
	Bomb* bom;
	Sprite sprite;
	Texture tex;
	Sprite laser;
	Texture laser_tex;
	Texture laser_tex_1;
	Texture laser_tex_2;
	Enemy()
	{
		bom=new Bomb;
		bom->laser.setPosition(-100,-100);
	}
	virtual void shoot(int count){}
	virtual void move(){}
	virtual ~Enemy(){}

};
class Monster : public Enemy
{
	bool flag;
public:
	Monster()
	{
		flag= false;
		laser_tex.loadFromFile("img/PNG/Lasers/laserRed02.png");
		laser.setTexture(laser_tex);
		laser.setPosition(-500,0);
		laser.setScale(3,20);
		laser.setColor(Color::Magenta);
		tex.loadFromFile("img/monster.png");
		sprite.setTexture(tex);
		sprite.setPosition(-500,0);
		sprite.setScale(0.25,0.25);
	}
	void move()
	{
		if (flag == false)
		{
			sprite.move(0.4,0);
			if (sprite.getPosition().x>=500)
				flag = true;
		}
		if (flag == true)
		{
			sprite.move(-0.4,0);
			if (sprite.getPosition().x<=-100)
				flag = false;
		}

	}
};
class Dragon : public Enemy
{
public:
	bool flag;
	Dragon()
	{
		flag= false;
		laser_tex.loadFromFile("dragFire.png");
		laser_tex_1.loadFromFile("dragFireLeft.png");
		laser_tex_2.loadFromFile("dragFireRight.png");
		laser.setPosition(-1000,-500);
		laser.setScale(0.5,0.5);
	//	laser.setColor(Color::White);
		tex.loadFromFile("img/dragon.png");
		sprite.setTexture(tex);
		sprite.setPosition(150,-500);
		sprite.setScale(2,2);
	}
	void move()
	{
		if (flag == false)
		{
			sprite.move(0,0.07);
			if (sprite.getPosition().y>=-100)
				flag = true;
		}
		if (flag == true)
		{
			sprite.move(0,-0.07);
			if (sprite.getPosition().y<=-150)
				flag = false;
		}

	}
};
class Invader : public Enemy
{
public:
	Invader()
	{
	}

	virtual void shoot(int count)
	{
		bom->move();
		if (bom->laser.getPosition().y > count*700)
		{
			bom->laser.setPosition(sprite.getPosition().x+20,sprite.getPosition().y+20);
			bom->flag = false;
		}
		else
			bom->flag = true;
	}
};


class Alpha : public Invader
{
public:
	Alpha()
	{
		tex.loadFromFile("img/enemy_1.png");
		sprite.setScale(0.5,0.5);
		sprite.setTexture(tex);
		sprite.setPosition(-500,-100);
	}





};

class Gamma : public Invader
{
public:
	Gamma()
	{
		tex.loadFromFile("img/enemy_3.png");
		sprite.setTexture(tex);
		sprite.setScale(0.45,0.45);
		sprite.setPosition(-500,-100);
	}

};

class Beta : public Invader
{
public:
	Beta()
	{
		tex.loadFromFile("img/enemy_2.png");
		sprite.setTexture(tex);
		sprite.setScale(0.5,0.5);
		sprite.setPosition(-500,-100);
	}



};
