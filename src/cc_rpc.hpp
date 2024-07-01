#ifndef CC_RPC_HPP
#define CC_RPC_HPP

#include <string>

namespace cc_rpc {
  typedef std::string interface_id_t;
  typedef std::string method_id_t;

  class rpc_request {
  public:
    std::string request_content;
  };

  class rpc_response {
    std::string response_content;
  public:
    std::string as_string() {return response_content; };
    int as_int() { return std::stoi(response_content); };
  };
  enum class eRpcError {
    OK = 0,
    ERROR = 1
  };

  enum class eType {
    eSTRING=0,
    eINT = 1
  };
}
#endif //#ifndef CC_RPC_HPP
