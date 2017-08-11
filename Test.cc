#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

extern "C"{
#include "Mutex.h"
#include "Thread.h"

using namespace std;

class Producer:public Thread
{
    public:
        Producer(int i,Mutex* m)
        {
            this->i = i;
            this->m_mutex = m;
            srand((unsigned)time(NULL));
        }

        void Run()
        {
            while(1)
            {
                m_mutex->Lock();
                cout << "Thread n: " << i << endl;
                m_mutex->UnLock();
                sleep(rand() % 5 + 1);
            }
        }

    private:
        int i;
        Mutex* m_mutex;
};

int main(int argc,char **argv)
{
    int i = 0;
    Mutex* m = new Mutex();

    vector<Producer*>v;

    if(argc < 2)
    {
        cout << "Usage: ./test nbThreads" << endl;
        return 1;
    }

    int nbThreads = atoi(argv[1]);

    while(i < nbThreads)
    {
        Producer *p = new Producer(i,m);
        p->Start();
        v.push_back(p);
       i++; 
    }

    i = 0;
    while(i < nbThreads)
    {
        v[i]->Join();
        i++;
    }
    return 0;
}
}
