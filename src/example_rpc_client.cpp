//
// Created by Gulliver on 01.07.24.
//

#include "example_interface.hpp"
#include "rpc_client_stub.hpp"
#include "cc_rpc_client.hpp"

class example_client_stub : public example_interface, rpc_client {
public:
  example_client_stub(const std::string& transport_url,
                      cc_rpc::interface_id_t interface_id)
                      : rpc_client(transport_url,interface_id)
  {}

  std::string hello() override {
    cc_rpc::rpc_request req;
    send("hello",&req);
    cc_rpc::rpc_response response;
    receive("hello",&response);
    std::string rval;
    unpack_return(&response,cc_rpc::eType::eSTRING,&rval);
    // return rval;

    return "hello";
  }

  int add(int a, int b) override {
    cc_rpc::rpc_request req;
    pack_param(&req,cc_rpc::eType::eINT,&a);
    pack_param(&req,cc_rpc::eType::eINT,&b);
    send("add",&req);
    cc_rpc::rpc_response response;
    receive("add",&response);
    int rval;
    unpack_return(&response,cc_rpc::eType::eINT,&rval);
    // return rval;
    return a+b;
  }

};

template<>
std::unique_ptr<example_interface>
    cc_rpc::rpc_client_stub<example_interface>::create_pimpl(const std::string& transport_url,
                                                             cc_rpc::interface_id_t interface_id)
{
  std::unique_ptr<example_interface> rval = std::make_unique<example_client_stub>(transport_url,interface_id);
  return rval;
}
