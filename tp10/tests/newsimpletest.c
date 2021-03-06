/*
 * File:   newsimpletest.c
 * Author: mateo
 *
 * Created on May 21, 2020, 9:46 PM
 */
/////////////////////////////////Atencion\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/*Para hacer el test en NECESARIO que la variable "ports" deje de ser estatica*/
/*para poder acceder a la estructura y corroborar los valores sin usar la     */
/*libreria siendo probada.                                                    */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "portABD.h"
//#define FAILURE_MESSAGE "SUCCESSFULL TEST\n"
#define SUCCESS_MESSAGE ("SUCCESSFULL TEST NUMBER\n")
typedef union
{
    struct portAB
    {
    uint_least8_t portA;
    uint_least8_t portB;
    }portAB;
    uint_least16_t portD;
}portABD_t;
portABD_t ports;
/*
 * Simple C Test Suite
 */

void test_bitSetClrToggle(uint_least16_t esperado, int actual);
void test_bitGet(int esperado, int llamado);



/*void test2() {
    printf("newsimpletest test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (newsimpletest) message=error message sample\n");
}*/

int main() {
    
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test bitSet (newsimpletest)\n");
    printf("TEST BIT SET");
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0x00;
    test_bitSetClrToggle(0x0001, bitSet(0,'d'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0x00;
    test_bitSetClrToggle(0x0002, bitSet(1,'d'));
    ports.portAB.portA = 0xfe;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xffff, bitSet(0,'a'));
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0x00;
    test_bitSetClrToggle(0x80ff, bitSet(7,'b'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xff10, bitSet(4,'A'));
    ports.portAB.portA = 0xf0;
    ports.portAB.portB = 0xf0;
    test_bitSetClrToggle(0xf0f0, bitSet(8,'b'));
    printf("%%TEST_FINISHED%% time=0 bitSet (newsimpletest) \n\n\n\n");
    
    printf("TEST BIT CLEAR");
    printf("%%TEST_STARTED%% test bitClr (newsimpletest)\n");
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xfffe, bitClr(0,'d'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0x00;
    test_bitSetClrToggle(0x0000, bitClr(1,'d'));
    ports.portAB.portA = 0x03;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xff02, bitClr(0,'a'));
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xc0;
    test_bitSetClrToggle(0x80ff, bitClr(7,'b'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xff00, bitClr(4,'A'));
    ports.portAB.portA = 0xf0;
    ports.portAB.portB = 0xf0;
    test_bitSetClrToggle(0xf0f0, bitClr(8,'b'));
    printf("%%TEST_FINISHED%% time=0 bitClr (newsimpletest) \n\n\n\n");
    
    
    
    printf("TEST BIT CLEAR");
    printf("%%TEST_STARTED%% test bitToggle (newsimpletest)\n");
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xfffe, bitToggle(0,'d'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0x00;
    test_bitSetClrToggle(0x0002, bitToggle(1,'d'));
    ports.portAB.portA = 0x03;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xff02, bitToggle(0,'a'));
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xc0;
    test_bitSetClrToggle(0x40ff, bitToggle(7,'b'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0xff;
    test_bitSetClrToggle(0xff10, bitToggle(4,'A'));
    ports.portAB.portA = 0xf0;
    ports.portAB.portB = 0xf0;
    test_bitSetClrToggle(0xf0f0, bitToggle(8,'b'));
    printf("%%TEST_FINISHED%% time=0 bitClr (newsimpletest) \n\n\n\n");
/******************************************************************************/
    printf("%%TEST_STARTED%% test bitGet (newsimpletest)\n");
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xff;
    test_bitGet(1, bitGet(0,'d'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0x00;
    test_bitGet(0, bitGet(1,'d'));
    ports.portAB.portA = 0x03;
    ports.portAB.portB = 0xff;
    test_bitGet(1, bitGet(0,'a'));
    ports.portAB.portA = 0xff;
    ports.portAB.portB = 0xc0;
    test_bitGet(1, bitGet(7,'b'));
    ports.portAB.portA = 0x00;
    ports.portAB.portB = 0xff;
    test_bitGet(0, bitGet(4,'A'));
    ports.portAB.portA = 0xf0;
    ports.portAB.portB = 0xf0;
    test_bitGet(-1, bitGet(8,'b'));
    printf("%%TEST_FINISHED%% time=0 bitGet (newsimpletest) \n");
    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}

void test_bitGet(int esperado, int llamado)
{
    static int n=0;
    n++;
    printf("bitGet test %d\n",n);
    if(llamado==esperado)
        printf(SUCCESS_MESSAGE);
    else
        printf("%%TEST_FAILED%% time=0 testname=puerto_correcto_%d (test_bitGet) message=esperado %x, llamado %x\n", n, esperado, ports.portD);
}


void test_bitSetClrToggle(uint_least16_t esperado, int actual)
{
    static int n=0;
    n++;
    printf("bitSet/Clr/Toggle test %d\n",n);
    if(ports.portD==esperado)
        printf(SUCCESS_MESSAGE);
    else
        printf("%%TEST_FAILED%% time=0 testname=puerto_correcto_%d (test_test_bitSetClrToggle) message=esperado %x, actual %x\n", n, esperado, ports.portD);
}