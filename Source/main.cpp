
//--------------------------------------------------------------------------------------------------------------

// �ҽ����� : ������ ����ȭ (LP, MIP, MILP, Pattern Generation) �𵨸��� ���� Main �Լ� �����Դϴ�.
// CPLEX (����ȭ Tool) ����, ���α׷� ���� �ð� ��� / ���� ��ġ, ������ ����, ����ȭ�� ����

// �ش��ڵ��� Naming rule�� Google C++ Style Guide�� �����Ͽ����ϴ�.
// �ش�ҽ� �ڵ��� �ǵ���� whcl303@hanmail.net���� ��Ź�帳�ϴ�:)

//--------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include "Global.h"

using namespace std;

int main(int argc, char* argv[]) // argc : ���ڼ�,  argv : �ش���/���ϸ�
{

	// ���α׷� ���۽ð� üũ
	clock_t start_time = clock();

	// Preparations : arguments ���� ���� (directory ��) �� Cplex ȯ�漳��

	IloEnv env;
	string directory;
	string argvOne = directory + "example.csv";

	// Frist : Read data from the directory -> DataManager ��ü


	DataManager* dm = new DataManager(env, directory);
	dm->ReadData(argvOne);

	// Second : Optimize Problem -> Optimizer ��ü

	Optimizer* opt = new Optimizer(dm, env);
	opt->PreProcessing();
	opt->Optimizing();
	opt->PostProcessing();
	opt->PrintSolution();

	// Thrid : Delete object
	env.end();
	delete dm;
	delete opt;

	// ���α׷� ����ð� üũ
	clock_t end_time = clock();

	// ���α׷� ����ð� ���
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "Total sloving time : " << execution_time << endl;

	return 0;
}