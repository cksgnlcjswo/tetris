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
void clearLine(int f_line,int l_line)
{
	for(int i = f_line;i<=l_line;i++)
	{
		for(int j=0;j<H;j++) Map[i][j] = 0;
	}
}

void downLine(int f_line,int l_line)
{
	int line_gap = (l_line - f_line) + 1;

	for(int i= l_line - line_gap ; i >=0 ; i--)
	{
		for(int j = 0;j < H; j++)
		{
			Map[i+line_gap][j] == Map[i][j];
			Map[i][j] == 0;
		}
	}
}

bool checkLine()
{
	// vector 의 pair를 사용하면 더 간단해 질지도 ... 일단 보류.
	
	bool rt_val = false;
	int f_line = -1; // 지워야 하는 첫번째 줄의 index값.
	int l_line = -1; // 지워야 하는 마지막 줄의 index값.
	int checking; // 현재 행에서 한칸하칸의 index.

	for(int cur=0;cur<W;cur++)
	{
		for(checking=0;checking<H && Map[cur][checking] != 0;checking++);

		// checking == H 라면 검사했던 라인은 사라져야 하는 라인.

		if(checking == H && f_line == -1) {f_line = cur; l_line = cur; rt_val=true;} 	// f_line이 -1이라면 cur가 지우기 시작줄. l_line도 같이 갱신.
		else if(checking == H) l_line = cur;				// 현재 라인이 지워야 하는 라인이고 f_line이 -1이 이니라면 l_line갱신.
		else if(checking != H && f_line != -1)				// f_line이 -1이 아니고 checking 이 H와 값이 다르면 일단 지우기를 진행.
		{
			// 지우기 진행.
			clearLine(f_line,l_line);
	
			// downLine 진행.
			downLine(f_line,l_line);

			// f_line과 l_line -1로 초기화.
			f_line = -1;
			l_line = -1;
		}
			
	}
	return rt_val;
}


