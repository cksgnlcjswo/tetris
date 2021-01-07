/* 테트리스 게임
 * 만든이: 김영우, 김찬휘, 정성구
 *  
 * 이메일: rdd0426@gmail.com, cksgnlcjswoo@naver.com, musichead99@naver.com
 * 
 * */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "block.h"
#include "menu.h"

using namespace sf;
int point;

RenderWindow window(VideoMode(320,480), "Tetris");

int main(void) {

  while(window.isOpen()) {
    switch(mainMenu())
    {
      case 1:
        gameStart();
        break;
      case 2:
        // scoreBoard 함수 실행.
        break;
      case 3:
        window.close();
        break;
    }
  }

  return 0;
}
