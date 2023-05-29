#include "showfont.h"

ShowFont* ShowFont::m_instance = NULL;

ShowFont::ShowFont()
{

}

ShowFont::~ShowFont()
{

}

int ShowFont::display(char *buf, int pixelsize, int backgroundWidth, int backgroundHeight, int backgroundColor, int fontColor, int posXToLcd, int posYToLcd)
{

    font_show(this->lcd, buf, pixelsize, backgroundWidth, backgroundHeight, backgroundColor, fontColor, posXToLcd, posYToLcd);

}

void ShowFont::font_show(LcdDevice *lcd, char *text, int pixelsize, int backgroundWidth, int backgroundHeight, int backgroundColor, int fontColor, int posXToLcd, int posYToLcd)
{
    //打开字体
    font *f = fontLoad((char*)"/usr/share/fonts/DroidSansFallback.ttf");

    //字体大小的设置
    fontSetSize(f,pixelsize);

    int bgc_red = backgroundColor>>16;
    int bgc_green = (backgroundColor>>8) & 0xff;
    int bgc_blue = backgroundColor  & 0xff;
    //创建一个画板（点阵图）
    bitmap *bm = createBitmapWithInit(backgroundWidth,backgroundHeight,4,getColor(0,bgc_red,bgc_green,bgc_blue)); //也可使用createBitmapWithInit函数，改变画板颜色
    //bitmap *bm = createBitmap(288, 100, 4);

    //将字体写到点阵图上
    int font_red = fontColor>>16;
    int font_green = (fontColor>>8) & 0xff;
    int font_blue = fontColor  & 0xff;
    fontPrint(f,bm,0,0,text,getColor(0,font_red,font_green,font_blue),0);

    //把字体框输出到LCD屏幕上
    show_font_to_lcd((unsigned int*)Lcd::instance()->addr(),posXToLcd,posYToLcd,bm);

    //关闭字体，关闭画板
    fontUnload(f);
    destroyBitmap(bm);
}

ShowFont *ShowFont::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new ShowFont();
    }
    return m_instance;
}
