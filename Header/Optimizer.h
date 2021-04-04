#pragma once

//--------------------------------------------------------------------------------------------------------------

// 소스설명 : 수학적 최적화 (LP, MIP, MILP, Pattern Generation) 모델링을 위한 Opitimizer 객체입니다.
// ① 전처리, ② 최적화 (ⓐ변수선언 및 초기화, ⓑ목적 및 제약사항 부여, ⓒ문제풀이, ⓓ후처리, ⓔ최적해 출력)

// 해당코드의 Naming rule은 Google C++ Style Guide를 참조하였습니다.
// 해당소스 코드의 피드백은 whcl303@hanmail.net으로 부탁드립니다:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"

class Opitimizer
{

	// 맴버함수
private:

	// CPELX 변수
	IloEnv env_;
	IloModel model_;

	// 목적함수
	IloObjective objective;

	// 결정변수 ( LP/MIP 등 최적화 문제 종류에 따라 적합한 Type 선택 ) 
	IloArray<IloBoolVarArray> matrixVar_;

public:

	// 생성자
	Opitimizer(DataManager* dm, IloEnv& env);
	~Opitimizer();

	// Getter 함수
	DataManager* GetDataManager();


	// 맴버 함수

	// 전처리
	bool PreProcessing();

	// 최적화
	bool Optimizing();

	// 변수선언 및 초기화
	bool Initializing();

	// 목적함수 및 제약조건 설정
	bool CreateModel();

	// 문제풀이
	bool SolveModel();

	// 후처리
	bool PostProcessing();

	// 최적해 출력
	bool PrintSolution();

};