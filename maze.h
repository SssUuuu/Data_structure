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
//	int _row;	//��
//	int _col;	//��
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
//	//��ӡ��С·��
//	void PrintMinMazePath()
//	{
//		pos cur(0, 0);
//		cout << "����: ";
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
//		cout << "�Թ���ͼ���£�" << endl;
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
//				printf("�ҵ�һ������Ϊ[%d][%d]", cur._row, cur._col);
//				q = p;
//			}
//			cout << endl;
//		}
//
//		//����̽��
//		next._row -= 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//����
//		next = cur;
//		next._col += 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//����
//		next = cur;
//		next._row += 1;
//		if (CheckAcess(cur, next))
//		{
//			GetMazePath(next, _arr[cur._row][cur._col]);
//		}
//
//		//����
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
//	stack<pos> p; //���浱ǰ·
//	stack<pos> q;//������·��
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
		//1���߽�����
		//2���ж��Ƿ���ͨ
		if ( (pos._row < N && pos._row >= 0 ) && ( pos._col < N && pos._col >= 0 )
			&& _maze[pos._row][pos._col] == 0)
		{
			return true;
		}
		return false;
	}

	//1��ջʵ��
	bool GetPathWithStack(Pos entry,stack<Pos>& path)
	{
		path.push(entry);
		while (!path.empty())
		{
			Pos cur = path.top();
			//��Ǹ�λ��
			_maze[cur._row][cur._col] = 2;
			if (cur._row == N - 1)
				return true;

			//�ж���
			Pos next = cur;
			next._row -= 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//�ж���
			next = cur;
			next._row += 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//�ж���
			next = cur;
			next._col -= 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//�ж���
			next = cur;
			next._col += 1;
			if (CheckAccess(next))
			{
				path.push(next);
				continue;
			}

			//�������Ҷ�����ͬ������pop����λ��
			path.pop();
		}
		return false;
	}

	//2���ݹ�ʵ��
	bool GetPathR(Pos entry, stack<Pos>& path)
	{
		//�ȱ��
		path.push(entry);
		_maze[entry._row][entry._col] = 2;

		if (entry._row == N - 1)
			return true;

		//�ֱ�̽����,�£�����
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

		//��λ���߲�ͨ
		path.pop();
		return false;
	}

	//�ҵ����·��,ֻ��Ҫ�ж�ջsize
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
		//̽����
		next._row -= 1;
		if (CheckAccess(next))
			GetShotPath(next,path,shortPath);

		//��
		next = entry;
		next._row += 1;
		if (CheckAccess(next))
			GetShotPath(next,path,shortPath);

		//��
		next = entry;
		next._col -= 1;
		if (CheckAccess(next))
			GetShotPath(next, path, shortPath);

		//��
		next = entry;
		next._col += 1;
		if (CheckAccess(next))
			GetShotPath(next, path, shortPath);

		path.pop();
	}

	//�����������
	void CricleMaze(Pos entry,stack<Pos>& path, stack<Pos>& shortPath,int count)
	{
		_maze[entry._row][entry._col] = ++count;
		path.push(entry);
		if (entry._row == N - 1)
		{
			printf("���ڵ�Ϊ[%d,%d]\n", entry._row, entry._col);
			if (path.size() < shortPath.size() || shortPath.empty())
			{
				shortPath = path;
				return;
			}
		}
		
		Pos next = entry;
		//̽����
		next._row -= 1;
		if (CheckAccess(entry,next))
			CricleMaze(next,path,shortPath,count);

		//��
		next = entry;
		next._row += 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);

		//��
		next = entry;
		next._col -= 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);
		//��
		next = entry;
		next._col += 1;
		if (CheckAccess(entry, next))
			CricleMaze(next, path, shortPath, count);

		path.pop();
	}

	bool CheckAccess(Pos cur, Pos next)
	{
		//1.���߽�
		//2.�Ƿ���ͨ· 0
		//3.���Ҵ�ı����߹���û�߹�
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
	int _maze[N][N]; //�Թ�
};