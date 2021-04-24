#pragma once

//--------------------------------------------------------------------------------------------------------------

// �ҽ����� : ������ ����ȭ (LP, MIP, MILP, Pattern Generation) �𵨸��� ���� Opitimizer ��ü�Դϴ�.
// �� ��ó��, �� ����ȭ (�ͺ������� �� �ʱ�ȭ, �θ��� �� ������� �ο�, �Ϲ���Ǯ��, ����ó��, �������� ���)

// �ش��ڵ��� Naming rule�� Google C++ Style Guide�� �����Ͽ����ϴ�.
// �ش�ҽ� �ڵ��� �ǵ���� whcl303@hanmail.net���� ��Ź�帳�ϴ�:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"
#include "DataManager.h"

class Optimizer
{

	// �ɹ�����
private:

	// CPELX ����
	IloEnv env_;
	IloModel model_;

	// DataManager ��ü ����
	DataManager* optimizer_data_;

	// Log ����
	fstream* log_;

	// �����Լ�
	IloObjective objective_;

	// �������� ( LP/MIP �� ����ȭ ���� ������ ���� ������ Type ���� ) 
	IloArray<IloBoolVarArray> matrixVar_;

public:

	// ������
	Optimizer(DataManager* dm, IloEnv& env);
	~Optimizer();

	// Getter �Լ�
	DataManager* GetDataManager();

	// �ɹ� �Լ�

	// ��ó��
	bool PreProcessing();

	// ����ȭ
	bool Optimizing();

	// ���� ����
	bool MakingVar();

	// �����Լ� ����
	bool MakingObj();

	// �������� ����
	bool MakingConstraint();

	// ����Ǯ��
	bool SolveModel();

	// ��ó��
	bool PostProcessing();

	// ������ ���
	bool PrintSolution();

};