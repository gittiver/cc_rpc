#include "example_interface.hpp"
#include "rpc_client_stub.hpp"
#include<iostream>

using std::cout;
using std::endl;

using cc_rpc::rpc_client_stub;

int main(int argc, char* argv[]) {

  cc_rpc::rpc_client_stub<example_interface> stub("fake:", "example");

  int add_result = stub.interface()->add(2,3);

  std::cout << "result of 2,3 =" << add_result << endl;

  std::cout << "result of rpc hello():" << stub.interface()->hello() << endl;

  return 0;
}

