/*map.h에서 정의한 함수 */
#include <iostream>
#include "map.h"
#include "block.h"

/* extern으로 정의한 배열 초기화 */
int Map[H][W] = {0};
int Score[H][W] = {0};

extern int point; //점수

void scoreGenerate() { //맵에 생성될 점수 생성
  for(int i = 0 ; i < H ; i++) { 
    for(int j = 0 ; j < W ; j++) {
      Score[i][j] = rand() % 38 + 1; //1~100까지 점수 생성.
    }
  }
}

bool boundaryCheck()
{
	for(int i = 0;i < 4; i++)
	{
		if(cur[i].x < 0 || cur[i].y < 0 || cur[i].x >= W || cur[i].y >= H )
		{
			return false;
		}
	        else if(Map[cur[i].y][cur[i].x]) return false;
	}
	return true;
}

void clearLine(int f_line,int l_line) // clear the map from f_line to l_line
{
	for(int i = f_line;i<=l_line;i++)
	{
		for(int j=0;j<W;j++) Map[i][j] = 0;
	}
}

void downLine(int f_line,int l_line) // pulling down the lines above the cleared lines.
{
	int line_gap = (l_line - f_line) + 1; // the distance between l_line and f_line

	for(int i= l_line - line_gap ; i >=0 ; i--)
	{
		for(int j = 0;j < W; j++)
		{
			Map[i+line_gap][j] = Map[i][j];
			Map[i][j] = 0;
		}
	}
}

bool checkLine()
{
	bool rt_val = false; // return value. if there's any lines which have to be cleared, rt_val would have true.
	int f_line = -1; // the first index value which points at the row that has to be cleared.
	int l_line = -1; // the last index value which points at the row that has to be cleared.
	int checking; // current index value.
	
	
	// row : H == 20, column : W == 10
	
	for(int cur=0;cur<H;cur++)
	{
		for(checking=0;checking<W && Map[cur][checking] != 0;checking++);

		// If the condition satisfies checking ==  W, current line which the program is checking should be cleared.
		if(checking == W && f_line == -1) {f_line = cur; l_line = cur; rt_val=true;} 	// If now f_line has -1 value, current line is the first line to be cleared. 
		else if(checking == W) l_line = cur;											// If the current line needs to be cleared and f_line has not -1 value, update the l_line.
		if( (checking != W && f_line != -1) || (cur == H-1 && f_line != -1))			// under following two conditions the clearing will have to be done before checkLine function ends. If f_line doesn't have -1 value and current line shouldn't be cleared  OR If f_line is not -1 and the checking prorgress reaches the end of map
		{
			// clear the lines which have to be wiped out.
			clearLine(f_line,l_line);
	                
			// pulling down the rest of lines above the cleared lines.
			downLine(f_line,l_line);
            
			// Scoring part.
			for(int row = f_line; row <=l_line; row++) 
                          for(int col = 0 ; col < W; col++) 
				point += Score[row][col];
			
			// initialize f_line and f_line to -1
			f_line = -1;
			l_line = -1;
		}
			
	}
	
	
	return rt_val;
}


