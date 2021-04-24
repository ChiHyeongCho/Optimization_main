
#include "Optimizer.h"

// 생성자

Optimizer::Optimizer(DataManager* dm, IloEnv& env)
{

	cout << "------------------------- Optimizer Starts ------------------------- " << endl;

	env_ = env;

	log_ = dm->GetLogOut();

	optimizerData_ = dm;
}


// 멤버함수


// 데이터 전처리
bool Optimizer::PreProcessing()
{
	try
	{
		cout << "--PreProcessing Starts.. " << endl;

		int i, j, k;

		// 데이터 불러오기


		// 데이터 변환

	}
	catch (...)
	{
		cout << "**** Error -> Optimizer PreProcessing" << endl;
	}

}

// 최적화 ( MakingVar, MakingObj, MakingConstraint, SolveModel )
bool Optimizer::Optimizing()
{
	cout << "--Optimizing Starts.. " << endl;

	try
	{
		// 최적화 문제 변수선언 및 초기화
		this->MakingVar();

		// 목적함수 생성
		this->MakingObj();

		// 제약조건 생성
		this->MakingConstraint();

		// 문제 풀이
		this->SolveModel();

	}
	catch (...)
	{
		cout << "**** Error -> Optimizing PreProcessing" << endl;
	}
}

// 모델 및 변수 생성
bool Optimizer::MakingVar()
{
	cout << "-- Making Variables.. " << endl;

	try
	{
		// 사용변수 선언 (참고 : mathematical modeling 결과 사용)
		int i, j, k;

		int input_row_size;
		int input_column_size;

		float var_min;
		float var_max;

		// 모델 생성
		model_ = IloModel(env_);

		// 변수 생성
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

// 목적함수 생성
bool Optimizer::MakingObj()
{
	cout << "-- Making objectives.. " << endl;

	try
	{
		// 사용변수 선언 (참고 : mathematical modeling 결과 사용)
		int i, j, k;

		// 목적함수 생성
		IloExpr total_cost(env_);

		// 목적함수 생성 (다목적 함수)
		IloExpr obj_max_one(env_);
		IloExpr obj_max_two(env_);

		// 목적함수 가중치
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

// 제약조건 생성
bool Optimizer::MakingConstraint()
{
	cout << "-- Making Constraint.. " << endl;

	try
	{
		// 사용변수 선언 (참고 : mathematical modeling 결과 사용)
		int i, j, k;

		// 제약조건 생성
		IloConstraint constraint_one;
		string constraint_one_name;
		constraint_one.setName(constraint_one_name.c_str());

		IloConstraint constraint_two;
		string constraint_two_name;
		constraint_two.setName(constraint_two_name.c_str());

		// 제약조건 부여

		model_.add(constraint_one);
		model_.add(constraint_two);
	}
	catch (...)
	{
		cout << "**** Error ->  Making Constraint" << endl;
	}
}

// 문제풀이
bool Optimizer::SolveModel()
{
	cout << "-- Solve Model.. " << endl;

	try
	{
		// 사용변수 선언 
		int i, j, k;

		string model_name = optimizer_data_->GetDir() + "model.lp";

		ilocplex



	}
	catch (...)
	{
		cout << "**** Error -> Solve Model" << endl;
	}
}

// 후처리
bool Optimizer::PostProcessing()
{

}

// 최적해 출력
bool Optimizer::PrintSolution()
{

}