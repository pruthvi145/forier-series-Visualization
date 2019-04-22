#include<graphics.h>
#include<math.h>
#include<vector>

#define PI 3.1415

/**Global Variables **/
float angle = 0;
int n = 6; // change it to see difference - To generate more accurate Waves
std::vector<float> wave;


void intro()
{
    setcolor(COLOR(38,224,165));
    settextstyle(10,HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(getmaxx()/2,getmaxy()/2,"Fourier Series Visualization - SQUARE WAVE");
    setcolor(15);
    settextstyle(8,HORIZ_DIR, 1);
    outtextxy(getmaxx()/2,getmaxy()/2+50,"*press Space or any key to get started!");
}
void loop()
{
  cleardevice();

    float x = 0;
    float y = 0;
    for (int i = 0; i < n; i++)
    {
        float cx = x;
        float cy = y;
        float n = i * 2 + 1;
        float radius =100 * (4 / (n * PI));
        x += radius * cos(n * angle/2);
        y += radius * sin(n * angle/2);

        circle(cx, cy, radius);
        line(cx, cy, x, y);
        fillellipse(x, y, 3,3);
  }
  wave.insert(wave.begin(),y);

  line(x, y, 300, wave.at(0));
  fillellipse(300, wave.at(0), 5, 5);

    for (int i = 1; i < wave.size(); i++)
    {
        //putpixel(i+300, wave.at(i),15);
        setcolor(15);
        line(300+i-1,wave.at(i-1),300+i, wave.at(i));
        setcolor(COLOR(77,166,225));
    }

  angle += 0.09;
}
int main()
{
    initwindow(1200,800);
    intro();
    getch();

    setviewport(getmaxx()/4, getmaxy()/2, getmaxx(), getmaxy(), 0); //used for transforming Origin

    setcolor(COLOR(77,166,225));
    while(true)
        loop();

    return 0;
}
