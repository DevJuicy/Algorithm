#include <iostream>
#include <vector>

using namespace std;

class ChessMan
{
public:
	int y;
	int x;
	int direction;
	int index;
	int parentIndex = 0;
	ChessMan* childMan = NULL;
	ChessMan(int y, int x, int direction, int index)
	{
		this->y = y;
		this->x = x;
		this->direction = direction;
		this->index = index;
	}
};

int map[13][13];
int topIndex[13][13];
int N, K;
int childCount;
int answer = 0;

vector<ChessMan*> chessMan;

void DEBUG()
{
	cout << endl;
	cout << answer << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << topIndex[i][j] << " ";
		}
		cout << endl;
	}
}

void FindChild(ChessMan* cm)
{
	childCount++;
	if (cm->childMan != NULL)
		FindChild(cm->childMan);
}

int GetChildCount(ChessMan* cm)
{
	childCount = 0;
	if (cm->childMan != NULL)
		FindChild(cm->childMan);
	return childCount;
}

int FindNextTile(int y, int x, int direction)
{
	if (direction == 1)
		x++;
	else if (direction == 2)
		x--;
	else if (direction == 3)
		y--;
	else
		y++;

	if (y < 0 || x < 0 || y >= K || x >= K)
		return 2;
	return map[y][x];
}

int ChangeDirection(int currentDirection)
{
	if (currentDirection == 1)
		return 2;
	else if (currentDirection == 2)
		return 1;
	else if (currentDirection == 3)
		return 4;
	else
		return 3;
}

void ReverseMoveChild(ChessMan* cm, int direction)
{
	if (cm->childMan != NULL)
		ReverseMoveChild(cm->childMan, direction);

	int originY = cm->y;
	int originX = cm->x;

	if (direction == 1)
		cm->x++;
	else if (direction == 2)
		cm->x--;
	else if (direction == 3)
		cm->y--;
	else
		cm->y++;

	topIndex[originY][originX] = cm->parentIndex;
	chessMan[cm->parentIndex - 1]->childMan = NULL;

	// 내 부모 업데이트
	if (topIndex[cm->y][cm->x] == 0)
		cm->parentIndex = 0;
	else
	{
		cm->parentIndex = topIndex[cm->y][cm->x];
		chessMan[cm->parentIndex - 1]->childMan = cm;
	}
	topIndex[cm->y][cm->x] = cm->index;

}

void MoveChild(ChessMan* cm, int direction)
{
	if (direction == 1)
		cm->x++;
	else if (direction == 2)
		cm->x--;
	else if (direction == 3)
		cm->y--;
	else
		cm->y++;

	topIndex[cm->y][cm->x] = cm->index;

	if (cm->childMan != NULL)
		MoveChild(cm->childMan, direction);
}

void MoveTile(ChessMan* cm)
{
	int originY = cm->y;
	int originX = cm->x;

	if (cm->direction == 1)
		cm->x++;
	else if (cm->direction == 2)
		cm->x--;
	else if (cm->direction == 3)
		cm->y--;
	else
		cm->y++;

	// 현재 topIndex맵 업데이트
	if (cm->parentIndex == 0)
		topIndex[originY][originX] = 0;
	else
	{
		topIndex[originY][originX] = cm->parentIndex;
		chessMan[cm->parentIndex - 1]->childMan = NULL;
	}

	// 내 부모 업데이트
	if (topIndex[cm->y][cm->x] == 0)
		cm->parentIndex = 0;
	else
	{
		cm->parentIndex = topIndex[cm->y][cm->x];
		chessMan[cm->parentIndex - 1]->childMan = cm;
	}
	topIndex[cm->y][cm->x] = cm->index;
}

void Move(ChessMan* cm)
{
	// 흰색인경우
	if (FindNextTile(cm->y, cm->x, cm->direction) == 0)
	{
		MoveTile(cm);

		if (cm->childMan != NULL)
			MoveChild(cm->childMan, cm->direction);
	}
	// 빨강인경우 1
	else if (FindNextTile(cm->y, cm->x, cm->direction) == 1)
	{

		if (cm->childMan != NULL)
			ReverseMoveChild(cm->childMan, cm->direction);

		MoveTile(cm);
		cm->childMan = NULL;
	}
	// 파랑인경우 2
	else if (FindNextTile(cm->y, cm->x, cm->direction) == 2)
	{
		cm->direction = ChangeDirection(cm->direction);

		if (FindNextTile(cm->y, cm->x, cm->direction) != 2)
			Move(cm);
	}
	//DEBUG();
}

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= K; i++)
	{
		int y, x, direction;
		cin >> y >> x >> direction;
		chessMan.push_back(new ChessMan(y - 1, x - 1, direction, i));
		topIndex[y - 1][x - 1] = i;
	}
}

int Solution()
{
	//DEBUG();
	bool circle = true;
	while (circle)
	{
		answer++;
		for (int i = 0; i < K; i++)
		{
			Move(chessMan[i]);

			for (int j = 0; j < K; j++)
			{
				if (GetChildCount(chessMan[j]) >= 3)
				{
					circle = false;
					break;
				}
			}
		}
		if (answer >= 1000)
		{
			answer = -1;
			break;
		}
	}
	return answer;
}


int main()
{
	Input();
	cout << Solution();

	// 해제
	for (int i = 0; i < K; i++)
		delete chessMan[i];
}