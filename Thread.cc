#include "Thread.h"
#include <iostream>

using namespace std;

int Thread::Start()
{
    if(pthread_create(&m_thread,0,&Thread::Go,this))
    {
        cerr << "Thread::start could not start thread" << endl;
        return -1;
    }
    return 0;
}

void* Thread::Go(void* obj)
{
    reinterpret_cast<Thread*>(obj)->Run();
    return NULL;
}

void* Thread::Join()
{
    void *result;
    pthread_join(m_thread,&result);
    return result;
}

pthread_t Thread::GetThread()
{
    return m_thread;
}

int Thread::Detach()
{
    return pthread_detach(m_thread);
}

int Thread::Equals(Thread *t)
{
    return pthread_equal(m_thread,t->GetThread());
}

void Thread::Exit(void *value_ptr)
{
    pthread_exit(value_ptr); 
}

int Thread::Cancel()
{
    return pthread_cancel(m_thread);
}
