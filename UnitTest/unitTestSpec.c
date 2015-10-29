#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf *abortTest;

#ifndef _GNU_SOURCE
typedef void (*sighandler_t)(int);
#endif

struct Runner
{
    int executedTestCaseCount;
    int successfulTestCaseCount;
    int failedTestCaseCount;
};

void abortHandler(int signum)
{
    longjmp(*abortTest, 1);
}

void run(struct Runner *runner, void (*testcase)(void))
{
    jmp_buf jumpBuf;
    jmp_buf *previousAbort = abortTest;
    abortTest = &jumpBuf;

    sighandler_t oldAbortHandler = signal(SIGABRT, abortHandler);

    if (0 == setjmp(jumpBuf))
    {
        testcase();
        runner->successfulTestCaseCount++;
    }
    else
        runner->failedTestCaseCount++;

    runner->executedTestCaseCount++;
    signal(SIGABRT, oldAbortHandler);
    abortTest = previousAbort;
}

void failingTestCase(void)
{
    assert(true);
}

void givenFailingTestCase_whenRunningIt_thenFailsTest(void)
{
    struct Runner runner;
    memset(&runner, 0, sizeof(runner));

givenFailingTestCase:;

whenRunningIt:;
    run(&runner, failingTestCase);

thenFailsTest:;
    assert(runner.executedTestCaseCount == 1);
    assert(runner.successfulTestCaseCount == 0);
    assert(runner.failedTestCaseCount == 1);

}

int main(void)
{
    struct Runner runner;
    memset(&runner, 0, sizeof(runner));
    run(&runner, givenFailingTestCase_whenRunningIt_thenFailsTest);
    fprintf(stderr, "Test cases executed: %d\tTest cases successful: %d\tTest cases failed: %d\n", runner.executedTestCaseCount, runner.successfulTestCaseCount, runner.failedTestCaseCount);
    return runner.failedTestCaseCount ? EXIT_FAILURE : EXIT_SUCCESS;
}
