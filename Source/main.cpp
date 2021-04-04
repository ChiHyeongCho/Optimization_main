
//--------------------------------------------------------------------------------------------------------------

// 소스설명 : 수학적 최적화 (LP, MIP, MILP, Pattern Generation) 모델링을 위한 Main 함수 구조입니다.
// CPLEX (최적화 Tool) 연동, 프로그램 실행 시간 출력 / 실행 위치, 데이터 관리, 최적화로 구성

// 해당코드의 Naming rule은 Google C++ Style Guide를 참조하였습니다.
// 해당소스 코드의 피드백은 whcl303@hanmail.net으로 부탁드립니다:)

//--------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include "Global.h"

using namespace std;

int main(int argc, char* argv[]) // argc : 인자수,  argv : 해당경로/파일명
{

	// 프로그램 시작시간 체크
	clock_t start_time = clock();

	// Preparations : arguments 변수 정의 (directory 등) 및 Cplex 환경설정

	IloEnv env;
	string directory;
	string argvOne = directory + "example.csv";

	// Frist : Read data from the directory -> DataManager 객체


	DataManager* dm = new DataManager(env, directory);
	dm->ReadData(argvOne);

	// Second : Optimize Problem -> Optimizer 객체

	Optimizer* opt = new Optimizer(dm, env);
	opt->PreProcessing();
	opt->Optimizing();
	opt->PostProcessing();
	opt->PrintSolution();

	// Thrid : Delete object
	env.end();
	delete dm;
	delete opt;

	// 프로그램 종료시간 체크
	clock_t end_time = clock();

	// 프로그램 실행시간 출력
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "Total sloving time : " << execution_time << endl;

	return 0;
}