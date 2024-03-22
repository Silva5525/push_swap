#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#define ROW 21
#define COL 72

enum move {UP, DOWN, LEFT, RIGHT, STOP} direction;
enum ghost_move {UP1, DOWN1, LEFT1, RIGHT1, STOP1} ghost1_dir, ghost2_dir;

void move_car(enum move dir);
void ghost1_direction();
void ghost2_direction();
void ghost1_move(enum ghost_move g1_dir);
void ghost2_move(enum ghost_move g2_dir);
int car_1r, car_1c, car_2r, car_2c;
int ghost1_r, ghost1_c;
int ghost2_r, ghost2_c, ghost11, ghost22;
char grid[ROW][COL]= {
	"***********************************************************************",
	"*                                          &                          *",
	"*   ********   *********   ***************   ********************     *",
	"*   *      *   *       *   *             *   *                  *     *",
	"*   *      *   *       *   *             *   *                  *     *",
	"*   *      *   *       *   *             *   *                  *     *",
	"*   *      *   *       *   *             *   *                  *     *",
	"*   ********   *********   ***************   ********************     *",
	"*                                :                                   *",
	"*   ****************************   ******************************     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   *                          *   *                            *     *",
	"*   ****************************   ******************************     *",
	"*                 @                                                   *",
	"***********************************************************************"};

void print_grid();

int getch(void) {
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    direction = STOP;
    ghost1_dir = STOP1;
    ghost2_dir = STOP1;
    int count = 200;
    car_1r = 8;
    car_1c = 33;
    car_2r = 8;
    car_2c = 34;
    ghost1_r = 1;
    ghost1_c = 43;
    ghost2_r = 19;
    ghost2_c = 18;
    char ch;
    print_grid();
    ghost1_direction();
    ghost2_direction();

    while (count) {
        // Lese einen einzelnen Tastenanschlag ein
       
		if ((ch = getch()) != -1)
		{
			// Verarbeite die Eingabe und ändere die Richtung entsprechend
			switch (ch) {
				case 'd':
					direction = RIGHT;
					break;
				case 'a':
					direction = LEFT;
					break;
				case 'w':
					direction = UP;
					break;
				case 's':
					direction = DOWN;
					break;
				default:
					break;
			}
		}
      
        // Aktualisiere die Positionen basierend auf den Richtungen
        move_car(direction);
        ghost1_move(ghost1_dir);
        ghost2_move(ghost2_dir);

        usleep(100); // Simuliere eine Verzögerung von 100ms
        system("clear"); // Lösche den Bildschirm, um das Spielfeld zu aktualisieren
        print_grid();
        count--; // Reduziere den Zähler für die Schleifeniteration (eine einfache Implementierung des Spielablaufs)
    }

    return 0;
}

void print_grid()
{
    int i;

    for(i=0;i<ROW;i++)
    printf("%s\n",grid[i]);

    printf("\ng2:%d dir: %d\n",ghost22,ghost2_dir);

    printf("\ng2:%d g2:%d\n",ghost2_r,ghost2_c);

}
void move_car(enum move dir)
{
    if(dir==UP)
    {
        if(grid[car_1r-1][car_1c]!= '*'& grid[car_2r-1][car_2c]!='*')
        {
           grid[car_1r][car_1c]=' ';
           grid[car_1r-1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r-1][car_2c]=':';
           car_1r--;
           car_2r--;
            //printf("\nUP UP UP\n");
        }
    }
    else if(dir==DOWN)

    {
        if(grid[car_1r+1][car_1c]!= '*'& grid[car_2r+1][car_2c]!='*')
      {
           grid[car_1r][car_1c]=' ';
           grid[car_1r+1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r+1][car_2c]=':';
           car_1r++;
           car_2r++;
           printf("\nDOWN\n");
      }
    }
    if(dir==LEFT)
    {
       if(grid[car_1r][car_1c-1]!= '*'& grid[car_2r][car_2c-1]!='*')
       {
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c-1]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c-1]=':';
           car_1c--;
           car_2c--;
      }
    }
    else if(dir==RIGHT)

    {
       if(grid[car_1r][car_1c+1]!= '*'& grid[car_2r][car_2c+1]!='*')
       {
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c+1]=':';
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c+1]=':';

           car_1c++;
           car_2c++;
       }
    }
}
void ghost1_direction()
{
    int ghost1;
    srand((unsigned) time(NULL));

    ghost1=(rand()%4)+1;


    if(ghost1==1)
        ghost1_dir=UP1;
        else if(ghost1==2)
            ghost1_dir=DOWN1;
    if(ghost1==3)
       ghost1_dir=LEFT1;
       else
        ghost1_dir=RIGHT1;
}

void ghost2_direction()
    {
        int ghost2;
        //srand((unsigned) time(NULL));
        ghost2=(rand()%4)+1;

        switch(ghost2)
        {
        case 1:
        case 3:


                ghost2_dir=LEFT1;
                break;

        case 2:
        case 4:

                ghost2_dir=RIGHT1;
                break;

        }

        ghost22=ghost2;
    }


void ghost1_move(enum ghost_move g1_dir)
{
 // Beep(200,200);
  int x,y;
  if(g1_dir==UP1)
  {

      if(grid[ghost1_r-1][ghost1_c]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r-1][ghost1_c]='&';
          ghost1_r--;

          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {
              x=rand()%2;
                switch (x)
                {
                case 0:

                        ghost1_dir = LEFT1;
                         break;


                case 1:

                        ghost1_dir = RIGHT1;
                        break;


                }
          }


          else if(grid[ghost1_r][ghost1_c]==grid[8][3])
            {
                x=rand()%2;
                switch (x)
                {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


                }
            }
         else if(grid[ghost1_r][ghost1_c]==grid[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }

         }

    }
  }
  else if (g1_dir==DOWN1)
  {
      if(grid[ghost1_r+1][ghost1_c]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r+1][ghost1_c]='&';
          ghost1_r++;

           if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]
              ==grid[8][24]||grid[ghost1_r][ghost1_c]== grid[8][43]||grid[ghost1_r][ghost1_c] == grid[19][33])
           {
               x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;



            }
           }


           else if(grid[ghost1_r][ghost1_c]==grid[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
      }

  }
  if(g1_dir==LEFT1)
  {

      if(grid[ghost1_r][ghost1_c-1]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c-1]='&';
          ghost1_c--;
          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {
              x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
         else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

            }
         }

      }


  }
  else if (g1_dir==RIGHT1)
  {
      if(grid[ghost1_r][ghost1_c+1]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c+1]='&';
          ghost1_c++;

          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {

            x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

            }
         }
      }

  }
}


void ghost2_move(enum ghost_move g2_dir)
{
 //Beep(200,250);
    int x,y;

    if(g2_dir==LEFT1)
    {

        if(grid[ghost2_r][ghost2_c-1]!= '*')
        {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r][ghost2_c-1]='@';
          ghost2_c--;

            if(grid[ghost2_r][ghost2_c]==grid[19][33])
            {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
                {
                    case 0:
                    break;
                    case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }

                }
           }
            else if(grid[ghost2_r][ghost2_c]==grid[19][3])
            {
                 x=rand()%2;
                 if(x==0||x==1)
                switch (x)
                {
                    case 0:
                        {
                            ghost2_dir= UP1;
                        break;
                        }

                    case 1:
                        {
                        ghost2_dir = RIGHT1;
                        break;
                        }

                }
            }
            if(grid[ghost2_r][ghost2_c]==grid[8][43]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][12])
            {
                x=rand()%2;
                if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = UP1;
                    break;
                    }

              }
            }
           else if(grid[ghost2_r][ghost2_c]==grid[8][33])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
              }

           }
           if(grid[ghost2_r][ghost2_c]==grid[1][3])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
             }
          }
          else if(grid[ghost2_r][ghost2_c]==grid[1][12]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c]==grid[1][43])
          {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir=LEFT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                        break;
                    }
             }
          }
        }
    }//if left
      if (g2_dir==RIGHT1)
        {
            if(grid[ghost2_r][ghost2_c+1]!= '*')
            {
                grid[ghost2_r][ghost2_c+1]='@';
                grid[ghost2_r][ghost2_c]=' ';
                ghost2_c++;


                if(grid[ghost2_r][ghost2_c]==grid[19][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                        break;
                        case 1:
                        {
                            ghost2_dir = UP1;
                        break;
                        }

                    }
                }
               else if(grid[ghost2_r][ghost2_c]==grid[19][68])
                 {
                  x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][43]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][12])
                {


                   x=rand()%2;
                   if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
        }//if with *

     }//if Right
     if (g2_dir==UP1)
     {

             if(grid[ghost2_r-1][ghost2_c]!= '*')
            {
                grid[ghost2_r][ghost2_c]=' ';
                grid[ghost2_r-1][ghost2_c]='@';
                ghost2_r--;

                if(grid[ghost2_r][ghost2_c]==grid[8][3])
                {

                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }

                    }
                }
                else if (grid[ghost2_r][ghost2_c]==grid[8][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }

                if(grid[ghost2_r][ghost2_c]==grid[1][12]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c] == grid[1][43])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][3])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }
                    }
                }
        }
     }// up1
     if (g2_dir==DOWN1)
     {
         if(grid[ghost2_r+1][ghost2_c]!= '*')
      {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r+1][ghost2_c]='@';
          ghost2_r++;

           if(grid[ghost2_r][ghost2_c]==grid[8][3])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {

                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
           else if(grid[ghost2_r][ghost2_c]==grid[8][12])
           {
             x=rand()%2;
             if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                       ghost2_dir = RIGHT1;
                       break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }
              }
           }
          else if(grid[ghost2_r][ghost2_c]==grid[8][43])
            {
                     x=rand()%2;
                     if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }

                        case 1:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }
                    }
            }
       }
     }
}