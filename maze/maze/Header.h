
#ifndef _MAP_FOR_MAZE
#include <iostream>  

#define _MAP_FOR_MAZE  

#define EAST MAZE[x][y+1]
#define EASTSOUTH MAZE[x-1][y+1]
#define EASTNORTH MAZE[x+1][y+1]

#define WEST MAZE[x][y-1]
#define WESTSOUTH MAZE[x-1][y-1]
#define WESTNORTH MAZE[x+1][y-1]

#define SOUTH MAZE[x+1][y]  
#define NORTH MAZE[x-1][y]  

struct pos {
	int x, y;
	struct pos* next;
};

typedef struct pos pnode;
typedef pnode* plink;


class Map {
public:
	plink curPos;
	Map() {
		curPos = NULL;
	}
	~Map() {
		//delete all curPos  
		while (curPos) {
			plink top = curPos;
			curPos = curPos->next;
			delete top;
		}
	}
	virtual plink push(int x, int y);
	virtual plink pop(int* x, int* y);
	virtual int chkExit(int x, int y, int ex, int ey);
};
#endif  