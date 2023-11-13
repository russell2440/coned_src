#include <iostream>
#include "hash_table_t.h"
  

//==============================================================================
//==============================================================================
hash_table_t::hash_table_t(size_t size)
{
  hash_table.resize(size);
}

//==============================================================================
//==============================================================================
void
hash_table_t::set(const std::string& key, uint32_t value)
{
  auto which_bucket = this->hash_fn(key);

  this->hash_table[which_bucket].push_back({key, value});
}

//==============================================================================
//==============================================================================
uint32_t
hash_table_t::get(const std::string& key)
{
  // Find the bucket for this key and then find the value.
  // If it's not there return.
  auto which_bucket = this->hash_fn(key);

  const auto& current_bucket = this->hash_table[which_bucket];

  if (current_bucket.size() == 0)
  {
    return 0;
  }

  for (const auto& kv_pair : current_bucket)
  {
    if (key == kv_pair.first)
    {
      return kv_pair.second;
    }
  }

  return 0;
}

//==============================================================================
//==============================================================================
void
hash_table_t::display(void)
{
  // Display Table by buckets and their kv pairs.
  std::cout << __FUNCTION__ << ": HT [" << hash_table.size() << "]: ";

  std::cout << "{";
  for (const auto& current_bucket: this->hash_table)
  {
    std::cout << "{";
    for (const auto& current_kv_pair: current_bucket)
    {
      std::cout << "{";
      std::cout
        << "[" 
        << current_kv_pair.first 
        << "],[" 
        << current_kv_pair.second 
        << "]";
      std::cout << "}, ";
    }
    std::cout << "},";
  }
  std::cout << "}";

  std::cout << std::endl;
}

//==============================================================================
//==============================================================================
size_t
hash_table_t::hash_fn(std::string key)
{
  size_t hash = 0;

  size_t table_size = this->hash_table.size(); 
  size_t key_size = key.size();
  for (size_t i = 0; i < key_size; i++)
  {
    hash = (hash + key[i] *  i) % table_size;
  }

  return hash;
}

