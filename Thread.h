#ifndef THREAD_H__
#define THREAD_H__

#include <pthread.h>

class Thread
{
    public:
        int Start();

        void* Join();

        int Detach();

        int Equals(Thread *t);

        void Exit(void *value_ptr);

        int Cancel();

        pthread_t GetThread();

    protected:
        virtual void Run() = 0;

    private:
        static void* Go(void *obj);
        pthread_t m_thread;
};
#endif
