
//============================================================================
// Name        : TAIMOOR ANWAR 1232.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================
#ifndef RushHour_CPP_
#define RushHour_CPP_
#include<windows.h>
#include<mmsystem.h>
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<iomanip>
#include<fstream>
#include"Header.h"
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 //structure to controll game//
	 // class 36 to 196              //
	//  326 542 GAME DISPLAY        //
   //   566 1226 NON PRINTABLE KEYS//
  //    1246 1911 PRINTABLE KEYS  //
 //     1996 main                //
//==============================//
// move 292//

controll c;// to controol game //

void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width - 1, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

// vehical axis //

int xI = 880, yI = 740;// non printable keys //// first player vehicall//
int xJ = 60, yJ = 60;// printable keys //// second or bot player vehicall //

int xC, yC; // controll canon of player first vehical//
int xR, yR; // controll canon of player second or bot  vehical//
//c.ds and c.df controll mirror image of vehicals//

void drawCar()
{
	// score of player 1 and spawn point of 2 player //
	if (c.score1 == 3 && c.spawn2 == 0)
	{
		c.spawn2 = 1;
		xJ = 60, yJ = 740;
	}
	else if (c.score1 == 6 && c.spawn2 == 1)
	{
		c.ds = 1;
		c.spawn2 = 2;
		xJ = 880, yJ = 740;
	}
	else if (c.score1 == 9 && c.spawn2 == 2)
	{
		c.ds = 1;
		c.spawn2 = 3;
		xJ = 880, yJ = 60;
	}
	else if (c.score1 == 10 && c.spawn2 == 3)
	{
		c.ds = 2;
		c.spawn2 = 4;
		xJ = 60, yJ = 60;
	}

	// score of player 2 and spawn point of 1 player //
	if (c.score2 == 3 && c.spawn1 == 0)
	{
		c.spawn1 = 1;
		xI = 60, yI = 60;
	}
	else if (c.score2 == 6 && c.spawn1 == 1)
	{
		c.df = 1;
		c.spawn1 = 2;
		xI = 880, yI = 60;
	}
	else if (c.score2 == 9 && c.spawn1 == 2)
	{
		c.df = 1;
		c.spawn1 = 3;
		xI = 880, yI = 740;
	}
	else if (c.score2 == 10 && c.spawn1 == 3)
	{
		c.df = 2;
		c.spawn1 = 4;
		xI = 60, yI = 740;
	}


	if (c.veh1 == 1)// car//
	{
		if (c.df == 1)
		{
			DrawRectangle(xI + 21, yI + 20, 20, 10, colors[BLACK]);
			DrawSquare(xI + 40, yI, 30, colors[BLUE]);
			DrawRectangle(xI, yI - 15, 70, 20, colors[BLUE]);
			DrawCircle(xI + 3, yI - 25, 10, colors[BLACK]);
			DrawCircle(xI + 63, yI - 25, 10, colors[BLACK]);
		}
		else if (c.df == 2)
		{
			DrawRectangle(xI + 27, yI + 20, 20, 10, colors[BLACK]);
			DrawSquare(xI, yI, 30, colors[BLUE]);
			DrawRectangle(xI, yI - 15, 70, 20, colors[BLUE]);
			DrawCircle(xI + 3, yI - 25, 10, colors[BLACK]);
			DrawCircle(xI + 63, yI - 25, 10, colors[BLACK]);
		}
	}
	else if (c.veh1 == 2)//tank//
	{
		if (c.df == 1)
		{
			DrawRectangle(xI + 30, yI + 33, 40, 10, colors[BLACK]);
			DrawRectangle(xI, yI + 15, 70, 20, colors[BLUE]);
			DrawRectangle(xI, yI, 70, 20, colors[BLUE]);
			DrawCircle(xI + 20, yI - 10, 20, colors[BLACK]);
			DrawCircle(xI + 50, yI - 10, 20, colors[BLACK]);

		}
		else if (c.df == 2)
		{
			DrawRectangle(xI, yI + 33, 40, 10, colors[BLACK]);
			DrawRectangle(xI, yI + 15, 70, 20, colors[BLUE]);
			DrawRectangle(xI, yI, 70, 20, colors[BLUE]);
			DrawCircle(xI + 20, yI - 10, 20, colors[BLACK]);
			DrawCircle(xI + 50, yI - 10, 20, colors[BLACK]);
		}
	}

	else if (c.veh1 == 3)//helicopter//
	{
		if (c.df == 1)
		{
			DrawRectangle(xI + 20, yI - 10, 5, 40, colors[BLUE]);
			DrawSquare(xI, yI - 30, 40, colors[BLUE]);
			DrawRectangle(xI, yI - 20, 70, 5, colors[BLUE]);
			DrawRectangle(xI + 50, yI, 20, 4, colors[BLACK]);
			DrawRectangle(xI + 60, yI - 20, 5, 20, colors[BLUE]);


			if (c.wing <= 5)
			{
				c.wing++;
				DrawRectangle(xI, yI + 25, 50, 5, colors[BLACK]);//parr-//
			}
			else if (c.wing <= 10)
			{
				c.wing++;
				DrawLine(xI, yI, xI + 40, yI + 50, 5, colors[BLACK]);//wing \//
			}

			else if (c.wing <= 15)
			{
				c.wing++;
				DrawRectangle(xI + 20, yI + 10, 5, 50, colors[BLACK]);//parr | //	
			}
			else if (c.wing <= 20)
			{
				if (c.wing == 20)
				{
					c.wing = 1;
				}
				else
				{
					DrawLine(xI, 50 + yI, 40 + xI, yI, 5, colors[BLACK]);
					c.wing++;
				}
			}
		}

		else if (c.df == 2)
		{
			//DrawRectangle(xI + 25, yI + 25, 50, 5, colors[BLACK]);
			DrawRectangle(xI + 50, yI - 10, 5, 40, colors[BLUE]);
			DrawSquare(xI + 30, yI - 30, 40, colors[BLUE]);
			DrawRectangle(xI, yI - 20, 70, 5, colors[BLUE]);
			DrawRectangle(xI - 1, yI, 20, 4, colors[BLACK]);
			DrawRectangle(xI + 5, yI - 20, 5, 20, colors[BLUE]);


			if (c.wing <= 5)
			{
				c.wing++;
				DrawRectangle(xI + 25, yI + 25, 50, 5, colors[BLACK]);//parr-//
			}
			else if (c.wing <= 10)
			{
				c.wing++;
				DrawLine(xI + 40, yI, xI + 60, yI + 50, 5, colors[BLACK]);//wing \//

			}

			else if (c.wing <= 15)
			{
				c.wing++;
				DrawRectangle(xI + 48, yI + 10, 5, 50, colors[BLACK]);//parr | //	
			}
			else if (c.wing <= 20)
			{

				if (c.wing == 20)
				{
					c.wing = 1;
				}
				else
				{
					DrawLine(xI + 42, yI + 50, xI + 60, yI, 5, colors[BLACK]);//wing \//
					c.wing++;
				}

			}

		}
	}

	if (c.veh2 == 1 || c.vehbot == 1)//car//
	{
		if (c.ds == 1)
		{
			DrawRectangle(xJ + 21, yJ + 20, 20, 10, colors[BLACK]);
			DrawSquare(xJ + 40, yJ, 30, colors[AQUA]);
			DrawRectangle(xJ, yJ - 15, 70, 20, colors[AQUA]);
			DrawCircle(xJ + 3, yJ - 25, 10, colors[BLACK]);
			DrawCircle(xJ + 63, yJ - 25, 10, colors[BLACK]);
		}
		else if (c.ds == 2)
		{
			DrawRectangle(xJ + 27, yJ + 20, 20, 10, colors[BLACK]);
			DrawSquare(xJ, yJ, 30, colors[AQUA]);
			DrawRectangle(xJ, yJ - 15, 70, 20, colors[AQUA]);
			DrawCircle(xJ + 3, yJ - 25, 10, colors[BLACK]);
			DrawCircle(xJ + 63, yJ - 25, 10, colors[BLACK]);
		}
	}

	else if (c.veh2 == 2 || c.vehbot == 2)//tank//
	{
		if (c.ds == 1)
		{
			DrawRectangle(xJ + 30, yJ + 33, 40, 10, colors[BLACK]);
			DrawRectangle(xJ, yJ + 15, 70, 20, colors[AQUA]);
			DrawRectangle(xJ, yJ, 70, 20, colors[AQUA]);
			DrawCircle(xJ + 20, yJ - 10, 20, colors[BLACK]);
			DrawCircle(xJ + 50, yJ - 10, 20, colors[BLACK]);
		}
		else if (c.ds == 2)
		{
			DrawRectangle(xJ, yJ + 33, 40, 10, colors[BLACK]);
			DrawRectangle(xJ, yJ + 15, 70, 20, colors[AQUA]);
			DrawRectangle(xJ, yJ, 70, 20, colors[AQUA]);
			DrawCircle(xJ + 20, yJ - 10, 20, colors[BLACK]);
			DrawCircle(xJ + 50, yJ - 10, 20, colors[BLACK]);
		}
	}
	else if (c.veh2 == 3 || c.vehbot == 3)//helicopter//
	{
		if (c.ds == 1)
		{
			//DrawRectangle(xJ, yJ + 25, 50, 5, colors[BLACK]);
			DrawRectangle(xJ + 20, yJ - 10, 5, 40, colors[AQUA]);
			DrawSquare(xJ, yJ - 30, 40, colors[AQUA]);
			DrawRectangle(xJ, yJ - 20, 70, 5, colors[AQUA]);
			DrawRectangle(xJ + 50, yJ, 20, 4, colors[BLACK]);
			DrawRectangle(xJ + 60, yJ - 20, 5, 20, colors[AQUA]);
			if (c.wing <= 5)
			{
				c.wing++;
				DrawRectangle(xJ, yJ + 25, 50, 5, colors[BLACK]);//parr-//
			}
			else if (c.wing <= 10)
			{
				c.wing++;
				DrawLine(xJ, yJ, xJ + 40, yJ + 50, 5, colors[BLACK]);//wing \//

			}

			else if (c.wing <= 15)
			{
				c.wing++;
				DrawRectangle(xJ + 20, yJ + 10, 5, 50, colors[BLACK]);//parr | //	
			}
			else if (c.wing <= 20)
			{

				if (c.wing == 20)
				{
					c.wing = 1;
				}
				else
				{
					DrawLine(xJ, 50 + yJ, 40 + xJ, yJ, 5, colors[BLACK]);
					c.wing++;
				}
			}
		}

		else if (c.ds == 2)
		{
			//DrawRectangle(xJ + 25, yJ + 25, 50, 5, colors[BLACK]);
			DrawRectangle(xJ + 50, yJ - 10, 5, 40, colors[AQUA]);
			DrawSquare(xJ + 30, yJ - 30, 40, colors[AQUA]);
			DrawRectangle(xJ, yJ - 20, 70, 5, colors[AQUA]);
			DrawRectangle(xJ - 1, yJ, 20, 4, colors[BLACK]);
			DrawRectangle(xJ + 5, yJ - 20, 5, 20, colors[AQUA]);


			if (c.wing <= 5)
			{
				c.wing++;
				DrawRectangle(xJ + 25, yJ + 25, 50, 5, colors[BLACK]);//parr-//
			}
			else if (c.wing <= 10)
			{
				c.wing++;
				DrawLine(xJ + 40, yJ, xJ + 60, yJ + 50, 5, colors[BLACK]);//wing \//

			}

			else if (c.wing <= 15)
			{
				c.wing++;
				DrawRectangle(xJ + 48, yJ + 10, 5, 50, colors[BLACK]);//parr | //	
			}
			else if (c.wing <= 20)
			{

				if (c.wing == 20)
				{
					c.wing = 1;
				}
				else
				{
					DrawLine(xJ + 42, yJ + 50, xJ + 60, yJ, 5, colors[BLACK]);//wing \//
					c.wing++;
				}

			}
		}
	}

	glutPostRedisplay();
}
//------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------// 
//======================================================canon======================================================//

void drawCanon1()// canon of first player//
{
	if (c.bc1 != 1)// draw small canon//
	{
		DrawCircle(xC, yC, 5, colors[BLACK]);
	}
	else if (c.bc1 == 1)// draw big canon//
	{
		DrawCircle(xC, yC, 15, colors[BROWN]);
	}

}
void drawCanon2()// canon of second player//
{
	if (c.bc2 != 1)// draw small canon//
	{
		DrawCircle(xR, yR, 5, colors[BLACK]);
	}
	else if (c.bc2 == 1)// draw big canon//
	{
		DrawCircle(xR, yR, 15, colors[BROWN]);
	}
}

bool flag = false;// controll left right movement of canon //

void movebot()
{

	if (yJ < yI && xJ <= xI)// bot is on left of my car and bot is below me //
	{
		cout << " bot go upward";
		if (c.lev == 2)//speed for level 2//
		{
			yJ += 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			yJ += 5;
		}
	}

	else  if (yJ == yI && xJ <= xI - 150)// bot is on left and bot is equall to my car on y axis   //
	{
		c.ds = 2;
		cout << " bot go right";
		if (c.lev == 2)//speed for level 2//
		{
			xJ += 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			xJ += 10;
		}

		if (xJ >= xI - 350 && xJ <= xI - 340)//shoot at certain distant
		{
			c.bc2 = 1;//big canon for second player//
			xR = 60 + xJ, yR = 25 + yJ;
			c.collision2 = 1;
			c.shoot2 = true;
			flag = false;
		}
	}

	else if (yJ > yI && xJ <= xI)// bot is on left of my car and bot is above me //
	{
		cout << " bot go downward";
		if (c.lev == 2)//speed for level 2//
		{
			yJ -= 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			yJ -= 5;
		}

	}
	else if (yJ < yI && xJ >= xI)// bot is on right of my car and bot is below me //
	{
		cout << " bot go upward";
		if (c.lev == 2)//speed for level 2//
		{
			yJ += 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			yJ += 5;
		}
	}

	else  if (yJ == yI && xJ >= xI + 150)// bot is equall to my car on y axis  and bot is on right  //
	{
		c.ds = 1;
		cout << " bot go left";

		if (c.lev == 2)//speed for level 2//
		{
			xJ -= 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			xJ -= 10;
		}

		if (xJ <= xI + 350 && xJ >= xI + 340)//shoot at certain distant
		{
			c.bc2 = 0;//small canon for second player//
			xR = 60 + xJ, yR = 25 + yJ;
			c.collision2 = 1;
			c.shoot2 = true;
			flag = true;
		}
	}
	else if (yJ > yI && xJ >= xI)// bot is on right of my car and bot is above me //
	{
		cout << " bot go downward";
		if (c.lev == 2)//speed for level 2//
		{
			yJ -= 10;
		}
		else if (c.lev == 3)//speed for level 3//
		{
			yJ -= 5;
		}
	}
}


void moveCanon() // canon move function //
{
	if (c.lev == 1)// cannon collision for level 1//firstplayer//
	{
		if (c.collision1 <= 3)
		{
			if (c.shoot1 == true)
			{
				if (xC > 10 && flag == true)// border dection //
				{
					xC -= 20;
					cout << "going left";
					// round rectangle //
					if (xC >= 360 && xC <= 370 && yC >= 180 && yC <= 230)
					{
						flag = false;
						c.collision1++;
					}
					//left ]  |  //
					else if (xC >= 220 && xC <= 230 && yC >= 350 && yC <= 640)
					{

						flag = false;
						c.collision1++;
					}
					// center plus //
					// plus |  //
					else if (xC >= 510 && xC <= 520 && yC >= 260 && yC <= 570)
					{
						flag = false;
						c.collision1++;
					}
					// center plus | mini left side  //
					else if (xC >= 650 && xC <= 660 && yC >= 400 && yC <= 420)
					{
						flag = false;
						c.collision1++;
					}
					// down square//
					else if (xC >= 660 && xC <= 670 && yC >= 130 && yC <= 170)
					{
						flag = false;
						c.collision1++;
					}
					// upward square//
					else if (xC >= 390 && xC <= 400 && yC >= 630 && yC <= 670)
					{
						flag = false;
						c.collision1++;
					}
					// right side obstacle [  lower | mini sides //
					else if (xC >= 870 && xC <= 880 && yC >= 150 && yC <= 160)
					{
						flag = false;
						c.collision1++;
					}

					// right side obstacle [  upper | mini sides //
					else if (xC >= 870 && xC <= 880 && yC >= 450 && yC <= 460)
					{
						flag = false;
						c.collision1++;
					}
					// right side obstacle [ //

					else if (xC >= 830 && xC <= 840 && yC >= 160 && yC <= 460)
					{
						flag = false;
						c.collision1++;
					}

					else if (xC < 70)// border dection //
					{
						flag = false;
						c.collision1++;
					}

					else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car <-side collosion detection //
					{
						c.collision1 = 3;
						c.score1++;
						flag = false;
					}
				}

				else if (xC > 10 && xC < 1010 && flag == false)// border dection //
				{

					cout << "go right";
					xC += 20;
					// round rectangle left//
					if (xC >= 190 && xC <= 200 && yC >= 180 && yC <= 230)
					{
						flag = true;
						c.collision1++;
					}
					//left blue ] //
			 // left ] - lower //
					else if (xC >= 140 && xC <= 160 && yC >= 350 && yC <= 360)
					{
						flag = true;
						c.collision1++;
					}
					//left blue ] //
		 // left ] - upper //
					else if (xC >= 140 && xC <= 160 && yC >= 630 && yC <= 640)
					{
						flag = true;
						c.collision1++;
					}
					// left ] | //
					else if (xC == 190 && yC >= 340 && yC < 640)
					{
						flag = true;
						c.collision1++;
					}
					//left blue ] end //
					// center plus //

			 // plus |  //

					else if (xC >= 480 && xC <= 490 && yC >= 260 && yC <= 570)
					{
						flag = true;
						c.collision1++;
					}
					// center plus | mini left side  //
					else if (xC >= 350 && xC <= 360 && yC >= 400 && yC <= 420)
					{
						flag = true;
						c.collision1++;
					}
					// right side obstacle [ //

					else if (xC >= 800 && xC <= 810 && yC >= 150 && yC <= 470)
					{
						flag = true;
						c.collision1++;
					}
					// right side obstacle [ end //

					// down square//
					else if (xC >= 590 && xC <= 630 && yC >= 130 && yC <= 170)
					{
						flag = true;
						c.collision1++;
					}
					// upward square//
					else if (xC >= 350 && xC <= 380 && yC >= 630 && yC <= 670)
					{
						flag = true;
						c.collision1++;
					}

					else if (xC > 930)// border dection //
					{
						flag = true;
						c.collision1++;
					}

					else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car -> side collosion detection //
					{
						c.collision1 = 3;
						c.score1++;
						flag = true;
					}
				}
			}

			else if (c.collision1 == 3)
			{
				c.shoot1 = false;
				flag = false;

			}
		}

		//============================================//
		if (c.collision2 <= 3)//player 2 canon detection//
		{
			if (c.shoot2 == true)
			{
				if (xR > 10 && flag == true)
				{
					xR -= 20;
					cout << "going left";
					// round rectangle //
					if (xR >= 360 && xR <= 370 && yR >= 180 && yR <= 230)
					{
						flag = false;
						c.collision2++;
					}
					//left ]  |  //
					else if (xR >= 220 && xR <= 230 && yR >= 350 && yR <= 640)
					{

						flag = false;
						c.collision2++;
					}
					// center plus //
					// plus |  //
					else if (xR >= 510 && xR <= 520 && yR >= 260 && yR <= 570)
					{
						flag = false;
						c.collision2++;
					}
					// center plus | mini left side  //
					else if (xR >= 650 && xR <= 660 && yR >= 400 && yR <= 420)
					{
						flag = false;
						c.collision2++;
					}
					// down square//
					else if (xR >= 660 && xR <= 670 && yR >= 130 && yR <= 170)
					{
						flag = false;
						c.collision2++;
					}
					// upward square//
					else if (xR >= 390 && xR <= 400 && yR >= 630 && yR <= 670)
					{
						flag = false;
						c.collision2++;
					}
					// right side obstacle [  lower | mini sides //
					else if (xR >= 870 && xR <= 880 && yR >= 150 && yR <= 160)
					{
						flag = false;
						c.collision2++;
					}

					// right side obstacle [  upper | mini sides //
					else if (xR >= 870 && xR <= 880 && yR >= 450 && yR <= 460)
					{
						flag = false;
						c.collision2++;
					}
					// right side obstacle [ //

					else if (xR >= 830 && xR <= 840 && yR >= 160 && yR <= 460)
					{
						flag = false;
						c.collision2++;
					}

					else if (xR < 70)// border detection//
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= xI && xR <= xI + 20 && yR >= yI - 30 && yR <= yI + 30) //car <-side collosion detection //
					{
						c.collision2 = 3;
						c.score2++;
						flag = false;
					}
				}

				else if (xR > 10 && xR < 1010 && flag == false)
				{
					cout << "go right";
					xR += 20;
					// round rectangle left//
					if (xR >= 190 && xR <= 200 && yR >= 180 && yR <= 230)
					{
						flag = true;
						c.collision2++;
					}
					//left blue ] //
			 // left ] - lower //
					else if (xR >= 140 && xR <= 160 && yR >= 350 && yR <= 360)
					{
						flag = true;
						c.collision2++;
					}
					//left blue ] //
		 // left ] - upper //
					else if (xR >= 140 && xR <= 160 && yR >= 630 && yR <= 640)
					{
						flag = true;
						c.collision2++;
					}
					// left ] | //
					else if (xR == 190 && yR >= 340 && yR < 640)
					{
						flag = true;
						c.collision2++;
					}
					//left blue ] end //
					// center plus //

			 // plus |  //

					else if (xR >= 480 && xR <= 490 && yR >= 260 && yR <= 570)
					{
						flag = true;
						c.collision2++;
					}
					// center plus | mini left side  //
					else if (xR >= 350 && xR <= 360 && yR >= 400 && yR <= 420)
					{
						flag = true;
						c.collision2++;
					}
					// right side obstacle [ //

					else if (xR >= 800 && xR <= 810 && yR >= 150 && yR <= 470)
					{
						flag = true;
						c.collision2++;
					}
					// right side obstacle [ end //

					// down square//
					else if (xR >= 590 && xR <= 630 && yR >= 130 && yR <= 170)
					{
						flag = true;
						c.collision2++;
					}
					// upward square//
					else if (xR >= 350 && xR <= 380 && yR >= 630 && yR <= 670)
					{
						flag = true;
						c.collision2++;
					}

					else if (xR > 930)// border dectection//
					{
						flag = true;
						c.collision2++;
					}

					else if (xR >= xI && xR <= xI + 10 && yR >= yI - 30 && yR <= yI + 30) //car -> side collosion detection //
					{
						c.score2++;
						flag = true;
						c.collision2 = 3;
					}
				}
			}
		}

		else if (c.collision2 == 3)
		{
			c.shoot2 = false;
			xR = 50 + xJ, yR = 50 + yJ;
			flag = false;
		}
	}

	else if (c.lev == 2)// cannon collision for level 2//
	{
		if (c.collision1 <= 3)
		{
			if (c.shoot1 == true)
			{
				if (xC > 10 && flag == true)
				{
					//left downsquare start//
					if (xC >= 300 && xC <= 310 && yC >= 200 && yC <= 300)
					{
						flag = false;
						c.collision1++;
					}
					//left downsquare end//
					//left uppersquare start//
					else if (xC >= 300 && xC <= 310 && yC >= 500 && yC <= 600)
					{
						flag = false;
						c.collision1++;
					}
					//left uppersquare end//

					//right downsquare start//
					else if (xC >= 800 && xC <= 810 && yC >= 200 && yC <= 300)
					{
						flag = false;
						c.collision1++;
					}
					//right downsquare end//
					//right uppersquare start//
					else if (xC >= 800 && xC <= 810 && yC >= 500 && yC <= 600)
					{
						flag = false;
						c.collision1++;
					}
					//right uppersquare end//

					//lower rectangle start //
					else if (xC >= 520 && xC <= 530 && yC >= 15 && yC <= 130)
					{
						flag = false;
						c.collision1++;
					}
					//lower rectangle end //

					//upper rectangle start //
					else if (xC >= 520 && xC <= 530 && yC >= 645 && yC <= 760)
					{
						flag = false;
						c.collision1++;
					}
					//upper rectangle end //

					else if (xC > 10 && flag == true)// border dection //
					{
						xC -= 20;
						cout << "going left";

						if (xC < 70)// border dection //
						{
							flag = false;
							c.collision1++;
						}

						else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car <-side collosion detection //
						{
							c.collision1 = 3;
							c.score1++;
							flag = false;

						}
					}
				}

				else if (xC > 10 && xC < 1010 && flag == false)// border dection //
				{

					cout << "go right";
					xC += 20;

					//left downsquare start//
					if (xC >= 190 && xC <= 200 && yC >= 200 && yC <= 300)
					{
						flag = true;
						c.collision1++;
					}
					//left downsquare end//
					//left uppersquare start//
					else if (xC >= 190 && xC <= 200 && yC >= 500 && yC <= 600)
					{
						flag = true;
						c.collision1++;
					}
					//left uppersquare end//

					//right downsquare start//
					else if (xC >= 690 && xC <= 700 && yC >= 200 && yC <= 300)
					{
						flag = true;
						c.collision1++;
					}
					//right downsquare end//
					//right uppersquare start//
					else if (xC >= 690 && xC <= 700 && yC >= 500 && yC <= 600)
					{
						flag = true;
						c.collision1++;
					}
					//right uppersquare end//

					//lower rectangle start //
					else if (xC >= 480 && xC <= 490 && yC >= 15 && yC <= 130)
					{
						flag = true;
						c.collision1++;
					}
					//lower rectangle end //
					//upper rectangle start //
					else if (xC >= 480 && xC <= 490 && yC >= 645 && yC <= 760)
					{
						flag = true;
						c.collision1++;
					}
					//upper rectangle end //
					else if (xC > 930)// border dection //
					{
						flag = true;
						c.collision1++;
					}

					else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car -> side collosion detection //
					{
						c.collision1 = 3;
						c.score1++;
						flag = true;
					}
				}
			}

			else if (c.collision1 == 3)
			{
				c.shoot1 = false;
				xC = 50 + xI, yC = 20 + yI;
				flag = false;
			}

		}

		//============================================//
		if (c.collision2 <= 3)
		{
			if (c.shoot2 == true)
			{
				if (xR > 10 && flag == true)
				{
					xR -= 20;
					cout << "going left";
					//left downsquare start//
					if (xR >= 300 && xR <= 310 && yR >= 200 && yR <= 300)
					{
						flag = false;
						c.collision2++;
					}
					//left downsquare end//
					//left uppersquare start//
					else if (xR >= 300 && xR <= 310 && yR >= 500 && yR <= 600)
					{
						flag = false;
						c.collision2++;
					}
					//left uppersquare end//

					//right downsquare start//
					else if (xR >= 800 && xR <= 810 && yR >= 200 && yR <= 300)
					{
						flag = false;
						c.collision2++;
					}
					//right downsquare end//
					//right uppersquare start//
					else if (xR >= 800 && xR <= 810 && yR >= 500 && yR <= 600)
					{
						flag = false;
						c.collision2++;
					}
					//right uppersquare end//

					//lower rectangle start //
					else if (xR >= 520 && xR <= 530 && yR >= 15 && yR <= 130)
					{
						flag = false;
						c.collision2++;
					}
					//lower rectangle end //

					//upper rectangle start //
					else if (xR >= 520 && xR <= 530 && yR >= 645 && yR <= 760)
					{
						flag = false;
						c.collision2++;
					}
					//upper rectangle end //

					else if (xR < 70)// border detection//
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= xI && xR <= xI + 20 && yR >= yI - 30 && yR <= yI + 30) //car <-side collosion detection //
					{
						c.collision2 = 3;
						c.score2++;
						flag = false;

					}

				}

				else if (xR > 10 && xR < 1010 && flag == false)
				{

					cout << "go right";
					xR += 20;

					//left downsquare start//
					if (xR >= 190 && xR <= 200 && yR >= 200 && yR <= 300)
					{
						flag = true;
						c.collision2++;
					}
					//left downsquare end//
					//left uppersquare start//
					else if (xR >= 190 && xR <= 200 && yR >= 500 && yR <= 600)
					{
						flag = true;
						c.collision2++;
					}
					//left uppersquare end//

					//right downsquare start//
					else if (xR >= 690 && xR <= 700 && yR >= 200 && yR <= 300)
					{
						flag = true;
						c.collision2++;
					}
					//right downsquare end//
					//right uppersquare start//
					else if (xR >= 690 && xR <= 700 && yR >= 500 && yR <= 600)
					{
						flag = true;
						c.collision2++;
					}
					//right uppersquare end//

					//lower rectangle start //
					else if (xR >= 480 && xR <= 490 && yR >= 15 && yR <= 130)
					{
						flag = true;
						c.collision2++;
					}
					//lower rectangle end //
					//upper rectangle start //
					else if (xR >= 480 && xR <= 490 && yR >= 645 && yR <= 760)
					{
						flag = true;
						c.collision2++;
					}
					//upper rectangle end //

					else if (xR > 930)// border dectection//
					{
						flag = true;
						c.collision2++;
					}

					else if (xR >= xI && xR <= xI + 10 && yR >= yI - 30 && yR <= yI + 30) //car -> side collosion detection //
					{
						c.score2++;
						flag = true;
						c.collision2 = 3;
					}
				}
			}
		}

		else if (c.collision2 == 3)
		{
			c.shoot2 = false;
			xR = 50 + xJ, yR = 50 + yJ;
			flag = false;
		}
	}

	else if (c.lev == 3)// cannon collision for level 3//
	{
		if (c.collision1 <= 3)
		{
			if (c.shoot1 == true)
			{
				if (xC > 10 && flag == true)// border dection //
				{
					xC -= 20;
					cout << "going left";

					if (xC >= 520 && xC <= 530 && yC >= 50 && yC <= 220)// center lower rectangle//
					{
						flag = false;
						c.collision1++;
					}
					else if (xC >= 520 && xC <= 530 && yC >= 570 && yC <= 770)// center upper rectangle//
					{
						flag = false;
						c.collision1++;
					}
					else if (xC >= 560 && xC <= 570 && yC >= 330 && yC <= 440)//center square //
					{
						flag = false;
						c.collision1++;
					}
					else if (xC >= 250 && xC <= 260 && yC >= 340 && yC <= 370)// left rectangle//
					{

						flag = false;
						c.collision1++;
					}

					if (xC < 70)// border dection //
					{
						flag = false;
						c.collision1++;
					}

					else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car <-side collosion detection //
					{
						c.collision1 = 3;
						c.score1++;
						flag = false;
					}
				}

				else if (xC > 10 && xC < 1010 && flag == false)// border dection //
				{
					cout << "go right";
					xC += 20;

					if (xC >= 480 && xC <= 490 && yC >= 50 && yC <= 220)// center lower rectangle//
					{
						flag = true;
						c.collision1++;
					}
					else if (xC >= 480 && xC <= 490 && yC >= 570 && yC <= 770)// center upper rectangle//
					{
						flag = true;
						c.collision1++;
					}
					else if (xC >= 450 && xC <= 480 && yC >= 330 && yC <= 440)//center square //
					{
						flag = true;
						c.collision1++;
					}
					else if (xC >= 750 && xC <= 760 && yC >= 330 && yC <= 380)// right rectangle//
					{

						flag = true;
						c.collision1++;
					}


					else if (xC > 930)// border dection //
					{
						flag = true;
						c.collision1++;
					}

					else if (xC >= xJ && xC <= xJ + 10 && yC >= yJ - 30 && yC <= yJ + 30) //car -> side collosion detection //
					{
						c.collision1 = 3;
						c.score1++;
						flag = true;
					}
				}
			}

			else if (c.collision1 == 3)
			{
				c.shoot1 = false;
				xC = 50 + xI, yC = 20 + yI;
				flag = false;
			}
		}
		//============================================//

		if (c.collision2 <= 3)
		{
			if (c.shoot2 == true)
			{
				if (xR > 10 && flag == true)
				{
					xR -= 20;
					cout << "going left";
					if (xR >= 520 && xR <= 530 && yR >= 50 && yR <= 220)// center lower rectangle//
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= 520 && xR <= 530 && yR >= 570 && yR <= 770)// center upper rectangle//
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= 560 && xR <= 570 && yR >= 330 && yR <= 440)//center square //
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= 250 && xR <= 260 && yR >= 340 && yR <= 370)// left rectangle//
					{

						flag = false;
						c.collision2++;
					}

					else if (xR < 70)// border detection//
					{
						flag = false;
						c.collision2++;
					}
					else if (xR >= xI && xR <= xI + 20 && yR >= yI - 30 && yR <= yI + 30) //car <-side collosion detection //
					{
						c.collision2 = 3;
						c.score2++;
						flag = false;
					}
				}

				else if (xR > 10 && xR < 1010 && flag == false)
				{
					cout << "go right";
					xR += 20;
					if (xR >= 480 && xR <= 490 && yR >= 50 && yR <= 220)// center lower rectangle//
					{
						flag = true;
						c.collision2++;
					}
					else if (xR >= 480 && xR <= 490 && yR >= 570 && yR <= 770)// center upper rectangle//
					{
						flag = true;
						c.collision2++;
					}
					else if (xR >= 450 && xR <= 480 && yR >= 330 && yR <= 440)//center square //
					{
						flag = true;
						c.collision2++;
					}
					else if (xR >= 750 && xR <= 760 && yR >= 330 && yR <= 380)// right rectangle//
					{

						flag = true;
						c.collision2++;
					}
					else if (xR > 930)// border dectection//
					{
						flag = true;
						c.collision2++;
					}

					else if (xR >= xI && xR <= xI + 10 && yR >= yI - 30 && yR <= yI + 30) //car -> side collosion detection //
					{
						c.score2++;
						flag = true;
						c.collision2 = 3;
					}
				}
			}

		}

		else if (c.collision2 == 3)
		{
			c.shoot2 = false;
			xR = 50 + xJ, yR = 50 + yJ;
			flag = false;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------//

//========================================================================================================================= =//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//

//MAP 1//
/*
 * Main Canvas drawing function.
 * */

void  level1::GameDisplay1()// level 1 function //
{
	// set the background color using function glClearColor.
   // to change the background play with the red, green and blue values below.
  // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//===========================================================================================//

	//DISPLAY SCORE START //
	DrawString(400, 800, "ATARI GAME ", colors[BLACK]);
	string s1 = to_string(c.score1);// score of first player//
	string s2 = to_string(c.score2);// score of second player //
	string s = "score =";

	DrawString(50, 800, s + s2, colors[BLACK]);/// FOR PLAYER 1
	DrawString(150, 800, c.play1, colors[RED]);

	DrawString(800, 800, s + s1, colors[BLACK]);//FOR PLAYER 2
	DrawString(900, 800, c.play2, colors[RED]);
	//DISPLAY SCORE END//

	 //BOUNDARYY START//
	 //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	// LEFT SE DIST,LEFT HIGHT UPWARD,LENGTH,RIGHT SE HIGHT ,WIDTH//
	DrawLine(50, 10, 970, 10, 10, colors[RED]);
	DrawLine(50, 780, 970, 780, 10, colors[RED]);
	DrawLine(54, 10, 54, 785, 10, colors[RED]);
	DrawLine(967, 10, 967, 785, 10, colors[RED]);
	//BOUNDARYY END//
   //backgroud//
	DrawRectangle(57, 17, 906, 757, colors[GOLD]);
	//background//
   //HURDEL LEFT START//
  //LEFT DIST,HIGHT UPWARD,WIDTH,HIEGHT//
	DrawRectangle(150, 630, 70, 20, colors[BLUE]);
	DrawRectangle(200, 370, 20, 270, colors[BLUE]);
	DrawRectangle(150, 351, 70, 20, colors[BLUE]);
	// HURDEL LEFT END//

	 //HURDEL RIGHT START//
	//LEFT DIST,HIGHT UPWARD,WIDTH,HIEGHT//

	DrawRectangle(800, 450, 70, 20, colors[BLUE]);
	DrawRectangle(800, 170, 20, 300, colors[BLUE]);
	DrawRectangle(800, 151, 70, 20, colors[BLUE]);
	// HURDEL RIGHT END//

	 //plus center start//
	//horizontal//
	DrawRectangle(350, 400, 300, 25, colors[GREEN]);
	//vertical//
	DrawRectangle(488, 265, 20, 300, colors[GREEN]);
	//plus center end//

	//YELLOW Square LEFT UPWARD//

	//SQUARE START//
	// left dist,hight upward,color//
	DrawSquare(350, 630, 50, colors[BROWN]);
	//YELLOW Square RIGHT DOWNWARD //
	DrawSquare(600, 130, 50, colors[BROWN]);
	//SQUARE END //

	 //ROUND RECTANGLE LEFT DOWNWARD START//
	DrawRoundRect(200, 180, 170, 50, colors[LIGHT_CORAL], 30);
	//ROUND RECTANGLE LEFT DOWNWARD  START//

	//===========================================================================================//

	drawCanon1();
	drawCanon2();
	drawCar();

	glutSwapBuffers(); // do not modify this line..

}

//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//

//MAP 2//
void  level2::GameDisplay2()//level 2 function //
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 1,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//===========================================================================================//

//DISPLAY SCORE START //
	DrawString(400, 800, "ATARI GAME ", colors[BLACK]);
	string s1 = to_string(c.score1);// score of first player//
	string s2 = to_string(c.score2);// score of second player //
	string s = "score =";

	DrawString(50, 800, s + s2, colors[BLACK]);/// FOR PLAYER 1
	DrawString(150, 800, c.play1, colors[RED]);

	DrawString(800, 800, s + s1, colors[BLACK]);//FOR PLAYER 2
	DrawString(900, 800, c.play2, colors[RED]);
	//DISPLAY SCORE END//

	//BOUNDARYY START//
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	// LEFT SE DIST,LEFT HIGHT UPWARD,LENGTH,RIGHT SE HIGHT ,WIDTH//
	DrawLine(50, 10, 970, 10, 10, colors[RED]);//upper and lower//
	DrawLine(50, 780, 970, 780, 10, colors[RED]);
	//boudry start//
	DrawLine(54, 10, 54, 300, 10, colors[RED]);// left//
	DrawLine(54, 500, 54, 780, 10, colors[RED]);// left //

	DrawLine(967, 10, 967, 300, 10, colors[RED]);//right//
	DrawLine(967, 500, 967, 785, 10, colors[RED]);//right//
	//BOUNDARYY END//

	//backgroud//
	DrawRectangle(57, 17, 906, 400, colors[CORAL]);
	DrawRectangle(57, 415, 906, 360, colors[GREEN]);
	//background//
	//LOWER LEFT SQUARE//
	DrawSquare(200, 200, 100, colors[RED]);
	//LOWER LEFT SQUARE END//
	// LOWER RIGHT SQUARE//
	DrawSquare(700, 200, 100, colors[RED]);
	// LOWER RIGHT SQUARE END//
	//LEFT SQUARE//
	DrawSquare(200, 500, 100, colors[RED]);
	//LEFT SQUARE END//
	//RIGHT SQUARE//
	DrawSquare(700, 500, 100, colors[RED]);
	//RIGHT SQUARE END//
	DrawRectangle(495, 656, 30, 120, colors[RED]);
	DrawRectangle(495, 15, 30, 120, colors[RED]);
	//DrawSquare(600, 130, 50, colors[BROWN]);
	//SQUARE END //
	//===========================================================================================//

	drawCanon1();
	drawCanon2();
	drawCar();

	glutSwapBuffers(); // do not modify this line..
}

//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//MAP 3//

void  level3::GameDisplay3()//level 3 map//
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//===========================================================================================//

	//DISPLAY SCORE START //
	DrawString(400, 800, "ATARI GAME ", colors[BLACK]);
	string s1 = to_string(c.score1);// score of first player//
	string s2 = to_string(c.score2);// score of second player //
	string s = "score =";

	DrawString(50, 800, s + s2, colors[BLACK]);/// FOR PLAYER 1
	DrawString(150, 800, c.play1, colors[RED]);

	DrawString(800, 800, s + s1, colors[BLACK]);//FOR PLAYER 2
	DrawString(900, 800, c.play2, colors[RED]);
	//DISPLAY SCORE END//

	//BOUNDARYY START//
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	// LEFT SE DIST,LEFT HIGHT UPWARD,LENGTH,RIGHT SE HIGHT ,WIDTH//
	DrawLine(50, 10, 970, 10, 10, colors[RED]);
	DrawLine(50, 780, 970, 780, 10, colors[RED]);
	DrawLine(54, 10, 54, 785, 10, colors[RED]);
	DrawLine(967, 10, 967, 785, 10, colors[RED]);
	//BOUNDARYY END//

	//backgroud//
	DrawRectangle(57, 17, 453, 756, colors[SALMON]);
	DrawRectangle(509, 17, 455, 756, colors[GREEN]);
	//background//

	// rectangle start upper and lower//
	DrawRectangle(495, 575, 30, 200, colors[BROWN]);
	DrawRectangle(495, 15, 30, 200, colors[BROWN]);
	// rectangle end//	

   // rectangle start left and right//
	DrawRectangle(57, 340, 200, 30, colors[BROWN]);
	DrawRectangle(765, 340, 200, 30, colors[BROWN]);
	// rectangle end//	

	// center square start //
	DrawSquare(457, 335, 100, colors[BROWN]);
	//center square end//

	//===========================================================================================//

	drawCanon1();
	drawCanon2();
	drawCar();

	glutSwapBuffers(); // do not modify this line..
}




//========================================================================================================================= =//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==============================================NONPRINTABLEKEYS============================================================//

void  level1::NonPrintableKeys1(int key, int x, int y)//level 1 controll for player 1//
{
	if (key
		== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		// left border //
		c.df = 1;//mirror image//

		if (xI <= 60 && yI >= 50)
		{

		}
		// round rect angele left//
		else if (xI == 370 && yI >= 160 && yI <= 250)
		{

		}
		//left ]  |  //
		else if (xI == 220 && yI >= 340 && yI < 680)
		{

		}
		// plus |  //
		else if (xI == 510 && yI >= 250 && yI < 600)
		{

		}
		// center plus | mini right side  //
		else if (xI == 650 && yI >= 380 && yI <= 450)
		{

		}

		// right side obstacle [ //

		else if (xI == 820 && yI >= 160 && yI <= 460)
		{

		}
		// right side obstacle [  | mini sides //
		else if (xI == 870 && yI >= 130 && yI <= 200)
		{

		}
		// right side obstacle [  | mini sides //
		else if (xI == 870 && yI >= 430 && yI <= 490)
		{

		}
		// down square//
		else if (xI == 650 && yI >= 110 && yI <= 200)
		{

		}
		// upward square//
		else if (xI == 400 && yI >= 610 && yI <= 700)
		{

		}
		else if (xI == xJ + 70 && yI >= yJ - 40 && yI <= yJ + 50) //car left side collosion detection //
		{

		}
		else
			xI -= 10;
	}

	else if (key
		== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		// right border //
		c.df = 2;//mirror image//
		if (xI >= 890 && yI >= 50)
		{

		}
		// round rectangle left//
		else if (xI == 130 && yI >= 160 && yI <= 250)
		{

		}
		//left blue ] //
		// left ] - lower //
		else if (xI == 80 && yI >= 340 && yI <= 400)
		{

		}
		// left - upper //
		else if (xI == 80 && yI >= 630 && yI <= 670)
		{

		}
		// left ] | //
		else if (xI == 130 && yI >= 340 && yI < 680)
		{

		}
		//left blue ] end //

		// center plus //

		// plus |  //

		else if (xI == 420 && yI >= 250 && yI < 600)
		{

		}
		// center plus | mini left side  //
		else if (xI == 280 && yI >= 380 && yI <= 450)
		{

		}
		// center plus end//
		// right side obstacle [ //

		else if (xI == 730 && yI >= 130 && yI <= 490)
		{

		}
		// right side obstacle [ end //

		// down square//
		else if (xI == 530 && yI >= 110 && yI <= 200)
		{

		}
		// upward square//
		else if (xI == 280 && yI >= 610 && yI <= 700)
		{

		}
		// upward square//
		else if (xI == xJ - 70 && yI >= yJ - 40 && yI <= yJ + 60) //car -> side collosion detection //
		{

		}
		else
			xI += 10;
	}

	else if (key
		== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		// upper border //
		if (yI >= 740 && xI >= 60)
		{

		}
		// round rectangle left//
		else if (yI == 150 && xI >= 140 && xI <= 360)
		{

		}
		// left ] - //
		else if (xI >= 90 && xI <= 210 && yI >= 320 && yI <= 340)
		{

		}
		// left ] - //
		else if (xI >= 90 && xI <= 210 && yI >= 600 && yI <= 620)
		{

		}
		// center plus //
		// plus - UPWARD//
		else if (xI > 280 && xI < 650 && yI == 370)
		{

		}
		// plus - downward //
		else if (xI >= 420 && xI <= 500 && yI == 230)
		{

		}
		// center plus end //

		//right [ - downside //
		else if (xI >= 740 && xI <= 860 && yI == 120)
		{

		}
		else if (xI >= 740 && xI <= 860 && yI == 420)
		{

		}
		// down square//
		else if (xI >= 540 && xI <= 640 && yI == 100)
		{

		}
		// upward square //
		else if (xI >= 290 && xI <= 390 && yI == 600)
		{

		}

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 50) //car upper side collosion detection //
		{

		}
		else

			yI += 10;
	}

	else if (key
		== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		// lower border //
		if (yI <= 50 && xI >= 60)
		{

		}
		// round rectangle left//
		else if (yI == 260 && xI >= 140 && xI <= 360)
		{

		}
		// left ] - // 
		else if (xI >= 90 && xI <= 140 && yI <= 400 && yI >= 380)
		{

		}
		// left ] - //
		else if (xI >= 90 && xI <= 210 && yI <= 680 && yI >= 670)
		{

		}
		// center plus //
		// plus - DOWNWARD//
		else if (xI > 280 && xI < 650 && yI == 450)
		{

		}
		// plus - upward //
		else if (xI >= 420 && xI <= 500 && yI == 590)
		{

		}
		// center plus end //

		//right side [ //
		//right side [ - downward  //

		else if (xI >= 740 && xI <= 860 && yI == 200)
		{

		}
		else if (xI >= 740 && xI <= 860 && yI == 500)
		{

		}
		//right side [ end //
		// doen square //
		else if (xI >= 540 && xI <= 640 && yI == 210)
		{

		}
		// upward square //
		else if (xI >= 290 && xI <= 390 && yI == 710)
		{

		}
		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ + 70) //car DOWN side collosion detection //
		{

		}

		else

			yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

void  level2::NonPrintableKeys2(int key, int x, int y)//level 2 controll for player 1//
{
	//boudry start//
	//DrawLine(54, 10, 54, 300, 10, colors[RED]);// left//
	//DrawLine(54, 500, 54, 780, 10, colors[RED]);// left //

	//DrawLine(967, 10, 967, 300, 10, colors[RED]);//right//
	//DrawLine(967, 500, 967, 785, 10, colors[RED]);//right//
	//BOUNDARYY END//
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{

		c.df = 1;//mirror image//

		//left border lower//
		if (xI <= 60 && yI >= 60 && yI <= 330)
		{

		}
		//left border upper//
		else if (xI >= 60 && xI <= 60 && yI >= 480 && yI <= 785)
		{

		}
		else if (xI <= -60 && yI >= 330 && yI <= 480)//blank//
		{
			int x = yI;
			xI = 980, yI = x;
		}

		//left downsquare start//
		else if (xI == 300 && yI >= 180 && yI <= 320)
		{

		}
		//left downsquare end//

		//left uppersquare start//
		else if (xI == 300 && yI >= 480 && yI <= 620)
		{

		}
		//left uppersquare end//

		//right downsquare start//
		else if (xI == 800 && yI >= 180 && yI <= 320)
		{

		}
		//right downsquare end//

		//right uppersquare start//
		else if (xI == 800 && yI >= 480 && yI <= 620)
		{

		}
		//right uppersquare end//

		//lower rectangle start //
		else if (xI == 530 && yI >= 15 && yI <= 150)
		{

		}
		//lower rectangle end //


		//upper rectangle start //
		else if (xI == 530 && yI >= 640 && yI <= 750)
		{

		}
		//upper rectangle end //
		else if (xI == xJ + 70 && yI >= yJ - 40 && yI <= yJ + 50) //car <- collosion detection //
		{

		}

		else
		{
			xI -= 10;

		}
	}

	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		c.df = 2;//mirror image//
		//left border lower//
		if (xI >= 900 && yI >= 60 && yI <= 330)
		{

		}
		//left border upper//
		else if (xI >= 900 && yI >= 480 && yI <= 785)
		{

		}
		else if (xI >= 1000 && yI >= 330 && yI <= 480)//blank//
		{
			int x = yI;
			xI = 30, yI = x;
		}

		//left downsquare start//
		else if (xI == 130 && yI >= 180 && yI <= 320)
		{

		}
		//left downsquare end//

		//left uppersquare start//
		else if (xI == 130 && yI >= 480 && yI <= 620)
		{

		}
		//left uppersquare end//

		//right downsquare start//
		else if (xI == 630 && yI >= 180 && yI <= 320)
		{

		}
		//right downsquare end//

		//right uppersquare start//
		else if (xI == 630 && yI >= 480 && yI <= 620)
		{

		}
		//right uppersquare end//

		//lower rectangle start //
		else if (xI == 420 && yI >= 15 && yI <= 150)
		{

		}
		//lower rectangle end //

		//upper rectangle start //
		else if (xI == 420 && yI >= 630 && yI <= 750)
		{

		}
		//upper rectangle end //

		else if (xI == xJ - 70 && yI >= yJ - 40 && yI <= yJ + 60) //car -> side collosion detection //
		{

		}

		else
			xI += 10;
	}

	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		// upper border //
		if (yI >= 740 && xI >= 60)
		{

		}

		//upper motion toward of border //
		else if (yI >= 470 && xI <= 50)
		{

		}
		//upper motion of right border//
		else if (yI >= 470 && xI >= 900)
		{

		}

		//lower left square start //
		else if (xI >= 140 && xI <= 290 && yI == 170)
		{

		}
		// lower left square end//
		//upper left square start //
		else if (xI >= 140 && xI <= 290 && yI == 470)
		{

		}
		// upper left square end//
		//lower right square start //
		else if (xI >= 640 && xI <= 790 && yI == 170)
		{

		}
		// lower right square end//
			//upper right square start //
		else if (xI >= 640 && xI <= 790 && yI == 470)
		{

		}

		// upper right square end//

		//upper rectangle start //
		else if (xI >= 430 && xI <= 520 && yI == 630)
		{

		}
		//upper rectangle end //

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 50) //car upper side collosion detection //
		{

		}


		else
		{

			yI += 10;
		}
	}
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		// lower border //
		if (yI <= 50 && xI >= 60)
		{

		}

		//lower motion  of  left border //
		else if (yI <= 330 && xI <= 50)
		{

		}
		//lower motion of right border//
		else if (yI <= 330 && xI >= 900)
		{

		}

		//left downsquare start//
			//lower left square start //
		else if (xI >= 140 && xI <= 290 && yI == 330)
		{

		}
		// lower left square end//
		//upper left square start //
		else if (xI >= 140 && xI <= 290 && yI == 630)
		{

		}
		// upper left square end//
		//lower right square start //
		else if (xI >= 640 && xI <= 790 && yI == 330)
		{

		}
		// lower right square end//
			//upper right square start //
		else if (xI >= 640 && xI <= 790 && yI == 630)
		{

		}
		// upper right square end//
		//LOWER rectangle start //
		else if (xI >= 430 && xI <= 520 && yI == 150)
		{

		}
		//LOWER rectangle end //

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ + 70) //car DOWN side collosion detection //
		{

		}

		else
		{
			yI -= 10;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

void  level3::NonPrintableKeys3(int key, int x, int y)//level 3 controll for player 1//
{
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		c.df = 1;//mirror image//

		// what to do when left key is pressed...
		// left border //
		if (xI <= 60 && yI >= 50)
		{

		}
		else if (xI == 530 && yI >= 50 && yI <= 230)// center lower rectangle//
		{

		}
		else if (xI == 530 && yI >= 560 && yI <= 740)// center upper rectangle//
		{

		}

		else if (xI == 560 && yI >= 310 && yI <= 450)// center square//
		{

		}

		else if (xI == 260 && yI >= 320 && yI <= 390)// left rectangle//
		{

		}
		else if (xI == xJ + 70 && yI >= yJ - 40 && yI <= yJ + 50) //car left side collosion detection //
		{

		}

		else
			xI -= 10;
	}


	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		c.df = 2;//mirror image//
		// right border //
		if (xI >= 890 && yI >= 50)
		{

		}

		else if (xI == 430 && yI >= 50 && yI <= 230)// center lower rectangle//
		{

		}

		else if (xI == 430 && yI >= 560 && yI <= 740)// center upper rectangle//
		{

		}

		else if (xI == 390 && yI >= 310 && yI <= 450)//center square //
		{

		}

		else if (xI == 700 && yI >= 320 && yI <= 390)// right rectangle//
		{

		}

		else if (xI == xJ - 70 && yI >= yJ - 40 && yI <= yJ + 60) //car -> side collosion detection //
		{

		}


		else
			xI += 10;
	}

	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		// upper border //
		if (yI >= 740 && xI >= 60)
		{

		}

		else if (xI >= 60 && xI <= 250 && yI == 310)// left  rectangle//
		{

		}
		else if (xI >= 710 && xI <= 890 && yI == 310)// right  rectangle//
		{

		}
		else if (xI >= 400 && xI <= 550 && yI == 300)// center square //
		{

		}
		else if (xI >= 430 && xI <= 520 && yI == 550)// upper rectangle //
		{

		}

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 50) //car upper side collosion detection //
		{

		}

		else
			yI += 10;

	}
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		// upper border //
		if (yI <= 50 && xI >= 60)
		{

		}
		else if (xI >= 60 && xI <= 250 && yI == 400)// left  rectangle//
		{

		}
		else if (xI >= 710 && xI <= 890 && yI == 400)// right  rectangle//
		{

		}
		else if (xI >= 400 && xI <= 550 && yI == 460)// center square //
		{

		}
		else if (xI >= 430 && xI <= 520 && yI == 250)// lower rectangle //
		{

		}

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ + 70) //car DOWN side collosion detection //
		{

		}

		else
			yI -= 10;

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==========================================================================================================================//
 //==============================================PRINTABLEKEYS===============================================================//


void  level1::PrintableKeys1(unsigned char key, int x, int y)//level 1 controll for player 2//
{


	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}



	if (key == 'a' || key == 'A') //to move left///
	{
		c.ds = 1;//mirror image//
		if (xJ <= 60 && yJ >= 50)
		{

		}
		// round rect angele left//
		else if (xJ == 370 && yJ >= 160 && yJ <= 250)
		{

		}
		//left ]  |  //
		else if (xJ == 220 && yJ >= 340 && yJ < 680)
		{

		}
		// plus |  //
		else if (xJ == 510 && yJ >= 250 && yJ < 600)
		{

		}
		// center plus | mini right side  //
		else if (xJ == 650 && yJ >= 380 && yJ <= 450)
		{

		}

		// right side obstacle [ //

		else if (xJ == 820 && yJ >= 160 && yJ <= 460)
		{

		}
		// right side obstacle [  | mini sides //
		else if (xJ == 870 && yJ >= 130 && yJ <= 200)
		{

		}
		// right side obstacle [  | mini sides //
		else if (xJ == 870 && yJ >= 430 && yJ <= 490)
		{

		}
		// down square//
		else if (xJ == 650 && yJ >= 110 && yJ <= 200)
		{

		}
		// upward square//
		else if (xJ == 400 && yJ >= 610 && yJ <= 700)
		{

		}
		else if (xJ == xI + 70 && yJ >= yI - 60 && yJ <= yI + 50) //car left side collosion detection //
		{

		}

		else
			xJ -= 10;
	}

	else if (key == 'd' || key == 'D')// to move right // 
	{
		c.ds = 2;//mirror image//

		if (xJ >= 890 && yJ >= 50)
		{

		}
		// round rectangle left//
		else if (xJ == 130 && yJ >= 160 && yJ <= 250)
		{

		}
		//left blue ] //
		// left ] - lower //
		else if (xJ == 80 && yJ >= 340 && yJ <= 400)
		{

		}
		// left - upper //
		else if (xJ == 80 && yJ >= 630 && yJ <= 670)
		{

		}
		// left ] | //
		else if (xJ == 130 && yJ >= 340 && yJ < 680)
		{

		}
		//left blue ] end //

		// center plus //

		// plus |  //

		else if (xJ == 420 && yJ >= 250 && yJ < 600)
		{

		}
		// center plus | mini left side  //
		else if (xJ == 280 && yJ >= 380 && yJ <= 450)
		{

		}
		// center plus end//
		// right side obstacle [ //

		else if (xJ == 730 && yJ >= 130 && yJ <= 490)
		{

		}
		// right side obstacle [ end //

		// down square//
		else if (xJ == 530 && yJ >= 110 && yJ <= 200)
		{

		}
		// upward square//
		else if (xJ == 280 && yJ >= 610 && yJ <= 700)
		{

		}
		// upward square//

		else if (xJ == xI - 70 && yJ >= yI - 60 && yJ <= yI + 50) //car -> side collosion detection //
		{

		}

		else
			xJ += 10;
	}
	else if (key == 'w' || key == 'W')// move upward//
	{
		// upper border //
		if (yJ >= 730 && xJ >= 60)
		{

		}
		// round rectangle left//
		else if (yJ == 140 && xJ >= 140 && xJ <= 360)
		{

		}
		// left ] - //
		else if (xJ >= 90 && xJ <= 210 && yJ >= 310 && yJ <= 320)
		{

		}
		// left ] - //
		else if (xJ >= 90 && xJ <= 210 && yJ >= 590 && yJ <= 600)
		{

		}
		// center plus //
		// plus - UPWARD//
		else if (xJ > 280 && xJ < 650 && yJ == 360)
		{

		}
		// plus - downward //
		else if (xJ >= 420 && xJ <= 500 && yJ == 220)
		{

		}
		// center plus end //

		//right [ - downside //
		else if (xJ >= 740 && xJ <= 860 && yJ == 110)
		{

		}
		else if (xJ >= 740 && xJ <= 860 && yJ == 410)
		{

		}
		// down square//
		else if (xJ >= 540 && xJ <= 640 && yJ == 90)
		{

		}
		// upward square //
		else if (xJ >= 290 && xJ <= 390 && yJ == 590)
		{

		}
		else if (xJ >= xI - 60 && xJ <= xI + 60 && yJ == yI - 70) //car upper side collosion detection //
		{

		}


		else
			yJ += 10;
	}

	else if (key == 's' || key == 'S') // TO MOVE DOWN //
	{
		if (yJ <= 50 && xJ >= 60)
		{

		}
		// round rectangle left//
		else if (yJ == 260 && xJ >= 140 && xJ <= 360)
		{

		}
		// left ] - // 
		else if (xJ >= 90 && xJ <= 140 && yJ <= 400 && yJ >= 380)
		{

		}
		// left ] - //
		else if (xJ >= 90 && xJ <= 210 && yJ <= 680 && yJ >= 670)
		{

		}
		// center plus //
		// plus - DOWNWARD//
		else if (xJ > 280 && xJ < 650 && yJ == 450)
		{

		}
		// plus - upward //
		else if (xJ >= 420 && xJ <= 500 && yJ == 590)
		{

		}
		// center plus end //

		//right side [ //
		//right side [ - downward  //

		else if (xJ >= 740 && xJ <= 860 && yJ == 200)
		{

		}
		else if (xJ >= 740 && xJ <= 860 && yJ == 500)
		{

		}
		//right side [ end //
		// doen square //
		else if (xJ >= 540 && xJ <= 640 && yJ == 210)
		{

		}
		// upward square //
		else if (xJ >= 290 && xJ <= 390 && yJ == 710)
		{


		}

		else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 60) //car down side collosion detection //
		{

		}

		else
			yJ -= 10;
	}

	else if (key == 'q' || key == 'e' || key == 'o' || key == 'p') //Key for shooting canon //
	{

		if (key == 'e')//shoot right for player 2//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc2 = 1;//big canon for second player//
			xR = 60 + xJ, yR = 25 + yJ;
			c.collision2 = 1;
			c.shoot2 = true;
			flag = false;
		}
		else if (key == 'q')//shoot left for player 2//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc2 = 0;//small canon for second player//
			xR = 60 + xJ, yR = 25 + yJ;
			c.collision2 = 1;
			c.shoot2 = true;
			flag = true;
		}
		else if (key == 'p')//shoot right for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 1;//big canon for first player//
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = false;
		}
		else if (key == 'o')//shoot left for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 0;
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = true;
		}
	}

	glutPostRedisplay();
}

void  level2::PrintableKeys2(unsigned char key, int x, int y)//level 2 controll for player 2//
{

	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (c.vehbot == 0)//bot nhi ha tu function chala gha for level 2//
	{
		if (key == 'a' || key == 'A') //to move left///
		{
			c.ds = 1;//mirror image//
			//left border lower//
			if (xJ <= 60 && yJ >= 60 && yJ <= 330)
			{

			}
			//left border upper//
			else if (xJ >= 60 && xJ <= 60 && yJ >= 480 && yJ <= 785)
			{

			}
			else if (xJ <= -60 && yJ >= 330 && yJ <= 480)//blank//
			{
				int x = yJ;
				xJ = 980, yJ = x;
			}
			//left downsquare start//
			else if (xJ == 300 && yJ >= 180 && yJ <= 320)
			{

			}
			//left downsquare end//

			//left uppersquare start//
			else if (xJ == 300 && yJ >= 480 && yJ <= 620)
			{

			}
			//left uppersquare end//

			//right downsquare start//
			else if (xJ == 800 && yJ >= 180 && yJ <= 320)
			{

			}
			//right downsquare end//

			//right uppersquare start//
			else if (xJ == 800 && yJ >= 480 && yJ <= 620)
			{

			}
			//right uppersquare end//

			//lower rectangle start //
			else if (xJ == 530 && yJ >= 15 && yJ <= 150)
			{

			}
			//lower rectangle end //


			//upper rectangle start //
			else if (xJ == 530 && yJ >= 640 && yJ <= 750)
			{

			}
			//upper rectangle end //
			else if (xJ == xI + 70 && yJ >= yI - 60 && yJ <= yI + 50) //car <- collosion detection //
			{

			}

			else
				xJ -= 10;
		}

		else if (key == 'd' || key == 'D')// to move right // 
		{
			c.ds = 2;//mirror image//

			//left border lower//
			if (xJ >= 900 && yJ >= 60 && yJ <= 330)
			{

			}
			//left border upper//
			else if (xJ >= 900 && yJ >= 480 && yJ <= 785)
			{

			}
			else if (xJ >= 1000 && yJ >= 330 && yJ <= 480)//blank//
			{
				int x = yJ;
				xJ = 30, yJ = x;
			}

			//left downsquare start//
			else if (xJ == 130 && yJ >= 180 && yJ <= 320)
			{

			}
			//left downsquare end//

			//left uppersquare start//
			else if (xJ == 130 && yJ >= 480 && yJ <= 620)
			{

			}
			//left uppersquare end//

			//right downsquare start//
			else if (xJ == 630 && yJ >= 180 && yJ <= 320)
			{

			}
			//right downsquare end//

			//right uppersquare start//
			else if (xJ == 630 && yJ >= 480 && yJ <= 620)
			{

			}
			//right uppersquare end//

			//lower rectangle start //
			else if (xJ == 420 && yJ >= 15 && yJ <= 150)
			{

			}
			//lower rectangle end //

			//upper rectangle start //
			else if (xJ == 420 && yJ >= 630 && yJ <= 750)
			{

			}
			//upper rectangle end //

			else if (xJ == xI - 70 && yJ >= yI - 60 && yJ <= yI + 50) //car -> side collosion detection //
			{

			}

			else
				xJ += 10;
		}

		else if (key == 'w' || key == 'W')// move upward//
		{
			// upper border //
			if (yJ >= 730 && xJ >= 60)
			{

			}
			//upper motion toward of border //
			else if (yJ >= 470 && xJ <= 50)
			{

			}
			//upper motion of right border//
			else if (yJ >= 470 && xJ >= 900)
			{

			}
			//lower left square start //
			else if (xJ >= 140 && xJ <= 290 && yJ == 170)
			{

			}
			// lower left square end//
			//upper left square start //
			else if (xJ >= 140 && xJ <= 290 && yJ == 470)
			{

			}
			// upper left square end//
			//lower right square start //
			else if (xJ >= 640 && xJ <= 790 && yJ == 170)
			{

			}
			// lower right square end//
				//upper right square start //
			else if (xJ >= 640 && xJ <= 790 && yJ == 470)
			{

			}

			// upper right square end//

			//upper rectangle start //
			else if (xJ >= 430 && xJ <= 520 && yJ == 630)
			{

			}
			//upper rectangle end //

			else if (xJ >= xI - 60 && xJ <= xI + 60 && yJ == yI - 70) //car upper side collosion detection //
			{

			}

			else
				yJ += 10;
		}

		else if (key == 's' || key == 'S') // TO MOVE DOWN //
		{
			if (yJ <= 50 && xJ >= 60)
			{

			}
			//lower motion  of  left border //
			else if (yJ <= 330 && xJ <= 50)
			{

			}
			//lower motion of right border//
			else if (yJ <= 330 && xJ >= 900)
			{

			}
			else if (xJ >= 140 && xJ <= 290 && yJ == 330)
			{

			}
			// lower left square end//
			//upper left square start //
			else if (xJ >= 140 && xJ <= 290 && yJ == 630)
			{

			}
			// upper left square end//
			//lower right square start //
			else if (xJ >= 640 && xJ <= 790 && yJ == 330)
			{

			}
			// lower right square end//
				//upper right square start //
			else if (xJ >= 640 && xJ <= 790 && yJ == 630)
			{

			}
			// upper right square end//
			//LOWER rectangle start //
			else if (xJ >= 430 && xJ <= 520 && yJ == 150)
			{

			}
			//LOWER rectangle end //	

			else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 60) //car down side collosion detection //
			{

			}


			else
				yJ -= 10;
		}
		else if (key == 'q' || key == 'e' || key == 'o' || key == 'p') //Key for shooting canon //
		{

			if (key == 'e')//shoot right for player 2//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc2 = 1;
				xR = 60 + xJ, yR = 25 + yJ;
				c.collision2 = 1;
				c.shoot2 = true;
				flag = false;
			}
			else if (key == 'q')//shoot left for player 2//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc2 = 0;
				xR = 60 + xJ, yR = 25 + yJ;
				c.collision2 = 1;
				c.shoot2 = true;
				flag = true;
			}

			else if (key == 'p')//shoot right for player 1//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc1 = 1;
				xC = 60 + xI, yC = 25 + yI;
				c.collision1 = 1;
				c.shoot1 = true;
				flag = false;
			}
			else if (key == 'o')//shoot left for player 1//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc1 = 0;
				xC = 60 + xI, yC = 25 + yI;
				c.collision1 = 1;
				c.shoot1 = true;
				flag = true;
			}
		}
	}

	//c.vehbot == controll bot vehicall// 
	else if (c.vehbot == 1 || c.vehbot == 2 || c.vehbot == 3)// agr bot ha tuu//
	{
		c.lev = 2;//active canon for level 2//

		if (key == 'p')//shoot right for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 1;//big canon for player 1//
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = false;
		}

		else if (key == 'o')//shoot left for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 0;//small canon for player 1//
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = true;
		}
	}

	glutPostRedisplay();
}

void  level3::PrintableKeys3(unsigned char key, int x, int y)//level 3 controll for player 2//
{

	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}
	if (c.vehbot == 0)//bot nhi ha tu function chala gha for level 2//
	{
		if (key == 'a' || key == 'A') //to move left///
		{
			c.ds = 1;//mirror image//

			if (xJ <= 60 && yJ >= 50)
			{

			}
			else if (xJ == 530 && yJ >= 50 && yJ <= 230)// center lower rectangle//
			{

			}
			else if (xJ == 530 && yJ >= 560 && yJ <= 740)// center upper rectangle//
			{

			}
			else if (xJ == 560 && yJ >= 310 && yJ <= 450)// center square//
			{

			}
			else if (xJ == 260 && yJ >= 320 && yJ <= 390)// left rectangle//
			{

			}
			else if (xJ == xI + 70 && yJ >= yI - 60 && yJ <= yI + 50) //car left side collosion detection //
			{

			}

			else
				xJ -= 10;
		}

		else if (key == 'd' || key == 'D')// to move right // 
		{
			c.ds = 2;//mirror image//

			if (xJ >= 890 && yJ >= 50)
			{

			}
			else if (xJ == 430 && yJ >= 50 && yJ <= 230)// center lower rectangle//
			{

			}
			else if (xJ == 430 && yJ >= 560 && yJ <= 740)// center upper rectangle//
			{

			}
			else if (xJ == 390 && yJ >= 310 && yJ <= 450)//center square //
			{

			}
			else if (xJ == 700 && yJ >= 320 && yJ <= 390)// right rectangle//
			{

			}
			else if (xJ == xI - 70 && yJ >= yI - 60 && yJ <= yI + 50) //car -> side collosion detection //
			{

			}

			else
				xJ += 10;
		}

		else if (key == 'w' || key == 'W')// move upward//
		{
			// upper border //
			if (yJ >= 730 && xJ >= 60)
			{

			}
			else if (xJ >= 60 && xJ <= 250 && yJ == 310)// left  rectangle//
			{

			}
			else if (xJ >= 710 && xJ <= 890 && yJ == 310)// right  rectangle//
			{

			}
			else if (xJ >= 400 && xJ <= 550 && yJ == 300)// center square //
			{

			}
			else if (xJ >= 430 && xJ <= 520 && yJ == 550)// upper rectangle //
			{

			}
			else if (xJ >= xI - 60 && xJ <= xI + 60 && yJ == yI - 70) //car upper side collosion detection //
			{

			}
			else
				yJ += 10;
		}

		else if (key == 's' || key == 'S') // TO MOVE DOWN //
		{
			if (yJ <= 50 && xJ >= 60)
			{

			}
			else if (xJ >= 60 && xJ <= 250 && yJ == 400)// left  rectangle//
			{

			}
			else if (xJ >= 710 && xJ <= 890 && yJ == 400)// right  rectangle//
			{

			}
			else if (xJ >= 400 && xJ <= 550 && yJ == 460)// center square //
			{

			}
			else if (xJ >= 430 && xJ <= 520 && yJ == 250)// lower rectangle //
			{

			}
			else if (xI >= xJ - 60 && xI <= xJ + 60 && yI == yJ - 60) //car down side collosion detection //
			{

			}

			else
				yJ -= 10;
		}

		else if (key == 'q' || key == 'e' || key == 'o' || key == 'p') //Key for shooting canon //
		{

			if (key == 'e')//shoot right for player 2//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc2 = 1;
				xR = 60 + xJ, yR = 25 + yJ;
				c.collision2 = 1;
				c.shoot2 = true;
				flag = false;
			}
			else if (key == 'q')//shoot left for player 2//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc2 = 0;
				xR = 60 + xJ, yR = 25 + yJ;
				c.collision2 = 1;
				c.shoot2 = true;
				flag = true;
			}
			else if (key == 'p')//shoot right for player 1//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc1 = 1;
				xC = 60 + xI, yC = 25 + yI;
				c.collision1 = 1;
				c.shoot1 = true;
				flag = false;
			}
			else if (key == 'o')//shoot left for player 1//
			{
				PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
				c.bc1 = 0;
				xC = 60 + xI, yC = 25 + yI;
				c.collision1 = 1;
				c.shoot1 = true;
				flag = true;
			}

		}
	}
	else if (c.vehbot == 1 || c.vehbot == 2 || c.vehbot == 3)// agr bot ha tuu//
	{
		c.lev = 3;//active canon for level 3//

		if (key == 'p')//shoot right for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 1;//big canon for player 1//
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = false;
		}

		else if (key == 'o')//shoot left for player 1//
		{
			PlaySound(TEXT("canon.wav"), NULL, SND_ASYNC);
			c.bc1 = 0;//small canon for player 1//
			xC = 60 + xI, yC = 25 + yI;
			c.collision1 = 1;
			c.shoot1 = true;
			flag = true;
		}
	}

	glutPostRedisplay();
}

//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//
//==========================================================================================================================//

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 *
 */
 // canon//

void Timer(int m)
{
	// implement your functionality here
	if (c.vehbot != 0)//bot ha tuu //
	{
		moveCanon();
		movebot();
	}
	else//bot nhi ha to // for two player//
	{
		moveCanon();
	}
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 *
 */

void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseMoved(int x, int y)
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */

 //==============================//
// class 30 to 190              //
//  320 536 GAME DISPLAY        //
//   560 1220 NON PRINTABLE KEYS//
//    1240 1905 PRINTABLE KEYS  //
//     1990 main                //
//==============================//

int main(int argc, char* argv[])
{
	int vehical_n;// to select vehical//
	int opt; // to controll switch statement //
	vehical v1(0), v2(0);//select vehical//

	player p1, p2;      //player object//
	record r1, r2;     //record class//

	level1 l1;  //level l1 //
	level2 l2; //level l2 //
	level3 l3;//level l3//

	bot b1;

	int botlevel = 0;//level 2 fix for bot //
	int score = 0;// keep count of score //

	string name = "null";// to store name of players//

	do
	{
		do
		{
			cout << setw(49) << "MENU\n";
			cout << setw(53) << "1]CONTROLLS\n";
			cout << setw(51) << "2]CREDITS\n";
			cout << setw(50) << "3]RECORD\n";
			cout << setw(51) << "4]START\n\n";

			cin >> opt;
		} while (opt <= 0 || opt >= 5);

		switch (opt)
		{
		case 1://controll//

			cout << setw(30) << "PLAYER 1\n";
			cout << "To move right     press RIGHT  ARROW KEY   \n  ";
			cout << "To move left      press LEFT   ARROW KEY   \n  ";
			cout << "To move upward    press UP     ARROW KEY   \n  ";
			cout << "To move downward  press down   ARROW KEY   \n\n";
			cout << "To shoot big   canon p\n";
			cout << "To shoot small canon o\n";
			cout << "\n==============================================\n";
			cout << setw(30) << "PLAYER 2\n";
			cout << "To move right     press RIGHT  ARROW KEY  d/D \n  ";
			cout << "To move left      press LEFT   ARROW KEY  a/A \n  ";
			cout << "To move upward    press UP     ARROW KEY  w/W \n  ";
			cout << "To move downward  press down   ARROW KEY  d/D \n\n";
			cout << "To shoot big   canon e\n";
			cout << "To shoot small canon q\n";
			cout << "\n==============================================\n";
			break;

		case 2://credict//

			cout << setw(50) << "\n\n Publish by:ATARI INC.\n Developed by:ATARI,INC.\n Released date 2 JUNE 2022.\n Released for WINDOW/ANDROID/LINUX/IOS.\n It is 2D ACTION and SHOOTING GAME Mulptiplayer and Single player.\n Available at Playstore/Official webite/Apple store.\n ";
			break;

		case 3://to keep record//

			cout << "\nSHOW RECORD\n";
			cout << "\n==================\n";
			cout << "Name          score\n";
			r1.top_score();
			break;

		case 4://menu single vs two player//

			do
			{
				cout << "1] FOR 1 PLAYER\n2] FOR 2 PLAYER \n = ";
				cin >> opt;

			} while (opt <= 0 || opt >= 3);

			if (opt == 1)
			{
				cout << "ENTER first player SCORE\n =";
				//cin >> score;
				cout << "ENTER  first player  NAME\n = ";
				cin >> name;
				b1.set_bot_name(" BOT ");

				do
				{
					cout << "SELECT VEHICAL \n\n1]CAR\n2]TANK\n3]HELICOPTER \n= ";
					cin >> vehical_n;
				} while (vehical_n <= 0 || vehical_n >= 4);

				p1.set_p_score(r1, score);// pass name and score to record class //
				p1.set_P_name(r1, name);
				p1.set_player_car(v1, vehical_n); // select vehical for players //

				c.veh1 = vehical_n;
				c.vehbot = vehical_n;

				c.play2 = p1.get_p_name();//player name//
				c.play1 = b1.get_bot_name();//bot name//

				r1.store_data();     // data storing in file//

				cout << "p1  car";
				cout << v1.get_select_car() << endl;
				opt = 4;//for selecting levels//
				botlevel = 1;//if bot level active// 
			}
			else if (opt == 2)
			{
				cout << "ENTER first player SCORE\n =";
				//cin >> score;
				cout << "ENTER  first player  NAME\n = ";
				cin >> name;
				p1.set_p_score(r1, score);
				p1.set_P_name(r1, name);
				cout << "ENTER second player  SCORE\n =";
				//cin >> score;
				cout << "ENTER second player NAME\n = ";
				cin >> name;

				do
				{
					cout << "SELECT VEHICAL \n\n1]CAR\n2]TANK\n3]HELICOPTER \n= ";
					cin >> vehical_n;
				} while (vehical_n <= 0 || vehical_n >= 4);

				p1.set_player_car(v1, vehical_n);
				p2.set_player_car(v2, vehical_n);
				c.veh1 = vehical_n;
				c.veh2 = vehical_n;

				p2.set_p_score(r2, score);// sending score and name to record class //
				p2.set_P_name(r2, name);

				c.play1 = p1.get_p_name();//player name to display during game//
				c.play2 = p2.get_p_name();

				//storing in file //
				r1.store_data();
				r2.store_data();

				cout << "p1  car";
				cout << v1.get_select_car() << endl;
				cout << "p2  car";
				cout << v2.get_select_car() << endl;
			}

			opt = 4;//for selecting levels//
			break;
		}
		if (opt != 4)
		{
			do
			{
				cout << "press 1 to go to main menu\npress 0 to Exit\n = ";
				cin >> opt;
			} while (opt <= -1 || opt >= 2);
		}

	} while (opt == 1);

	if (opt == 4)
	{
		if (botlevel == 0) //agr bot nhi ha //
		{
			do
			{
				cout << "Selet level from 1 to 3\n = ";
				cin >> opt;//select level of game//

			} while (opt <= 0 || opt >= 4);

			c.lev = opt;//to controll the movement of canon with respect to level//
		}

		else if (botlevel == 1) //agr bot ha tu//
		{
			do
			{
				cout << "Selet level from 2 to 3\n = ";
				cin >> opt;//select level of game//
				c.lev = opt;//to controll the movement of canon with respect to level//
			} while (opt <= 1 || opt >= 4);
		}

		int width = 1020, height = 840; // i have set my window size to be 800 x 600//

		InitRandomizer(); // seed the random number generator...
		glutInit(&argc, argv); // initialize the graphics library...
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
		glutInitWindowPosition(50, 50); // set the initial position of our window
		glutInitWindowSize(width, height); // set the size of our window
		glutCreateWindow("Battle Ground"); // set the title of our game window
		SetCanvasSize(width, height); // set the number of pixels...

		// Register your functions to the library,
		// you are telling the library names of function to call for different tasks.
		//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
		cout << "\nloop\n";

		if (opt == 1)
		{
			glutDisplayFunc(l1.GameDisplay1);    // tell library which function to call for drawing Canvas//.
			glutSpecialFunc(l1.NonPrintableKeys1); // tell library which function to call for non-printable ASCII characters//
			glutKeyboardFunc(l1.PrintableKeys1); // tell library which function to call for printable ASCII characters//
		}

		else if (opt == 2)
		{
			glutDisplayFunc(l2.GameDisplay2);    // tell library which function to call for drawing Canvas//.
			glutSpecialFunc(l2.NonPrintableKeys2); // tell library which function to call for non-printable ASCII characters//	
			glutKeyboardFunc(l2.PrintableKeys2); // tell library which function to call for printable ASCII characters//
		}

		else if (opt == 3)
		{
			glutDisplayFunc(l3.GameDisplay3);    // tell library which function to call for drawing Canvas//.
			glutSpecialFunc(l3.NonPrintableKeys3); // tell library which function to call for non-printable ASCII characters//
			glutKeyboardFunc(l3.PrintableKeys3); // tell library which function to call for printable ASCII characters//
		}

		// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
		glutTimerFunc(1000.0, Timer, 0);
		glutMouseFunc(MouseClicked);
		glutPassiveMotionFunc(MouseMoved); // Mouse
		glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
		glutMainLoop();
	}

	return 1;
}

#endif /* RushHour_CPP_ */




