
#include "Optimizer.h"

// »ý¼ºÀÚ

Optimizer::Optimizer(DataManager* dm, IloEnv& env)
{

	cout << "------------------------- Optimizer Starts ------------------------- " << endl;

	env_ = env;

	log_ = dm->GetLogOut();

	optimizerData_ = dm;
}

bool Optimizer::PreProcessing()
{

}
