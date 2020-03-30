/*
	DIGITAL DIFFERENTIAL ANALYZER LINE DRAWING ALGORITHM:
	LET (X1,Y1)(X2,Y2) BE THE TWO END POINTS
	THEREFORE SLPOE OF THE GIVEN LINE IS
	M=(Y2-Y1)/(X2-X1)
	LET DY(DIFFERENCE IN Y)=(Y2-Y1)
	AND DX(DIFFERENCE IN X)-=(X2-X1)
	M=DY/DX
	IF
	DX>=DY : GENTLE SLOPE
	DX<DY : STEEP SLOPE

	IF
	GENTLE SLOPE IS THERE THEN WE STEP THROUGH EACH COLUMN AND CALCULATE ROW VALUE PIXEL TO BE ILLUMINATED
		X=X+1
		Y=Y+M

	ELSE
	STEEP SLOPE IS THERE THEN WE STEP THROUGH EACH ROW AND CALCULATE CORRESSPONDING COLUMN PIXEL VALUE TO BE ILLUMINATED
		Y=Y+1
		X=X+(1/M)

	WE DON'T WANT FRACTIONAL PART WHILE PUTTING PIXEL SO WE USE CEILING AND THE FLOOR FUNCTIONS TO CONVERT FRACTIONAL POINTS TO INTEGER

*/
#include<iostream>
#include<graphics.h>
using namespace std;
drawLINE(int x2,int y2,int x1,int y1)
{
	int X2=x2; int Y2=y2;int X1=x1;int Y1=y1;
    int X0=0;int Y0 =0;
    X0=getmaxx()/2;
    Y0=getmaxy()/2;
	int STEPS;
	int DX,DY,X,Y;
	int X_INC,Y_INC;	//FOR GETTING MIDPOINT OF THE SCREEN
	putpixel(X0,Y0,WHITE);								//PUTTING MIDPOINT
	DX=X2-X1;
	DY=Y2-Y1;
	if(DX<0)
		DX=-DX;
	if(DY<0)
		DY=-DY;
	if(DX>=DY)												//TO DECIDE: COLUMN /ROW STEPING
		STEPS=DX;
	else
		STEPS=DY;
	DX=X2-X1;
	DY=Y2-Y1;
	X_INC=(float)DX/STEPS;								//X INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	Y_INC=(float)DY/STEPS;								//Y INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	X=X1;Y=Y1;
	while(STEPS)											//LOOP EXECUTES "STEPS" TIMES
	{
		putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	putpixel(X0,Y0,WHITE);										//CLOSING THE GRAPH
}



int main()													//MAIN FUNCTION
{
	cout<<"DRAWING SHAPE USING DDA LINE DRAWING ALGORITHM"<<endl;
	char c_ch;
	int gd,gm;
	int x1,y1,x2,y2;
	initgraph(&gd,&gm,NULL);							//INITALIZING GRAPH
	drawLINE(100,50,100,-50);
	drawLINE(100,-50,-100,-50);
	drawLINE(-100,-50,-100,50);
	drawLINE(-100,50,100,50);

	drawLINE(200,100,200,-100);
	drawLINE(200,-100,-200,-100);
	drawLINE(-200,-100,-200,100);
	drawLINE(-200,100,200,100);

	drawLINE(200,0,0,100);
	drawLINE(200,0,0,-100);
	drawLINE(-200,0,0,100);
	drawLINE(-200,0,0,-100);
	getch();									//DELAY FOR DISPLAY
	closegraph();

	cout<<endl<<"LINE DRAWN SUCCESSFULLY"<<endl;
	return 0;
}
