#include <netinet/in.h>
#include <sys/socket.h>

void do_bind(int sockfd) {
  union {
    struct sockaddr addr;
    struct sockaddr_in addr_in;
  };

  addr_in.sin_addr.s_addr = INADDR_ANY;
  addr_in.sin_port = htons(8080);
  // See also [class.mem.general], p. 29.
  bind(sockfd, &addr, sizeof(addr_in));
}
