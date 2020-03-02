#include "Job.h"
#include "JobScheduler.h"

int main() {
    JobScheduler js{};
    js.submit(Job(1, 0, 15000));
    js.submit(Job(2, 0, 6000));
    js.submit(Job(3, 1000, 9000));
    js.submit(Job(4, 2000, 12000));
    js.submit(Job(5, 3000, 16000));
    js.submit(Job(6, 3000, 5000));
    js.submit(Job(7, 4000, 7000));
    js.submit(Job(8, 4000, 6000));
    js.submit(Job(9, 5000, 9000));
    js.start();
}
