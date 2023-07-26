//import{Date} from'./package-lock.json'

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
console.log(`sum of matrix is ${sum}` );
document.cookie = "username=John Doe";

class dog extends animal{
   constructor(name,breed){
      super(name,"dog");
      this.breed=breed;
   }
   makeSound(){
      console.log("Woof Woof");
   }
   fetch(){
      console.log("Fetching the ball!");
   }
}
class Shape {
   constructor(color) {
     this.color = color;
   }
 
   draw() {
     console.log(`Drawing a shape with ${this.color}`);
   }
 }
 
 class Square extends Shape {
   constructor(color, sideLength) {
     super(color);
     this.sideLength = sideLength;
   }
 
   calculateArea() {
     return this.sideLength ** 2;
   }
 
   draw() {
     const area = this.calculateArea();
     console.log(`Drawing a square with ${this.color} color and Area is ${area}.`);
   }
 }
 
 class Circle extends Shape {
   constructor(color, radius) {
     super(color);
     this.radius = radius;
   }
 
   calculateArea() {
     return Math.PI * this.radius ** 2;
   }
 
   draw() {
     const area = this.calculateArea();
     console.log(`Drawing a circle with ${this.color} color and Area is ${area}.`);
   }
 }
 class Vector2D {
   constructor(x, y) {
     this.x = x;
     this.y = y;
   }

   add(vector) {
     return new Vector2D(this.x + vector.x, this.y + vector.y);
   }

   toString() {
     return `Vector2D { x: ${this.x}, y: ${this.y} }`;
   }
 }
 

const expirationTime = 3600;
const now = new Date();
const expirationDate = new Date(now.getTime() + expirationTime * 1000); // Multiply by 1000 to convert to milliseconds

document.cookie = "username=John Doe; expires=" + expirationDate.toUTCString();

const mainheading = document.getElementById('mainHeading');
        const paragraph = document.getElementById('paragraph');
        const changetextbutton = document.getElementById('changeTextButton');
        const list = document.getElementById('list');
        
        changetextbutton.addEventListener('click', function() {
            mainheading.innerHTML = 'Hello, this is the fucking DOM';
            paragraph.textContent = 'The text has been changed!';
        });

        const newItem = document.createElement('li');
        newItem.textContent = 'New Item';
        list.appendChild(newItem);

        const firstItem = list.firstElementChild;
        list.removeChild(firstItem);

        paragraph.style.color = 'blue';
        paragraph.style.fontWeight = 'bold';

<<<<<<< HEAD
        const button = document.getElementById('mybutton');

        function handleclick() {
            button.innerHTML = 'Button Clicked';
        }
        
        button.addEventListener('click', handleclick);
=======
function handleclick(){
    document.getElementById("mybutton").innerHTML="Hello fucking world";
}
function changelist(){
  const changecontent=document.getElementById('changecontent').value;
  const index=parseInt(document.getElementById('indexcontent')).value;
  const listitems=document.querySelectorAll("#list li");
  if(index>=1&&index<=listitems.length){
    listitems[index-1].textContent=changecontent;
  }
  else{
    alert("Invalid index, please enter a valid index between 1 and "+ listitems.length);
  }

}
>>>>>>> b6460911a0f9b55f9e56bd267072061648ba64f0
