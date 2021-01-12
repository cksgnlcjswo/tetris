/*block.h에서 정의한 함수 */

#include <iostream>
#include "block.h"
#include "map.h"

/* extern으로 정의한 배열과 구조체 다시 정의 */

int figure[7][4] = { //모양은 7개
  1,3,5,7,
  2,4,5,7,
  3,5,4,6,
  3,5,4,7,
  2,3,5,7,
  3,5,7,6,
  2,3,4,5,
};

struct Point cur[4], prev[4], next[4];

bool curSquareFlag = false;
bool nextSquareFlag = false;

bool move(int dx)
{
	/* 우선 cur의 block의 좌표를 이동시킴 */
	for(int i=0;i<4;i++){
		cur[i].x += dx;
	}

	if(!boundaryCheck()) {
		for(int i=0;i<4;i++){
			cur[i].x = prev[i].x;
		}
		return false;
	}
	for(int i=0;i<4;i++){
		prev[i].x = cur[i].x;
	}
	return true;
}

void generateBlock(struct Point p[4]) {
  
  int randFigure = rand() % 7; //figure 숫자 0~6도형 중 1개 랜덤생성
  
  for(int i=0;i<4;i++) { //figure의 숫자를 4x2 행렬 인덱스로 대응.

   p[i].x = figure[randFigure][i] % 2;
   p[i].y = figure[randFigure][i] / 2;
  }
  if(randFigure == 6) nextSquareFlag = true;
  else nextSquareFlag = false;

return;
}

bool rotation()
{
   Point tmp;
   
   if(curSquareFlag) return true;

   /* mod연산을 통해서 회전축을 1,2,3,0 순서로 바꿈 */
   for(int i = 1;i < 5; i++)
   {
      for(int j = 0;j < 4; j++)
      {
         prev[j].x = cur[j].x;
         prev[j].y = cur[j].y;
  
	 /* 회전축을 기준으로 y축의 블록이 회전할 때는 -, x축 블록이 회전할 때는 + */
         tmp.x = cur[j].y - cur[i%4].y;
         tmp.y = cur[j].x - cur[i%4].x;
         cur[j].x = cur[i%4].x - tmp.x; 
         cur[j].y = cur[i%4].y + tmp.y;
      }
      
      /* boundaryCheck()를 통과하면 prev갱신 후 return */
      if(boundaryCheck())
      {
         for(int j = 0;j < 4; j++)
	 {
            prev[j].x = cur[j].x;
            prev[j].y = cur[j].y;
         }
      	return true;
      }
      /* 통과하지 못했을 경우 prev에서 cur를 복구한 후 회전축을 바꿔서 다시 회전 */
      else 
      {
         for(int j = 0;j < 4; j++)
	 {
            cur[j].x = prev[j].x;
	    cur[j].y = prev[j].y;
	 }
      }
   }
   /* 어떤 회전축을 잡아도 회전이 가능하지 않으면 false return */
   return false;
}

