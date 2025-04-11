class Semaphore{
    mutex m;
    condition_variable cv;
    int cnt;
public:
    Semaphore(){}
    Semaphore(int c):cnt(c){};
    void setCount(int a){
        cnt=a;
    }
    inline void signal(){
        unique_lock<mutex> lock(m);
        cnt++;
        if(cnt<=0) cv.notify_all();
    }
    inline void wait(){
        unique_lock<mutex> lock(m);
        cnt--;
        while(cnt<0) cv.wait(lock);
    }
};
class DiningPhilosophers {
    Semaphore fork[5];
    mutex m;
public:
    DiningPhilosophers() {
        for(int i=0;i<5;i++){
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,function<void()> pickLeftFork,function<void()> pickRightFork,function<void()> eat,function<void()> putLeftFork,function<void()> putRightFork) {
        lock_guard<mutex> lock(m);
        fork[(philosopher+1)%5].wait();
        fork[philosopher].wait();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};