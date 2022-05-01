#include "UserService.pb.h"
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcApplication.hpp>
#include <google/protobuf/service.h>
#include <google/protobuf/empty.pb.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    ik_UserService::UserServiceRpc_Stub stub(new RpcChannel);

    // 登录功能
    ik_UserService::LoginRequest request;
    request.set_id(1);
    request.set_password("123456");

    //　注册功能
    ik_UserService::RegisterRequest regster;
    regster.set_name("hjk");
    regster.set_password("123");

    ik_UserService::RegisterResponse regresponse;
    stub.Registe(nullptr, &regster, &regresponse, nullptr);

    //　退出功能
    ik_UserService::LoginOutRequest lgrequest;
    lgrequest.set_id(1);

    ::google::protobuf::Empty lgresponse;
    stub.LoginOut(nullptr, &lgrequest, &lgresponse, nullptr);


    return 0;
}