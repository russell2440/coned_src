#pragma once

#include <string>
#include <utility>
#include <cstdint>

class hash_table_t
{
public:
  using kv_pair = std::pair<std::string, uint32_t>;

  hash_table_t(size_t size);

  void set(std::string key, uint32_t value);

  uint32_t get(std::string key);

  void keys(void);


private:
  size_t hash_fn(std::string key);
};
