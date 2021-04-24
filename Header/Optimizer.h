#pragma once

//--------------------------------------------------------------------------------------------------------------

// 소스설명 : 수학적 최적화 (LP, MIP, MILP, Pattern Generation) 모델링을 위한 Opitimizer 객체입니다.
// ① 전처리, ② 최적화 (ⓐ변수선언 및 초기화, ⓑ목적 및 제약사항 부여, ⓒ문제풀이, ⓓ후처리, ⓔ최적해 출력)

// 해당코드의 Naming rule은 Google C++ Style Guide를 참조하였습니다.
// 해당소스 코드의 피드백은 whcl303@hanmail.net으로 부탁드립니다:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"
#include "DataManager.h"

class Optimizer
{

	// 맴버변수
private:

	// CPELX 변수
	IloEnv env_;
	IloModel model_;

	// DataManager 객체 저장
	DataManager* optimizer_data_;

	// Log 관리
	fstream* log_;

	// 목적함수
	IloObjective objective_;

	// 결정변수 ( LP/MIP 등 최적화 문제 종류에 따라 적합한 Type 선택 ) 
	IloArray<IloBoolVarArray> matrixVar_;

public:

	// 생성자
	Optimizer(DataManager* dm, IloEnv& env);
	~Optimizer();

	// Getter 함수
	DataManager* GetDataManager();

	// 맴버 함수

	// 전처리
	bool PreProcessing();

	// 최적화
	bool Optimizing();

	// 변수 생성
	bool MakingVar();

	// 목적함수 생성
	bool MakingObj();

	// 제약조건 생성
	bool MakingConstraint();

	// 문제풀이
	bool SolveModel();

	// 후처리
	bool PostProcessing();

	// 최적해 출력
	bool PrintSolution();

};