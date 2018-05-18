//
// �Q�ΰ��|�Ӧs���g�c���|�A�i���K�Ӥ��A�]�w���L�ܼƨӿ���n�����g�c

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
	//�Ĥ@�Ӱg�c
	bool a = 1;
	//�ĤG�Ӱg�c
	bool b = 0;
	//�X�f��m
	const int ExitX = 12;
	const int ExitY = 15;

	int X[30] = { 0 };
	int Y[30] = { 0 };

	//�Ĥ@�Ӱg�c
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
	//�ĤG�Ӱg�c
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
	    //�Ĥ@�Ӱg�c�}�l
		if (a)
		{
			//�]�w�_�I
			int x = 1, y = 1;
			plink path = NULL;
			Map map;
			std::cout << std::endl << "[�C�L�X�g�c���|]" << std::endl;
			
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << MAZE[i][j] << " ";
				std::cout << std::endl;
			}
			// �}�l���g�c  
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
					std::cout << "\t>>> ���X�g�c!" << std::endl;
					std::cout << std::endl << "path:" << path << std::endl;
					break;
				}
				else
				{ // ���즺�J�P  
					MAZE[x][y] = 2;
					path = map.pop(&x, &y);
				}
			}
			std::cout << std::endl << "[�C�L�X�g�c���|]" << std::endl;

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << MAZE[i][j] << " ";
				    std::cout << std::endl;
			}
			
			// �L�X�Ĥ@�Ӱg�c�����|
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


		//�ĤG�Ӱg�c�}�l
		if (b)
		{
			int x = 1, y = 1;
			plink path = NULL;
			Map map;
			std::cout << std::endl << "[�C�L�X�g�c���|]" << std::endl;

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 17; j++)
					std::cout << FAKEMAZE[i][j] << " ";
				std::cout << std::endl;
			}
			// �}�l���g�c  
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
					std::cout << std::endl << "\t>>> ���X�g�c!" << std::endl;
					break;
				}
				else
				{ // ���즺�J�P  
					FAKEMAZE[x][y] = 2;
					path = map.pop(&x, &y);
					std::cout << "\t>>> The maze does not have a path." << std::endl;
					break;
				}
			}
			std::cout << "[�C�L�X�g�c���|]" << std::endl;
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

