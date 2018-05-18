//
// 利用堆疊來存取迷宮路徑，可走八個方位，設定布林變數來選取要走的迷宮

#include "Header.h"  
#include <iostream>  


plink Map::push(int x, int y) {
	if (curPos == NULL) {
		curPos = new pnode;
		curPos->x = x;
		curPos->y = y;
		curPos->next = NULL;
		return curPos;
	}
	else {
		plink newnode = new pnode;
		newnode->x = x;
		newnode->y = y;
		newnode->next = curPos;
		curPos = newnode;
		return curPos;
	}
}

plink Map::pop(int* x, int* y) {
	if (curPos == NULL) {
		*x = -1;
		return NULL;
	}
	else {
		plink top = curPos;
		*x = curPos->x;
		*y = curPos->y;
		curPos = curPos->next;
		delete top;
		return curPos;
	}
}

int Map::chkExit(int x, int y, int ex, int ey) {
	if (x == ex && y == ey) {
		return 1;
	}
	else {
		return 0;
	}
}


int main(void)
{
	//第一個迷宮
	bool a = 1;
	//第二個迷宮
	bool b = 0;
	//出口位置
	const int ExitX = 12;
	const int ExitY = 15;

	int X[30] = { 0 };
	int Y[30] = { 0 };

	//第一個迷宮
	int MAZE[14][17] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		                 1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
		                 1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,
		                 1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,
		                 1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,
						 1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,
						 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
						 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
		                 1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,
						 1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,
						 1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,
						 1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
						 1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,
	                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	//第二個迷宮
	int FAKEMAZE[14][17] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
							 1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
							 1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,
							 1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,
							 1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,
							 1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,
							 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
							 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
							 1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,
							 1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,
							 1,1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,1,
							 1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
							 1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1 };
	    //第一個迷宮開始
		if (a)
		{
			//設定起點
			int x = 1, y = 1;
			plink path = NULL;
			Map map;
			std::cout << std::endl << "[列印出迷宮路徑]" << std::endl;
			
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << MAZE[i][j] << " ";
				std::cout << std::endl;
			}
			// 開始走迷宮  
			while (x <= ExitX && y <= ExitY)
			{
				MAZE[x][y] = 2;
				if (NORTH == 0)
				{
					x -= 1;
					path = map.push(x, y);
				}
				else if (SOUTH == 0)
				{
					x += 1;
					path = map.push(x, y);
				}
				else if (WEST == 0)
				{
					y -= 1;
					path = map.push(x, y);
				}
				else if (EAST == 0)
				{
					y += 1;
					path = map.push(x, y);
				}
				else if (WESTSOUTH == 0)
				{
					x -= 1;
					y -= 1;
					path = map.push(x, y);
				}
				else if (WESTNORTH == 0)
				{
					x += 1;
					y -= 1;
					path = map.push(x, y);
				}
				else if (EASTSOUTH == 0)
				{
					x -= 1;
					y += 1;
					path = map.push(x, y);
				}
				else if (EASTNORTH == 0)
				{
					x += 1;
					y += 1;
					path = map.push(x, y);
				}
				else if (map.chkExit(x, y, ExitX, ExitY) == 1)
				{
					std::cout << "\t>>> 走出迷宮!" << std::endl;
					std::cout << std::endl << "path:" << path << std::endl;
					break;
				}
				else
				{ // 走到死胡同  
					MAZE[x][y] = 2;
					path = map.pop(&x, &y);
				}
			}
			std::cout << std::endl << "[列印出迷宮路徑]" << std::endl;

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << MAZE[i][j] << " ";
				    std::cout << std::endl;
			}
			
			// 印出第一個迷宮的路徑
			for(int i = 0; i < 30;i++)
			{  
				path = map.pop(&x, &y);
				std::cout << "Row:" << x << " "<< "Column:" <<  y << std::endl;
		 		int ii = i + 1;
				X[ii] = x;
				Y[ii] = y;
			}
			std::cout << std::endl << "Row:" << " " << "Column:"<< std::endl;
			std::cout << 1 << "     " << 1 << std::endl;
			for (int i = 30; i > 0; i--)
			{
				std::cout << X[i] << "     " << Y[i] << std::endl;
			}
			
		}


		//第二個迷宮開始
		if (b)
		{
			int x = 1, y = 1;
			plink path = NULL;
			Map map;
			std::cout << std::endl << "[列印出迷宮路徑]" << std::endl;

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << FAKEMAZE[i][j] << " ";
				std::cout << std::endl;
			}
			// 開始走迷宮  
			while (x <= ExitX && y <= ExitY)
			{
				FAKEMAZE[x][y] = 2;
				if (NORTH == 0)
				{
					x -= 1;
					path = map.push(x, y);
				}
				else if (SOUTH == 0)
				{
					x += 1;
					path = map.push(x, y);
				}
				else if (WEST == 0)
				{
					y -= 1;
					path = map.push(x, y);
				}
				else if (EAST == 0)
				{
					y += 1;
					path = map.push(x, y);
				}
				else if (WESTSOUTH == 0)
				{
					x -= 1;
					y -= 1;
					path = map.push(x, y);
				}
				else if (WESTNORTH == 0)
				{
					x += 1;
					y -= 1;
					path = map.push(x, y);
				}
				else if (EASTSOUTH == 0)
				{
					x -= 1;
					y += 1;
					path = map.push(x, y);
				}
				else if (EASTNORTH == 0)
				{
					x += 1;
					y += 1;
					path = map.push(x, y);
				}
				else if (map.chkExit(x, y, ExitX, ExitY) == 1)
				{
					std::cout << std::endl << "\t>>> 走出迷宮!" << std::endl;
					break;
				}
				else
				{ // 走到死胡同  
					FAKEMAZE[x][y] = 2;
					path = map.pop(&x, &y);
					std::cout << "\t>>> The maze does not have a path." << std::endl;
					break;
				}
			}
			std::cout << "[列印出迷宮路徑]" << std::endl;
			std::cout << std::endl << "path:" << path << std::endl;
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << FAKEMAZE[i][j] << " ";
				std::cout << std::endl;
			}
		}

		system("pause");
		return 0;
}

