#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct team_info //define team information structure for all divisions//
{
    char team[50];
    char venue[50];
    char convenor[50];
    int played;
    int won;
    int lost;
    int points;
};

struct player_info  //define player information structure for all divisions//
{
    char team_name[50];
    int hksnum;
    char player_name[50];
    float average_points;
    int total_points;
    int played;
    int won;
    int lost;
};

struct schedule  //define schedule information structure for all divisions//
{
    int week;
    char team1[50];
    char team2[50];
    char place[50];
    char time[5];
    char team1player1[50];
    char team1player2[50];
    char team1player3[50];
    char team2player1[50];
    char team2player2[50];
    char team2player3[50];
    char homeoraway[10];
    char result1[10];
    char result2[10];
    char result3[10];
};

//The main function is to display welcome screen and identity declaration interface//
int main()
{
    char i[10];
    int n=0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t****************************************************************************************\n");
    printf("\t\t******************           Welcome to Squash league system !           ***************\n");
    printf("\t\t****************************************************************************************\n\n\n\n\n\n\n\n");
	printf("\n\n\n\t\t\t\t\t\t\t\tPress any key to continue...");
	getch();
	system("cls");
    while(n==0)
    {
        fflush(stdin);
        printf("\n\n\t:::::::::::::::::::::::::::::::::::\n");
        printf("\t:::::::IDENTITY CONFIRMATION:::::::\n");
        printf("\t:::::::::::::::::::::::::::::::::::");
        printf("\n\n\n\n\n\n\n\n\nPlease state your identity (admin/guest): ");
        scanf("%s",&i);
        if(strcmp(i,"admin")==0)
        {
            n=1;
            printf("\n");
            login();
        }
        if(strcmp(i,"guest")==0)
        {
            n=1;
            guest_functions();
        }
        else if(strcmp(i,"admin")!=0&&strcmp(i,"guest")!=0)
        {
            printf("\nWARNING! INVALID INPUT. PRESS ANY KEY TO TRY AGAIN.\n\n");
            getch();
            system("cls");
        }
    }
    return 0;
}

//This function is to display administrator login screen//
int login()
{
    system("cls");
    char password[] = "1234",c=' ',enter[50];
    int flag=0,i=0;
    printf("\n\n\t:::::::::::::::::::::::::::::::::::\n");
    printf("\t:::::::::ADMIN LOGIN SCREEN::::::::\n");
    printf("\t:::::::::::::::::::::::::::::::::::");
    while (flag == 0)
    {
        fflush(stdin);
        printf("\n\n\n\n\nEnter password:"); //password is 1234//
        while(i<4)
        {
	    enter[i]=getch();
	    c=enter[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
        }
        enter[i]='\0';
        i=0;
        if (strcmp(enter,password)==0)
            {
                flag = 1;
                system("cls");
                printf("\n\n\t:::::::::::::::::::::::::::::::::::\n");
                printf("\t:::::::::::LOGIN SUCCESSFUL::::::::\n");
                printf("\t:::::::::::::::::::::::::::::::::::\n\n\n\n\n");
                printf("Press any key to continue....");
                getch();
                admin_functions();
            }
        if (strcmp(enter,password)!= 0)
            printf("\nWARNING! Wrong password, please enter again.\n");
    }
    return 0;
}

//This function is to let the guest choose the division that they want to enter//
int guest_functions()
{
    fflush(stdin);
    system("cls");
    int ch;
    printf("\n\n\t::::::DIVISION SELECTOR::::::\n\n");
    printf("\n\n\tPLEASE SELECT DIVISION\n\n");
    printf("\tPress <1> To DIVISION 1\n");
    printf("\tPress <2> To EXIT\n");
    printf("\nENTER YOUR CHOICE:  ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:
            gdivision1();
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\tTHANK YOU FOR USING THE SOFTWARE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
            break;
        default:
            printf("\nYOU ENTERED WRONG CHOICE..");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            system("cls");
            guest_functions();
            break;
        }
        return 0;
}

//This function is to let the administrator choose the division that they want to enter//
int admin_functions()
{
    int ch;
    fflush(stdin);
    system("cls");
    printf("\n\n\t::::::MAIN MENU::::::\n\n");
    printf("\n\n\tPLEASE SELECT DIVISION\n\n");
    printf("\tPress <1> To DIVISION 1\n");
    printf("\tPress <2> To EXIT\n");
    printf("\nENTER YOUR CHOICE:  ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:
            adivision1();
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\tTHANK YOU FOR USING THE SOFTWARE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
            break;
        default:
            printf("\nYOU ENTERED WRONG CHOICE..");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            admin_functions();
            break;
        }
        system("cls");
        return 0;
}

//This function is to let the guest user choose the actions that they want to perform within Division 1//
int gdivision1()
{
    fflush(stdin);
    system("cls");
    int ch;
    printf("\n\n\t::::::FUNCTIONS SELECTOR::::::\n\n");
    printf("\tPress <1> To VIEW Team list\n");
    printf("\tPress <2> To VIEW Player list\n");
    printf("\tPress <3> To VIEW Schedule and Match Results\n");
    printf("\tPress <4> To VIEW Team Summary\n");
    printf("\tPress <5> To VIEW Divisional Ranking\n");
    printf("\tPress <6> To RETURN Division selector\n");
    printf("\tPress <7> To EXIT\n");
    printf("\nENTER YOUR CHOICE:  ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:
            viewteamlist1guest();
            break;
        case 2:
            viewplayerlist1guest();
            break;
        case 3:
            viewscheduleandresultguest1();
            break;
        case 4:
            viewteamsummary1guest();
            break;
        case 5:
            viewdivisionalranking1guest();
        case 6:
            guest_functions();
        case 7:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\tTHANK YOU FOR USING THE SOFTWARE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
        default:
            printf("\nINVALID INPUT");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            system("cls");
            gdivision1();
            break;
        }
        system("cls");
        return 0;
}

//This function is to let the administrator choose the actions that they want to perform within Division 1//
int adivision1()
{
    fflush(stdin);
    system("cls");
    struct schedule s[100];
    int y=0,a=0,count=0,f,ch,weekdelete,e;
    char teamdelete[50],yesorno[5],x[50];
    FILE *z=fopen("schedule1.txt","r");
    while(fscanf(z,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[y].week,&s[y].place,&s[y].time,&s[y].result1,&s[y].result2,&s[y].result3,&s[y].team1,&s[y].team1player1,&s[y].team1player2,&s[y].team1player3,&s[y].team2,&s[y].team2player1,&s[y].team2player2,&s[y].team2player3)!=EOF)
    {
        y++;
    }
    printf("\n\n\t::::::FUNCTIONS SELECTOR::::::\n\n");
    printf("\tPress <1> To ACCESS Team list\n");
    printf("\tPress <2> To ACCESS Player list\n");
    printf("\tPress <3> To ACCESS Schedule and Match Results\n");
    printf("\tPress <4> To VIEW Team Summary\n");
    printf("\tPress <5> To VIEW Divisional Ranking\n");
    printf("\tPress <6> To RETURN Division selector\n");
    printf("\tPress <7> To EXIT\n");
    printf("\nENTER YOUR CHOICE:  ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:
            system("cls");
            printf("\n\n\n\n\tPress <1> To VIEW Team list\n");
            printf("\tPress <2> To ADD NEW team\n");
            printf("\tPress <3> To MODIFY Team information\n");
            printf("\tPress <4> To RETURN Functions Selector\n");
            printf("\nENTER YOUR CHOICE:  ");
            scanf("%d",&f);
            switch(f)
            {
                case 1:
                    viewteamlist1admin();
                    break;
                case 2:
                    addteam1();
                    break;
                case 3:
                    modifyteaminfo1();
                    break;
                case 4:
                    adivision1();
                    break;
                default:
                    printf("\nINVALID INPUT");
                    printf("\nPRESS ANY KEY TO TRY AGAIN");
                    getch();
                    adivision1();
                    break;
            }
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\tPress <1> To VIEW Player list\n");
            printf("\tPress <2> To ADD NEW player\n");
            printf("\tPress <3> To MODIFY Player information\n");;
            printf("\tPress <4> To RETURN Functions Selector\n");
            printf("\nENTER YOUR CHOICE:  ");
            scanf("%d",&f);
            switch(f)
            {
                case 1:
                    viewplayerlist1admin();
                    break;
                case 2:
                    addplayer1();
                    break;
                case 3:
                    modifyplayerinfo1();
                    break;
                case 4:
                    adivision1();
                    break;
                default:
                    printf("\nINVALID INPUT");
                    printf("\nPRESS ANY KEY TO TRY AGAIN");
                    getch();
                    adivision1();
                    break;
            }
            break;
        case 3:
            system("cls");
            printf("\n\n\n\n\tPress <1> To VIEW Schedule and Match Results\n");
            printf("\tPress <2> To ADD NEW Schedule and Match Results\n");
            printf("\tPress <3> To MODIFY Match Results\n");
            printf("\tPress <4> To DELETE Schedule and Match Results\n");
            printf("\tPress <5> To RETURN Functions Selector\n");
            printf("\nENTER YOUR CHOICE:  ");
            scanf("%d",&f);
            switch(f)
            {
                case 1:
                    viewscheduleandresultadmin1();
                    break;
                case 2:
                    addscheduleandresult1();
                    break;
                case 3:
                    modifyscheduleandresult1();
                    break;
                case 4:
                    system("cls");
                    fflush(stdin);
                    printf("\n\nEnter the no. of the week of the schedule that you want to delete (1-20):  //Type '999' to go back to Function Selector// :     ");
                    scanf("%d",&weekdelete);
                    if(weekdelete==999)
                    {
                        adivision1();
                    }
                    while(!(weekdelete>0&&weekdelete<21)||checkifweekexistschedule1(weekdelete)==0)
                    {
                        if(!(weekdelete>0&&weekdelete<21))
                        {
                            printf("\nInvalid input. Please the no. of the week of the schedule that you want to delete again (1-20):  //Type '999' to go back to Function Selector// :     ");
                            fflush(stdin);
                            scanf("%d",&weekdelete);
                            if(weekdelete==999)
                            {
                                adivision1();
                            }
                        }
                        if(checkifweekexistschedule1(weekdelete)==0)
                        {
                            printf("\nWeek %d does not have any matches scheduled. Enter the no. of the week of the schedule that you want to delete (1-20):  //Type '999' to go back to Function Selector// :     ",weekdelete);
                            fflush(stdin);
                            scanf("%d",&weekdelete);
                            if(weekdelete==999)
                            {
                                adivision1();
                            }
                        }
                        if(weekdelete==999)
                        {
                            adivision1();
                        }
                    }
                    system("cls");
                    printf("\n\nWeek %d\n",weekdelete);
                    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
                    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
                    for(a=0;a<y;a++)
                    {
                        count=0;
                        if(s[a].week==weekdelete)
                        {
                            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
                            {
                                count++;
                            }
                            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
                            {
                                count++;
                            }
                            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
                            {
                                count++;
                            }
                            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
                        }
                    }
                    fflush(stdin);
                    printf("\n\nWhich match do you want to delete? Please enter the name of one team that is involved in the match (Please use '_' to represent space between characters): ");
                    gets(teamdelete);
                    while (checkspace(teamdelete)==1||checkalreadyexist1(teamdelete)==0||checkteamalreadyexistinschedule1(weekdelete,teamdelete)==0)
                    {
                        fflush(stdin);
                        if (checkspace(teamdelete)==1||checkalreadyexist1(teamdelete)==0)
                        {
                            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
                        }
                        if (checkteamalreadyexistinschedule1(weekdelete,teamdelete)==0&&!(checkspace(teamdelete)==1||checkalreadyexist1(teamdelete)==0))
                        {
                            printf("\n\n\nWARNING! %s is not scheduled for Week %d!!",teamdelete,weekdelete);
                        }
                        printf("\n\nEnter enter the name of one team that is involved in the match AGAIN! (Please use '_' to represent space between characters): ");
                        gets(teamdelete);
                    }
                    fflush(stdin);
                    printf("\nRecord located. Are you sure you want to delete? (Y/N): ");
                    gets(yesorno);
                    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
                    {
                        fflush(stdin);
                        printf("\nInvalid Input! Are you sure you want to delete? (Y/N) ");
                        gets(yesorno);
                    }
                    for (e=0;e<strlen(teamdelete);e++)
                    {
                        x[e]=toupper(teamdelete[e]);
                    }
                    if(strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0)
                    {
                        deletemarksandschedule1(weekdelete,x);
                        printf("\n\nRecord Updated.\n\nPress any key to go back to Functions selector......");
                        getch();
                        adivision1();
                    }
                    else
                    {
                        fflush(stdin);
                        printf("\n\n\nPress any key to go back to Functions selector...");
                        getch();
                        adivision1();
                    }
                    break;
                case 5:
                    adivision1();
                    break;
                default:
                    printf("\nINVALID INPUT");
                    printf("\nPRESS ANY KEY TO TRY AGAIN");
                    getch();
                    adivision1();
                    break;
            }
            break;
        case 4:
            viewteamsummary1admin();
            break;
        case 5:
            viewdivisionalranking1admin();
        case 6:
            admin_functions();
        case 7:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\tTHANK YOU FOR USING THE SOFTWARE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
        default:
            printf("\nINVALID INPUT");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            adivision1();
            break;
        }
        system("cls");
        return 0;
}

//This function is to display the brief information of Division 1 team//
int viewteamlist1guest()
{
    int i=0;
    struct team_info division1[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    printf("\n\n\n\n\n\n%30s%30s%30s\n","Team Name","Home","Convenor");
    printf("------------------------------------------------------------------------------------------\n");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        printf("%30s%30s%30s\n",division1[i].team,division1[i].venue,division1[i].convenor);
        i++;
    }
    fclose(f);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    gdivision1();
}

int viewteamlist1admin()
{
    int i=0;
    struct team_info division1[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    printf("\n\n\n\n\n\n%30s%30s%30s\n","Team Name","Home","Convenor");
    printf("------------------------------------------------------------------------------------------\n");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        printf("%30s%30s%30s\n",division1[i].team,division1[i].venue,division1[i].convenor);
        i++;
    }
    fclose(f);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}
//This function is to retrieve Division 1 team information from the file//
int viewteamsummary1guest()
{
    int i=0,a;
    struct team_info division1[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        i++;
    }
    fclose(f);
    printf("\n\n\n\n\n\n%30s%15s%15s%15s%15s\n","Team Name","Played","Won","Lost","Points");
    printf("------------------------------------------------------------------------------------------\n");
    sortteamrank(i,division1);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    gdivision1();
}

int viewteamsummary1admin()
{
    int i=0;
    struct team_info division1[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        i++;
    }
    fclose(f);
    printf("\n\n\n\n\n\n%30s%15s%15s%15s%15s\n","Team Name","Played","Won","Lost","Points");
    printf("------------------------------------------------------------------------------------------\n");
    sortteamrank(i,division1);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}
//This function is to sort and display the teams from all divisions in ascending order of their marks//
void sortteamrank(int a, struct team_info* str)
{
    int i,j,k;
    struct team_info temp;
    for (i=1;i<=a-1;i++)
    {for (j=1;j<=a-i;j++)
        {
            if (str[j-1].points<str[j].points)
            {
            temp=str[j];
            str[j]=str[j-1];
            str[j-1]=temp;
            }
        }
    }
    for (k=0;k<a;k++)
    {
        printf("%30s%15d%15d%15d%15d\n",str[k].team,str[k].played,str[k].won,str[k].lost,str[k].points);
    }
}

void viewdivisionalranking1admin()
{
    int j=0,x=0,y=0,i=0,k=0;
    struct player_info p[50];
    struct player_info a[50];
    struct player_info b[50];
    struct player_info temp;
    system("cls");
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for(x=0;x<j;x++)
    {
        if(p[x].played>=5)
        {
            a[i]=p[x];
            a[i].average_points=((float)(p[x].total_points)/(p[x].played));
            i++;
        }
        else if (p[x].played<5)
        {
            b[k]=p[x];
            if(p[x].played>0)
            {
                b[k].average_points=(float)(p[x].total_points)/(p[x].played);
            }
            else
            {
                b[k].average_points=0.0;
            }
            k++;
        }
    }
    for(x=1;x<i;x++)
    {
        for(y=1;y<=i-x;y++)
        {
            if (a[y-1].average_points<a[y].average_points)
            {
            temp=a[y];
            a[y]=a[y-1];
            a[y-1]=temp;
            }
        }
    }
    for(x=1;x<k;x++)
    {
        for(y=1;y<=k-x;y++)
        {
            if (b[y-1].average_points<b[y].average_points)
            {
            temp=b[y];
            b[y]=b[y-1];
            b[y-1]=temp;
            }
        }
    }
    printf("\n\n\n\n\n\t%-10s%-30s%-30s%-20s%-20s%-17s%-5s%-5s\n","Position","Name of Players","Team","Average points","Total Game Points","Games Played","Won","Lost");
    printf("\t----------------------------------------------------------------------------------------------------------------------------------------\n");
    for(x=0;x<i;x++)
    {
        printf("\t%-10d%-30s%-30s%-20.2f%-20d%-17d%-5d%-5d\n",x+1,a[x].player_name,a[x].team_name,a[x].average_points,a[x].total_points,a[x].played,a[x].won,a[x].lost);
    }
    printf("\n\n\tFOLLOWING PLAYERS HAVE PLAYED LESS THAN 5 MATCHES AND WOULD NOT BE INCLUDED IN THE DIVISIONAL RANKING:\n\n");
    printf("\t%-10s%-30s%-30s%-20s%-20s%-17s%-5s%-5s\n","Position","Name of Players","Team","Average points","Total Game Points","Games Played","Won","Lost");
    printf("\t----------------------------------------------------------------------------------------------------------------------------------------\n");
    for(x=0;x<k;x++)
    {
        printf("\t%-10c%-30s%-30s%-20.2f%-20d%-17d%-5d%-5d\n",'/',b[x].player_name,b[x].team_name,b[x].average_points,b[x].total_points,b[x].played,b[x].won,b[x].lost);
    }
    fclose(fp);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

void viewdivisionalranking1guest()
{
    int j=0,x=0,y=0,i=0,k=0,c=0,d=0;
    struct player_info p[50];
    struct player_info a[50];
    struct player_info b[50];
    struct player_info temp;
    system("cls");
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for(x=0;x<j;x++)
    {
        if(p[x].played>=5)
        {
            a[i]=p[x];
            a[i].average_points=((float)(p[x].total_points)/(p[x].played));
            i++;
        }
        else if (p[x].played<5)
        {
            b[k]=p[x];
            if(p[x].played>0)
            {
                b[k].average_points=(float)(p[x].total_points)/(p[x].played);
            }
            else
            {
                b[k].average_points=0.0;
            }
            k++;
        }
    }
    for(x=1;x<i;x++)
    {
        for(y=1;y<=i-x;y++)
        {
            if (a[y-1].average_points<a[y].average_points)
            {
            temp=a[y];
            a[y]=a[y-1];
            a[y-1]=temp;
            }
        }
    }
    for(x=1;x<k;x++)
    {
        for(y=1;y<=k-x;y++)
        {
            if (b[y-1].average_points<b[y].average_points)
            {
            temp=b[y];
            b[y]=b[y-1];
            b[y-1]=temp;
            }
        }
    }
    printf("\n\n\n\n\n\t%-10s%-30s%-30s%-20s%-20s%-17s%-5s%-5s\n","Position","Name of Players","Team","Average points","Total Game Points","Games Played","Won","Lost");
    printf("\t----------------------------------------------------------------------------------------------------------------------------------------\n");
    for(x=0;x<i;x++)
    {
        printf("\t%-10d%-30s%-30s%-20.2f%-20d%-17d%-5d%-5d\n",x+1,a[x].player_name,a[x].team_name,a[x].average_points,a[x].total_points,a[x].played,a[x].won,a[x].lost);
    }
    printf("\n\n\tFOLLOWING PLAYERS HAVE PLAYED LESS THAN 5 MATCHES AND WOULD NOT BE INCLUDED IN THE DIVISIONAL RANKING:\n\n");
    printf("\t%-10s%-30s%-30s%-20s%-20s%-17s%-5s%-5s\n","Position","Name of Players","Team","Average points","Total Game Points","Games Played","Won","Lost");
    printf("\t----------------------------------------------------------------------------------------------------------------------------------------\n");
    for(x=0;x<k;x++)
    {
        printf("\t%-10c%-30s%-30s%-20.2f%-20d%-17d%-5d%-5d\n",'/',b[x].player_name,b[x].team_name,b[x].average_points,b[x].total_points,b[x].played,b[x].won,b[x].lost);
    }
    fclose(fp);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    gdivision1();
}

int addteam1()
{
    fflush(stdin);
    system("cls");
    int k=0,j=0,a=0;
    char newteam[50],newvenue[50],newconvenor[50],*z,*b,*c,*d,*e,*y;
    FILE *f=fopen("team_division1.txt","a");
    printf("\n\n\n\nEnter new team name (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   " );
    gets(newteam);
    if(strcmp(newteam,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(newteam)==1||checkalreadyexist1(newteam)==1)
    {
        fflush(stdin);
        if (checkspace(newteam)==1)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
        }
        else if (checkalreadyexist1(newteam)==1)
        {
            printf("\n\n\nWARNING! TEAM ALREADY EXISTS!!");
        }
        printf("\nEnter new team name AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   " );
        gets(newteam);
        if(strcmp(newteam,"exit")==0)
        {
            adivision1();
        }
    }
    printf("\n\n\n\nEnter Home Venue for the new team (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(newvenue);
    if(strcmp(newvenue,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(newvenue)==1)
    {
        fflush(stdin);
        printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
        printf("\nEnter Home Venue for the new team AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   " );
        gets(newvenue);
        if(strcmp(newvenue,"exit")==0)
        {
            adivision1();
        }
    }
    printf("\n\n\n\nEnter Convenor for the new team (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(newconvenor);
    if(strcmp(newconvenor,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(newconvenor)==1)
    {
        fflush(stdin);
        printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
        printf("\nEnter Convenor for the new team AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   " );
        gets(newconvenor);
        if(strcmp(newconvenor,"exit")==0)
        {
            adivision1();
        }
    }
    printf("\n\n\n\nNEW TEAM IS ADDED TO THE LIST!\n------------------------------------------------");
    while(newteam[a]!='\0')
    {
        newteam[a]=toupper(newteam[a]);
        a++;
    }
    printf("\nNEW Team name: %s",newteam);
    while(newvenue[k]!='\0')
    {
        newvenue[k]=toupper(newvenue[k]);
        k++;
    }
    printf("\nNEW Team Home Venue: %s",newvenue);
    while(newconvenor[j]!='\0')
    {
        newconvenor[j]=toupper(newconvenor[j]);
        j++;
    }
    printf("\nNew Team Convenor: %s\n------------------------------------------------",newconvenor);
    z = strcat(newteam," ");
    b = strcat(z,newvenue);
    c = strcat(b," ");
    d = strcat(c,newconvenor);
    e = strcat(d,"\t");
    y = strcat(e,"0\t0\t0\t0\n");
    fputs(y,f);
    fclose(f);
    printf("\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

int checkspace(char s[])
{
    int i=0,f=0;
    while(s[i]!='\0'&&f==0)
    {
        if(s[i]!=' ')
            i++;
        else if(s[i]==' ')
            f=1;
    }
    return f;
}

int checkalreadyexist1(char s[])
{
    int i=0,f=0,j=0,k=0;
    char x[50]="";
    struct team_info division1[50];
    FILE *fp=fopen("team_division1.txt","r");
    while (fscanf(fp,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        i++;
    }
    for (k=0;k<strlen(s);k++)
        x[k]=toupper(s[k]);
    while(f==0&&j<i)
    {
        if(strcmp(x,division1[j].team)!=0)
            j++;
        else
            f=1;
    }
    return f;
}

int viewplayerlist1admin()
{
    int i=0,j=0,k=0,a=0,order=1,rank=0;
    float average_points;
    struct team_info t[50];
    struct player_info p[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&t[i].team,&t[i].venue,&t[i].convenor,&t[i].played,&t[i].won,&t[i].lost,&t[i].points)!=EOF)
    {
        i++;
    }
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for(k=0;k<i;k++)
    {
        order=1;
        printf("\n\n\t\t\t\t\t\t%-20s%s","Team name:",t[k].team);
        printf("\n\t\t\t\t\t\t%-20s%s","Convener:",t[k].convenor);
        printf("\n\t\t\t\t\t\t%-20s%s","Effective Date:","06/10/2018");
        printf("\n\t\t\t\t\t\t------------------------------------------------------------------");
        printf("\n\t\t\t\t\t\t%-10s%-10s%-30s%-10s%-10s","Order","HKS No.","Name of PLayers","Ranking","Points");
        printf("\n\t\t\t\t\t\t------------------------------------------------------------------");
        for(a=0;a<j;a++)
        {
            if(strcmp(t[k].team,p[a].team_name)==0)
            {
                if(p[a].played>0)
                {
                    average_points=(float)(p[a].total_points)/(p[a].played);
                }
                else
                {
                    average_points=0;
                }
                if(p[a].played>=5)
                {
                    rank=getplayerrank1(p[a].player_name);
                }
                else
                {
                    rank=0;
                }
                printf("\n\t\t\t\t\t\t%-10d%-10d%-30s%-10d%-10.2f",order,p[a].hksnum,p[a].player_name,rank,average_points);
                order++;
            }
        }
    printf("\n\n");
    }
    fclose(f);
    fclose(fp);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

int viewplayerlist1guest()
{
    int i=0,j=0,k=0,a=0,order=1,rank=0;
    float average_points;
    struct team_info t[50];
    struct player_info p[50];
    system("cls");
    FILE *f=fopen("team_division1.txt","r");
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&t[i].team,&t[i].venue,&t[i].convenor,&t[i].played,&t[i].won,&t[i].lost,&t[i].points)!=EOF)
    {
        i++;
    }
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for(k=0;k<i;k++)
    {
        order=1;
        printf("\n\n\t\t\t\t\t\t%-20s%s","Team name:",t[k].team);
        printf("\n\t\t\t\t\t\t%-20s%s","Convener:",t[k].convenor);
        printf("\n\t\t\t\t\t\t%-20s%s","Effective Date:","06/10/2018");
        printf("\n\t\t\t\t\t\t------------------------------------------------------------------");
        printf("\n\t\t\t\t\t\t%-10s%-10s%-30s%-10s%-10s","Order","HKS No.","Name of PLayers","Ranking","Points");
        printf("\n\t\t\t\t\t\t------------------------------------------------------------------");
        for(a=0;a<j;a++)
        {
            if(strcmp(t[k].team,p[a].team_name)==0)
            {
                if(p[a].played>0)
                {
                    average_points=(float)(p[a].total_points)/(p[a].played);
                }
                else
                {
                    average_points=0;
                }
                if(p[a].played>=5)
                {
                    rank=getplayerrank1(p[a].player_name);
                }
                else
                {
                    rank=0;
                }
                printf("\n\t\t\t\t\t\t%-10d%-10d%-30s%-10d%-10.2f",order,p[a].hksnum,p[a].player_name,rank,average_points);
                order++;
            }
        }
    printf("\n\n");
    }
    fclose(f);
    fclose(fp);
    printf("\n\n\n\n\n\n\n\nPress any key to go back to Functions selector...");
    getch();
    gdivision1();
}

void addplayer1()
{
    fflush(stdin);
    system("cls");
    int j=0,a=0,newhksnum;
    char team[50],newplayer[50],t[50],n[50];
    FILE *f=fopen("player_division1.txt","a");
    printf("\n\n\n\nEnter the name of the new player (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(newplayer);
    if(strcmp(newplayer,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(newplayer)==1||checkplayeralreadyexist1(newplayer)==1)
    {
        fflush(stdin);
        if (checkspace(newplayer)==1)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
        }
        if (checkplayeralreadyexist1(newplayer)==1)
        {
            printf("\n\n\nWARNING! PLAYER ALREADY EXISTS!!");
        }
        printf("\nEnter the name of the new player AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(newplayer);
        if(strcmp(newplayer,"exit")==0)
        {
            adivision1();
        }
    }
    printf("\n\n\n\nEnter the team name of the new player (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(team);
    if(strcmp(team,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(team)==1||checkalreadyexist1(team)==0)
    {
        fflush(stdin);
        if (checkspace(team)==1)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
        }
        if (checkalreadyexist1(team)==0)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE DOES NOT EXIST!!");
        }
        printf("\nEnter the team name of the new player AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(team);
        if(strcmp(team,"exit")==0)
        {
            adivision1();
        }
    }
    printf("\n\n\n\nEnter new HKS Number for the new player (Please enter a value between 10000 and 99999 inclusively): ");
    scanf("%d",&newhksnum);
    while (newhksnum<10000||newhksnum>99999||checkahksnumalreadyexist1(newhksnum)==1)
    {
        fflush(stdin);
        if(newhksnum<10000||newhksnum>99999)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE IS INVALID!!");
        }
        if(checkahksnumalreadyexist1(newhksnum)==1)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE ALREADY EXIST!!");
        }
        printf("\nEnter new HKS Number for the new player AGAIN! (Please enter a value between 10000 and 99999 inclusively): ");
        scanf("%d",&newhksnum);
    }
    printf("\n\n\n\nNEW PLAYER IS ADDED TO THE LIST!\n------------------------------------------------");
    for(a=0;a<=strlen(team);a++)
    {
        t[a]=toupper(team[a]);
    }
    for(j=0;j<=strlen(newplayer);j++)
    {
        n[j]=toupper(newplayer[j]);
    }
    printf("\nTeam of the new player: %s",t);
    printf("\nHKS Number of the new player: %d",newhksnum);
    printf("\nName of the new player: %s\n------------------------------------------------",n);
    strcat(n,"\t");
    fprintf(f,"%s %d\t%s0\t0\t0\t0\n",t,newhksnum,n);
    fclose(f);
    printf("\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

int checkahksnumalreadyexist1(int x)
{
    int i=0,f=0,j=0,k=0;
    struct player_info p[50];
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    while(f==0&&i<j)
    {
        if(x!=p[i].hksnum)
            i++;
        else
            f=1;
    }
    return f;
}

int checkplayeralreadyexist1(char s[])
{
    int i=0,f=0,j=0,k=0;
    char x[50]="";
    struct player_info p[50];
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for (k=0;k<strlen(s);k++)
        x[k]=toupper(s[k]);
    while(f==0&&i<j)
    {
        if(strcmp(x,p[i].player_name)!=0)
            i++;
        else
            f=1;
    }
    return f;
}

int modifyteaminfo1()
{
    fflush(stdin);
    int i=0,k=0;
    char findteam[50]="",yesorno1[5],yesorno2[5],newconvenor[50]="",newhomevenue[50]="",x[50]="",y[50]="";
    struct team_info t[50];
    system("cls");
    FILE *a=fopen("team_division1.txt","r");
    while (fscanf(a,"%s %s %s\t%d\t%d\t%d\t%d",&t[i].team,&t[i].venue,&t[i].convenor,&t[i].played,&t[i].won,&t[i].lost,&t[i].points)!=EOF)
    {
        i++;
    }
    fclose(a);
    printf("\n\nEnter the name of the team that you want to modify its information (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(findteam);
    if(strcmp(findteam,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(findteam)==1||checkalreadyexist1(findteam)==0)
    {
        fflush(stdin);
        if (checkspace(findteam)==1||checkalreadyexist1(findteam)==0)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
        }
        printf("\nEnter the name of the team that you want to modify its information AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(findteam);
        if(strcmp(findteam,"exit")==0)
        {
            adivision1();
        }
    }
    fflush(stdin);
    printf("\n\nChange the name of team convenor? (Y/N) ");
    gets(yesorno1);
    while(strcmp(yesorno1,"Y")!=0&&strcmp(yesorno1,"N")!=0&&strcmp(yesorno1,"y")!=0&&strcmp(yesorno1,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the name of team convenor? (Y/N) ");
        gets(yesorno1);
    }
    if(strcmp(yesorno1,"Y")==0||strcmp(yesorno1,"y")==0)
    {
        printf("\n\nEnter the new name of team convenor (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(newconvenor);
        if(strcmp(newconvenor,"exit")==0)
        {
            adivision1();
        }
        while (checkspace(newconvenor)==1)
        {
            fflush(stdin);
            if (checkspace(newconvenor)==1)
            {
                printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
            }
            printf("\nEnter the new name of team convenor AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
            gets(newconvenor);
            if(strcmp(newconvenor,"exit")==0)
            {
                adivision1();
            }
        }
        for (k=0;k<strlen(newconvenor);k++)
        {
            x[k]=toupper(newconvenor[k]);
        }
        strcpy(t[findteampositionbyname1(findteam)].convenor,x);
    }
    fflush(stdin);
    printf("\n\nChange the name of home venue? (Y/N) ");
    gets(yesorno2);
    while(strcmp(yesorno2,"Y")!=0&&strcmp(yesorno2,"N")!=0&&strcmp(yesorno2,"y")!=0&&strcmp(yesorno2,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the name of team convenor? (Y/N) ");
        gets(yesorno2);
    }
    if(strcmp(yesorno2,"Y")==0||strcmp(yesorno2,"y")==0)
    {
        printf("\n\nEnter the new name of home venue (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(newhomevenue);
        if(strcmp(newhomevenue,"exit")==0)
        {
            adivision1();
        }
        while (checkspace(newhomevenue)==1)
        {
            fflush(stdin);
            if (checkspace(newhomevenue)==1)
            {
                printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
            }
            printf("\nEnter the new name of home venue AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
            gets(newhomevenue);
            if(strcmp(newhomevenue,"exit")==0)
            {
                adivision1();
            }
        }
        for (k=0;k<strlen(newhomevenue);k++)
        {
            y[k]=toupper(newhomevenue[k]);
        }
        strcpy(t[findteampositionbyname1(findteam)].venue,y);
    }
    if((strcmp(yesorno1,"N")==0||strcmp(yesorno1,"n")==0)&&(strcmp(yesorno2,"n")==0||strcmp(yesorno2,"N")==0))
    {
        printf("\n\nNothing has been modified.");
    }
    else
    {
        printf("\n\n--------------\nRECORD UPDATED\n--------------");
    }
    FILE *b=fopen("team_division1.txt","w");
    for(k=0;k<i;k++)
    {
        fprintf(b,"%s %s %s\t%d\t%d\t%d\t%d\n",t[k].team,t[k].venue,t[k].convenor,t[k].played,t[k].won,t[k].lost,t[k].points);
    }
    fclose(b);
    printf("\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

int modifyplayerinfo1()
{
    int newhksnum=0,k=0,j=0;
    char yesorno[5],findplayer[50];
    system("cls");
    fflush(stdin);
    struct player_info p[50];
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    fclose(fp);
    printf("\n\nEnter the name of the player that you want to modify his information (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
    gets(findplayer);
    if(strcmp(findplayer,"exit")==0)
    {
        adivision1();
    }
    while (checkspace(findplayer)==1||checkplayeralreadyexist1(findplayer)==0)
    {
        fflush(stdin);
        if (checkspace(findplayer)==1||checkplayeralreadyexist1(findplayer)==0)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
        }
        printf("\nEnter the name of the player that you want to modify his information AGAIN! (Please use '_' to represent space between characters) //Type 'exit' to go back to Function Selector//:   ");
        gets(findplayer);
        if(strcmp(findplayer,"exit")==0)
        {
            adivision1();
        }
    }
    newhksnum=p[findplayerpositionbyname1(findplayer)].hksnum;
    fflush(stdin);
    printf("\n\nChange the HKS Number for the new player? (Y/N) ");
    gets(yesorno);
    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the HKS Number for the new player? (Y/N) ");
        gets(yesorno);
    }
    if((strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0))
    {
        fflush(stdin);
        printf("\n\nEnter new HKS Number for the new player (Please enter a value between 10000 and 99999 inclusively): ");
        scanf("%d",&newhksnum);
        while (newhksnum<10000||newhksnum>99999||checkahksnumalreadyexist1(newhksnum)==1||p[findplayerpositionbyname1(findplayer)].hksnum==newhksnum)
        {
            fflush(stdin);
            if(newhksnum<10000||newhksnum>99999)
            {
                printf("\n\n\nWARNING! INPUTTED VALUE IS INVALID!!");
            }
            if(p[findplayerpositionbyname1(findplayer)].hksnum==newhksnum&&checkahksnumalreadyexist1(newhksnum)==1)
            {
                printf("\n\n\nWARNING! INPUTTED VALUE IS THE SAME AS BEFORE!!");
            }
            if(checkahksnumalreadyexist1(newhksnum)==1&&p[findplayerpositionbyname1(findplayer)].hksnum!=newhksnum)
            {
                printf("\n\n\nWARNING! INPUTTED VALUE ALREADY EXIST!!");
            }
            printf("\nEnter new HKS Number for the new player AGAIN! (Please enter a value between 10000 and 99999 inclusively): ");
            scanf("%d",&newhksnum);
        }
    }
    p[findplayerpositionbyname1(findplayer)].hksnum=newhksnum;
    if((strcmp(yesorno,"N")==0||strcmp(yesorno,"n")==0))
    {
        printf("\n\nNothing has been modified.");
    }
    else
    {
        printf("\n\n--------------\nRECORD UPDATED\n--------------");
    }
    FILE *b=fopen("player_division1.txt","w");
    for(k=0;k<j;k++)
    {
        fprintf(b,"%s %d\t%s\t%d\t%d\t%d\t%d\n",p[k].team_name,p[k].hksnum,p[k].player_name,p[k].total_points,p[k].played,p[k].won,p[k].lost);
    }
    fclose(b);
    printf("\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

int addscheduleandresult1()
{
    system("cls");
    struct team_info d1[50];
    struct player_info p[50];
    FILE *f=fopen("team_division1.txt","r");
    FILE *fp=fopen("player_division1.txt","r");
    FILE *s=fopen("schedule1.txt","a");
    int week,i=0,j=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
    char t1[50],t1p1[50],t1p2[50],t1p3[50],t2[50],t2p1[50],t2p2[50],t2p3[50],bigvenue[50],x[50],team1[50],team2[50],place[50],time[5],team1player1[50],team1player2[50],team1player3[50],team2player1[50],team2player2[50],team2player3[50],homeoraway[10],result1[10],result2[10],result3[10];
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&d1[i].team,&d1[i].venue,&d1[i].convenor,&d1[i].played,&d1[i].won,&d1[i].lost,&d1[i].points)!=EOF)
    {
        i++;
    }
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    printf("\n\nEnter week (1-20)  //Type '999' to go back to Function Selector// :    ");
    scanf("%d",&week);
    if(week==999)
    {
        adivision1();
    }
    while(!(week>0&&week<21)&&week!=999)
          {
              if (!(week>0&&week<21))
              {
                printf("\nInvalid input. Please enter week no. of the match again  //Type '999' to go back to Function Selector// :    ");
                fflush(stdin);
                scanf("%d",&week);
              }
              if(week==999)
                {
                    adivision1();
                }
          }
    fflush(stdin);
    printf("\n\nHome or away match (home/away) //Type 'exit' to go back to Function Selector//:   ");
    gets(homeoraway);
    if(strcmp(homeoraway,"exit")==0)
    {
        adivision1();
    }
    while(strcmp(homeoraway,"home")!=0&&strcmp(homeoraway,"away")!=0)
          {
              fflush(stdin);
              printf("\nInvalid input. Please state whether the match is home or away match again (home/away) //Type 'exit' to go back to Function Selector//:   ");
              gets(homeoraway);
              if(strcmp(homeoraway,"exit")==0)
                {
                    adivision1();
                }
          }
    fflush(stdin);
    if(strcmp(homeoraway,"home")==0)
       {
            printf("\n\nEnter the name of HOME team (Please use '_' to represent space between characters): ");
            gets(team1);
            for (a1=0;a1<strlen(team1);a1++)
            {
                t1[a1]=toupper(team1[a1]);
            }
            strcpy(team1,t1);
            while (checkspace(team1)==1||checkalreadyexist1(team1)==0||checkteamalreadyexistinschedule1(week,team1)==1)
            {
                fflush(stdin);
                if (checkspace(team1)==1||checkalreadyexist1(team1)==0)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
                }
                if (checkteamalreadyexistinschedule1(week,team1)==1)
                {
                    printf("\n\n\nWARNING! %s already scheduled for Week %d!!",team1,week);
                }
                printf("\n\nEnter enter the name of HOME team AGAIN! (Please use '_' to represent space between characters): ");
                gets(team1);
                for (a1=0;a1<strlen(team1);a1++)
                {
                    t1[a1]=toupper(team1[a1]);
                }
                strcpy(team1,t1);
            }
            fflush(stdin);
            strcpy (place,d1[findteampositionbyname1(team1)].venue);
            strcpy (x,place);
            printf("\n\nEnter the name of AWAY team (Please use '_' to represent space between characters): ");
            gets(team2);
            for (a5=0;a5<strlen(team2);a5++)
            {
                t2[a5]=toupper(team2[a5]);
            }
            strcpy(team2,t2);
            while (checkspace(team2)==1||checkalreadyexist1(team2)==0||checkteamalreadyexistinschedule1(week,team2)==1||strcmp(team1,team2)==0)
            {
                fflush(stdin);
                if (checkspace(team2)==1||checkalreadyexist1(team2)==0)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
                }
                if (checkteamalreadyexistinschedule1(week,team2)==1)
                {
                    printf("\n\n\nWARNING! %s already scheduled for Week %d!!",team2,week);
                }
                if (strcmp(team1,team2)==0)
                {
                    printf("\n\n\nWARNING! AWAY team cannot be the same as HOME team!");
                }
                printf("\n\nEnter enter the name of AWAY team AGAIN! (Please use '_' to represent space between characters): ");
                gets(team2);
                for (a5=0;a5<strlen(team2);a5++)
                {
                    t2[a5]=toupper(team2[a5]);
                }
                strcpy(team2,t2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of HOME team in the 1st match (Please use '_' to represent space between characters): ");
            gets(team1player1);
            while (checkspace(team1player1)==1||checkifplayerexistinspecificteam1(team1player1,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player1)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player1,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the home team!!");
                }
                printf("\nEnter the player name of HOME team in the 1st match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player1);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of AWAY team in the 1st match (Please use '_' to represent space between characters): ");
            gets(team2player1);
            while (checkspace(team2player1)==1||checkifplayerexistinspecificteam1(team2player1,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player1)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player1,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the away team!!");
                }
                printf("\nEnter the player name of AWAY team in the 1st match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player1);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of HOME team in the 2nd match (Please use '_' to represent space between characters): ");
            gets(team1player2);
            while (checkspace(team1player2)==1||checkifplayerexistinspecificteam1(team1player2,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player2)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player2,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the home team!!");
                }
                printf("\nEnter the player name of HOME team in the 2nd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of AWAY team in the 2nd match (Please use '_' to represent space between characters): ");
            gets(team2player2);
            while (checkspace(team2player2)==1||checkifplayerexistinspecificteam1(team2player2,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player2)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player2,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the away team!!");
                }
                printf("\nEnter the player name of AWAY team in the 2nd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of HOME team in the 3rd match (Please use '_' to represent space between characters): ");
            gets(team1player3);
            while (checkspace(team1player3)==1||checkifplayerexistinspecificteam1(team1player3,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player3)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player3,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the home team!!");
                }
                printf("\nEnter the player name of HOME team in the 3rd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player3);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of AWAY team in the 3rd match (Please use '_' to represent space between characters): ");
            gets(team2player3);
            while (checkspace(team2player3)==1||checkifplayerexistinspecificteam1(team2player3,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player3)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player3,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in the away team!!");
                }
                printf("\nEnter the player name of AWAY team in the 3rd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player3);
            }
            fflush(stdin);
       }
       else if (strcmp(homeoraway,"away")==0)
        {
            printf("\n\nEnter the venue of the match (Please use '_' to represent space between characters): ");
            gets(place);
            while (checkspace(place)==1)
            {
                fflush(stdin);
                printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                printf("\nEnter the venue of the match AGAIN! (Please use '_' to represent space between characters): " );
                gets(place);
            }
            strcpy(x,place);
            printf("\n\nEnter the name of Team 1 (Please use '_' to represent space between characters): ");
            gets(team1);
            for (a1=0;a1<strlen(team1);a1++)
            {
                t1[a1]=toupper(team1[a1]);
            }
            strcpy(team1,t1);
            while (checkspace(team1)==1||checkalreadyexist1(team1)==0||checkteamalreadyexistinschedule1(week,team1)==1)
            {
                fflush(stdin);
                if (checkspace(team1)==1||checkalreadyexist1(team1)==0)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
                }
                if (checkteamalreadyexistinschedule1(week,team1)==1)
                {
                    printf("\n\n\nWARNING! %s already scheduled for Week %d!!",team1,week);
                }
                printf("\n\nEnter the the name of Team 1 AGAIN! (Please use '_' to represent space between characters): ");
                gets(team1);
                for (a1=0;a1<strlen(team1);a1++)
                {
                    t1[a1]=toupper(team1[a1]);
                }
                strcpy(team1,t1);
            }
            fflush(stdin);
            printf("\n\nEnter the name of Team 2 (Please use '_' to represent space between characters): ");
            gets(team2);
            for (a5=0;a5<strlen(team2);a5++)
            {
                t2[a5]=toupper(team2[a5]);
            }
            strcpy(team2,t2);
            while (checkspace(team2)==1||checkalreadyexist1(team2)==0||checkteamalreadyexistinschedule1(week,team2)==1||strcmp(team1,team2)==0)
            {
                fflush(stdin);
                if (checkspace(team2)==1||checkalreadyexist1(team2)==0)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
                }
                if (checkteamalreadyexistinschedule1(week,team2)==1)
                {
                    printf("\n\n\nWARNING! %s already scheduled for Week %d!!",team2,week);
                }
                if (strcmp(team1,team2)==0)
                {
                    printf("\n\n\nWARNING! Team 2 cannot be the same as Team 1!");
                }
                printf("\n\nEnter the the name of Team 2 AGAIN! (Please use '_' to represent space between characters): ");
                gets(team2);
                for (a5=0;a5<strlen(team2);a5++)
                {
                    t2[a5]=toupper(team2[a5]);
                }
                strcpy(team2,t2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 1 in the 1st match (Please use '_' to represent space between characters): ");
            gets(team1player1);
            while (checkspace(team1player1)==1||checkifplayerexistinspecificteam1(team1player1,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player1)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player1,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 1!!");
                }
                printf("\nEnter the player name of Team 1 in the 1st match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player1);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 2 in the 1st match (Please use '_' to represent space between characters): ");
            gets(team2player1);
            while (checkspace(team2player1)==1||checkifplayerexistinspecificteam1(team2player1,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player1)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player1,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 2!!");
                }
                printf("\nEnter the player name of Team 2 in the 1st match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player1);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 1 in the 2nd match (Please use '_' to represent space between characters): ");
            gets(team1player2);
            while (checkspace(team1player2)==1||checkifplayerexistinspecificteam1(team1player2,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player2)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player2,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 1!!");
                }
                printf("\nEnter the player name of Team 1 in the 2nd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 2 in the 2nd match (Please use '_' to represent space between characters): ");
            gets(team2player2);
            while (checkspace(team2player2)==1||checkifplayerexistinspecificteam1(team2player2,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player2)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player2,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 2!!");
                }
                printf("\nEnter the player name of Team 2 in the 2nd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player2);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 1 in the 3rd match (Please use '_' to represent space between characters): ");
            gets(team1player3);
            while (checkspace(team1player3)==1||checkifplayerexistinspecificteam1(team1player3,team1)!=1)
            {
                fflush(stdin);
                if (checkspace(team1player3)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team1player3,team1)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 1!!");
                }
                printf("\nEnter the player name of Team 1 in the 3rd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team1player3);
            }
            fflush(stdin);
            printf("\n\nEnter the player name of Team 2 in the 3rd match (Please use '_' to represent space between characters): ");
            gets(team2player3);
            while (checkspace(team2player3)==1||checkifplayerexistinspecificteam1(team2player3,team2)!=1)
            {
                fflush(stdin);
                if (checkspace(team2player3)==1)
                {
                    printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE!!");
                }
                if (checkifplayerexistinspecificteam1(team2player3,team2)!=1)
                {
                    printf("\n\n\nWARNING! Player DOES NOT exist in Team 2!!");
                }
                printf("\nEnter the player name of Team 2 in the 3rd match AGAIN (Please use '_' to represent space between characters): ");
                gets(team2player3);
            }
            fflush(stdin);
        }
    int checktimevalid=0;
    fflush(stdin);
    printf("\n\nEnter the time of the match (HH:MM)(e.g. 19:00): ");
    gets(time);
    if(time[2]!=":"||strlen(time)!=5)
    {
        checktimevalid=0;
    }
    if((time[0]=='0'||time[0]=='1'||time[0]=='2')&&(time[1]=='0'||time[1]=='1'||time[1]=='2'||time[1]=='3')&&(time[2]==':')&&(time[3]=='0'||time[3]=='1'||time[3]=='2'||time[3]=='3'||time[3]=='4'||time[3]=='5')&&(time[4]=='0'||time[4]=='1'||time[4]=='2'||time[4]=='3'||time[4]=='4'||time[4]=='5'||time[4]=='6'||time[4]=='7'||time[4]=='8'||time[4]=='9')&&(strlen(time)==5))
    {
        checktimevalid=1;
    }
    while(checktimevalid==0)
    {
        fflush(stdin);
        printf("\n\nInvalid time. Please enter the time of the match AGAIN (HH:MM)(e.g. 19:00): ");
        gets(time);
        if(time[2]!=":"||strlen(time)!=5)
        {
            checktimevalid=0;
        }
        if((time[0]=='0'||time[0]=='1'||time[0]=='2')&&(time[1]=='0'||time[1]=='1'||time[1]=='2'||time[1]=='3')&&(time[2]==':')&&(time[3]=='0'||time[3]=='1'||time[3]=='2'||time[3]=='3'||time[3]=='4'||time[3]=='5')&&(time[4]=='0'||time[4]=='1'||time[4]=='2'||time[4]=='3'||time[4]=='4'||time[4]=='5'||time[4]=='6'||time[4]=='7'||time[4]=='8'||time[4]=='9')&&(strlen(time)==5))
        {
            checktimevalid=1;
        }
    }
    fflush(stdin);
    printf("\n\nEnter the result of match 1 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
    gets(result1);
    while (strcmp(result1,"3-0")!=0&&strcmp(result1,"3-1")!=0&&strcmp(result1,"3-2")!=0&&strcmp(result1,"2-3")!=0&&strcmp(result1,"1-3")!=0&&strcmp(result1,"0-3")!=0)
    {
        fflush(stdin);
        printf("\nInvalid input. Please enter the result of match 1 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result1);
    }
    fflush(stdin);
    printf("\n\nEnter the result of match 2 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
    gets(result2);
    while (strcmp(result2,"3-0")!=0&&strcmp(result2,"3-1")!=0&&strcmp(result2,"3-2")!=0&&strcmp(result2,"2-3")!=0&&strcmp(result2,"1-3")!=0&&strcmp(result2,"0-3")!=0)
    {
        fflush(stdin);
        printf("\nInvalid input. Please enter the result of match 2 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result2);
    }
    fflush(stdin);
    printf("\n\nEnter the result of match 3 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
    gets(result3);
    while (strcmp(result3,"3-0")!=0&&strcmp(result3,"3-1")!=0&&strcmp(result3,"3-2")!=0&&strcmp(result3,"2-3")!=0&&strcmp(result3,"1-3")!=0&&strcmp(result3,"0-3")!=0)
    {
        fflush(stdin);
        printf("\nInvalid input. Please enter the result of match 3 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result3);
    }
    for (a2=0;a2<strlen(team1player1);a2++)
    {
        t1p1[a2]=toupper(team1player1[a2]);
    }
    strcpy(team1player1,t1p1);
    for (a3=0;a3<strlen(team1player2);a3++)
    {
        t1p2[a3]=toupper(team1player2[a3]);
    }
    strcpy(team1player2,t1p2);
    for (a4=0;a4<strlen(team1player3);a4++)
    {
        t1p3[a4]=toupper(team1player3[a4]);
    }
    strcpy(team1player3,t1p3);
    for (a6=0;a6<strlen(team2player1);a6++)
    {
        t2p1[a6]=toupper(team2player1[a6]);
    }
    strcpy(team2player1,t2p1);
    for (a7=0;a7<strlen(team2player2);a7++)
    {
        t2p2[a7]=toupper(team2player2[a7]);

    }
    strcpy(team2player2,t2p2);
    for (a8=0;a8<strlen(team2player3);a8++)
    {
        t2p3[a8]=toupper(team2player3[a8]);
    }
    strcpy(team2player3,t2p3);
    for (a9=0;a9<strlen(x);a9++)
    {
        bigvenue[a9]=toupper(x[a9]);
    }
    printf("\n\n------------------------------RECORD UPDATED------------------------------");
    fprintf(s,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",week,bigvenue,time,result1,result2,result3,team1,team1player1,team1player2,team1player3,team2,team2player1,team2player2,team2player3);
    passnewscheduleaddmarks1(result1,result2,result3,team1,team1player1,team1player2,team1player3,team2,team2player1,team2player2,team2player3);
    printf("\n\nPress any key to go back to Functions selector......");
    getch();
    fclose(f);
    fclose(fp);
    fclose(s);
    adivision1();
    return 0;
}

int checkteamalreadyexistinschedule1(int week,char a[])
{
    struct schedule s[50];
    int i=0,j=0,k=0,flag=0;
    char x[50]="";
    FILE *f=fopen("schedule1.txt","r");
    while(fscanf(f,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[i].week,&s[i].place,&s[i].time,&s[i].result1,&s[i].result2,&s[i].result3,&s[i].team1,&s[i].team1player1,&s[i].team1player2,&s[i].team1player3,&s[i].team2,&s[i].team2player1,&s[i].team2player2,&s[i].team2player3)!=EOF)
    {
        i++;
    }
    for (k=0;k<strlen(a);k++)
    {
        x[k]=toupper(a[k]);
    }
    for(j=0;j<i;j++)
    {
        if(week==s[j].week&&(strcmp(x,s[j].team1)==0||strcmp(x,s[j].team2)==0))
            flag=1;
    }
    return flag;
}

int checkifweekexistschedule1(int week)
{
    struct schedule s[50];
    int i=0,j=0,k=0,flag=0;
    FILE *f=fopen("schedule1.txt","r");
    while(fscanf(f,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[i].week,&s[i].place,&s[i].time,&s[i].result1,&s[i].result2,&s[i].result3,&s[i].team1,&s[i].team1player1,&s[i].team1player2,&s[i].team1player3,&s[i].team2,&s[i].team2player1,&s[i].team2player2,&s[i].team2player3)!=EOF)
    {
        i++;
    }
    for(j=0;j<i;j++)
    {
        if(week==s[j].week)
            flag=1;
    }
    return flag;
}

int findteampositionbyname1(char s[])
{
    int i=0,j=0,k=0;
    char x[50]="";
    struct team_info division1[50];
    FILE *fp=fopen("team_division1.txt","r");
    while (fscanf(fp,"%s %s %s\t%d\t%d\t%d\t%d",&division1[i].team,&division1[i].venue,&division1[i].convenor,&division1[i].played,&division1[i].won,&division1[i].lost,&division1[i].points)!=EOF)
    {
        i++;
    }
    for (k=0;k<strlen(s);k++)
        x[k]=toupper(s[k]);
    while(strcmp(x,division1[j].team)!=0&&j<i)
    {
        if(strcmp(x,division1[j].team)!=0)
            j++;
    }
    return j;
}

int checkifplayerexistinspecificteam1(char person[],char t[])
{
    int i=0,f=0,j=0,k=0,d=0;
    char x[50]="";
    char y[50]="";
    struct player_info p[50];
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for (k=0;k<strlen(person);k++)
    {
        x[k]=toupper(person[k]);
    }
    for (d=0;d<strlen(t);d++)
    {
        y[d]=toupper(t[d]);
    }
    while(f==0&&i<j)
    {
        if(strcmp(x,p[i].player_name)==0&&strcmp(y,p[i].team_name)==0)
            f=1;
        else
            i++;
    }
    return f;
}

void passnewscheduleaddmarks1(char r1[],char r2[],char r3[],char t1[],char t1p1[],char t1p2[],char t1p3[],char t2[],char t2p1[],char t2p2[],char t2p3[])
{
    int team1score1,team2score1,team1score2,team2score2,team1score3,team2score3,i=0,j=0,k=0,e=0,countteam1win=0,countteam2win=0,countteam1lost=0,countteam2lost=0,team1total=0,team2total=0;
    struct team_info t[50];
    struct player_info p[50];
    FILE *a=fopen("team_division1.txt","r");
    FILE *b=fopen("player_division1.txt","r");
    while(fscanf(a,"%s %s %s\t%d\t%d\t%d\t%d",&t[i].team,&t[i].venue,&t[i].convenor,&t[i].played,&t[i].won,&t[i].lost,&t[i].points)!=EOF)
    {
        i++;
    }
    while(fscanf(b,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    if(strcmp(r1,"3-0")==0)
    {
        team1score1=27;
        team2score1=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r1,"3-1")==0)
    {
        team1score1=24;
        team2score1=15;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r1,"3-2")==0)
    {
        team1score1=21;
        team2score1=18;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r1,"2-3")==0)
    {
        team1score1=18;
        team2score1=21;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r1,"1-3")==0)
    {
        team1score1=15;
        team2score1=24;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r1,"0-3")==0)
    {
        team1score1=12;
        team2score1=27;
        countteam1lost++;
        countteam2win++;
    }
    if(strcmp(r2,"3-0")==0)
    {
        team1score2=24;
        team2score2=9;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r2,"3-1")==0)
    {
        team1score2=21;
        team2score2=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r2,"3-2")==0)
    {
        team1score2=18;
        team2score2=15;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r2,"2-3")==0)
    {
        team1score2=15;
        team2score2=18;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r2,"1-3")==0)
    {
        team1score2=12;
        team2score2=21;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r2,"0-3")==0)
    {
        team1score2=9;
        team2score2=24;
        countteam1lost++;
        countteam2win++;
    }
    if(strcmp(r3,"3-0")==0)
    {
        team1score3=21;
        team2score3=6;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r3,"3-1")==0)
    {
        team1score3=18;
        team2score3=9;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r3,"3-2")==0)
    {
        team1score3=15;
        team2score3=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(r3,"2-3")==0)
    {
        team1score3=12;
        team2score3=15;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r3,"1-3")==0)
    {
        team1score3=9;
        team2score3=18;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(r3,"0-3")==0)
    {
        team1score3=6;
        team2score3=21;
        countteam1lost++;
        countteam2win++;
    }
    t[findteampositionbyname1(t1)].played++;
    t[findteampositionbyname1(t2)].played++;
    p[findplayerpositionbyname1(t1p1)].played++;
    p[findplayerpositionbyname1(t1p2)].played++;
    p[findplayerpositionbyname1(t1p3)].played++;
    p[findplayerpositionbyname1(t2p1)].played++;
    p[findplayerpositionbyname1(t2p2)].played++;
    p[findplayerpositionbyname1(t2p3)].played++;
    p[findplayerpositionbyname1(t1p1)].total_points+=team1score1;
    p[findplayerpositionbyname1(t1p2)].total_points+=team1score2;
    p[findplayerpositionbyname1(t1p3)].total_points+=team1score3;
    p[findplayerpositionbyname1(t2p1)].total_points+=team2score1;
    p[findplayerpositionbyname1(t2p2)].total_points+=team2score2;
    p[findplayerpositionbyname1(t2p3)].total_points+=team2score3;
    if (strcmp(r1,"3-0")==0||strcmp(r1,"3-1")==0||strcmp(r1,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p1)].won++;
        p[findplayerpositionbyname1(t2p1)].lost++;
    }
    else if (strcmp(r1,"2-3")==0||strcmp(r1,"1-3")==0||strcmp(r1,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p1)].lost++;
        p[findplayerpositionbyname1(t2p1)].won++;
    }
    if (strcmp(r2,"3-0")==0||strcmp(r2,"3-1")==0||strcmp(r2,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p2)].won++;
        p[findplayerpositionbyname1(t2p2)].lost++;
    }
    else if (strcmp(r2,"2-3")==0||strcmp(r2,"1-3")==0||strcmp(r2,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p2)].lost++;
        p[findplayerpositionbyname1(t2p2)].won++;
    }
    if (strcmp(r3,"3-0")==0||strcmp(r3,"3-1")==0||strcmp(r3,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p3)].won++;
        p[findplayerpositionbyname1(t2p3)].lost++;
    }
    else if (strcmp(r3,"2-3")==0||strcmp(r3,"1-3")==0||strcmp(r3,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p3)].lost++;
        p[findplayerpositionbyname1(t2p3)].won++;
    }
    if (countteam1win>countteam2win)
    {
        t[findteampositionbyname1(t1)].points=t[findteampositionbyname1(t1)].points+countteam1win+1;
        t[findteampositionbyname1(t2)].points+=countteam2win;
        t[findteampositionbyname1(t1)].won++;
        t[findteampositionbyname1(t2)].lost++;
    }
    else
    {
        t[findteampositionbyname1(t2)].points=t[findteampositionbyname1(t2)].points+countteam2win+1;
        t[findteampositionbyname1(t1)].points+=countteam1win;
        t[findteampositionbyname1(t2)].won++;
        t[findteampositionbyname1(t1)].lost++;
    }
    fclose(a);
    fclose(b);
    FILE *c=fopen("team_division1.txt","w");
    FILE *d=fopen("player_division1.txt","w");
    for (k=0;k<i;k++)
    {
        fprintf(c,"%s %s %s\t%d\t%d\t%d\t%d\n",t[k].team,t[k].venue,t[k].convenor,t[k].played,t[k].won,t[k].lost,t[k].points);
    }
    for (e=0;e<j;e++)
    {
        fprintf(d,"%s %d\t%s\t%d\t%d\t%d\t%d\n",p[e].team_name,p[e].hksnum,p[e].player_name,p[e].total_points,p[e].played,p[e].won,p[e].lost);
    }
    fclose(c);
    fclose(d);
}

void modifyscheduleandresult1()
{
    system("cls");
    int y=0,a=0,count=0,weekmodify,i=0,j=0,flag=0,realpos=0,q,e;
    char teammodify[50],yesorno[5],tm[50],t1[50],t1p1[50],t1p2[50],t1p3[50],t2[50],t2p1[50],t2p2[50],t2p3[50],bigvenue[50],team1[50],team2[50],place[50],time[5],team1player1[50],team1player2[50],team1player3[50],team2player1[50],team2player2[50],team2player3[50],homeoraway[10],result1[10],result2[10],result3[10];
    FILE *f=fopen("team_division1.txt","r");
    FILE *fp=fopen("player_division1.txt","r");
    FILE *z=fopen("schedule1.txt","r");
    struct team_info d1[50];
    struct player_info p[50];
    struct schedule s[100];
    fflush(stdin);
    while (fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&d1[i].team,&d1[i].venue,&d1[i].convenor,&d1[i].played,&d1[i].won,&d1[i].lost,&d1[i].points)!=EOF)
    {
        i++;
    }
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    while (fscanf(z,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[y].week,&s[y].place,&s[y].time,&s[y].result1,&s[y].result2,&s[y].result3,&s[y].team1,&s[y].team1player1,&s[y].team1player2,&s[y].team1player3,&s[y].team2,&s[y].team2player1,&s[y].team2player2,&s[y].team2player3)!=EOF)
    {
        y++;
    }
    fclose(f);
    fclose(fp);
    fclose(z);
    printf("\n\nEnter the no. of the week of the match that you want to modify its result (1-20)  //Type '999' to go back to Function Selector// :    ");
    scanf("%d",&weekmodify);
    if(weekmodify==999)
    {
        adivision1();
    }
    while(!(weekmodify>0&&weekmodify<21)||checkifweekexistschedule1(weekmodify)==0)
    {
        if(!(weekmodify>0&&weekmodify<21))
        {
            printf("\nInvalid input. Please the no. of the week of the schedule that you want to modify again (1-20)  //Type '999' to go back to Function Selector// :    ");
            fflush(stdin);
            scanf("%d",&weekmodify);
            if(weekmodify==999)
            {
                adivision1();
            }
        }
        if(checkifweekexistschedule1(weekmodify)==0)
        {
            printf("\nWeek %d does not have any matches scheduled. Enter the no. of the week of the schedule that you want to modify (1-20)  //Type '999' to go back to Function Selector// :    ",weekmodify);
            fflush(stdin);
            scanf("%d",&weekmodify);
            if(weekmodify==999)
            {
                adivision1();
            }
        }
        if(weekmodify==999)
        {
            adivision1();
        }
    }
    system("cls");
    printf("\n\nWeek %d\n",weekmodify);
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==weekmodify)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    fflush(stdin);
    printf("\n\nWhich match result do you want to modify? Please enter the name of one team that is involved in the match (Please use '_' to represent space between characters): ");
    gets(teammodify);
    while (checkspace(teammodify)==1||checkalreadyexist1(teammodify)==0||checkteamalreadyexistinschedule1(weekmodify,teammodify)==0)
    {
        fflush(stdin);
        if (checkspace(teammodify)==1||checkalreadyexist1(teammodify)==0)
        {
            printf("\n\n\nWARNING! INPUTTED VALUE CONTAINS SPACE OR DOES NOT EXIST!!");
        }
            if (checkteamalreadyexistinschedule1(weekmodify,teammodify)==0&&!(checkspace(teammodify)==1||checkalreadyexist1(teammodify)==0))
        {
            printf("\n\n\nWARNING! %s is not scheduled for Week %d!!",teammodify,weekmodify);
        }
        printf("\n\nEnter enter the name of one team that is involved in the match AGAIN! (Please use '_' to represent space between characters): ");
        gets(teammodify);
    }
    fflush(stdin);
    for (e=0;e<strlen(teammodify);e++)
    {
        tm[e]=toupper(teammodify[e]);
    }
    for(q=0;q<y;q++)
    {
        if(!(weekmodify==s[q].week&&(strcmp(teammodify,s[q].team1)==0||strcmp(teammodify,s[q].team2)==0)))
            flag++;
    }
    if(flag==0)
    {
        realpos=0;
    }
    else if (flag>1)
    {
        realpos=flag-1;
    }
    if(strcmp(s[realpos].team1,teammodify)==0)
    {
        strcpy(t1,teammodify);
        strcpy(t2,s[realpos].team2);
    }
    else if(strcmp(s[realpos].team2,teammodify)==0)
    {
        strcpy(t2,teammodify);
        strcpy(t1,s[realpos].team1);
    }
    printf("\nRecord located. Are you sure you want to modify? (Y/N): ");
    gets(yesorno);
    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
    {
        fflush(stdin);
        printf("\nInvalid Input! Are you sure you want to modify? (Y/N) ");
        gets(yesorno);
    }
    if(strcmp(yesorno,"N")==0||strcmp(yesorno,"n")==0)
    {
        fflush(stdin);
        printf("\n\n\nPress any key to go back to Functions selector...");
        getch();
        adivision1();
    }
    else if (strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0)
    {
        strcpy(bigvenue,s[realpos].place);
        strcpy(time,s[realpos].time);
        strcpy(result1,s[realpos].result1);
        strcpy(result2,s[realpos].result2);
        strcpy(result3,s[realpos].result3);
        strcpy(team1,s[realpos].team1);
        strcpy(team1player1,s[realpos].team1player1);
        strcpy(team1player2,s[realpos].team1player2);
        strcpy(team1player3,s[realpos].team1player3);
        strcpy(team2,s[realpos].team2);
        strcpy(team2player1,s[realpos].team2player1);
        strcpy(team2player2,s[realpos].team2player2);
        strcpy(team2player3,s[realpos].team2player3);
    }
    fflush(stdin);
    strcpy(yesorno,"");
    printf("\n\nChange the result of match 1? (Y/N) ");
    gets(yesorno);
    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the result of match 1? (Y/N) ");
        gets(yesorno);
    }
    if (strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0)
    {
        fflush(stdin);
        strcpy(result1,"");
        printf("\n\nEnter the result of match 1 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result1);
        while (strcmp(result1,"3-0")!=0&&strcmp(result1,"3-1")!=0&&strcmp(result1,"3-2")!=0&&strcmp(result1,"2-3")!=0&&strcmp(result1,"1-3")!=0&&strcmp(result1,"0-3")!=0)
        {
            fflush(stdin);
            printf("\nInvalid input. Please enter the result of match 1 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
            gets(result1);
        }
    }
    fflush(stdin);
    strcpy(yesorno,"");
    printf("\n\nChange the result of match 2? (Y/N) ");
    gets(yesorno);
    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the result of match 2? (Y/N) ");
        gets(yesorno);
    }
    if (strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0)
    {
        fflush(stdin);
        strcpy(result2,"");
        printf("\n\nEnter the result of match 2 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result2);
        while (strcmp(result2,"3-0")!=0&&strcmp(result2,"3-1")!=0&&strcmp(result2,"3-2")!=0&&strcmp(result2,"2-3")!=0&&strcmp(result2,"1-3")!=0&&strcmp(result2,"0-3")!=0)
        {
            fflush(stdin);
            printf("\nInvalid input. Please enter the result of match 2 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
            gets(result2);
        }
    }
    fflush(stdin);
    strcpy(yesorno,"");
    printf("\n\nChange the result of match 3? (Y/N) ");
    gets(yesorno);
    while(strcmp(yesorno,"Y")!=0&&strcmp(yesorno,"N")!=0&&strcmp(yesorno,"y")!=0&&strcmp(yesorno,"n")!=0)
    {
        fflush(stdin);
        printf("\n\n\nInvalid Input!");
        printf("\nChange the result of match 3? (Y/N) ");
        gets(yesorno);
    }
    if (strcmp(yesorno,"Y")==0||strcmp(yesorno,"y")==0)
    {
        fflush(stdin);
        strcpy(result3,"");
        printf("\n\nEnter the result of match 3 (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
        gets(result3);
        while (strcmp(result3,"3-0")!=0&&strcmp(result3,"3-1")!=0&&strcmp(result3,"3-2")!=0&&strcmp(result3,"2-3")!=0&&strcmp(result3,"1-3")!=0&&strcmp(result3,"0-3")!=0)
        {
            fflush(stdin);
            printf("\nInvalid input. Please enter the result of match 3 again (e.g. Please enter 3-2 if a player from home team or Team 1 won 3 rounds and lost 2 rounds): ");
            gets(result3);
        }
    }
    fflush(stdin);
    deletemarksandschedule1(weekmodify,tm);
    FILE *n=fopen("schedule1.txt","a");
    fprintf(n,"%d\t%s\t%.5s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",weekmodify,bigvenue,time,result1,result2,result3,team1,team1player1,team1player2,team1player3,team2,team2player1,team2player2,team2player3);
    passnewscheduleaddmarks1(result1,result2,result3,team1,team1player1,team1player2,team1player3,team2,team2player1,team2player2,team2player3);
    printf("\n\n------------------------------RECORD UPDATED------------------------------\n\nPress any key to go back to Functions selector......");
    getch();
    adivision1();
    fclose(n);
    fflush(stdin);
    printf("\n\n\nPress any key to go back to Functions selector...");
    getch();
    adivision1();
}

void deletemarksandschedule1(int weekdelete,char teamdelete[])
{
    fflush(stdin);
    int i=0,j=0,y=0,q,flag=0,f1,team1score1,team2score1,team1score2,team2score2,team1score3,team2score3,countteam1win=0,countteam2win=0,countteam1lost=0,countteam2lost=0,team1total=0,team2total=0,realpos=0;
    char t1[50],t2[50],t1p1[50],t1p2[50],t1p3[50],t2p1[50],t2p2[50],t2p3[50];
    struct team_info d1[50];
    struct player_info p[50];
    struct schedule s[100];
    FILE *f=fopen("team_division1.txt","r");
    FILE *fp=fopen("player_division1.txt","r");
    FILE *z=fopen("schedule1.txt","r");
    while(fscanf(f,"%s %s %s\t%d\t%d\t%d\t%d",&d1[i].team,&d1[i].venue,&d1[i].convenor,&d1[i].played,&d1[i].won,&d1[i].lost,&d1[i].points)!=EOF)
    {
        i++;
    }
    while(fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    while(fscanf(z,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[y].week,&s[y].place,&s[y].time,&s[y].result1,&s[y].result2,&s[y].result3,&s[y].team1,&s[y].team1player1,&s[y].team1player2,&s[y].team1player3,&s[y].team2,&s[y].team2player1,&s[y].team2player2,&s[y].team2player3)!=EOF)
    {
        y++;
    }
    fclose(f);
    fclose(fp);
    fclose(z);
    for(q=0;q<y;q++)
    {
        if(!(weekdelete==s[q].week&&(strcmp(teamdelete,s[q].team1)==0||strcmp(teamdelete,s[q].team2)==0)))
            flag++;
    }
    if(flag==0)
    {
        realpos=0;
    }
    else if (flag>1)
    {
        realpos=flag-1;
    }
    if(strcmp(s[realpos].team1,teamdelete)==0)
    {
        strcpy(t1,teamdelete);
        strcpy(t2,s[realpos].team2);
    }
    else if(strcmp(s[realpos].team2,teamdelete)==0)
    {
        strcpy(t2,teamdelete);
        strcpy(t1,s[realpos].team1);
    }
    strcpy(t1p1,s[realpos].team1player1);
    strcpy(t1p2,s[realpos].team1player2);
    strcpy(t1p3,s[realpos].team1player3);
    strcpy(t2p1,s[realpos].team2player1);
    strcpy(t2p2,s[realpos].team2player2);
    strcpy(t2p3,s[realpos].team2player3);
    if(strcmp(s[realpos].result1,"3-0")==0)
    {
        team1score1=27;
        team2score1=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result1,"3-1")==0)
    {
        team1score1=24;
        team2score1=15;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result1,"3-2")==0)
    {
        team1score1=21;
        team2score1=18;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result1,"2-3")==0)
    {
        team1score1=18;
        team2score1=21;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result1,"1-3")==0)
    {
        team1score1=15;
        team2score1=24;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result1,"0-3")==0)
    {
        team1score1=12;
        team2score1=27;
        countteam1lost++;
        countteam2win++;
    }
    if(strcmp(s[realpos].result2,"3-0")==0)
    {
        team1score2=24;
        team2score2=9;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result2,"3-1")==0)
    {
        team1score2=21;
        team2score2=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result2,"3-2")==0)
    {
        team1score2=18;
        team2score2=15;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result2,"2-3")==0)
    {
        team1score2=15;
        team2score2=18;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result2,"1-3")==0)
    {
        team1score2=12;
        team2score2=21;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result2,"0-3")==0)
    {
        team1score2=9;
        team2score2=24;
        countteam1lost++;
        countteam2win++;
    }
    if(strcmp(s[realpos].result3,"3-0")==0)
    {
        team1score3=21;
        team2score3=6;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result3,"3-1")==0)
    {
        team1score3=18;
        team2score3=9;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result3,"3-2")==0)
    {
        team1score3=15;
        team2score3=12;
        countteam1win++;
        countteam2lost++;
    }
    else if(strcmp(s[realpos].result3,"2-3")==0)
    {
        team1score3=12;
        team2score3=15;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result3,"1-3")==0)
    {
        team1score3=9;
        team2score3=18;
        countteam1lost++;
        countteam2win++;
    }
    else if(strcmp(s[realpos].result3,"0-3")==0)
    {
        team1score3=6;
        team2score3=21;
        countteam1lost++;
        countteam2win++;
    }
    d1[findteampositionbyname1(t1)].played--;
    d1[findteampositionbyname1(t2)].played--;
    p[findplayerpositionbyname1(t1p1)].played--;
    p[findplayerpositionbyname1(t1p2)].played--;
    p[findplayerpositionbyname1(t1p3)].played--;
    p[findplayerpositionbyname1(t2p1)].played--;
    p[findplayerpositionbyname1(t2p2)].played--;
    p[findplayerpositionbyname1(t2p3)].played--;
    p[findplayerpositionbyname1(t1p1)].total_points-=team1score1;
    p[findplayerpositionbyname1(t1p2)].total_points-=team1score2;
    p[findplayerpositionbyname1(t1p3)].total_points-=team1score3;
    p[findplayerpositionbyname1(t2p1)].total_points-=team2score1;
    p[findplayerpositionbyname1(t2p2)].total_points-=team2score2;
    p[findplayerpositionbyname1(t2p3)].total_points-=team2score3;
    if (strcmp(s[realpos].result1,"3-0")==0||strcmp(s[realpos].result1,"3-1")==0||strcmp(s[realpos].result1,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p1)].won--;
        p[findplayerpositionbyname1(t2p1)].lost--;
    }
    else if (strcmp(s[realpos].result1,"2-3")==0||strcmp(s[realpos].result1,"1-3")==0||strcmp(s[realpos].result1,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p1)].lost--;
        p[findplayerpositionbyname1(t2p1)].won--;
    }
    if (strcmp(s[realpos].result2,"3-0")==0||strcmp(s[realpos].result2,"3-1")==0||strcmp(s[realpos].result2,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p2)].won--;
        p[findplayerpositionbyname1(t2p2)].lost--;
    }
    else if (strcmp(s[realpos].result2,"2-3")==0||strcmp(s[realpos].result2,"1-3")==0||strcmp(s[realpos].result2,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p2)].lost--;
        p[findplayerpositionbyname1(t2p2)].won--;
    }
    if (strcmp(s[realpos].result3,"3-0")==0||strcmp(s[realpos].result3,"3-1")==0||strcmp(s[realpos].result3,"3-2")==0)
    {
        p[findplayerpositionbyname1(t1p3)].won--;
        p[findplayerpositionbyname1(t2p3)].lost--;
    }
    else if (strcmp(s[realpos].result3,"2-3")==0||strcmp(s[realpos].result3,"1-3")==0||strcmp(s[realpos].result3,"0-3")==0)
    {
        p[findplayerpositionbyname1(t1p3)].lost--;
        p[findplayerpositionbyname1(t2p3)].won--;
    }
    if (countteam1win>countteam2win)
    {
        d1[findteampositionbyname1(t1)].points=d1[findteampositionbyname1(t1)].points-countteam1win-1;
        d1[findteampositionbyname1(t2)].points-=countteam2win;
        d1[findteampositionbyname1(t1)].won--;
        d1[findteampositionbyname1(t2)].lost--;
    }
    else
    {
        d1[findteampositionbyname1(t2)].points=d1[findteampositionbyname1(t2)].points-countteam2win-1;
        d1[findteampositionbyname1(t1)].points-=countteam1win;
        d1[findteampositionbyname1(t2)].won--;
        d1[findteampositionbyname1(t1)].lost--;
    }
    FILE *a=fopen("team_division1.txt","w");
    FILE *b=fopen("player_division1.txt","w");
    FILE *c=fopen("schedule1.txt","w");
    for (f1=0;f1<i;f1++)
    {
        fprintf(a,"%s %s %s\t%d\t%d\t%d\t%d\n",d1[f1].team,d1[f1].venue,d1[f1].convenor,d1[f1].played,d1[f1].won,d1[f1].lost,d1[f1].points);
    }
    for (f1=0;f1<j;f1++)
    {
        fprintf(b,"%s %d\t%s\t%d\t%d\t%d\t%d\n",p[f1].team_name,p[f1].hksnum,p[f1].player_name,p[f1].total_points,p[f1].played,p[f1].won,p[f1].lost);
    }
    if (realpos==0)
    {
        for (f1=1;f1<y;f1++)
        {
            fprintf(c,"%d\t%s\t%.5s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[f1].week,s[f1].place,s[f1].time,s[f1].result1,s[f1].result2,s[f1].result3,s[f1].team1,s[f1].team1player1,s[f1].team1player2,s[f1].team1player3,s[f1].team2,s[f1].team2player1,s[f1].team2player2,s[f1].team2player3);
        }
    }
    else if (realpos!=0&&realpos!=y)
    {
        for (f1=0;f1<realpos;f1++)
        {
            fprintf(c,"%d\t%s\t%.5s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[f1].week,s[f1].place,s[f1].time,s[f1].result1,s[f1].result2,s[f1].result3,s[f1].team1,s[f1].team1player1,s[f1].team1player2,s[f1].team1player3,s[f1].team2,s[f1].team2player1,s[f1].team2player2,s[f1].team2player3);
        }
        for (f1=realpos+1;f1<y;f1++)
        {
            fprintf(c,"%d\t%s\t%.5s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[f1].week,s[f1].place,s[f1].time,s[f1].result1,s[f1].result2,s[f1].result3,s[f1].team1,s[f1].team1player1,s[f1].team1player2,s[f1].team1player3,s[f1].team2,s[f1].team2player1,s[f1].team2player2,s[f1].team2player3);
        }
    }
    else if (realpos==y)
    {
        for (f1=0;f1<y-1;f1++)
        {
            fprintf(c,"%d\t%s\t%.5s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[f1].week,s[f1].place,s[f1].time,s[f1].result1,s[f1].result2,s[f1].result3,s[f1].team1,s[f1].team1player1,s[f1].team1player2,s[f1].team1player3,s[f1].team2,s[f1].team2player1,s[f1].team2player2,s[f1].team2player3);
        }
    }
    fclose(a);
    fclose(b);
    fclose(c);
}

int findplayerpositionbyname1(char s[])
{
    int i=0,j=0,k=0;
    char x[50]="";
    struct player_info p[50];
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[i].team_name,&p[i].hksnum,&p[i].player_name,&p[i].total_points,&p[i].played,&p[i].won,&p[i].lost)!=EOF)
    {
        i++;
    }
    for (k=0;k<strlen(s);k++)
        x[k]=toupper(s[k]);
    while(strcmp(x,p[j].player_name)!=0&&j<i)
    {
        if(strcmp(x,p[j].player_name)!=0)
            j++;
    }
    return j;
}

void viewscheduleandresultadmin1()
{
    struct schedule s[100];
    int y=0,a=0,count=0;
    FILE *z=fopen("schedule1.txt","r");
    while(fscanf(z,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[y].week,&s[y].place,&s[y].time,&s[y].result1,&s[y].result2,&s[y].result3,&s[y].team1,&s[y].team1player1,&s[y].team1player2,&s[y].team1player3,&s[y].team2,&s[y].team2player1,&s[y].team2player2,&s[y].team2player3)!=EOF)
    {
        y++;
    }
    system("cls");
    printf("Week 1\t\t11 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==1)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 2\t\t18 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==2)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 3\t\t25 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==3)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 4\t\t1 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==4)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 5\t\t8 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==5)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 6\t\t15 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==6)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 7\t\t29 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==7)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 8\t\t6 December 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==8)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 9\t\t13 December 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==9)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 10\t\t3 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==10)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 11\t\t10 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==11)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 12\t\t17 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==12)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 13\t\t24 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==13)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 14\t\t31 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==14)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 15\t\t21 February 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==15)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 16\t\t28 February 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==16)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 17\t\t7 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==17)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 18\t\t14 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==18)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 19\t\t21 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==19)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 20\t\t28 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==20)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    getch();
    adivision1();
    fclose(z);
}

void viewscheduleandresultguest1()
{
    struct schedule s[100];
    int y=0,a=0,count=0;
    FILE *z=fopen("schedule1.txt","r");
    while(fscanf(z,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",&s[y].week,&s[y].place,&s[y].time,&s[y].result1,&s[y].result2,&s[y].result3,&s[y].team1,&s[y].team1player1,&s[y].team1player2,&s[y].team1player3,&s[y].team2,&s[y].team2player1,&s[y].team2player2,&s[y].team2player3)!=EOF)
    {
        y++;
    }
    system("cls");
    printf("Week 1\t\t11 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==1)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 2\t\t18 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==2)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 3\t\t25 October 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==3)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 4\t\t1 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==4)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 5\t\t8 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==5)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 6\t\t15 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==6)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 7\t\t29 November 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==7)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 8\t\t6 December 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==8)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 9\t\t13 December 2018\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==9)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 10\t\t3 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==10)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 11\t\t10 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==11)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 12\t\t17 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==12)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 13\t\t24 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==13)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 14\t\t31 January 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==14)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 15\t\t21 February 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==15)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 16\t\t28 February 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==16)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 17\t\t7 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==17)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 18\t\t14 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==18)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 19\t\t21 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==19)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    printf("\n\nWeek 20\t\t28 March 2019\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s%-5c%-30s%-30s%-10s%-30s\n","TEAM",'V',"TEAM","VENUE","TIME","RESULT");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<y;a++)
    {
        count=0;
        if(s[a].week==20)
        {
            if (strcmp(s[a].result1,"3-0")==0||strcmp(s[a].result1,"3-1")==0||strcmp(s[a].result1,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result2,"3-0")==0||strcmp(s[a].result2,"3-1")==0||strcmp(s[a].result2,"3-2")==0)
            {
                count++;
            }
            if (strcmp(s[a].result3,"3-0")==0||strcmp(s[a].result3,"3-1")==0||strcmp(s[a].result3,"3-2")==0)
            {
                count++;
            }
            printf("%-30s%-5c%-30s%-30s%.5s\t %d-%d(%s,%s,%s)\n",s[a].team1,'V',s[a].team2,s[a].place,s[a].time,count,3-count,s[a].result1,s[a].result2,s[a].result3);
        }
    }
    getch();
    gdivision1();
    fclose(z);
}

int getplayerrank1(char s[])
{
    int j=0,x=0,y=0,i=0,k=0,c=0;
    struct player_info p[50];
    struct player_info a[50];
    struct player_info b[50];
    struct player_info temp;
    FILE *fp=fopen("player_division1.txt","r");
    while (fscanf(fp,"%s %d\t%s\t%d\t%d\t%d\t%d",&p[j].team_name,&p[j].hksnum,&p[j].player_name,&p[j].total_points,&p[j].played,&p[j].won,&p[j].lost)!=EOF)
    {
        j++;
    }
    for(x=0;x<j;x++)
    {
        if(p[x].played>=5)
        {
            a[i]=p[x];
            a[i].average_points=((float)(p[x].total_points)/(p[x].played));
            i++;
        }
    }
    for(x=1;x<i;x++)
    {
        for(y=1;y<=i-x;y++)
        {
            if (a[y-1].average_points<a[y].average_points)
            {
            temp=a[y];
            a[y]=a[y-1];
            a[y-1]=temp;
            }
        }
    }
    while(strcmp(a[c].player_name,s)!=0&&c<i)
    {
        if(strcmp(a[c].player_name,s)!=0)
            c++;
    }
    return c+1;
}
