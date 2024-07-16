


#include "BasicAISystemThings/TokenSystemComponent.h"


bool UTokenSystemComponent::TookToken(int amount)
{
	if(currentToken >= amount)
	{
		currentToken -= amount;
		return true;
	}
	else
	{
		return false;
	}
}

void UTokenSystemComponent::GiveToken(int amount)
{
	currentToken += amount;
}
