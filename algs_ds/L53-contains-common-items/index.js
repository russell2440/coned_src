
const array1 = ['a','b','c','d'];
const array2 = ['z','d','x'];

function containsCommonItem(a1, a2){
  // Create hash table from first array, then
  // check second array to table for match
  // Perform error checks against inputs:
  //  too few or too many inputs,
  //  types and count of inputs; expecting arrays....
  //  items in the arrays....
  //  array sizes....
  let map = {};
  for (let i = 0;i < a1.length;i++){
    map[a1[i]] = true;
  }
  console.log(map);
  for (let i = 0;i < a2.length;i++){
    if (map[a2[i]])
      return true;
  }
  return false;
  // O(a+b) time complexity
  // O(a) space complexity
}


function containsCommonItem2(a1, a2){
  return a1.some(item=>a2.includes(item));
}

containsCommonItem(array1,array2);

//containsCommonItem2(array1,array2);
