//
// Created by Gulliver on 01.07.24.
//

#include "example_interface.hpp"
#include "cc_rpc_client.hpp"

using cc_rpc::eType;
rpc_client::rpc_client(const std::string& transport_url,
           std::string interface_id)
{}

cc_rpc::eRpcError rpc_client::unpack_return(cc_rpc::rpc_response* pResponse,cc_rpc::eType type,void* pReturn_value) {
  if (!pResponse || !pReturn_value)
    return cc_rpc::eRpcError::ERROR;
  switch(type) {

  case eType::eSTRING:
    *((std::string*)pReturn_value) = pResponse->as_string();
    break;
  case eType::eINT:
    *((int*)pReturn_value) = pResponse->as_int();
    break;

  }
  return cc_rpc::eRpcError::OK;
}

cc_rpc::eRpcError rpc_client::pack_param(cc_rpc::rpc_request* pRequest,cc_rpc::eType type,void* pParam_value) {
  if (!pRequest || !pParam_value)
    return cc_rpc::eRpcError::ERROR;
  switch(type) {

    case eType::eSTRING:
      pRequest->request_content.append(*((std::string*)pParam_value));
      break;
    case eType::eINT:
      pRequest->request_content.append(std::to_string( *((int*)pParam_value)) );
      break;

  }
  return cc_rpc::eRpcError::OK;

}

cc_rpc::eRpcError rpc_client::send(cc_rpc::method_id_t method, cc_rpc::rpc_request *pRequest) {
  return cc_rpc::eRpcError::ERROR;
}

cc_rpc::eRpcError rpc_client::receive(cc_rpc::method_id_t method, cc_rpc::rpc_response *pResponse) {
  return cc_rpc::eRpcError::ERROR;
}
