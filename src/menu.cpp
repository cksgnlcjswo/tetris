#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include <vector>
#include <algorithm>
#include "map.h"
#include "block.h"
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <string>
#include <sstream>

using namespace sf;

extern RenderWindow window;
extern int point;

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

int mainMenu()
{
    // Configuring for background image
    Texture t;
    t.loadFromFile("../image/mainMenu.png");
    Sprite mainMenu(t);
    mainMenu.setScale(1.33f, 1.5f);

    //font setting
    Font athena;
    athena.loadFromFile("../font/Athena.ttf");

    // text setting
    // t_start : start button
    // t_score : score board button
    // t_exit  : exit game button
    // t_cursor : text for * shaped cursor
    Text t_start, t_score , t_exit, t_cursor;

    // giving a font to text objects
    t_start.setFont(athena);
    t_score.setFont(athena);
    t_exit.setFont(athena);
    t_cursor.setFont(athena);

    // writting the actual texts
    t_start.setString("Game Start");
    t_score.setString("Score Board");
    t_exit.setString("Exit Game");
    t_cursor.setString("*");

    // setting the charactersize
    t_start.setCharacterSize(CHARSIZE);
    t_score.setCharacterSize(CHARSIZE);
    t_exit.setCharacterSize(CHARSIZE);
    t_cursor.setCharacterSize(CHARSIZE);

    // setting the text color to white
    t_start.setFil0lColor(Color::White);
    t_score.setFillColor(Color::White);
    t_exit.setFillColor(Color::White);
    t_cursor.setFillColor(Color::Green);

    // setting event
    Event e; 

    // initial position for cursor
    int cursor_pos = 390;

    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed) window.close(); // x누르면 윈도우 닫기.
     
            if(e.type == Event::KeyPressed)
            {
                if(e.key.code == Keyboard::Up){ // up moving for cursor
                    if(cursor_pos > 390){ // if the cursor_pos is 390, it's already at the most top  position
                        cursor_pos -= 15;
                    }
                }
                else if(e.key.code == Keyboard::Down){ // down moving for cursor
                    if(cursor_pos < 420){ // if the cursor_pos is 420 it's already at the most bottom position
                        cursor_pos += 15;
                    }
                }
                else if(e.key.code == Keyboard::Enter){ // selection
                    switch(cursor_pos)
                    {
                        case 390: // 390 is the y position for game start so return 1 to start the game
                            return 1;
                        case 405: // 405 is the y position for score board
                            return 2;
                        case 420: // 420 is the y position for exit game
                            return 3;
                    }
                }
            }
        }

        // setting for each options' position
        t_start.setPosition(120,390);
        t_score.setPosition(120,405);
        t_exit.setPosition(120,420);
        t_cursor.setPosition(110,cursor_pos);

        // clear display before draw something on it.
        window.clear(Color::White);
        // draw the texts
        window.draw(mainMenu);
        window.draw(t_start);
        window.draw(t_score);
        window.draw(t_exit);
        window.draw(t_cursor);

        // display the drawings
        window.display();
    }
    return -1;
}

void gameOverMenu() {
	
   Texture t;
   t.loadFromFile("../image/id_input.png");
   Sprite gameOverMenu(t);
   gameOverMenu.move(40,135);	
   //font 설정
   Font athena;
   athena.loadFromFile("../font/Athena.ttf");
   
   Text word;
   word.setFont(athena);
   word.move(65,200);
   word.setFillColor(Color::Black);

   std::string tmp="";
   Event e;

while(window.isOpen()) {
      	  
    while(window.pollEvent(e)) {
	
	   if(e.type == Event::Closed) window.close(); // x누르면 윈도우 닫기.   

       if(e.type == Event::KeyPressed) {  
           if(e.key.code == Keyboard::A) tmp+="a";
           else if(e.key.code == Keyboard::B) tmp+="b";
           else if(e.key.code == Keyboard::C) tmp+="c";
           else if(e.key.code == Keyboard::D) tmp+="d";
           else if(e.key.code == Keyboard::E) tmp+="e";
           else if(e.key.code == Keyboard::F) tmp+="f";
           else if(e.key.code == Keyboard::G) tmp+="g";
        // else if(e.key.code == Keyboard::H) tmp+="h"; H를 HEIGHT로 W를 WIDTH로 바꿔야할듯
           else if(e.key.code == Keyboard::I) tmp+="i";
           else if(e.key.code == Keyboard::J) tmp+="j";
           else if(e.key.code == Keyboard::K) tmp+="k";
           else if(e.key.code == Keyboard::L) tmp+="l";
           else if(e.key.code == Keyboard::M) tmp+="m";
           else if(e.key.code == Keyboard::N) tmp+="n";
           else if(e.key.code == Keyboard::O) tmp+="o";
           else if(e.key.code == Keyboard::P) tmp+="p";
           else if(e.key.code == Keyboard::Q) tmp+="q";
           else if(e.key.code == Keyboard::R) tmp+="r";
           else if(e.key.code == Keyboard::S) tmp+="s";
           else if(e.key.code == Keyboard::T) tmp+="t";
           else if(e.key.code == Keyboard::U) tmp+="u";
           else if(e.key.code == Keyboard::V) tmp+="v";
        // else if(e.key.code == Keyboard::W) tmp+="w";
           else if(e.key.code == Keyboard::X) tmp+="x";
           else if(e.key.code == Keyboard::Y) tmp+="y";
           else if(e.key.code == Keyboard::Z) tmp+="z";
	       else if(e.key.code == Keyboard::Backspace) tmp.erase(tmp.begin() + tmp.length() - 1); //마지막 단어 삭제
	       else if(e.key.code == Keyboard::Enter) { //게임종료 조건

           FILE *fp = fopen("../score/score.txt","a"); //text 파일로 읽음
           fprintf(fp, "%d %s\n",point ,tmp.c_str());
           fclose(fp);
           window.close(); 
           }
	       
        }
    }
     
   word.setString(tmp);

   window.draw(gameOverMenu);
   window.draw(word);
   window.display();
}
return;
}

void scoreBoard() {
    using namespace std;

    FILE *fp = fopen("../score/score.txt", "rt" );
    int rank = 1;
    char id[10];
    int p;

    int ranking_xpos = 30, ranking_ypos = 90;
    int name_xpos = 60, name_ypos = 90;
    int point_xpos = 250, point_ypos = 90;

    vector<pair<int, string> > v;

    while(1) {
        int ret = fscanf(fp, "%d %s",&p, id);
        string str(id);
        if(ret == EOF) break;
        v.push_back({p, str});
    }
    fclose(fp);

    sort(v.begin(), v.end());

    Texture t;
    t.loadFromFile("../image/rank.png");
    Sprite r(t);

    Font athena;
    athena.loadFromFile("../font/Athena.ttf");
    
    Text ranking, name, P;
    ranking.setFont(athena);
    name.setFont(athena);
    ranking.setFillColor(Color::Black);
    name.setFillColor(Color::Black);
    P.setFont(athena);
    P.setFillColor(Color::Black);

    Event e;

    window.clear(Color::White);
    window.draw(r);

    for(int i = 0 ; i < v.size() ; i++) {
        ranking.setString(to_string(rank));
        P.setString(to_string(v[i].first));
        name.setString(v[i].second);
        rank++;

        ranking.setPosition(ranking_xpos,ranking_ypos);
        P.setPosition(point_xpos, point_ypos);
        name.setPosition(name_xpos, name_ypos);

        window.draw(ranking);
        window.draw(P);
        window.draw(name);

        ranking_ypos += 30;
        point_ypos += 30;
        name_ypos += 30;
    }

    window.display();

    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed) window.close(); // x누르면 윈도우 닫기.        
        }
    }
}

bool gameOver() {
   for(int i=0;i<4;i++) {
     if(Map[cur[i].y][cur[i].x]) return false; //next 도형좌표에 다른 블록이 있다면 종료
   }
return true;
}

void gameStart()
{
  srand(time(NULL));	
  bool rotate = false;
  clock_t delay = 0.05 * CLOCKS_PER_SEC; // 0.5 초
  int dx= 0, color=1;
  
  /*폰트, 이미지*/
  Font athena;
  athena.loadFromFile("../font/Athena.ttf");

  Text sc;
  sc.setCharacterSize(30);
  sc.setFont(athena);

  Texture t1,t2,t3;
  t1.loadFromFile("../image/tiles.png");
  t2.loadFromFile("../image/background.png");
  t3.loadFromFile("../image/frame.png");

  Sprite s(t1), background(t2), frame(t3);
  
  scoreGenerate();

  clock_t timer=clock();
  generateBlock(cur);
  
  curSquareFlag = nextSquareFlag;
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
	    else if(e.key.code == Keyboard::Space || e.key.code == Keyboard::Escape) pauseMenu();
     }
   }

   if(Keyboard::isKeyPressed(Keyboard::Down)) delay=0.2; //delay 변화 
   
   move(dx);
   dx = 0; // dx를 초기화해주지 않으면 한번의 키입력으로도 계속 움직임

   if(rotate) {
	rotation();
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
	      curSquareFlag = nextSquareFlag;   
	 }	  

	 generateBlock(next); //next 갱신
      }
   timer = clock();
   }
   
   /*line check함수 */
   checkLine();

   /*게임 종료 체크*/

   if(!gameOver()) { //게임 종료
     gameOverMenu();
   }

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
       s.move(255,54);
       window.draw(s);
   }

   std::ostringstream oss; //output string stream
   oss << point;
   sc.setString(oss.str());
   
   sc.setPosition(140,420); //score 자리수별로 위치 조정해야 할 듯.

   window.draw(sc);
   window.draw(frame);
   window.display();
  }
  return;
}
