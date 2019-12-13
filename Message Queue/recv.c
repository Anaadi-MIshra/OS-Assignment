#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>

struct mq_attr desd_mq_attr;

int main(int argc, char const *argv[])
{
    mqd_t desd_mq_desc;
    unsigned char buff[64];
    int prio;

    desd_mq_attr.mq_flags = 0;
    desd_mq_attr.mq_maxmsg = 4;
    desd_mq_attr.mq_msgsize = 64;
    desd_mq_attr.mq_curmsgs = 0;

    desd_mq_desc = mq_open("/desdmq", O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR, &desd_mq_attr);

    if (-1 == desd_mq_desc)
    {
        perror("Error opening MQ: ");
        return EXIT_FAILURE;
    }

    mq_receive(desd_mq_desc, buff, 64, &prio);

    printf("Rec: %s\n", buff);

    mq_close(desd_mq_desc);

    return 0;
}
