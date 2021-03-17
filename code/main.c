#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    int w, h; //why?
    int noOfbuildings, noOfantenas, noOfMidpoints = 0, reward;
    FILE *fptr;
    fptr = fopen("C:\\Users\\Dell\\Desktop\\Competitions\\ReplyChallenge\\input\\b.in", "r");
    if(fptr == NULL)
    {
      printf("Error!");
      exit(1);
    }
    fscanf(fptr, "%d %d\n%d %d %d", &w, &h, &noOfbuildings, &noOfantenas, &reward);

    int number = noOfantenas;
    struct antena *data = (struct antena*)malloc(noOfantenas*sizeof(struct antena));
    struct buildings *build = (struct buildings*)malloc(noOfbuildings*sizeof(struct buildings));
    fscanf(fptr, "\n\n");
    for (int i = 0; i < noOfbuildings; i++)
    {
        fscanf(fptr, "%d %d %d %d\n", &build[i].x, &build[i].y, &build[i].latency, &build[i].speed);
    }
    for (int i = 0; i < noOfantenas; i++)
    {
        fscanf(fptr, "%d %d\n", &data[i].range, &data[i].connectionSpeed);
    }
    fclose(fptr);

    for(int i=noOfbuildings-1; i>=1;i--)
    {
        noOfMidpoints = noOfMidpoints+i;
    }
    printf("%d", noOfMidpoints);
    struct midpoints *mid = (struct midpoints*)malloc(noOfMidpoints*sizeof(struct midpoints));
    if(mid == NULL){
        printf("Not found");
        exit(0);
    }
    int countOfXY = 0;
    //o(n2)
    for(int i=noOfbuildings-1;i>=1 ;i--)
    {
        for(int j=0 ;j<=i-1;j++)
        {
            mid[countOfXY].x = (build[i].x + build[j].x)/2;
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
        int *closeOnes = (int*)calloc(noOfMidpoints, sizeof(int));
        for(int i=0 ;i<noOfMidpoints ;i++)
        {
            for(int j = 0; j<noOfbuildings; j++)
            {
                if( mid[i].x != -1 && abs(mid[i].x - build[j].x)<=maxRange)
                    if(abs(mid[i].y - build[j].y)<=maxRange)
                        closeOnes[i]++;
            }
        }
        // for(int i=0; i<noOfMidpoints ;i++)
        //     printf("%d ",closeOnes[i]);
        //     printf("\n");

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
        free(closeOnes);
    }
    free(data);
    free(build);
    free(mid);
    return 0;
}

