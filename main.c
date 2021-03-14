#include <stdio.h>
#include <math.h>
int main()
{
    int w = 15,h = 10;
    int noOfbuildings = 5, noOfantenas = 4, noOfMidpoints = 0;
    int building[][2] = {{0,7},{12,2},{2,4},{10,7},{11,8}};
    for(int i=noOfbuildings-1; i>=1;i--)
    {
        noOfMidpoints = noOfMidpoints+i;
    }
    int midpoints[noOfMidpoints][2];
    int countOfBuilding[noOfMidpoints];
    int countOfXY = 0;
    //o(n2)
    for(int i=noOfbuildings-1;i>=1 ;i--)
    {
        for(int j=0 ;j<=i-1;j++)
        {
            midpoints[countOfXY][0] = (building[i][0] + building[j][0])/2;
            countOfXY++;
        }
    }
    countOfXY = 0;
    //o(n2)
    for(int i=noOfbuildings-1;i>=1 ;i--)
    {
        for(int j=0 ;j<=i-1;j++)
        {
            midpoints[countOfXY][1] = (building[i][1] + building[j][1])/2;
            countOfXY++;
        }
    }
    for(int i=0 ;i<noOfMidpoints ;i++)
    {
            printf("%d,%d\n",midpoints[i][0],midpoints[i][1]);
    }

}
