#include "interfaces.hpp"


class ServerStub {

};

class Example_Server {
public:
  Example_Server(const std::string& connection, example_service* service, const std::string& service_name);
private:
  example_service* _iface;
  std::string service_name;
  ServerStub client_stub;
};

