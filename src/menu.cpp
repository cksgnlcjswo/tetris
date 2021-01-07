#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;

extern RenderWindow window;

/* pausemenu 함수 */
bool pauseMenu()
{
    Texture pause, returnButton, exitButton;
    pause.loadFromFile("../image/menu.png");
    returnButton.loadFromFile("../image/return.png");
    exitButton.loadFromFile("../image/exit.png");
    Sprite menu(pause), rButton(returnButton), eButton(exitButton);

    /* load한 파일들 위치 설정 */
    menu.move(25,54);	
    rButton.move(48,120);
    eButton.move(48,255);

    /* 현재 메뉴의 어떤 버튼을 선택하고 있는지 확인하기 위한 flag */
    bool menuFlag = true;
    
    Event e;

    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed) window.close(); 
            if(e.type == Event::KeyPressed)
            {
                if(e.key.code == Keyboard::Up) menuFlag = true;
                else if(e.key.code == Keyboard::Down) menuFlag = false;
                else if(e.key.code == Keyboard::Space || e.key.code == Keyboard::Enter)
                {
                    if(menuFlag) return true;
                    else window.close();
                }
		else if(e.key.code == Keyboard::Escape) return true;
            }
        }
	/* 메뉴 그리기 */
	window.draw(menu);
	if(menuFlag) window.draw(rButton);
	else window.draw(eButton);
	window.display();
    }
    return false;
}
