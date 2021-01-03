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

struct Point cur[4], prev[4];

/* move함수 */

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

/* rotate 함수 */

bool rotation()
{
	

	if(!boundaryCheck()){
		for(int i=0;i<4;i++){
			cur[i].x = prev[i].x;
			cur[i].y = prev[i].y;
		}
		return false;
	}
	for(int i=0;i<4;i++){
		prev[i].x = cur[i].x;
		prev[i].y = cur[i].y;
	}
	return true;
}
