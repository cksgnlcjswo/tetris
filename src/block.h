/*블록 관련 파일
 *
 * */


#ifndef __BLOCK_H__
#define __BLOCK_H__

int figures[7][4] = { //모양은 7개
  1,3,5,7,
  2,4,5,7,
  3,5,4,6,
  3,5,4,7,
  2,3,5,7,
  3,5,7,6,
  2,3,4,5,
};

struct Point {
  int x;
  int y;
} cur[4], prev[4];

//moving함수
//rotate함수

#endif
