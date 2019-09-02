#include "stdafx.h"
#include "afxdialogex.h"
#include "MyProg.h"
#include "fstream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

void Circle::draw(CPaintDC & dc)
{
	dc.Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
}

void Circle::setData(int _r, Point _o)
{
	r = _r;
	o = _o;
}

void ThisProg::init()
{
	char buff[100];
	size = 0;
	Point _o;
	int _r;
	FILE *circleFile = fopen("circles.txt", "r");
	lines();
	cc = new ColorCircle[size];
	for (int i = 0; i < size; i++) {
		fscanf(circleFile, "%s ox=%d, oy=%d, r=%d;", buff, &_o.x, &_o.y, &_r);
		cc[i].setData(_r, _o);
	}
}

void ThisProg::crossing()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (i!=j && cc[i].isCrossed(cc[j])) {
				cc[i].setColor(255, 0, 0);
			}
		}
}

void ThisProg::start()
{
	NumberGroup = 0;
	if (size != 0)
	{
		for (int k = 0; k < size; k++)
		{
			if (cc[k].numberOfGroup == 0)
			{
				NumberGroup++;
				cc[k].numberOfGroup = NumberGroup;
				for (int sign = 1; sign != 0;)
				{
					sign = 0;
					for (int i = 0; i < size; i++)
					{
						if (cc[i].checked != 1 && cc[i].numberOfGroup == NumberGroup)
						{
							for (int j = 0; j < size; j++)
							{
								if (i != j && cc[j].numberOfGroup == 0 && cc[i].isCrossed(cc[j]) == 1)
								{
									sign = 1;
									cc[j].numberOfGroup = NumberGroup;
								}
							}
							cc[i].checked = 1;
						}

					}
				}
			}
		}
	}

	amount = new int[NumberGroup-1];

	for (int i = 0; i < NumberGroup; i++)
	{
		int numbers = 0;
		for (int j = 0; j < size; j++)
		{
			if (cc[j].numberOfGroup == i + 1)
			{
				numbers++;
			}
		}
		amount[i] = numbers;
	}
	for (int i = 0; i < NumberGroup; i++)
	{
		if (amount[i] > amount[max])
			max = i;
	}
	for (int i = 0; i < NumberGroup; i++)
	{
		if (amount[i] == amount[max])
			return;
	}
	max++;
	if (amount[max]>1) {
		for (int i = 0; i < size; i++)
		{
			if (cc[i].numberOfGroup == max)
			{
				cc[i].setColor(255, 255, 0);
			}
		}
	}
}

void ThisProg::lines()
{
	char buff[200];
	ifstream file("circles.txt");
	while (!file.eof())
	{
		if (file.getline(buff, 200, ';'))size++;
	}
	file.close();
}

void ThisProg::draw(CPaintDC & dc)
{
	for (int i = 0; i < size; i++) {
		cc[i].draw(dc);
	}
}


bool ColorCircle::isCrossed(ColorCircle circle)
{
	double lenght = 0;
	lenght = sqrt((double)pow(o.x - circle.o.x, 2) + (double)pow(o.y - circle.o.y, 2));
	if (lenght < (r + circle.r) && lenght >= (abs(r - circle.r)))
	{
		return true;
	}
	return 0;
}

void ColorCircle::draw(CPaintDC & dc)
{
	CPen Pen(PS_SOLID, 2, RGB(R, G, B));
	dc.SelectStockObject(HOLLOW_BRUSH);
	dc.SelectObject(&Pen);
	Circle::draw(dc);
}

void ColorCircle::setColor(int r, int g, int b)
{
	R = r; G = g; B = b;
}

ThisProg thisProg;

