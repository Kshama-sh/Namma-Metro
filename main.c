#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int begin,end;
int c=0;
struct platform_detail
{
    int station_id;
    char station[50];
    double distance;
};
typedef struct platform_detail platform;
struct Node                        //map display traversal
{
    platform pf;
    struct Node *next, *prev;
}; 
typedef struct Node node;
node *start = NULL;
node *create()                    //creating linked list to display map
{
    node *new;
    new=(node *)malloc(sizeof(node));
    new->next=new->prev=NULL;
    return new;
}
void insert_rear(platform a)      // inserting structure members to linked list
{
    node *new1, *temp = start; 
    new1 = create();
    new1->pf=a;
    if (start == NULL)
    {
        start = new1;
        return; 
    }
    while ( temp->next != NULL)
        temp = temp->next;
    temp->next = new1;
    new1->prev = temp; 
}
void display_map()               // displaying the map
{
    node *temp;
    temp=start;
    printf("\n");
     int i=0;
    while(temp->next!=NULL)
    {
        printf("%s-->",temp->pf.station);
        i++;
        if(i%5==0)
        printf("\n\n");
        temp=temp->next;
        
    }
    printf("%s\n\n",temp->pf.station);
}
double dist_check(int key)
{
    node *tempd=start;int flag=0;
    while(tempd->pf.station_id!=key)
        tempd=tempd->next;
    if(c%2==0)
        {
        printf("\n-> Your staion\t      : %s",tempd->pf.station);
        c++;
        }
    else
    {
        printf("\n-> Destination staion : %s",tempd->pf.station);
        c++;
    }
    return(tempd->pf.distance);
}
void price_check(double total_dist)
{
    if(total_dist>0&&total_dist<=2)
        printf("\n-> Amount to be paid  : Rs.10\n");
    else if(total_dist>2&&total_dist<=5)  
        printf("\n-> Amount to be paid  : Rs.20\n");
    else if(total_dist>5&&total_dist<=12)  
        printf("\n-> Amount to be paid  : Rs.30\n");
    else if(total_dist>12&&total_dist<=21)
        printf("\n-> Amount to be paid  : Rs.40\n");
    else if(total_dist>21&&total_dist<=35)
        printf("\n-> Amount to be paid  : Rs.50\n");
    else
    printf("Nothing");
}
void dist_time()
{
    printf("\nEnter source station id       : ");
    scanf("%d",&begin);
    printf("Enter destination station id  : ");
    scanf("%d",&end);
    int stops=abs(begin-end);
    double begind= dist_check(begin);
    double endd= dist_check(end);
    double total_dist=fabs(endd-begind);
    /*printf("->Your station:  %s",pf.station);
        printf("->Destination station:  %s",pf.station);*/

    printf("\n-> Total distance     : %.2lf Kms",total_dist);
    printf("\n-> Number of stops    : %d",stops);
    int time = stops*2;
    printf("\n-> Journey time       : %d Mins",time);
    price_check(total_dist);
}
int main()
{
    printf("\n---------------------!!!!!Namma Metro Welcomes You!!!!!---------------------\n");
    platform temp;
    FILE *fp;
    int ch;
    fp = fopen ("/Users/kshama/Documents/cp/nammametro.txt", "r+");
        while ((fread(&temp,sizeof(temp),1,fp))!=0)
        {
                        insert_rear(temp);
        }
    fclose(fp);   
    while(1)
    {
            printf("\nEnter\t1 for Map display\n\t2 for Station ID's\n\t3 for details of travel\n\t4 to exit\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n--------------------------------Route Map--------------------------------\n");
                    display_map();
                    break;
            case 2: printf("\n--------------------------------Station Details--------------------------------\n");
                    fp = fopen ("/Users/kshama/Documents/cp/nammametro.txt", "r+");
                    printf("\nDETAILS:\n");
                    printf("\nSTATION ID\tSTATION NAME\t\t  DISTANCE\n\n");
                    while ((fread(&temp,sizeof(temp),1,fp))!=0)
                    {
                        //printf("\n");
                        printf("%-16d",temp.station_id);
                        //printf("\n");
                        printf("%-26s",temp.station);
                        //printf("\n");
                        printf("%-10.2lf",temp.distance);
                        printf("\n");
                    }
                    fclose(fp);
                    break; 
            case 3: printf("\n--------------------------------Your Journey Plan--------------------------------\n");
                    dist_time();
                    break;
            case 4:exit(1);
            default: printf("Wrong choice...Please try again!!!\n");
                    break;
        }   
    }
}

