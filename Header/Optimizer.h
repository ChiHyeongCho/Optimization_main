#pragma once

//--------------------------------------------------------------------------------------------------------------

// �ҽ����� : ������ ����ȭ (LP, MIP, MILP, Pattern Generation) �𵨸��� ���� Opitimizer ��ü�Դϴ�.
// �� ��ó��, �� ����ȭ (�ͺ������� �� �ʱ�ȭ, �θ��� �� ������� �ο�, �Ϲ���Ǯ��, ����ó��, �������� ���)

// �ش��ڵ��� Naming rule�� Google C++ Style Guide�� �����Ͽ����ϴ�.
// �ش�ҽ� �ڵ��� �ǵ���� whcl303@hanmail.net���� ��Ź�帳�ϴ�:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"

class Opitimizer
{

	// �ɹ��Լ�
private:

	// CPELX ����
	IloEnv env_;
	IloModel model_;

	// �����Լ�
	IloObjective objective;

	// �������� ( LP/MIP �� ����ȭ ���� ������ ���� ������ Type ���� ) 
	IloArray<IloBoolVarArray> matrixVar_;

public:

	// ������
	Opitimizer(DataManager* dm, IloEnv& env);
	~Opitimizer();

	// Getter �Լ�
	DataManager* GetDataManager();


	// �ɹ� �Լ�

	// ��ó��
	bool PreProcessing();

	// ����ȭ
	bool Optimizing();

	// �������� �� �ʱ�ȭ
	bool Initializing();

	// �����Լ� �� �������� ����
	bool CreateModel();

	// ����Ǯ��
	bool SolveModel();

	// ��ó��
	bool PostProcessing();

	// ������ ���
	bool PrintSolution();

};