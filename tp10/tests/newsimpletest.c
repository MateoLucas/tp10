/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: mateo
 *
 * Created on May 21, 2020, 9:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define FAILURE_MESSAGE "error xd"
#define SUCCESS_MESSAGE "nice wey"
typedef union
{
    struct portAB
    {
    uint_least8_t portA;
    uint_least8_t portB;
    }portAB;
    uint_least16_t portD;
}portABD_t;
portABD_t port;
/*
 * Simple C Test Suite
 */

/*void test1() {
    printf("newsimpletest test 1\n");
}

void test2() {
    printf("newsimpletest test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (newsimpletest) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (newsimpletest)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (newsimpletest) \n");

    printf("%%TEST_STARTED%% test2 (newsimpletest)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (newsimpletest) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}*/



void reset_port(uint_least8_t valueA,uint_least8_t valueB)
{
    port.portAB.portA = valueA;
    port.portAB.portB = valueB;
}

void test_bitSetClrToggle(uint_least16_t esperado, int actual)
{
    if(port.portD==esperado)
        printf(SUCCESS_MESSAGE);
    else
        printf(FAILURE_MESSAGE);
}

void test_bitGet(int esperado, int actual)
{
    if(port.portD==esperado)
        printf(SUCCESS_MESSAGE);
    else
        printf(FAILURE_MESSAGE);
}


