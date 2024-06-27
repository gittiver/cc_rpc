#include "interfaces.hpp"
#include "cc_rpc_client.hpp"

class Example_Client {
public:
  Example_Client(const std::string& connection,const std::string& service_name);
  virtual ~Example_Client();

  example_service& get_example_service();

private:
  std::string service_name;
  example_service* _iface;
  ClientStub client_stub;
};
