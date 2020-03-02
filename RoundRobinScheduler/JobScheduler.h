//
// Created by davide on 23/08/19.
//

#ifndef ES4_JOBSCHEDULER_H
#define ES4_JOBSCHEDULER_H

#include <algorithm>
#include <queue>
#include <thread>
#include <vector>
#include "Job.h"

using namespace std;

struct JobCompare {
    bool operator() (Job j1, Job j2) const {
        return j1.getStartTime() < j2.getStartTime();
    }
};

class JobScheduler {
private:
    static bool terminating;
    static int max_time;
    static int num_thread;
    static vector<thread> thread_pool;
    static priority_queue<Job, vector<Job>, JobCompare> job_queue;
    static queue<Job> running_jobs;
    static vector<Job> terminated_jobs;
public:
    JobScheduler();
    ~JobScheduler();
    void submit(Job j);
    void start();
    static void makeJob();
};

#endif //ES4_JOBSCHEDULER_H
