/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
/** Note: This class is closely modeled
	after the book code from...
		Multi-Threaded Game Engine Design
		Copyright 2010 by Jonathan Harbour
**/
#include "Engine_Core.h"
using namespace std;

namespace Smoke 
{
	Font::Font() {}

    Font::Font(string name, int pointsize)
    {
        fontObj = NULL;

        D3DXFONT_DESC fontDesc = {
            pointsize,              //height
            0,                      //width
            0,                      //weight
            0,                      //miplevels
            false,                  //italic
            DEFAULT_CHARSET,        //charset
            OUT_TT_PRECIS,          //output precision
            CLIP_DEFAULT_PRECIS,    //quality
            DEFAULT_PITCH,          //pitch and family
            ""
        };
        strcpy_s(fontDesc.FaceName, name.c_str());

        D3DXCreateFontIndirect(g_Engine->GetDevice(), &fontDesc, &fontObj);
    }

    void Font::Print(int x, int y, string text, D3DCOLOR color)
    {
        //figure out the text boundary
        RECT rect = { x, y, 0, 0 };
        fontObj->DrawText( NULL, text.c_str(), (int)text.length(), &rect, DT_CALCRECT, color); 

        //print the text
        fontObj->DrawText( g_Engine->GetSpriteObj(), text.c_str(), (int)text.length(), &rect, DT_LEFT, color); 
    }

    int Font::getTextWidth(std::string text)
    {
        RECT rect = { 0, 0, 0, 0 };
        fontObj->DrawText( NULL, text.c_str(), (int)text.length(), &rect, DT_CALCRECT, 0xffffffff); 
        return rect.right;
    }

    int Font::getTextHeight(std::string text)
    {
        RECT rect = { 0, 0, 0, 0 };
        fontObj->DrawText( NULL, text.c_str(), (int)text.length(), &rect, DT_CALCRECT, 0xffffffff); 
        return rect.bottom;
    }

};
