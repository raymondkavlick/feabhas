#include "step.h"
#include "Wash.h"


Wash::Wash(std::array<Step *,8> steplist) :
    steps { steplist}
{
    


}

void Wash::operate()
{

    for(auto &elem : steps)
    {
        if(elem)
            elem->run();

    }

}