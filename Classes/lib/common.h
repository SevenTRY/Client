//
//  common.h
//  SevenClient
//
//  Created by  TianRunyan on 16/9/11.
//
//

#ifndef common_h
#define common_h

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>


#define	SA	struct sockaddr

/* Define some port number that can be used for our examples */
#define	SERV_PORT		 9877			/* TCP and UDP */
#define	SERV_PORT_STR	"9877"			/* TCP and UDP */


#define	MAXLINE		4096	/* max text line length */

/*commsock .h*/

int Socket(int family,int type,int protocol);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
pid_t Fork(void);

/*error .h*/
void err_sys(const char *fmt, ...);
void err_quit(const char *fmt, ...);

/*wraplib .h*/
const char * Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
void Inet_pton(int family, const char *strptr, void *addrptr);

/*str_cli .h*/
void	 str_cli(FILE *, int);

/*wrapstdio .h*/
void	 Fclose(FILE *);
FILE	*Fdopen(int, const char *);
char	*Fgets(char *, int, FILE *);
FILE	*Fopen(const char *, const char *);
void	 Fputs(const char *, FILE *);

/*Wirten .h*/
void	 Writen(int, void *, size_t);

/*readline .h*/
ssize_t	 Readline(int, void *, size_t);

#endif /* common_h */
