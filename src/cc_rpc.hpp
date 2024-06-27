#include <string>

class rpc_request {
  std::string service;
  std::string method;
  std::string request_content;
};

class rpc_response {
  std::string service;
  std::string method;
  std::string response_content;
};
