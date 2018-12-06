#include "Token.h"
using namespace TLGE;

	Token::Token(GameObject* aObjectInCharge):
		Component(aObjectInCharge)
	{

	}
	Token::~Token()
	{
		//nothing to do
	}
	
	void Token::Initialize(int type, bool disabeled)
	{
		m_tokenType = type;
		m_disabeled = disabeled;
	}
	void Token::SetType(int argument)
	{
		m_tokenType = argument;
	}
	void Token::SetDisabled(int argument)
	{
		m_disabeled = argument != 0;
	}
	int Token::GetType()
	{
		return m_tokenType;
	}
	int Token::GetDisabled()
	{
		return m_disabeled;
	}
	void Token::Update(float adeltatime)
	{

	}