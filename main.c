/* 
 * File:   main.c
 * Author: James
 *
 * Created on July 23, 2015, 11:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>

/* This is the password_queue program
 * 
 */
int main(int argc, char** argv) {
    mqd_t qd = mq_open("/queue", O_CREAT | O_WRONLY, S_IRUSR|S_IWUSR, NULL);
    if (qd == -1) {
        perror("Could not create queue");
    }
    if (-1 == mq_send(qd, "swordfish", 9,1))
    {
        perror("Could not create queue");
    }
    
    mq_close(qd); 
    return (EXIT_SUCCESS);
}

