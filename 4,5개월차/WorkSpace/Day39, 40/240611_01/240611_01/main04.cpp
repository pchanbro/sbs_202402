#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 1. dijistra -> 현재까지 알고 있던 최단 경로를 계속해서 갱신함
//    - 설명 / 구현

// 2. 미로 길찾기를
//   - 무작정 길찾아보기 로직
//   - BFS(dijistra)로 길찾아보기

// 3. Astar 이론

struct Vertex
{
	int Index;
};

//struct Edge
//{
//	int From;
//	int To;
//	int Cost;
//}; 그래프 그릴 일이 있으면 이 struct를 쓰는게 맞는데 코딩테스트 같은곳에서 간단하게 그래프를 표시할 때는 2차원 배열을 사용
// 왜냐면 from, to를 사용하면 찾기가 어려움
// int 2차원배열 => 값을 cost

vector<Vertex> vertices;
vector<vector<int>> edges;


void CreateGraph()
{
	for (int i = 0; i < 6; i++)
	{
		vertices.push_back(Vertex({ i }));
	}

	// vector<int> a = vector<int>(6, -1)
	// a를 6개까지 늘리고, 모든 값을 -1로 한다.

	// vector<vector<int>> a = vector<vector<int>>(6, vector<int>(6, -1));
	// a를 6개 사이즈로 늘리고, 그 안의 벡터들을 각각 6개 사이즈로 하고 값을 모두 -1로 한다.
	edges = vector<vector<int>>(6, vector<int>(6, -1)); // -1은 못간다는 의미로

	edges[0][1] = 30;
	edges[1][0] = 30; // 양방향 값이 같도록 하려면 둘 다 쳐줘라

	edges[0][2] = 10;
	edges[2][0] = 10;

	edges[0][5] = 100;
	edges[5][0] = 100;

	edges[1][3] = 120;
	edges[3][1] = 120;

	edges[1][2] = 3;
	edges[2][1] = 3;

	edges[2][4] = 7;
	edges[4][2] = 7;

	edges[4][5] = 1;
	edges[5][4] = 1;


}

struct DijikstraNode
{
	int Cost;
	int Vertex;

	bool operator<(const DijikstraNode& other) const
	{
		return Cost > other.Cost;
	}

	bool operator>(const DijikstraNode& other) const
	{
		return Cost > other.Cost;
	}
};

void Dijikstra(int start)
{
	// 1. 이건 BFS 기반
	// 2. BFS -> Queue
	//    - dijikstra -> priority_queue
	// 코테볼때 dijikstra 써서 코테해도 되는데 이거 전용문제 아니면 그냥 BFS 써라

	// priority_queue 특징 (트리) (값이 추가 / 삭제) (루트에 넣어두고 도장깨리를 하던 / 뿌리에 넣어두고 역도장깨기를 하던)
	//   -> 내부에서 < 연산자를 사용

	/*DijikstraNode a{ 1, 2 };
	DijikstraNode b{ 2, 3 };
	printf("%d", a < b);*/ // 이게 greater라고 생각해도 된다.
	// greater, less 무엇일까

	// start -> end
	// start에서부터 정확히 어떤 노드를 타고가서 이 길찾기가 되었는지를 파악하는 방법
	// vector<int> parent(6, -1); 이걸 추가

	priority_queue<DijikstraNode, vector<DijikstraNode>, greater<DijikstraNode>> queue;
	
	// 각 인덱스로 가기위한 best 코스트
	vector<int> best(6, INT32_MAX);

	vector<int> parent(6, -1);
	// 각각 인덱스가 정점(Vertex)
	// 값 -> (어디서 타고왔는지를 체크해주는)

	queue.push(DijikstraNode{ 0, 0 });
	best[start] = 0;
	parent[start] = start;

	int here = start;
	while (queue.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		DijikstraNode node = queue.top();
		queue.pop();

		// 빙의 시작
		int cost = node.Cost;
		here = node.Vertex;

		// 더 짧은 경로를 뒤늦게 찾은 경우 스킵
		if (best[here] < cost)
		{
			continue;
		}

		cout << node.Vertex << "방문" << endl;

		for (int i = 0; i < best.size(); i++)
		{
			// 연결되어 있지 않으면 continue
			if (edges[here][i] == -1)
			{
				continue;
			}

			// 더 좋은 경로를 과거에 찾았다면 스킵
			int nextCost = best[here] + edges[here][i];
			if (best[i] <= nextCost)
			{
				continue;
			}

			// 지금까지 찾은 경로중에서 최선의 수치
			best[i] = nextCost;
			parent[i] = here;
			queue.push(DijikstraNode{ nextCost, i });
		}
	}

	cout << endl;
	for (int i = 0; i < parent.size(); i++)
	{
		cout << i << " <= " << parent[i] << "." << endl;
	}
	
}

void main()
{
	CreateGraph();
	Dijikstra(0);
}