/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �1  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab1                                               *
 * File Name     : Lab1. CPP                                                    *
 * Programmer(s) : ������� �.�.  &   ����� �. �.                                *
 * Modifyed By   :                                                              *
 * Created       : 13/09/23                                                     *
 * Last Revision : 20/09/23                                                     *
 * Comment(s)    : ���������, �������������� ��������� ��������������           *
 *                 �����/�������: ������ �������� ������, ������� ����������,   *
 *				   �������, ������, ��������� ����������� ������ (��� �����)    *                   
 *				   ��������� ������������ ������ (��� �����). ������            *
 *				   ������������ ���������� ������-��������.                     *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std




/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
//const char* FNAMEIN = "matrix_t1_001.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_002.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_003.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_004.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_005.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_006.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_007.txt";           // ���� � �������� ���������
const char* FNAMEIN = "matrix_t1_008.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_009.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_010.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_011.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_012.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_013.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_014.txt";           // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t1_015.txt";           // ���� � �������� ���������

// ����� ��� ������ �����
//const char* FNAMEIN = "list_of_edges_t1_001.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_002.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_003.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_004.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_005.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_006.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_007.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_008.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_009.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_010.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_011.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_012.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_013.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_014.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t1_015.txt";         // ���� �� ������� ����


// ����� ��� ������ ���������
//const char* FNAMEIN = "list_of_adjacency_t1_013.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t1_014.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t1_015.txt";     // ���� �� ������� ���������


// �������� �����
const char* FNAMEOUT = "Output_File.txt";


// ������������� ��� ������� ����������
const int INF = 10000;




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                     // �������, ������� ���������� ������� �� �����. �������� �� ��������

// �������� ������-��������
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays); // ������� ���������� �����, � ������� ��������. ��������� �� ��������, � ����� ����������� �������� ������� �� ���� ��������

// ������ ������� � ������� ������
void Usloviya();

// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix);                 // �������, ������� ���������� ������� � ����. �������� �� ��������


// ����� � ���� ������� �������� ������
void PrintDegrees(Graph NewGraph                                  // ������ �����
	            , vector<int> Degrees                             // ������ �������� ������ ��� ������������������ �����
	            , vector<int> DegIn                               // ����������� ������ (��� �������)
	            , vector<int> DegOut);                            // ����������� ������ (��� �������)

// ������ � ���� ��������� ����������� � ������� ��������
void PrintOthers(Graph NewGraph                                   // ������ �����
	           , vector<int>Eccentricity                          // ������ ��� ���������������� ������. �� ��������
	           , bool CountEccentricity                           // ������� ����, ����� �� �������� �������������� (���, ���� � ������� �������������)
	           , int Radius                                       // ������ �����. �� ��������
	           , int Diameter                                     // ������� �����
	           , vector<int> Central_Vertices                     // ������ ��������� ����������� ������ �����. �� ��������
	           , vector<int> Peripheral_Vertices);                // ������ ��������� ������������ ������ �����. �� ��������




/*******************************************************************/
/*                      � � � � � �   � � � � � �                  */
/*******************************************************************/

// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
    char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
		// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			// ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line))
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			std::vector<std::vector<int>> vec_1(m_size);    // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}


// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}


// ������ ��� ��������� �������� �������
const int Graph:: GetSize()
{
	// ������� �������� �������
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph:: adjacency_matrix()
{
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi<<" � "<< Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}
	
	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}

}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph:: adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i
	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix) 
{
	// ��������� ������ ������� ���������. ���� ������ 19, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if(adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
				key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++) 
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0) 
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1) 
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}

	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 19)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
	
	// ���������� ��������� ��������
	return;
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size()*2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	
	// ���������� ��������� ��������
	return;
}


// �������� ������-��������
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays) // ������� ���������� �����, � ������� ��������. ��������� �� ��������, � ����� ����������� �������� ������� �� ���� ��������
{
	// shortWays - ���������� ��������� � �������� ���������
	// �������������� ������� ���������� �����
	// ��� �� �������
	for (int i = 0; i < shortWays.size(); i++)
	{
		// ��� �� ��������
		for (int j = 0; j < shortWays.size(); j++)
		{
			//distInit[a][a] = 0
			if (i == j)
			{
				shortWays[i][j] = 0;
			}
			// ���� ����� a � b ��� �����, �� distInit[a][b] = INF
			else if (i != j && shortWays[i][j] == 0)
			{
				shortWays[i][j] = INF;
			}// if
		}// for j
	}// for i

	// ������� ��� �������� ����, ���������� ����� ������������� �������
	for (int k = 0; k < shortWays.size(); k++)
	{
		// ������ ������� ����
		for (int i = 0; i < shortWays.size(); i++)
		{
			// �������� ������� ����
			for (int j = 0; j < shortWays.size(); j++)
			{
				// ������� �������: shortWays[i][j] > shortWays[i][k] + shortWays[k][j]. ���� ���� ����� �����-���� ������������� ������� ������, ��� �������
				if (shortWays[i][j] > shortWays[i][k] + shortWays[k][j])
				{
					// ������������� ����� ���������� ����� ����� ���������
					shortWays[i][j] = shortWays[i][k] + shortWays[k][j];
				}// if
			}// for j
		}// for i
	}// for k

	// ���������� ������� ����������� �����
	return(shortWays);
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �1  � �   5   � � � � � � �   �  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab1                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab1. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.  &   ����� �. �.                                 *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 13/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 20/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����
	
	return;                                 // ���������� ��������� ��������
}



// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix)                 // �������, ������� ���������� ������� � ����. �������� �� ��������
{
	// ��� �� ������� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		// ��� �� �������� �������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ��������� ������� ������� � ����
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// ���������� ��������� ��������
	return;
}

// ����� � ���� ������� �������� ������
void PrintDegrees(Graph NewGraph                                  // ������ �����
	, vector<int> Degrees                             // ������ �������� ������ ��� ������������������ �����
	, vector<int> DegIn                               // ����������� ������ (��� �������)
	, vector<int> DegOut)                             // ����������� ������ (��� �������)
{
	// ���� �����������������
	if (!NewGraph.is_directed())
	{
		// ������� ������� ������ �������� ������
		fout << "\n\n � � �  � � �   � � � � � � � �   � � � � � �   � � � � � :\n";
		fout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			fout << Degrees[i] << " ";
		}// for i

		fout << "]\n";
	}

	// ��������������� ����
	else
	{
		fout << "\n\n � � �  � � �   � � � � � � � �   � � � � � �   � � � � � � � � � � � � � � � �   � � � � � :\n";
		// ������ Degin - V - �������� �������
		fout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegIn[i] << " ";
		}// for i

		fout << "]";

		// ������ Degin - V - ��������� �������
		fout << "\n  DegOut: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegOut[i] << " ";
		}// for i

		fout << "]\n";
	}// if (!NewGraph.is_directed())

	// ���������� ��������� ��������
	return;
}


// ��������� ������ � ����
// ������ � ���� ��������� ����������� � ������� ��������
void PrintOthers(Graph NewGraph                                   // ������ �����
	, vector<int>Eccentricity                          // ������ ��� ���������������� ������. �� ��������
	, bool CountEccentricity                           // ������� ����, ����� �� �������� �������������� (���, ���� � ������� �������������)
	, int Radius                                       // ������ �����. �� ��������
	, int Diameter                                     // ������� �����
	, vector<int> Central_Vertices                     // ������ ��������� ����������� ������ �����. �� ��������
	, vector<int> Peripheral_Vertices)                 // ������ ��������� ������������ ������ �����. �� ��������
{
	// ���� ������� ��������������� ����� ����� - ���� true
	if (CountEccentricity)
	{
		fout << "\n\n � � � � � � � � � � � � � � � :\n";
		fout << "\n  Eccentricity: [ ";
		// ������� �������������� �� �����
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			fout << Eccentricity[i] << " ";;
		}// for i

		fout << "]\n";
	}// if (CountEccentricity)

	if (!NewGraph.is_directed())
	{
		// ���� ���� �������������, �� ������� ������� � ��������, � ������������� ����������� � ������������ ������ �� ����� ������
		if (Radius != INF && Diameter != INF)
		{
			fout << "\n\n � � � � � � �   �   � � � � � �   � � � � � :\n\n";
			// ����� �������� � ������� � ����
			fout << "  Graph radius: " << Radius << endl;
			fout << "  Graph diameter: " << Diameter << endl;

			fout << "\n\n � � � � � � � � �   � � � � � � � � � � �   �   � � � � � � � � � � � �   � � � � � � :\n\n";
			// ����� ��������� ����������� � ������������ ������ � ����
			fout << "  Central_Vertices: [ ";
			for (int i = 0; i < Central_Vertices.size(); i++)
			{
				fout << Central_Vertices[i] << " ";
			}// for i
			fout << "]\n";


			fout << "  Peripheral_Vertices: [ ";
			for (int i = 0; i < Peripheral_Vertices.size(); i++)
			{
				fout << Peripheral_Vertices[i] << " ";
			}// for i
			fout << "]\n";
		}// if (Radius != INF && Diameter != INF)
	}// if (!NewGraph.is_directed())
	
	// ���������� ��������� ��������
	return;
}




/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;
	// ��� �������� �����
	vector<int> Degrees;                   // ������ �������� ������

	// ��� �������
	vector<int> DegIn;                     // ������ Degin - V - �������� �������
	vector<int> DegOut;                    // ������ DegOut - V - ��������� �������

	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";

	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                          // ���� �������������
	cout << "\n �� �����: " << letter;      // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		print = true;
	}

	cout << "\n\n\x1b[35m � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
	// ������� ������� ��������� �� ������ �� ����� �� �����
	PrintMatrix(NewGraph.adjacency_matrix());
	 
	// ������ ������� ��������
	// ����������������� ����
	if (!NewGraph.is_directed())
	{
		cout << "\n\n\x1b[31m � � �  � � �   � � � � � � � �   � � � � � �   � � � � � :\x1b[30m\n";

		// ������� ������� - ���������� ��������� �� �� ����
		// ���������� �� ���� �������� �����
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// � ������ �������� ������ �������� �� ������� ������� ������, ������������ �������� �������, ������������� �����, ����������� ������� i
			Degrees.push_back(NewGraph.list_of_edges(i).size());
		}// for i
		
		// ������� ������ �������� ������ �� �����
		cout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			cout << Degrees[i] << " ";
		}// for i
		cout << "]";
	}


	// ��������������� ����
	else
	{
		cout << "\n\n\x1b[31m � � �  � � �   � � � � � � � �   � � � � � �   � � � � � � � � � � � � � � � �   � � � � � :\x1b[30m\n";
		
		// ��������� DegOut
		// ��� �� ���� �������� �����
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// ������������ ����, ��������� �� ������ �������, ������������ �������� �������, ������������� �����, ����������� ������� i
			DegOut.push_back(NewGraph.list_of_edges(i).size());
		}// for i

		// ������� �� ����� ���������� ������
		cout << "\n  DegOut: [ ";
		for (int i = 0; i < DegOut.size(); i++)
		{
			cout << DegOut[i] << " ";
		}// for i

		cout << "]";

		// �������� ������ ���� �����, ����� ��������, ����� ������� i ����� �������� � �����
		vector<pair<int, int>> pair = NewGraph.list_of_edges_pairs();
		int count = 0; // �������, ������� ��� ������� ���� ��������

		// ��������� DegIn
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// ��� ������ ������� ������� ����������� ������
			count = 0;
			// ���� �� ���� ��������� ������� ���
			for (int j = 0; j < NewGraph.list_of_edges_pairs().size(); j++)
			{
				// ���� ������ ��������� �������� ��������������� �������
				if (pair[j].second == i)
				{
					// ����������� �������
					count = count + 1;
				}// if (pair[j].second == i)
			}// for j
			// ����� ������������ ��������� ������� �� ������� �������� � � ������
			DegIn.push_back(count);
		}// for i

		// ������� ����������� ������
		cout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			cout << DegIn[i] << " ";
		}// for i

		cout << "]";
	}// // if (!NewGraph.is_directed())
 
	// �������� ������-��������
	// ���������� �� ������� ���������� ����� ��������� ������� ���������
	vector<vector<int>> shortWays = NewGraph.adjacency_matrix();
	// ����� ���������� ��������� �������� �������� ������� ���������� �����, � ������� ����� �������� �����
	shortWays = Floyd_Ourshell(shortWays);
	
	// ���� �������� ���������������
	bool CountEccentricity = true;
	cout << endl << endl;
	cout << "\n\x1b[36m � � � � � � �   � � � � � � � � � �   � � � � � :\x1b[30m\n";
	// ������� ������� ���������� ���������� �� �����
	PrintMatrix(shortWays);



	// �������������� - ������������ ������� � ������ ������� ���������� �����
	int max = 0;                   // ����� ���������
	vector<int> Eccentricity;      // ������ ����������������

	// ���� ������������� ������� � ��������� ������ ������� ���������� �����
	for (int i = 0; i < shortWays.size(); i++)
	{
		for (int j = 0; j < shortWays.size(); j++)
		{
			if (shortWays[i][j] > max)
			{
				max = shortWays[i][j];
			}// if (shortWays[i][j] > max)
		}// for j

		// ���� �� - �������������, �� ������� ��������������� �� ����� ������
		if (max == INF)
		{
			// ������� ����
			CountEccentricity = false;
		}
		// �������� ��������� �������������� � ������
		Eccentricity.push_back(max);
		// ������� ������������ ������� ������
		max = 0;
	}// for i

	// ���� ������� ��������������� ����� ����� - ���� true
	if (CountEccentricity)
	{
		// ������� ������ �� �����
		cout << "\n\n\x1b[34m � � � � � � � � � � � � � � � :\x1b[30m\n";
		cout << "\n  Eccentricity: [ ";
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			cout << Eccentricity[i] << " ";;
		}// for i
		cout << "]\n";
	}// 	if (CountEccentricity)

	// ������ � �������. �������������� ��������� ������� ����������������
	int Radius = Eccentricity[0];
	int Diameter = Eccentricity[0];

	vector<int> Central_Vertices;
	vector<int> Peripheral_Vertices;

	// �������� � ������������������ �������. ��� ������� ���� � ������ ������ ����� ����� ������ ��� ���
	// ���� ����������� �������������� � ������� - ��� � ����� ������ �����
	// ���� ������������ �������������� � ������� - ��� � ����� ������� �����
	if (!NewGraph.is_directed())
	{
		// ��� �� ���� ��������� ������� ����������������
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			if (Radius > Eccentricity[i])
			{
				Radius = Eccentricity[i];
			}
			if (Diameter < Eccentricity[i])
			{
				Diameter = Eccentricity[i];
			}
		}// for i

		// ���� �����-�� �� ��������: ������ ��� ������� - �������������. �� ������� � ����� �� ����� ������
		// ����� - ������� �� �� �����
		if (Radius != INF && Diameter != INF)
		{
			cout << "\n\n\x1b[35m � � � � � � �   �   � � � � � �   � � � � � :\x1b[30m\n";
			cout << "  Graph radius: " << Radius << endl;
			cout << "  Graph diameter: " << Diameter << endl;
		}//if (Radius != INF && Diameter != INF)

		// ����������� � ������������ �������
		// ������ ������ ���������� � 1 -> � ������� ������ ���������� 1
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			// �������� �������, � ������� �������������� ����� ������� - ����������� �������
			if (Radius == Eccentricity[i] && Radius != INF)
			{
				// �������� � ������ ��������� �������
				Central_Vertices.push_back(i + 1);
			}// if (Radius == Eccentricity[i] && Radius != INF)

			// �������� �������, � ������� �������������� ����� �������� - ������������ �������
			if (Diameter == Eccentricity[i] && Diameter != INF)
			{
				// �������� � ������ ��������� �������
				Peripheral_Vertices.push_back(i + 1);
			}// if (Diameter == Eccentricity[i] && Diameter != INF)
		}// for i

		//// ���� �����-�� �� ��������: ������ ��� ������� - �������������. ����� ������� ����������� � ������������ ������ �� ����� ������
		// ����� - ������� �� �� �����
		if (Radius != INF && Diameter != INF)
		{
			// ������� �������� �� ����� � � ����
			cout << "\n\n\x1b[33m � � � � � � � � �   � � � � � � � � � � �   �   � � � � � � � � � � � �   � � � � � � :\x1b[30m\n";
			cout << "  Central_Vertices: [ ";
			// ������� ��� ����������� �������
			for (int i = 0; i < Central_Vertices.size(); i++)
			{
				cout << Central_Vertices[i] << " ";
			}// for i
			cout << "]\n";


			cout << "  Peripheral_Vertices: [ ";
			// ������� ��� ������������ �������
			for (int i = 0; i < Peripheral_Vertices.size(); i++)
			{
				cout << Peripheral_Vertices[i] << " ";
			}// for i
			cout << "]\n";
		}// if (Radius != INF && Diameter != INF)
	}// if (!NewGraph.is_directed())

	// ������������ ������� �������� ���������� � ����
	if (print)
	{
		fout.open(FNAMEOUT);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �\n\n\n";
		fout << "\n\n � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		// ������� ������� ��������� � ����
		PrintMatrToFile(NewGraph.adjacency_matrix());
		// ������� ������� ������ � ����
		PrintDegrees(NewGraph, Degrees, DegIn, DegOut);
		fout << "\n � � � � � � �   � � � � � � � � � �   � � � � � :\n\n";
		// ������� ������� ���������� ����� � ����
		PrintMatrToFile(shortWays);
		// ��������� ������, ����������� �� �������, � ����
		PrintOthers(NewGraph, Eccentricity, CountEccentricity, Radius, Diameter, Central_Vertices, Peripheral_Vertices);

		// ��������� ���� ��� ������
		fout.close();
	}// if (print)

	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());

	// ���������� ��������� �������� � �������
	return 0;
}