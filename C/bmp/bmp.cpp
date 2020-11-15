#include <stdio.h>
#include <malloc.h>
#include <disp.h>
#include <conio.h>

#define SCR_H	40
#define SCR_W	79

int main()
{
  int i;
  int red = 0, green = 0, blue = 0;
  char ch = '\0';
  int xpos = 0, ypos = 0;
  int width = 0;
  int height = 0;
  char filesize = 54;
  char * image = NULL;
  char header[54] = {'B', 'M', filesize,0,0,0, 0,0,0,0, 0x36,0,0,0, 0x28,0,0,0, width, height};

  printf("Enter height:");
  scanf("%d", &height);
  printf("Enter width:");
  scanf("%d", &width);

  image = (char *) malloc(sizeof(char) * (3*width+width%4) * height);

  header[2] += (3*width+width%4)*height;
  header[18] = width & 0xff; header[19] = width & 0xff00; header[20] = width & 0xff0000; header[21] = width & 0xff000000;
  header[22] = height & 0xff; header[23] = height & 0xff00; header[24] = height & 0xff0000; header[25] = height & 0xff000000;
  header[26] = 1; header[28] = 0x18;
  header[34] = (3*width+width%4)*height;

  disp_open();
  disp_move(0,0);
  disp_eeop();
  disp_setattr(0xff);

  for(i=0; i<(3*width+width%4)*height; i++)
    image[(3*width+width%4)*height-i-1] = 0xff;

  for(i=0; i<height*width; i++)
  {
    disp_move(i/height,i%width);
    disp_setattr(0xff);
    printf(" \b");
  }

  disp_move(0,0);
  disp_setattr(0);

  while(ch != 4)
  {
    if(kbhit() != 0)
      ch = getch();
    else
      ch = '\0';

    switch(ch)
    {
      case 'h': if(xpos > 0)				xpos--; break;
      case 'l': if(xpos < SCR_W && xpos < width)	xpos++; break;
      case 'j': if(ypos < SCR_H	&& ypos < height)	ypos++; break;
      case 'k': if(ypos > 0)				ypos--; break;

      case 'c':
      disp_setattr(7);

      disp_move(SCR_H,0); disp_eeol();
      printf("color - red:");
      scanf("%x", &red);

      disp_move(SCR_H,0); disp_eeol();
      printf("color - green:");
      scanf("%x", &green);

      disp_move(SCR_H,0); disp_eeol();
      printf("color - blue:");
      scanf("%x", &blue);

      break;

      case ' ':
      printf(" \b");
      image[(ypos*width+xpos)*3+ypos*width%4+0] = blue;
      image[(ypos*width+xpos)*3+ypos*width%4+1] = green;
      image[(ypos*width+xpos)*3+ypos*width%4+2] = red;
      break;
    }
    disp_move(ypos, xpos);
  }

  disp_close();

  FILE * ofp = fopen("image.bmp", "w");

  for(i=0; i<54; i++)
    putc(header[i], ofp);

  for(i=0; i<(3*width+width%4)*height; i++)
    putc(image[(3*width+width%4)*height-i-1],ofp);

  fclose(ofp);

  return 0;
}