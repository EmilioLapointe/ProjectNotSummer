#include "EnginePCH.h"

namespace TLGE
{
	std::vector<Tween*> Tween::m_liveTweens;

	Tween::Tween(Scene* apOwner, float* apTweenedValue, float aStartValue, float aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback):
		m_pTweenedValueFloat(apTweenedValue),
		m_startValueFloat(aStartValue),
		m_valueRangeFloat(aEndValue - aStartValue),
		m_timePassed(0.0f),
		m_totalTime(aTotalTime),
		m_tweenFunction(aTweenFunction),
		m_pOwner(apOwner),
		m_type(TweenType_float),
		m_callback(aCallback)
	{
		//nothing to do
	}

	Tween::Tween(Scene* apOwner, glm::vec2* apTweenedValue, glm::vec2 aStartValue, glm::vec2 aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback) :
		m_pTweenedValueVec2(apTweenedValue),
		m_startValueVec2(aStartValue),
		m_valueRangeVec2(aEndValue - aStartValue),
		m_timePassed(0.0f),
		m_totalTime(aTotalTime),
		m_tweenFunction(aTweenFunction),
		m_pOwner(apOwner),
		m_type(TweenType_vec2),
		m_callback(aCallback)
	{
		//nothing to do
	}
	Tween::Tween(Scene* apOwner, glm::vec3* apTweenedValue, glm::vec3 aStartValue, glm::vec3 aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback) :
		m_pTweenedValueVec3(apTweenedValue),
		m_startValueVec3(aStartValue),
		m_valueRangeVec3(aEndValue - aStartValue),
		m_timePassed(0.0f),
		m_totalTime(aTotalTime),
		m_tweenFunction(aTweenFunction),
		m_pOwner(apOwner),
		m_type(TweenType_vec3),
		m_callback(aCallback)
	{
		//nothing to do
	}
	Tween::~Tween()
	{
		//nothing to do
	}

	Tween* Tween::NewTween(Scene* apOwner, float* apTweenedValue, float aStartValue, float aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback)
	{
		Tween* newTween = new Tween(apOwner, apTweenedValue, aStartValue, aEndValue, aTotalTime, aTweenFunction, aCallback);
		m_liveTweens.push_back(newTween);
		return newTween;
	}
	Tween* Tween::NewTween(Scene* apOwner, glm::vec2* apTweenedValue, glm::vec2 aStartValue, glm::vec2 aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback)
	{
		Tween* newTween = new Tween(apOwner, apTweenedValue, aStartValue, aEndValue, aTotalTime, aTweenFunction, aCallback);
		m_liveTweens.push_back(newTween);
		return newTween;
	}
	Tween* Tween::NewTween(Scene* apOwner, glm::vec3* apTweenedValue, glm::vec3 aStartValue, glm::vec3 aEndValue, float aTotalTime, TweenFunction aTweenFunction, TweenOverCallback aCallback)
	{
		Tween* newTween = new Tween(apOwner, apTweenedValue, aStartValue, aEndValue, aTotalTime, aTweenFunction, aCallback);
		m_liveTweens.push_back(newTween);
		return newTween;
	}

	void Tween::Update(Scene* aScene, float deltaTime)
	{
		for (std::vector<Tween*>::iterator it = m_liveTweens.begin(); it != m_liveTweens.end();)
		{
			if (aScene == (*it)->m_pOwner)
			{
				(*it)->m_timePassed += deltaTime;

				switch ((*it)->m_type)
				{
				case TweenType_float:
					*((*it)->m_pTweenedValueFloat) = (*it)->m_tweenFunction((*it)->m_startValueFloat, (*it)->m_valueRangeFloat, (*it)->m_timePassed, (*it)->m_totalTime);
					break;
				case TweenType_vec2:
					(*(*it)->m_pTweenedValueVec2).x = (*it)->m_tweenFunction((*it)->m_startValueVec2.x, (*it)->m_valueRangeVec2.x, (*it)->m_timePassed, (*it)->m_totalTime);
					(*(*it)->m_pTweenedValueVec2).y = (*it)->m_tweenFunction((*it)->m_startValueVec2.y, (*it)->m_valueRangeVec2.y, (*it)->m_timePassed, (*it)->m_totalTime);
					break;
				case TweenType_vec3:
					(*(*it)->m_pTweenedValueVec3).x = (*it)->m_tweenFunction((*it)->m_startValueVec3.x, (*it)->m_valueRangeVec3.x, (*it)->m_timePassed, (*it)->m_totalTime);
					(*(*it)->m_pTweenedValueVec3).y = (*it)->m_tweenFunction((*it)->m_startValueVec3.y, (*it)->m_valueRangeVec3.y, (*it)->m_timePassed, (*it)->m_totalTime);
					(*(*it)->m_pTweenedValueVec3).z = (*it)->m_tweenFunction((*it)->m_startValueVec3.z, (*it)->m_valueRangeVec3.z, (*it)->m_timePassed, (*it)->m_totalTime);
					break;
				default:
					break;
				}

				if ((*it)->m_timePassed >= (*it)->m_totalTime)
				{
					if ((*it)->m_callback != NULL)
					{
						(*it)->m_callback();
					}
					delete *it;
					it = m_liveTweens.erase(it);
				}
				else
				{
					it++;
				}
			}
			else
			{
				it++;
			}
		}
	}
}