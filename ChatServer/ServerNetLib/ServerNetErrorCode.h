#pragma once

namespace NServerNetLib
{
	// 에러 코드는 1 ~ 200까지 사용한다.
	// 에러 코드는 바로 찾아 갈 수 있도록 유니크하게.
	enum class NET_ERROR_CODE : short
	{
		NONE = 0,

		SERVER_SOCKET_CREATE_FAIL = 11,
		SERVER_SOCKET_SO_REUSEADDR_FAIL = 12,
		SERVER_SOCKET_BIND_FAIL = 14,
		SERVER_SOCKET_LISTEN_FAIL = 15,
		SERVER_SOCKET_FIONBIO_FAIL = 16,

		SEND_CLOSE_SOCKET = 21,
		SEND_SIZE_ZERO = 22,
		CLIENT_SEND_BUFFER_FULL = 23,
		CLIENT_FLUSH_SEND_BUFF_REMOTE_CLOSE = 24,
		
		ACCEPT_API_ERROR = 26,
		ACCEPT_MAX_SESSION_COUNT = 27,
		ACCEPT_API_WSAEWOULDBLOCK = 28,

		RECV_API_ERROR = 32,
		RECV_BUFFER_OVERFLOW = 32,
		RECV_REMOTE_CLOSE = 33,
		RECV_PROCESS_NOT_CONNECTED = 34,
		RECV_CLIENT_MAX_PACKET = 35,
	};


	const int MAX_NET_ERROR_STRING_COUNT = 64;
	struct NetError
	{
		NetError(NET_ERROR_CODE code)
		{
			Error = code;
		}

		NET_ERROR_CODE Error = NET_ERROR_CODE::NONE;
		wchar_t Msg[MAX_NET_ERROR_STRING_COUNT] = { 0, };
		int Vlaue = 0;
	};
}
