#pragma once

#include <string>
#include <utility>
#include <cstdint>
#include <vector>

class hash_table_t
{
public:
  using kv_pair = std::pair<std::string, uint32_t>;

  hash_table_t(size_t size);

  void set(const std::string& key, uint32_t value);

  uint32_t get(const std::string& key);

  void keys(void);

  void display(void);

private:
  using kv_bucket = std::vector<kv_pair>;

  std::vector<kv_bucket> hash_table;

  size_t hash_fn(std::string key);

};
