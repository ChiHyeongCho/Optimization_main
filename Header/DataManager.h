
//--------------------------------------------------------------------------------------------------------------

// �ҽ����� : ������ ����ȭ (LP, MIP, MILP, Pattern Generation) �𵨸��� ���� DataManger �Լ� �����Դϴ�.
// Input ������ ��  Vector / Map �ڷᱸ�� ��ȯ

// �ش��ڵ��� Naming rule�� Google C++ Style Guide�� �����Ͽ����ϴ�.
// �ش�ҽ� �ڵ��� �ǵ���� whcl303@hanmail.net���� ��Ź�帳�ϴ�:)

//--------------------------------------------------------------------------------------------------------------

#include "Global.h"

class DataManager {

	// �ɹ�����
private:

	// CPELX ����
	IloEnv env_;

	// ���
	string dir_;

	// �α�����
	fstream* log_;

	// Input Data �� Vector / Map �ڷᱸ�� ��ȯ
	vector<Input*> inputs_;
	map<string, Input*>inputMap_;

public:

	// ������
	DataManager(IloEnv& env, string& dir);
	~DataManager();

	// �α� �� ��� Getter �Լ�
	fstream* GetLogOut() const;
	string GetDir() const;

	// Input Getter �Լ�
	Input* GetInput(int i) const;
	Input* GetInput(string key) const;
	int GetSizeInput() const;

	// Data read �Լ� (read �����Ͱ� ���� �� �߰� ����)
	bool ReadData(string& argvInput);
	bool ReadInput(string& data);
};