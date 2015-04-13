#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>
#include <nocopyable.h>
#include <assert.h>
#define LOCK_CHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
							if (__builtin_expect(errnum != 0, 0))    \
							__assert_perror_fail(errnum, __FILE__, __LINE__, __func__); })

class MutexLock:NonCopyable
{
public:
	MutexLock()
	{
		LOCK_CHECK(pthread_mutex_init(&mutex_, NULL));
	}
	~MutexLock()
	{
		LOCK_CHECK(pthread_mutex_destroy(&mutex_));
	}
	void Lock()
	{
		pthread_mutex_lock(&mutex_);
	}
	void Unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}
	pthread_mutex_t* GetMutex() { return &mutex_; }
	pthread_mutex_t mutex_;
};

class MutexLockGuard :NonCopyable
{
public:
	explicit MutexLockGuard(MutexLock& mutex)
		: mutex_(mutex)
	{
		mutex_.Lock();
	}

	~MutexLockGuard()
	{
		mutex_.Unlock();
	}

private:

	MutexLock& mutex_;
};
#endif