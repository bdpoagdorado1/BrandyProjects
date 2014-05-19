#include <vector>
#include <iostream>
using namespace std;

#ifndef SORTER_H
#define SORTER_H

struct Node
{
	Node(int wn, int weightn) : w(wn) , weight(weightn), next(NULL) { }
		
	int w;
	int weight;
	Node * next;
};

class Graph
{
public:
	explicit Graph(int node0, int edge0) : node(node0),  edge(edge0) 
	{
		for (int i = 0; i <= node0; i++)
		{
			arr1[i] = NULL;
			arr2[i] = NULL;
		}
	}
	void build_list( int vn, int wn, int weightn)
	{
		if (arr1[vn] == NULL)
		{
			arr1[vn] = new Node(wn, weightn);
		}
		else
		{
			int z = 0;
			Node * go = arr1[vn];
			while(go != NULL)
			{
				if (go->next != NULL) go = go->next;
				else break;
			}
			go->next = new Node(wn, weightn);
		}

		if (arr2[wn] == NULL)
		{
			arr2[wn] = new Node(vn, weightn);
		}
		else
		{
			Node * go0 = arr2[wn];
			while(go0 != NULL)
			{
				if(go0->next != NULL) go0 = go0->next;
				else break;
			}
			go0->next = new Node(vn, weightn);
		}
	}

	void time(int num, int v)
	{
		int arr_critical[800] = {0};
		int arr_slack[200] = {0};
		int arr_ec[200] = {0};
		int arr_lc[200] = {0};
		int num1 = 0;
		for (int i = 1; i <= node; i++)
		{
			if (arr2[i] != NULL)
			{
				if (arr2[i]->weight != 0)
				{
					num1 = arr_ec[arr2[i]->w];
				}
				else
				{
					Node * go = arr2[i];
					while(go != NULL)
					{
						if (arr_ec[go->w] > num1) 
							num1 = arr_ec[go->w];
						go = go->next;
					}
				}
				arr_ec[i] = num1 + arr2[i]->weight;
			}
			num1 = 0;
		}
		
		///////////////////////////////////////////////////////////////
		num1 = arr_ec[node];
		arr_lc[node] = arr_ec[node];
		for (int i = node - 1; i >= 1; i--)
		{
			if (arr1[i] != NULL)
			{
				Node * go = arr1[i];
				num1 = arr_lc[go->w];
				while(go != NULL)
				{
					if (arr_lc[go->w]- go->weight < num1) 
						num1 = arr_lc[go->w] - go->weight;
					go = go->next;
				}
	
				arr_lc[i] = num1;
			}
		}
		
		for (int i = 1; i <= node; i++)
		{
			std::cout << "activity " << i << '\n';
			std::cout << "ec  " << arr_ec[i] << '\n';
			std::cout << "lc  " << arr_lc[i] << '\n';
			arr_slack[i] = arr_lc[i] - arr_ec[i];
			std::cout << "slack  " << arr_slack[i] << '\n' << '\n';
		}

		critical(1, 0, arr_slack, arr_critical);
	}

	void critical(int start, int i, int arr_slack[], int arr_critical[])
	{
		if (start == node && arr_slack[start] == 0)
		{
			i++;
			arr_critical[i] = start;
			std::cout << "critical path: \n";
			for(int k = 1; k <= i; k++)
				std::cout << arr_critical[k] << ' ';
			std::cout << '\n';
		}
		i++;
		Node * go = arr1[start];
		while (go != NULL)
		{
			if (arr_slack[start] == 0)
			{
				arr_critical[i] = start;
				critical(go->w, i, arr_slack, arr_critical);
			}
			go = go->next;
		}
	}

	int edge;
	int node;
	Node * arr1[200];
	Node * arr2[200];
};

#endif

