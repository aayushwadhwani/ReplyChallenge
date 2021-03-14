#include <stdio.h>
#include <math.h>
struct antena
{
    int range;
    int connectionSpeed;
};

struct buildings
{
    int x;
    int y;
    int latency;
    int speed;
};
struct midpoints
{
    int x;
    int y;
};
int main()
{
    int w = 15,h = 10;
    int noOfbuildings = 5, noOfantenas = 4,number = noOfantenas , noOfMidpoints = 0;
    struct antena data[noOfantenas];
    struct buildings build[noOfbuildings];
    data[0].range = 2;
    data[1].range = 4;
    data[2].range = 1;
    data[3].range = 2;

    //int building[][2] = {{0,7},{12,2},{2,4},{10,7},{11,8}};
    build[0].x = 0;
    build[0].y = 7;
    build[1].x = 12;
    build[1].y = 2;
    build[2].x = 2;
    build[2].y = 4;
    build[3].x = 10;
    build[3].y = 7;
    build[4].x = 11;
    build[4].y = 8;
    for(int i=noOfbuildings-1; i>=1;i--)
    {
        noOfMidpoints = noOfMidpoints+i;
    }
    struct midpoints mid[noOfMidpoints];
    int countOfXY = 0;
    //o(n2)
    for(int i=noOfbuildings-1;i>=1 ;i--)
    {
        for(int j=0 ;j<=i-1;j++)
        {
            mid[countOfXY].x = (build[i].x + build[j].x)/2;
            countOfXY++;
        }
    }
    countOfXY = 0;
    //o(n2)
    for(int i=noOfbuildings-1;i>=1 ;i--)
    {
        for(int j=0 ;j<=i-1;j++)
        {
            mid[countOfXY].y = (build[i].y + build[j].y)/2;
            countOfXY++;
        }
    }

    while(number>0)
    {
    int maxRange = 0;
    int id = -1;
//to find maximum range and id of that antena
    for(int i=0; i<noOfantenas ;i++)
    {
        if(maxRange < data[i].range)
        {
            id = i;
            maxRange = data[i].range;
        }
    }
    /*for(int i=0 ;i<noOfMidpoints ;i++)
    {
            printf("%d,%d\n",mid[i].x,mid[i].y);
    }*/
    int closeOnes[noOfMidpoints];
    for(int i=0 ;i<noOfMidpoints ;i++)
        closeOnes[i] = 0;
    for(int i=0 ;i<noOfMidpoints ;i++)
    {
        for(int j = 0; j<noOfbuildings; j++)
        {
            if( mid[i].x != -1 && abs(mid[i].x - build[j].x)<=maxRange)
                if(abs(mid[i].y - build[j].y)<=maxRange)
                    closeOnes[i]++;
        }
    }
    for(int i=0; i<noOfMidpoints ;i++)
        printf("%d ",closeOnes[i]);
        printf("\n");

    int closest = 0;
    int closestId = -1;
    for(int i=0; i<noOfMidpoints; i++)
    {
        if(closest < closeOnes[i])
        {
            closest = closeOnes[i];
            closestId = i;
        }
    }
    /*if(closestId == -1)
    {} start from here !!!!!!!!!
    */
    printf("\n%d %d %d\n",id,mid[closestId].x,mid[closestId].y);
    for(int i=0 ;i<noOfMidpoints ;i++)
    {
        if (mid[i].x == mid[closestId].x && mid[i].y == mid[closestId].y)
        {
            mid[i].x = -1;
            mid[i].y = -1;
        }
    }
    data[id].range = -1;
    number --;
    }
}

