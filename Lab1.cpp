/********************************************************************************
 * Ë À Á Î Ð À Ò Î Ð Í À ß   Ð À Á Î Ò À  ¹1  Ç À   5   Ñ Å Ì Å Ñ Ò Ð   Ñ  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab1                                               *
 * File Name     : Lab1. CPP                                                    *
 * Programmer(s) : Âèêóëîâ Ä.Ã.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 13/09/23                                                     *
 * Last Revision : 20/09/23                                                     *
 * Comment(s)    : Ïðîãðàììà, ðàññ÷èòûâàþùàÿ ñëåäóþùèå õàðàêòåðèñòèêè           *
 *                 ãðàôà/îðãðàôà: âåêòîð ñòåïåíåé âåðøèí, ìàòðèöó ðàññòîÿíèé,   *
 *				   äèàìåòð, ðàäèóñ, ìíîæåñòâî öåíòðàëüíûõ âåðøèí (äëÿ ãðàôà)    *                   
 *				   ìíîæåñòâî ïåðèôåðèéíûõ âåðøèí (äëÿ ãðàôà). Ðàñ÷¸ò            *
 *				   ïðîèçâîäèòñÿ àëãîðèòìîì Ôëîéäà-Óîðøåëëà.                     *
 ********************************************************************************/


#include <iostream>              // ñòàíäàðòíûå ïîòîêè ââîäà/âûâîäà
#include <vector>                // ðàáîòà ñ âåêòîðàìè äëÿ óäîáñòâà áûñòðîãî èçâëå÷åíèÿ è óäàëåíèÿ ýëåìåíòîâ
#include <fstream>               // ðàáîòà ñ ïîòîêàìè ââîäà/âûâîäà äëÿ ôàéëà
#include <iomanip>               // áèáëèîòåêà ñ ìîäèôèêàòîðîì setw
#include <graphviz/gvc.h>        // áèáëèîòåêà Graphviz äëÿ ãðàôè÷åñêîãî èçîáðàæåíèÿ ãðàôà ïî ìàòðèöå ñìåæíîñòè
#include <opencv2/opencv.hpp>    // çàãîëîâîê, ïîäòÿãèâàþùèé âñå ôóíêöèè OpenCv

using namespace std;             // èñïîëüçóåì ïðîñòðàíñòâî èì¸í std




/*******************************************************************/
/*            Ã Ë Î Á À Ë Ü Í Û Å    Ê Î Í Ñ Ò À Í Ò Û             */
/*******************************************************************/

// ïóòü ê ôàéëó ÷åðåç êîíñòàíòíûé óêàçàòåëü
// Âõîäíûå ôàéëû
// ÒÅÑÒÛ ÄËß ÌÀÒÐÈÖÛ ÑÌÅÆÍÎÑÒÈ
//const char* FNAMEIN = "matrix_t1_001.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_002.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_003.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_004.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_005.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_006.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_007.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
const char* FNAMEIN = "matrix_t1_008.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_009.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_010.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_011.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_012.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_013.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_014.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè
//const char* FNAMEIN = "matrix_t1_015.txt";           // ôàéë ñ ìàòðèöåé ñìåæíîñòè

// ÒÅÑÒÛ ÄËß ÑÏÈÑÊÀ ÐÅÁÅÐ
//const char* FNAMEIN = "list_of_edges_t1_001.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_002.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_003.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_004.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_005.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_006.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_007.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_008.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_009.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_010.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_011.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_012.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_013.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_014.txt";         // ôàéë ñî ñïèñêîì ð¸áåð
//const char* FNAMEIN = "list_of_edges_t1_015.txt";         // ôàéë ñî ñïèñêîì ð¸áåð


// ÒÅÑÒÛ ÄËß ÑÏÈÑÊÀ ÑÌÅÆÍÎÑÒÈ
//const char* FNAMEIN = "list_of_adjacency_t1_013.txt";     // ôàéë ñî ñïèñêîì ñìåæíîñòè
//const char* FNAMEIN = "list_of_adjacency_t1_014.txt";     // ôàéë ñî ñïèñêîì ñìåæíîñòè
//const char* FNAMEIN = "list_of_adjacency_t1_015.txt";     // ôàéë ñî ñïèñêîì ñìåæíîñòè


// ÂÛÕÎÄÍÛÅ ÔÀÉËÛ
const char* FNAMEOUT = "Output_File.txt";


// áåñêîíå÷íîñòü äëÿ ìàòðèöû ðàññòîÿíèé
const int INF = 10000;




/*******************************************************************/
/*      Ã Ë Î Á À Ë Ü Í Û Å    Ô À É Ë Î Â Û Å    Ï Î Ò Î Ê È      */
/*******************************************************************/

 // îáúÿâëåíèå îáúåêòà äëÿ ïîòîêîâîãî ââîäà äàííûõ èç ôàéëà
ifstream fin;
// îáúÿâëåíèå îáúåêòà äëÿ ïîòîêîâîãî âûâîäà äàííûõ â ôàéë
ofstream fout;




/*******************************************************************/
/*                 È Å Ð À Ð Õ È ß   Ê Ë À Ñ Ñ Î Â                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ãðàô â ïðîãðàììå ïðåäñòàâëåí ìàòðèöåé ñìåæíîñòè
	int m_size;                                               // ðàçìåð ìàòðèöû ñìåæíîñòè (êîëè÷åñòâî âåðøèí â ãðàôå)

public:
	// êîíñòðóêòîð
	Graph();
	// äåñòðóêòîð
	~Graph();
	// êîíñòàíòíûé ãåòòåð äëÿ ïîëó÷åíèÿ çíà÷åíèÿ ðàçìåðà
	const int GetSize();
	// ôóíêöèÿ âîçâðàùàþùàÿ True, åñëè ãðàô îðèåíòèðîâàííûé, False, åñëè ãðàô ïðîñòîé;
	bool is_directed();
	// ôóíêöèÿ, âîçâðàùàþùàÿ ìàòðèöó ñìåæíîñòè
	vector<vector<int>> adjacency_matrix();
	// âåñîâàÿ ôóíêöèÿ, ïðèíèìàåò íîìåðà âåðøèí, âîçâðàùàåò âåñ ðåáðà, ñâÿçûâàþùåãî èõ;
	int Weight(int Vi, int Vj);
	// ôóíêöèÿ, ïðèíèìàþùàÿ íîìåðà âåðøèí è âîçâðàùàåò True, åñëè â ãðàôå åñòü ñîîòâåòñòâóþùåå ðåáðî / äóãà, False, åñëè ðåáðà íåò;
	bool is_edge(int Vi, int Vj);
	// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âåðøèí, ñìåæíûõ âåðøèíå v;
	vector<int> adjacency_list(int v);
	// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âñåõ ð¸áåð ãðàôà;
	vector<pair<int, int>> list_of_edges_pairs();
	// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âñåõ ð¸áåð ãðàôà, èíöèäåíòíûõ âåðøèíå v / èñõîäÿùèõ èç âåðøèíû v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              Ï Ð Î Ò Î Ò È Ï Û    Ô Ó Í Ê Ö È É                 */
/*******************************************************************/

// ñîõðàíåíèå ãðàôà êàê ôîòîãðàôèè
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // îáúÿâëåíèå êîíñòàíòíîé ññûëêè íà äâóìåðíûé âåêòîð adjacencyMatrix, ñîäåðæàùèé öåëî÷èñëåííûå çíà÷åíèÿ 

// âûâîä ãðàôà íà ýêðàí â âèäå êàðòèíêè
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // îáúÿâëåíèå êîíñòàíòíîé ññûëêè íà äâóìåðíûé âåêòîð adjacencyMatrix, ñîäåðæàùèé öåëî÷èñëåííûå çíà÷åíèÿ 

// âûâîä ìàòðèöû ñìåæíîñòè íà ýêðàí
void PrintMatrix(vector<vector<int>> matrix);                     // ìàòðèöà, êîòîðóþ íåîáõîäèìî âûâåñòè íà ýêðàí. Ïåðåäà÷à ïî çíà÷åíèþ

// Àëãîðèòì Ôëîéäà-Óîðøåëëà
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays); // ìàòðèöà êðàò÷àéøèõ ïóòåé, ñ êîòîðîé ðàáîòàåì. Ïåðåäà¸òñÿ ïî çíà÷åíèþ, à äàëåå ïðèñâàèâàåì îñíîâíîé ìàòðèöå ïî òèïó âîçâðàòà

// ïå÷àòü ñïðàâêè è àâòîðîâ ðàáîòû
void Usloviya();

// âûâîä ìàòðèöû  â ôàéë
void PrintMatrToFile(vector<vector<int>> matrix);                 // ìàòðèöà, êîòîðóþ íåîáõîäèìî âûâåñòè â ôàéë. Ïåðåäà÷à ïî çíà÷åíèþ


// Âûâîä â ôàéë âåêòîðà ñòåïåíåé âåðøèí
void PrintDegrees(Graph NewGraph                                  // îáúåêò ãðàôà
	            , vector<int> Degrees                             // âåêòîð ñòåïåíåé âåðøèí äëÿ íåîðèåíòèðîâàííîãî ãðàôà
	            , vector<int> DegIn                               // ïîëóñòåïåíü çàõîäà (äëÿ îðãðàôà)
	            , vector<int> DegOut);                            // ïîëóñòåïåíü èñõîäà (äëÿ îðãðàôà)

// Âûâîäû â ôàéë îñòàëüíûõ íåîáõîäèìûõ â óñëîâèè çíà÷åíèé
void PrintOthers(Graph NewGraph                                   // îáúåêò ãðàôà
	           , vector<int>Eccentricity                          // âåêòîð äëÿ ýêñöåíòðèñèòåòîâ âåðøèí. Ïî çíà÷åíèþ
	           , bool CountEccentricity                           // ïðèçíàê òîãî, ñòîèò ëè âûâîäèòü ýêñöåíòðèñèòåò (íåò, åñëè â âåêòîðå áåñêîíå÷íîñòü)
	           , int Radius                                       // ðàäèóñ ãðàôà. Ïî çíà÷åíèþ
	           , int Diameter                                     // äèàìåòð ãðàôà
	           , vector<int> Central_Vertices                     // âåêòîð ìíîæåñòâà öåíòðàëüíûõ âåðøèí ãðàôà. Ïî çíà÷åíèþ
	           , vector<int> Peripheral_Vertices);                // âåêòîð ìíîæåñòâà ïåðåôåðèéíûõ âåðøèí ãðàôà. Ïî çíà÷åíèþ




/*******************************************************************/
/*                      Ì Å Ò Î Ä Û   Ê Ë À Ñ Ñ À                  */
/*******************************************************************/

// êîíñòðóêòîð - ñ÷èòûâàíèå ìàòðèöû èç ôàéëà
Graph::Graph()
{
	fin.open(FNAMEIN);            // ñâÿçûâàåì îáúåêò ñ ôàéëîì
	if (!fin.is_open())           // ôàéë íå íàéäåí
	{
		cout << "Ôàéëà ñ òàêèì èìåíåì íåò. Íåâîçìîæíî îñóùåñòâèòü ÷òåíèå";
		fin.close();              // çàêðûòü ôàéë äëÿ ÷òåíèÿ
		system("pause");
		exit(0);                  // âîçâðàùàåì çíà÷åíèå, ñîîòâåòñòâóþùåå òèïó â caller
	}// if (!fin.is_open())

	int value;                    // î÷åðåäíîé ñ÷èòûâàåìûé ñèìâîë
    char key;                     // êëþ÷ äëÿ óêàçàíèÿ ïîëüçîâàòåëåì âàðèàíòà çàäàíèÿ ãðàôà â ôàéëå
	bool spravka = true;          // êëþ÷ äëÿ âûâîäà ñïðàâêè íà ýêðàí
	vector<int> row;              // âåêòîð äëÿ ñ÷èòûâàíèÿ ïðîìåæóòî÷íûõ çíà÷åíèé èç ôàéëà ïîñòðî÷íî
	vector<vector<int>> matrix;   // âñïîìîãàòåëüíàÿ ìàòðèöà ñìåæíîñòè

	// ïîâòîð ââîäà çàäàíèÿ ãðàôà, êîãäà ïîëüçîâàòåëü çàõîòåë âûâåñòè íà ýêðàí ñïðàâêó
	while (spravka)
	{
		cout << "\x1b[30m Â Â Å Ä È Ò Å   Ê Ë Þ ×   È Ë È   <h>   Ä Ë ß   Â Û Ç Î Â À   Ï Î Ä Ñ Ê À Ç Ê È : \x1b[30m";
		// ïîëüçîâàòåëü ââ¸ë êëþ÷ äëÿ òîãî, ÷òîáû ÿâíî óêàçàòü, êàêèì ñïîñîáîì îí çàäàë ãðàô
		cin >> key;
		cout << "\n Âû ââåëè: " << key << endl;

		// â çàâèñèìîñòè îò çíà÷åíèÿ êëþ÷à
		switch (key)
		{
		// ðàáîòà ñ ìàòðèöåé ñìåæíîñòè
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m Â Û   Â Û Á Ð À Ë È   Ò È Ï   Ç À Ä À Í È ß   -   Ì À Ò Ð È Ö À   Ñ Ì Å Æ Í Î Ñ Ò È\n\n\x1b[30m\n";
			// ñ÷èòûâàåì î÷åðåäíîå ÷èñëî èç ôàéëà
			while (fin >> value)
			{
				// ïîñëå ñ÷èòûâàíèÿ êàæäîé ñòðîêè î÷èùàåì âåêòîð ñòðîêè
				row.clear();
				// çàãîíÿåì â âåêòîð ïåðâûé ñ÷èòàííûé ýëåìåíò îò ïåðâîãî while (fin >> value)
				row.push_back(value);
				// ñ÷èòûâàåì âñå îñòàëüíûå ýëåìåíòû ñòðîêè, ïîêà íå íàøëè ñèìâîë å¸ îêîí÷àíèÿ - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// êëàäåì â ìàòðèöó ñ÷èòàííóþ ñòðîêó. Âñå ñòðîêè èìåþò îäèíàêîâûé ðàçìåð, òàê êàê ðàáîòàåì ñ ìàòðèöåé ñìåæíîñòè
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ïîâòîðÿòü ââîä íå íàäî. Ìàòðèöà çàïîëíåíà
			spravka = false;
			break;
		}

		// ðàáîòà ñî ñïèñêîì ð¸áåð
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m Â Û   Â Û Á Ð À Ë È   Ò È Ï   Ç À Ä À Í È ß   -   Ñ Ï È Ñ Î Ê   Ð ¨ Á Å Ð\n\n\x1b[30m\n";

			// ñ÷èòûâàåì çíà÷åíèÿ èç ôàéëà â âåêòîð
			// â âåêòîðå áóäóò íàõîäèòüñÿ ñ ÷åðåäîâàíèåì ÷åðåç òðè ýëåìåíòû: íà÷àëüíàÿ âåðøèíà, êîíå÷íàÿ âåðøèíà è âåñ ðåáðà
			while (fin >> value)
			{
				// ïîñëå ñ÷èòûâàíèÿ êàæäîé ñòðîêè î÷èùàåì âåêòîð ñòðîêè
				row.clear();
				// çàãîíÿåì â âåêòîð ïåðâûé ñ÷èòàííûé ýëåìåíò îò ïåðâîãî while (fin >> value)
				row.push_back(value);
				// ñ÷èòûâàåì âñå îñòàëüíûå ýëåìåíòû ñòðîêè, ïîêà íå íàøëè ñèìâîë å¸ îêîí÷àíèÿ - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// êëàäåì â ìàòðèöó ñ÷èòàííóþ ñòðîêó. Âñå ñòðîêè èìåþò îäèíàêîâûé ðàçìåð, òàê êàê ðàáîòàåì ñ ìàòðèöåé ñìåæíîñòè
				m_matrix.push_back(row);
			}// while (fin >> value)

			// çàêðûòü ôàéë ÷òåíèÿ
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ðàçìåð ìàòðèöû ñìåæíîñòè
			vector<vector<int>> vec_1(size_m);                // ìàòðèöà ñìåæíîñòè

			for (int i = 0; i < size_m; i++)                  // çàäà¸ì ðàçìåð êàæäîé ÿ÷åéêè vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// çàïîëíÿåì ìàòðèöó ñìåæíîñòè
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ýëåìåíò - ýòî âåñ ðåáðà, åñëè îí íå óêàçàí, òî çíà÷èò îí = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// çàïîìèíàåì ìàòðèöó ñìåæíîñòè
			m_matrix = vec_1;

			// ïîâòîðÿòü ââîä íå íàäî. Ìàòðèöà çàïîëíåíà
			spravka = false;
			break;
		}

		// ðàáîòàåì ñî ñïèñêàìè ñìåæíîñòè
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m Â Û   Â Û Á Ð À Ë È   Ò È Ï   Ç À Ä À Í È ß   -   Ñ Ï È Ñ Î Ê   Ñ Ì Å Æ Í Î Ñ Ò È\n\n\x1b[30m\n";

			// ÷òåíèå èç ôàéëà ïîñòðî÷íî
			string line;
			int rowNumber = 0;            // íîìåð òåêóùåé ñòðîêè

			// ÷òåíèå ïîñòðî÷íîå
			while (getline(fin, line))
			{
				// Åñëè ñòðîêà ïóñòàÿ, çàïîëíÿåì òåêóùóþ ñòðîêó íóëÿìè
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// ñòðîêà íå ïóñòàÿ
				else
				{
					// âåêòîð ñòðîêè
					vector<int> row;
					// ñîçäàåò ïîòîê äëÿ ÷òåíèÿ çíà÷åíèé èç ñòðîêè line. Çàòåì ìû ìîæåì èñïîëüçîâàòü iss âìåñòå ñ îïåðàòîðîì >> äëÿ èçâëå÷åíèÿ çíà÷åíèé èç ñòðîêè.
					istringstream iss(line);
					// î÷åðåäíàÿ âåëè÷èíà äëÿ ÷òåíèÿ
					int value;

					// ÷èòàåì çíà÷åíèå èç ôàéëà è ïîìåùàåì åãî â âåêòîð ñòðîêè
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// ïîìåùàåì ñòðîêó â ìàòðèöó
					matrix.push_back(row);
				}// if (line.empty()) 

				// óâåëè÷èâàåì íîìåð ñòðîêè
				rowNumber++;
			}// while (getline(fin, line)) 

			// ôàéë ïðî÷èòàí - çàêðûâàåì åãî
			fin.close();

			m_size = matrix.size();                         // ðàçìåð ìàòðèöû ñìåæíîñòè

			std::vector<std::vector<int>> vec_1(m_size);    // äîï ìàòðèöà ñìåæíîñòè ðàçìåðîì m_size

			for (int i = 0; i < m_size; i++)                // çàäà¸ì ðàçìåð êàæäîé ÿ÷åéêè äîï ìàòðèöû ñìåæíîñòè
			{
				// çàïîëíÿåì âñïîìîãàòåëüíóþ ìàòðèöó íóëÿìè ïî âñåìó ðàçìåðó
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // çàïîëíÿåì äîï ìàòðèöó ñìåæíîñòè 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// åäèíèöà â òåõ ñòîëáöàõ, êîòîðûå ïåðå÷èñëåíû äëÿ äàííîé â ôàéëå
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// çàãîíÿåì çíà÷åíèÿ â îñíîâíóþ ìàòðèöó ñìåæíîñòè
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ïîâòîðÿòü ââîä íå íàäî. Ìàòðèöà çàïîëíåíà
			spravka = false;
			break;
		}

		// ïîëüçîâàòåëü âûáðàë ñïðàâêó
		case('h'):
		case('H'):
		{
			// ïîâòîðèòü ââîä ïîñëå ïîÿâëåíèÿ ìïðàâêè íà ýêðàíå
			spravka = true;
			// âûâîäèì óñëîâèÿ
			Usloviya();
			break;
		}

		// èíà÷å - ïîëüçîâàòåëü ââ¸ë íå òîò êëþ÷. Çàêàí÷èâàåì ïðîãðàììó ñ îøèáêîé
		default:
			cout << "\n\x1b[31m ÏÅÐÅÇÀÏÓÑÒÈÒÅ ÏÐÎÃÐÀÌÌÓ È ÂÂÅÄÈÒÅ ÇÍÀ×ÅÍÈÅ ÈÇ ÑÏÈÑÊÀ ÊËÞ×ÅÉ!!!\n\x1b[30m";
			// çàêðûâàåì ôàéë ñ÷èòûâàíèÿ
			fin.close();
			exit(0);
		}
	}
	// çàêðûâàåì ôàéë ñ÷èòûâàíèÿ
	fin.close();
	// çàïîìèíàåì ðàçìåð ñ÷èòàííîé/ ïðåîáðàçîâàííîé ìàòðèöû ñìåæíîñòè
	m_size = m_matrix.size();
}


// äåñòðóêòîð
Graph::~Graph()
{
	// ïóñòîå òåëî - âåêòîðû óíè÷òîæàþòñÿ àâòîìàòè÷åñêè
}


// ãåòòåð äëÿ ïîëó÷åíèÿ çíà÷åíèÿ ðàçìåðà
const int Graph:: GetSize()
{
	// âåðíóòü çíà÷åíèå ðàçìåðà
	return(m_size);
}


// ôóíêöèÿ âîçâðàùàþùàÿ True, åñëè ãðàô îðèåíòèðîâàííûé, False, åñëè ãðàô ïðîñòîé;
bool Graph::is_directed()
{
	// èä¸ì ïî ñòðîêàì
	for (int i = 0; i < m_size; i++)
	{
		// èä¸ì ïî ñòîëáöàì
		for (int j = 0; j < m_size; j++)
		{
			// åñëè ãðàô íåîðèåíòèðîâàííûé, òî ìàòðèöà ñèììåòðè÷íà, òàê êàê ïî ðåáðó ìîæíî ïðîéòè ïîäâóì íàïðàâëåíèÿì
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // Íàéäåíî íàïðàâëåííîå ðåáðî - ãðàô îðèåíòèðîâàííûé
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // Íå íàéäåíî íàïðàâëåííûõ ðåáåð - ãðàô íåîðèåíòèðîâàííûé
}


// ôóíêöèÿ, âîçâðàùàþùàÿ ìàòðèöó ñìåæíîñòè
vector<vector<int>> Graph:: adjacency_matrix()
{
	return(m_matrix);
}


// âåñîâàÿ ôóíêöèÿ, ïðèíèìàåò íîìåðà âåðøèí, âîçâðàùàåò âåñ ðåáðà, ñâÿçûâàþùåãî èõ;
int Graph::Weight(int Vi, int Vj)

{
	// íîìåðà âåðøèí âûøëè çà äèàïàçîíû äîïóñòèìûõ çíà÷åíèé
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "Îøèáêà! Òàêîé âåðøèíû íå ñóùåñòâóåò\n";
		// âåðíóëè îøèáêó
		return(-1);
	}

	// åñëè ïóòü ñóùåñòâóåò(â ìàòðèöå ñìåæíîñòè íå 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "Âåñ ðåáðà ìåæäó âåðøèíàìè " << Vi << " è " << Vj << " ðàâåí" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// âîçâðàùàåì âåñ ðåáðà ìåæäó âåðøèíàìè
		return(m_matrix[Vi][Vj]);
	}

	// ãðàô îðèåíòèðîâàííûé. Âûâîäèì âåñ äóãè
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "Ãðàô îðèåíòèðîâàííûé. Äóãà åñòü. Íàïðàâëåíèå ó÷èòûâàåòñÿ. Âåñ äóãè ìåæäó âåðøèíàìè " << Vi << " è " << Vj << " ðàâåí" << m_matrix[Vi][Vj] << endl;
		// âîçâðàùàåì âåñ äóãè
		return(m_matrix[Vi][Vj]);
	}

	// ðåáðà ìåæäó âåðøèíàìè íåò - ýëåìåíò ìàòðèöû ñìåæíîñòè ðàâåí 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "Ðåáðà ìåæäó âåðøèíàìè " << Vi<<" è "<< Vj << "íåò\n";
		// Âåðíóëè íóëåâîå çíà÷åíèå
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// ôóíêöèÿ, ïðèíèìàþùàÿ íîìåðà âåðøèí è âîçâðàùàåò True, åñëè â ãðàôå åñòü ñîîòâåòñòâóþùåå ðåáðî / äóãà, False, åñëè ðåáðà íåò;
bool Graph::is_edge(int Vi, int Vj)
{
	// íîìåðà âåðøèí âûøëè çà äèàïàçîíû äîïóñòèìûõ çíà÷åíèé - äóãè íåò
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// âåðíóëè, ÷òî äóãè íåò
		return(false);
	}

	// ýëåìåíò ìàòðèöû ñìåæíîñòè íå ðàâåí 0 - ðåáðî åñòü
	if (m_matrix[Vi][Vj] != 0)
	{
		// ïîäòâåðæäàåì, ÷òî ðåáðî åñòü
		return(true);
	}
	
	// ýëåìåíò ìàòðèöû ñìåæíîñòè íóëåâîé - ðåáðà íåò
	if (m_matrix[Vi][Vj] == 0)
	{
		// ïîäòâåðæäàåì, ÷òî ðåáðà íåò
		return(false);
	}

}


// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âåðøèí, ñìåæíûõ âåðøèíå v;
vector<int> Graph:: adjacency_list(int v)
{
	// ñïèñîê âåðøèí
	vector<int> adjList;

	// Ïðîõîäèì ïî âñåì âåðøèíàì è ïðîâåðÿåì, åñòü ëè ðåáðî ìåæäó âåðøèíîé v è òåêóùåé âåðøèíîé
	for (int i = 0; i < m_size; i++)
	{
		// ïóòü åñòü - ýëåìåíò ìàòðèöû íå íóëåâîé
		if (m_matrix[v][i] != 0)
		{
			// ïîìåùàåì âåðøèíó â ñïèñîê
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// Âîçâðàùàåì ñïèñîê ñìåæíûõ âåðøèí
	return adjList;
}


// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âñåõ ð¸áåð ãðàôà;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// âåêòîð ïàð, ñîäåðæàùèé ðåáðî â âèäå äâóõ èíöèäåíòíûõ åìó âåðøèí
	vector<pair<int, int>> edges_pairs;
	// èä¸ì ïî âñåì ýëåìåíòàì ñòðîêè
	for (int i = 0; i < m_size; i++)
	{
		// èä¸ì ïî âñåì ýëåìåíòàì ñòîëáöà
		for (int j = 0; j < m_size; j++)
		{
			// åñëè ýëåìåíò íå íóëåâîé
			if (m_matrix[i][j] != 0)
			{
				// çàãðóçèëè ïàðó âåðøèí
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i
	// âåðíóëè âåêòîð ð¸áåð (ïàð âåðøèí)
	return(edges_pairs);
}


// ôóíêöèÿ, âîçâðàùàþùàÿ ñïèñîê âñåõ ð¸áåð ãðàôà, èíöèäåíòíûõ âåðøèíå v / èñõîäÿùèõ èç âåðøèíû v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // âåêòîð ïàð âåðøèí(âåêòîð ð¸áåð)
	vector<pair<int, int>> edges_inc;     // âåêòîð ð¸áåð èíöèäåíòíûõ âåðøèíå v / èñõîäÿùèõ èç âåðøèíû v
	edges = list_of_edges_pairs();        // ïîëó÷àåì âñå ïàðû âåðøèí ãðàôà

	// îáõîäèì ýòè ïàðû. Åñëè ãðàô íåîðèåíòèðîâàííûé, òî òàì áóäåò ïàðà (v,n) è (n, v) - äîñòàòî÷íî ðàññìîòðåòü äëÿ èíöèäåíòíîñòè ïåðâûé ýëåìåíò. Â îðãðàôå - èñõîäÿùèé ýëåìåíò âñåãäà ïåðâûé
	for (int i = 0; i < edges.size(); i++)
	{
		// ðàññìàòðèâàåì ïåðâûé ýëåìåíò ïàðû
		if (edges[i].first == v)
		{
			// ïîìåùàåì â ñïèñî ðåáåð, èíöèäåíòíûõ âåðøèíå äàííîå ðåáðî
			edges_inc.push_back(edges[i]);
			// óâåëè÷èâàåì ñ÷¸ò÷èê
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// âîçâðàùàåì  ñïèñîê âñåõ ð¸áåð ãðàôà, èíöèäåíòíûõ âåðøèíå v / èñõîäÿùèõ èç âåðøèíû v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                Ôóíêöèè               */
/*--------------------------------------*/

// ñîõðàíåíèå ãðàôà êàê ôîòîãðàôèè
string drawGraph(const vector<vector<int>>& adjacencyMatrix) 
{
	// Ïðîâåðÿåì ðàçìåð ìàòðèöû ñìåæíîñòè. Åñëè áîëüøå 19, òî ñ÷èòàåì åå ñëèøêîì áîëüøîé
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// Ïðîâåðÿåì íàëè÷èå âåñîâ íà ðåáðàõ, ÷òîáû ïîíÿòü, íóæíî ëè óêàçûâàòü èõ ïðè âûâîäå
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// Åñëè âåñ ðåáðà áîëüøå 1 èëè îòðèöàòåëüíûé, çíà÷èò, íóæíî óêàçûâàòü âåñ â âûâîäå
				if(adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
				key = true;
			}
		}

		// Îòêðûâàåì ôàéë äëÿ çàïèñè ãðàôà â ôîðìàòå DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// Âûâîäèì ãðàô ñ óêàçàíèåì âåñîâ ðåáåð
			for (int i = 0; i < adjacencyMatrix.size(); i++) 
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Ïðîâåðÿåì, ÷òî âåñ ðåáðà íå ðàâåí 0, ÷òîáû íå âûâîäèòü íåíóæíûå ðåáðà
					if (adjacencyMatrix[i][j] != 0) 
					{
						// Âûâîäèì ðåáðî ñ óêàçàíèåì âåñà â ôîðìàòå DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// Âûâîäèì ãðàô áåç óêàçàíèÿ âåñîâ ðåáåð
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Ïðîâåðÿåì, ÷òî âåñ ðåáðà ðàâåí 1, ÷òîáû íå âûâîäèòü íåíóæíûå ðåáðà
					if (adjacencyMatrix[i][j] == 1) 
					{
						// Âûâîäèì ðåáðî áåç óêàçàíèÿ âåñà â ôîðìàòå DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// Çàêðûâàåì ôàéë è ñîõðàíÿåì ðåçóëüòàòû
		file << "}" << std::endl;
		file.close();

		// Ãåíåðèðóåì èçîáðàæåíèå ãðàôà â ôîðìàòå PNG ñ ïîìîùüþ óòèëèòû DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// Âûâîäèì, ÷òî ãðàô áîëüøîé äëÿ ðèñîâàíèÿ
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}

	// âîçâðàùàåì êàðòèíêó äëÿ îòêðûòèÿ ñèëàìè OpenCV
	return "graph.png";
}


// âûâîä ãðàôà íà ýêðàí
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// Ïðîâåðÿåì ðàçìåðíîñòü ìàòðèöû ñìåæíîñòè
	if (adjacencyMatrix.size() <= 19)
	{
		// Ïîëó÷àåì ïóòü ê èçîáðàæåíèþ, ñîçäàííîìó ñ ïîìîùüþ ôóíêöèè drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// Çàãðóæàåì èçîáðàæåíèå ñ ïîìîùüþ OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// Ïðîâåðÿåì, óäàëîñü ëè çàãðóçèòü èçîáðàæåíèå
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// Ñîçäàåì îêíî ñ íàçâàíèåì "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// Ïîêàçûâàåì èçîáðàæåíèå â îêíå
		cv::imshow("Graph", img);
		// Æäåì, ïîêà ïîëüçîâàòåëü íàæìåò ëþáóþ êëàâèøó
		cv::waitKey(0);
		// Çàêðûâàåì îêíî
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
	
	// âîçâðàùàåì îáåùàííîå çíà÷åíèå
	return;
}


// âûâîä ìàòðèöû ñìåæíîñòè íà ýêðàí
void PrintMatrix(vector<vector<int>> matrix)
{
	// îòêëþ÷àåì ðóññêèé ÿçûê
	setlocale(0, "C");            // âûâîäèì ìàññèâ â êðàñèâûõ ñêîáêàõ
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size()*2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // âûâîä âåðõíèõ êâàäðàòíûõ ñêîáîê

	// èä¸ì ïî ñòðîêàì
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// èä¸ì ïî ñòîëáöàì
		for (int j = 0; j < matrix.size(); j++)
		{
			// âûâîäèì ýëåìåíò ìàòðèöû
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // âûâîä âåðõíèõ êâàäðàò
	// ïîäêëþ÷àåì ðóññêèé ÿçûê
	setlocale(LC_ALL, "Russian");
	
	// âîçâðàùàåì îáåùàííîå çíà÷åíèå
	return;
}


// Àëãîðèòì Ôëîéäà-Óîðøåëëà
vector<vector<int>>Floyd_Ourshell(vector<vector<int>> shortWays) // ìàòðèöà êðàò÷àéøèõ ïóòåé, ñ êîòîðîé ðàáîòàåì. Ïåðåäà¸òñÿ ïî çíà÷åíèþ, à äàëåå ïðèñâàèâàåì îñíîâíîé ìàòðèöå ïî òèïó âîçâðàòà
{
	// shortWays - èçíà÷àëüíî ñîâïàäàåò ñ ìàòðèöåé ñìåæíîñòè
	// ïîäãîòàâëèâàåì ìàòðèöó êðàò÷àéøèõ ïóòåé
	// èä¸ì ïî ñòðîêàì
	for (int i = 0; i < shortWays.size(); i++)
	{
		// èä¸ì ïî ñòîëáöàì
		for (int j = 0; j < shortWays.size(); j++)
		{
			//distInit[a][a] = 0
			if (i == j)
			{
				shortWays[i][j] = 0;
			}
			// Åñëè ìåæäó a è b íåò ðåáðà, òî distInit[a][b] = INF
			else if (i != j && shortWays[i][j] == 0)
			{
				shortWays[i][j] = INF;
			}// if
		}// for j
	}// for i

	// ñìîòðèì âñå îáõîäíûå ïóòè, äîñòèæèìûå ÷åðåç ïðîìåæóòî÷íûå âåðøèíû
	for (int k = 0; k < shortWays.size(); k++)
	{
		// ïåðâàÿ âåðøèíà ïóòè
		for (int i = 0; i < shortWays.size(); i++)
		{
			// êîíå÷íàÿ âåðøèíà ïóòè
			for (int j = 0; j < shortWays.size(); j++)
			{
				// Ðàáî÷àÿ ôîðìóëà: shortWays[i][j] > shortWays[i][k] + shortWays[k][j]. Åñëè ïóòü ÷åðåç êàêóþ-ëèáî ïðîìåæóòî÷íóþ âåðøèíó êîðî÷å, ÷åì òåêóùèé
				if (shortWays[i][j] > shortWays[i][k] + shortWays[k][j])
				{
					// óñòàíàâëèâàåì íîâîå ðàññòîÿíèå ìåæäó ýòèìè âåðøèíàìè
					shortWays[i][j] = shortWays[i][k] + shortWays[k][j];
				}// if
			}// for j
		}// for i
	}// for k

	// âîçâðàùàåì ìàòðèöó êðàò÷àééøèõ ïóòåé
	return(shortWays);
}


// ïå÷àòü ñïðàâêè è àâòîðîâ ðàáîòû
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* Ë À Á Î Ð À Ò Î Ð Í À ß   Ð À Á Î Ò À  ¹1  Ç À   5   Ñ Å Ì Å Ñ Ò Ð   Ñ  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab1                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab1. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : Âèêóëîâ Ä.Ã.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 13/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 20/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   Ñ Ï Ð À Â Ê À : \n\n\x1b[30m";
	// Âûâîäèì óñëîâèÿ â òàáëèöå
	setlocale(0, "C");                       // îòêëþ÷àåì ðóññêèé ÿçûê
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // âûâîäèì âåðõíþþ ñòðîêó øàïêè
	setlocale(LC_ALL, "Rus");                // ïîäêëþ÷àåì ðóññêèé ÿçûê
	cout << " Âûáåðèòå îäíî çíà÷íèå èç ñïèñêà:      ";
	setlocale(0, "C");                       // îòêëþ÷àåì ðóññêèé ÿçûê
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // âûâîäèì íèæíþþ ñòðîêó øàïêè ñ ðàçäåëèòåëåì ìåæäó íîìåðîì è íàçâàíèåì àëãîðèòìà
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // âûâîäèì óñëîâèÿ âûáîðà è íèæíþþ ñ áîêîâûìè ñòðî÷êàìè òàáëèöû
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ïîäêëþ÷àåì ðóññêèé ÿçûê
	
	return;                                 // âîçâðàùàåì îáåùàííîå çíà÷åíèå
}



// âûâîä ìàòðèöû  â ôàéë
void PrintMatrToFile(vector<vector<int>> matrix)                 // ìàòðèöà, êîòîðóþ íåîáõîäèìî âûâåñòè â ôàéë. Ïåðåäà÷à ïî çíà÷åíèþ
{
	// èä¸ì ïî ñòðîêàì ìàòðèöû
	for (int i = 0; i < matrix.size(); i++)
	{
		// èä¸ì ïî ñòîëáöàì ìàòðèöû
		for (int j = 0; j < matrix.size(); j++)
		{
			// âûâîäèì î÷åðåäíîé ýëåìåíò ìàòðèöû â ôàéë
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// âîçâðàùàåì îáåùàííîå çíà÷åíèå
	return;
}

// Âûâîä â ôàéë âåêòîðà ñòåïåíåé âåðøèí
void PrintDegrees(Graph NewGraph                                  // îáúåêò ãðàôà
	, vector<int> Degrees                             // âåêòîð ñòåïåíåé âåðøèí äëÿ íåîðèåíòèðîâàííîãî ãðàôà
	, vector<int> DegIn                               // ïîëóñòåïåíü çàõîäà (äëÿ îðãðàôà)
	, vector<int> DegOut)                             // ïîëóñòåïåíü èñõîäà (äëÿ îðãðàôà)
{
	// ãðàô íåîðèåíòèðîâàííûé
	if (!NewGraph.is_directed())
	{
		// âûâîäèì ïðîñòîé âåêòîð ñòåïåíåé âåðøèí
		fout << "\n\n Â Å Ê  Ò Î Ð   Ñ Ò Å Ï Å Í Å É   Â Å Ð Ø È Í   Ã Ð À Ô À :\n";
		fout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			fout << Degrees[i] << " ";
		}// for i

		fout << "]\n";
	}

	// îðèåíòèðîâàííûé ãðàô
	else
	{
		fout << "\n\n Â Å Ê  Ò Î Ð   Ñ Ò Å Ï Å Í Å É   Â Å Ð Ø È Í   Î Ð È Å Í Ò È Ð Î Â À Í Í Î Ã Î   Ã Ð À Ô À :\n";
		// Âåêòîð Degin - V - êîíå÷íàÿ âåðøèíà
		fout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegIn[i] << " ";
		}// for i

		fout << "]";

		// Âåêòîð Degin - V - íà÷àëüíàÿ âåðøèíà
		fout << "\n  DegOut: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			fout << DegOut[i] << " ";
		}// for i

		fout << "]\n";
	}// if (!NewGraph.is_directed())

	// âîçâðàùàåì îáåùàííîå çíà÷åíèå
	return;
}


// îñòàëüíûå âûâîäû â ôàéë
// Âûâîäû â ôàéë îñòàëüíûõ íåîáõîäèìûõ â óñëîâèè çíà÷åíèé
void PrintOthers(Graph NewGraph                                   // îáúåêò ãðàôà
	, vector<int>Eccentricity                          // âåêòîð äëÿ ýêñöåíòðèñèòåòîâ âåðøèí. Ïî çíà÷åíèþ
	, bool CountEccentricity                           // ïðèçíàê òîãî, ñòîèò ëè âûâîäèòü ýêñöåíòðèñèòåò (íåò, åñëè â âåêòîðå áåñêîíå÷íîñòü)
	, int Radius                                       // ðàäèóñ ãðàôà. Ïî çíà÷åíèþ
	, int Diameter                                     // äèàìåòð ãðàôà
	, vector<int> Central_Vertices                     // âåêòîð ìíîæåñòâà öåíòðàëüíûõ âåðøèí ãðàôà. Ïî çíà÷åíèþ
	, vector<int> Peripheral_Vertices)                 // âåêòîð ìíîæåñòâà ïåðåôåðèéíûõ âåðøèí ãðàôà. Ïî çíà÷åíèþ
{
	// Åñëè ïîíÿòèå ýêñöåíòðèñèòåòà èìååò ñìûñë - ôëàã true
	if (CountEccentricity)
	{
		fout << "\n\n Ý Ê Ñ Ö Å Í Ò Ð È Ñ È Ò Å Ò Û :\n";
		fout << "\n  Eccentricity: [ ";
		// âûâîäèì ýêñöåíòðèñèòåò íà ýêðàí
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			fout << Eccentricity[i] << " ";;
		}// for i

		fout << "]\n";
	}// if (CountEccentricity)

	if (!NewGraph.is_directed())
	{
		// Åñëè åñòü áåñêîíå÷íîñòü, òî ïîíÿòèÿ ðàäèóñà è äèàìåòðà, à ñëåäîâàòåëüíî öåíòðàëüíûõ è ïåðåôåðèéíûõ âåðøèí íå èìåþò ñìûñëà
		if (Radius != INF && Diameter != INF)
		{
			fout << "\n\n Ä È À Ì Å Ò Ð   È   Ð À Ä È Ó Ñ   Ã Ð À Ô À :\n\n";
			// âûâîä äèàìåòðà è ðàäèóñà â ôàéë
			fout << "  Graph radius: " << Radius << endl;
			fout << "  Graph diameter: " << Diameter << endl;

			fout << "\n\n Ì Í Î Æ Å Ñ Ò Â À   Ö Å Í Ò Ð À Ë Ü Í Û Õ   È   Ï Å Ð È Ô Å Ð È É Í Û Õ   Â Å Ð Ø È Í :\n\n";
			// âûâîä ìíîæåñòâà öåíòðàëüíûõ è ïåðåôåðèéíûõ âåðøèí â ôàéë
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
	
	// âîçâðàùàåì îáåùàííîå çíà÷åíèå
	return;
}




/*------------------------------------------------------------------------*/
/*            Ãëàâíàÿ ôóíêöèÿ           */
/*--------------------------------------*/
int main()
{
	// ïîäêëþ÷àåì ðóññêèé ÿçûê
	setlocale(LC_ALL, "Russian");
	// öâåò êîíñîëè - áåëûé
	system("color F0");
	// ôëàã ïå÷àòè â ôàéë. Èçíà÷àëüíî - ïå÷àòè íåò
	bool print = false;
	// êëþ÷, ââåä¸ííûé ïîëüçîâàòåëåì äëÿ ïå÷àòè
	char letter;
	// äëÿ ïðîñòîãî ãðàôà
	vector<int> Degrees;                   // Âåêòîð ñòåïåíåé âåðøèí

	// äëÿ îðãðàôà
	vector<int> DegIn;                     // Âåêòîð Degin - V - êîíå÷íàÿ âåðøèíà
	vector<int> DegOut;                    // Âåêòîð DegOut - V - íà÷àëüíàÿ âåðøèíà

	cout << "\t\t\t\t\t\t\x1b[34m    Ð À Á Î Ò À   Ñ   Ã Ð À Ô À Ì È\x1b[30m\n\n\n";

	// ñîçäàëè îáúåêò ãðàôà. Êîíñòðóêòîð ïðèìåíèëñÿ ïî-óìîë÷àíèþ
	Graph NewGraph;

	// Âûáîð, õî÷åò ëè ïîëüçîâàòåëü âûâîäèòü â ôàéë âû÷åñëåííóþ èíôîðìàöèþ
	cout << " Õîòèòå ëè Âû âûâîäèòü äàííûå â ôàéë? Ââåäèòå <o>, åñëè õîòèòå, èëè ëþáîé äðóãîé ñèìâîë - åñëè íåò. Ââåäèòå: ";
	cin >> letter;                          // ââîä ïîëüçîâàòåëåì
	cout << "\n Âû ââåëè: " << letter;      // ýõî-ïå÷àòü

	// Åñëè ïîëüçîâàòåëü õî÷åò ïå÷àòàòü. Óñòàíàâëèâàåì ôëàã
	if (letter == 'o' || letter == 'O')
	{
		print = true;
	}

	cout << "\n\n\x1b[35m Ì À Ò Ð È Ö À   Ñ Ì Å Æ Í Î Ñ Ò È   Ï Î   È Ñ Õ Î Ä Í Û Ì   Ä À Í Í Û Ì :\x1b[30m\n\n";
	// Âûâîäèì ìàòðèöó ñìåæíîñòè ïî äàííûì èç ôàéëà íà ýêðàí
	PrintMatrix(NewGraph.adjacency_matrix());
	 
	// ÐÀÑ×ÅÒ ÂÅÊÒÎÐÀ ÑÒÅÏÅÍÅÉ
	// íåîðèåíòèðîâàííûé ãðàô
	if (!NewGraph.is_directed())
	{
		cout << "\n\n\x1b[31m Â Å Ê  Ò Î Ð   Ñ Ò Å Ï Å Í Å É   Â Å Ð Ø È Í   Ã Ð À Ô À :\x1b[30m\n";

		// Ñòåïåíü âåðøèíû - êîëè÷åñòâî èñõîäÿùèõ èç íå¸ ð¸áåð
		// ïðîõîäèìñÿ ïî âñåì âåðøèíàì ãðàôà
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// Â âåêòîð ñòåïåíåé âåðøèí çàãîíÿåì ïî ïîðÿäêó ñòåïåíè âåðøèí, ïîäñ÷èòàííûå ðàçìåðîì âåêòîðà, âîçâðàùàþùåãî ðåáðà, èíöèäåíòíûå âåðøèíå i
			Degrees.push_back(NewGraph.list_of_edges(i).size());
		}// for i
		
		// Âûâîäèì âåêòîð ñòåïåíåé âåðøèí íà ýêðàí
		cout << "\n  Degrees: [ ";
		for (int i = 0; i < Degrees.size(); i++)
		{
			cout << Degrees[i] << " ";
		}// for i
		cout << "]";
	}


	// îðèåíòèðîâàííûé ãðàô
	else
	{
		cout << "\n\n\x1b[31m Â Å Ê  Ò Î Ð   Ñ Ò Å Ï Å Í Å É   Â Å Ð Ø È Í   Î Ð È Å Í Ò È Ð Î Â À Í Í Î Ã Î   Ã Ð À Ô À :\x1b[30m\n";
		
		// âû÷èñëÿåì DegOut
		// èä¸ì ïî âñåì âåðøèíàì ãðàôà
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// ïîäñ÷èòûâàåì ð¸áðà, èñõîäÿùèå èç äàííîé âåðøèíû, ïîäñ÷èòàííûå ðàçìåðîì âåêòîðà, âîçâðàùàþùåãî ðåáðà, èíöèäåíòíûå âåðøèíå i
			DegOut.push_back(NewGraph.list_of_edges(i).size());
		}// for i

		// âîâîäèì íà ýêðàí ïîëó÷åííûé âåêòîð
		cout << "\n  DegOut: [ ";
		for (int i = 0; i < DegOut.size(); i++)
		{
			cout << DegOut[i] << " ";
		}// for i

		cout << "]";

		// ïîëó÷àåì ñïèñîê ð¸áåð ãðàôà, ÷òîáû âûÿñíÿòü, êîãäà âåðøèíà i áóäåò êîíå÷íîé ó ðåáðà
		vector<pair<int, int>> pair = NewGraph.list_of_edges_pairs();
		int count = 0; // ïîäñ÷åò, ñêîëüêî ðàç âåðøèíà áûëà êîíå÷íîé

		// âû÷èñëÿåì DegIn
		for (int i = 0; i < NewGraph.adjacency_matrix().size(); i++)
		{
			// äëÿ êàæäîé âåðøèíû ñ÷¸ò÷èê çàïóñêàåòñÿ çàíîâî
			count = 0;
			// èäåì ïî âñåì ýëåìåíòàì âåêòîðà ïàð
			for (int j = 0; j < NewGraph.list_of_edges_pairs().size(); j++)
			{
				// åñëè âòîðûì ýëåìåíòîì ÿâëÿåòñÿ ðàññìàòðèâàåìàÿ âåðøèíà
				if (pair[j].second == i)
				{
					// óâåëè÷èâàåì ñ÷¸ò÷èê
					count = count + 1;
				}// if (pair[j].second == i)
			}// for j
			// ïîñëå ðàññìîòðåíèÿ î÷åðåäíîé âåðøèíû ïî ïîðÿäêó ïîìåùàåì å¸ â âåêòîð
			DegIn.push_back(count);
		}// for i

		// âûâîäèì íàêîïëåííûé âåêòîð
		cout << "\n  DegIn: [ ";
		for (int i = 0; i < DegIn.size(); i++)
		{
			cout << DegIn[i] << " ";
		}// for i

		cout << "]";
	}// // if (!NewGraph.is_directed())
 
	// àëãîðèòì Ôëîéäà-Óîðøåëëà
	// Èçíà÷àëüíî çà ìàòðèöó êðàò÷àéøèõ ïóòåé ïðèíèìàåì ìàòðèöó ñìåæíîñòè
	vector<vector<int>> shortWays = NewGraph.adjacency_matrix();
	// ïîñëå ïðèìåíåíèÿ àëãîðèòìà ïîëó÷àåì èòîãîâóþ ìàòðèöó êðàò÷àéøèõ ïóòåé, ñ êîòîðîé áóäåì ðàáîòàòü äàëåå
	shortWays = Floyd_Ourshell(shortWays);
	
	// ôëàã ïîäñ÷¸òà ýêñöåíòðèñèòåòà
	bool CountEccentricity = true;
	cout << endl << endl;
	cout << "\n\x1b[36m Ì À Ò Ð È Ö À   Ð À Ñ Ñ Ò Î ß Í È É   Ã Ð À Ô À :\x1b[30m\n";
	// âûâîäèì ìàòðèöó êðàò÷àéøèõ ðàññòîÿíèé íà ýêðàí
	PrintMatrix(shortWays);



	// Ýêñöåíòðèñèòåò - ìàêñèìàëüíûé ýëåìåíò â ñòðîêå ìàòðèöû êðàò÷àéøèõ ïóòåé
	int max = 0;                   // ïîèñê ìàêñèìóìà
	vector<int> Eccentricity;      // âåêòîð ýêñöåíòðèñèòåòîâ

	// èùåì ìàêñèììàëüíûé ýëåìåíò â î÷åðåäíîé ñòðîêå ìàòðèöû êðàò÷àéøèõ ïóòåé
	for (int i = 0; i < shortWays.size(); i++)
	{
		for (int j = 0; j < shortWays.size(); j++)
		{
			if (shortWays[i][j] > max)
			{
				max = shortWays[i][j];
			}// if (shortWays[i][j] > max)
		}// for j

		// åñëè îí - áåñêîíå÷íîñòü, òî ïîíÿòèå ýêñöåíòðèñèòåòà íå èìååò ñìûñëà
		if (max == INF)
		{
			// óáèðàåì ôëàã
			CountEccentricity = false;
		}
		// ïîìåùàåì íàéäåííûé ýêñöåíòðèñèòåò â âåêòîð
		Eccentricity.push_back(max);
		// î÷èùàåì ìàêñèìàëüíûé ýëåìåíò ñòðîêè
		max = 0;
	}// for i

	// Åñëè ïîíÿòèå ýêñöåíòðèñèòåòà èìååò ñìûñë - ôëàã true
	if (CountEccentricity)
	{
		// âûâîäèì âåêòîð íà ýêðàí
		cout << "\n\n\x1b[34m Ý Ê Ñ Ö Å Í Ò Ð È Ñ È Ò Å Ò Û :\x1b[30m\n";
		cout << "\n  Eccentricity: [ ";
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			cout << Eccentricity[i] << " ";;
		}// for i
		cout << "]\n";
	}// 	if (CountEccentricity)

	// ðàäèóñ è äèàìåòð. Èíèöèàëèçèðóåì ýëåìåíòîì âåêòîðà ýêñöåíòðèñèòåòîâ
	int Radius = Eccentricity[0];
	int Diameter = Eccentricity[0];

	vector<int> Central_Vertices;
	vector<int> Peripheral_Vertices;

	// ðàáîòàåì ñ íåîðèåíòèðîâàííûìè ãðàôàìè. Âñå ïîíÿòèÿ íèæå â äàííîé ðàáîòå èìåþò ñìûñë òîëüêî äëÿ íèõ
	// èùåì ìèíèìàëüíûé ýêñöåíòðèñèòåò â âåêòîðå - ýòî è áóäåò ðàäèóñ ãðàôà
	// èùåì ìàêñèìàëüíûé ýêñöåíòðèñèòåò â âåêòîðå - ýòî è áóäåò äèàìåòð ãðàôà
	if (!NewGraph.is_directed())
	{
		// èä¸ì ïî âñåì ýëåìåíòàì âåêòîðà ýêñöåíòðèñèòåòîâ
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

		// Åñëè êàêîå-òî èç çíà÷åíèé: ðàäèóñ èëè äèàìåòð - áåñêîíå÷íîñòü. Èõ ïîíÿòèå â ãðàôå íå èìååò ñìûñëà
		// èíà÷å - âûâîäèì èõ íà ýêðàí
		if (Radius != INF && Diameter != INF)
		{
			cout << "\n\n\x1b[35m Ä È À Ì Å Ò Ð   È   Ð À Ä È Ó Ñ   Ã Ð À Ô À :\x1b[30m\n";
			cout << "  Graph radius: " << Radius << endl;
			cout << "  Graph diameter: " << Diameter << endl;
		}//if (Radius != INF && Diameter != INF)

		// öåíòðàëüíûå è ïåðèôåðèéíûå âåðøèíû
		// íîìåðà âåðøèí íà÷èíàþòñÿ ñ 1 -> ê êàæäîìó íîìåðó ïðèáàâëÿåì 1
		for (int i = 0; i < Eccentricity.size(); i++)
		{
			// Âûáèðàåì âåðøèíû, ó êîòîðûõ ýêñöåíòðèñèòåò ðàâåí ðàäèóñó - öåíòðàëüíûå âåðøèíû
			if (Radius == Eccentricity[i] && Radius != INF)
			{
				// ïîìåùàåì â âåêòîð î÷åðåäíóþ âåðøèíó
				Central_Vertices.push_back(i + 1);
			}// if (Radius == Eccentricity[i] && Radius != INF)

			// Âûáèðàåì âåðøèíû, ó êîòîðûõ ýêñöåíòðèñèòåò ðàâåí äèàìåòðó - ïåðåôåðèéíûå âåðøèíû
			if (Diameter == Eccentricity[i] && Diameter != INF)
			{
				// ïîìåùàåì â âåêòîð î÷åðåäíóþ âåðøèíó
				Peripheral_Vertices.push_back(i + 1);
			}// if (Diameter == Eccentricity[i] && Diameter != INF)
		}// for i

		//// Åñëè êàêîå-òî èç çíà÷åíèé: ðàäèóñ èëè äèàìåòð - áåñêîíå÷íîñòü. Òîãäà ïîíÿòèå öåíòðàëüíûõ è ïåðåôåðèéíûõ âåðøèí íå èìååò ñìûñëà
		// èíà÷å - âûâîäèì èõ íà ýêðàí
		if (Radius != INF && Diameter != INF)
		{
			// âûâîäèì çíà÷åíèÿ íà ýêðàí è â ôàéë
			cout << "\n\n\x1b[33m Ì Í Î Æ Å Ñ Ò Â À   Ö Å Í Ò Ð À Ë Ü Í Û Õ   È   Ï Å Ð È Ô Å Ð È É Í Û Õ   Â Å Ð Ø È Í :\x1b[30m\n";
			cout << "  Central_Vertices: [ ";
			// âûâîäèì âñå öåíòðàëüíûå âåðøèíû
			for (int i = 0; i < Central_Vertices.size(); i++)
			{
				cout << Central_Vertices[i] << " ";
			}// for i
			cout << "]\n";


			cout << "  Peripheral_Vertices: [ ";
			// âûâîäèì âñå ïåðåôåðèéíûå âåðøèíû
			for (int i = 0; i < Peripheral_Vertices.size(); i++)
			{
				cout << Peripheral_Vertices[i] << " ";
			}// for i
			cout << "]\n";
		}// if (Radius != INF && Diameter != INF)
	}// if (!NewGraph.is_directed())

	// ïîëüçîâàòåëü çàõîòåë ïå÷àòàòü èíôîðìàöèþ â ôàéë
	if (print)
	{
		fout.open(FNAMEOUT);           // ñâÿçûâàåì îáúåêò ñ ôàéëîì
		if (!fout.is_open())           // ôàéë íå íàéäåí
		{
			cout << "Ôàéëà ñ òàêèì èìåíåì íåò. Íåâîçìîæíî îñóùåñòâèòü ÷òåíèå";
			fin.close();               // çàêðûòü ôàéë äëÿ ÷òåíèÿ
			system("pause");
			exit(0);                   // âîçâðàùàåì çíà÷åíèå, ñîîòâåòñòâóþùåå òèïó â caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    Ð À Á Î Ò À   Ñ   Ã Ð À Ô À Ì È\n\n\n";
		fout << "\n\n Ì À Ò Ð È Ö À   Ñ Ì Å Æ Í Î Ñ Ò È   Ï Î   È Ñ Õ Î Ä Í Û Ì   Ä À Í Í Û Ì :\n\n";
		// âûâîäèì ìàòðèöó ñìåæíîñòè â ôàéë
		PrintMatrToFile(NewGraph.adjacency_matrix());
		// âûâîäèì ñòåïåíè âåðøèí â ôàéë
		PrintDegrees(NewGraph, Degrees, DegIn, DegOut);
		fout << "\n Ì À Ò Ð È Ö À   Ð À Ñ Ñ Ò Î ß Í È É   Ã Ð À Ô À :\n\n";
		// âûâîäèì ìàòðèöó êðàò÷àéøèõ ïóòåé â ôàéë
		PrintMatrToFile(shortWays);
		// îñòàëüíûå âûâîäû, íåîáõîäèìûå ïî çàäàíèþ, â ôàéë
		PrintOthers(NewGraph, Eccentricity, CountEccentricity, Radius, Diameter, Central_Vertices, Peripheral_Vertices);

		// çàêðûâàåì ôàéë äëÿ âûâîäà
		fout.close();
	}// if (print)

	// Âûâîäèì êàðòèíêó ñ ãðàôîì íà ýêðàí
	OpenImage(NewGraph.adjacency_matrix());

	// âîçâðàùàåì îáåùàííîå çíà÷åíèå â ôóíêöèþ
	return 0;
}
