#include "Mutex.h"
#include <iostream>

using namespace std;

Mutex::Mutex()
{
    this->m_Mutex = new pthread_mutex_t;
    pthread_mutex_init(m_Mutex,NULL);
}

Mutex::~Mutex()
{
	
}

int Mutex::Lock()
{
    return pthread_mutex_lock(m_Mutex);
}

int Mutex::TryLock()
{
    return pthread_mutex_trylock(m_Mutex);
}

int Mutex::UnLock()
{
    return pthread_mutex_unlock(m_Mutex);
}

int Mutex::Destroy()
{
    return pthread_mutex_destroy(m_Mutex);
}
