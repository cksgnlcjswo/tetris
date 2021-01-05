/* 테트리스 게임
 * 만든이: 김영우, 김찬휘, 정성구
 *  
 * 이메일:        , rdd0426@gmail.com, cksgnlcjswoo@naver.com, musichead99@naver.com
 * 
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "map.h"
#include "block.h"

using namespace sf;

int main(void) {
  srand(time(NULL));	
  bool rotate = false;
  clock_t delay = 0.05 * CLOCKS_PER_SEC; // 0.3 초
  int dx= 0, color=1;
  
/* rotation함수 작동 확인을 위해서 블록 모양 미리 정의 */

  RenderWindow window(VideoMode(320,480), "Tetris");
  
  /*이미지 로드*/

  Texture t1,t2,t3;
  t1.loadFromFile("../image/tiles.png");
  t2.loadFromFile("../image/background.png");
  t3.loadFromFile("../image/frame.png");

  Sprite s(t1), background(t2), frame(t3);
  
  clock_t timer=clock();
  generateBlock(cur);
  generateBlock(next);

  while(window.isOpen()) {
   Event e;
   clock_t cur_time;

   /*게임 시작 메뉴 */

   while(window.pollEvent(e)) {
     if(e.type == Event::Closed) window.close(); //종료시 window 닫기
     
     if(e.type == Event::KeyPressed) { //키가 눌렸을 때
        if(e.key.code == Keyboard::Up) rotate = true;
	else if(e.key.code == Keyboard::Left) dx = -1;
	else if(e.key.code == Keyboard::Right) dx = 1;
      //else if(e.key.code == Keyboard::Space) pause();
     }
   }

   if(Keyboard::isKeyPressed(Keyboard::Down)) delay=0.2; //delay 변화 
   
   move(dx);
   dx = 0; // dx를 초기화해주지 않으면 한번의 키입력으로도 계속 움직임

   if(rotate) {
	rotation();
	rotate = false; // 초기화해주지 않으면 계속 회전함
   }

   /*tick moving함수 */
   cur_time = clock();

   if(cur_time > timer + delay) {
	   
      for(int i=0;i<4;i++) cur[i].y++;

      if(!boundaryCheck()) { //y축으로 바운드를 나가거나 블록에 부딪힌 경우 된경우는 새로운 블록 생성및 블록 값 맵에 입력
	 
	 int color = rand() % 7 + 1; //값의 범위를 1~7로 줌 -> 블록이 있는 곳의 Map값은 0이 될수없어서..     
	 for(int i=0;i<4;i++) { 
	      cur[i].y--;
	      Map[cur[i].y][cur[i].x] = 1; //움직일수 없는 블록은 같은색으로 고정
	      cur[i].x = next[i].x; 
	      cur[i].y = next[i].y;   
	 }	     

	 generateBlock(next); //next 갱신
      }
   timer = clock();
   }
   
   /*line check함수 */
   checkLine();

   /*게임 종료 체크-> 이거는 main.cpp에 구현*/

   delay = 0.05 * CLOCKS_PER_SEC; rotate = false; //delay, rotate 초기화
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
       s.setTextureRect(IntRect(color,0,18,18)); //새로 만들어진 도형 그리기
       s.setPosition(cur[i].x*18,cur[i].y*18);
       s.move(28,31);
       window.draw(s);
   }

   for(int i=0; i < 4; i++) {
       s.setTextureRect(IntRect(1,0,18,18)); //다음 도형 그리기
       s.setPosition(next[i].x*18, next[i].y*18);
       s.move(250,31);
       window.draw(s);
   }

   window.draw(frame);
   window.display();
  }

return 0;
}
