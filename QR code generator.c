/* AUTHOR: M.M.M.RILWAN
   E NO  : E/17/292
   CO 222 PROJECT 1 (QR CODE)
*/

#include <stdio.h>
#include <string.h>

void moveTo(int row,int col) //moving cursor to required coordinate
{printf("\x1b[%d;%df",row,col);}

void moveDown(int post)  //cursor moving down
{printf("\x1b[%dB",post);}

void moveLeft(int post)  //cursor moving left
{printf("\x1b[%dD",post);}

void miniqr(unsigned char a,int x,int y,int color) //printing one qr at given coordinates
{

int bin[9]; //array for binary
int i;
int k=0;
for(i=8;i>=0;i--) //converting to binary
    {
        bin[i]=a%2; //remainder
           a=a/2; // a is divided by 2
    }

moveTo(x,y); //moving that converted binary to required coordinate
for(i=0;i<3;i++) // 1st raw
{
        if(bin[k]==0)
            {printf("\x1b[47m  \x1b[0m");} // if 0 default white clr jst spac
        else
            {printf("\x1b[%im  \x1b[0m",color);}//if 1 default black clr
        k++;
}

moveDown(1); //next row
moveLeft(6); //to begin 2nd row

for(i=0;i<3;i++) //2nd row
{
        if(bin[k]==0)
            {printf("\x1b[47m  \x1b[0m");}
        else
            {printf("\x1b[%im  \x1b[0m",color);}
        k++;
}

moveDown(1); //next row
moveLeft(6); //to begin 3rd row

for(i=0;i<3;i++) //3rd row
{
        if(bin[k]==0)
            {printf("\x1b[47m  \x1b[0m");}
        else
            {printf("\x1b[%im  \x1b[0m",color);}
        k++;
}

}

void position(int x,int y,int color) // position with coordinates
{
moveTo(x,y);
int i;
for(i=0;i<6;i++) //1st row
{
    printf("\x1b[%im  \x1b[0m",color); //black clr
}

 moveDown(1); //next row
 moveLeft(12); //begin of 2nd row

 for(i=0;i<6;i++)
{
    if (i==0 || i==5)
    printf("\x1b[%im  \x1b[0m",color); //black clr
    else
    printf("\x1b[47m  \x1b[0m");
}

 moveDown(1);
 moveLeft(12);//begin of 3rd row

 for(i=0;i<6;i++)
{
    if (i==1 || i==4)
    printf("\x1b[47m  \x1b[0m"); //white clr
    else
    printf("\x1b[%im  \x1b[0m",color);
}

 moveDown(1);
 moveLeft(12);//begin of 4th row

 for(i=0;i<6;i++)
{
    if (i==1 || i==4)
    printf("\x1b[47m  \x1b[0m"); //white clr
    else
    printf("\x1b[%im  \x1b[0m",color);
}

 moveDown(1);
 moveLeft(12);//begin of 5th row

 for(i=0;i<6;i++)
{
    if (i==0 || i==5)
    printf("\x1b[%im  \x1b[0m",color); //black clr
    else
    printf("\x1b[47m  \x1b[0m"); // white clr
}

 moveDown(1);
 moveLeft(12);//begin of 6th row

for(i=0;i<6;i++)
{
    printf("\x1b[%im  \x1b[0m",color); //black clr
}

} //end of position

void borderh(int num,int x,int y) //along horizontal
{
    moveTo(x,y);
    int i;
    for(i=1;i<=num;i++)
{
    printf("\x1b[47m  \x1b[0m"); //white border
}

}

void borderv(int num,int x,int y) //along vertical boarder
{
    moveTo(x,y);
    int i;
    for(i=1;i<=num;i++)
{
   printf("\x1b[47m  \x1b[0m\n"); //white border
}

}

//begining of main funct
int main(int argc,char *argv[])
{
    int color=40; //default black clr=40
    unsigned int x;

    if (argc==3)
    {
    for(x=0;x<strlen(argv[2]);x++)
    {
        if (argv[2][x]>='A' && argv[2][x]<='Z')  //checks whether capital
        {
            argv[2][x]=argv[2][x]+32; //convert to simple
        }
    }
    }

    if (argc >3 || (argc==2 && strcmp(argv[1],"-h")!=0) || (argc==3 && strcmp(argv[1],"-c")!=0))
    {
        printf("Incorrect usage of arguments.\n");
        printf("usage:\n");
        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
        printf("%s -h for the help about the program.\n",argv[0]);
    }
    else if (argc==2 && strcmp(argv[1],"-h")==0)
    {
        printf("usage:\n");
        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
        printf("%s -h for the help about the program.\n",argv[0]);
    }

    else if (argc==3 && ((strcmp(argv[2],"black")!=0) && (strcmp(argv[2],"red")!=0) && (strcmp(argv[2],"green")!=0) && (strcmp(argv[2],"yellow")!=0) && (strcmp(argv[2],"blue")!=0) && (strcmp(argv[2],"magenta")!=0) && (strcmp(argv[2],"cyan")!=0)))
    {   printf("Invalid argument for color.\n");
        printf("usage:\n");
        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
        printf("%s -h for the help about the program.\n",argv[0]);
    }
    else if (argc==1 ||(argc==3 && ((strcmp(argv[2],"black")==0) || (strcmp(argv[2],"red")==0) || (strcmp(argv[2],"green")==0) || (strcmp(argv[2],"yellow")==0) || (strcmp(argv[2],"blue")==0) || (strcmp(argv[2],"magenta")==0) || (strcmp(argv[2],"cyan")==0))))
    {


        if(argc==1 || (strcmp(argv[2],"black")==0))
            color=40;
        else if(strcmp(argv[2],"red")==0)
            color=41;
        else if(strcmp(argv[2],"green")==0)
            color=42;
        else if(strcmp(argv[2],"yellow")==0)
            color=43;
        else if(strcmp(argv[2],"blue")==0)
            color=44;
        else if(strcmp(argv[2],"magenta")==0)
            color=45;
        else if(strcmp(argv[2],"cyan")==0)
            color=46;


    char str[250];
    printf("Enter the URL: "); //getting URL
    scanf("%s",str);

    if(strlen(str)<=3) //less than 3
    {printf("String is too short.Not supported by available QR versions.\n");}

    else if(strlen(str)>=120) //greater than 120
    {printf("String is too long.Not supported by available QR versions.\n");}

    else if (strlen(str)<=20) //in between 3 and 20
    {
        printf("\x1b[2J");  //clear the entire screen
        unsigned int i=0;
        unsigned int j=0;
        int k=1;
        int z=0;
        char new[24];
        char rev[24];
        while(i<24)
        {
        if(i==0)
            {new[0]=50+strlen(str);// 1st ch of hashing
            i++;}
        else if(i<=strlen(str)) //printf("%c",str[i]);
            {new[i]=str[i-1];
            i++;}
        else
        {

           for(j=0;j<strlen(str);j++)   //next letters repeating
                {
                    if(i+j<24)
                    {new[i+j]=str[j]+k;}
                }
         i=i+strlen(str);
         k++;
        }
        }    //end of hashed string

        for(i=0;i<24;i++)
        {
       if(i<=strlen(str))
       {   rev[i]=new[i];} //printing same letters as hashed one
      else
       {
          rev[i]=new[23-z];//reversing hashed parts
          z++;
       }
       }//every hashed elements are assigned to rev.

    //Getting relevant coordinates and printing qr in specified places
    position(2,3,color);
    position(2,27,color);
    position(14,3,color);
    int p,q;
    int r=0;
    //printing 1st 16 ch
    for(p=8;p<=17;p=p+3)
    {
        for(q=15;q<=33;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }
    //printing 17,18,19,20
    for(p=2;p<=5;p=p+3)
    {
        for(q=15;q<=21;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }
    //printing 21,22,23,24
    for(p=8;p<=11;p=p+3)
    {
        for(q=3;q<=9;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }

    //printing borders
    borderh(20,1,1);
    borderh(20,20,1);
    borderv(20,1,1);

    for(p=1;p<=20;p++) //last vertical border
    {
    moveTo(p,39);
    printf("\x1b[47m  \x1b[0m"); //white border
    }
    moveTo(100,1); //moving cursor to somewhere else

    }//end of 24 program.


    else      // in between 20 and 120

    {
        printf("\x1b[2J");
        unsigned int i=0;
        unsigned int j=0;
        int k=1;
        int z=0;
        char new[132];
        char rev[132];
        while(i<132)
    {
        if(i==0)
            {new[0]=50+strlen(str);// 1st ch of hashing
            i++;}
        else if(i<=strlen(str)) //printf("%c",str[i]);
            {new[i]=str[i-1];
            i++;}
        else
        {

           for(j=0;j<strlen(str);j++)   //next letters repeating
                {
                    if(i+j<132)
                    {new[i+j]=str[j]+k;}
                }
         i=i+strlen(str);
         k++;
        }
    }

//end of hashed string

   for(i=0;i<132;i++)
    {
       if(i<=strlen(str))
      {   rev[i]=new[i];} //printing same letters as hashed one
      else
      {
          rev[i]=new[131-z];//reversing hashed parts
          z++;
      }
    } //every hashed elements are assigned to rev.

    //Getting relevant coordinates and printing qr in specified places
    position(2,3,color);
    position(2,63,color);
    position(32,3,color);
    int p,q;
    int r=0;

    //printing 1-100
    for(p=8;p<=35;p=p+3)
    {
        for(q=15;q<=69;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }
    //printing 101-116
    for(p=2;p<=5;p=p+3)
    {
        for(q=15;q<=57;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }

    //printing 117-132
    for(p=8;p<=29;p=p+3)
    {
        for(q=3;q<=9;q=q+6)
        {
            miniqr(rev[r],p,q,color);
            r++;
        }
    }

    //printing borders
    borderh(38,1,1);
    borderh(38,38,1);
    borderv(38,1,1);

    for(p=1;p<=37;p++) //last vertical border
    {
    moveTo(p,75);
    printf("\x1b[47m  \x1b[0m"); //white border
    }

    moveTo(40,1);//cursor moves to somewhere else

    }//end of 132

    }
return 0;
}//end of all program tnx...................................................................................

