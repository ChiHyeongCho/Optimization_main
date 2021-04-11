
#include "DataManager.h"

// ������

DataManger::DataManger(IloEnv& env, string& dir)
{

	env_ = env;
	dir_ = dir;

	string logDirectory = dir_ + "LogFile.csv";
	log_ = new fstream(logDirectory.c_str(), ios::out);

	inputs_.clear();
	inputMap_.clear();

};

DataManger::~DataManger()