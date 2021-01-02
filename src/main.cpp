/* 테트리스 게임
 * 만든이: 김영우, 김찬휘, 정성구
 * 이메일:        , cksgnlcjswoo@naver.com, musichead99@naver.com
 * 
 * */

#include <SFML/Graphics.hpp>
#include "map.h"
#include "block.h"

using namespace sf;

int main(void) {
  bool rotate = false;
  float delay = 0;
  int dx= 0;

  RenderWindow window(VideoMode(320,480), "Tetris");
  
  /*이미지 로드*/
  Texture t1,t2,t3;
  t1.loadFromFile("../image/tiles.png");
  t2.loadFromFile("../image/background.png");
  t3.loadFromFile("../image/frame.png");

  Sprite s(t1), background(t2), frame(t3);

  while(window.isOpen()) {
   Event e;
   while(window.pollEvent(e)) {
     if(e.type == Event::Closed) window.close(); //종료시 window 닫기
     
     if(e.type == Event::KeyPressed) { //키가 눌렸을 때
        if(e.key.code == Keyboard::Up) rotate = true;
	else if(e.key.code == Keyboard::Left) dx = -1;
	else if(e.key.code == Keyboard::Right) dx = 1;
     }
   }
     
   if(Keyboard::isKeyPressed(Keyboard::Down)) //delay 변화 
   
   /*Move함수 */

   /*rotate함수 */
   if(rotate) {

   }
   
   /*tick moving함수 */
   
   /*line check함수 */
   
   /*게임 종료 체크-> 이거는 main.cpp에 구현*/

   /*그리기 */	   
   window.clear(Color::White); 
   window.draw(background);
   
   for(int i=0; i < H; i++) {
     for(int j=0; j < W; j++) {
       if(Map[i][j] == 0) continue;
       s.setTextureRect(IntRect(Map[i][j]*18,0,18,18)); //현재까지 만들어진 모양 그리기
       s.setPosition(j*18,i*18);
       s.move(28,31);
       window.draw(s);
     }
   }
   
   for(int i=0; i < 4; i++) {   
       s.setTextureRect(IntRect(colorNum*18,0,18,18)); //새로 만들어진 도형 그리기
       s.setPosition(cur[i].x*18,cur[i].y*18);
       s.move(28,31);
       window.draw(s);
   }

   window.draw(frame);
   window.display();
  }
  return 0;
}
