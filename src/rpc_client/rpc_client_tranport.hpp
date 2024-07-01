#ifndef CC_RPC_RPC_CLIENT_TRANPORT_HPP
#define CC_RPC_RPC_CLIENT_TRANPORT_HPP

#include "cc_rpc.hpp"

namespace cc_rpc {
  class rpc_client_tranport {
  public:

    static std::unique_ptr<rpc_client_tranport> get_transport(const std::string& transport_url);

    virtual eRpcError send(const interface_id_t& interface_id, const method_id_t method_id, rpc_request* request) = 0;
    virtual eRpcError receive(const interface_id_t& interface_id, const method_id_t method_id, rpc_request* request) = 0;

  private:
    std::string transport_url;
  };
}


#endif //CC_RPC_RPC_CLIENT_TRANPORT_HPP
