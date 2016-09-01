#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
//Bresenham's integer line resterization algorithm for all quadrnts
//The line end points are (xs,ys) and (xe,ye) assumed not equal. All variables are assumed integer.
//initialize variables
    x=xs
	y=ys
	∆x = abs(xe -xs)        //∆x = xe -xs
	∆y = abs(ye -ys)        //∆y = ye -ys
	sx = isign(xe -xs)
	sy = isign(ye -ys)
		//Swap ∆x and ∆y depending on the slope of the line.
	if ∆y>∆x then
	    Swap(∆x,∆y)
		Flag=1
	else
	    Flag=0
	end if
		//initialize the error term to compensate for a nonezero intercept
	NError =2*∆y-∆x
		//begin the main loop
	for i=1 to ∆x
		WritePixel(x, y , value)
		if (Nerror>=0) then
		   if (Flag) then     //∆y>∆x，Y=Y+1
	            x=x+sx
		   else
		        y=y+sy
		   end if             // End of Flag
	       NError = NError –2*∆x
		end if                 // End of Nerror
		if (Flag) then        //∆y>∆x，X=X+1
	    	y=y+sy
		else
	        x=x+sx
	    end if
	    NError = NError +2*∆y
	next i
	finish
*/

void print_rasterize_point(int xs, int ys, int xe, int ye)
{
	int x = xs;
	int y = ys;
	int triangle_x = abs(xe - xs);
	int triangle_y = abs(ye - ys);
	int sx = 1;//xe - xs;
	int sy = 1;//ye - ys;
	int flag = 0;
	if (triangle_y > triangle_x)
	{
		int tmp = triangle_x;
		triangle_x = triangle_y;
		triangle_y = tmp;
		flag = 1;
	}
	int nerror = 2 * triangle_y - triangle_x;
	for (int i = 1; i <= triangle_x; ++i)
	{
		printf("[%d][%d] ", x, y);
		if (nerror >= 0)
		{
			if (flag)
				x = x + sx;
			else
				y = y + sy;
			nerror = nerror - 2 * triangle_x;
		}
		if (flag)
			y = y + sy;
		else
			x = x + sx;
		nerror = nerror + 2 * triangle_y;
	}
	printf("\n");
}
/*
//Bresenham's integer line resterization algorithm for the first octal.
//The line end points are (xs,ys) and (xe,ye) assumed not equal. All variables are assumed integer.
//initialize variables
	x=xs
	y=ys
	∆x = xe -xs
	∆y = ye -ys
		//initialize e to compensate for a nonzero intercept
	NError =2*∆y-∆x                 //Error =∆y/∆x-0.5
		//begin the main loop
	for i=1 to ∆x
		WritePixel (x, y)
		if (NError >=0) then
	        y=y+1
			NError = NError –2*∆x  //Error = Error -1
	    end if
	    x=x+1
		NError = NError +2*∆y       //Error = Error +∆y/∆x
	next i
	finish
*/
void print_rasterize_point2(int xs, int ys, int xe, int ye)
{
	int x = xs;
	int y = ys;
	int triangle_x = xe - xs;
	int triangle_y = ye - ys;
	int nerror = 2 * triangle_y - triangle_x;
	for (int i = 1; i <= triangle_x; ++i)
	{
		printf("[%d][%d] ", x, y);
		if (nerror >= 0)
		{
			y = y + 1;
			nerror = nerror - 2 * triangle_x;
		}
		x = x + 1;
		nerror = nerror + 2 * triangle_y;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int start_x, start_y, end_x, end_y;
	if (argc != 5)
	{
		printf("./test START_X START_Y END_X END_Y\n");
		return (0);
	}
	start_x = atoi(argv[1]);
	start_y = atoi(argv[2]);
	end_x = atoi(argv[3]);
	end_y = atoi(argv[4]);	

	printf("move from[%d][%d] to[%d][%d]\n", start_x, start_y, end_x, end_y);

	print_rasterize_point(start_x, start_y, end_x, end_y);	
	print_rasterize_point2(start_x, start_y, end_x, end_y);
    return 0;
}
