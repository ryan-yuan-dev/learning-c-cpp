// copyright (c) 2024 by Ryan <ryan.yuen@qq.com>

#ifndef SRC_INCLUDE_WEBSOCKET_CLIENT_H_
#define SRC_INCLUDE_WEBSOCKET_CLIENT_H_

#ifdef __cplusplus
#include "include/websocket.h"
#include <iostream>
#include <string>

class WebsocketClient : public loongflavors::IWebSocket {
public:
  void Open() override {
    auto url = "ws://localhost:8080";
    std::cout << "Connecting to " << url << std::endl;
  }

  void Close() override {}

  void Send(const std::string &message) override {}
  /**
   * Handles the reception of messages via web socket.
   *
   * This function is called when a message is received via web socket.
   * @see IWebSocket
   * @param message The received message.
   * @return void
   */
  void OnReceive(const std::string &message) override {}

  ~WebsocketClient() override {}
};
#endif
#endif  // SRC_INCLUDE_WEBSOCKET_CLIENT_H_
