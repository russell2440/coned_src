function merge_sorted_arrays(ar1, ar2){
  let merged_array = [];

  if (ar1.length == 0){
    return ar2;
  }
  if (ar2.length == 0){
    return ar1;
  }
  
  // Fill merged array up to it's 
  // length. It's length is dictated
  // by the total of the two arrays.
  // If either of the two arrays have
  // junk data in them then:
  //  return an empty array.
  for (
    let merged_array_length = 
        ar1.length+ar2.length,
      ma_index=0, 
      i=0, j=0;
    ma_index<merged_array_length; 
    ma_index++)
  {
    // Get data from one of the two inputs.
    // Check input length for validity
    if(i<ar1.length&&j<ar2.length){
      if(ar1[i]<ar2[j]){
        item = ar1[i];
        i++;
      }
      else{
        item = ar2[j];
        j++;
      }
    }
    else{
      if(i<ar1.length){
        item = ar1[i];
        i++;
      }
      else{//j<ar2.length
        item = ar2[j];
        j++;
      }
    }
    merged_array[ma_index]=item;
  }
  return merged_array;
}




const array1 = [0,3,4,31], array2 = [3,4,6,30];

merge_sorted_arrays(array1, array2);
