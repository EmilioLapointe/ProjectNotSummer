#ifndef __TLGE__RESOURCE_H__
#define __TLGE__RESOURCE_H__

namespace TLGE
{
	/**************************************************************************
	* Resource is an interface for all loaded resources                      *
	*                                                                         *
	* Important notes:                                                        *
	*	-Resource is an abstract class and cannot be instantiated            *
	***************************************************************************/
	class Resource
	{
	public:
		Resource();
		virtual ~Resource();

		virtual void Load() = 0;

		static void LoadAllResources();

	protected:
		char* m_identifier;

		static Resource* GetResource(char* &identifier);
		static void AddResource(char* &identifier, Resource* resource);

	private:
		static std::map<std::string, Resource*> m_resourceDB;
	};
}

#endif