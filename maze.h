#include <iostream>
#include <stack>
using namespace std;

//struct pos
//{
//	pos(int row, int col)
//		:_row(row)
//		,_col(col)
//	{}
//
//	int _row;	//行
//	int _col;	//列
//};
//
//template<int M, int N>
//class maze
//{
//public:
//	maze(int arr[][N])
//	{
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				_arr[i][j] = arr[i][j];
//			}
//		}
//	}
//
//	/*maze(const maze& M)
//	{
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				_arr[i][j] = M._arr[i][j]
//			}
//		}
//	}*/
//
//	//打印最小路径
//	void PrintMinMazePath()
//	{
//		pos cur(0, 0);
//		cout << "出口: ";
//		while (!q.empty())
//		{
//			cur = q.top();
//			printf("->[%d,%d]", cur._row, cur._col);
//			q.pop();
//		}
//	}
//
//	void PrintMaze()
//	{
//		cout << "迷宫地图如下：" << endl;
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				cout << _arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	void GetMazePath(pos Enter, int count)
//	{
//		pos cur = Enter;
//		pos next = cur;
//		_arr[Enter._row][Enter._col] = count + 1;
//
//		p.push(cur);
//
//		if (cur._row == M - 1)
//		{
//			if (q.empty() || q.size() > p.size())
//			{
//				printf("找到一个出口为[%d][%d]", cur._row, cur._col);
//				q = p;
//			}
//			cout << endl;
//		}
//
//		//向上探测
//		next._row -= 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//向右
//		next = cur;
//		next._col += 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//向下
//		next = cur;
//		next._row += 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//向左
//		next = cur;
//		next._col -= 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		p.pop();
//		return;
//	}
//
//	bool CheckAcess(pos cur, pos next)
//	{
//		if (next._row >= 0 && next._row < M
//			&& next._col >= 0 && next._col < N
//			&& _arr[next._row][next._col] == 0 || _arr[cur._row][cur._col] < _arr[next._row][next._col])
//		{
//			return true;
//		}
//		return false;
//	}
//
//
//private:
//	int _arr[M][N];
//	stack<pos> p; //保存当前路
//	stack<pos> q;//存放最短路径
//};
//

struct Pos
{
	int _row;
	int _col;

	Pos(const int& x, const int& y)
		:_row(x)
		,_col(y)
	{}
};

template < size_t N>
class Maze
{
public:
	Maze(const int maze[][N])
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				_maze[i][j] = maze[i][j];
			}
		}
	}

	bool CheckAccess(Pos pos)
	{
		//1、边界条件
		//2、判断是否能通
		if ( (pos._row < N && pos._row >= 0 ) && ( pos._col < N && pos._col >= 0 )
			&& _maze[pos._row][pos._col] == 0)
		{
			return true;
		}
		return false;
	}

	//1、栈实现
	bool GetPathWithStack(Pos entry,stack<Pos>& path)
	{
		path.push(entry);
		while (!path.empty())
		{
			Pos cur = path.top();
			//标记该位置
			_maze[cur._row][cur._col] = 2;
			if (cur._row == N - 1)
				return true;

			//判断上
			Pos next = cur;
			next._row -= 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//判断下
			next = cur;
			next._row += 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//判断左
			next = cur;
			next._col -= 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//判断右
			next = cur;
			next._col += 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//上下左右都不可同，回溯pop掉该位置
			path.pop();
		}
		return false;
	}

	//2、递归实现
	bool GetPathR(Pos entry, stack<Pos>& path)
	{
		//先标记
		path.push(entry);
		_maze[entry._row][entry._col] = 2;

		if (entry._row == N - 1)
			return true;

		//分别探测上,下，左右
		Pos next = entry;
		next._row -= 1;
		if (CheckAccess(next))
		{
			if (GetPathR(next, path))
				return true;
		}

		next = entry;
		next._row += 1;
		if (CheckAccess(next))
		{
			if (GetPathR(next, path))
				return true;
		}
		
		next = entry;
		next._col -= 1;
		if (CheckAccess(next))
		{
			if (GetPathR(next, path))
				return true;
		}

		next = entry;
		next._col += 1;
		if (CheckAccess(next))
		{
			if (GetPathR(next, path))
				return true;
		}

		//该位置走不通
		path.pop();
		return false;
	}

	//找到最短路径,只需要判断栈size
	void GetShotPath(Pos entry, stack<Pos>& path, stack<Pos>& shortPath)
	{
		path.push(entry);
		_maze[entry._row][entry._col] = 2;

		if (entry._row == N - 1)
		{
			if (path.size() < shortPath.size() || shortPath.empty())
			{
				shortPath = path;
				return;
			}
		}

		Pos next = entry;
		//探测上
		next._row -= 1;
		if (CheckAccess(next))
			GetShotPath(next,path,shortPath);

		//下
		next = entry;
		next._row += 1;
		if (CheckAccess(next))
			GetShotPath(next,path,shortPath);

		//左
		next = entry;
		next._col -= 1;
		if (CheckAccess(next))
			GetShotPath(next, path, shortPath);

		//右
		next = entry;
		next._col += 1;
		if (CheckAccess(next))
			GetShotPath(next, path, shortPath);

		path.pop();
	}

	//解决带环问题
	void CricleMaze(Pos entry,stack<Pos>& path, stack<Pos>& shortPath,int count)
	{
		_maze[entry._row][entry._col] = ++count;
		path.push(entry);
		if (entry._row == N - 1)
		{
			printf("出口点为[%d,%d]\n", entry._row, entry._col);
			if (path.size() < shortPath.size() || shortPath.empty())
			{
				shortPath = path;
				return;
			}
		}
		
		Pos next = entry;
		//探测上
		next._row -= 1;
		if (CheckAccess(entry,next))
			CricleMaze(next,path,shortPath,count);

		//下
		next = entry;
		next._row += 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);

		//左
		next = entry;
		next._col -= 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);
		//右
		next = entry;
		next._col += 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);

		path.pop();
	}

	bool CheckAccess(Pos cur, Pos next)
	{
		//1.检查边界
		//2.是否是通路 0
		//3.比我大的别人走过我没走过
		if ((next._row < N && next._row >= 0) && (next._col < N && next._col >= 0)
			&& ( (_maze[next._row][next._col] == 0) || (_maze[cur._row][cur._col] < _maze[next._row][next._col])))
		{
			return true;
		}
		return false;
	}

	void PrintMaze()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << _maze[i][j] << " ";
			}
			cout << endl;
		}
	}

	void PrintPath(stack<Pos> path)
	{
		while (!path.empty())
		{
			Pos cur = path.top();
			printf("<- [%d,%d] ", cur._row, cur._col);
			path.pop();
		}
		cout << endl;
	}


private:
	int _maze[N][N]; //迷宫
};