#ifndef __TLGE_TWEEN_H__
#define __TLGE_TWEEN_H__

typedef float(*TweenFunction)(float startvalue, float valuerange, double timepassed, double totaltime);

typedef void(*TweenOverCallback)(void);

namespace TLGE
{

	class Tween
	{
	public:
		~Tween();

		static Tween* NewTween(Scene* owner, float* tweenedValue, float startValue, float endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback = NULL);
		static Tween* NewTween(Scene* owner, glm::vec2* tweenedValue, glm::vec2 startValue, glm::vec2 endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback = NULL);
		static Tween* NewTween(Scene* owner, glm::vec3* tweenedValue, glm::vec3 startValue, glm::vec3 endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback = NULL);

		static void Update(Scene* scene, float deltaTime);
	private:
		enum TweenType
		{
			TweenType_float,
			TweenType_vec2,
			TweenType_vec3,
			NumTweenTypes,
			TweenType_Invalid
		};

		Tween(Scene* owner, float* tweenedValue, float startValue, float endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback);
		Tween(Scene* owner, glm::vec2* tweenedValue, glm::vec2 startValue, glm::vec2 endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback);
		Tween(Scene* owner, glm::vec3* tweenedValue, glm::vec3 startValue, glm::vec3 endValue, float totalTime, TweenFunction tweenFunction, TweenOverCallback callback);

		static std::vector<Tween*> m_liveTweens;

		float* m_pTweenedValueFloat;
		glm::vec2* m_pTweenedValueVec2;
		glm::vec3* m_pTweenedValueVec3;

		float m_startValueFloat;
		glm::vec2 m_startValueVec2;
		glm::vec3 m_startValueVec3;

		float m_valueRangeFloat;
		glm::vec2 m_valueRangeVec2;
		glm::vec3 m_valueRangeVec3;

		float m_timePassed;
		float m_totalTime;
		TweenFunction m_tweenFunction;
		Scene* m_pOwner;

		TweenType m_type;
		TweenOverCallback m_callback;
	};
}

#endif