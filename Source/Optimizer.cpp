
#include "Optimizer.h"

// ������

Optimizer::Optimizer(DataManager* dm, IloEnv& env)
{

	cout << "------------------------- Optimizer Starts ------------------------- " << endl;

	env_ = env;

	log_ = dm->GetLogOut();

	optimizerData_ = dm;
}


// ����Լ�


// ������ ��ó��
bool Optimizer::PreProcessing()
{
	try
	{
		cout << "--PreProcessing Starts.. " << endl;

		int i, j, k;

		// ������ �ҷ�����


		// ������ ��ȯ

	}
	catch (...)
	{
		cout << "**** Error -> Optimizer PreProcessing" << endl;
	}

}

// ����ȭ ( MakingVar, MakingObj, MakingConstraint, SolveModel )
bool Optimizer::Optimizing()
{
	cout << "--Optimizing Starts.. " << endl;

	try
	{
		// ����ȭ ���� �������� �� �ʱ�ȭ
		this->MakingVar();

		// �����Լ� ����
		this->MakingObj();

		// �������� ����
		this->MakingConstraint();

		// ���� Ǯ��
		this->SolveModel();

	}
	catch (...)
	{
		cout << "**** Error -> Optimizing PreProcessing" << endl;
	}
}

// �� �� ���� ����
bool Optimizer::MakingVar()
{
	cout << "-- Making Variables.. " << endl;

	try
	{
		// ��뺯�� ���� (���� : mathematical modeling ��� ���)
		int i, j, k;

		int input_row_size;
		int input_column_size;

		float var_min;
		float var_max;

		// �� ����
		model_ = IloModel(env_);

		// ���� ����
		matrixVar_ = IloArray<IloBoolVarArray>(env_, input_row_size);

		for (i = 0; i < input_row_size; i++)
		{
			matrixVar_[i] = IloBoolVarArray(env_, input_column_size);

			for (j = 0; j < input_column_size; j++)
			{
				string input_name;

				matrixVar_[i][j] = IloNumVar(env_, var_min, var_max, ILOINT, input_name.c_str());
			}
		}
	}
	catch (...)
	{
		cout << "**** Error -> Making Variables" << endl;
	}
}

// �����Լ� ����
bool Optimizer::MakingObj()
{
	cout << "-- Making objectives.. " << endl;

	try
	{
		// ��뺯�� ���� (���� : mathematical modeling ��� ���)
		int i, j, k;

		// �����Լ� ����
		IloExpr total_cost(env_);

		// �����Լ� ���� (�ٸ��� �Լ�)
		IloExpr obj_max_one(env_);
		IloExpr obj_max_two(env_);

		// �����Լ� ����ġ
		float obj_max_one_weight;
		float obj_max_two_weight;

		total_cost = obj_max_one * obj_max_one_weight
			+ obj_max_two * obj_max_two_weight;

		objective_ = IloMaximize(env_, total_cost);
		model_.add(objective_);
	}
	catch (...)
	{
		cout << "**** Error -> Making objectives" << endl;
	}
}

// �������� ����
bool Optimizer::MakingConstraint()
{
	cout << "-- Making Constraint.. " << endl;

	try
	{
		// ��뺯�� ���� (���� : mathematical modeling ��� ���)
		int i, j, k;

		// �������� ����
		IloConstraint constraint_one;
		string constraint_one_name;
		constraint_one.setName(constraint_one_name.c_str());

		IloConstraint constraint_two;
		string constraint_two_name;
		constraint_two.setName(constraint_two_name.c_str());

		// �������� �ο�

		model_.add(constraint_one);
		model_.add(constraint_two);
	}
	catch (...)
	{
		cout << "**** Error ->  Making Constraint" << endl;
	}
}

// ����Ǯ��
bool Optimizer::SolveModel()
{
	cout << "-- Solve Model.. " << endl;

	try
	{
		// ��뺯�� ���� 
		int i, j, k;

		string model_name = optimizer_data_->GetDir() + "model.lp";

		ilocplex



	}
	catch (...)
	{
		cout << "**** Error -> Solve Model" << endl;
	}
}

// ��ó��
bool Optimizer::PostProcessing()
{

}

// ������ ���
bool Optimizer::PrintSolution()
{

}