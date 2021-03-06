#ifndef GT_IOBUFFER_H_
#define GT_IOBUFFER_H_

/************************************************************************/
/* IO DATA FOR EACH SOCKET EVENT                                        */
/************************************************************************/

#include "GT_Definition.h"

#ifndef WIN32_LEAN_AND_MEAN         // The declarations in the Winsock.h header file will conflict with the declarations in the Winsock2.h header file required by Windows Sockets 2.0. The WIN32_LEAN_AND_MEAN macro prevents the Winsock.h from being included by the Windows.h header. An example illustrating this is shown below.
#define WIN32_LEAN_AND_MEAN         // https://msdn.microsoft.com/en-us/library/windows/desktop/ms737629(v=vs.85).aspx
#endif

#include <Windows.h>
#include <WinSock2.h>
#include <memory>

namespace GT {

	namespace NET {

#define DEFAULT_BUFFER_LEN 4*1024

		class GT_IOContextBuffer: public OVERLAPPED {

		public:
			GT_IOContextBuffer(size_t len = DEFAULT_BUFFER_LEN);
			~GT_IOContextBuffer();

			bool AllocateIOBuffer();
			void SetIOBufferSocket(std::shared_ptr<SOCKET> s);
			void SetIOBufferEventType(IO_EVENT_TYPE type);
			void ResetBuffer();
			bool AllocateIOBufferBySize(size_t len);

            char* GetBufferAddr();
            size_t GetBufferSize();
            std::shared_ptr<SOCKET> GetClientSocketPtr();
            WSABUF& GetWsaBuf() { return io_wsa_buf_; }
            IO_EVENT_TYPE GetIOEventType() { return io_event_type_; }

		public:
			std::shared_ptr<SOCKET>		io_socket_ptr_;
			WSABUF						io_wsa_buf_;
			char*						io_buffer_;
			size_t						io_buffer_size_;
			IO_EVENT_TYPE				io_event_type_;
		};
	}
}

#endif // GT_IOBUFFER_H_
