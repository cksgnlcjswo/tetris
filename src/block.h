/*블록 관련 파일
 *
 * */


#ifndef __BLOCK_H__
#define __BLOCK_H__
/* Point 구조체와 figures배열의 multiple defination 해결을 위해 수정 */

extern int figures[7][4];

struct Point{
	int x;
	int y;
};

extern bool squareFlag;

extern struct Point cur[4], prev[4], next[4];
bool move(int dx);
void generateBlock(struct Point p[4]);
bool rotation();

#endif
