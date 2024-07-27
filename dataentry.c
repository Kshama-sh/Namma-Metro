#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct station
{
    int id;
    char stop[50];
    double dist;
}a;
typedef struct station s;
int main ()
{
    //struct station a;
    int i;
    FILE *outfile;
    outfile = fopen ("nammametro.txt", "r+");
    if (outfile == NULL)
    {
        printf( "\nError!!Cannot open file...Try again\n");
        exit (1);
    }
    for(int i=0;i<29;i++)
    {
        printf("StationID : ");
        scanf("%d",&a.id);
        printf("Station : ");
        scanf("%s",a.stop);
        printf("Distance : ");
        scanf("%lf",&a.dist);
        fwrite(&a,sizeof(a),1,outfile);
    }
    fclose (outfile);
    s temp;
    outfile = fopen ("nammametro.txt", "r+");
    printf("\nOUTPUT\n");
    while ((fread(&temp,sizeof(temp),1,outfile))!=0)
    {
        printf("\n");
        printf("%d",temp.id);
        printf("\t");
        printf("%s",temp.stop);
        printf("\t");
        printf("%.2lf",temp.dist);
       /* printf("\n");
        printf("%d",temp.price);*/
    }
    return 0;
}
