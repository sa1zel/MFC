#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif
// main symbols


struct Point
{
	int x, y;
};


class Circle {
public:
	int r;
	Point o;
	void draw(CPaintDC &dc);
	void setData(int _r, Point _o);

};

class ColorCircle : public Circle {
	int R, G, B;
public:
	bool checked;
	int numberOfGroup;
	ColorCircle() {
		R = 0;
		G = 0;
		B = 0;
		checked = 0;
		numberOfGroup = 0;
	}
	bool isCrossed(ColorCircle circle);
	void draw(CPaintDC &dc);
	void setColor(int r, int g, int b);
};

class ThisProg {
	ColorCircle *cc;
	int size = 0;
	int max = 0;
	int NumberGroup = 0;
	int *amount;
public:
	void init();
	void crossing();
	void start();
	void lines();
	void draw(CPaintDC &dc);
};

extern ThisProg thisProg;