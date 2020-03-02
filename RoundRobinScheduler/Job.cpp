//
// Created by davide on 23/08/19.
//

#include "Job.h"

int Job::getId() {
    return Job::id;
}

int Job::getStartTime() {
    return Job::start_time;
}

int Job::getDuration() {
    return Job::duration;
}

Job::Job(int id, int start_time, int duration): id(id), start_time(start_time), duration(duration) {
    Job::execution_time = 0;
    Job::wait_time = 0;
    Job::completion_time = 0;
    Job::unix_time_start = -1;
}

int Job::getUnixTimeStart() {
    return Job::unix_time_start;
}
void Job::setUnixTimeStart(int timestamp) {
    Job::unix_time_start = timestamp;
}

Job::Job(Job &&job) noexcept {
    Job::id = job.id;
    Job::duration = job.duration;
    Job::start_time = job.start_time;
    Job::execution_time = job.execution_time;
    Job::wait_time = job.wait_time;
    Job::completion_time = job.completion_time;
}

Job::Job(const Job &job) {
    Job::id = job.id;
    Job::duration = job.duration;
    Job::start_time = job.start_time;
    Job::execution_time = job.execution_time;
    Job::wait_time = job.wait_time;
    Job::completion_time = job.completion_time;
}

int Job::getExecutionTime() {
    return Job::execution_time;
}

void Job::setExecutionTime(int execution_time) {
    Job::execution_time = execution_time;
}

int Job::getWaitTime() {
    return Job::wait_time;
}

void Job::setWaitTime(int wait_time) {
    Job::wait_time = wait_time;
}

int Job::getCompletionTime() {
    return Job::wait_time;
}

void Job::setCompletionTime(int completion_time) {
    Job::completion_time = completion_time;
}
