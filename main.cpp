#include <graphics.h>
#include <bitmap_image.hpp>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NOMINMAX

//! @ AUTHOR : SHEME HAMITAJ 
 

int radius=5;
bitmap_image savethis(1187,595);

int rgb_tographicsColor(int red, int green , int blue){

    if(red == 0 && green ==0 && blue == 0)
    return 0;

    if(red == 0 && green ==0 && blue == 255)
    return 1;

    if(red == 0 && green ==128 && blue == 0)
    return 2;

    if(red == 0 && green ==128 && blue == 128)
    return 3;

    if(red == 128 && green ==0 && blue == 0)
    return 4;

    if(red == 128 && green ==0 && blue == 128)
    return 5;

    if(red == 128 && green ==128 && blue == 0)
    return 6;

    if(red == 192 && green ==192 && blue == 192)
    return 7;

    if(red == 128 && green ==128 && blue == 128)
    return 8;

    if(red == 128 && green ==255 && blue == 255)
    return 9;

    if(red == 128 && green ==255 && blue == 128)
    return 10;

    if(red == 128 && green ==255 && blue == 255)
    return 11;

    if(red == 255 && green ==128 && blue == 128)
    return 12;

    if(red == 255 && green ==128 && blue == 255)
    return 13;

    if(red == 255 && green ==255 && blue == 0)
    return 14;

    if(red == 255 && green ==255 && blue == 255)
    return 15;

    return 404; //!on default return 404 (debug)

}

void graphics_color2rgb(){
        int gColor, i ,j;
        for(i = 8 ; i< 1195 ; i++)
        {
            for(j = 100 ; j < 695 ;j++)
            {
                gColor = getpixel(i,j);

                switch (gColor){ /// get colors from graphics.h and transfer it to bitmap RGB color

                    case 0:
                        savethis.set_pixel(i-8,j-100,0,0,0);
                        break;

                    case 1:
                        savethis.set_pixel(i-8,j-100,0,0,255);
                        break;

                    case 2:
                        savethis.set_pixel(i-8,j-100,0,128,0);
                        break;

                    case 3:
                        savethis.set_pixel(i-8,j-100,0,128,128);
                        break;

                    case 4:
                        savethis.set_pixel(i-8,j-100,128,0,0);
                        break;

                    case 5:
                        savethis.set_pixel(i-8,j-100,128,0,128);
                        break;

                    case 6:
                        savethis.set_pixel(i-8,j-100,128,128,0);
                        break;

                    case 7:
                        savethis.set_pixel(i-8,j-100,192,192,192);
                        break;

                    case 8:
                        savethis.set_pixel(i-8,j-100,128,128,128);
                        break;

                    case 9:
                        savethis.set_pixel(i-8,j-100,128,255,255);
                        break;

                    case 10:
                        savethis.set_pixel(i-8,j-100,128,255,128);
                        break;

                    case 11:
                        savethis.set_pixel(i-8,j-100,128,255,255);
                        break;

                    case 12:
                        savethis.set_pixel(i-8,j-100,255,128,128);
                        break;

                    case 13:
                        savethis.set_pixel(i-8,j-100,255,128,255);
                        break;

                    case 14:
                        savethis.set_pixel(i-8,j-100,255,255,0);
                        break;

                    case 15:
                        savethis.set_pixel(i-8,j-100,255,255,255);
                        break;

                    default:
                        break;
                }
            }
    }
}

void hintbar(char *hints, int col) /// reset and write hints into hintbar
{
    setfillstyle(SOLID_FILL, WHITE);
    bar(400,20,800,80); // reset white bar
    setbkcolor(WHITE);
    setcolor(0);
    outtextxy(410,40,hints);
    setfillstyle(SOLID_FILL,col);
    bar(760,40,780,60);
}


const char * opath() /// get open path
{
  char filename[ MAX_PATH ];
  ZeroMemory( &filename, sizeof( filename ) );

  OPENFILENAME oFilename;

    ZeroMemory( &oFilename,      sizeof( oFilename ) );
    oFilename.lStructSize  = sizeof( oFilename );
    oFilename.lpstrFilter  = "Bitmap\0*.bmp\0Any File\0*.*\0";
    oFilename.lpstrFile    = filename;
    oFilename.nMaxFile     = MAX_PATH;
    oFilename.lpstrTitle   = "Select a File";
    oFilename.Flags        = OFN_FILEMUSTEXIST;

    GetOpenFileNameA( &oFilename ); //! this is the command to get path from opening dialog


  if(strcmp(filename,"")!=0)
    {
        return filename;
    }
    else
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(400,20,800,80); // reset white bar

        setbkcolor(WHITE);
        setcolor(0);
        outtextxy(410,40,"You cancelled.");
        return "";

    }
}

const char * spath() /// get save path
{
   char filename[MAX_PATH];
   ZeroMemory( &filename, sizeof( filename ) );

   OPENFILENAME sFilename;

    ZeroMemory(&sFilename, sizeof(sFilename));
    sFilename.lStructSize = sizeof(sFilename);
    sFilename.lpstrFilter  = "Bitmap\0*.bmp\0Any File\0*.*\0";
    sFilename.lpstrFile = filename;
    sFilename.nMaxFile = MAX_PATH;
    sFilename.lpstrTitle   = "Select a path to save your image";
    sFilename.lpstrDefExt="bmp";

    GetSaveFileName(&sFilename); //! this is the command to get path from saving dialog

    if(strcmp(filename,"")!=0)
    {
        return filename;
    }
    else
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(400,20,800,80); // reset white bar

        setbkcolor(WHITE);
        setcolor(0);
        outtextxy(410,40,"You cancelled.");
        return "";

    }
}

void pWindow() /// BUILD MAIN WINDOW
{
    setfillstyle(SOLID_FILL, 8);
    bar(3,3,1200,700); // whole window in dark grey
    setfillstyle(SOLID_FILL, 15);
    int i,j,o,k;
    setcolor(15);

    ///BUILD THE INTERFACE
    setcolor(7);

        // OPENING ANIMATION
                o=70;
                for(i=9; i<13;i++)
                {
                    setfillstyle(SOLID_FILL, i);
                    bar(378-o,470-o,830+o,330+o);
                    o+=70;
                    delay(333);
                }

                setfillstyle(SOLID_FILL, WHITE);
                bar(8,100,1195,695); // painting window

                for(j=8;j<=1195;j++)
                    {
                    for(i=95,o=695;i<=100, o <=700;i++,o++)
                        {
                        putpixel(j,i,7);
                        putpixel(j,o,7);
                        }
                    }
                for(i=700;i>=95;i--)
                    {
                    for(j=8, o=1200;j>=3, o>=1195;j--, o--)
                        {
                        putpixel(j,i,7);
                        putpixel(o,i,7);
                        }
                    }
                for(i=95;i>=3;i--)
                    {
                    for(j=100, o=1100;j>=95, o>=1095;j--, o--)
                        {
                        putpixel(j,i,7);
                        putpixel(o,i,7);
                        }
                    }
        //END OF ANIMATION



    for (i=0,o=8,k=31;i<3;i++,o+=28,k+=28) // 3 buttons , open, exit, save
        {
        bar(8,o,90,k);
        setfillstyle(SOLID_FILL, 7);
        bar(11,o+3,87,k-3);
        setfillstyle(SOLID_FILL,15);

        }

    setbkcolor(7);
    setcolor(0);

    outtextxy(32,12,"OPEN");
    outtextxy(34,40,"EXIT");
    outtextxy(34,68,"SAVE");

    for (i=0,o=115,k=165;i<5;i++,o+=55,k+=55) // 5 buttons , left of the hint bar
        {
        bar(o,25,k,75);
        setfillstyle(SOLID_FILL, 7);
        bar(o+3,28,k-3,72);
        setfillstyle(SOLID_FILL,15);
        }


    setbkcolor(7);
    setcolor(0);
    outtextxy(120,41,"Pencil");

    setbkcolor(7);
    setcolor(0);
    outtextxy(175,41,"Line");
    line(170,60,220,60);
    line(170,61,220,61);
    line(170,62,220,62);

    setbkcolor(7);
    setcolor(0);
    outtextxy(230,31,"Circle");
    circle(250,57,8);
    circle(250,57,7);

    setbkcolor(7);
    setcolor(0);
    outtextxy(287,31,"Rect.");
    rectangle(290,51,315,65);
    rectangle(289,50,314,64);

    setbkcolor(7);
    setcolor(0);
    outtextxy(339,31,"Triang");
    line(352,64,367,64);
    line(352,64,360,52);
    line(360,52,367,64);



    setbkcolor(0);
    setcolor(15);
    outtextxy(1111,12,"140201113");
    outtextxy(1111,32,"140201113");

    bar(1110,55,1185,85);
    setbkcolor(15);
    setcolor(4);
    outtextxy(1120,62,"Color Fill");

    setfillstyle(SOLID_FILL, 0);
    bar(395,15,795,75);
    bar(395,15,795,75);
    for(i=395,j=15,o=795,k=75 ; i<=400,j<=20,o<=800,k<=80;i++,k++,o++,j++){ //3D bar
        bar(i,j,o,k);
    }
    setfillstyle(SOLID_FILL,15);
    bar(400,20,800,80);
    setcolor(0);
    outtextxy(410,40,"Welcome , this is the hint box"); // hint box
    setfillstyle(SOLID_FILL,1);
    bar(760,40,780,60);

//Interface closed

//Colors:
    setfillstyle(SOLID_FILL,7);
    bar(806,16,1019,80);
    for(i=0,o=810,k=835;i<=6;i++,o+=30,k+=30) // line1 of colors
    {
        setfillstyle(SOLID_FILL, i);
        bar(o,20,k,45);
    }
    for(i=9,o=810,k=835;i<=15;i++,o+=30,k+=30) // line 2 of colors
    {
        setfillstyle(SOLID_FILL, i);
        bar(o,51,k,76);
    }


setcolor(15);
for(i=1;i<8;i++)
{
    circle(1050,24,i);
}
setcolor(0);
setbkcolor(8);
outtextxy(1037,32, "7px");

setcolor(15);
for(i=1;i<6;i++)
{
    circle(1040,58,i);
}
setcolor(0);
setbkcolor(8);
outtextxy(1027,63, "5px");

setcolor(15);
circle(1070,58,1);
setcolor(0);
setbkcolor(8);
outtextxy(1057,63, "1px");

bitmap_image(8,100);


//End of Colors

}


int start_acting(int xcoord, int ycoord,char command,int color) /// execute commands
{
        setcolor(color);
        if(command=='e') /// exit command
        {
            hintbar("Exiting...", color);

        delay(1696);
        exit(1);
        }
        else if(command=='p') /// pencil command
            {
                clearmouseclick(WM_LBUTTONUP);
                while(!ismouseclick(WM_LBUTTONUP))
                    {
                        if(xcoord < 1195 && xcoord > 8 && ycoord < 695 && ycoord >100) // paint  pixels around mouse
                            {

                                        for(int y=-radius; y<=radius; y++){

                                                for(int x=-radius; x<=radius; x++){
                                                        if(x*x+y*y <= radius*radius)
                                                        putpixel(xcoord+x, ycoord+y, color);
                                                }

                                            }

                        xcoord= mousex() , ycoord= mousey();
                            }
                            else
                            {
                            break;
                            }
                    }
            }
            else if(command=='l') ///line command
            {
                int lx,ly;
                hintbar("Click end point of line inside the box ", color);
                while(1){
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        lx = mousex();
                        ly = mousey();
                        clearmouseclick(WM_LBUTTONDOWN);
                    }

                    if(lx<=1195 && lx >= 8 && ly<=695 && ly>=100)
                    {
                        break;
                    }
                    else
                    {
                        setbkcolor(WHITE);
                        setcolor(0);
                        outtextxy(410,40,"Please, Click end point of line inside the box ");
                    }

                }
                setcolor(color);
                line(xcoord,ycoord,lx,ly);
                hintbar("Line Selected, click start point", color);
            }
            else if(command=='c') /// circle command
            {
                int r,cx,cy;
                hintbar("Click the end of the circle's radius inside the box", color);
                    while(1)
                    {

                        if(ismouseclick(WM_LBUTTONDOWN)){

                            cx = mousex();
                            cy = mousey();
                            clearmouseclick(WM_LBUTTONDOWN);
                            }
                        if(cx<=1195 && cx >= 8 && cy<=695 && cy>=100)
                            {
                                r= sqrt(pow((cx-xcoord) , 2) + pow((cy-ycoord) , 2) );
                                break;
                            }

                    }
                    /// manually paint circle by checking if points are on the circle

                //center : xcoord, ycoord ; radius: r ;
                for(int i=8; i <=1195; i++)
                {
                    for(int j=100; j<=695;j++)
                    {
                        if(abs(r - sqrt(pow((xcoord-i) , 2) + pow((ycoord-j) , 2)))<=1)
                        {
                            putpixel(i,j,color);
                        }
                    }
                }

                hintbar("Circle Selected, click the center", color);

            }
            else if(command=='r') ///rectangle command
            {
                int rx,ry;
                hintbar("Click end point of line inside the box ",color);
                while(1)
                {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        rx = mousex();
                        ry = mousey();
                        clearmouseclick(WM_LBUTTONDOWN);
                    }

                    if(rx<=1195 && rx >= 8 && ry<=695 && ry>=100)
                    {
                        break;
                    }
                    else
                    {
                        setbkcolor(WHITE);
                        setcolor(0);
                        outtextxy(410,40,"Please, Click end point of line inside the box ");

                    }

                }
                setcolor(color);
                rectangle(xcoord,ycoord,rx,ry);
                rectangle(xcoord-1,ycoord-1,rx-1,ry-1);
                hintbar("Rectangle selected, click start point", color);

            }
            else if(command=='t') ///triangle command
            {
                int tx,ty,tx1,ty1;
                hintbar("Please, Click 3 points of triangle inside the box ", color);
                while(1)
                {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        tx = mousex();
                        ty = mousey();
                        clearmouseclick(WM_LBUTTONDOWN);
                    }

                    if(tx<=1195 && tx >= 8 && ty<=695 && ty>=100)
                    {
                        break;
                    }
                    else
                    {
                        setbkcolor(WHITE);
                        setcolor(0);
                        outtextxy(410,40,"Please, Click 2 other points of triangle inside the box ");
                    }

                }

                while(1)
                {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        tx1 = mousex();
                        ty1 = mousey();
                        clearmouseclick(WM_LBUTTONDOWN);
                    }

                    if(tx1<=1195 && tx1 >= 8 && ty1<=695 && ty1>=100)
                    {
                        break;
                    }
                    else
                    {
                        setbkcolor(WHITE);
                        setcolor(0);
                        outtextxy(410,40,"Please, Click 2 other points of triangle inside the box ");
                    }

                }
                setcolor(color);
                line(xcoord,ycoord,tx,ty);
                line(xcoord,ycoord,tx1,ty1);
                line(tx1,ty1,tx,ty);

                hintbar("Triangle Selected, click start point", color);
            }
            else if(command=='o') ///open image
            {


                const char* helper=opath();
                char patho[199];
                strcpy(patho, helper);

                if(strcmp(patho,"")!=0)
                {
                    hintbar("Opening your file...", color);

                    bitmap_image openthis(patho);

                    if (!openthis)
                    {
                        hintbar("File couldn't be opened", color);
                    }
                    else
                    {
                        int x,y,graph_color;
                        int de_bug=0;
                        for (y = 0; y < 595; ++y)
                        {
                            for (x = 0; x < 1187; ++x)
                            {
                                rgb_t colour;
                                openthis.get_pixel(x, y, colour);

                                graph_color = rgb_tographicsColor(colour.red , colour.green , colour.blue);
                                if(graph_color == 404)
                                {
                                        graph_color = 0;
                                        de_bug = 1;
                                }

                                if(getpixel(x+8,y+100) != graph_color)
                                    putpixel(x+8,y+100,graph_color);

                            }
                        }
                    (de_bug == 0) ? hintbar("File opened successfully", color) : hintbar("Unrecognized color , replaced with black", color);

                    }
                }
            }
            else if(command=='s') ///save image
            {
                const char* helper=spath();
                char paths[199];
                strcpy(paths,helper);

                if(strcmp(paths,"")!=0)
                {
                hintbar("File is being saved...", color);

                    graphics_color2rgb();

                    savethis.save_image(paths);

                hintbar("File Successfully Saved ", color);
                }
            }
            else
            {
                hintbar("Please, select a tool ", color);
                return(1);
            }
}


void mouseclick() /// clicking buttons (coordinates)
{
    int xcoord,ycoord,color=1;
    char command = 'p';

while(1) //!Here starts an infinite loop to detect mouse clicking and to paint
    {
        clearmouseclick(WM_LBUTTONDOWN);
        delay(10);

        if(ismouseclick(WM_LBUTTONDOWN)) ///Detects Mouse Left-Click
            {
                xcoord = mousex(); ycoord = mousey();//gets x and y of mouse position
                clearmouseclick(WM_LBUTTONDOWN);
            if(ycoord<95 && ycoord>3 && ((xcoord>0 && xcoord<805) || (xcoord>1095 && xcoord<1200)) )
            {
                    if(ycoord<31&& ycoord>8 && xcoord<90 && xcoord>8) // open coordinates
                    {

                    start_acting(xcoord,ycoord,'o',color); // open
                    }
                    if(ycoord<59&& ycoord>36 && xcoord<90 && xcoord>8) // exit coordinates
                    {
                    start_acting(xcoord,ycoord,'e',color);// exit
                    }
                    if(ycoord<87&& ycoord>64 && xcoord<90 && xcoord>8) // save coordinates
                    {
                    start_acting(xcoord,ycoord,'s',color); //save
                    }
                    else if(xcoord<1185 && xcoord>1110 && ycoord<85 && ycoord>55) //reset & fill color
                    {
                        setfillstyle(SOLID_FILL, 7);
                        bar(3,95,1200,700);
                        setfillstyle(SOLID_FILL, color);
                        bar(8,100,1195,695);
                    }
                    else if(ycoord<75 && ycoord>25)
                    {
                        if(xcoord<165 && xcoord>115)
                        {
                            command='p'; //pencil
                            hintbar("Pencil Selected, start drawing", color);
                        }
                        else if(xcoord<220 && xcoord>170)
                        {
                            command = 'l'; //line
                            hintbar("Line Selected, click start point", color);
                        }else if(xcoord<275 && xcoord>225)
                        {
                            command = 'c'; //circle
                            hintbar("Circle Selected, click the center", color);
                        }else if(xcoord<330 && xcoord>280)
                        {
                            command = 'r'; //rectangle
                            hintbar("Rectangle Selected, click start point", color);
                        }else if(xcoord<385 && xcoord>335)
                        {
                            command = 't'; //triangle
                            hintbar("Triangle Selected, click start point", color);
                        }
                    }
                    else
                    {
                        command='n'; //neutral
                    }
                    //!test : printf("\n%c", command);
                    //!test : printf("\nx: %d y: %d", xcoord, ycoord);

            }
            else if(xcoord<1195 && xcoord>8 && ycoord<695 && ycoord>100) /** clicking inside the box gives the start_acting() command*/
            {
                start_acting(xcoord,ycoord,command,color);
            }
            else if(ycoord<45 && ycoord>20 && (xcoord>805 && xcoord <1095)) //choose colors
                {
                    if(xcoord<835 && xcoord>810)
                    {
                        color=0;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<865 && xcoord>840)
                    {
                        color=1;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<895 && xcoord>870)
                    {
                        color=2;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<925 && xcoord>900)
                    {
                        color=3;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<955 && xcoord>930)
                    {
                        color=4;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<985 && xcoord>960)
                    {
                        color=5;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<1015 && xcoord>990)
                    {
                        color=6;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }

                    if(xcoord<1068 && xcoord>1035) // radius 7 px
                    {
                        radius = 7;
                        hintbar("Radius changed to 7 px", color);

                    }
                }
            else if(ycoord<76 && ycoord>51 && (xcoord>805 && xcoord <1095)) //choose colors
                {
                    if(xcoord<835 && xcoord>810)
                    {
                        color=9;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<865 && xcoord>840)
                    {
                        color=10;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<895 && xcoord>870)
                    {
                        color=11;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<925 && xcoord>900)
                    {
                        color=12;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<955 && xcoord>930)
                    {
                        color=13;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<985 && xcoord>960)
                    {
                        color=14;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }
                    if(xcoord<1015 && xcoord>990)
                    {
                        color=15;
                        setfillstyle(SOLID_FILL,color);
                        bar(760,40,780,60);
                    }

                    if(xcoord<1052 && xcoord>1026) // radius 5 px
                    {
                        radius = 5;
                        hintbar("Radius changed to 5 px", color);
                    }
                    if(xcoord<1082 && xcoord>1056) // radius 1 px
                    {
                        radius = 1;
                        hintbar("Radius changed to 1 px", color);
                    }
                }
                else command='n';
            }
    }
}


int main()
{
    printf("Close this window to terminate the program! \n");
    initwindow(1203, 703,"Paint",50,5); /// main window : 1203 x 703 , open at point(50,5)
    pWindow();
    mouseclick();
}
