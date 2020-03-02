//
// Created by davide on 23/08/19.
//

#ifndef ES4_JOB_H
#define ES4_JOB_H

using namespace std;

class Job {
private:
    int unix_time_start;
    int id, duration, start_time;
    int execution_time, wait_time, completion_time;
public:
    Job(int id, int start_time, int duration);
    Job(Job &&job) noexcept; // movement
    Job(const Job &job); // copy

    int getUnixTimeStart();
    void setUnixTimeStart(int timestamp);

    int getId();
    int getStartTime();
    int getDuration();
    
    int getExecutionTime();
    void setExecutionTime(int execution_time);
    int getWaitTime();
    void setWaitTime(int wait_time);
    int getCompletionTime();
    void setCompletionTime(int completion_time);
};

#endif //ES4_JOB_H
