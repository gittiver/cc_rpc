#include "cc_rpc.hpp"
namespace cc_rpc {

  template <typename T>
  class rpc_client_stub {
  public:
    static std::unique_ptr<T> create_pimpl(const std::string& transport_url,cc_rpc::interface_id_t interface_id);

    rpc_client_stub(const std::string& transport_url,cc_rpc::interface_id_t interface_id)
    { pImpl = create_pimpl(transport_url,interface_id); };

    T* interface() { return pImpl.get(); }

  private:
    std::unique_ptr<T> pImpl;
  };
}

