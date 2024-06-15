#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class map // level 1 to 3 inherit from map class//
{
protected:
public:
};

class level1 :public map
{
protected:
public:
	void static   GameDisplay1();
	void static   NonPrintableKeys1(int key, int x, int y);
	void static   PrintableKeys1(unsigned char key, int x, int y);

};
class level2 :public map
{
protected:
public:
	void static   GameDisplay2();
	void static   NonPrintableKeys2(int key, int x, int y);
	void static   PrintableKeys2(unsigned char key, int x, int y);
};
class level3 :public map
{
protected:
public:
	void static   GameDisplay3();
	void static   NonPrintableKeys3(int key, int x, int y);
	void static   PrintableKeys3(unsigned char key, int x, int y);
};

class vehical  // vehical class to control vehical //vehical class associated with player class //
{
protected:
	int car;
public:
	vehical()
	{
		car = 0;
	}
	vehical(int c)
	{
		car = c;
	}
	void set_select_car(int c)
	{
		car = c;
	}

	int get_select_car()
	{
		return car;
	}
};

class record  //record class associated with player class to store data //
{
protected:
	string rec_name;
	int rec_score;
	string fech_rec;

public:
	record()
	{
		rec_name = "null";
		rec_score = 0;
		fech_rec = "empty";
	}
	void set_rec_name(string n)
	{
		rec_name = n;
	}
	void set_rec_score(int s)
	{
		rec_score = s;
	}
	string get_rec_name()
	{
		return rec_name;
	}
	int get_rec_score()
	{
		return rec_score;
	}
	void store_data()
	{
		ofstream write("player_record.txt", ios::app);
		write << rec_name;
		write << setw(15);
		write << rec_score << "\n";

		write.close();
	}
	void top_score()
	{
		ifstream out("player_record.txt");
		while (getline(out, fech_rec))
		{
			cout << fech_rec << endl;
		}
		out.close();
	}
};

//class vehical and class record is associated with player class //
class player
{
protected:
	string p_name;
	int p_score;

public:
	player()
	{
		p_name = "null";
		p_score = 0;
	}

	void set_P_name(record& obj, string n)
	{
		p_name = n;

		obj.set_rec_name(n);

	}
	void set_p_score(record& obj, int s)
	{
		p_score = s;
		obj.set_rec_score(s);
	}
	void set_player_car(vehical& obj, int c)
	{
		obj.set_select_car(c);
	}
	string get_p_name()
	{
		return p_name;
	}
	int get_p_score()
	{
		return p_score;
	}

};

class bot
{
private:
	string bot_name;
	int bot_score;
public:

	void set_bot_name(string bn)
	{
		bot_name = bn;
	}
	void set_bot_score(int bs)
	{
		bot_score = bs;
	}
	string get_bot_name()
	{
		return bot_name;
	}
	int get_bot_score()
	{
		return bot_score;
	}

};

struct controll
{
	string play1;//name of first player//
	string play2;//name of second player//

	int veh1;//controll vehical for first player//
	int veh2;//controll vehical for second player//
	int vehbot = 0;//bot vehical//

	int lev;// control lev for shooting canon//

	int score1 = 0;//score for first player//
	int score2 = 0;//score for second player//

	int wing = 1;//controll movement of helicopter wing//

	int df = 1; // to controll mirror image of first player vehical//
	int ds = 2; // to controll mirror image of second player vehical//

	int bc1 = 0; //big canon for first player//
	int bc2 = 0;//big canon for second player//

	bool shoot1 = false;// controll canon shoot of player 1 //
	int collision1 = 0;// count number of collision of canon1 for  player 1//

	bool shoot2 = false;// controll canon shoot of player 2 //
	int collision2 = 0;// count number of collision of canon2 for player 2//

	int spawn2 = 0;//controll spawn fro  player 2//
	int spawn1 = 0;//controll spawn fro  player 1//
};
