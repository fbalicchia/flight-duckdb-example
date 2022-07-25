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

#include "duckdb_sql_info.h"

#include <arrow/flight/sql/types.h>

namespace arrow {
namespace flight {
namespace sql {
namespace duckdbflight {

/// \brief Gets the mapping from SQL info ids to SqlInfoResult instances.
/// \return the cache.
SqlInfoResultMap GetSqlInfoResultMap() {
  return {
      {SqlInfoOptions::SqlInfo::FLIGHT_SQL_SERVER_NAME,
       SqlInfoResult(std::string("db_name"))},
      {SqlInfoOptions::SqlInfo::FLIGHT_SQL_SERVER_VERSION,
       SqlInfoResult(std::string("duckdb"))},
      {SqlInfoOptions::SqlInfo::FLIGHT_SQL_SERVER_ARROW_VERSION,
       SqlInfoResult(std::string("8.0.0-SNAPSHOT" /* Only an example */))},
      {SqlInfoOptions::SqlInfo::FLIGHT_SQL_SERVER_READ_ONLY, SqlInfoResult(false)},
      {SqlInfoOptions::SqlInfo::SQL_DDL_CATALOG,
       SqlInfoResult(false)},
      {SqlInfoOptions::SqlInfo::SQL_DDL_SCHEMA,
       SqlInfoResult(false)},
      {SqlInfoOptions::SqlInfo::SQL_DDL_TABLE, SqlInfoResult(true)},
      {SqlInfoOptions::SqlInfo::SQL_IDENTIFIER_CASE,
       SqlInfoResult(int64_t(SqlInfoOptions::SqlSupportedCaseSensitivity::
                                 SQL_CASE_SENSITIVITY_CASE_INSENSITIVE))},
      {SqlInfoOptions::SqlInfo::SQL_IDENTIFIER_QUOTE_CHAR,
       SqlInfoResult(std::string("\""))},
      {SqlInfoOptions::SqlInfo::SQL_QUOTED_IDENTIFIER_CASE,
       SqlInfoResult(int64_t(SqlInfoOptions::SqlSupportedCaseSensitivity::
                                 SQL_CASE_SENSITIVITY_CASE_INSENSITIVE))},
      {SqlInfoOptions::SqlInfo::SQL_ALL_TABLES_ARE_SELECTABLE, SqlInfoResult(true)},
      {SqlInfoOptions::SqlInfo::SQL_NULL_ORDERING,
       SqlInfoResult(
           int64_t(SqlInfoOptions::SqlNullOrdering::SQL_NULLS_SORTED_AT_START))},
      {SqlInfoOptions::SqlInfo::SQL_KEYWORDS,
       SqlInfoResult(std::vector<std::string>({"ABORT_P"
                                                "ABSOLUTE_P"
                                                "ACCESS"
                                                "ACTION"
                                                "ADD_P"
                                                "ADMIN"
                                                "AFTER"
                                                "AGGREGATE"
                                                "ALL"
                                                "ALSO"
                                                "ALTER"
                                                "ALWAYS"
                                                "ANALYSE"
                                                "ANALYZE"
                                                "AND"
                                                "ANY"
                                                "ARRAY"
                                                "AS"
                                                "ASC_P"
                                                "ASSERTION"
                                                "ASSIGNMENT"
                                                "ASYMMETRIC"
                                                "AT"
                                                "ATTACH"
                                                "ATTRIBUTE"
                                                "AUTHORIZATION"
                                                "AUTHORIZATION"
                                                "BACKWARD"
                                                "BEFORE"
                                                "BEGIN_P"
                                                "BETWEEN"
                                                "BIGINT"
                                                "BINARY"
                                                "BINARY"
                                                "BIT"
                                                "BOOLEAN_P"
                                                "BOTH"
                                                "BY"
                                                "CACHE"
                                                "CALL_P"
                                                "CALLED"
                                                "CASCADE"
                                                "CASCADED"
                                                "CASE"
                                                "CAST"
                                                "CATALOG_P"
                                                "CHAIN"
                                                "CHAR_P"
                                                "CHARACTER"
                                                "CHARACTERISTICS"
                                                "CHECK_P"
                                                "CHECKPOINT"
                                                "CLASS"
                                                "CLOSE"
                                                "CLUSTER"
                                                "COALESCE"
                                                "COLLATE"
                                                "COLLATION"
                                                "COLLATION"
                                                "COLUMN"
                                                "COLUMNS"
                                                "COMMENT"
                                                "COMMENTS"
                                                "COMMIT"
                                                "COMMITTED"
                                                "CONCURRENTLY"
                                                "CONCURRENTLY"
                                                "CONFIGURATION"
                                                "CONFLICT"
                                                "CONNECTION"
                                                "CONSTRAINT"
                                                "CONSTRAINTS"
                                                "CONTENT_P"
                                                "CONTINUE_P"
                                                "CONVERSION_P"
                                                "COPY"
                                                "COST"
                                                "CREATE_P"
                                                "CROSS"
                                                "CROSS"
                                                "CSV"
                                                "CUBE"
                                                "CURRENT_CATALOG"
                                                "CURRENT_DATE"
                                                "CURRENT_P"
                                                "CURRENT_ROLE"
                                                "CURRENT_SCHEMA"
                                                "CURRENT_SCHEMA"
                                                "CURRENT_TIME"
                                                "CURRENT_TIMESTAMP"
                                                "CURRENT_USER"
                                                "CURSOR"
                                                "CYCLE"
                                                "DATA_P"
                                                "DATABASE"
                                                "DAY_P"
                                                "DAYS_P"
                                                "DEALLOCATE"
                                                "DEC"
                                                "DECIMAL_P"
                                                "DECLARE"
                                                "DEFAULT"
                                                "DEFAULTS"
                                                "DEFERRABLE"
                                                "DEFERRED"
                                                "DEFINER"
                                                "DELETE_P"
                                                "DELIMITER"
                                                "DELIMITERS"
                                                "DEPENDS"
                                                "DESC_P"
                                                "DESCRIBE"
                                                "DETACH"
                                                "DICTIONARY"
                                                "DISABLE_P"
                                                "DISCARD"
                                                "DISTINCT"
                                                "DO"
                                                "DOCUMENT_P"
                                                "DOMAIN_P"
                                                "DOUBLE_P"
                                                "DROP"
                                                "EACH"
                                                "ELSE"
                                                "ENABLE_P"
                                                "ENCODING"
                                                "ENCRYPTED"
                                                "END_P"
                                                "ENUM_P"
                                                "ESCAPE"
                                                "EVENT"
                                                "EXCEPT"
                                                "EXCLUDE"
                                                "EXCLUDING"
                                                "EXCLUSIVE"
                                                "EXECUTE"
                                                "EXISTS"
                                                "EXPLAIN"
                                                "EXPORT_P"
                                                "EXTENSION"
                                                "EXTERNAL"
                                                "EXTRACT"
                                                "FALSE_P"
                                                "FAMILY"
                                                "FETCH"
                                                "FILTER"
                                                "FIRST_P"
                                                "FLOAT_P"
                                                "FOLLOWING"
                                                "FOR"
                                                "FORCE"
                                                "FOREIGN"
                                                "FORWARD"
                                                "FREEZE"
                                                "FREEZE"
                                                "FROM"
                                                "FULL"
                                                "FULL"
                                                "FUNCTION"
                                                "FUNCTIONS"
                                                "GENERATED"
                                                "GLOB"
                                                "GLOB"
                                                "GLOBAL"
                                                "GRANT"
                                                "GRANTED"
                                                "GROUP_P"
                                                "GROUPING"
                                                "HANDLER"
                                                "HAVING"
                                                "HEADER_P"
                                                "HOLD"
                                                "HOUR_P"
                                                "HOURS_P"
                                                "IDENTITY_P"
                                                "IF_P"
                                                "ILIKE"
                                                "ILIKE"
                                                "IMMEDIATE"
                                                "IMMUTABLE"
                                                "IMPLICIT_P"
                                                "IMPORT_P"
                                                "IN_P"
                                                "INCLUDING"
                                                "INCREMENT"
                                                "INDEX"
                                                "INDEXES"
                                                "INHERIT"
                                                "INHERITS"
                                                "INITIALLY"
                                                "INLINE_P"
                                                "INNER_P"
                                                "INNER_P"
                                                "INOUT"
                                                "INPUT_P"
                                                "INSENSITIVE"
                                                "INSERT"
                                                "INSTEAD"
                                                "INT_P"
                                                "INTEGER"
                                                "INTERSECT"
                                                "INTERVAL"
                                                "INTO"
                                                "INVOKER"
                                                "IS"
                                                "IS"
                                                "ISNULL"
                                                "ISNULL"
                                                "ISOLATION"
                                                "JOIN"
                                                "JOIN"
                                                "KEY"
                                                "LABEL"
                                                "LANGUAGE"
                                                "LARGE_P"
                                                "LAST_P"
                                                "LATERAL_P"
                                                "LEADING"
                                                "LEAKPROOF"
                                                "LEFT"
                                                "LEFT"
                                                "LEVEL"
                                                "LIKE"
                                                "LIKE"
                                                "LIMIT"
                                                "LISTEN"
                                                "LOAD"
                                                "LOCAL"
                                                "LOCALTIME"
                                                "LOCALTIMESTAMP"
                                                "LOCATION"
                                                "LOCK_P"
                                                "LOCKED"
                                                "LOGGED"
                                                "MACRO"
                                                "MAP"
                                                "MAP"
                                                "MAPPING"
                                                "MATCH"
                                                "MATERIALIZED"
                                                "MAXVALUE"
                                                "METHOD"
                                                "MICROSECOND_P"
                                                "MICROSECONDS_P"
                                                "MILLISECOND_P"
                                                "MILLISECONDS_P"
                                                "MINUTE_P"
                                                "MINUTES_P"
                                                "MINVALUE"
                                                "MODE"
                                                "MONTH_P"
                                                "MONTHS_P"
                                                "MOVE"
                                                "NAME_P"
                                                "NAMES"
                                                "NATIONAL"
                                                "NATURAL"
                                                "NATURAL"
                                                "NCHAR"
                                                "NEW"
                                                "NEXT"
                                                "NO"
                                                "NONE"
                                                "NOT"
                                                "NOTHING"
                                                "NOTIFY"
                                                "NOTNULL"
                                                "NOTNULL"
                                                "NOWAIT"
                                                "NULL_P"
                                                "NULLIF"
                                                "NULLS_P"
                                                "NUMERIC"
                                                "OBJECT_P"
                                                "OF"
                                                "OFF"
                                                "OFFSET"
                                                "OIDS"
                                                "OLD"
                                                "ON"
                                                "ONLY"
                                                "OPERATOR"
                                                "OPTION"
                                                "OPTIONS"
                                                "OR"
                                                "ORDER"
                                                "ORDINALITY"
                                                "OUT_P"
                                                "OUTER_P"
                                                "OUTER_P"
                                                "OVER"
                                                "OVERLAPS"
                                                "OVERLAPS"
                                                "OVERLAY"
                                                "OVERRIDING"
                                                "OWNED"
                                                "OWNER"
                                                "PARALLEL"
                                                "PARSER"
                                                "PARTIAL"
                                                "PARTITION"
                                                "PASSING"
                                                "PASSWORD"
                                                "PERCENT"
                                                "PLACING"
                                                "PLANS"
                                                "POLICY"
                                                "POSITION"
                                                "PRAGMA_P"
                                                "PRECEDING"
                                                "PRECISION"
                                                "PREPARE"
                                                "PREPARED"
                                                "PRESERVE"
                                                "PRIMARY"
                                                "PRIOR"
                                                "PRIVILEGES"
                                                "PROCEDURAL"
                                                "PROCEDURE"
                                                "PROGRAM"
                                                "PUBLICATION"
                                                "QUOTE"
                                                "RANGE"
                                                "READ_P"
                                                "REAL"
                                                "REASSIGN"
                                                "RECHECK"
                                                "RECURSIVE"
                                                "REF"
                                                "REFERENCES"
                                                "REFERENCING"
                                                "REFRESH"
                                                "REINDEX"
                                                "RELATIVE_P"
                                                "RELEASE"
                                                "RENAME"
                                                "REPEATABLE"
                                                "REPLACE"
                                                "REPLICA"
                                                "RESET"
                                                "RESTART"
                                                "RESTRICT"
                                                "RETURNING"
                                                "RETURNS"
                                                "REVOKE"
                                                "RIGHT"
                                                "RIGHT"
                                                "ROLE"
                                                "ROLLBACK"
                                                "ROLLUP"
                                                "ROW"
                                                "ROWS"
                                                "RULE"
                                                "SAMPLE"
                                                "SAVEPOINT"
                                                "SCHEMA"
                                                "SCHEMAS"
                                                "SCROLL"
                                                "SEARCH"
                                                "SECOND_P"
                                                "SECONDS_P"
                                                "SECURITY"
                                                "SELECT"
                                                "SEQUENCE"
                                                "SEQUENCES"
                                                "SERIALIZABLE"
                                                "SERVER"
                                                "SESSION"
                                                "SESSION_USER"
                                                "SET"
                                                "SETOF"
                                                "SETS"
                                                "SHARE"
                                                "SHOW"
                                                "SIMILAR"
                                                "SIMILAR"
                                                "SIMPLE"
                                                "SKIP"
                                                "SMALLINT"
                                                "SNAPSHOT"
                                                "SOME"
                                                "SQL_P"
                                                "STABLE"
                                                "STANDALONE_P"
                                                "START"
                                                "STATEMENT"
                                                "STATISTICS"
                                                "STDIN"
                                                "STDOUT"
                                                "STORAGE"
                                                "STRICT_P"
                                                "STRIP_P"
                                                "STRUCT"
                                                "STRUCT"
                                                "SUBSCRIPTION"
                                                "SUBSTRING"
                                                "SYMMETRIC"
                                                "SYSID"
                                                "SYSTEM_P"
                                                "TABLE"
                                                "TABLES"
                                                "TABLESAMPLE"
                                                "TABLESAMPLE"
                                                "TABLESPACE"
                                                "TEMP"
                                                "TEMPLATE"
                                                "TEMPORARY"
                                                "TEXT_P"
                                                "THEN"
                                                "TIME"
                                                "TIMESTAMP"
                                                "TO"
                                                "TRAILING"
                                                "TRANSACTION"
                                                "TRANSFORM"
                                                "TREAT"
                                                "TRIGGER"
                                                "TRIM"
                                                "TRUE_P"
                                                "TRUNCATE"
                                                "TRUSTED"
                                                "TRY_CAST"
                                                "TRY_CAST"
                                                "TYPE_P"
                                                "TYPES_P"
                                                "UNBOUNDED"
                                                "UNCOMMITTED"
                                                "UNENCRYPTED"
                                                "UNION"
                                                "UNIQUE"
                                                "UNKNOWN"
                                                "UNLISTEN"
                                                "UNLOGGED"
                                                "UNTIL"
                                                "UPDATE"
                                                "USER"
                                                "USING"
                                                "VACUUM"
                                                "VALID"
                                                "VALIDATE"
                                                "VALIDATOR"
                                                "VALUE_P"
                                                "VALUES"
                                                "VARCHAR"
                                                "VARIADIC"
                                                "VARYING"
                                                "VERBOSE"
                                                "VERBOSE"
                                                "VERSION_P"
                                                "VIEW"
                                                "VIEWS"
                                                "VOLATILE"
                                                "WHEN"
                                                "WHERE"
                                                "WHITESPACE_P"
                                                "WINDOW"
                                                "WITH"
                                                "WITHIN"
                                                "WITHOUT"
                                                "WORK"
                                                "WRAPPER"
                                                "WRITE_P"
                                                "XML_P"
                                                "XMLATTRIBUTES"
                                                "XMLCONCAT"
                                                "XMLELEMENT"
                                                "XMLEXISTS"
                                                "XMLFOREST"
                                                "XMLNAMESPACES"
                                                "XMLPARSE"
                                                "XMLPI"
                                                "XMLROOT"
                                                "XMLSERIALIZE"
                                                "XMLTABLE"
                                                "YEAR_P"
                                                "YEARS_P"
                                                "YES_P"
                                                "ZONE"}))},
      {SqlInfoOptions::SqlInfo::SQL_NUMERIC_FUNCTIONS,
       SqlInfoResult(std::vector<std::string>(
           {"ABS"
            "ACOS"
            "ASIN"
            "ATAN2"
            "ATAN2"
            "BIT_COUNT"
            "CBRT"
            "CEIL"
            "CEILING"
            "CHR"
            "COS"
            "COT"
            "DEGREES"
            "EVEN"
            "FACTORIAL"
            "FLOOR"
            "GAMMA"
            "GREATEST"
            "LEAST"
            "LGAMMA"
            "LN"
            "LOG"
            "LOG2"
            "LOG10"
            "NEXTAFTER"
            "PI"
            "POW"
            "POWER"
            "RADIANS"
            "RANDOM"
            "ROUND"
            "SETSEED"
            "SIN"
            "SIGN"
            "SQRT"
            "XOR"
            "TAN"
            "@"}))},
      {SqlInfoOptions::SqlInfo::SQL_STRING_FUNCTIONS,
       SqlInfoResult(
           std::vector<std::string>({"ARRAY_EXTRACT"
                            "ARRAY_SLICE"
                            "ASCII"
                            "BASE64"
                            "BIT_LENGTH"
                            "CONCAT"
                            "CONCAT_WS"
                            "CONTAINS"
                            "FORMAT"
                            "FROM_BASE64"
                            "INSTR"
                            "LCASE"
                            "LEFT"
                            "LENGTH"
                            "STRING"
                            "LIKE_ESCAPE"
                            "LIST_ELEMENT"
                            "LIST_EXTRACT"
                            "LOWER"
                            "LPAD"
                            "LTRIM"
                            "LTRIM"
                            "MD5"
                            "NFC_NORMALIZE"
                            "NOT_LIKE_ESCAPE"
                            "ORD"
                            "POSITION"
                            "PREFIX"
                            "PRINTF"
                            "REGEXP_FULL_MATCH"
                            "REGEXP_MATCHES"
                            "REGEXP_REPLACE"
                            "REGEXP_SPLIT_TO_ARRAY"
                            "REPEAT"
                            "REPLACE"
                            "REVERSE"
                            "RIGHT"
                            "RPAD"
                            "RTRIM"
                            "RTRIM"
                            "STRING"
                            "STRLEN"
                            "STRPOS"
                            "STRIP_ACCENTS"
                            "STR_SPLIT"
                            "STR_SPLIT_REGEX"
                            "STRING_SPLIT"
                            "STRING_SPLIT_REGEX"
                            "STRING_TO_ARRAY"
                            "SUBSTR"
                            "SUBSTRING"
                            "SUFFIX"
                            "STRPOS"
                            "TO_BASE64"
                            "TRIM"
                            "TRIM"
                            "UCASE"
                            "UNICODE"
                            "UPPER"
                            "EDITDIST3"
                            "HAMMING"
                            "JACCARD"
                            "LEVENSHTEIN"
                            "MISMATCHES"}))},
      {SqlInfoOptions::SqlInfo::SQL_SUPPORTS_CONVERT,
       SqlInfoResult(std::unordered_map<int32_t, std::vector<int32_t>>(
           {{SqlInfoOptions::SqlSupportsConvert::SQL_CONVERT_BIGINT,
             std::vector<int32_t>(
                 {SqlInfoOptions::SqlSupportsConvert::SQL_CONVERT_INTEGER})}}))}};
}

}  // namespace duckdbflight
}  // namespace sql
}  // namespace flight
}  // namespace arrow
