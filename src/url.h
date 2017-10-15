#ifndef QURL_H
#define QURL_H
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <regex.h>
#include <queue>
#include <map>
#include <string>
#include "spider.h"

using namespace std;

#define MAX_LINK_LEN 128

#define TYPE_HTML  0
#define TYPE_IMAGE 1

#define OQUEUE_MAX_SIZE 50
#define SQUEUE_MAX_SIZE 400

typedef struct Surl {
    char  *url;
    int    level;
    int    type;
} Surl;

typedef struct Url {
    char *domain;
    char *path;
    int  port;
    char *ip;
    int  level;
} Url;

typedef struct evso_arg {
    int     fd;
    Url     *url;
} evso_arg;

extern void push_surlqueue(Surl * url);
extern Url * pop_ourlqueue();
extern void * urlparser(void * arg);
extern char * url2fn(const Url * url);
extern char * url_normalized(char *url);
extern void free_url(Url * ourl);
extern int is_ourlqueue_empty();
extern int is_surlqueue_empty();
extern int get_surl_queue_size();
extern int get_ourl_queue_size();
extern int extract_url(regex_t *re, char *str, Url *domain);
extern int iscrawled(char * url);
extern char * attach_domain(char *url, const char *domain);

#endif
