#include "AllZone.h"
#include "Net.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	int testCase = 4;
	/*
	AllZone allZone(testCase);
	allZone.getBlock("BLOCK_1").showBlockInfo();
	allZone.getRegion("REGION_64").showRegionInfo();
	*/

	Net Nets;
	Nets.ParserAllNets(testCase);
	Nets.allNets[3].showNetInfo();
}

// cd "c:\Users\照元喔\source\repos\Problem_D\" ; if ($?) { g++ main.cpp AllZone.cpp Block.cpp Net.cpp Region.cpp -o main} ; if ($?) { .\main }