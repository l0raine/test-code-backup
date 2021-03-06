#pragma once

//信号量处理类
class CSEM
{
public:
	CSEM(LONG lMaximumCount, LONG lInitialCount = 0, LPCTSTR lpName = NULL, LPSECURITY_ATTRIBUTES pSecurity = NULL)
	{
		//创建一个不允许继承(pSecurity ==0)初始计数为lInitialCount最大计数lMaximumCount名称为lpName的信号量
		m_hsem = ::CreateSemaphore(pSecurity, lInitialCount, lMaximumCount, lpName); 
		ASSERT(IsValid());
	}

	~CSEM()
	{
		if(IsValid())
			VERIFY(::CloseHandle(m_hsem));
	}

	BOOL Open(DWORD dwAccess, BOOL bInheritHandle, LPCTSTR pszName)
	{
		if(IsValid())
			VERIFY(::CloseHandle(m_hsem));

		m_hsem = ::OpenSemaphore(dwAccess, bInheritHandle, pszName);
		return(IsValid());
	}

	void Wait(DWORD dwMilliseconds = INFINITE)
	{
		::WaitForSingleObject(m_hsem, dwMilliseconds);
	}

	BOOL Release(LONG lReleaseCount = 1, LPLONG lpPreviousCount = NULL)
	{
		return ::ReleaseSemaphore(m_hsem, lReleaseCount, lpPreviousCount);
	}

	HANDLE& GetHandle	() 	{return m_hsem;}
	operator HANDLE		()	{return m_hsem;}
	HANDLE* operator &	()	{return &m_hsem;}
	BOOL IsValid		()	{return m_hsem != NULL;}

private:
	CSEM(const CSEM& sem);
	CSEM operator = (const CSEM& sem);
private:
	HANDLE m_hsem;
};