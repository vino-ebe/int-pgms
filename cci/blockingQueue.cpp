#include<iostream>
#include<queue>
#include<thread>
#include<pthread.h>

using namespace std;

class BlockingQueue {

    private:

        queue<int> q;

        unique_lock<mutex> mlock;

        condition_variable cv;

        int max_size;



    public:

        BlockingQueue()

        {

            max_size = 5;

        }

        void push(int const &value)

        {

            mlock.lock();

            bool emptyBeforePush = false;

            if (q.empty())

                emptyBeforePush = true;

            while (isFull()) // 'while' instead of 'if' bcos, if it was notified instead of another thread, it will still check the condition before proceeding.

            {

                cout << endl << "Queue is full. Cannot push, so going to wait!" << endl;

                cv.wait(mlock);

            }

            cout << endl << "Now pushing ..." << endl;

            q.push(value);

            mlock.unlock();

            if (emptyBeforePush)

                cv.notify_one();

        }

        bool isEmpty()

        {

            mlock.lock();

            return (q.empty());

        }

        bool isFull()

        {

            mlock.lock();

            return (q.size() == max_size);

        }

        int front()

        {

            mlock.lock();

            while (q.empty())

            {

                cout << endl << "Queue is empty. Cannot get front, so going to wait!" << endl;

                cv.wait(mlock);

            }

            cout << endl << "Now getting front ..." << endl;

            return q.front();

        }

        void pop()

        {

            mlock.lock();

            bool fullBeforePop = false;

            if (isFull())

                fullBeforePop = true;

            while (q.empty())

            {

                cout << endl << "Queue is empty. Cannot pop, so going to wait!" << endl;

                cv.wait(mlock);

            }

            cout << endl << "Now popping ..." << endl;

            q.pop();

            mlock.unlock();

            if (fullBeforePop)

                cv.notify_one();

        }

};

static void fun() {
}




int main()

{

    BlockingQueue bq;
    std::thread t1 (&BlockingQueue::pop, &bq);
    //pthread_create(&thread1, (void*)BlockingQueue::pop, NULL);

    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    thread t2(&BlockingQueue::push,&bq,a[0]);

    thread t3(bq.push(a[1]));

    thread t4(bq.push(a[2]));

    thread t5(bq.push(a[3]));

    thread t6(bq.push(a[4]));

    thread t7(bq.push(a[5]));

    thread t8(bq.push(a[6]));

    t1.join();

    t2.join();

}
