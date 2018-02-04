#pragma once
#include <unordered_map>
#include <deque>
#include <string>

namespace NCommon
{
	enum class ERROR_CODE :short;
}
using ERROR_CODE = NCommon::ERROR_CODE;

namespace NLogicLib
{	
	class User;

	class UserManager
	{
	public:
		UserManager();
		virtual ~UserManager();

		void Init(const int maxUserCount);

		ERROR_CODE AddUser(const int sessionIndex, const char* pszID);
		ERROR_CODE RemoveUser(const int sessionIndex);

		std::tuple<ERROR_CODE,User*> GetUser(const int sessionIndex);

				
	private:
		User* AllocUserObjPoolIndex();
		void ReleaseUserObjPoolIndex(const int index);

		User* FindUser(const int sessionIndex);
		User* FindUser(const char* pszID);
				
	private:
		std::vector<User> m_UserObjPool;
		std::deque<int> m_UserObjPoolIndex;	// 루프 돌지 않고 인덱스로 미사용 유저를 검색할 수 있도록 미사용 인덱스 관리

		// 편의용으로 인덱스나 아이디값으로 해당 유저를 검색할 수 있도록 컨테이너 사용
		std::unordered_map<int, User*> m_UserSessionDic;
		std::unordered_map<const char*, User*> m_UserIDDic; //char*는 key로 사용못함

	};
}