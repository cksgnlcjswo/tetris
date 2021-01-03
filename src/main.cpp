/* 테트리스 게임
 * 만든이: 김영우, 김찬휘, 정성구
 *  
 * 이메일:        , cksgnlcjswoo@naver.com, musichead99@naver.com
 * 
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "map.h"
#include "block.h"

using namespace sf;

int main(void) {
<<<<<<< HEAD
 	
  bool rotate = false, pause=false;
  clock_t delay = 0.3 * CLOCKS_PER_SEC; // 0.3 초
  int dx= 0, colorNum;
=======
  bool rotate = false;
  clock_t delay = 0.05 * CLOCKS_PER_SEC; // 0.5 초
  int dx= 0;
>>>>>>> d8c7585fe787a893e6ff25e7dab8f345ecc7a68c

/* rotation함수 작동 확인을 위해서 블록 모양 미리 정의 */
  cur[0].x = 1;
  cur[0].y = 1;
  cur[1].x = 1;
  cur[1].y = 2;
  cur[2].x = 0;
  cur[2].y = 2;
  cur[3].x = 0;
  cur[3].y = 3;

  RenderWindow window(VideoMode(320,480), "Tetris");
  
  /*이미지 로드*/
  Texture t1,t2,t3;
  t1.loadFromFile("../image/tiles.png");
  t2.loadFromFile("../image/background.png");
  t3.loadFromFile("../image/frame.png");

  Sprite s(t1), background(t2), frame(t3);
  
  clock_t timer=clock();

  while(window.isOpen()) {
   Event e;
   clock_t cur_time;
   while(window.pollEvent(e)) {
     if(e.type == Event::Closed) window.close(); //종료시 window 닫기
     
     if(e.type == Event::KeyPressed) { //키가 눌렸을 때
        if(e.key.code == Keyboard::Up) rotate = true;
	else if(e.key.code == Keyboard::Left) dx = -1;
	else if(e.key.code == Keyboard::Right) dx = 1;
     //   else if(e.key.code == Keyboard::Escape) pause=true;
     }
   }

/*
   if(pause) {
    while(true) {
     if(Keyboard :: isKeyPressed(Keyboard::Escape)) {
      pause = false;
      break;
      //pause하고 menu창 추가하려면 다시 만들어야함.
     }
    }
   }
*/
   if(Keyboard::isKeyPressed(Keyboard::Down)) delay=0.15; //delay 변화 
   
   move(dx);
   dx = 0; // dx를 초기화해주지 않으면 한번의 키입력으로도 계속 움직임

   if(rotate) {
	   rotation();
	   rotate = false; // 초기화해주지 않으면 계속 회전함
   }

   /*tick moving함수 */
   cur_time = clock();
<<<<<<< HEAD
   if(cur_time > timer + delay) {
	   
      for(int i=0;i<4;i++) cur[i].y++;

      if(!boundaryCheck()) { //y축으로 바운드를 나가거나 블록에 부딪힌 경우 된경우는 새로운 블록 생성및 블록 값 맵에 입력
	      
	 for(int i=0;i<4;i++) { 
		 cur[i].y--;
	         Map[cur[i].y][cur[i].x] = 2; //색깔 만들면 2 대신에 색깔변수 넣어주면 됨.
	 }	     
	 generateBlock(); //cur 갱신
      }
   timer = clock();
=======
   if(cur_time > timer + delay)
   {
	   for(int i=0;i<4;i++) cur[i].y++;

	   if(!boundaryCheck()) for(int i=0;i<4;i++) cur[i].y--;

	   timer = clock();
>>>>>>> d8c7585fe787a893e6ff25e7dab8f345ecc7a68c
   }
   
   /*line check함수 */
   
   /*게임 종료 체크-> 이거는 main.cpp에 구현*/

   delay = 0.3 * CLOCKS_PER_SEC; rotate = false; //delay, rotate 초기화
   /*그리기 */	   

   window.clear(Color::White); 
   window.draw(background);
   
   for(int i=0; i < H; i++) 
     for(int j=0; j < W; j++) {
       if(Map[i][j] == 0) continue;
       s.setTextureRect(IntRect(Map[i][j]*18,0,18,18)); //현재까지 만들어진 모양 그리기
       s.setPosition(j*18,i*18);
       s.move(28,31);
       window.draw(s);
     }
      
   for(int i=0; i < 4; i++) {   
       s.setTextureRect(IntRect(18,0,18,18)); //새로 만들어진 도형 그리기, 색깔 변수있으면 1대신에 색깔 변수
       s.setPosition(cur[i].x*18,cur[i].y*18);
       s.move(28,31);
       window.draw(s);
   }

   window.draw(frame);
   window.display();
  }

  return 0;
}
