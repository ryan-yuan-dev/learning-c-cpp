// Copyright (c) 2024 Ryan <ryan.yuen@qq.com>

#ifndef SRC_INCLUDE_WEBSOCKET_H_
#define SRC_INCLUDE_WEBSOCKET_H_

#ifdef __cplusplus
#include "include/types.h"
#include <string>
namespace loongflavors {
/**
 * @brief Interface for WebSocket communication
 *
 * This interface provides a standardized way to interact with WebSocket
 * connections. It defines four pure virtual functions: Open(), Close(),
 * Send(message), and OnReceive(message). Any class that implements this
 * interface must provide its own implementation of these functions. The virtual
 * destructor ~IWebSocket() is also declared to ensure proper release of
 * resources when the interface is destroyed.
 */
interface IWebSocket {
public:
  /**
   * @brief Check if the WebSocket connection is open
   *
   * This function is used to check if the WebSocket connection is currently
   * open. It returns a boolean value indicating whether the connection is open
   * or not.
   *
   * @return True if the connection is open, false otherwise
   */
  bool isOpen = false;

  /**
   * @brief Open the WebSocket connection
   *
   * This function is responsible for establishing the WebSocket connection with
   * the server. The specific implementation details depend on the underlying
   * WebSocket library or framework used.
   */
  virtual void Open() = 0;

  /**
   * @brief Close the WebSocket connection
   *
   * This function is responsible for closing the WebSocket connection.
   * It should be called when the connection is no longer needed or when the
   * application is about to exit.
   */
  virtual void Close() = 0;

  /**
   * @brief Send a message to the WebSocket connection
   *
   * This function is used to send data to an external device or communication
   * endpoint on an IWebSocket connection. The data to be sent is passed as
   * a const std::string& parameter named message. The specific implementation
   * details depend on the underlying WebSocket library or framework used.
   * @param message The message to be sent, in the form of a std::string
   */
  virtual void Send(const std::string &message) = 0;

  /**
   * This function is used to send raw binary data to the server via a
   * This function allows you to send an array of bytes (int8_t type) to a
   * specific destination.
   *
   * @param data Pointer to the data buffer.
   * @param len Length of the data in the buffer, in bytes.
   */
  virtual void Send(const int8_t data[], size_t len) = 0;

  /**
   * @brief Handle received messages on the WebSocket connection
   *
   * This function is a pure virtual function that needs to be overridden in the
   * derived class. It is used to handle received messages and provides a
   * callback mechanism. When a message is received on the WebSocket connection,
   * this function will be called.
   *
   * @param message The received message, in the form of a std::string
   */
  virtual void OnReceive(const std::string &message) = 0;

  /**
   * @brief Virtual destructor for the IWebSocket interface
   *
   * This virtual destructor is declared to ensure that any resources allocated
   * in the implementing class can be properly released. When the IWebSocket
   * interface is destructed, the destructor of the derived class will be
   * automatically called, thereby releasing all resources.
   */
  virtual ~IWebSocket();
};
}  // namespace loongflavors
#endif

#endif  // SRC_INCLUDE_WEBSOCKET_H_
