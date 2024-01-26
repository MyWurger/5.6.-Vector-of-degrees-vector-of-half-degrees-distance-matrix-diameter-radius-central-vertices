/********************************************************************************
 * Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №1  З А   5   С Е М Е С Т Р   С  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab1                                               *
 * File Name     : Lab1. CPP                                                    *
 * Programmer(s) : Викулов Д.Г.  &   Сашин А. Ю.                                *
 * Modifyed By   :                                                              *
 * Created       : 13/09/23                                                     *
 * Last Revision : 20/09/23                                                     *
 * Comment(s)    : Программа, рассчитывающая следующие характеристики           *
 *                 графа/орграфа: вектор степеней вершин, матрицу расстояний,   *
 *				   диаметр, радиус, множество центральных вершин (для графа)    *                   
 *				   множество периферийных вершин (для графа). Расчёт            *
 *				   производится алгоритмом Флойда-Уоршелла.                     *
 ********************************************************************************/


#include <iostream>              // стандартные потоки ввода/вывода
#include <vector>                // работа с векторами для удобства быстрого извлечения и удаления элементов
#include <fstream>               // работа с потоками ввода/вывода для файла
#include <iomanip>               // библиотека с модификатором setw
#include <graphviz/gvc.h>        // библиотека Graphviz для графического изображения графа по матрице смежности
#include <opencv2/opencv.hpp>    // заголовок, подтягивающий все функции OpenCv

using namespace std;             // используем пространство имён std




/*******************************************************************/
/*            Г Л О Б А Л Ь Н Ы Е    К О Н С Т А Н Т Ы             */
/*******************************************************************/

// путь к файлу через константный указатель
// Входные файлы
// ТЕСТЫ ДЛЯ МАТРИЦЫ СМЕЖНОСТИ
//const char* FNAMEIN = "matrix_t1_001.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_002.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_003.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_004.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_005.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_006.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_007.txt";           // файл с матрицей смежности
const char* FNAMEIN = "matrix_t1_008.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_009.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_010.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_011.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_012.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_013.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_014.txt";           // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t1_015.txt";           // файл с матрицей смежности

// ТЕСТЫ ДЛЯ СПИСКА РЕБЕР
//const char* FNAMEIN = "list_of_edges_t1_001.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_002.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_003.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_004.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_005.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_006.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_007.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_008.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_009.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_010.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_011.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_012.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_013.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_014.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t1_015.txt";         // файл со списком рёбер


// ТЕСТЫ ДЛЯ СПИСКА СМЕЖНОСТИ
//const char* FNAMEIN = "list_of_adjacency_t1_013.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t1_014.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t1_015.txt";     // файл со списком смежности


// ВЫХОДНЫЕ ФАЙЛЫ
const char* FNAMEOUT = "Output_File.txt";


// бесконечность для матрицы расстояний
const int INF = 10000;




/*******************************************************************/
/*      Г Л О Б А Л Ь Н Ы Е    Ф А Й Л О В Ы Е    П О Т О К И      */
/*******************************************************************/

 // объявление объекта для потокового ввода данных из файла
ifstream fin;
// объявление объекта для потокового вывода данных в файл
ofstream fout;




/*******************************************************************/
/*                 И Е Р А Р Х И Я   К Л А С С О В                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // граф в программе представлен матрицей смежности
	int m_size;                                               // размер матрицы смежности (количество вершин в графе)

public:
	// конструктор
	Graph();
	// деструктор
	~Graph();
	// константный геттер для получения значения размера
	const int GetSize();
	// функция возвращающая True, если граф ориентированный, False, если граф простой;
	bool is_directed();
	// функция, возвращающая матрицу смежности
	vector<vector<int>> adjacency_matrix();
	// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
	int Weight(int Vi, int Vj);
	// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
	bool is_edge(int Vi, int Vj);
	// функция, возвращающая список вершин, смежных вершине v;
	vector<int> adjacency_list(int v);
	// функция, возвращающая список всех рёбер графа;
	vector<pair<int, int>> list_of_edges_pairs();
	// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                 */
/*******************************************************************/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод графа на экран в виде картинки
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix);                     // матрица, которую необходимо вывести на экран. Передача по значению

// Алгоритм Флойда-Уоршелла
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays); // матрица кратчайших путей, с которой работаем. Передаётся по значению, а далее присваиваем основной матрице по типу возврата

// печать справки и авторов работы
void Usloviya();

// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix);                 // матрица, которую необходимо вывести в файл. Передача по значению


// Вывод в файл вектора степеней вершин
void PrintDegrees(Graph NewGraph                                  // объект графа
	            , vector<int> Degrees                             // вектор степеней вершин для неориентированного графа
	            , vector<int> DegIn                               // полустепень захода (для орграфа)
	            , vector<int> DegOut);                            // полустепень исхода (для орграфа)

// Выводы в файл остальных необходимых в условии значений
void PrintOthers(Graph NewGraph                                   // объект графа
	           , vector<int>Eccentricity                          // вектор для эксцентриситетов вершин. По значению
	           , bool CountEccentricity                           // признак того, стоит ли выводить эксцентриситет (нет, если в векторе бесконечность)
	           , int Radius                                       // радиус графа. По значению
	           , int Diameter                                     // диаметр графа
	           , vector<int> Central_Vertices                     // вектор множества центральных вершин графа. По значению
	           , vector<int> Peripheral_Vertices);                // вектор множества переферийных вершин графа. По значению




/*******************************************************************/
/*                      М Е Т О Д Ы   К Л А С С А                  */
/*******************************************************************/

// конструктор - считывание матрицы из файла
Graph::Graph()
{
	fin.open(FNAMEIN);            // связываем объект с файлом
	if (!fin.is_open())           // файл не найден
	{
		cout << "Файла с таким именем нет. Невозможно осуществить чтение";
		fin.close();              // закрыть файл для чтения
		system("pause");
		exit(0);                  // возвращаем значение, соответствующее типу в caller
	}// if (!fin.is_open())

	int value;                    // очередной считываемый символ
    char key;                     // ключ для указания пользователем варианта задания графа в файле
	bool spravka = true;          // ключ для вывода справки на экран
	vector<int> row;              // вектор для считывания промежуточных значений из файла построчно
	vector<vector<int>> matrix;   // вспомогательная матрица смежности

	// повтор ввода задания графа, когда пользователь захотел вывести на экран справку
	while (spravka)
	{
		cout << "\x1b[30m В В Е Д И Т Е   К Л Ю Ч   И Л И   <h>   Д Л Я   В Ы З О В А   П О Д С К А З К И : \x1b[30m";
		// пользователь ввёл ключ для того, чтобы явно указать, каким способом он задал граф
		cin >> key;
		cout << "\n Вы ввели: " << key << endl;

		// в зависимости от значения ключа
		switch (key)
		{
		// работа с матрицей смежности
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   М А Т Р И Ц А   С М Е Ж Н О С Т И\n\n\x1b[30m\n";
			// считываем очередное число из файла
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);

			}// while (fin >> value)

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работа со списком рёбер
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   Р Ё Б Е Р\n\n\x1b[30m\n";

			// считываем значения из файла в вектор
			// в векторе будут находиться с чередованием через три элементы: начальная вершина, конечная вершина и вес ребра
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);
			}// while (fin >> value)

			// закрыть файл чтения
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // размер матрицы смежности
			vector<vector<int>> vec_1(size_m);                // матрица смежности

			for (int i = 0; i < size_m; i++)                  // задаём размер каждой ячейки vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// заполняем матрицу смежности
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 элемент - это вес ребра, если он не указан, то значит он = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// запоминаем матрицу смежности
			m_matrix = vec_1;

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работаем со списками смежности
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   С М Е Ж Н О С Т И\n\n\x1b[30m\n";

			// чтение из файла построчно
			string line;
			int rowNumber = 0;            // номер текущей строки

			// чтение построчное
			while (getline(fin, line))
			{
				// Если строка пустая, заполняем текущую строку нулями
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// строка не пустая
				else
				{
					// вектор строки
					vector<int> row;
					// создает поток для чтения значений из строки line. Затем мы можем использовать iss вместе с оператором >> для извлечения значений из строки.
					istringstream iss(line);
					// очередная величина для чтения
					int value;

					// читаем значение из файла и помещаем его в вектор строки
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// помещаем строку в матрицу
					matrix.push_back(row);
				}// if (line.empty()) 

				// увеличиваем номер строки
				rowNumber++;
			}// while (getline(fin, line)) 

			// файл прочитан - закрываем его
			fin.close();

			m_size = matrix.size();                         // размер матрицы смежности

			std::vector<std::vector<int>> vec_1(m_size);    // доп матрица смежности размером m_size

			for (int i = 0; i < m_size; i++)                // задаём размер каждой ячейки доп матрицы смежности
			{
				// заполняем вспомогательную матрицу нулями по всему размеру
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // заполняем доп матрицу смежности 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// единица в тех столбцах, которые перечислены для данной в файле
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// загоняем значения в основную матрицу смежности
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// пользователь выбрал справку
		case('h'):
		case('H'):
		{
			// повторить ввод после появления мправки на экране
			spravka = true;
			// выводим условия
			Usloviya();
			break;
		}

		// иначе - пользователь ввёл не тот ключ. Заканчиваем программу с ошибкой
		default:
			cout << "\n\x1b[31m ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n\x1b[30m";
			// закрываем файл считывания
			fin.close();
			exit(0);
		}
	}
	// закрываем файл считывания
	fin.close();
	// запоминаем размер считанной/ преобразованной матрицы смежности
	m_size = m_matrix.size();
}


// деструктор
Graph::~Graph()
{
	// пустое тело - векторы уничтожаются автоматически
}


// геттер для получения значения размера
const int Graph:: GetSize()
{
	// вернуть значение размера
	return(m_size);
}


// функция возвращающая True, если граф ориентированный, False, если граф простой;
bool Graph::is_directed()
{
	// идём по строкам
	for (int i = 0; i < m_size; i++)
	{
		// идём по столбцам
		for (int j = 0; j < m_size; j++)
		{
			// если граф неориентированный, то матрица симметрична, так как по ребру можно пройти подвум направлениям
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // Найдено направленное ребро - граф ориентированный
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // Не найдено направленных ребер - граф неориентированный
}


// функция, возвращающая матрицу смежности
vector<vector<int>> Graph:: adjacency_matrix()
{
	return(m_matrix);
}


// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
int Graph::Weight(int Vi, int Vj)

{
	// номера вершин вышли за диапазоны допустимых значений
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "Ошибка! Такой вершины не существует\n";
		// вернули ошибку
		return(-1);
	}

	// если путь существует(в матрице смежности не 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "Вес ребра между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// возвращаем вес ребра между вершинами
		return(m_matrix[Vi][Vj]);
	}

	// граф ориентированный. Выводим вес дуги
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "Граф ориентированный. Дуга есть. Направление учитывается. Вес дуги между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		// возвращаем вес дуги
		return(m_matrix[Vi][Vj]);
	}

	// ребра между вершинами нет - элемент матрицы смежности равен 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "Ребра между вершинами " << Vi<<" и "<< Vj << "нет\n";
		// Вернули нулевое значение
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
bool Graph::is_edge(int Vi, int Vj)
{
	// номера вершин вышли за диапазоны допустимых значений - дуги нет
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// вернули, что дуги нет
		return(false);
	}

	// элемент матрицы смежности не равен 0 - ребро есть
	if (m_matrix[Vi][Vj] != 0)
	{
		// подтверждаем, что ребро есть
		return(true);
	}
	
	// элемент матрицы смежности нулевой - ребра нет
	if (m_matrix[Vi][Vj] == 0)
	{
		// подтверждаем, что ребра нет
		return(false);
	}

}


// функция, возвращающая список вершин, смежных вершине v;
vector<int> Graph:: adjacency_list(int v)
{
	// список вершин
	vector<int> adjList;

	// Проходим по всем вершинам и проверяем, есть ли ребро между вершиной v и текущей вершиной
	for (int i = 0; i < m_size; i++)
	{
		// путь есть - элемент матрицы не нулевой
		if (m_matrix[v][i] != 0)
		{
			// помещаем вершину в список
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// Возвращаем список смежных вершин
	return adjList;
}


// функция, возвращающая список всех рёбер графа;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// вектор пар, содержащий ребро в виде двух инцидентных ему вершин
	vector<pair<int, int>> edges_pairs;
	// идём по всем элементам строки
	for (int i = 0; i < m_size; i++)
	{
		// идём по всем элементам столбца
		for (int j = 0; j < m_size; j++)
		{
			// если элемент не нулевой
			if (m_matrix[i][j] != 0)
			{
				// загрузили пару вершин
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i
	// вернули вектор рёбер (пар вершин)
	return(edges_pairs);
}


// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // вектор пар вершин(вектор рёбер)
	vector<pair<int, int>> edges_inc;     // вектор рёбер инцидентных вершине v / исходящих из вершины v
	edges = list_of_edges_pairs();        // получаем все пары вершин графа

	// обходим эти пары. Если граф неориентированный, то там будет пара (v,n) и (n, v) - достаточно рассмотреть для инцидентности первый элемент. В орграфе - исходящий элемент всегда первый
	for (int i = 0; i < edges.size(); i++)
	{
		// рассматриваем первый элемент пары
		if (edges[i].first == v)
		{
			// помещаем в списо ребер, инцидентных вершине данное ребро
			edges_inc.push_back(edges[i]);
			// увеличиваем счётчик
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// возвращаем  список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                Функции               */
/*--------------------------------------*/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix) 
{
	// Проверяем размер матрицы смежности. Если больше 19, то считаем ее слишком большой
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// Проверяем наличие весов на ребрах, чтобы понять, нужно ли указывать их при выводе
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// Если вес ребра больше 1 или отрицательный, значит, нужно указывать вес в выводе
				if(adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
				key = true;
			}
		}

		// Открываем файл для записи графа в формате DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// Выводим граф с указанием весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++) 
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра не равен 0, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] != 0) 
					{
						// Выводим ребро с указанием веса в формате DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// Выводим граф без указания весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра равен 1, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] == 1) 
					{
						// Выводим ребро без указания веса в формате DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// Закрываем файл и сохраняем результаты
		file << "}" << std::endl;
		file.close();

		// Генерируем изображение графа в формате PNG с помощью утилиты DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// Выводим, что граф большой для рисования
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}

	// возвращаем картинку для открытия силами OpenCV
	return "graph.png";
}


// вывод графа на экран
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// Проверяем размерность матрицы смежности
	if (adjacencyMatrix.size() <= 19)
	{
		// Получаем путь к изображению, созданному с помощью функции drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// Загружаем изображение с помощью OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// Проверяем, удалось ли загрузить изображение
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// Создаем окно с названием "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// Показываем изображение в окне
		cv::imshow("Graph", img);
		// Ждем, пока пользователь нажмет любую клавишу
		cv::waitKey(0);
		// Закрываем окно
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
	
	// возвращаем обещанное значение
	return;
}


// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix)
{
	// отключаем русский язык
	setlocale(0, "C");            // выводим массив в красивых скобках
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size()*2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // вывод верхних квадратных скобок

	// идём по строкам
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// идём по столбцам
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим элемент матрицы
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // вывод верхних квадрат
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");
	
	// возвращаем обещанное значение
	return;
}


// Алгоритм Флойда-Уоршелла
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays) // матрица кратчайших путей, с которой работаем. Передаётся по значению, а далее присваиваем основной матрице по типу возврата
{
	// shortWays - изначально совпадает с матрицей смежности
	// подготавливаем матрицу кратчайших путей
	// идём по строкам
	for (int i = 0; i < shortWays.size(); i++)
	{
		// идём по столбцам
		for (int j = 0; j < shortWays.size(); j++)
		{
			//distInit[a][a] = 0
			if (i == j)
			{
				shortWays[i][j] = 0;
			}
			// Если между a и b нет ребра, то distInit[a][b] = INF
			else if (i != j && shortWays[i][j] == 0)
			{
				shortWays[i][j] = INF;
			}// if
		}// for j
	}// for i

	// смотрим все обходные пути, достижимые через промежуточные вершины
	for (int k = 0; k < shortWays.size(); k++)
	{
		// первая вершина пути
		for (int i = 0; i < shortWays.size(); i++)
		{
			// конечная вершина пути
			for (int j = 0; j < shortWays.size(); j++)
			{
				// Рабочая формула: shortWays[i][j] > shortWays[i][k] + shortWays[k][j]. Если путь через какую-либо промежуточную вершину короче, чем текущий
				if (shortWays[i][j] > shortWays[i][k] + shortWays[k][j])
				{
					// устанавливаем новое расстояние между этими вершинами
					shortWays[i][j] = shortWays[i][k] + shortWays[k][j];
				}// if
			}// for j
		}// for i
	}// for k

	// возвращаем матрицу кратчаййших путей
	return(shortWays);
}


// печать справки и авторов работы
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №1  З А   5   С Е М Е С Т Р   С  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab1                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab1. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : Викулов Д.Г.  &   Сашин А. Ю.                                 *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 13/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 20/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   С П Р А В К А : \n\n\x1b[30m";
	// Выводим условия в таблице
	setlocale(0, "C");                       // отключаем русский язык
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // выводим верхнюю строку шапки
	setlocale(LC_ALL, "Rus");                // подключаем русский язык
	cout << " Выберите одно значние из списка:      ";
	setlocale(0, "C");                       // отключаем русский язык
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // выводим нижнюю строку шапки с разделителем между номером и названием алгоритма
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // выводим условия выбора и нижнюю с боковыми строчками таблицы
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // подключаем русский язык
	
	return;                                 // возвращаем обещанное значение
}



// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix)                 // матрица, которую необходимо вывести в файл. Передача по значению
{
	// идём по строкам матрицы
	for (int i = 0; i < matrix.size(); i++)
	{
		// идём по столбцам матрицы
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим очередной элемент матрицы в файл
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// возвращаем обещанное значение
	return;
}

// Вывод в файл вектора степеней вершин
void PrintDegrees(Graph NewGraph                                  // объект графа
	, vector<int> Degrees                             // вектор степеней вершин для неориентированного графа
	, vector<int> DegIn                               // полустепень захода (для орграфа)
	, vector<int> DegOut)                             // полустепень исхода (для орграфа)
{
	// граф неориентированный
	if (!NewGraph.is_directed())
	{
		// выводим простой вектор степеней вершин
		fout << "\n\n В Е К  Т О Р   С Т Е П Е Н Е Й   В Е Р Ш И Н   Г Р А Ф А :\n";
		fout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			fout << Degrees[i] << " ";
		}// for i

		fout << "]\n";
	}

	// ориентированный граф
	else
	{
		fout << "\n\n В Е К  Т О Р   С Т Е П Е Н Е Й   В Е Р Ш И Н   О Р И Е Н Т И Р О В А Н Н О Г О   Г Р А Ф А :\n";
		// Вектор Degin - V - конечная вершина
		fout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegIn[i] << " ";
		}// for i

		fout << "]";

		// Вектор Degin - V - начальная вершина
		fout << "\n  DegOut: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegOut[i] << " ";
		}// for i

		fout << "]\n";
	}// if (!NewGraph.is_directed())

	// возвращаем обещанное значение
	return;
}


// остальные выводы в файл
// Выводы в файл остальных необходимых в условии значений
void PrintOthers(Graph NewGraph                                   // объект графа
	, vector<int>Eccentricity                          // вектор для эксцентриситетов вершин. По значению
	, bool CountEccentricity                           // признак того, стоит ли выводить эксцентриситет (нет, если в векторе бесконечность)
	, int Radius                                       // радиус графа. По значению
	, int Diameter                                     // диаметр графа
	, vector<int> Central_Vertices                     // вектор множества центральных вершин графа. По значению
	, vector<int> Peripheral_Vertices)                 // вектор множества переферийных вершин графа. По значению
{
	// Если понятие эксцентриситета имеет смысл - флаг true
	if (CountEccentricity)
	{
		fout << "\n\n Э К С Ц Е Н Т Р И С И Т Е Т Ы :\n";
		fout << "\n  Eccentricity: [ ";
		// выводим эксцентриситет на экран
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			fout << Eccentricity[i] << " ";;
		}// for i

		fout << "]\n";
	}// if (CountEccentricity)

	if (!NewGraph.is_directed())
	{
		// Если есть бесконечность, то понятия радиуса и диаметра, а следовательно центральных и переферийных вершин не имеют смысла
		if (Radius != INF && Diameter != INF)
		{
			fout << "\n\n Д И А М Е Т Р   И   Р А Д И У С   Г Р А Ф А :\n\n";
			// вывод диаметра и радиуса в файл
			fout << "  Graph radius: " << Radius << endl;
			fout << "  Graph diameter: " << Diameter << endl;

			fout << "\n\n М Н О Ж Е С Т В А   Ц Е Н Т Р А Л Ь Н Ы Х   И   П Е Р И Ф Е Р И Й Н Ы Х   В Е Р Ш И Н :\n\n";
			// вывод множества центральных и переферийных вершин в файл
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
	
	// возвращаем обещанное значение
	return;
}




/*------------------------------------------------------------------------*/
/*            Главная функция           */
/*--------------------------------------*/
int main()
{
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");
	// цвет консоли - белый
	system("color F0");
	// флаг печати в файл. Изначально - печати нет
	bool print = false;
	// ключ, введённый пользователем для печати
	char letter;
	// для простого графа
	vector<int> Degrees;                   // Вектор степеней вершин

	// для орграфа
	vector<int> DegIn;                     // Вектор Degin - V - конечная вершина
	vector<int> DegOut;                    // Вектор DegOut - V - начальная вершина

	cout << "\t\t\t\t\t\t\x1b[34m    Р А Б О Т А   С   Г Р А Ф А М И\x1b[30m\n\n\n";

	// создали объект графа. Конструктор применился по-умолчанию
	Graph NewGraph;

	// Выбор, хочет ли пользователь выводить в файл вычесленную информацию
	cout << " Хотите ли Вы выводить данные в файл? Введите <o>, если хотите, или любой другой символ - если нет. Введите: ";
	cin >> letter;                          // ввод пользователем
	cout << "\n Вы ввели: " << letter;      // эхо-печать

	// Если пользователь хочет печатать. Устанавливаем флаг
	if (letter == 'o' || letter == 'O')
	{
		print = true;
	}

	cout << "\n\n\x1b[35m М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\x1b[30m\n\n";
	// Выводим матрицу смежности по данным из файла на экран
	PrintMatrix(NewGraph.adjacency_matrix());
	 
	// РАСЧЕТ ВЕКТОРА СТЕПЕНЕЙ
	// неориентированный граф
	if (!NewGraph.is_directed())
	{
		cout << "\n\n\x1b[31m В Е К  Т О Р   С Т Е П Е Н Е Й   В Е Р Ш И Н   Г Р А Ф А :\x1b[30m\n";

		// Степень вершины - количество исходящих из неё рёбер
		// проходимся по всем вершинам графа
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// В вектор степеней вершин загоняем по порядку степени вершин, подсчитанные размером вектора, возвращающего ребра, инцидентные вершине i
			Degrees.push_back(NewGraph.list_of_edges(i).size());
		}// for i
		
		// Выводим вектор степеней вершин на экран
		cout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			cout << Degrees[i] << " ";
		}// for i
		cout << "]";
	}


	// ориентированный граф
	else
	{
		cout << "\n\n\x1b[31m В Е К  Т О Р   С Т Е П Е Н Е Й   В Е Р Ш И Н   О Р И Е Н Т И Р О В А Н Н О Г О   Г Р А Ф А :\x1b[30m\n";
		
		// вычисляем DegOut
		// идём по всем вершинам графа
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// подсчитываем рёбра, исходящие из данной вершины, подсчитанные размером вектора, возвращающего ребра, инцидентные вершине i
			DegOut.push_back(NewGraph.list_of_edges(i).size());
		}// for i

		// воводим на экран полученный вектор
		cout << "\n  DegOut: [ ";
		for (int i = 0; i < DegOut.size(); i++)
		{
			cout << DegOut[i] << " ";
		}// for i

		cout << "]";

		// получаем список рёбер графа, чтобы выяснять, когда вершина i будет конечной у ребра
		vector<pair<int, int>> pair = NewGraph.list_of_edges_pairs();
		int count = 0; // подсчет, сколько раз вершина была конечной

		// вычисляем DegIn
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// для каждой вершины счётчик запускается заново
			count = 0;
			// идем по всем элементам вектора пар
			for (int j = 0; j < NewGraph.list_of_edges_pairs().size(); j++)
			{
				// если вторым элементом является рассматриваемая вершина
				if (pair[j].second == i)
				{
					// увеличиваем счётчик
					count = count + 1;
				}// if (pair[j].second == i)
			}// for j
			// после рассмотрения очередной вершины по порядку помещаем её в вектор
			DegIn.push_back(count);
		}// for i

		// выводим накопленный вектор
		cout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			cout << DegIn[i] << " ";
		}// for i

		cout << "]";
	}// // if (!NewGraph.is_directed())
 
	// алгоритм Флойда-Уоршелла
	// Изначально за матрицу кратчайших путей принимаем матрицу смежности
	vector<vector<int>> shortWays = NewGraph.adjacency_matrix();
	// после применения алгоритма получаем итоговую матрицу кратчайших путей, с которой будем работать далее
	shortWays = Floyd_Ourshell(shortWays);
	
	// флаг подсчёта эксцентриситета
	bool CountEccentricity = true;
	cout << endl << endl;
	cout << "\n\x1b[36m М А Т Р И Ц А   Р А С С Т О Я Н И Й   Г Р А Ф А :\x1b[30m\n";
	// выводим матрицу кратчайших расстояний на экран
	PrintMatrix(shortWays);



	// Эксцентриситет - максимальный элемент в строке матрицы кратчайших путей
	int max = 0;                   // поиск максимума
	vector<int> Eccentricity;      // вектор эксцентриситетов

	// ищем максиммальный элемент в очередной строке матрицы кратчайших путей
	for (int i = 0; i < shortWays.size(); i++)
	{
		for (int j = 0; j < shortWays.size(); j++)
		{
			if (shortWays[i][j] > max)
			{
				max = shortWays[i][j];
			}// if (shortWays[i][j] > max)
		}// for j

		// если он - бесконечность, то понятие эксцентриситета не имеет смысла
		if (max == INF)
		{
			// убираем флаг
			CountEccentricity = false;
		}
		// помещаем найденный эксцентриситет в вектор
		Eccentricity.push_back(max);
		// очищаем максимальный элемент строки
		max = 0;
	}// for i

	// Если понятие эксцентриситета имеет смысл - флаг true
	if (CountEccentricity)
	{
		// выводим вектор на экран
		cout << "\n\n\x1b[34m Э К С Ц Е Н Т Р И С И Т Е Т Ы :\x1b[30m\n";
		cout << "\n  Eccentricity: [ ";
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			cout << Eccentricity[i] << " ";;
		}// for i
		cout << "]\n";
	}// 	if (CountEccentricity)

	// радиус и диаметр. Инициализируем элементом вектора эксцентриситетов
	int Radius = Eccentricity[0];
	int Diameter = Eccentricity[0];

	vector<int> Central_Vertices;
	vector<int> Peripheral_Vertices;

	// работаем с неориентированными графами. Все понятия ниже в данной работе имеют смысл только для них
	// ищем минимальный эксцентриситет в векторе - это и будет радиус графа
	// ищем максимальный эксцентриситет в векторе - это и будет диаметр графа
	if (!NewGraph.is_directed())
	{
		// идём по всем элементам вектора эксцентриситетов
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

		// Если какое-то из значений: радиус или диаметр - бесконечность. Их понятие в графе не имеет смысла
		// иначе - выводим их на экран
		if (Radius != INF && Diameter != INF)
		{
			cout << "\n\n\x1b[35m Д И А М Е Т Р   И   Р А Д И У С   Г Р А Ф А :\x1b[30m\n";
			cout << "  Graph radius: " << Radius << endl;
			cout << "  Graph diameter: " << Diameter << endl;
		}//if (Radius != INF && Diameter != INF)

		// центральные и периферийные вершины
		// номера вершин начинаются с 1 -> к каждому номеру прибавляем 1
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			// Выбираем вершины, у которых эксцентриситет равен радиусу - центральные вершины
			if (Radius == Eccentricity[i] && Radius != INF)
			{
				// помещаем в вектор очередную вершину
				Central_Vertices.push_back(i + 1);
			}// if (Radius == Eccentricity[i] && Radius != INF)

			// Выбираем вершины, у которых эксцентриситет равен диаметру - переферийные вершины
			if (Diameter == Eccentricity[i] && Diameter != INF)
			{
				// помещаем в вектор очередную вершину
				Peripheral_Vertices.push_back(i + 1);
			}// if (Diameter == Eccentricity[i] && Diameter != INF)
		}// for i

		//// Если какое-то из значений: радиус или диаметр - бесконечность. Тогда понятие центральных и переферийных вершин не имеет смысла
		// иначе - выводим их на экран
		if (Radius != INF && Diameter != INF)
		{
			// выводим значения на экран и в файл
			cout << "\n\n\x1b[33m М Н О Ж Е С Т В А   Ц Е Н Т Р А Л Ь Н Ы Х   И   П Е Р И Ф Е Р И Й Н Ы Х   В Е Р Ш И Н :\x1b[30m\n";
			cout << "  Central_Vertices: [ ";
			// выводим все центральные вершины
			for (int i = 0; i < Central_Vertices.size(); i++)
			{
				cout << Central_Vertices[i] << " ";
			}// for i
			cout << "]\n";


			cout << "  Peripheral_Vertices: [ ";
			// выводим все переферийные вершины
			for (int i = 0; i < Peripheral_Vertices.size(); i++)
			{
				cout << Peripheral_Vertices[i] << " ";
			}// for i
			cout << "]\n";
		}// if (Radius != INF && Diameter != INF)
	}// if (!NewGraph.is_directed())

	// пользователь захотел печатать информацию в файл
	if (print)
	{
		fout.open(FNAMEOUT);           // связываем объект с файлом
		if (!fout.is_open())           // файл не найден
		{
			cout << "Файла с таким именем нет. Невозможно осуществить чтение";
			fin.close();               // закрыть файл для чтения
			system("pause");
			exit(0);                   // возвращаем значение, соответствующее типу в caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    Р А Б О Т А   С   Г Р А Ф А М И\n\n\n";
		fout << "\n\n М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\n\n";
		// выводим матрицу смежности в файл
		PrintMatrToFile(NewGraph.adjacency_matrix());
		// выводим степени вершин в файл
		PrintDegrees(NewGraph, Degrees, DegIn, DegOut);
		fout << "\n М А Т Р И Ц А   Р А С С Т О Я Н И Й   Г Р А Ф А :\n\n";
		// выводим матрицу кратчайших путей в файл
		PrintMatrToFile(shortWays);
		// остальные выводы, необходимые по заданию, в файл
		PrintOthers(NewGraph, Eccentricity, CountEccentricity, Radius, Diameter, Central_Vertices, Peripheral_Vertices);

		// закрываем файл для вывода
		fout.close();
	}// if (print)

	// Выводим картинку с графом на экран
	OpenImage(NewGraph.adjacency_matrix());

	// возвращаем обещанное значение в функцию
	return 0;
}