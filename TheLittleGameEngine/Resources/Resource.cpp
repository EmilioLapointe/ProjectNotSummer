#include "EnginePCH.h"

using namespace std;

namespace TLGE
{
	std::map<string, Resource*> Resource::m_resourceDB;

	Resource::Resource()
	{
		//nothing to do
	}
	Resource::~Resource()
	{
		//nothing to do
	}

	void Resource::LoadAllResources()
	{
		for (map<string, Resource*>::iterator it = m_resourceDB.begin(); it != m_resourceDB.end(); it++)
		{
			it->second->Load();
		}
	}

	Resource* Resource::GetResource(char* &identifier)
	{
		if (m_resourceDB.find(identifier) != m_resourceDB.end())
		{
			return m_resourceDB.find(identifier)->second;
		}
		return nullptr;
	}
	void Resource::AddResource(char* &identifier, Resource* resource)
	{
		m_resourceDB[identifier] = resource;
	}
}