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

bool squareFlag = false;

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

return;
}

bool rotation()
{
   Point tmp;

   for(int i = 1;i < 5; i++) // %를 이용해서 2,3,4,1번 블록 순서로 회전축을 바꿈
   {
      for(int j = 0;j < 4; j++)
      {
         prev[j].x = cur[j].x;
         prev[j].y = cur[j].y;
      }

      for(int j = 0;j < 4; j++)
      {
         tmp.x = cur[j].y - cur[i%4].y;
         tmp.y = cur[j].x - cur[i%4].x;

         /* 중심 블록을 기준으로 x축에 있는 블록을 회전시킬 땐 +, y축에 있는 블록을 회전시킬 땐 - */

         cur[j].x = cur[i%4].x - tmp.x; 
         cur[j].y = cur[i%4].y + tmp.y;
      }

      if(boundaryCheck()) // boundaryCheck()를 통과하면 prev갱신 후 return
      {
         for(int j = 0;j < 4; j++)
	 {
            prev[j].x = cur[j].x;
            prev[j].y = cur[j].y;
         }
      	return true;
      }
      else // 통과하지 못하면 cur를 복구한 뒤 회전축을 바꿔서 다시 실행
      {
         for(int j = 0;j < 4; j++)
	 {
            cur[j].x = prev[j].x;
	    cur[j].y = prev[j].y;
	 }
      }
   }
   return false; // 모두 가능하지 않다면 false값 return
}

