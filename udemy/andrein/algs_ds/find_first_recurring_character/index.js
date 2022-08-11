function find_first_recurring_character(input){
  let map = {};

  for(let i=0;i<input.length;i++){
    if(map[input[i]]!==undefined){
      return input[i];
    }else{
      map[input[i]]=i;
    }
  console.log(map);
  }
  return(undefined);
}

find_first_recurring_character([2,5,7,2,3,5,1,2,4]);