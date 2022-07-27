// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once


#include <memory>
#include <string>

#include <arrow/record_batch.h>
#include "duckdb_sql_info.h"
#include "duckdb_statement.h"
#include "duckdb_statement_batch_reader.h"


namespace arrow {
namespace flight {
namespace sql {
namespace duckdbflight {

class DuckDBTablesWithSchemaBatchReader : public RecordBatchReader {
 private:
  std::shared_ptr<DuckDBStatementBatchReader> reader_;
  std::string main_query_;
  std::shared_ptr<duckdb::Connection> con_;

 public:
  /// Constructor for DuckDBTablesWithSchemaBatchReader class
  /// \param reader an shared_ptr from a DuckDBStatementBatchReader.
  /// \param main_query  SQL query that originated reader's data.
  /// \param con     a shared pointer to the duckdb connection.
  SqliteTablesWithSchemaBatchReader(
      std::shared_ptr<DuckDBStatementBatchReader> reader, std::string main_query,
      std::shared_ptr<duckdb::Connection> con)
      : reader_(std::move(reader)), main_query_(std::move(main_query)), con_(std::move(con)) {}

  std::shared_ptr<Schema> schema() const override;

  Status ReadNext(std::shared_ptr<RecordBatch>* batch) override;
};

}  // namespace duckdbflight
}  // namespace sql
}  // namespace flight
}  // namespace arrow
