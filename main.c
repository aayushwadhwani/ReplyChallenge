#include <stdio.h>
#include <math.h>
struct max
{
    int Range;
    int id;
}a;
int main()
{
    int w = 15,h = 10;
    int noOfbuildings = 5, noOfantenas = 4, noOfMidpoints = 0;
    int building[noOfbuildings][2] = {{0,7},{12,2},{2,4},{10,7},{11,8}};
    int antenas[noOfantenas][2] = {{2,100},{4,10},{1,50},{2,50}};
    countMax(antenas,noOfantenas);
    for(int i=noOfbuildings-1; i>=1;i--)
    {
        noOfMidpoints = noOfMidpoints+i;
    }
    int buildingsCovered[noOfMidpoints];
    for(int i=0; i<noOfMidpoints ;i++)
      buildingsCovered[i] = 0;
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

    for(int i=0; i<noOfMidpoints; i++)
    {
        for(int j=0 ;j<noOfbuildings ;j++)
        {
            if(abs(midpoints[i][0]-building[j][0])<= (a->Range))
            {
                if(abs(midpoints[i][1]-building[j][1])<= (a->Range))
                    buildingsCovered[i]++;
            }
        }
        printf("%d ",buildingsCovered[i]);
    }
}

void countMax(int array[][], int number)
{
    for(int i=0 ;i<number ;i++)
    {
        a->Range = 0;
        if(array[i][0]>= a->Range)
        {
            a->Range = array[i][0];
            a->id = i;
        }
    }
}
