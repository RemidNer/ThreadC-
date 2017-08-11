#ifndef MUTEX_H__
#define MUTEX_H__

#include <pthread.h>

class Mutex
{
    public:
        Mutex();

        int Lock();

        int TryLock();

        int UnLock();

        int Destroy();
    private:
        pthread_mutex_t *m_Mutex;
};
#endif
