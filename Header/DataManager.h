
//--------------------------------------------------------------------------------------------------------------

// 소스설명 : 수학적 최적화 (LP, MIP, MILP, Pattern Generation) 모델링을 위한 DataManger 함수 구조입니다.
// Input 데이터 →  Vector / Map 자료구조 변환

// 해당코드의 Naming rule은 Google C++ Style Guide를 참조하였습니다.
// 해당소스 코드의 피드백은 whcl303@hanmail.net으로 부탁드립니다:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"

class DataManager {

	// 맴버변수
private:

	// CPELX 변수
	IloEnv env_;

	// 경로
	string dir_;

	// 로그파일
	fstream* log_;

	// Input Data → Vector / Map 자료구조 변환
	vector<Input*> inputs_;
	map<string, Input*>inputMap_;

public:

	// 생성자
	DataManager(IloEnv& env, string& dir);
	~DataManager();

	// 로그 및 경로 Getter 함수
	fstream* GetLogOut() const;
	string GetDir() const;

	// Input Getter 함수
	Input* GetInput(int i) const;
	Input* GetInput(string key) const;
	int GetSizeInput() const;

	// Data read 함수 (read 데이터가 많을 시 추가 생성)
	bool ReadData(string& argvInput);
	bool ReadInput(string& data);
};