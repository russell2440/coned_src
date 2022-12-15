#include "hash_table_t.h"
  

//==============================================================================
//==============================================================================
hash_table_t::hash_table_t(size_t size)
{
  (void) size;
}

//==============================================================================
//==============================================================================
void
hash_table_t::set(std::string key, uint32_t value)
{
  (void) key;
  (void) value;
#if 0
    let address = this.hash_fn(key);
    if(!this.data[address]){
      this.data[address] = [];
    }
    this.data[address].push([key,value]);
    //return this.data;
#endif
}

//==============================================================================
//==============================================================================
uint32_t
hash_table_t::get(std::string key)
{
  (void) key;
#if 0
    let address = 0;
    address = this.hash_fn(key);
    let current_bucket = this.data[address];
    if(current_bucket){
      for(let i=0;i<current_bucket.length;i++){
        if(key==current_bucket[i][0]){
          console.log('get bucket',current_bucket,"-",current_bucket[i],'\n');
          return current_bucket[i][1]
        }
      }
    }
    console.log('get value',value,'\n');
    return(value);
#endif

  return 0;
}

//==============================================================================
//==============================================================================
void
hash_table_t::keys(void)
{
#if 0
    const key_array = [];
    for (let i=0;i<this.data.length;i++)
    {
      if(this.data[i]){
        key_array.push(this.data[i][0][0])
      }
    }
    return key_array;
#endif
}

//==============================================================================
//==============================================================================
size_t
hash_table_t::hash_fn(std::string key)
{
  (void) key;
#if 0
    let hash = 0;
    for(let i=0;i<key.length;i++){
      hash=(hash+key.charCodeAt(i)*i)%this.data.length
    }
    console.log('hash_fn at',hash);
    return hash;
#endif

  return 0;
}

