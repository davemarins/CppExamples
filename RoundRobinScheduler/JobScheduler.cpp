//
// Created by davide on 23/08/19.
//

#include <chrono>
#include <mutex>
#include <thread>
#include "Job.h"
#include "JobScheduler.h"

using namespace std;

mutex mtx;

void JobScheduler::makeJob() {
    if(JobScheduler::terminating) {
        exit(0);
    } else {
        mtx.lock();
        if(!JobScheduler::job_queue.empty()) {
            // from job_queue to running_jobs
            Job j1 = JobScheduler::job_queue.top();
            JobScheduler::job_queue.pop();
            JobScheduler::running_jobs.push(j1);
            mtx.unlock();
            // looking for termination
            if(JobScheduler::terminating && JobScheduler::job_queue.empty()) {
                exit(0);
            }
            mtx.lock();
            // elaborate the first job with priority
            Job j2 = JobScheduler::running_jobs.front();
            JobScheduler::running_jobs.pop();
            mtx.unlock();
            // start elaboration of j2
            if((j2.getDuration() - j2.getExecutionTime()) <= JobScheduler::max_time) {
                if(j2.getUnixTimeStart() == -1) {
                    // first execution - no wait time
                    j2.setUnixTimeStart(
                            chrono::duration_cast<chrono::milliseconds>(
                                    chrono::system_clock::now().time_since_epoch()
                            ).count()
                    );
                } else {
                    // update wait time
                    j2.setWaitTime(j2.getWaitTime() + (int) (
                            chrono::duration_cast<chrono::milliseconds>(
                                    chrono::system_clock::now().time_since_epoch()
                            ).count() - j2.getUnixTimeStart() - j2.getCompletionTime()
                    ));
                }
                this_thread::sleep_for(chrono::milliseconds(j2.getDuration() - j2.getExecutionTime()));
                j2.setExecutionTime(j2.getExecutionTime() + j2.getDuration());
                j2.setCompletionTime(j2.getStartTime() + j2.getExecutionTime() + j2.getWaitTime());
                // Job terminated
            } else {
                if(j2.getUnixTimeStart() == -1) {
                    // first execution - no wait time
                    j2.setUnixTimeStart(
                            chrono::duration_cast<chrono::milliseconds>(
                                    chrono::system_clock::now().time_since_epoch()
                            ).count()
                    );
                } else {
                    // update wait time
                    j2.setWaitTime(j2.getWaitTime() + (int) (
                            chrono::duration_cast<chrono::milliseconds>(
                                    chrono::system_clock::now().time_since_epoch()
                                    ).count() - j2.getUnixTimeStart() - j2.getCompletionTime()
                    ));
                }
                this_thread::sleep_for(chrono::milliseconds(JobScheduler::max_time));
                j2.setExecutionTime(j2.getExecutionTime() + max_time);
                j2.setCompletionTime(j2.getStartTime() + j2.getExecutionTime() + j2.getWaitTime());
                // Job not yet terminated
            }
            // end elaboration of j2
            mtx.lock();
            JobScheduler::job_queue.push(j2);
            mtx.unlock();
        } else {
            mtx.unlock();
            exit(0);
        }
    }
}

JobScheduler::JobScheduler() {}

JobScheduler::~JobScheduler() {
    JobScheduler::terminating = false;
    while(!JobScheduler::thread_pool.empty()) {
        JobScheduler::thread_pool.back().join();
        JobScheduler::thread_pool.pop_back();
    }
}

void JobScheduler::submit(Job j) {
    JobScheduler::job_queue.push(j);
}

void JobScheduler::start() {
    JobScheduler::max_time = 3000;
    JobScheduler::num_thread = max(2, (int) thread::hardware_concurrency());
    for(int i = 0; i < JobScheduler::num_thread; i++) {
        thread t(JobScheduler::makeJob);
        JobScheduler::thread_pool.push_back(t);
    }
}
