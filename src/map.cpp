/*map.h에서 정의한 함수 */
#include <iostream>
#include "map.h"
#include "block.h"

/* extern으로 정의한 배열 초기화 */
int Map[W][H] = {0};

/* 블록이 주어진 맵을 벗어나는지 체크하는 함수 */
bool boundaryCheck()
{
	for(int i = 0;i < 4; i++)
	{
		if(cur[i].x < 0 || cur[i].y < 0 || cur[i].x >= H || cur[i].y >= W )
		{
			return false;
		}
	}
	return true;
}
