/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include "interface/rdbc/transaction_constructor.h"
#include "proto/contract/account.pb.h"
#include "proto/contract/contract.pb.h"
#include "proto/contract/rpc.pb.h"

namespace resdb {
namespace contract {

// ContractClient to send data to the contract server.
class ContractClient : public TransactionConstructor {
 public:
  ContractClient(const ResDBConfig& config);

  absl::StatusOr<Account> CreateAccount();
  absl::StatusOr<Contract> DeployContract(
      const std::string& caller_address, const std::string& contract_name,
      const std::string& contract_path,
      const std::vector<std::string>& init_params);

  absl::StatusOr<std::string> ExecuteContract(
      const std::string& caller_address, const std::string& contract_address,
      const std::string& func_name,
      const std::vector<std::string>& func_params);

  absl::StatusOr<std::string> GetBalance(const std::string& address);
  absl::StatusOr<std::string> SetBalance(const std::string& address, const std::string& balance);

  private:
  int SendRequestInternal(const resdb::contract::Request& request, resdb::contract::Response* response);
};

}  // namespace contract
}  // namespace resdb
