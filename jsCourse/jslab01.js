console.log("hello")
//undefined , null, boolean,string ,symbol,number, object
var mystr="\n\tfirstline\n\tsecondline\n\tthirdline"
console.log(mystr);
var str1s="what's up!";
var str2s="how're you ";
useInput = "dude";
//const useInput=prompt("enter your name ...");
str2s+=useInput;
var strmain=str1s+" "+str2s;
console.log(strmain);
// const  readline =require('readline');
// const rl=readline.createInterface(
//   {
//     input: process.stdin,
//     output: process.stdout
//   }
// );
function testArray(person){
   // const arr=document.getElementById("arraytest").
     for(let key in person){
        console.log(key+" : "+ person[key]);
     }
}
function createMatrix(rows,columns){
const matrix=[];
for(let i=0;i<rows;i++){
   const row=[];
    for(let j=0;j<columns;j++){
        const inputValue=prompt('Enter the value for matrix[${i}][${j}]: ');
        const numericValue=parseFloat(inputValue);
        row.push(isNaN(numericValue)?0:numericValue);
    }
    matrix.push(row);
}
return matrix;
}
function printMatrix(matrix){
   for(let i=0;i<matrix.length;i++){
      console.log(matrix[i].join('\t'));
   }
}
function sumMatrix(matrix){
   let sum=0;
   for(let i=0;i<matrix.length;i++){
      for(let j=0;j<matrix[i].length;j++){
         sum+=matrix[i][j];
      }
   }
   return sum;
}
const rows=parseInt(prompt('enter the number of rows: '));
const columns=parseInt(prompt('enter the number of columns: '));
const matrix =createMatrix(rows,columns);
console.log('Matrix: ');
printMatrix(matrix);

const sum=sumMatrix(matrix);
console.log('sum of matrix is ${sum}' );