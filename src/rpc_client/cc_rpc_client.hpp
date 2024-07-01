//
// Created by Gulliver on 01.07.24.
//

#ifndef CC_RPC_CC_RPC_CLIENT_HPP
#define CC_RPC_CC_RPC_CLIENT_HPP

#include "cc_rpc_client.hpp"
#include "cc_rpc.hpp"

struct rpc_client {
  rpc_client(const std::string& transport_url,
             std::string interface_id);

  cc_rpc::eRpcError send(cc_rpc::method_id_t method,cc_rpc::rpc_request* pRequest);
  cc_rpc::eRpcError receive(cc_rpc::method_id_t method,cc_rpc::rpc_response* pResponse);

  cc_rpc::eRpcError unpack_return(cc_rpc::rpc_response* pResponse,cc_rpc::eType type,void* pReturn_value);
  cc_rpc::eRpcError pack_param(cc_rpc::rpc_request* pRequest,cc_rpc::eType type,void* pReturn_value);
};

#endif //CC_RPC_CC_RPC_CLIENT_HPP
