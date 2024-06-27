#include "cc_rpc.hpp"

class ClientTransport {
public:
  static ClientTransport get_transport(const std::string& connection);

  class Receiver {
  public:
    virtual void on_receive(const rpc_response&) = 0;
  };
  int send_msg(const rpc_request& request);
  void set_receiver(Receiver* rcv);
};


class ClientStub {
public:
  ClientStub(const std::string& connection); 
};
