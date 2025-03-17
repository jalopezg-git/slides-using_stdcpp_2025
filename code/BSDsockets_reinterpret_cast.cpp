#include <netinet/in.h>
#include <sys/socket.h>

void do_bind(int sockfd) {
  struct sockaddr_in addr_in;

  addr_in.sin_addr.s_addr = INADDR_ANY;
  addr_in.sin_port = htons(8080);
  // Violates strict aliasing ??
  bind(sockfd, reinterpret_cast<struct sockaddr *>(&addr_in), sizeof(addr_in));
}
