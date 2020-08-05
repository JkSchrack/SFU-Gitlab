#include <stdio.h> // for perror, fopen, etc.


int InRectangle( float pt[2], float rect[4] )
{
	int Xin = 0;
	int Yin = 0;
	int InOut;


	float PointX = pt[0];
	float PointY = pt[1];
	// Points coords

	float RectX1 = rect[0];
	float RectY1 = rect[1];
	float RectX2 = rect[2];
	float RectY2 = rect[3];
	// Rectangles coords

	if ((PointX >= RectX1 && PointX <= RectX2) || (PointX <= RectX1 && PointX >= RectX2))
	{
		Xin = 1;
	}

	if ((PointY >= RectY1 && PointY <= RectY2) || (PointY <= RectY1 && PointY >= RectY2))
	{
		Yin = 1;
	}

	if (Xin == 1 && Yin == 1)
	{
		InOut = 1;
	}
	else
	{
		InOut = 0;
	}
	return InOut;

}