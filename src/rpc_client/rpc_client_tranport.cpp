//
// Created by Gulliver on 01.07.24.
//

#include "rpc_client_tranport.hpp"
#include <memory>
namespace cc_rpc {


  struct FakeTransport : public virtual rpc_client_tranport {
    FakeTransport() = default;
    ~FakeTransport()=default;

    eRpcError send(const interface_id_t &interface_id, const method_id_t method_id, rpc_request *request) override {

      return eRpcError::ERROR;
    }

    eRpcError receive(const interface_id_t &interface_id, const method_id_t method_id, rpc_request *request) override {
      return eRpcError::ERROR;
    }

  };

  std::unique_ptr<rpc_client_tranport> rpc_client_tranport::get_transport(const std::string &transport_url) {
    std::unique_ptr<rpc_client_tranport> rval;
    if (transport_url.find("fake://")==0) {
      rval = std::make_unique<FakeTransport>();
    }
    if (transport_url.find("http://")==0) {
      rval= nullptr;
      //set rval with http transport instance
      //  rval = std::make_unique<FakeTransport>();
    }

    return rval;
  }


}
