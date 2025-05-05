/*
 * Addon.h
 *
 *  Created on: May 12, 2023
 *      Author: saif
 */
#include <SFML/Graphics.hpp>
#pragma once
#include <time.h>
#include <iostream>
using namespace std;
#include<string.h>
using namespace sf;
#ifndef ADDON_H_
#define ADDON_H_
class Addon
{
public:
	Sprite sprite;
	Texture Tex;
	float delta_y;
	Addon()
	{
		delta_y = 0.3;
	}
	virtual void move()
	{
		sprite.move(0,delta_y);
	}


};
class Power : public Addon
{
public:
	Power()
	{
		Tex.loadFromFile("img/PNG/Power-ups/powerupBlue_bolt.png");
		sprite.setTexture(Tex);
		sprite.setScale(1.6,1.6);
		sprite.setPosition(0 , -100);
	}



};
class Life : public Addon
{
public:
	Life()
	{
		Tex.loadFromFile("img/PNG/Power-ups/pill_blue.png");
		sprite.setTexture(Tex);
		sprite.setScale(1.6,1.6);
		sprite.setPosition(0 , -100);
	}


};
class Danger : public Addon
{
public:
	Danger()
	{
		Tex.loadFromFile("img/danger.png");
		sprite.setTexture(Tex);
		sprite.setScale(0.19 , 0.1);
		sprite.setPosition(0 , -200);
	}


};
class Fire : public Addon
{
public:
	Fire()
	{
		Tex.loadFromFile("img/PNG/Power-ups/bolt_bronze.png");
		sprite.setTexture(Tex);
		sprite.setScale(1.6,1.6);
		sprite.setPosition(0 , -100);
	}


};




#endif /* ADDON_H_ */
