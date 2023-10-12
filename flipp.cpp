#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;

#define delay Sleep
#define gotoxy gotoXY
#define random(x) rand()%x


void GET_CONSOLE_SIZE(int & HEIGHT_H, int & WIDTH_W)
{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        WIDTH_W = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        HEIGHT_H = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void randomize()
{
        time_t t;
        time(&t);
        srand(t);
}

void gotoXY(int X_AXIS,int Y_AXIS)
{
        COORD coordinates;
        coordinates.X=X_AXIS;
        coordinates.Y=Y_AXIS;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void setcursor(bool visible=0,DWORD size=0)
{
    if(size==0)
        size=20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize   = size;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&lpCursor);
}

int main()
{
    int state = 0;
    int flips = 0;
    int total_flips = 100;

    float head  = 0;
    float tail  = 0;
    float head_probab = 0;
    float tail_probab = 0;

    int row=0;
    int col=0;
    cout<<"ENTER TOTAL NUMBER OF FLIPS : ";
    cin>>total_flips;
    int h,w;
    GET_CONSOLE_SIZE(h,w);
    setcursor();
    randomize();
    do
    {
        state = rand()%2;
        flips++;

        if(state)
            head++;
        else
            tail++;

        head_probab = (head)/(head+tail);
        tail_probab = 1-head_probab;

        gotoxy(0,1);
          if(state)
            cout<<"HEAD";
          else
            cout<<"TAIL";

        gotoxy(0,2);
            cout<<"HEAD COUNT : "<<head;

        gotoxy(0,4);
            cout<<"TAIL COUNT : "<<tail;

        gotoxy(0,6);
           cout<<"TOTAL FLIPS : "<<flips<<"/"<<total_flips;

        gotoxy(0,8);
            cout<<"HEAD PROBABILITY : "<<head_probab;

        gotoxy(0,10);
            cout<<"TAIL PROBABILITY : "<<tail_probab;

        gotoxy(col,row+12);
           if(state)
             cout<<"H ";
           else
            cout<<"T  ";

        col = col + 2;
        if(col>=w-5)
        {
            col=0;
            row++;
        }


        delay(100);


    }while(flips!=total_flips);

    getch();
    return 0;
}

