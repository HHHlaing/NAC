/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2018,  Regents of the University of California
 *
 * This file is part of NAC (Name-based Access Control for NDN).
 * See AUTHORS.md for complete list of NAC authors and contributors.
 *
 * NAC is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NAC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NAC, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Zhiyi Zhang <zhiyi@cs.ucla.edu>
 */

#ifndef NAC_PRODUCER_HPP
#define NAC_PRODUCER_HPP

#include "common.hpp"

namespace ndn {
namespace nac {

/**
 * In NAC, the producer generates content Data packet carrying the encrypted content.
 * The encryption key is E-KEY generated by the data owner in NAC system.
 */
class Producer
{
public:
  class Error : public std::runtime_error
  {
  public:
    using std::runtime_error::runtime_error;
  };

public:
  Producer(const security::v2::Certificate& identityCert,
           security::v2::KeyChain& keyChain);

  /**
   * @brief Produce a content Data packet
   * @note Naming Convention:
   *       /name
   * @note The generated Data packet carries the encrypted payload. The app
   *       developer should get the E-KEY Data from the data owner and invoke
   *       Producer::parseEKeyData to get the key name and the key buffer.
   *       The generated Data packet will be signed with producer's identity cert.
   *
   * @param name The Data packet name
   * @param payload The payload bytes
   * @param payloadLen The payload bytes length
   * @param asymmetricKeyName The name of D-KEY and E-KEY. Obtained from
   *        Producer::parseEKeyData.
   * @param encryptionKey The encryption key used to encrypte the payload.
   *        Obtained from Producer::parseEKeyData.
   * @return The generated content Data
   */
  std::tuple<shared_ptr<Data>, shared_ptr<Data>>
  produce(const Name& name,
          const uint8_t* payload, size_t payloadLen,
          const Name& asymmetricKeyName, const Buffer& encryptionKey);

  /**
   * @brief Parse E-KEY Data produced by the owner
   * @note The function will NOT verify the signature. The app developer should
   *       first verify the Data signature and then invoke the function.
   *
   * @param eKeyData The E-KEY Data packet
   * @return The asymmetric key name and the key buffer
   */
  static std::tuple<Name, Buffer>
  parseEKeyData(const Data& eKeyData);

private:
  security::v2::Certificate m_cert;
  security::v2::KeyChain& m_keyChain;
};


} // namespace nac
} // namespace ndn

#endif // NAC_PRODUCER_HPP
