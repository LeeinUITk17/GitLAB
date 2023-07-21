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
  