function reverse(str){
 let i = 0;
 let  j = str.length - 1;
 while(i < j){
    let temp = str[i];
    str[i] = str[j];
    str[j] = temp;
 } 
 return str;
}

console.log(reverse("sadik"))